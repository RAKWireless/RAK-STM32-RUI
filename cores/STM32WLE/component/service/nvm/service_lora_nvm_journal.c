#include "service_lora_nvm_journal.h"

#if defined(STM32WLE5xx) && defined(SUPPORT_LORA) && defined(LORA_STACK_104)

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "board_basic.h"
#include "mcu_basic.h"
#include "udrv_errno.h"
#include "udrv_flash.h"
#include "uhal_flash.h"

#define LORA_JOURNAL_PAGE_SIZE             2048U
#define LORA_JOURNAL_PAGE_A                MCU_CERT_CONFIG_NVM_ADDR
#define LORA_JOURNAL_PAGE_B                (MCU_CERT_CONFIG_NVM_ADDR + LORA_JOURNAL_PAGE_SIZE)
#define LORA_JOURNAL_PAGE_MAGIC            0x4C4A5047UL /* LJPG */
#define LORA_JOURNAL_RECORD_MAGIC          0x4C4A5243UL /* LJRC */
#define LORA_JOURNAL_FORMAT_VERSION        1UL
#define LORA_JOURNAL_COMMIT                0x434F4D4D49544F4BULL /* COMMITOK */
#define LORA_JOURNAL_RESERVATION_BLOCK     10UL
#define LORA_JOURNAL_PAGE_HEADER_SIZE      32U
#define LORA_JOURNAL_RECORD_HEADER_SIZE    24U
#define LORA_JOURNAL_MAX_CHANNELS          16U

typedef enum
{
    LORA_JOURNAL_RECORD_DEVNONCE = 1,
    LORA_JOURNAL_RECORD_ABP_COUNTERS = 2,
    LORA_JOURNAL_RECORD_ABP_CHANNELS = 3,
} lora_journal_record_type_t;

typedef struct __attribute__((aligned(8)))
{
    uint32_t magic;
    uint32_t generation;
    uint32_t format_version;
    uint32_t header_crc;
    uint32_t reserved0;
    uint32_t reserved1;
    uint64_t commit;
} lora_journal_page_header_t;

typedef struct __attribute__((aligned(8)))
{
    uint32_t magic;
    uint32_t sequence;
    uint16_t type;
    uint16_t payload_length;
    uint32_t payload_crc;
    uint32_t header_crc;
    uint32_t reserved;
} lora_journal_record_header_t;

typedef struct __attribute__((aligned(8)))
{
    uint32_t reserved_until;
} lora_journal_devnonce_t;

typedef struct __attribute__((aligned(8)))
{
    uint32_t session_id;
    uint32_t fcnt_up_reserved_until;
    uint32_t nfcnt_down;
    uint32_t afcnt_down;
    uint32_t fcnt_down;
    uint32_t mc_fcnt_down[LORAMAC_MAX_MC_CTX];
    uint32_t last_down_fcnt;
    uint32_t last_rx_mic;
} lora_journal_abp_counters_t;

typedef struct __attribute__((aligned(4)))
{
    uint32_t frequency;
    uint32_t rx1_frequency;
    uint8_t index;
    int8_t dr_min;
    int8_t dr_max;
    uint8_t band;
} lora_journal_channel_t;

typedef struct __attribute__((aligned(8)))
{
    uint32_t session_id;
    uint8_t region;
    uint8_t channel_count;
    uint8_t mask_words;
    uint8_t reserved;
    uint16_t channels_mask[REGION_NVM_CHANNELS_MASK_SIZE];
    lora_journal_channel_t channels[LORA_JOURNAL_MAX_CHANNELS];
} lora_journal_abp_channels_t;

typedef struct
{
    bool initialized;
    bool rotate_required;
    uint32_t active_page;
    uint32_t generation;
    uint32_t next_sequence;
    uint32_t append_offset;
    bool devnonce_valid;
    uint32_t devnonce_sequence;
    lora_journal_devnonce_t devnonce;
    bool counters_valid;
    uint32_t counters_sequence;
    lora_journal_abp_counters_t counters;
    bool channels_valid;
    uint32_t channels_sequence;
    lora_journal_abp_channels_t channels;
} lora_journal_context_t;

typedef struct
{
    uint32_t highest_sequence;
    uint32_t append_offset;
    bool dirty_tail;
} lora_journal_scan_result_t;

static lora_journal_context_t journal;

static uint32_t journal_crc32(const void *data, uint32_t length)
{
    const uint8_t *bytes = (const uint8_t *)data;
    uint32_t crc = 0xFFFFFFFFUL;

    while (length-- != 0U)
    {
        crc ^= *bytes++;
        for (uint8_t bit = 0; bit < 8U; bit++)
        {
            crc = (crc >> 1U) ^
                  ((0U - (crc & 1U)) & 0xEDB88320UL);
        }
    }
    return ~crc;
}

static bool journal_sequence_is_newer(uint32_t lhs, uint32_t rhs)
{
    return ((int32_t)(lhs - rhs) > 0);
}

static uint32_t journal_align8(uint32_t value)
{
    return (value + 7U) & ~7U;
}

static uint32_t journal_page_header_crc(
    const lora_journal_page_header_t *header)
{
    return journal_crc32(header, offsetof(lora_journal_page_header_t, header_crc));
}

static uint32_t journal_record_header_crc(
    const lora_journal_record_header_t *header)
{
    return journal_crc32(header, offsetof(lora_journal_record_header_t, header_crc));
}

static bool journal_page_header_valid(uint32_t page,
                                      lora_journal_page_header_t *header)
{
    memcpy(header, (const void *)(uintptr_t)page, sizeof(*header));
    return (header->magic == LORA_JOURNAL_PAGE_MAGIC) &&
           (header->format_version == LORA_JOURNAL_FORMAT_VERSION) &&
           (header->header_crc == journal_page_header_crc(header)) &&
           (header->commit == LORA_JOURNAL_COMMIT);
}

static uint32_t journal_session_id(void)
{
    uint8_t identity[37];

    memset(identity, 0, sizeof(identity));
    service_nvm_get_dev_addr_from_nvm(&identity[0], 4);
    service_nvm_get_nwk_skey_from_nvm(&identity[4], 16);
    service_nvm_get_app_skey_from_nvm(&identity[20], 16);
    identity[36] = (uint8_t)service_nvm_get_band_from_nvm();
    return journal_crc32(identity, sizeof(identity));
}

static void journal_apply_record(uint16_t type, uint32_t sequence,
                                 const void *payload, uint16_t length)
{
    if ((type == LORA_JOURNAL_RECORD_DEVNONCE) &&
        (length == sizeof(journal.devnonce)) &&
        (!journal.devnonce_valid ||
         journal_sequence_is_newer(sequence, journal.devnonce_sequence)))
    {
        memcpy(&journal.devnonce, payload, length);
        journal.devnonce_sequence = sequence;
        journal.devnonce_valid = true;
    }
    else if ((type == LORA_JOURNAL_RECORD_ABP_COUNTERS) &&
             (length == sizeof(journal.counters)) &&
             (!journal.counters_valid ||
              journal_sequence_is_newer(sequence, journal.counters_sequence)))
    {
        memcpy(&journal.counters, payload, length);
        journal.counters_sequence = sequence;
        journal.counters_valid = true;
    }
    else if ((type == LORA_JOURNAL_RECORD_ABP_CHANNELS) &&
             (length == sizeof(journal.channels)) &&
             (!journal.channels_valid ||
              journal_sequence_is_newer(sequence, journal.channels_sequence)))
    {
        memcpy(&journal.channels, payload, length);
        journal.channels_sequence = sequence;
        journal.channels_valid = true;
    }
}

static lora_journal_scan_result_t journal_scan_page(uint32_t page,
                                                     uint32_t scan_limit)
{
    uint32_t offset = LORA_JOURNAL_PAGE_HEADER_SIZE;
    lora_journal_scan_result_t result = {0};

    if (scan_limit > LORA_JOURNAL_PAGE_SIZE)
    {
        scan_limit = LORA_JOURNAL_PAGE_SIZE;
    }

    while ((offset + LORA_JOURNAL_RECORD_HEADER_SIZE + sizeof(uint64_t)) <=
           scan_limit)
    {
        lora_journal_record_header_t header;
        uint32_t payload_size;
        uint32_t total_size;
        uint64_t commit;
        const uint8_t *payload;

        memcpy(&header, (const void *)(uintptr_t)(page + offset), sizeof(header));
        if (header.magic == 0xFFFFFFFFUL)
        {
            break;
        }
        if ((header.magic != LORA_JOURNAL_RECORD_MAGIC) ||
            (header.header_crc != journal_record_header_crc(&header)))
        {
            result.dirty_tail = true;
            break;
        }

        payload_size = journal_align8(header.payload_length);
        total_size = LORA_JOURNAL_RECORD_HEADER_SIZE + payload_size +
                     sizeof(uint64_t);
        if ((header.payload_length == 0U) ||
            ((offset + total_size) > scan_limit))
        {
            result.dirty_tail = true;
            break;
        }

        payload = (const uint8_t *)(uintptr_t)
                  (page + offset + LORA_JOURNAL_RECORD_HEADER_SIZE);
        memcpy(&commit, payload + payload_size, sizeof(commit));
        if ((commit != LORA_JOURNAL_COMMIT) ||
            (journal_crc32(payload, header.payload_length) != header.payload_crc))
        {
            result.dirty_tail = true;
            break;
        }

        journal_apply_record(header.type, header.sequence, payload,
                             header.payload_length);
        if ((result.highest_sequence == 0U) ||
            journal_sequence_is_newer(header.sequence,
                                      result.highest_sequence))
        {
            result.highest_sequence = header.sequence;
        }
        offset += total_size;
    }

    result.append_offset = offset;
    return result;
}

static int32_t journal_program_record(uint16_t type, const void *payload,
                                      uint16_t length, bool allow_rotate);

static int32_t journal_create_page(uint32_t page, uint32_t generation)
{
    lora_journal_page_header_t header __attribute__((aligned(8)));
    uint64_t commit __attribute__((aligned(8))) = LORA_JOURNAL_COMMIT;
    lora_journal_context_t previous = journal;
    int32_t ret = UDRV_RETURN_OK;

    ret = udrv_flash_erase(page, LORA_JOURNAL_PAGE_SIZE);
    if (ret != UDRV_RETURN_OK)
    {
        return ret;
    }

    memset(&header, 0xFF, sizeof(header));
    header.magic = LORA_JOURNAL_PAGE_MAGIC;
    header.generation = generation;
    header.format_version = LORA_JOURNAL_FORMAT_VERSION;
    header.header_crc = journal_page_header_crc(&header);

    ret = udrv_flash_program(page, 24U, (uint8_t *)&header);
    if (ret != UDRV_RETURN_OK)
    {
        return ret;
    }

    journal.active_page = page;
    journal.generation = generation;
    journal.append_offset = LORA_JOURNAL_PAGE_HEADER_SIZE;
    journal.rotate_required = false;

    if (journal.devnonce_valid)
    {
        ret = journal_program_record(LORA_JOURNAL_RECORD_DEVNONCE,
                                     &journal.devnonce,
                                     sizeof(journal.devnonce), false);
    }
    if ((ret == UDRV_RETURN_OK) && journal.counters_valid)
    {
        ret = journal_program_record(LORA_JOURNAL_RECORD_ABP_COUNTERS,
                                     &journal.counters,
                                     sizeof(journal.counters), false);
    }
    if ((ret == UDRV_RETURN_OK) && journal.channels_valid)
    {
        ret = journal_program_record(LORA_JOURNAL_RECORD_ABP_CHANNELS,
                                     &journal.channels,
                                     sizeof(journal.channels), false);
    }
    if (ret != UDRV_RETURN_OK)
    {
        journal = previous;
        return ret;
    }

    ret = udrv_flash_program(page + 24U, sizeof(commit), (uint8_t *)&commit);
    if (ret == UDRV_RETURN_OK)
    {
        udrv_serial_log_printf(
            "+EVT:LORA_NVM_JOURNAL_PAGE,ADDR:0x%08lX,GEN:%lu\r\n",
            (unsigned long)page, (unsigned long)generation);
    }
    else
    {
        journal = previous;
    }
    return ret;
}

static int32_t journal_rotate(void)
{
    uint32_t destination = (journal.active_page == LORA_JOURNAL_PAGE_A) ?
                           LORA_JOURNAL_PAGE_B : LORA_JOURNAL_PAGE_A;
    return journal_create_page(destination, journal.generation + 1U);
}

static int32_t journal_program_record(uint16_t type, const void *payload,
                                      uint16_t length, bool allow_rotate)
{
    uint32_t payload_size = journal_align8(length);
    uint32_t total_size = LORA_JOURNAL_RECORD_HEADER_SIZE + payload_size +
                          sizeof(uint64_t);
    uint8_t record[352] __attribute__((aligned(8)));
    lora_journal_record_header_t *header =
        (lora_journal_record_header_t *)record;
    uint64_t *commit;
    int32_t ret;

    if (total_size > sizeof(record))
    {
        return -UDRV_BUFF_OVERFLOW;
    }
    if (allow_rotate && journal.rotate_required)
    {
        ret = journal_rotate();
        if (ret != UDRV_RETURN_OK)
        {
            return ret;
        }
    }
    if ((journal.append_offset + total_size) > LORA_JOURNAL_PAGE_SIZE)
    {
        if (!allow_rotate)
        {
            return -UDRV_BUFF_OVERFLOW;
        }
        ret = journal_rotate();
        if (ret != UDRV_RETURN_OK)
        {
            return ret;
        }
    }

    memset(record, 0xFF, total_size);
    header->magic = LORA_JOURNAL_RECORD_MAGIC;
    header->sequence = journal.next_sequence++;
    header->type = type;
    header->payload_length = length;
    header->payload_crc = journal_crc32(payload, length);
    header->reserved = 0xFFFFFFFFUL;
    header->header_crc = journal_record_header_crc(header);
    memcpy(record + LORA_JOURNAL_RECORD_HEADER_SIZE, payload, length);
    commit = (uint64_t *)(record + LORA_JOURNAL_RECORD_HEADER_SIZE + payload_size);
    *commit = LORA_JOURNAL_COMMIT;

    ret = udrv_flash_program(journal.active_page + journal.append_offset,
                             total_size, record);
    if (ret == UDRV_RETURN_OK)
    {
        journal_apply_record(type, header->sequence, payload, length);
        journal.append_offset += total_size;
        udrv_serial_log_printf(
            "+EVT:LORA_NVM_JOURNAL_WRITE,TYPE:%u,SEQ:%lu,LEN:%u\r\n",
            (unsigned int)type, (unsigned long)header->sequence,
            (unsigned int)length);
    }
    else
    {
        /* The failed operation may have programmed a partial double-word. */
        journal.rotate_required = true;
    }
    return ret;
}

static bool journal_fixed_channel_region(LoRaMacRegion_t region)
{
    return (region == LORAMAC_REGION_AU915) ||
           (region == LORAMAC_REGION_US915) ||
           (region == LORAMAC_REGION_CN470) ||
           (region == LORAMAC_REGION_LA915);
}

int32_t service_lora_nvm_journal_init(void)
{
    lora_journal_page_header_t header_a;
    lora_journal_page_header_t header_b;
    bool valid_a;
    bool valid_b;
    lora_journal_scan_result_t active_scan;
    lora_journal_scan_result_t fallback_scan = {0};
    uint32_t highest_sequence;
    uint32_t legacy_devnonce = 0;
    uint32_t bad_page = 0;
    uint32_t fault_address = 0;
    uint32_t scan_limit = LORA_JOURNAL_PAGE_SIZE;
    bool legacy_present = false;
    bool eccd_pending;

    memset(&journal, 0, sizeof(journal));
    eccd_pending = uhal_flash_eccd_get_pending(&bad_page, &fault_address);
    valid_a = !eccd_pending || (bad_page != LORA_JOURNAL_PAGE_A) ||
              (fault_address >= (LORA_JOURNAL_PAGE_A +
                                  LORA_JOURNAL_PAGE_HEADER_SIZE));
    valid_b = !eccd_pending || (bad_page != LORA_JOURNAL_PAGE_B) ||
              (fault_address >= (LORA_JOURNAL_PAGE_B +
                                  LORA_JOURNAL_PAGE_HEADER_SIZE));
    valid_a = valid_a &&
              journal_page_header_valid(LORA_JOURNAL_PAGE_A, &header_a);
    valid_b = valid_b &&
              journal_page_header_valid(LORA_JOURNAL_PAGE_B, &header_b);

    if (valid_a || valid_b)
    {
        if (valid_a && valid_b)
        {
            journal.active_page =
                journal_sequence_is_newer(header_b.generation,
                                          header_a.generation) ?
                LORA_JOURNAL_PAGE_B : LORA_JOURNAL_PAGE_A;
        }
        else
        {
            journal.active_page = valid_b ? LORA_JOURNAL_PAGE_B :
                                            LORA_JOURNAL_PAGE_A;
        }
        journal.generation = (journal.active_page == LORA_JOURNAL_PAGE_A) ?
                             header_a.generation : header_b.generation;
        if (eccd_pending && (bad_page == journal.active_page))
        {
            scan_limit = fault_address - bad_page;
        }
        if (eccd_pending && (bad_page == journal.active_page) &&
            valid_a && valid_b)
        {
            uint32_t fallback_page =
                (journal.active_page == LORA_JOURNAL_PAGE_A) ?
                LORA_JOURNAL_PAGE_B : LORA_JOURNAL_PAGE_A;
            fallback_scan = journal_scan_page(fallback_page,
                                              LORA_JOURNAL_PAGE_SIZE);
        }
        active_scan = journal_scan_page(journal.active_page, scan_limit);
        highest_sequence = fallback_scan.highest_sequence;
        if ((highest_sequence == 0U) ||
            ((active_scan.highest_sequence != 0U) &&
             journal_sequence_is_newer(active_scan.highest_sequence,
                                       highest_sequence)))
        {
            highest_sequence = active_scan.highest_sequence;
        }
        journal.append_offset = active_scan.append_offset;
        journal.rotate_required = active_scan.dirty_tail;
        journal.next_sequence = highest_sequence + 1U;
        if (journal.next_sequence == 0U)
        {
            journal.next_sequence = 1U;
        }
        journal.initialized = true;
        if (eccd_pending)
        {
            int32_t recovery_result;
            if (bad_page == journal.active_page)
            {
                if (valid_a && valid_b)
                {
                    /*
                     * Rebuild the damaged page while the committed fallback
                     * page remains intact until the new page is committed.
                     */
                    recovery_result = journal_create_page(
                        bad_page, journal.generation + 1U);
                }
                else
                {
                    recovery_result = journal_rotate();
                    if (recovery_result == UDRV_RETURN_OK)
                    {
                        recovery_result = udrv_flash_erase(
                            bad_page, LORA_JOURNAL_PAGE_SIZE);
                    }
                }
            }
            else
            {
                recovery_result = udrv_flash_erase(
                    bad_page, LORA_JOURNAL_PAGE_SIZE);
            }
            uhal_flash_eccd_complete_lora_recovery(recovery_result);
            uhal_flash_eccd_log_recovery();
            if (recovery_result != UDRV_RETURN_OK)
            {
                journal.initialized = false;
            }
            return recovery_result;
        }
        return UDRV_RETURN_OK;
    }

    if (eccd_pending)
    {
        uint32_t destination = (bad_page == LORA_JOURNAL_PAGE_A) ?
                               LORA_JOURNAL_PAGE_B : LORA_JOURNAL_PAGE_A;
        if (bad_page != LORA_JOURNAL_PAGE_A)
        {
            uint32_t first_word =
                *(const uint32_t *)(uintptr_t)LORA_JOURNAL_PAGE_A;
            if ((first_word != 0xFFFFFFFFUL) &&
                (first_word != LORA_JOURNAL_PAGE_MAGIC))
            {
                memcpy(&legacy_devnonce,
                       (const void *)(uintptr_t)(LORA_JOURNAL_PAGE_A +
                       offsetof(lora_mac_nvm_data_t, loramac_crypto_nvm) +
                       offsetof(LoRaMacCryptoNvmData_t, DevNonce)),
                       sizeof(uint16_t));
            }
        }
        journal.devnonce.reserved_until =
            (legacy_devnonce != 0xFFFFU) ? legacy_devnonce : 0U;
        journal.devnonce_valid = true;
        journal.next_sequence = 1U;
        int32_t recovery_result = journal_create_page(destination, 1U);
        if (recovery_result == UDRV_RETURN_OK)
        {
            recovery_result = udrv_flash_erase(
                bad_page, LORA_JOURNAL_PAGE_SIZE);
        }
        uhal_flash_eccd_complete_lora_recovery(recovery_result);
        uhal_flash_eccd_log_recovery();
        journal.initialized = (recovery_result == UDRV_RETURN_OK);
        return recovery_result;
    }

    memcpy(&legacy_devnonce,
           (const void *)(uintptr_t)(LORA_JOURNAL_PAGE_A +
           offsetof(lora_mac_nvm_data_t, loramac_crypto_nvm) +
           offsetof(LoRaMacCryptoNvmData_t, DevNonce)),
           sizeof(uint16_t));
    legacy_present =
        (*(const uint32_t *)(uintptr_t)LORA_JOURNAL_PAGE_A != 0xFFFFFFFFUL) &&
        (*(const uint32_t *)(uintptr_t)LORA_JOURNAL_PAGE_A !=
         LORA_JOURNAL_PAGE_MAGIC);
    journal.devnonce.reserved_until =
        (legacy_present && (legacy_devnonce != 0xFFFFU)) ?
        legacy_devnonce : 0U;
    journal.devnonce_valid = true;
    journal.next_sequence = 1U;

    if (journal_create_page(legacy_present ? LORA_JOURNAL_PAGE_B :
                                             LORA_JOURNAL_PAGE_A, 1U) !=
        UDRV_RETURN_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    journal.initialized = true;
    return UDRV_RETURN_OK;
}

uint16_t service_lora_nvm_journal_get_devnonce(void)
{
    if (!journal.initialized || !journal.devnonce_valid ||
        (journal.devnonce.reserved_until > 0xFFFFUL))
    {
        return 0;
    }
    return (uint16_t)journal.devnonce.reserved_until;
}

int32_t service_lora_nvm_journal_prepare_devnonce(uint16_t current_devnonce)
{
    lora_journal_devnonce_t next;

    if (!journal.initialized)
    {
        return -UDRV_INTERNAL_ERR;
    }
    if (journal.devnonce_valid &&
        ((uint32_t)current_devnonce < journal.devnonce.reserved_until))
    {
        return UDRV_RETURN_OK;
    }
    if (current_devnonce > (0xFFFFU - LORA_JOURNAL_RESERVATION_BLOCK))
    {
        return -UDRV_INTERNAL_ERR;
    }

    next.reserved_until =
        (uint32_t)current_devnonce + LORA_JOURNAL_RESERVATION_BLOCK;
    return journal_program_record(LORA_JOURNAL_RECORD_DEVNONCE, &next,
                                  sizeof(next), true);
}

int32_t service_lora_nvm_journal_prepare_fcnt_up(LoRaMacNvmData_t *nvm)
{
    lora_journal_abp_counters_t next;
    uint32_t session_id = journal_session_id();
    uint32_t current = nvm->Crypto.FCntList.FCntUp;

    if (!journal.initialized)
    {
        return -UDRV_INTERNAL_ERR;
    }
    if (!journal.counters_valid || (journal.counters.session_id != session_id))
    {
        memset(&next, 0, sizeof(next));
        next.session_id = session_id;
        next.fcnt_up_reserved_until = current;
    }
    else
    {
        next = journal.counters;
    }

    if (current < next.fcnt_up_reserved_until)
    {
        return UDRV_RETURN_OK;
    }
    if (current > (0xFFFFFFFFUL - LORA_JOURNAL_RESERVATION_BLOCK))
    {
        return -UDRV_INTERNAL_ERR;
    }
    next.fcnt_up_reserved_until = current + LORA_JOURNAL_RESERVATION_BLOCK;
    return journal_program_record(LORA_JOURNAL_RECORD_ABP_COUNTERS, &next,
                                  sizeof(next), true);
}

int32_t service_lora_nvm_journal_store_abp(LoRaMacNvmData_t *nvm,
                                           uint16_t notify_flags)
{
    int32_t ret = UDRV_RETURN_OK;
    uint32_t session_id = journal_session_id();

    if (!journal.initialized)
    {
        return -UDRV_INTERNAL_ERR;
    }
    if ((notify_flags & LORAMAC_NVM_NOTIFY_FLAG_CRYPTO) != 0U)
    {
        lora_journal_abp_counters_t next;
        memset(&next, 0, sizeof(next));
        next.session_id = session_id;
        next.fcnt_up_reserved_until =
            (journal.counters_valid &&
             (journal.counters.session_id == session_id)) ?
            journal.counters.fcnt_up_reserved_until :
            nvm->Crypto.FCntList.FCntUp;
        next.nfcnt_down = nvm->Crypto.FCntList.NFCntDown;
        next.afcnt_down = nvm->Crypto.FCntList.AFCntDown;
        next.fcnt_down = nvm->Crypto.FCntList.FCntDown;
        memcpy(next.mc_fcnt_down, nvm->Crypto.FCntList.McFCntDown,
               sizeof(next.mc_fcnt_down));
        next.last_down_fcnt = nvm->Crypto.LastDownFCnt;
        next.last_rx_mic = nvm->MacGroup1.LastRxMic;

        if (!journal.counters_valid ||
            (memcmp(&next, &journal.counters, sizeof(next)) != 0))
        {
            ret = journal_program_record(LORA_JOURNAL_RECORD_ABP_COUNTERS,
                                         &next, sizeof(next), true);
        }
    }

    if ((ret == UDRV_RETURN_OK) &&
        ((notify_flags & LORAMAC_NVM_NOTIFY_FLAG_REGION_GROUP2) != 0U))
    {
        lora_journal_abp_channels_t next;
        memset(&next, 0, sizeof(next));
        next.session_id = session_id;
        next.region = (uint8_t)nvm->MacGroup2.Region;
        next.mask_words = REGION_NVM_CHANNELS_MASK_SIZE;
        memcpy(next.channels_mask, nvm->RegionGroup2.ChannelsMask,
               sizeof(next.channels_mask));

        if (!journal_fixed_channel_region(nvm->MacGroup2.Region))
        {
            for (uint8_t index = 0;
                 (index < REGION_NVM_MAX_NB_CHANNELS) &&
                 (next.channel_count < LORA_JOURNAL_MAX_CHANNELS);
                 index++)
            {
                ChannelParams_t *source = &nvm->RegionGroup2.Channels[index];
                lora_journal_channel_t *destination;
                if (source->Frequency == 0U)
                {
                    continue;
                }
                destination = &next.channels[next.channel_count++];
                destination->frequency = source->Frequency;
                destination->rx1_frequency = source->Rx1Frequency;
                destination->index = index;
                destination->dr_min = source->DrRange.Fields.Min;
                destination->dr_max = source->DrRange.Fields.Max;
                destination->band = source->Band;
            }
        }

        if (!journal.channels_valid ||
            (memcmp(&next, &journal.channels, sizeof(next)) != 0))
        {
            ret = journal_program_record(LORA_JOURNAL_RECORD_ABP_CHANNELS,
                                         &next, sizeof(next), true);
        }
    }
    return ret;
}

void service_lora_nvm_journal_restore_abp(LoRaMacNvmData_t *nvm)
{
    uint32_t session_id = journal_session_id();

    if (!journal.initialized)
    {
        return;
    }
    if (journal.counters_valid &&
        (journal.counters.session_id == session_id))
    {
        nvm->Crypto.FCntList.FCntUp =
            journal.counters.fcnt_up_reserved_until;
        nvm->Crypto.FCntList.NFCntDown = journal.counters.nfcnt_down;
        nvm->Crypto.FCntList.AFCntDown = journal.counters.afcnt_down;
        nvm->Crypto.FCntList.FCntDown = journal.counters.fcnt_down;
        memcpy(nvm->Crypto.FCntList.McFCntDown,
               journal.counters.mc_fcnt_down,
               sizeof(journal.counters.mc_fcnt_down));
        nvm->Crypto.LastDownFCnt = journal.counters.last_down_fcnt;
        nvm->MacGroup1.LastRxMic = journal.counters.last_rx_mic;
    }

    if (journal.channels_valid &&
        (journal.channels.session_id == session_id) &&
        (journal.channels.region == (uint8_t)nvm->MacGroup2.Region) &&
        (journal.channels.mask_words == REGION_NVM_CHANNELS_MASK_SIZE))
    {
        memcpy(nvm->RegionGroup2.ChannelsMask,
               journal.channels.channels_mask,
               sizeof(journal.channels.channels_mask));
        for (uint8_t i = 0; i < journal.channels.channel_count; i++)
        {
            const lora_journal_channel_t *source = &journal.channels.channels[i];
            ChannelParams_t *destination;
            if (source->index >= REGION_NVM_MAX_NB_CHANNELS)
            {
                continue;
            }
            destination = &nvm->RegionGroup2.Channels[source->index];
            destination->Frequency = source->frequency;
            destination->Rx1Frequency = source->rx1_frequency;
            destination->DrRange.Fields.Min = source->dr_min;
            destination->DrRange.Fields.Max = source->dr_max;
            destination->Band = source->band;
        }
    }
}

int32_t service_lora_nvm_journal_reset_abp(void)
{
    if (!journal.initialized)
    {
        return -UDRV_INTERNAL_ERR;
    }
    journal.counters_valid = false;
    journal.channels_valid = false;
    return journal_rotate();
}

#endif

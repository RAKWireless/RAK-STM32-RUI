#include "uhal_flash.h"
#include "uhal_powersave.h"

#ifndef RUI_BOOTLOADER
#include "mcu_basic.h"
#include "udrv_serial.h"

#define UHAL_FLASH_PAGE_SIZE                 2048UL
#define UHAL_FLASH_END_ADDR                  0x08040000UL
#define UHAL_FLASH_ECCD_RECORD_MAGIC         0x45434344UL
#define UHAL_FLASH_ECCD_RECORD_CHECK         0xA56CF03DUL

typedef struct
{
    uint32_t magic;
    uint32_t magic_inv;
    uint32_t page_address;
    uint32_t page_address_inv;
    uint32_t eccr;
    uint32_t attempt;
    uint32_t checksum;
} uhal_flash_eccd_record_t;

typedef enum
{
    UHAL_FLASH_ECCD_ACTION_NONE = 0,
    UHAL_FLASH_ECCD_ACTION_ERASE_PAGE,
    UHAL_FLASH_ECCD_ACTION_ERASE_LORA_NVM,
    UHAL_FLASH_ECCD_ACTION_DEFER_LORA_JOURNAL,
    UHAL_FLASH_ECCD_ACTION_RECOVER_LORA_JOURNAL,
    UHAL_FLASH_ECCD_ACTION_RESTORE_CONFIG,
    UHAL_FLASH_ECCD_ACTION_DEFAULT_CONFIG,
    UHAL_FLASH_ECCD_ACTION_SKIPPED,
} uhal_flash_eccd_action_t;

typedef struct
{
    bool valid;
    uint32_t page_address;
    uint32_t eccr;
    uint32_t attempt;
    uhal_flash_eccd_action_t action;
    int32_t result;
} uhal_flash_eccd_report_t;


__attribute__((section(".RAM2_region"), used, aligned(8)))
static volatile uhal_flash_eccd_record_t uhal_flash_eccd_record;

static uhal_flash_eccd_report_t uhal_flash_eccd_report;

static uint32_t uhal_flash_eccd_checksum(uint32_t page_address,
                                         uint32_t eccr,
                                         uint32_t attempt)
{
    return UHAL_FLASH_ECCD_RECORD_CHECK ^
           page_address ^
           eccr ^
           attempt;
}

static bool uhal_flash_eccd_record_is_valid(
    const volatile uhal_flash_eccd_record_t *record)
{
    uint32_t magic = record->magic;
    uint32_t page_address = record->page_address;
    uint32_t eccr = record->eccr;
    uint32_t attempt = record->attempt;

    return (magic == UHAL_FLASH_ECCD_RECORD_MAGIC) &&
           (record->magic_inv == ~UHAL_FLASH_ECCD_RECORD_MAGIC) &&
           (record->page_address_inv == ~page_address) &&
           (record->checksum ==
            uhal_flash_eccd_checksum(page_address, eccr, attempt));
}

static void uhal_flash_eccd_store_record(uint32_t page_address,
                                          uint32_t eccr)
{
    uint32_t attempt = 1;

    if (uhal_flash_eccd_record_is_valid(&uhal_flash_eccd_record) &&
        (uhal_flash_eccd_record.page_address == page_address))
    {
        attempt = uhal_flash_eccd_record.attempt + 1;
        if (attempt == 0)
        {
            attempt = 0xFFFFFFFFUL;
        }
    }

    uhal_flash_eccd_record.magic = 0;
    uhal_flash_eccd_record.magic_inv = ~UHAL_FLASH_ECCD_RECORD_MAGIC;
    uhal_flash_eccd_record.page_address = page_address;
    uhal_flash_eccd_record.page_address_inv = ~page_address;
    uhal_flash_eccd_record.eccr = eccr;
    uhal_flash_eccd_record.attempt = attempt;
    uhal_flash_eccd_record.checksum =
        uhal_flash_eccd_checksum(page_address, eccr, attempt);
    __DMB();
    uhal_flash_eccd_record.magic = UHAL_FLASH_ECCD_RECORD_MAGIC;
    __DSB();
}

static void uhal_flash_eccd_clear_record(void)
{
    uhal_flash_eccd_record.magic = 0;
    __DSB();
}
#endif


/**@brief   Sleep until an event is received. */
static void power_manage(void){
}


void uhal_flash_init (void) {
}

void uhal_flash_deinit (void) {
}

int32_t uhal_flash_write (uint32_t addr, uint8_t *buff, uint32_t len) {
    /* Unlock the Flash to enable the flash control register access *************/
    HAL_FLASH_Unlock();
  
    /* Clear all error flags */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_SR_ERRORS);

    uint32_t uhal_addr = addr;     
    uint8_t* data = buff;
    while(uhal_addr < addr + len) {
      if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, uhal_addr, *(uint64_t *)data) == HAL_OK) {
          uhal_addr += 8;
    	  data += 8;
      } else {
	  HAL_FLASH_Lock();
          return -UDRV_INTERNAL_ERR;
      }
    }

    HAL_FLASH_Lock();
    return UDRV_RETURN_OK;
}

int32_t uhal_flash_read (uint32_t addr, uint8_t *buff, uint32_t len) {
    memcpy(buff, (__IO uint8_t*)addr, len);
    return UDRV_RETURN_OK;
}

int32_t uhal_flash_erase (uint32_t addr, uint32_t len) {
    /* Unlock the Flash to enable the flash control register access *************/
    HAL_FLASH_Unlock();
  
    /* Clear all error flags */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_SR_ERRORS);

    uint32_t page_cnt = len / uhal_flash_get_page_size();
    uint32_t pageError = 0;

    static FLASH_EraseInitTypeDef EraseInitStruct;
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Page      = (addr - 0x08000000) / uhal_flash_get_page_size();
    EraseInitStruct.NbPages   = page_cnt; 

    HAL_StatusTypeDef erase_status =
        HAL_FLASHEx_Erase(&EraseInitStruct, &pageError);
    if (erase_status != HAL_OK) {
      HAL_FLASH_Lock();
      return -UDRV_INTERNAL_ERR;
    }
    HAL_FLASH_Lock();
    return UDRV_RETURN_OK;
}

uint32_t uhal_flash_get_page_size(void) {
    return 2048;
}

bool uhal_flash_check_addr_valid(uint32_t addr, uint32_t len) {
    return 0;
}

void uhal_flash_suspend(void) {
}

void uhal_flash_resume(void) {
}


#ifndef RUI_BOOTLOADER
bool uhal_flash_eccd_nmi_handler(void)
{
    uint32_t eccr = FLASH->ECCR;
    uint32_t flash_address;
    uint32_t page_address;

    if ((eccr & FLASH_ECCR_ECCD) == 0)
    {
        return false;
    }

    if ((eccr & FLASH_ECCR_SYSF_ECC) != 0)
    {
        page_address = 0xFFFFFFFFUL;
    }
    else
    {
        /*
         * ADDR_ECC stores the failing double-word index. Convert it to a
         * byte address, then retain the physical 2 KB page for recovery.
         */
        flash_address =
            FLASH_BASE + ((eccr & FLASH_ECCR_ADDR_ECC) << 3U);
        page_address = flash_address & ~(UHAL_FLASH_PAGE_SIZE - 1U);
    }

    uhal_flash_eccd_store_record(page_address, eccr);
    return true;
}

void uhal_flash_eccd_early_recovery(void)
{
    uint32_t page_address;
    int32_t ret = UDRV_RETURN_OK;
    uhal_flash_eccd_action_t action = UHAL_FLASH_ECCD_ACTION_NONE;
    bool is_factory_page;
    bool is_lora_nvm_page;
    bool is_active_config_page;

    uhal_flash_eccd_report.valid = false;

    if (!uhal_flash_eccd_record_is_valid(&uhal_flash_eccd_record))
    {
        return;
    }

    page_address = uhal_flash_eccd_record.page_address;
    uhal_flash_eccd_report.valid = true;
    uhal_flash_eccd_report.page_address = page_address;
    uhal_flash_eccd_report.eccr = uhal_flash_eccd_record.eccr;
    uhal_flash_eccd_report.attempt = uhal_flash_eccd_record.attempt;

    is_factory_page = (page_address == MCU_FACTORY_DEFAULT_NVM_ADDR);
    is_lora_nvm_page =
        (page_address >= MCU_CERT_CONFIG_NVM_ADDR) &&
        (page_address < MCU_SYS_CONFIG_NVM_ADDR);
    is_active_config_page = (page_address == MCU_SYS_CONFIG_NVM_ADDR);

    /*
     * Never erase bootloader or application code automatically. The only
     * automatically recoverable pages are the factory backup, LoRa NVM, and
     * active RUI configuration. In particular, user-data pages are not
     * erased because the firmware has no authoritative copy to restore.
     */
    if ((page_address >= UHAL_FLASH_END_ADDR) ||
        ((page_address & (UHAL_FLASH_PAGE_SIZE - 1U)) != 0) ||
        (!is_factory_page && !is_lora_nvm_page && !is_active_config_page))
    {
        action = UHAL_FLASH_ECCD_ACTION_SKIPPED;
        ret = -UDRV_FORBIDDEN;
        uhal_flash_eccd_clear_record();
        goto out;
    }

    if (is_lora_nvm_page)
    {
        /*
         * The journal must scan the committed prefix before this page is
         * erased. Keep the SRAM ECCD record until service NVM completes
         * the single-page recovery.
         */
        action = UHAL_FLASH_ECCD_ACTION_DEFER_LORA_JOURNAL;
        ret = UDRV_RETURN_OK;
        goto out;
    }
    else
    {
        action = UHAL_FLASH_ECCD_ACTION_ERASE_PAGE;
        ret = uhal_flash_erase(page_address, UHAL_FLASH_PAGE_SIZE);
    }

    if ((ret == UDRV_RETURN_OK) && is_active_config_page)
    {
        uint64_t factory_first_double_word =
            *(const volatile uint64_t *)MCU_FACTORY_DEFAULT_NVM_ADDR;

        if (factory_first_double_word != 0xFFFFFFFFFFFFFFFFULL)
        {
            action = UHAL_FLASH_ECCD_ACTION_RESTORE_CONFIG;
            ret = uhal_flash_write(
                MCU_SYS_CONFIG_NVM_ADDR,
                (uint8_t *)MCU_FACTORY_DEFAULT_NVM_ADDR,
                UHAL_FLASH_PAGE_SIZE);
        }
        else
        {
            /*
             * No AT+FACTORY backup exists. Keep the page erased so
             * service_nvm_init_config() applies the built-in defaults.
             */
            action = UHAL_FLASH_ECCD_ACTION_DEFAULT_CONFIG;
        }
    }

    if (ret == UDRV_RETURN_OK)
    {
        uhal_flash_eccd_clear_record();
    }

out:
    uhal_flash_eccd_report.action = action;
    uhal_flash_eccd_report.result = ret;
}

bool uhal_flash_eccd_get_pending(uint32_t *page_address,
                                  uint32_t *fault_address)
{
    uint32_t eccr;

    if (!uhal_flash_eccd_record_is_valid(&uhal_flash_eccd_record))
    {
        return false;
    }
    eccr = uhal_flash_eccd_record.eccr;
    if ((eccr & FLASH_ECCR_SYSF_ECC) != 0U)
    {
        return false;
    }
    if ((uhal_flash_eccd_record.page_address < MCU_CERT_CONFIG_NVM_ADDR) ||
        (uhal_flash_eccd_record.page_address >= MCU_SYS_CONFIG_NVM_ADDR))
    {
        return false;
    }
    if (page_address != NULL)
    {
        *page_address = uhal_flash_eccd_record.page_address;
    }
    if (fault_address != NULL)
    {
        *fault_address = FLASH_BASE +
            ((eccr & FLASH_ECCR_ADDR_ECC) << 3U);
    }
    return true;
}

void uhal_flash_eccd_complete_lora_recovery(int32_t result)
{
    uhal_flash_eccd_report.action =
        UHAL_FLASH_ECCD_ACTION_RECOVER_LORA_JOURNAL;
    uhal_flash_eccd_report.result = result;
    if (result == UDRV_RETURN_OK)
    {
        uhal_flash_eccd_clear_record();
    }
}

void uhal_flash_eccd_log_recovery(void)
{
    const char *action;

    if (uhal_flash_eccd_report.valid)
    {
        switch (uhal_flash_eccd_report.action)
        {
        case UHAL_FLASH_ECCD_ACTION_ERASE_PAGE:
            action = "ERASE_PAGE";
            break;
        case UHAL_FLASH_ECCD_ACTION_ERASE_LORA_NVM:
            action = "ERASE_LORA_NVM";
            break;
        case UHAL_FLASH_ECCD_ACTION_DEFER_LORA_JOURNAL:
            action = "DEFER_LORA_JOURNAL";
            break;
        case UHAL_FLASH_ECCD_ACTION_RECOVER_LORA_JOURNAL:
            action = "RECOVER_LORA_JOURNAL";
            break;
        case UHAL_FLASH_ECCD_ACTION_RESTORE_CONFIG:
            action = "RESTORE_CONFIG";
            break;
        case UHAL_FLASH_ECCD_ACTION_DEFAULT_CONFIG:
            action = "DEFAULT_CONFIG";
            break;
        case UHAL_FLASH_ECCD_ACTION_SKIPPED:
            action = "SKIPPED";
            break;
        default:
            action = "NONE";
            break;
        }

        udrv_serial_log_printf(
            "+EVT:FLASH_ECCD_RECOVERY,ECCR:0x%08lX,ADDR:0x%08lX,"
            "ATTEMPT:%lu,ACTION:%s,RESULT:%ld\r\n",
            (unsigned long)uhal_flash_eccd_report.eccr,
            (unsigned long)uhal_flash_eccd_report.page_address,
            (unsigned long)uhal_flash_eccd_report.attempt,
            action,
            (long)uhal_flash_eccd_report.result);
    }

}


#endif

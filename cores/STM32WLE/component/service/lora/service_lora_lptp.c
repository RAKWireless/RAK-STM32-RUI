#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "LoRaMac.h"
#include "Region.h"
#include "systime.h"
#include "utilities.h"
#include "service_lora_test.h"

extern rui_cfg_t g_rui_cfg_t;

#define LPTP_DATA_BUFFER_MAX_SIZE               1024

/*!
 * Data parameters of Subcontracting
 */
static uint8_t AppPort;
static uint8_t AppData[256] = {0};
static uint8_t AppLen = 0;

/*!
 * Long packet data parameters
 */
uint8_t lp_data[1024];
uint32_t lp_len = 0;

bool lptp_enable = false;

/*!
 * Packet transfer parameter structure
 */
typedef struct _LoRaPacket_LHDR_s{
    uint8_t  LType : 1;     // 0 - fixed length,  1 - variable length
    uint8_t  RetryFlag : 1; // 0 - normal packet,  1 - the current packet is a retransmission packet
    uint8_t  RSV : 6;       // Reserved
} __attribute__ ((packed)) LHDR_st;

typedef struct {
    LHDR_st header;             // LHDR_st
    uint8_t magic;              // A random data
    uint8_t fcnt;               // Total number of subcontracting
    uint8_t fser;               // Current number of packets to be subcontracted
    uint8_t fdata_len;          // Data filed length in current packet

    uint8_t *pdata;             // Data buffer pointer
    uint32_t data_total_len;    // Total data length
    uint32_t data_finish_len;   // The length of the data sent in the total data
    uint32_t data_packet_len;   // Maximum length of data field in single packet
    uint32_t confirm_status;    // confirmed / unconfirmed
}LP_State_st;

LP_State_st lp_state;

void lora_send_subcontract(void);

void printf_hex(uint8_t *pdata, uint16_t len)
{
    while(len--)
        udrv_serial_log_printf("%02X", *pdata++);
}

void service_lora_lptp_update_status(bool enable)
{
    lptp_enable = enable;
}

void service_lora_lptp_send_callback(int status)
{
    if (lptp_enable == false)
        return ;

    if (0 == status)
    {
        if (0 == lp_state.fcnt)
        {
            LORA_TEST_DEBUG("transmission is completed");
            // If the transmission is completed, it goes to sleep. 
            lptp_enable = false;
        }
        else
        {
            // If the transmission is successful, send the next packet.
            lp_state.header.RetryFlag = 0;
            lp_state.fser++;
            lp_state.data_finish_len += lp_state.fdata_len;
            lora_send_subcontract();
        }
    }
    else
    {
        // If the transmission is fails, resend the current packet
        lp_state.header.RetryFlag = 1;
        lora_send_subcontract();
    }
}

void lora_send_subcontract(void)
{
    uint32_t data_offset, data_remain_len;
    uint16_t payload_len;

    memset(AppData, 0x00, sizeof(AppData));
    AppLen = 0;

    payload_len = GetMaxAppPayloadWithFOptsLength();
    if (payload_len > 200) payload_len -= 20;
    LORA_TEST_DEBUG("Maximum payload size payload_len %d", payload_len);

    lp_state.data_packet_len = payload_len - 6;

    /*No need to subcontract transmission */
    if (lp_state.data_total_len <= lp_state.data_packet_len)
    {
        lp_state.fcnt = 0;

        data_offset = 0;
        lp_state.fdata_len = lp_state.data_total_len;
    }
    /*need to subcontract transmission */
    else
    {
        data_remain_len = lp_state.data_total_len - lp_state.data_finish_len;

        lp_state.fcnt = data_remain_len / lp_state.data_packet_len;
        if (0 != (data_remain_len % lp_state.data_packet_len))
            lp_state.fcnt++;

        lp_state.fcnt--;

        data_offset = lp_state.data_finish_len;
        lp_state.fdata_len = data_remain_len < lp_state.data_packet_len ? data_remain_len : lp_state.data_packet_len;
    }

    AppData[AppLen++] = *(uint8_t *)&lp_state.header;
    AppData[AppLen++] = lp_state.magic;
    AppData[AppLen++] = lp_state.fcnt;
    AppData[AppLen++] = lp_state.fser;
    AppData[AppLen++] = lp_state.fdata_len;

    memcpy(AppData+AppLen, &lp_state.pdata[data_offset], lp_state.fdata_len);
    AppLen += lp_state.fdata_len;

    // FCS
    for (uint8_t i=0; i<AppLen; i++)
        AppData[AppLen] += AppData[i];

    AppLen++;

    LORA_TEST_DEBUG("fcnt %d, fser %d port %d", lp_state.fcnt, lp_state.fser ,AppPort);
    LORA_TEST_DEBUG("fdata_len %d, data_total_len %d",lp_state.fdata_len ,lp_state.data_total_len);

    SERVICE_LORA_SEND_INFO info;

    info.port = AppPort;
    info.confirm_valid = true;
    if (lp_state.confirm_status) {
        info.confirm = SERVICE_LORA_ACK;
    } else {
        info.confirm = SERVICE_LORA_NO_ACK;
    }
    info.retry_valid = false;

    service_lora_send(AppData, AppLen, info, false);

    // udrv_serial_log_printf("(Send data is: ");
    // printf_hex(AppData, AppLen);
    // udrv_serial_log_printf(")\r\n");
}

int32_t service_lora_lptp_send(uint8_t port, bool ack, uint8_t *p_data, uint16_t len)
{
    if ((port == 0) || (port > 223))
        return -UDRV_WRONG_ARG;

    if( ack > 1)
        return -UDRV_WRONG_ARG;

    if (len > LPTP_DATA_BUFFER_MAX_SIZE)
        return -UDRV_WRONG_ARG;

    lptp_enable = true;
    
    /* There is no need for memory copy */
    memcpy(lp_data, p_data, len);
    lp_len = len;

    lp_state.header.RetryFlag = 0;
    lp_state.header.LType = 1;
    lp_state.magic = (uint8_t)RtcGetTimerValue(); // Radom
    lp_state.fser = 1;

    lp_state.pdata = lp_data;
    lp_state.data_finish_len = 0;
    lp_state.data_total_len = lp_len;

    lp_state.confirm_status = ack;

    AppPort = port;

    lora_send_subcontract();

    return UDRV_RETURN_OK;
}


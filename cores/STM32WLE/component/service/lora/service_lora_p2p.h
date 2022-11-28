/**
 * @file        service_lora_p2p.h
 * @brief       Provide LoRa service layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.6
 */

#ifndef __SERVICE_LORA_P2P_H__
#define __SERVICE_LORA_P2P_H__

#ifdef SUPPORT_LORA

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"


//#define P2P_DEBUG_ENABLE
#ifdef P2P_DEBUG_ENABLE
#define LORA_P2P_DEBUG(fmt, args...)      udrv_serial_log_printf(fmt, ##args)
#else
#define LORA_P2P_DEBUG(fmt, args...)
#endif


#define LORA_SYMBOL_TIMEOUT                         5         /* Symbols */
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false
    
#define LORA_BUFFER_SIZE                            255  /* Define the payload size here */
    
typedef struct {
    bool isRxCancel;
    bool isRadioBusy;
    bool isContinue;
    bool isContinue_no_exit;
    bool isContinue_compatible_tx;
}LORA_P2P_STATUS_ST;

typedef struct rui_lora_p2p_revc
{
    /*!
     * Pointer to the received data stream
     */
    uint8_t *Buffer;
    /*!
     * Size of the received data stream
     */
    uint8_t BufferSize;

    /*!
     * Rssi of the received packet
     */
    int16_t Rssi;
    /*!
     * Snr of the received packet
     */
    int8_t Snr;
} rui_lora_p2p_recv_t;

typedef void(*service_lora_p2p_send_cb_type)(void);
typedef void(*service_lora_p2p_recv_cb_type)(rui_lora_p2p_recv_t recv_data_pkg);

int32_t service_lora_p2p_init(void);

int32_t service_lora_p2p_config(void);

int32_t service_lora_p2p_send(uint8_t *p_data, uint8_t len);

int32_t service_lora_p2p_recv(uint32_t timeout);

uint32_t service_lora_p2p_get_freq (void);;

int32_t service_lora_p2p_set_freq (uint32_t freq);

uint8_t service_lora_p2p_get_sf (void);

int32_t service_lora_p2p_set_sf (uint8_t spreadfact);

uint32_t service_lora_p2p_get_bandwidth (void);

int32_t service_lora_p2p_set_bandwidth (uint32_t bandwidth);

uint8_t service_lora_p2p_get_codingrate (void);

int32_t service_lora_p2p_set_codingrate (uint8_t codingrate);

uint16_t service_lora_p2p_get_preamlen (void);

int32_t service_lora_p2p_set_preamlen (uint16_t preamlen);

uint8_t service_lora_p2p_get_powerdbm (void);

int32_t service_lora_p2p_set_powerdbm (uint8_t powerdbm);

bool service_lora_p2p_get_crypto_enable(void);

int32_t service_lora_p2p_set_crypto_enable(bool enable);

int32_t service_lora_p2p_get_crypto_key (uint8_t *buff, uint32_t len);

int32_t service_lora_p2p_set_crypto_key (uint8_t *buff, uint32_t len);

uint32_t service_lora_p2p_get_fdev(void);

int32_t service_lora_p2p_set_fdev(uint32_t fdev);

uint32_t service_lora_p2p_get_bitrate(void);

int32_t service_lora_p2p_set_bitrate(uint32_t bitrate);

int32_t service_lora_p2p_encrpty(uint8_t *indata, uint16_t inlen,uint8_t *outdata );

int32_t service_lora_p2p_decrpty(uint8_t *indata,uint16_t inlen ,uint8_t *outdata );

int32_t service_lora_p2p_register_send_cb(service_lora_p2p_send_cb_type callback);

int32_t service_lora_p2p_register_recv_cb(service_lora_p2p_recv_cb_type callback);

#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif  // __SERVICE_LORA_P2P_H__


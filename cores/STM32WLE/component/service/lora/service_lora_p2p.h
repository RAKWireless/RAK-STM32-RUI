/**
 * @file        service_lora_p2p.h
 * @brief       Provide LoRa service layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.6
 */

#ifndef __SERVICE_LORA_P2P_H__
#define __SERVICE_LORA_P2P_H__

#ifndef NO_LORA_SUPPORT

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"
#include "service_lora.h"

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
    
/**@par	Description
 *	The default syncword in P2P mode
 */
typedef enum
{
  LORA_MAC_PRIVATE_SYNCWORD = 0x1424, //  Syncword for Private LoRa networks
  LORA_MAC_PUBLIC_SYNCWORD =  0x3444  // Syncword for Public LoRa networks
} RAK_LORA_P2P_SYNCWORD;

/**@}*/

#ifdef rak4200
    #define LORA_CHIP_SX1276
#elif defined rak4630
    #define LORA_CHIP_SX126X
#elif defined rak11720
    #define LORA_CHIP_SX126X
#elif defined rak3172 \
      || defined rak3172-sip \
      || defined rak3172T
    #define LORA_CHIP_STM32WLE5XX
#endif

#ifdef LORA_CHIP_SX1276
    #define SYMBTIMEOUT_MAX 1023
#elif defined LORA_CHIP_SX126X
    #define SYMBTIMEOUT_MAX 248
#elif defined LORA_CHIP_STM32WLE5XX
    #define SYMBTIMEOUT_MAX 248
#else
    #define SYMBTIMEOUT_MAX 0
#endif

// #ifdef sx1276
//     #define SYMBTIMEOUT_MAX 1023
// #elif defined sx126x
//     #define SYMBTIMEOUT_MAX 248
// #elif defined stm32wle5xx
//     #define SYMBTIMEOUT_MAX 248
// #else
//     #define SYMBTIMEOUT_MAX 0
// #endif

typedef struct {
    bool isRxCancel;
    bool isRadioBusy;
    bool isContinue;
    bool isContinue_no_exit;
    bool isContinue_compatible_tx;
    volatile bool isCAD;
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
    /*!
     * Snr of the received packet
     */
    int8_t Status; //0:RxDone; 1:RxTimeout, 2:RxError
} rui_lora_p2p_recv_t;

/**@par Description
 *  The last RX status in P2P mode
 */
typedef enum
{
  LORA_P2P_RXDONE = 0, // Received data complete for LoRa P2P Rx status
  LORA_P2P_RXTIMEOUT, // Timeout for LoRa P2P Rx status
  LORA_P2P_RXERROR // Received data has CRC error for LoRa P2P Rx status
} RAK_LORA_P2P_RX_STATUS;

typedef void(*service_lora_p2p_send_cb_type)(void);
typedef void(*service_lora_p2p_recv_cb_type)(rui_lora_p2p_recv_t recv_data_pkg);
typedef void(*service_lora_p2p_send_CAD_cb_type)(bool);

SERVICE_LORA_WORK_MODE service_lora_p2p_get_nwm(void);

int32_t service_lora_p2p_set_nwm(SERVICE_LORA_WORK_MODE nwm);

int32_t service_lora_p2p_init(void);

int32_t service_lora_p2p_config(void);

int32_t service_lora_p2p_send(uint8_t *p_data, uint8_t len, bool cad_enable);

int32_t service_lora_p2p_recv(uint32_t timeout);

uint32_t service_lora_p2p_get_freq (void);;

int32_t service_lora_p2p_set_freq (uint32_t freq);

int32_t service_lora_p2p_check_runtime_freq(uint32_t freq);

uint8_t service_lora_p2p_get_sf (void);

int32_t service_lora_p2p_set_sf (uint8_t spreadfact);

int32_t service_lora_p2p_check_runtime_sf(uint8_t spreadfact);

uint32_t service_lora_p2p_get_bandwidth (void);

int32_t service_lora_p2p_set_bandwidth (uint32_t bandwidth);

int32_t service_lora_p2p_check_runtime_bandwidth(uint32_t bandwidth);

uint8_t service_lora_p2p_get_codingrate (void);

int32_t service_lora_p2p_set_codingrate (uint8_t codingrate);

int32_t service_lora_p2p_check_runtime_codingrate(uint8_t codingrate);

uint16_t service_lora_p2p_get_preamlen (void);

int32_t service_lora_p2p_set_preamlen (uint16_t preamlen);

int32_t service_lora_p2p_check_runtime_preamlen(uint16_t preamlen);

uint8_t service_lora_p2p_get_powerdbm (void);

int32_t service_lora_p2p_set_powerdbm (uint8_t powerdbm);

int32_t service_lora_p2p_check_runtime_powerdbm(uint8_t powerdbm);

bool service_lora_p2p_get_crypto_enable(void);

int32_t service_lora_p2p_set_crypto_enable(bool enable);

int32_t service_lora_p2p_get_crypto_key (uint8_t *buff, uint32_t len);

int32_t service_lora_p2p_set_crypto_key (uint8_t *buff, uint32_t len);

int32_t service_lora_p2p_get_crypto_IV (uint8_t *buff, uint32_t len);

int32_t service_lora_p2p_set_crypto_IV (uint8_t *buff, uint32_t len);

uint32_t service_lora_p2p_get_fdev(void);

int32_t service_lora_p2p_set_fdev(uint32_t fdev);

uint32_t service_lora_p2p_get_bitrate(void);

int32_t service_lora_p2p_set_bitrate(uint32_t bitrate);

int32_t service_lora_p2p_encrpty(uint8_t *indata, uint16_t inlen,uint8_t *outdata );

int32_t service_lora_p2p_decrpty(uint8_t *indata,uint16_t inlen ,uint8_t *outdata );

int32_t service_lora_p2p_register_send_cb(service_lora_p2p_send_cb_type callback);

int32_t service_lora_p2p_register_send_CAD_cb(service_lora_p2p_send_CAD_cb_type callback);

int32_t service_lora_p2p_register_recv_cb(service_lora_p2p_recv_cb_type callback);

bool service_lora_p2p_get_public_network(void);

int32_t service_lora_p2p_set_public_network(bool enable);

uint32_t service_lora_p2p_get_symbol_timeout(void);

int32_t service_lora_p2p_set_symbol_timeout(uint32_t symbol_timeout);

bool service_lora_p2p_get_iqinverted(void);

int32_t service_lora_p2p_set_iqinverted(bool iqinverted);

bool service_lora_p2p_get_fix_length_payload(void);

int32_t service_lora_p2p_set_fix_length_payload(bool enable);

uint16_t service_lora_p2p_get_syncword(void);

int32_t service_lora_p2p_set_syncword( uint16_t syncword );

bool service_lora_p2p_get_CAD(void);

int32_t service_lora_p2p_set_CAD(bool enable);

bool service_lora_p2p_get_radio_stat(void);


#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif  // __SERVICE_LORA_P2P_H__


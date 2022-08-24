#ifndef __SERVICE_LORA_TEST_H__
#define __SERVICE_LORA_TEST_H__

#ifdef SUPPORT_LORA

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"

//#define _TEST_DEBUG_ENABLE
#ifdef  _TEST_DEBUG_ENABLE
#define LORA_TEST_DEBUG(fmt, args...)      udrv_serial_log_printf("(Line:%d,Func:%s)[DEBUG]"fmt"\r\n",__LINE__,__func__,##args)
#else
#define LORA_TEST_DEBUG(fmt, args...)
#endif


/*!
 * \brief Sets the reception parameters
 *
 * \param [IN] modem        Radio modem to be used [0: FSK, 1: LoRa]
 * \param [IN] bandwidth    Sets the bandwidth
 *                          FSK : >= 2600 and <= 250000 Hz
 *                          LoRa: [0: 125 kHz, 1: 250 kHz,
 *                                 2: 500 kHz, 3: Reserved]
 * \param [IN] datarate     Sets the Datarate
 *                          FSK : 600..300000 bits/s
 *                          LoRa: [6: 64, 7: 128, 8: 256, 9: 512,
 *                                10: 1024, 11: 2048, 12: 4096  chips]
 * \param [IN] coderate     Sets the coding rate (LoRa only)
 *                          FSK : N/A ( set to 0 )
 *                          LoRa: [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
 * \param [IN] bandwidthAfc Sets the AFC Bandwidth (FSK only)
 *                          FSK : >= 2600 and <= 250000 Hz
 *                          LoRa: N/A ( set to 0 )
 * \param [IN] preambleLen  Sets the Preamble length
 *                          FSK : Number of bytes
 *                          LoRa: Length in symbols (the hardware adds 4 more symbols)
 * \param [IN] symbTimeout  Sets the RxSingle timeout value
 *                          FSK : timeout in number of bytes
 *                          LoRa: timeout in symbols
 * \param [IN] fixLen       Fixed length packets [0: variable, 1: fixed]
 * \param [IN] payloadLen   Sets payload length when fixed length is used
 * \param [IN] crcOn        Enables/Disables the CRC [0: OFF, 1: ON]
 * \param [IN] FreqHopOn    Enables disables the intra-packet frequency hopping
 *                          FSK : N/A ( set to 0 )
 *                          LoRa: [0: OFF, 1: ON]
 * \param [IN] HopPeriod    Number of symbols between each hop
 *                          FSK : N/A ( set to 0 )
 *                          LoRa: Number of symbols
 * \param [IN] iqInverted   Inverts IQ signals (LoRa only)
 *                          FSK : N/A ( set to 0 )
 *                          LoRa: [0: not inverted, 1: inverted]
 * \param [IN] rxContinuous Sets the reception in continuous mode
 *                          [false: single mode, true: continuous mode]
 */
typedef struct
{
  uint32_t modem;         
  uint32_t bandwidth;              
  uint32_t datarate;               
  uint8_t coderate;  
  uint32_t bandwidthAfc;    
  uint16_t preambleLen;        
  bool fixLen;            
  uint8_t payloadLen;  
  bool crcOn;             
  bool FreqHopOn;           
  uint8_t HopPeriod;
  bool iqInverted;        

  /*additional rx parameters*/
  bool rxContinuous;
  uint32_t symbTimeout;           

  /*additionaltx parameters*/
  int8_t power;
  uint32_t fdev;
  uint32_t txTimeout;
  uint32_t frequency;

  /*Unused variables*/
  uint32_t lna;                /* 0:off 1:On */ //Unused variables only FSK
  uint32_t paBoost;            /* 0:off 1:On */ //Unused variables
  uint32_t lowDrOpt;           //RadioSetRxConfig Will be automatically configured according to SF
  uint32_t BTproduct;          //Unused variables
  
  /* hopping test */
  uint32_t freq_start;
  uint32_t freq_stop;
  uint32_t hp_step;
  uint32_t nb_tx;
  
}testParameter_t;


typedef struct
{
  uint32_t frequency;
  uint32_t txpower;
  uint32_t txTimeout;
}testCwParameter_t;


int32_t service_lora_trssi(int16_t *rssiVal);
int32_t service_lora_ttone(void);

void service_lora_toff(void);
int32_t service_lora_trssi(int16_t *rssiVal);

int32_t service_lora_trx(int32_t nb_packet);
int32_t service_lora_ttx(int32_t nb_packet);

int32_t service_lora_set_tconf(testParameter_t *Param);
int32_t service_lora_get_tconf(testParameter_t *Param);
int32_t service_lora_tth(const testParameter_t *param);

int32_t service_lora_get_cw(testCwParameter_t *param);
int32_t service_lora_set_cw(testCwParameter_t *param);

#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif // __SERVICE_LORA_TEST_H__

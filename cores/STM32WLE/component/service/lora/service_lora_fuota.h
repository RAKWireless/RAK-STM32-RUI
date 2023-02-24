/**
 * @file        service_lora_fuota.h
 * @brief       Provide LoRa service layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.5
 */

#ifndef __SERVICE_LORA_FUOTA_H__
#define __SERVICE_LORA_FUOTA_H__
 
#ifdef SUPPORT_FUOTA


#ifdef __cplusplus
extern "C"
{
#endif


#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"
#include "LoRaMac.h"
#include "LoRaMacTypes.h"
#include "LmHandlerTypes.h"
#include "FragDecoder.h"
#include "service_nvm.h"
#include "service_lora.h"
#include "Region.h"
#include "LmhPackage.h"
#include "service_lora_fuota.h"
#include "LmhpClockSync.h"
#include "LmhpRemoteMcastSetup.h"
#include "LmhpFragmentation.h"

#define UNFRAGMENTED_DATA_SIZE                     ( FRAG_MAX_NB * FRAG_MAX_SIZE )
extern volatile uint8_t IsTxFramePending;
extern volatile bool IsMcSessionStarted ;
extern LmhpFragmentationParams_t LmhpFragmentationParams ;
/*
 * Un-fragmented data storage. Only if datafile fragments are
 * collected in RAM
 */
static uint8_t UnfragmentedData[UNFRAGMENTED_DATA_SIZE];


void UplinkProcess( void ); 
void OnSysTimeUpdate(void);
void OnFragProgress(uint16_t fragCounter, uint16_t fragNb, uint8_t fragSize, uint16_t fragNbLost);
void OnFragDone(int32_t status, uint8_t *file, uint32_t size);
void LoraStartTx(void);

#ifdef __cplusplus
}
#endif


#endif // __SERVICE_LORA_H__
#endif // FUOTA
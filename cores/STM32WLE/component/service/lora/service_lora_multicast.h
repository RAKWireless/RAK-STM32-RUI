/*
 * @Author: Daniel
 * @Date: 2021-06-09 11:05:36
 * @LastEditTime: 2021-06-22 10:53:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \rui-v3-all\component\service\lora\service_lora_multicast.h
 */
#ifndef __SERVICE_LORA_MULTICAST_H__
#define __SERVICE_LORA_MULTICAST_H__

#ifndef NO_LORA_SUPPORT

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"
#include "LoRaMacTypes.h"
#include "LoRaMac.h"


typedef struct McSession_s
{
    uint8_t Devclass;
    uint32_t Address;
    uint8_t McAppSKey[16];
    uint8_t McNwkSKey[16];
    uint32_t Frequency;
    int8_t Datarate;
    uint16_t Periodicity;
    int8_t GroupID;
    uint8_t entry;
}McSession_t;



int32_t service_lora_addmulc(McSession_t McSession);
int32_t service_lora_rmvmulc(uint32_t devaddr);
int32_t service_lora_lstmulc(McSession_t *iterator);
void MulticastMcpsIndication( McpsIndication_t *mcpsIndication );
int32_t service_lora_setup_multicast(void);
int32_t service_lora_clear_multicast(void);

#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif // __SERVICE_LORA_MULTICAST_H__

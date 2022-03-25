/*
 * @Author: Daniel
 * @Date: 2021-06-09 10:54:47
 * @LastEditTime: 2021-06-24 00:19:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \rui-v3-all\component\service\lora\service_lora_multicast.c
 */

#include "service_lora_multicast.h"
#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "LoRaMac.h"
#include "Region.h"
#include "radio.h"
#include "delay.h"
#include "timer.h"
#include "string.h"
#include "udrv_serial.h"
#include "service_lora_test.h"

#define LORAMAC_MAX_MC_CTX 4

McSession_t McSession_group[LORAMAC_MAX_MC_CTX];


int32_t service_lora_addmulc(McSession_t McSession)
{

    LoRaMacStatus_t lorastatus;
    uint8_t i, j;
    McChannelParams_t channel;
    uint8_t status = 0x00;

    for (i = 0; i < 4; i++)
    {
        if (McSession.Address == McSession_group[i].Address)
            return -UDRV_WRONG_ARG;
    }

    for (i = 0; i < 4; i++)
    {
        if (McSession_group[i].Address == 0)
        {


            McSession.GroupID = i;

            channel.IsRemotelySetup = false;
            channel.Class = McSession.Devclass;
            channel.IsEnabled = true;
            channel.GroupID = McSession.GroupID ;
            channel.Address = McSession.Address;
            channel.McKeys.Session.McAppSKey = McSession.McAppSKey;
            channel.McKeys.Session.McNwkSKey = McSession.McNwkSKey;
            channel.FCountMin = 0;
            channel.FCountMax = 0xFFFF;

            if (McSession.Devclass == 2)    //classC multicast group
            {
                //channel.RxParams.ClassC.Frequency
                if(McSession.Frequency!=0)
                {
                    channel.RxParams.ClassC.Frequency = McSession.Frequency;
                    channel.RxParams.ClassC.Datarate = McSession.Datarate;
                }
                else
                {
                    SERVICE_LORA_BAND band = service_lora_get_band();
                    switch (band)
                    {
                        case SERVICE_LORA_AS923:
                        channel.RxParams.ClassC.Frequency = 923200000;
                        channel.RxParams.ClassC.Datarate = 2;
                        break;
                        case SERVICE_LORA_AU915:
                        channel.RxParams.ClassC.Frequency = 923300000;
                        channel.RxParams.ClassC.Datarate = 8;
                        break;
                        case SERVICE_LORA_CN470 :
                        channel.RxParams.ClassC.Frequency = 505300000;
                        channel.RxParams.ClassC.Datarate = 0;
                        break;
                        case SERVICE_LORA_CN779 :
                        channel.RxParams.ClassC.Frequency = 786000000;
                        channel.RxParams.ClassC.Datarate = 0;
                        break;
                        case SERVICE_LORA_EU433  :
                        channel.RxParams.ClassC.Frequency = 434665000;
                        channel.RxParams.ClassC.Datarate = 0;
                        break;
                        case SERVICE_LORA_EU868  :
                        channel.RxParams.ClassC.Frequency = 869525000;
                        channel.RxParams.ClassC.Datarate = 0;
                        break;
                        case SERVICE_LORA_KR920   :
                        channel.RxParams.ClassC.Frequency = 921900000;
                        channel.RxParams.ClassC.Datarate =  0;
                        break;
                        case SERVICE_LORA_IN865  :
                        channel.RxParams.ClassC.Frequency = 866550000;
                        channel.RxParams.ClassC.Datarate =  2;
                        break;
                        case SERVICE_LORA_US915  :
                        channel.RxParams.ClassC.Frequency = 923300000;
                        channel.RxParams.ClassC.Datarate =8;
                        break;
                        case SERVICE_LORA_RU864 :
                        channel.RxParams.ClassC.Frequency = 869100000;
                        channel.RxParams.ClassC.Datarate = 0;
                        break;
                        default:
                        return UDRV_INTERNAL_ERR;
                    }
                    McSession.Frequency = channel.RxParams.ClassC.Frequency;
                    McSession.Datarate = channel.RxParams.ClassC.Datarate;
                }
            }
            else   //classB multicast group
            {
                if(McSession.Frequency!=0)
                {
                    channel.RxParams.ClassB.Frequency = McSession.Frequency;
                    channel.RxParams.ClassB.Datarate = McSession.Datarate;
                    channel.RxParams.ClassB.Periodicity = McSession.Periodicity;
                }
                else
                {
                    /* Increase channel default value */
                    SERVICE_LORA_BAND band = service_lora_get_band();
                    switch (band)
                    {
                        case SERVICE_LORA_AS923:          //RP002-1.0.3  P68
                        channel.RxParams.ClassB.Frequency = 923400000;
                        channel.RxParams.ClassB.Datarate = 3;
                        break;
                        case SERVICE_LORA_AU915:          //RP002-1.0.3  P52
                        channel.RxParams.ClassB.Frequency = 923300000;
                        channel.RxParams.ClassB.Datarate = 8;
                        break;
                        case SERVICE_LORA_CN470 :         //RP002-1.0.3  P60
                        channel.RxParams.ClassB.Frequency = 494900000;
                        channel.RxParams.ClassB.Datarate = 2;
                        break;
                        case SERVICE_LORA_CN779 :         //RP002-1.0.3  P41
                        channel.RxParams.ClassB.Frequency = 785000000;
                        channel.RxParams.ClassB.Datarate = 3;
                        break;
                        case SERVICE_LORA_EU433  :        //RP002-1.0.3  P45
                        channel.RxParams.ClassB.Frequency = 434665000;
                        channel.RxParams.ClassB.Datarate = 3;
                        break;
                        case SERVICE_LORA_EU868  :        //RP002-1.0.3  P29
                        channel.RxParams.ClassB.Frequency = 869525000;
                        channel.RxParams.ClassB.Datarate = 3;
                        break;
                        case SERVICE_LORA_KR920   :       //RP002-1.0.3  P74
                        channel.RxParams.ClassB.Frequency = 923100000;
                        channel.RxParams.ClassB.Datarate =  3;
                        break;
                        case SERVICE_LORA_IN865  :        //RP002-1.0.3  P79
                        channel.RxParams.ClassB.Frequency = 866550000;
                        channel.RxParams.ClassB.Datarate =  4;
                        break;
                        case SERVICE_LORA_US915  :        //RP002-1.0.3  P35
                        channel.RxParams.ClassB.Frequency = 923300000;
                        channel.RxParams.ClassB.Datarate =8;
                        break;
                        case SERVICE_LORA_RU864 :         //RP002-1.0.3  P84
                        channel.RxParams.ClassB.Frequency = 86890000;
                        channel.RxParams.ClassB.Datarate = 3;
                        break;
                        default:
                        return UDRV_INTERNAL_ERR;
                    }

                    McSession.Frequency = channel.RxParams.ClassB.Frequency;
                    McSession.Datarate = channel.RxParams.ClassB.Datarate;
                    channel.RxParams.ClassB.Periodicity = McSession.Periodicity;
                }

            }
            if (LoRaMacMcChannelSetup(&channel) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }


            if (LoRaMacMcChannelSetupRxParams(channel.GroupID, &channel.RxParams, &status) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            if((status & 0xFC) != 0x00)
            {
                return -UDRV_WRONG_ARG;
            }

            memcpy(&McSession_group[i], &McSession, sizeof(McSession_t));   
            if(service_nvm_set_multicast_to_nvm(McSession_group)!=UDRV_RETURN_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }


            break;
        }
    }
     if (i == 4)
    {
        memset(&McSession_group[i], 0, sizeof(McSession_t));
        return -UDRV_INTERNAL_ERR;
    }

    return UDRV_RETURN_OK;
}

int32_t service_lora_rmvmulc(uint32_t devaddr)
{
    uint8_t i;
    for(i=0;i<4;i++)
    {
        if((McSession_group[i].Address) == devaddr)
        {
            if(LoRaMacMcChannelDelete((AddressIdentifier_t)(McSession_group[i].GroupID)) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            memset(&McSession_group[i], 0, sizeof(McSession_t));
            if(service_nvm_set_multicast_to_nvm(McSession_group)!=UDRV_RETURN_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            break;
        }
    }
    if(i==4)
    {
        return -UDRV_INTERNAL_ERR;
    }
    return UDRV_RETURN_OK;
}

int32_t service_lora_lstmulc(McSession_t *iterator)
{
    for (int i = 1 ; i <= LORAMAC_MAX_MC_CTX ; i++)
    {
        McSession_group[i].entry = i;
    }

    for (int i = 0 ; i < LORAMAC_MAX_MC_CTX ; i++)     
    {
        if (!memcmp(iterator, &McSession_group[i], sizeof(McSession_t)))   
        {
            if (i == (LORAMAC_MAX_MC_CTX-1)) 
            {//This is the last call
                return UDRV_RETURN_OK;
            } 
            else 
            {
                memcpy(iterator, &McSession_group[i+1], sizeof(McSession_t));  
                LORA_TEST_DEBUG("i=%d",i);
                return -UDRV_CONTINUE;
            }
        }
        else //
        {
            LORA_TEST_DEBUG("i=%d",i);
            
        }
    }
    //This is the first call
    memcpy(iterator, &McSession_group[0], sizeof(McSession_t));
    return -UDRV_CONTINUE;
}

void MulticastMcpsIndication(McpsIndication_t *mcpsIndication)
{
    udrv_serial_log_printf("MULTICAST\r\n");
}


int32_t service_lora_setup_multicast(void)
{
    uint8_t i;
    McSession_t * pMcSession;
    McSession_t McSession_group_temp[LORAMAC_MAX_MC_CTX];
    pMcSession = service_nvm_get_multicast_from_nvm();
    memcpy(McSession_group_temp,pMcSession,4*sizeof(McSession_t));

    for (i = 0 ; i < LORAMAC_MAX_MC_CTX ; i++)
    {
        if(McSession_group_temp[i].Address == 0)
        continue;
        if(service_lora_addmulc(McSession_group_temp[i])!=UDRV_RETURN_OK)
        {  
            return -UDRV_INTERNAL_ERR;       
        }
    }
    return UDRV_RETURN_OK;
}


int32_t service_lora_clear_multicast(void)
{
    uint8_t i;

    for(i=0;i<4;i++)
    {
        if(McSession_group[i].Address != 0)
        {
            if(service_lora_rmvmulc(McSession_group[i].Address)!=UDRV_RETURN_OK)
            {  
                return -UDRV_INTERNAL_ERR;       
            }
        }
    }
    return UDRV_RETURN_OK;
}

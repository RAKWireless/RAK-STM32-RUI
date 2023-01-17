#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_system.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "service_lora.h"
#include "service_lora_arssi.h"
#include "LoRaMac.h"
#include "Region.h"
#include "systime.h"
#include "utilities.h"

static uint8_t last_tx_channel;
static int8_t arssi[96] = {0};
static chan_rssi service_lora_chan_arssi = {.chan = UINT32_MAX};

void service_lora_arssi_tx_callback(uint8_t channel)
{
    last_tx_channel = channel;
}

void service_lora_arssi_rx_callback(int8_t rssi)
{
    arssi[last_tx_channel] = rssi;
}

static void service_lora_arssi_iterator_init(chan_rssi *iterator)
{
    iterator->chan = UINT32_MAX;
    return;
}

int32_t service_lora_get_arssi(chan_rssi *iterator)
{
    LoRaMacStatus_t Status;
    MibRequestConfirm_t mibReq;
    uint16_t channel_mask[REGION_NVM_CHANNELS_MASK_SIZE] = {0},i,j;
    mibReq.Type = MIB_CHANNELS_MASK;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    for(i = 0 ; i < REGION_NVM_CHANNELS_MASK_SIZE ; i++)
    {
        for(j = 0 ; j < 16 ; j++)
        {
            if (service_lora_chan_arssi.chan == (i*16+j) && service_lora_chan_arssi.rssi == arssi[i*16+j]) {
                if (j == (16-1)) {
                    if (i == (REGION_NVM_CHANNELS_MASK_SIZE-1)) {//This is the last call
                        service_lora_arssi_iterator_init(&service_lora_chan_arssi);
                        return UDRV_RETURN_OK;
                    } else {
                        service_lora_chan_arssi.chan = (i+1)*16 + 0;
                        service_lora_chan_arssi.mask = mibReq.Param.ChannelsMask[i+1]&(1<<0);
                        service_lora_chan_arssi.rssi = arssi[(i+1)*16 + 0];
                        goto get_arssi_out;
                    }
                } else {
                    service_lora_chan_arssi.chan = i*16 + (j+1);
                    service_lora_chan_arssi.mask = mibReq.Param.ChannelsMask[i]&(1<<(j+1));
                    service_lora_chan_arssi.rssi = arssi[i*16 + (j+1)];
                    goto get_arssi_out;
                }
            }
        }
    }

    //This is the first call
    service_lora_chan_arssi.chan = 0;
    service_lora_chan_arssi.mask = mibReq.Param.ChannelsMask[0]&(1<<0);
    service_lora_chan_arssi.rssi = arssi[0];
get_arssi_out:
    memcpy(iterator, &service_lora_chan_arssi, sizeof(chan_rssi));
    return -UDRV_CONTINUE;
}

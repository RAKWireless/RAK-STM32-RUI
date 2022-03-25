#ifndef __SERVICE_LORA_ARSSI_H__
#define __SERVICE_LORA_ARSSI_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>

typedef struct chan_rssi_t
{
    uint32_t chan;
    uint16_t mask;
    int8_t rssi;
} chan_rssi;

void service_lora_arssi_tx_callback(uint8_t channel);
void service_lora_arssi_rx_callback(int8_t rssi);
int32_t service_lora_get_arssi(chan_rssi *iterator);

#ifdef __cplusplus
}
#endif


#endif

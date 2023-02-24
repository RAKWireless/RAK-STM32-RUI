/**
 * @file        service_battery.h
 * @brief       Provide battery service layer.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.6
 */

#ifndef __SERVICE_BATTERY_H__
#define __SERVICE_BATTERY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define SERVICE_BATT_MIN	(2.0f)
#define SERVICE_BATT_2V0	(2.0f)
#define SERVICE_BATT_2V1	(2.1f)
#define SERVICE_BATT_2V2	(2.2f)
#define SERVICE_BATT_2V3	(2.3f)
#define SERVICE_BATT_2V4	(2.4f)
#define SERVICE_BATT_2V5	(2.5f)
#define SERVICE_BATT_2V6	(2.6f)
#define SERVICE_BATT_2V7	(2.7f)
#define SERVICE_BATT_2V8	(2.8f)
#define SERVICE_BATT_2V9	(2.9f)
#define SERVICE_BATT_3V0	(3.0f)
#define SERVICE_BATT_3V1	(3.1f)
#define SERVICE_BATT_3V2	(3.2f)
#define SERVICE_BATT_3V3	(3.3f)
#define SERVICE_BATT_3V4	(3.4f)
#define SERVICE_BATT_3V5	(3.5f)
#define SERVICE_BATT_3V6	(3.6f)
#define SERVICE_BATT_3V7	(3.7f)
#define SERVICE_BATT_3V8	(3.8f)
#define SERVICE_BATT_3V9	(3.9f)
#define SERVICE_BATT_4V0	(4.0f)
#define SERVICE_BATT_4V1	(4.1f)
#define SERVICE_BATT_4V2	(4.2f)
#define SERVICE_BATT_4V3	(4.3f)
#define SERVICE_BATT_4V4	(4.4f)
#define SERVICE_BATT_4V5	(4.5f)
#define SERVICE_BATT_4V6	(4.6f)
#define SERVICE_BATT_4V7	(4.7f)
#define SERVICE_BATT_4V8	(4.8f)
#define SERVICE_BATT_4V9	(4.9f)
#define SERVICE_BATT_5V0	(5.0f)
#define SERVICE_BATT_5V1	(5.1f)
#define SERVICE_BATT_5V2	(5.2f)
#define SERVICE_BATT_5V3	(5.3f)
#define SERVICE_BATT_5V4	(5.4f)
#define SERVICE_BATT_5V5	(5.5f)
#define SERVICE_BATT_5V6	(5.6f)
#define SERVICE_BATT_5V7	(5.7f)
#define SERVICE_BATT_5V8	(5.8f)
#define SERVICE_BATT_5V9	(5.9f)
#define SERVICE_BATT_6V0	(6.0f)
#define SERVICE_BATT_MAX	(6.0f)

typedef struct _batt_level {
    float batt_vol;
    uint32_t adc_val;
} batt_level;

void service_battery_get_batt_level(float *bat_lvl);

#ifdef __cplusplus
}
#endif

#endif  // __SERVICE_BATTERY_H__


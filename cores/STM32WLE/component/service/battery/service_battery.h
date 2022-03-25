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

#define SERVICE_BATT_MIN	((float)2.0)
#define SERVICE_BATT_2V0	((float)2.0)
#define SERVICE_BATT_2V1	((float)2.1)
#define SERVICE_BATT_2V2	((float)2.2)
#define SERVICE_BATT_2V3	((float)2.3)
#define SERVICE_BATT_2V4	((float)2.4)
#define SERVICE_BATT_2V5	((float)2.5)
#define SERVICE_BATT_2V6	((float)2.6)
#define SERVICE_BATT_2V7	((float)2.7)
#define SERVICE_BATT_2V8	((float)2.8)
#define SERVICE_BATT_2V9	((float)2.9)
#define SERVICE_BATT_3V0	((float)3.0)
#define SERVICE_BATT_3V1	((float)3.1)
#define SERVICE_BATT_3V2	((float)3.2)
#define SERVICE_BATT_3V3	((float)3.3)
#define SERVICE_BATT_3V4	((float)3.4)
#define SERVICE_BATT_3V5	((float)3.5)
#define SERVICE_BATT_3V6	((float)3.6)
#define SERVICE_BATT_3V7	((float)3.7)
#define SERVICE_BATT_3V8	((float)3.8)
#define SERVICE_BATT_3V9	((float)3.9)
#define SERVICE_BATT_4V0	((float)4.0)
#define SERVICE_BATT_4V1	((float)4.1)
#define SERVICE_BATT_4V2	((float)4.2)
#define SERVICE_BATT_4V3	((float)4.3)
#define SERVICE_BATT_4V4	((float)4.4)
#define SERVICE_BATT_4V5	((float)4.5)
#define SERVICE_BATT_4V6	((float)4.6)
#define SERVICE_BATT_4V7	((float)4.7)
#define SERVICE_BATT_4V8	((float)4.8)
#define SERVICE_BATT_4V9	((float)4.9)
#define SERVICE_BATT_5V0	((float)5.0)
#define SERVICE_BATT_5V1	((float)5.1)
#define SERVICE_BATT_5V2	((float)5.2)
#define SERVICE_BATT_5V3	((float)5.3)
#define SERVICE_BATT_5V4	((float)5.4)
#define SERVICE_BATT_5V5	((float)5.5)
#define SERVICE_BATT_5V6	((float)5.6)
#define SERVICE_BATT_5V7	((float)5.7)
#define SERVICE_BATT_5V8	((float)5.8)
#define SERVICE_BATT_5V9	((float)5.9)
#define SERVICE_BATT_6V0	((float)6.0)
#define SERVICE_BATT_MAX	((float)6.0)

typedef struct _batt_level {
    float batt_vol;
    uint32_t adc_val;
} batt_level;

void service_battery_get_batt_level(float *bat_lvl);

#ifdef __cplusplus
}
#endif

#endif  // __SERVICE_BATTERY_H__


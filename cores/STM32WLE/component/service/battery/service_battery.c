#include <stdint.h>
#include "board_basic.h"
#include "udrv_errno.h"
#include "service_battery.h"
#include "udrv_adc.h"
#include "variant.h"
#include "udrv_serial.h"

extern batt_level batt_table[];

void service_battery_get_batt_level(float *bat_lvl) {
    uint16_t adc_value;
    float max, ref_over_gain;

#if defined(rak3172_sip)
    UDRV_ADC_RESOLUTION resolution = udrv_adc_get_resolution();
    udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_12BIT);
    udrv_adc_read(UDRV_ADC_CHANNEL_VREFINT, &adc_value);
    *bat_lvl = (float)adc_value;
	*bat_lvl = *bat_lvl / 4095;
	*bat_lvl = 1.27 / *bat_lvl;
    *bat_lvl = *bat_lvl * 0.974 - 0.065;  //calibrate
    udrv_adc_set_resolution(resolution);
    return ;
#endif

    switch (udrv_adc_get_resolution()) {
        case UDRV_ADC_RESOLUTION_6BIT:
        {
            max = 64.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            max = 256.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        default:
        {
            max = 1024.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        {
            max = 4096.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            max = 16384.0;
            break;
        }
    }

    switch (udrv_adc_get_mode()) {
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            #ifndef rak11720
            ref_over_gain = 3.6;
            #else
            ref_over_gain = 2.0;
            #endif
            break;
        }
        #ifndef rak11720
        case UDRV_ADC_MODE_3_3:
        {
            ref_over_gain = 3.3;
            break;
        }
        case UDRV_ADC_MODE_3_0:
        {
            ref_over_gain = 3.0;
            break;
        }
        case UDRV_ADC_MODE_2_4:
        {
            ref_over_gain = 2.4;
            break;
        }
        case UDRV_ADC_MODE_1_8:
        {
            ref_over_gain = 1.8;
            break;
        }
        case UDRV_ADC_MODE_1_2:
        {
            ref_over_gain = 1.2;
            break;
        }
        #else
        case UDRV_ADC_MODE_1_5:
        {
            ref_over_gain = 1.5;
            break;
        }
        #endif
    }

#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
    udrv_adc_read(WB_A0, &adc_value);
#endif

#ifdef RAK5010_EVB
    udrv_adc_read(BAT_PIN, &adc_value);
#endif

    for (int i = 0 ; i < get_batt_table_size() ; i++) {
        *bat_lvl = batt_table[i].batt_vol;
        if (adc_value < batt_table[i].adc_val) {
            break;
        }
    }

    /*******************************************/
    /*
     * voltage divider = 0.6
     *
     * Vin = ((ref)/(gain))*((adc value)/(max))/(divider)
     *
     *******************************************/
#ifndef RAK3372+RAK5005-O_V1.0
    *bat_lvl = ref_over_gain*(((float)adc_value)/max)*(5.0f)/(3.0f);
#endif

#ifdef RAK11720+RAK5005-O_V1.0
    *bat_lvl = ((ref_over_gain*(((float)adc_value)/max)*(5.0f))/(3.0f))*(1.3f);
#endif

#ifdef RAK5010_EVB
    *bat_lvl = (ref_over_gain*(((float)adc_value)/max)*(5.0f)/(2.0f)) + 0.3f;
#endif

    return;
}

void service_battery_get_SysVolt_level (float *sys_lvl) {
    uint16_t adc_value;
    float max, ref_over_gain;

    switch (udrv_adc_get_resolution()) {
        case UDRV_ADC_RESOLUTION_6BIT:
        {
            max = 64.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_8BIT:
        {
            max = 256.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_10BIT:
        default:
        {
            max = 1024.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_12BIT:
        {
            max = 4096.0;
            break;
        }
        case UDRV_ADC_RESOLUTION_14BIT:
        {
            max = 16384.0;
            break;
        }
    }

    switch (udrv_adc_get_mode()) {
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            #ifndef rak11720
            ref_over_gain = 3.6;
            #else
            ref_over_gain = 2.0;
            #endif
            break;
        }
        #ifndef rak11720
        case UDRV_ADC_MODE_3_3:
        {
            ref_over_gain = 3.3;
            break;
        }
        case UDRV_ADC_MODE_3_0:
        {
            ref_over_gain = 3.0;
            break;
        }
        case UDRV_ADC_MODE_2_4:
        {
            ref_over_gain = 2.4;
            break;
        }
        case UDRV_ADC_MODE_1_8:
        {
            ref_over_gain = 1.8;
            break;
        }
        case UDRV_ADC_MODE_1_2:
        {
            ref_over_gain = 1.2;
            break;
        }
        #else
        case UDRV_ADC_MODE_1_5:
        {
            ref_over_gain = 1.2;
            break;
        }
        #endif
    }

    udrv_adc_read(255, &adc_value);
    *sys_lvl = ((float)adc_value)*ref_over_gain/max;

    return;
}


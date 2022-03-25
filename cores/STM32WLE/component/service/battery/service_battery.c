#include <stdint.h>
#include "board_basic.h"
#include "udrv_errno.h"
#include "service_battery.h"
#include "udrv_adc.h"
#include "variant.h"

extern batt_level batt_table[];

void service_battery_get_batt_level(float *bat_lvl) {
#if defined(WISBLOCK_BASE_5005) || defined(WISBLOCK_BASE_5005_O)
    uint16_t adc_value;
    float max, ref_over_gain;

    switch (udrv_adc_get_resolution()) {
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
            ref_over_gain = 3.6;
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
    }

    udrv_adc_read(WB_A0, &adc_value);

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
    *bat_lvl = ref_over_gain*(((float)adc_value)/max)*((float)5.0)/((float)3.0);

#endif
    return;
}

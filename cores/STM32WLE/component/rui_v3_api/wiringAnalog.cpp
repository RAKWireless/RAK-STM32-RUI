#include "ruiTop.h"
#include "udrv_adc.h"
#include "variant.h"

uint8_t referenceMode = UDRV_ADC_MODE_DEFAULT;

void analogReference(uint8_t mode)
{
    switch ((UDRV_ADC_MODE)mode) {
        case UDRV_ADC_MODE_3_0:
        {
            udrv_adc_set_mode(UDRV_ADC_MODE_3_0);
            break;
        }
        case UDRV_ADC_MODE_2_4:
        {
            udrv_adc_set_mode(UDRV_ADC_MODE_2_4);
            break;
        }
        case UDRV_ADC_MODE_1_8:
        {
            udrv_adc_set_mode(UDRV_ADC_MODE_1_8);
            break;
        }
        case UDRV_ADC_MODE_1_2:
        {
            udrv_adc_set_mode(UDRV_ADC_MODE_1_2);
            break;
        }
        case UDRV_ADC_MODE_DEFAULT:
        default:
        {
            udrv_adc_set_mode(UDRV_ADC_MODE_DEFAULT);
            break;
        }
    }
}

int analogRead(uint8_t pin)
{ 
    int16_t value;

    udrv_adc_read(pin, &value);
    return (int)value;
}

void analogReadResolution(uint8_t bits)
{
    if (!bits || bits > 32) {
        return;
    }

    if (bits <= 8) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_8BIT);
    } else if (bits <= 10) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_10BIT);
    } else if (bits <= 12) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_12BIT);
    } else {//bits <= 14
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_14BIT);
    }
}

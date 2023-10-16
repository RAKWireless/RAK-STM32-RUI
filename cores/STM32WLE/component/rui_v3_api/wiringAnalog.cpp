#include "ruiTop.h"
#include "udrv_adc.h"
#include "variant.h"

void analogReference(eAnalogReference mode)
{
    
    udrv_adc_set_mode((UDRV_ADC_MODE)mode);
}


void analogOversampling(uint32_t ulOversampling )
{
     udrv_adc_oversampling(ulOversampling);
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

    if (bits <= 6) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_6BIT);
    } else if (bits <= 8) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_8BIT);
    } else if (bits <= 10) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_10BIT);
    } else if (bits <= 12) {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_12BIT);
    } else {
        udrv_adc_set_resolution(UDRV_ADC_RESOLUTION_14BIT);
    }
}

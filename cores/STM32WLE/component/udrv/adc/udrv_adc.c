#include "udrv_adc.h"
#include "udrv_errno.h"
#include "uhal_adc.h"

void udrv_adc_set_resolution (UDRV_ADC_RESOLUTION resolution)
{
    uhal_adc_set_resolution(resolution);
}

UDRV_ADC_RESOLUTION udrv_adc_get_resolution (void)
{
    return uhal_adc_get_resolution();
}

void udrv_adc_set_mode (UDRV_ADC_MODE mode)
{
    uhal_adc_set_mode(mode);
}

UDRV_ADC_MODE udrv_adc_get_mode (void) {
    return uhal_adc_get_mode();
}

void udrv_adc_oversampling (uint32_t uloversampling)
{
    uhal_adc_oversampling(uloversampling);
}


int32_t udrv_adc_read (uint32_t pin, int16_t *value)
{
    return uhal_adc_read(pin, value);
}

void udrv_adc_suspend(void) {
    uhal_adc_suspend();
}

void udrv_adc_resume(void) {
    uhal_adc_resume();
}

#ifndef _UHAL_ADC_H_
#define _UHAL_ADC_H_

#include <stdint.h>
#include <stddef.h>
#include "udrv_adc.h"
#include "udrv_errno.h"
#include "stm32wlxx_hal.h"

#define VDDA_APPLI                       ((uint16_t)1024)

#define DIGITAL_SCALE_6BITS              ((uint16_t) 0x003F)
#define DIGITAL_SCALE_8BITS              ((uint16_t) 0x00FF)
#define DIGITAL_SCALE_10BITS             ((uint16_t) 0x03FF)
#define DIGITAL_SCALE_12BITS             ((uint16_t) 0x0FFF)

#define VAR_CONVERTED_DATA_INIT_VALUE    (DIGITAL_SCALE_12BITS + 1)

int32_t uhal_adc_read (uint32_t pin, uint16_t *value);
void uhal_adc_suspend (void);
void uhal_adc_resume (void);
void uhal_adc_set_resolution (UDRV_ADC_RESOLUTION resolution);
UDRV_ADC_RESOLUTION uhal_adc_get_resolution (void);
void uhal_adc_set_mode (UDRV_ADC_MODE mode);
UDRV_ADC_MODE uhal_adc_get_mode (void);
void uhal_adc_oversampling(uint32_t oversampling);
#endif  // #ifndef _UHAL_ADC_H_

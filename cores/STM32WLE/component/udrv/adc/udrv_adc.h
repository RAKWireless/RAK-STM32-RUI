/**
 * @file        udrv_adc.h
 * @brief       Provide a hardware independent ADC driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.3
 */

#ifndef _UDRV_ADC_H_
#define _UDRV_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>

#define UDRV_ADC_SAMPLE_CNT 16

typedef enum{
    UDRV_ADC_RESOLUTION_6BIT  = (0UL),  //< 6 bit resolution.
    UDRV_ADC_RESOLUTION_8BIT  = (1UL),  //< 8 bit resolution.
    UDRV_ADC_RESOLUTION_10BIT = (2UL),  //< 10 bit resolution.
    UDRV_ADC_RESOLUTION_12BIT = (3UL),  //< 12 bit resolution.
    UDRV_ADC_RESOLUTION_14BIT = (4UL)   //< 14 bit resolution.
}UDRV_ADC_RESOLUTION ;

typedef enum{
    UDRV_ADC_MODE_DEFAULT = (0UL),  //default range
    UDRV_ADC_MODE_3_3     = (1UL),  // 0 - 3.3 V
    UDRV_ADC_MODE_3_0     = (2UL),  // 0 - 3 V
    UDRV_ADC_MODE_2_4     = (3UL),  // 0 - 2.4 V
    UDRV_ADC_MODE_1_8     = (4UL),  // 0 - 1.8 V
    UDRV_ADC_MODE_1_2     = (5UL),  // 0 - 1.2 V
} UDRV_ADC_MODE;

/**
 *  Set ADC resolutions.
 * @param  resolution              The resolution to be set
 * UDRV_ADC_RESOLUTION_8BIT - 8 bit resolution.
 * UDRV_ADC_RESOLUTION_10BIT - 10 bit resolution.
 * UDRV_ADC_RESOLUTION_12BIT - 12 bit resolution.
 * UDRV_ADC_RESOLUTION_14BIT - 14 bit resolution.
 *
 */

void udrv_adc_set_resolution (UDRV_ADC_RESOLUTION resolution);

/**
 *  Get ADC resolutions.
 *
 */

UDRV_ADC_RESOLUTION udrv_adc_get_resolution (void);

/**
 *  Set ADC mode.
 * @param  mode               The ADC mode to be set
 * UDRV_ADC_MODE_DEFAULT : default range
 * UDRV_ADC_MODE_3_0 : 0 - 3.0 V
 * UDRV_ADC_MODE_2_4 : 0 - 2.4 V
 * UDRV_ADC_MODE_1_8 : 0 - 1.8 V
 * UDRV_ADC_MODE_1_2 : 0 - 1.2 V
 *
 */

void udrv_adc_set_mode (UDRV_ADC_MODE mode);

/**
 *  Get ADC mode.
 *
 */

UDRV_ADC_MODE udrv_adc_get_mode (void);

/**
 * Read out the ADC value.
 * @param  pin                      The analog input pin
 * @param  value                    The read out value
 */

int32_t udrv_adc_read (uint32_t pin, int16_t *value);

/**
 * Disable and save all the active ADC channel for power saving
 *
 */
void udrv_adc_suspend(void);

/**
 * Restore all the active ADC channel after power saving
 *
 */
void udrv_adc_resume(void);

#ifdef __cplusplus
}
#endif

#endif //_UDRV_ADC_H_

/**
 * @file        udrv_trng.h
 * @brief       Provide a hardware independent true random number generator driver layer.
 * @author      Rakwireless
 * @version     1.0.0
 * @date        2023.3
 */

#ifndef _UDRV_CRYPTO_H_
#define _UDRV_CRYPTO_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Initialize the true random number generator hardware.
 * @retval void
 */
void udrv_trng_init(void);

/**
 * @brief Create random numbers from the rng hardware.
 * @retval void
 * 
 * @param  output                   where to put the random data.
 * @param  length                   how much data you want.
 */
void udrv_trng_get_values(uint8_t *output, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif //_UDRV_ADC_H_
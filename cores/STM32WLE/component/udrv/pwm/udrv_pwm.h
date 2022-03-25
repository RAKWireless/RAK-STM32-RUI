/**
 * @file        udrv_pwm.h
 * @brief       Provide a hardware independent PWM driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.3
 */

#ifndef _UDRV_PWM_H_
#define _UDRV_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>

#define PWM_NO_TIMEOUT UINT32_MAX

typedef enum{
    UDRV_PWM_RESOLUTION_8BIT  = (0UL),  //< 8 bit resolution.
    UDRV_PWM_RESOLUTION_10BIT = (1UL),  //< 10 bit resolution.
    UDRV_PWM_RESOLUTION_12BIT = (2UL),  //< 12 bit resolution.
    UDRV_PWM_RESOLUTION_14BIT = (3UL)   //< 14 bit resolution.
}UDRV_PWM_RESOLUTION ;

typedef enum {
    UDRV_PWM_0 = 0x0,   
    UDRV_PWM_1 = 0x1,
    UDRV_PWM_2 = 0x2,
    UDRV_PWM_MAX = 0x3,
} udrv_pwm_port;

/**
 * Initilize PWM to ready operations.
 * 
 * @param   port
 *
 */
void udrv_pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin);

/**
 * Deinitialize all PWM to disable operations
 * 
 */
void udrv_pwm_deinit(udrv_pwm_port port);

/**
 * Set the duty cycle for the PWM
 *
 * @param       port
 *
 */
int32_t udrv_pwm_set_duty(udrv_pwm_port port, uint32_t duty);

/**
 * Enables the PWM to start operation
 *
 * @param       port
 * @param       duration
 *
 */
int32_t udrv_pwm_enable(udrv_pwm_port port, uint32_t duration);

/**
 * Disables the PWM to stop operation
 *
 * @param   port
 *
 */
void udrv_pwm_disable(udrv_pwm_port port);

/**
 * Disable and save all the active PWM for power saving
 *
 */
void udrv_pwm_suspend(void);

/**
 * Restore all the active PWM after power saving
 *
 */
void udrv_pwm_resume(void);

/**
 * Get resolution for PWM
 *
 */
UDRV_PWM_RESOLUTION udrv_pwm_get_resolution (void);

/**
 * Set resolution for PWM
 *
 */
void udrv_pwm_set_resolution (UDRV_PWM_RESOLUTION resolution);

#ifdef __cplusplus
}
#endif

#endif //_UDRV_PWM_H_

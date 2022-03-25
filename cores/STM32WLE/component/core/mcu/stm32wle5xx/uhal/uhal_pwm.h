#ifndef _UHAL_PWM_H_
#define _UHAL_PWM_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "pin_define.h"
#include "udrv_pwm.h"
#include "udrv_timer.h"

#include "stm32wlxx_hal.h"
#include "stm32_timer.h"

#define PERIOD_8BIT  256
#define PERIOD_10BIT  1024
#define PERIOD_12BIT  4096
#define PERIOD_14BIT  16384

void uhal_pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin);
void uhal_pwm_deinit(udrv_pwm_port port);
int32_t uhal_pwm_set_duty(udrv_pwm_port port, uint32_t duty);
void uhal_pwm_enable(udrv_pwm_port port);
void uhal_pwm_disable(udrv_pwm_port port);
void uhal_pwm_suspend(void);
void uhal_pwm_resume(void);
UDRV_PWM_RESOLUTION uhal_pwm_get_resolution (void);
void uhal_pwm_set_resolution (UDRV_PWM_RESOLUTION resolution);
int32_t uhal_pwm_timer_create (timer_handler tmr_handler, TimerMode_E mode);
int32_t uhal_pwm_timer_start (uint32_t count, void *m_data);
int32_t uhal_pwm_timer_stop (void);

#endif  // #ifndef _UHAL_PWM_H_

#ifndef _UHAL_POWERSAVE_H_
#define _UHAL_POWERSAVE_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "udrv_powersave.h"
#include "udrv_timer.h"

#include "stm32wlxx_hal.h"
#include "stm32_timer.h"

void uhal_mcu_sleep (uint32_t level);
void uhal_sys_clock_init(void);
void uhal_sys_clock_on(void);
void uhal_sys_clock_off(void);
int32_t uhal_ps_timer_create (timer_handler tmr_handler, TimerMode_E mode);
int32_t uhal_ps_timer_start (uint32_t count, void *m_data);
int32_t uhal_ps_timer_stop ();

#endif  // #ifndef _UHAL_POWERSAVE_H_

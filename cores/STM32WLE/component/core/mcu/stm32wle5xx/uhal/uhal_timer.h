#ifndef _UHAL_TIMER_H_
#define _UHAL_TIMER_H_

#include <stdint.h>
#include <stddef.h>
#include "udrv_timer.h"
#include "udrv_serial.h"
#include "stm32_timer.h"

typedef struct uhal_timer_data_ {
    union {
        TimerID_E timer_id;
        SysTimerID_E sys_timer_id;
    };
    void *m_data;
    timer_handler timer_func;
} uhal_timer_data;

void uhal_timer_init (void);
int32_t uhal_timer_create (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t uhal_timer_start (TimerID_E timer_id, uint32_t count, void *m_data);
int32_t uhal_timer_stop (TimerID_E timer_id);
int32_t uhal_sys_timer_create (SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t uhal_sys_timer_start (SysTimerID_E timer_id, uint32_t count, void *m_data);
int32_t uhal_sys_timer_stop (SysTimerID_E timer_id);

uint32_t uhal_get_microsecond(void);

void uhal_timer_handler_handler(void *pdata);

#endif  // #ifndef _UHAL_TIMER_H_

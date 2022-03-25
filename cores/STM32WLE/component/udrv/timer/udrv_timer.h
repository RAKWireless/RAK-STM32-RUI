#ifndef _UDRV_TIMER_H_
#define _UDRV_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
        TIMER_0 = 0,
        TIMER_1 = 1,
        TIMER_2 = 2,
        TIMER_3 = 3,
        TIMER_4 = 4,
        TIMER_ID_MAX = 5,
} TimerID_E;

typedef enum {
        SYSTIMER_LORAWAN = 0,
        SYSTIMER_TRANSPARENT_MODE = 1,
        SYSTIMER_PROTOCOL_MODE = 2,
        SYSTIMER_LED = 3,
        SYSTIMER_LCT = 4,
        SYSTIMER_ID_MAX = 5,
} SysTimerID_E;

typedef enum hwtmr_op_mode {
    HTMR_ONESHOT = 0,
    HTMR_PERIODIC = 1,
} TimerMode_E;

typedef void (*timer_handler) (void *m_data);

//The structure of timer function 
struct udrv_timer_api {
    void (*TIMER_INIT) (void);
    int32_t (*TIMER_CREATE) (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
    int32_t (*TIMER_START) (TimerID_E timer_id, uint32_t count, void *m_data);
    int32_t (*TIMER_STOP) (TimerID_E timer_id);
};

void udrv_timer_init (void);
int32_t udrv_timer_create (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t udrv_timer_start (TimerID_E timer_id, uint32_t count, void *m_data);
int32_t udrv_timer_stop (TimerID_E timer_id);

int32_t udrv_system_timer_create (SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t udrv_system_timer_start (SysTimerID_E timer_id, uint32_t count, void *m_data);
int32_t udrv_system_timer_stop (SysTimerID_E timer_id);

void udrv_system_timer_handler_handler (void *pdata);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_TIMER_H_

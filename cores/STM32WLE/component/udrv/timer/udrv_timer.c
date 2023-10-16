#include <stddef.h>
#include "udrv_timer.h"
#include "uhal_timer.h"
#include "uhal_rtc.h"

#if 0
struct udrv_timer_api timer_driver =
{
  uhal_sys_timer_create,
  uhal_sys_timer_start,
  uhal_sys_timer_stop,
};
#else
struct udrv_timer_api timer_driver =
{
  uhal_timer_init,
  uhal_timer_create,
  uhal_timer_start,
  uhal_timer_stop,
};
#endif

void udrv_timer_init (void)
{
    timer_driver.TIMER_INIT();
}

int32_t udrv_timer_create (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode)
{
    return timer_driver.TIMER_CREATE(timer_id, tmr_handler, mode);
}

int32_t udrv_timer_start (TimerID_E timer_id, uint32_t count, void *m_data)
{
    return timer_driver.TIMER_START(timer_id, count, m_data);
}

int32_t udrv_timer_stop (TimerID_E timer_id)
{
    return timer_driver.TIMER_STOP(timer_id);
}

int32_t udrv_system_timer_create (SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode) {
    return uhal_sys_timer_create(timer_id, tmr_handler, mode);
}

int32_t udrv_system_timer_start (SysTimerID_E timer_id, uint32_t count, void *m_data) {
    return uhal_sys_timer_start(timer_id, count, m_data);
}

int32_t udrv_system_timer_stop (SysTimerID_E timer_id) {
    return uhal_sys_timer_stop(timer_id);
}

void udrv_system_timer_handler_handler (void *pdata) {
    uhal_timer_handler_handler(pdata);
}

unsigned long  udrv_get_microsecond(void)
{
    return uhal_get_microsecond();
}
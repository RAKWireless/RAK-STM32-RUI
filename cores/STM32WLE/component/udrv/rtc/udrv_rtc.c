#include <stddef.h>
#include "udrv_rtc.h"
#include "uhal_rtc.h"

uint32_t udrv_rtc_tick2ms(uint32_t tick) {
    return uhal_rtc_tick2ms(tick);
}

uint32_t udrv_rtc_ms2tick(uint32_t ms) {
    return uhal_rtc_ms2tick(ms);
}

int32_t udrv_rtc_init (RtcID_E timer_id, rtc_handler handler)
{ 
    return uhal_rtc_init(timer_id, handler, SYS_RTC_FREQ);
}

int32_t udrv_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data)
{ 
    return uhal_rtc_set_alarm(timer_id, count, m_data);
}

int32_t udrv_rtc_cancel_alarm (RtcID_E timer_id)
{ 
    return uhal_rtc_cancel_alarm(timer_id);
}

uint64_t udrv_rtc_get_counter (RtcID_E timer_id)
{
    return uhal_rtc_get_counter(timer_id);
}

uint64_t udrv_rtc_get_timestamp (RtcID_E timer_id)
{ 
    return uhal_rtc_get_timestamp(timer_id);
}

uint64_t udrv_rtc_get_us_timestamp (RtcID_E timer_id)
{
    return uhal_rtc_get_us_timestamp(timer_id);
}

uint64_t udrv_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t old_ts)
{ 
    return uhal_rtc_get_elapsed_time(timer_id, old_ts);
}

void udrv_rtc_suspend(void)
{
    uhal_rtc_suspend();
}

void udrv_rtc_resume(void)
{
    uhal_rtc_resume();
}

void udrv_rtc_timer_handler_handler (void *pdata) {
    uhal_rtc_handler_handler(pdata);
}

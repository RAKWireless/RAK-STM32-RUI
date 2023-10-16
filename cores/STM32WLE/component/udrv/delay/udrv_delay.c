#include <stddef.h>
#include "udrv_delay.h"
#include "uhal_delay.h"
#include "udrv_rtc.h"

extern void rui_running(void);

void udrv_app_delay_ms (uint32_t ms_time)
{
    uint64_t start, end;

    start = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
    end = start + ms_time;

    udrv_system_user_app_timer_stop();

    while (udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT) < end) {
        rui_running();
    }
}

void udrv_app_delay_us (uint32_t us_time)
{
#if defined(STM32WLE5xx) || defined(DNRF52840_XXAA)
    uhal_delay_us(us_time);
#else
    uint64_t start, end;
    uint32_t delay_us_time;

    start = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
    end = start + us_time/1000;

    udrv_system_user_app_timer_stop();

    while (udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT) < end) {
        rui_running();
    }

    delay_us_time = us_time%1000;
    if (delay_us_time)
        uhal_delay_us(delay_us_time);
#endif
}

void udrv_delay_ms (uint32_t ms_time)
{
    uhal_delay_ms(ms_time);
}

void udrv_delay_us (uint32_t us_time)
{
    uhal_delay_us(us_time);
}


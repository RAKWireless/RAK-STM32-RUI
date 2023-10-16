#include "uhal_delay.h"

void uhal_delay_ms (uint32_t ms_time) {
    HAL_Delay(ms_time);
}

void uhal_delay_us (uint32_t us_time) {
/*    uint64_t start, end;
    uint32_t delay_us_time;

    start = uhal_rtc_get_us_timestamp(0);
    end = start + us_time;
    uhal_sys_user_app_timer_stop();
    while (uhal_rtc_get_us_timestamp(0) < end); */

        uint32_t l = us_time<<4;
        l = l-4;
        __asm__ __volatile__( "0:" "SUBS %[count], 1;" "BNE 0b;" :[count]"+r"(l) );
}


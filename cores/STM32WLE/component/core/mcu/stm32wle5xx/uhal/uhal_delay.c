#include "uhal_delay.h"

void uhal_delay_ms (uint32_t ms_time) {
    HAL_Delay(ms_time);
}

void uhal_delay_us (uint32_t us_time) {
        uint32_t l = us_time<<4;
        __asm__ __volatile__( "0:" "SUBS %[count], 1;" "BNE 0b;" :[count]"+r"(l) );
}


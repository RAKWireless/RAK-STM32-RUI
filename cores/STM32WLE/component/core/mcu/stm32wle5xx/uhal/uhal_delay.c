#include "uhal_delay.h"

void uhal_delay_ms (uint32_t ms_time) {
    HAL_Delay(ms_time);
}

void uhal_delay_us (uint32_t us_time) {
    uint32_t temp;
    SysTick->LOAD = 6 * us_time;
    SysTick->VAL  = 0x00;
    SysTick->CTRL = 0x01;

    do {
        temp = SysTick->CTRL;
    } while((temp&0x01) && (!(temp&(1<<16))));

    SysTick->CTRL = 0x00;
    SysTick->VAL  = 0x00;
    HAL_InitTick(TICK_INT_PRIORITY);
}


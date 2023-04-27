#include "uhal_powersave.h"
#include "udrv_errno.h"
#include "radio_conf.h"

static UTIL_TIMER_Object_t uhal_ps_timer_id;

int32_t uhal_ps_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    if (UTIL_TIMER_Create(&uhal_ps_timer_id, 0xFFFFFFFFU, UTIL_TIMER_ONESHOT, tmr_handler, NULL) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_ps_timer_start (uint32_t count, void *m_data) {
    if (UTIL_TIMER_SetPeriod(&uhal_ps_timer_id, count) == UTIL_TIMER_OK)
    {
        if (UTIL_TIMER_Start(&uhal_ps_timer_id) == UTIL_TIMER_OK)
        {
            return UDRV_RETURN_OK;
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_ps_timer_stop () {
    if (UTIL_TIMER_Stop(&uhal_ps_timer_id) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

void uhal_mcu_sleep (uint32_t level) {
    CRITICAL_SECTION_BEGIN();

    HAL_SuspendTick();

    LL_PWR_ClearFlag_C1STOP_C1STB();
 
    if(level == 2) 
        HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
    else
        HAL_PWREx_EnterSTOP1Mode(PWR_STOPENTRY_WFI);

    HAL_ResumeTick();

    CRITICAL_SECTION_END();
}

static void clock_initialization() {
}

void uhal_sys_clock_init(void) {

}

void uhal_sys_clock_on(void) {
    SystemClock_Config();
}

void uhal_sys_clock_off(void) {
}

#include "udrv_errno.h"
#include "udrv_system.h"
#include "uhal_timer.h"
#include "stm32wlxx_hal.h"

extern bool udrv_powersave_in_sleep;

UTIL_TIMER_Object_t uhal_timer_id0;
UTIL_TIMER_Object_t uhal_timer_id1;
UTIL_TIMER_Object_t uhal_timer_id2;
UTIL_TIMER_Object_t uhal_timer_id3;
UTIL_TIMER_Object_t uhal_timer_id4;
UTIL_TIMER_Object_t uhal_sys_timer_id0;
UTIL_TIMER_Object_t uhal_sys_timer_id1;
UTIL_TIMER_Object_t uhal_sys_timer_id2;
UTIL_TIMER_Object_t uhal_sys_timer_id3;
UTIL_TIMER_Object_t uhal_sys_timer_id4;

static uhal_timer_data uhal_timer_pdata[TIMER_ID_MAX];
static uhal_timer_data uhal_sys_timer_pdata[SYSTIMER_ID_MAX];

static udrv_system_event_t rui_user_timer_event[TIMER_ID_MAX];
static udrv_system_event_t rui_sys_timer_event[SYSTIMER_ID_MAX];

void uhal_timer_handler_handler(void *pdata)
{
    if (((uhal_timer_data *)pdata)->timer_func) {
        ((uhal_timer_data *)pdata)->timer_func(((uhal_timer_data *)pdata)->m_data);
    }
}

static void uhal_timer_handler_dispatcher(TimerID_E timer_id)
{
    udrv_powersave_in_sleep = false;

    rui_user_timer_event[timer_id].request = UDRV_SYS_EVT_OP_USER_TIMER;
    rui_user_timer_event[timer_id].p_context = (void *)&uhal_timer_pdata[timer_id];
    udrv_system_event_produce(&rui_user_timer_event[timer_id]);
}

static void uhal_sys_timer_handler_dispatcher(SysTimerID_E timer_id)
{
    udrv_powersave_in_sleep = false;

    rui_sys_timer_event[timer_id].request = UDRV_SYS_EVT_OP_SYS_TIMER;
    rui_sys_timer_event[timer_id].p_context = (void *)&uhal_sys_timer_pdata[timer_id];
    udrv_system_event_produce(&rui_sys_timer_event[timer_id]);
}

UTIL_TIMER_Mode_t get_stm_timer_mode(TimerMode_E mode)
{
    switch (mode)
    {
    case HTMR_ONESHOT:
        return UTIL_TIMER_ONESHOT;
    case HTMR_PERIODIC:
        return UTIL_TIMER_PERIODIC;
    default:
        return UTIL_TIMER_PERIODIC;
    }
}

static UTIL_TIMER_Object_t * get_stm_timer_obj(TimerID_E timer_id)
{
    switch (timer_id)
    {
    case TIMER_0:
        return &uhal_timer_id0;
    case TIMER_1:
        return &uhal_timer_id1;
    case TIMER_2:
        return &uhal_timer_id2;
    case TIMER_3:
        return &uhal_timer_id3;
    case TIMER_4:
        return &uhal_timer_id4;
    default:
        return NULL;
    }
}

static UTIL_TIMER_Object_t * get_sys_stm_timer_id(SysTimerID_E timer_id)
{
    switch (timer_id)
    {
    case SYSTIMER_LORAWAN:
        return &uhal_sys_timer_id0;
    case SYSTIMER_TRANSPARENT_MODE:
        return &uhal_sys_timer_id1;
    case SYSTIMER_PROTOCOL_MODE:
        return &uhal_sys_timer_id2;
    case SYSTIMER_LED:
        return &uhal_sys_timer_id3;
    case SYSTIMER_LCT:
        return &uhal_sys_timer_id4;
    default:
        return NULL;
    }
}

void uhal_timer_init(void)
{
    UTIL_TIMER_Status_t ret = UTIL_TIMER_Init();
    return;
}

int32_t uhal_timer_create(TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode)
{
    uhal_timer_pdata[timer_id].timer_id = timer_id;
    uhal_timer_pdata[timer_id].timer_func = tmr_handler;

    UTIL_TIMER_Object_t *stm_timer_object = get_stm_timer_obj(timer_id);
    if (UTIL_TIMER_Create(stm_timer_object, 0xFFFFFFFFU, get_stm_timer_mode(mode), uhal_timer_handler_dispatcher, (void *)timer_id) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_timer_start(TimerID_E timer_id, uint32_t count, void *m_data)
{
    UTIL_TIMER_Object_t *stm_timer_object = get_stm_timer_obj(timer_id);

    uhal_timer_pdata[timer_id].timer_id = timer_id;
    uhal_timer_pdata[timer_id].m_data = m_data;

    if (UTIL_TIMER_SetPeriod(stm_timer_object, count) == UTIL_TIMER_OK)
    {
        if (UTIL_TIMER_Start(stm_timer_object) == UTIL_TIMER_OK)
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

int32_t uhal_timer_stop(TimerID_E timer_id)
{
    UTIL_TIMER_Object_t *stm_timer_object = get_stm_timer_obj(timer_id);

    uhal_timer_pdata[timer_id].m_data = NULL;

    if (UTIL_TIMER_Stop(stm_timer_object) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_timer_create(SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode)
{
    uhal_sys_timer_pdata[timer_id].sys_timer_id = timer_id;
    uhal_sys_timer_pdata[timer_id].timer_func = tmr_handler;

    UTIL_TIMER_Object_t *stm_timer_object = get_sys_stm_timer_id(timer_id);
    if (UTIL_TIMER_Create(stm_timer_object, 0xFFFFFFFFU, get_stm_timer_mode(mode), uhal_sys_timer_handler_dispatcher, (void *)timer_id) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_timer_start(SysTimerID_E timer_id, uint32_t count, void *m_data)
{
    UTIL_TIMER_Object_t *stm_timer_object = get_sys_stm_timer_id(timer_id);

    uhal_sys_timer_pdata[timer_id].sys_timer_id = timer_id;
    uhal_sys_timer_pdata[timer_id].m_data = m_data;

    if (UTIL_TIMER_SetPeriod(stm_timer_object, count) == UTIL_TIMER_OK)
    {
        if (UTIL_TIMER_Start(stm_timer_object) == UTIL_TIMER_OK)
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

int32_t uhal_sys_timer_stop(SysTimerID_E timer_id)
{
    UTIL_TIMER_Object_t * stm_timer_object = get_sys_stm_timer_id(timer_id);

    uhal_sys_timer_pdata[timer_id].m_data = NULL;

    if (UTIL_TIMER_Stop(stm_timer_object) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

static inline uint32_t LL_SYSTICK_IsActiveCounterFlag(void)
{
    return ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == (SysTick_CTRL_COUNTFLAG_Msk));
}

uint32_t uhal_get_microsecond(void)
{
    uint32_t m = HAL_GetTick();
    const uint32_t tms = (SysTick->LOAD + 1)/1000;
    __IO uint32_t u = SysTick->LOAD + 1 - SysTick->VAL;
    return (uint64_t)(m * 1000 + (u/tms));
}

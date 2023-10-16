#include <stddef.h>
#include "udrv_system.h"
#include "uhal_system.h"
#ifndef RUI_BOOTLOADER
#include "uhal_timer.h"
#include "fund_event_queue.h"
#endif
#ifdef SUPPORT_MULTITASK
#include "uhal_sched.h"

extern tcb_ *current_thread;
#endif

#if defined(rak11720) && defined(RUI_BOOTLOADER)
#include "fund_event_queue.h"
#endif

void rui_event_handler_func(void *data, uint16_t size);

void udrv_system_event_init(void)
{
    FUND_EVENT_QUEUE_INIT(EVENT_DATA_SIZE, EVENT_QUEUE_SIZE);
}

int32_t udrv_system_event_produce(udrv_system_event_t *event)
{
    return fund_event_queue_put(event, sizeof(udrv_system_event_t), rui_event_handler_func);
}

void udrv_system_event_consume(void)
{
    fund_event_queue_execute();
}

void udrv_system_reboot(void)
{
    return uhal_sys_reboot();
}

#if  defined(rak11720) && defined(RUI_BOOTLOADER)
void udrv_system_critical_section_begin (uint32_t *mask)
{ 
    return uhal_sys_board_critical_section_begin(mask);
}

void udrv_system_critical_section_end (uint32_t *mask)
{ 
    return uhal_sys_board_critical_section_end(mask);
}
#endif

#ifndef RUI_BOOTLOADER
void udrv_system_critical_section_begin (uint32_t *mask)
{ 
    return uhal_sys_board_critical_section_begin(mask);
}

void udrv_system_critical_section_end (uint32_t *mask)
{ 
    return uhal_sys_board_critical_section_end(mask);
}

unsigned long udrv_system_random (unsigned long maxvalue)
{
    return uhal_sys_random(maxvalue);
}

void udrv_randomseed(unsigned long seed)
{
    uhal_sys_randomseed(seed);
}

int32_t udrv_system_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode)
{
    return uhal_sys_user_app_timer_create(tmr_handler, mode);
}

int32_t udrv_system_user_app_timer_start (uint32_t count, void *m_data)
{
    return uhal_sys_user_app_timer_start (count, m_data);
}

int32_t udrv_system_user_app_timer_stop (void)
{
    return uhal_sys_user_app_timer_stop();
}

int32_t udrv_create_thread(char *name, UDRV_TASK_HANDLER handler)
{
#ifdef SUPPORT_MULTITASK
    return uhal_sched_create_thread(name, handler);
#else
    return UDRV_RETURN_OK;
#endif
}

void udrv_destroy_thread(char *name)
{
#ifdef SUPPORT_MULTITASK
    tcb_ *tcb = uhal_sched_get_tcb_by_name(name);
    uhal_sched_destroy_thread(tcb);
#endif
}

void udrv_destroy_myself(void)
{
#ifdef SUPPORT_MULTITASK
    uhal_sched_destroy_thread(current_thread);
#endif
}

void udrv_thread_lock(void)
{
#ifdef SUPPORT_MULTITASK
    uhal_sched_lock();
#endif
}
void udrv_thread_unlock(void)
{
#ifdef SUPPORT_MULTITASK
    uhal_sched_unlock();
#endif
}
#endif

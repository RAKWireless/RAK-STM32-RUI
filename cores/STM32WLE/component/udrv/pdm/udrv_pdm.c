#include <stddef.h>
#include "udrv_delay.h"
#include "udrv_pdm.h"

void udrv_pdm_enable_frequency(void)
{
    uhal_pdm_enable_frequency();
}

bool udrv_pdm_set_rate(long rate)
{
    return uhal_pdm_set_rate(rate);
}
 
bool udrv_pdm_set_channel(int channels)
{
    return uhal_pdm_set_channel(channels);
}

void udrv_pdm_psel_connect(uint32_t psel_clk,uint32_t psel_din)
{
    uhal_pdm_psel_connect(psel_clk,psel_din);
}

void udrv_pdm_event_clear(udrv_pdm_event_t event)
{
    uhal_pdm_event_clear(event);
}

void udrv_pdm_int_enable(void)
{
    uhal_pdm_int_enable();
}

void udrv_pdm_set_nvic(void)
{
    uhal_pdm_set_nvic();
}

void udrv_pdm_enable(void)
{
    uhal_pdm_enable();
}

void udrv_pdm_task_trigger(udrv_pdm_task_t task)
{
    uhal_pdm_task_trigger(task);
}

void udrv_pdm_disable(void)
{
    uhal_pdm_disable();
}

void udrv_pdm_disable_nvic(void)
{
    uhal_pdm_disable_nvic();
}

void udrv_pdm_enable_nvic(void)
{
    uhal_pdm_enable_nvic();
}

void udrv_pdm_psel_disconnect(void)
{
    uhal_pdm_psel_disconnect();
}

void udrv_pdm_set_gain(int gain)
{
    uhal_pdm_set_gain(gain);
}

bool udrv_pdm_event_check(udrv_pdm_event_t event)
{
    return uhal_pdm_event_check(event);
}

bool udrv_pdm_buffer_set(uint32_t * p_buffer, uint32_t num)
{
    return uhal_pdm_buffer_set(p_buffer,num);
}


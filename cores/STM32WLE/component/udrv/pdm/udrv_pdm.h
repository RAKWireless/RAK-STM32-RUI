#ifndef _UDRV_PDM_H_
#define _UDRV_PDM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    UDRV_PDM_TASK_START,
    UDRV_PDM_TASK_STOP,
} udrv_pdm_task_t;

typedef enum
{
    UDRV_PDM_EVENT_STARTED,
    UDRV_PDM_EVENT_STOPPED,
    UDRV_PDM_EVENT_END,
} udrv_pdm_event_t;

void udrv_pdm_enable_frequency(void);
bool udrv_pdm_set_rate(long rate);
bool udrv_pdm_set_channel(int channels);
void udrv_pdm_psel_connect(uint32_t psel_clk,uint32_t psel_din);
void udrv_pdm_event_clear(udrv_pdm_event_t event);
void udrv_pdm_int_enable(void);
void udrv_pdm_set_nvic(void);
void udrv_pdm_enable(void);
void udrv_pdm_task_trigger(udrv_pdm_task_t task);
void udrv_pdm_disable(void);
void udrv_pdm_disable_nvic(void);
void udrv_pdm_enable_nvic(void);
void udrv_pdm_psel_disconnect(void);
void udrv_pdm_set_gain(int gain);
bool udrv_pdm_event_check(udrv_pdm_event_t event);
bool udrv_pdm_buffer_set(uint32_t* p_buffer, uint32_t num);

#ifdef __cplusplus
}
#endif

#endif // #ifndef _UDRV_PDM_H_

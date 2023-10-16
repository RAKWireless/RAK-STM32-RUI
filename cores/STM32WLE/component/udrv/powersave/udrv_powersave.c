#include <stddef.h>
#include <stdbool.h>
#include "udrv_powersave.h"
#include "uhal_powersave.h"
#ifdef SUPPORT_LORA
#include "radio.h"
#include "service_lora.h"
#endif
#include "udrv_serial.h"
#include "udrv_gpio.h"
#include "udrv_twimst.h"
#include "udrv_pwm.h"
#include "udrv_adc.h"
#include "udrv_rtc.h"
#include "udrv_system.h"
#include "udrv_errno.h"

#ifdef  RAK5010_EVB
#include "bg96.h"
#endif

#define UDRV_PS_MAX_CB_NUM 16

POWER_SAVE_HANDLER udrv_ps_sleep_cb[UDRV_PS_MAX_CB_NUM];
POWER_SAVE_HANDLER udrv_ps_wakeup_cb[UDRV_PS_MAX_CB_NUM];

bool udrv_powersave_in_sleep;
bool udrv_powersave_in_deep_sleep;
bool udrv_powersave_early_wakeup;

static uint64_t udrv_powersave_last_wakeup_time;
static uint32_t udrv_powersave_min_wakeup_time = 3;//3ms > the time to receive 2 byte in baudrate 9600 = (1/9600)*10*2 = 2.08ms

uint32_t wlock_cnt;

#ifdef SUPPORT_MULTITASK
extern bool sched_pending;
#endif

#ifdef rak11720
extern volatile bool rx_wait_active;
extern volatile bool is_mcu_resumed;
static inline bool isInISR(void)
{
  return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0 ;
}
#endif

struct udrv_powersave_api powersave_driver =
{
  uhal_mcu_sleep,
  uhal_sys_clock_init,
  uhal_sys_clock_on,
  uhal_sys_clock_off,
};

static void powersave_mcu_sleep_handler(void * p_context)
{
    udrv_powersave_in_sleep = false;
}

static void powersave_radio_sleep_handler(void * p_context)
{
#ifdef SUPPORT_LORA
        service_lora_resume();
#endif
}

static void powersave_sleep_handler(void * p_context)
{
    udrv_powersave_in_sleep = false;
}

static void handle_sleep_callback() {
    for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
        if (udrv_ps_sleep_cb[i]) {
            udrv_ps_sleep_cb[i]();
        }
    }
}

static void handle_wakeup_callback() {
    for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
        if (udrv_ps_wakeup_cb[i]) {
            udrv_ps_wakeup_cb[i]();
        }
    }
}

static int32_t handle_mcu_sleep(bool all) {
    if ((udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT) - udrv_powersave_last_wakeup_time) < udrv_powersave_min_wakeup_time) {
        return -UDRV_BUSY;
    }

    if (fund_event_queue_space_get() != EVENT_QUEUE_SIZE) {
        return -UDRV_BUSY;
    }
    uint32_t sleep_level = service_nvm_get_auto_sleep_level_from_nvm();
#ifdef SUPPORT_MULTITASK
    sched_pending = true;
#endif

//#ifdef SUPPORT_BLE
//    //TODO: Consider advertising in sleep.
//    udrv_ble_stop();
//#endif

    handle_sleep_callback();

#ifdef rak11720
    UBaseType_t uxSavedInterruptStatus;
    if(isInISR())
    {
        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();
    }
    else
    {
        taskENTER_CRITICAL();
    }
#endif

#ifdef SUPPORT_USB
    uhal_usb_suspend();
#endif

#ifdef SUPPORT_SPI
    udrv_spimst_suspend();
#endif

    udrv_adc_suspend();
    udrv_pwm_suspend();
    udrv_serial_suspend();
    udrv_twimst_suspend();
    udrv_gpio_suspend();

    udrv_rtc_suspend();

#ifdef rak11720
    if(isInISR())
    {
        taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );

    }
    else
    {
        taskEXIT_CRITICAL();
    }
#endif

#if 1
    powersave_driver.SYS_CLOCK_OFF();
#endif

#ifdef RAK5010_EVB
    if (all) {
        RAK5010_BG96_POWER_DOWN;
    }
#endif

    while (udrv_powersave_in_sleep) {
        powersave_driver.MCU_SLEEP(sleep_level);
    }

#ifdef RAK5010_EVB
    if (all) {
        Gsm_PowerUp();
    }
#endif

#if 1
    powersave_driver.SYS_CLOCK_ON();
#endif

#ifdef rak11720
    if(isInISR())
    {
        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();
    }
    else
    {
        taskENTER_CRITICAL();
    }
#endif

    udrv_rtc_resume();
    udrv_gpio_resume();
#ifdef SUPPORT_SPI
    udrv_spimst_resume();
#endif
    udrv_twimst_resume();
    udrv_serial_resume();
    udrv_pwm_resume();
    udrv_adc_resume();
#ifdef SUPPORT_USB
    uhal_usb_resume();
#endif

#ifdef rak11720
    if(isInISR())
    {
        taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );

    }
    else
    {
        taskEXIT_CRITICAL();
    }
#endif

    handle_wakeup_callback();

//#ifdef SUPPORT_BLE
//    //TODO: Consider advertising in sleep.
//    //udrv_ble_stack_start();
//    udrv_ble_services_start();
//#endif

#ifdef SUPPORT_MULTITASK
    sched_pending = false;
#endif

    udrv_powersave_last_wakeup_time = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);

    return UDRV_RETURN_OK;
}

void udrv_powersave_wake_lock (void) {
    wlock_cnt++;
}

void udrv_powersave_wake_unlock (void) {
    if (wlock_cnt > 0) {
        wlock_cnt--;
    }
}


int32_t udrv_mcu_sleep_ms (uint32_t ms_time)
{
    if (wlock_cnt) {
#ifdef SUPPORT_WDT
        udrv_wdt_feed();
#endif
        return -UDRV_TEMP_LOCKED;
    }

#ifdef rak11720
    if( rx_wait_active == true)
        return -UDRV_BUSY;
    if( is_mcu_resumed == true)
        return -UDRV_BUSY;
#endif

    udrv_powersave_in_deep_sleep = false;
    udrv_powersave_in_sleep = true;

    if (ms_time != 0) {
        uhal_ps_timer_create(powersave_mcu_sleep_handler, HTMR_ONESHOT);
        uhal_ps_timer_stop();
        uhal_ps_timer_start(ms_time, NULL);
    }

    return handle_mcu_sleep(false);
}

void udrv_radio_sleep_ms (uint32_t ms_time)
{
    if (wlock_cnt) {
#ifdef SUPPORT_WDT
        udrv_wdt_feed();
#endif
        return;
    }

    udrv_powersave_in_deep_sleep = false;
    udrv_powersave_in_sleep = true;

    if (ms_time != 0) {
        uhal_ps_timer_create(powersave_radio_sleep_handler, HTMR_ONESHOT);
        uhal_ps_timer_stop();
        uhal_ps_timer_start(ms_time, NULL);
    }

#ifdef SUPPORT_LORA
        service_lora_suspend();
#endif
}

int32_t udrv_sleep_ms (uint32_t ms_time)
{
    int32_t ret;

    if (wlock_cnt) {
#ifdef SUPPORT_WDT
        udrv_wdt_feed();
#endif
        return -UDRV_TEMP_LOCKED;
    }

#ifdef rak11720
    if( rx_wait_active == true)
        return -UDRV_BUSY;
    if( is_mcu_resumed == true)
        return -UDRV_BUSY;
#endif

#ifdef SUPPORT_LORA
    if (service_lora_isbusy()) {
#endif
        udrv_powersave_in_deep_sleep = true;
#ifdef SUPPORT_LORA
    } else {
        udrv_powersave_in_deep_sleep = false;
    }
#endif
    udrv_powersave_in_sleep = true;

    if (ms_time != 0) {
        uhal_ps_timer_create(powersave_sleep_handler, HTMR_ONESHOT);
        uhal_ps_timer_stop();
        uhal_ps_timer_start(ms_time, NULL);
    }

#ifdef SUPPORT_LORA
        service_lora_suspend();
#endif
    ret = handle_mcu_sleep(true);

#ifdef SUPPORT_LORA
        service_lora_resume();
#endif
    return ret;
}

void udrv_sys_clock_init(void) {
    powersave_driver.SYS_CLOCK_INIT();
}

void udrv_sys_clock_on(void) {
    powersave_driver.SYS_CLOCK_ON();
}

void udrv_sys_clock_off(void) {
    powersave_driver.SYS_CLOCK_OFF();
}

void udrv_register_sleep_callback(POWER_SAVE_HANDLER handler) {
    if (handler != NULL) {
        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_sleep_cb[i] == handler) {
                /* It already exists! */
                return;
            }
        }

        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_sleep_cb[i] == NULL) {
                udrv_ps_sleep_cb[i] = handler;
                return;
            }
        }
    }
}

void udrv_deregister_sleep_callback(POWER_SAVE_HANDLER handler) {
    if (handler != NULL) {
        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_sleep_cb[i] == handler) {
                /* Remove it! */
                udrv_ps_sleep_cb[i] = NULL;
                return;
            }
        }
    }
}

int32_t udrv_register_wakeup_callback(POWER_SAVE_HANDLER handler) {
    if (handler != NULL) {
        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_wakeup_cb[i] == handler) {
                /* It already exists! */
                return UDRV_RETURN_OK;
            }
        }

        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_wakeup_cb[i] == NULL) {
                udrv_ps_wakeup_cb[i] = handler;
                return UDRV_RETURN_OK;
            }
        }
    }
    return -UDRV_INTERNAL_ERR;
}

void udrv_deregister_wakeup_callback(POWER_SAVE_HANDLER handler) {
    if (handler != NULL) {
        for (int i = 0 ; i < UDRV_PS_MAX_CB_NUM ; i++) {
            if (udrv_ps_wakeup_cb[i] == handler) {
                /* Remove it! */
                udrv_ps_wakeup_cb[i] = NULL;
                return;
            }
        }
    }
}

void udrv_set_min_wakeup_time(uint32_t ms_time) {
    udrv_powersave_min_wakeup_time = ms_time;
}

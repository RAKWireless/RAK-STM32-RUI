#ifndef _UDRV_POWERSAVE_H_
#define _UDRV_POWERSAVE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <udrv_timer.h>

typedef void (*POWER_SAVE_HANDLER) (void);

//The structure of powersave function 
struct udrv_powersave_api {
    void (*MCU_SLEEP) (void);
    void (*SYS_CLOCK_INIT) (void);
    void (*SYS_CLOCK_ON) (void);
    void (*SYS_CLOCK_OFF) (void);
};

void udrv_powersave_wake_lock (void);
void udrv_powersave_wake_unlock (void);
int32_t udrv_mcu_sleep_ms (uint32_t ms_time);
void udrv_radio_sleep_ms (uint32_t ms_time);
int32_t udrv_sleep_ms (uint32_t ms_time);
void udrv_clock_init (void);
void udrv_clock_on (void);
void udrv_clock_off (void);
void udrv_register_sleep_callback(POWER_SAVE_HANDLER handler);
void udrv_deregister_sleep_callback(POWER_SAVE_HANDLER handler);
void udrv_register_wakeup_callback(POWER_SAVE_HANDLER handler);
void udrv_deregister_wakeup_callback(POWER_SAVE_HANDLER handler);
void udrv_set_min_wakeup_time(uint32_t ms_time);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_POWERSAVE_H_

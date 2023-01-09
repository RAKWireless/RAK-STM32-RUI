#ifndef _UDRV_RTC_H_
#define _UDRV_RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define SYS_RTC_FREQ 32768

typedef enum {
        UDRV_RTC_0 = 0,
        UDRV_RTC_1 = 1,
        UDRV_RTC_2 = 2,
        UDRV_RTC_MAX = 3,
} RtcID_E;

typedef void (*rtc_handler) (void *m_data);

uint32_t udrv_rtc_tick2ms(uint32_t tick);
uint32_t udrv_rtc_ms2tick(uint32_t ms);
int32_t udrv_rtc_init (RtcID_E timer_id, rtc_handler handler);
int32_t udrv_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data);
int32_t udrv_rtc_cancel_alarm (RtcID_E timer_id);
uint64_t udrv_rtc_get_counter (RtcID_E timer_id);
uint64_t udrv_rtc_get_timestamp (RtcID_E timer_id);
uint64_t udrv_rtc_get_us_timestamp (RtcID_E timer_id);
uint64_t udrv_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t savedTime);
void udrv_rtc_suspend (void);
void udrv_rtc_resume (void);

void udrv_rtc_timer_handler_handler (void *pdata);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_RTC_H_

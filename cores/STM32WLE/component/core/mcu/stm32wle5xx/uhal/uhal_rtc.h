#ifndef _UHAL_RTC_H_
#define _UHAL_RTC_H_

#include <stdint.h>
#include <stddef.h>
#include "udrv_rtc.h"
#include "stm32wlxx_hal.h"

#define UHAL_RTC_SLEEP_MODE_FREQ 10 /* Hz */

/*#define RTC_CLOCK_SOURCE_LSI*/
#define RTC_CLOCK_SOURCE_LSE

#ifdef RTC_CLOCK_SOURCE_LSI
#define RTC_ASYNCH_PREDIV    0x7F
#define RTC_SYNCH_PREDIV     0xFF
#endif

#ifdef RTC_CLOCK_SOURCE_LSE
#define RTC_ASYNCH_PREDIV  0x7F
#define RTC_SYNCH_PREDIV   0x00FF
#endif

#define RTC_N_PREDIV_S 15
#define RTC_PREDIV_S ((1<<RTC_N_PREDIV_S)-1)
#define RTC_PREDIV_A ((1<<(15-RTC_N_PREDIV_S))-1)

uint32_t uhal_rtc_tick2ms(uint32_t tick);
uint32_t uhal_rtc_ms2tick(uint32_t ms);
int32_t uhal_rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz);
int32_t uhal_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data);
int32_t uhal_rtc_cancel_alarm (RtcID_E timer_id);
uint64_t uhal_rtc_get_counter (RtcID_E timer_id);
uint64_t uhal_rtc_get_timestamp (RtcID_E timer_id);
uint64_t uhal_rtc_get_us_timestamp(RtcID_E timer_id);
uint64_t uhal_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t old_ts);
void uhal_rtc_suspend(void);
void uhal_rtc_resume(void);

#endif  // #ifndef _UHAL_RTC_H_

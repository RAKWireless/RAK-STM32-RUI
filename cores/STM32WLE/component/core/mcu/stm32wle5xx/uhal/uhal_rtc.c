#include "uhal_rtc.h"
#include "udrv_serial.h"
#include "stm32wlxx_ll_rtc.h"
#include "timer_if.h"

RTC_HandleTypeDef hrtc;

extern const UTIL_TIMER_Driver_s UTIL_TimerDriver;
extern const UTIL_SYSTIM_Driver_s UTIL_SYSTIMDriver;

uint32_t uhal_rtc_tick2ms(uint32_t tick) {
    return UTIL_TimerDriver.Tick2ms(tick);
}

uint32_t uhal_rtc_ms2tick(uint32_t ms) {
    return UTIL_TimerDriver.ms2Tick(ms);
}

uint32_t uhal_rtc_sleep_mode_tick2ms(uint32_t tick) {
    return UTIL_TimerDriver.Tick2ms(tick);
}


uint32_t uhal_rtc_sleep_mode_ms2tick(uint32_t ms) {
    return UTIL_TimerDriver.ms2Tick(ms);
}



int32_t uhal_rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz) {

    RTC_AlarmTypeDef sAlarm = {0};
    RTC_TimeTypeDef sTime;
  
    /** Initialize RTC Only
    */
    hrtc.Instance = RTC;
    hrtc.Init.AsynchPrediv = 0;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    hrtc.Init.OutPutPullUp = RTC_OUTPUT_PULLUP_NONE;
    hrtc.Init.BinMode = RTC_BINARY_ONLY;
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
      Error_Handler();
    }
  
    /** Initialize RTC and set the Time and Date
    */
    if (HAL_RTCEx_SetSSRU_IT(&hrtc) != HAL_OK)
    {
      Error_Handler();
    }
    /** Enable the Alarm A
    */
    sAlarm.BinaryAutoClr = RTC_ALARMSUBSECONDBIN_AUTOCLR_NO;
    sAlarm.AlarmTime.SubSeconds = 0x0; 
    sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
    sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
    sAlarm.Alarm = RTC_ALARM_A;
    if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, 0) != HAL_OK)
    {
      Error_Handler();
    }
    return 0;
}

int32_t uhal_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data) {
    UTIL_TimerDriver.StartTimerEvt(count);
    return 0;
}

int32_t uhal_rtc_cancel_alarm (RtcID_E timer_id) {
    UTIL_TimerDriver.StopTimerEvt();
    return 0;
}

uint64_t uhal_rtc_get_counter (RtcID_E timer_id) {
    return  UTIL_TimerDriver.GetTimerValue();
}

uint64_t uhal_rtc_get_timestamp(RtcID_E timer_id){
    uint32_t Seconds;
    uint16_t SubSeconds;
    Seconds = UTIL_SYSTIMDriver.GetCalendarTime(&SubSeconds );
    return  Seconds*1000 + SubSeconds;
}

static inline uint32_t LL_SYSTICK_IsActiveCounterFlag(void)
{
    return ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == (SysTick_CTRL_COUNTFLAG_Msk));
}

uint64_t uhal_rtc_get_us_timestamp(RtcID_E timer_id){
    uint64_t m = uhal_rtc_get_timestamp(timer_id);
    uint32_t mseconds = 0;
    uint32_t ticks;
    uint32_t timerValueLsb = (UINT32_MAX - LL_RTC_TIME_GetSubSecond(RTC));
    ticks =  timerValueLsb & RTC_PREDIV_S;
    mseconds = (ticks & ((1<<5)-1))*31 ;
    return m*1000 + mseconds;

}

uint64_t uhal_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t old_ts) {
    uint32_t nowInTicks = UTIL_TimerDriver.GetTimerValue( );
    uint32_t pastInTicks = UTIL_TimerDriver.ms2Tick( old_ts );
    return UTIL_TimerDriver.Tick2ms( nowInTicks- pastInTicks );
}

void uhal_rtc_suspend(void){
}

void uhal_rtc_resume(void){
}

#include "uhal_rtc.h"
#include "udrv_serial.h"
#include "stm32wlxx_ll_rtc.h"

RTC_HandleTypeDef hrtc;

uint8_t aShowTime[] = "hh:ms:ss";
uint8_t aShowTimeStamp[] = "hh:ms:ss";
uint8_t aShowDate[] = "dd-mm-yyyy";
uint8_t aShowDateStamp[] = "dd-mm-yyyy";

static uint32_t rtc_timer_context = 0;

static uint64_t time_base = 0;
static uint32_t max_ticks;
static rtc_handler compare0_handler;

uint32_t uhal_rtc_tick2ms(uint32_t tick) {
    return (uint32_t)((float)tick*(float)1000/(float)SYS_RTC_FREQ);
}

uint32_t uhal_rtc_ms2tick(uint32_t ms) {
    return (uint32_t)((float)ms*(float)SYS_RTC_FREQ/(float)1000);
}

uint32_t uhal_rtc_sleep_mode_tick2ms(uint32_t tick) {
    return (uint32_t)((float)tick*(float)1000/(float)UHAL_RTC_SLEEP_MODE_FREQ);
}

uint32_t uhal_rtc_sleep_mode_ms2tick(uint32_t ms) {
    return (uint32_t)((float)ms*(float)UHAL_RTC_SLEEP_MODE_FREQ/(float)1000);
}

static int32_t rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz) {
    return 0;
}

int32_t uhal_rtc_init (RtcID_E timer_id, rtc_handler handler, uint32_t hz) {

    RTC_AlarmTypeDef sAlarm = {0};
    RTC_TimeTypeDef sTime;
  
    /** Initialize RTC Only
    */
    hrtc.Instance = RTC;
    hrtc.Init.AsynchPrediv = RTC_PREDIV_A;
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
    //sAlarm.AlarmTime.SubSeconds = (0xFFFFFFFFu - (5 * 32768 / (127 + 1))); 
    sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
    sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
    sAlarm.Alarm = RTC_ALARM_A;
    if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, 0) != HAL_OK)
    {
      Error_Handler();
    }

    rtc_timer_context = uhal_rtc_get_counter(UDRV_RTC_0);

    if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
    {
      Error_Handler();
    }

    return 0;
}

int32_t uhal_rtc_set_alarm (RtcID_E timer_id, uint32_t count, void *m_data) {
    RTC_AlarmTypeDef sAlarm = {0};

    uhal_rtc_cancel_alarm(UDRV_RTC_0);

    count += rtc_timer_context;

    /* starts timer*/
    sAlarm.BinaryAutoClr = RTC_ALARMSUBSECONDBIN_AUTOCLR_NO;
    sAlarm.AlarmTime.SubSeconds = 0xFFFFFFFFu - 4096;
    sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
    sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDBINMASK_NONE;
    sAlarm.Alarm = RTC_ALARM_A;
    if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BCD) != HAL_OK)
    {
      Error_Handler();
    }
    udrv_serial_printf(SERIAL_UART2, "UAHL alarm init %d\r\n", count);

    return 0;
}

int32_t uhal_rtc_cancel_alarm (RtcID_E timer_id) {
    /* Clear RTC Alarm Flag */
    __HAL_RTC_ALARM_CLEAR_FLAG(&hrtc, RTC_FLAG_ALRAF);

    /* Disable the Alarm A interrupt */
    HAL_RTC_DeactivateAlarm(&hrtc, RTC_ALARM_A);
    
    /*overload RTC feature enable*/
    hrtc.IsEnabled.RtcFeatures = UINT32_MAX;

    return 0;
}

uint64_t uhal_rtc_get_counter (RtcID_E timer_id) {
    return (UINT32_MAX - LL_RTC_TIME_GetSubSecond(RTC));
}

uint64_t uhal_rtc_get_timestamp(RtcID_E timer_id){
    return (UINT32_MAX - LL_RTC_TIME_GetSubSecond(RTC));
}

uint64_t uhal_rtc_get_elapsed_time (RtcID_E timer_id, uint64_t old_ts) {
    return 0;
}

void uhal_rtc_suspend(void){
}

void uhal_rtc_resume(void){
}

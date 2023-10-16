/*!
 * \file      rtc-board.c
 *
 * \brief     Target board RTC timer and low power modes management
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech - STMicroelectronics
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 *
 * \author    MCD Application Team (C)( STMicroelectronics International )
 */
#include <math.h>
#include <time.h>
#include "utilities.h"
#include "delay.h"
#include "board.h"
#include "timer.h"
#include "systime.h"
//#include "gpio.h"
//#include "sysIrqHandlers.h"
//#include "lpm-board.h"
#include "rtc-board.h"
#include "udrv_rtc.h"
#include "service_nvm.h"

// MCU Wake Up Time
#define MIN_ALARM_DELAY                             3 // in ticks

// sub-second number of bits
#define N_PREDIV_S                                  10

// Synchronous prediv
#define PREDIV_S                                    ( ( 1 << N_PREDIV_S ) - 1 )

// Asynchronous prediv
#define PREDIV_A                                    ( 1 << ( 15 - N_PREDIV_S ) ) - 1

// Sub-second mask definition
#define ALARM_SUBSECOND_MASK                        ( N_PREDIV_S << RTC_ALRMASSR_MASKSS_Pos )

// RTC Time base in us
#define USEC_NUMBER                                 1000000
#define MSEC_NUMBER                                 ( USEC_NUMBER / 1000 )

#define COMMON_FACTOR                               3
#define CONV_NUMER                                  ( MSEC_NUMBER >> COMMON_FACTOR )
#define CONV_DENOM                                  ( 1 << ( N_PREDIV_S - COMMON_FACTOR ) )

/*!
 * \brief Days, Hours, Minutes and seconds
 */
#define DAYS_IN_LEAP_YEAR                           ( ( uint32_t )  366U )
#define DAYS_IN_YEAR                                ( ( uint32_t )  365U )
#define SECONDS_IN_1DAY                             ( ( uint32_t )86400U )
#define SECONDS_IN_1HOUR                            ( ( uint32_t ) 3600U )
#define SECONDS_IN_1MINUTE                          ( ( uint32_t )   60U )
#define MINUTES_IN_1HOUR                            ( ( uint32_t )   60U )
#define HOURS_IN_1DAY                               ( ( uint32_t )   24U )

/*!
 * \brief Correction factors
 */
#define  DAYS_IN_MONTH_CORRECTION_NORM              ( ( uint32_t )0x99AAA0 )
#define  DAYS_IN_MONTH_CORRECTION_LEAP              ( ( uint32_t )0x445550 )

/*!
 * \brief Calculates ceiling( X / N )
 */
#define DIVC( X, N )                                ( ( ( X ) + ( N ) -1 ) / ( N ) )

/*!
 * RTC timer context 
 */
typedef struct
{
    uint64_t        Time;         // Reference time
}RtcTimerContext_t;

/*!
 * \brief Indicates if the RTC is already Initialized or not
 */
static bool RtcInitialized = false;

/*!
 * \brief Indicates if the RTC Wake Up Time is calibrated or not
 */
static bool McuWakeUpTimeInitialized = false;

/*!
 * \brief Compensates MCU wakeup time
 */
static int16_t McuWakeUpTimeCal = 0;

/*!
 * Number of days in each month on a normal year
 */
static const uint8_t DaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*!
 * Number of days in each month on a leap year
 */
static const uint8_t DaysInMonthLeapYear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*!
 * \brief RTC Alarm
 */
//static RTC_AlarmTypeDef RtcAlarm;

/*!
 * Keep the value of the RTC timer when the RTC alarm is set
 * Set with the \ref RtcSetTimerContext function
 * Value is kept as a Reference to calculate alarm
 */
static RtcTimerContext_t RtcTimerContext;


void TimerIrqHandler( void );


void RtcInit( void )
{
    if( RtcInitialized == false )
    {
        udrv_rtc_init(SYS_RTC_COUNTER_PORT, TimerIrqHandler);
        RtcInitialized = true;
    }
}

/*!
 * \brief Sets the RTC timer reference, sets also the RTC_DateStruct and RTC_TimeStruct
 *
 * \param none
 * \retval timerValue In ticks
 */
uint32_t RtcSetTimerContext( void )
{
    RtcTimerContext.Time = udrv_rtc_get_counter(SYS_RTC_COUNTER_PORT);
    return (uint32_t)RtcTimerContext.Time;
}

/*!
 * \brief Gets the RTC timer reference
 *
 * \param none
 * \retval timerValue In ticks
 */
uint32_t RtcGetTimerContext( void )
{
    return (uint32_t)RtcTimerContext.Time;
}

/*!
 * \brief returns the wake up time in ticks
 *
 * \retval wake up time in ticks
 */
uint32_t RtcGetMinimumTimeout( void )
{
    return( MIN_ALARM_DELAY );
}

/*!
 * \brief converts time in ms to time in ticks
 *
 * \param[IN] milliseconds Time in milliseconds
 * \retval returns time in timer ticks
 */
uint32_t RtcMs2Tick( uint32_t milliseconds )
{
    return udrv_rtc_ms2tick(milliseconds);
}

/*!
 * \brief converts time in ticks to time in ms
 *
 * \param[IN] time in timer ticks
 * \retval returns time in milliseconds
 */
uint32_t RtcTick2Ms( uint32_t tick )
{
    return udrv_rtc_tick2ms(tick);
}

/*!
 * \brief a delay of delay ms by polling RTC
 *
 * \param[IN] delay in ms
 */
void RtcDelayMs( uint32_t delay )
{
    udrv_delay_ms(delay);
}

/*!
 * \brief Sets the alarm
 *
 * \note The alarm is set at now (read in this function) + timeout
 *
 * \param timeout Duration of the Timer ticks
 */
void RtcSetAlarm( uint32_t timeout )
{
    udrv_rtc_set_alarm(SYS_RTC_COUNTER_PORT, timeout, NULL);
}

void RtcStopAlarm( void )
{
    udrv_rtc_cancel_alarm(SYS_RTC_COUNTER_PORT);
}

void RtcStartAlarm( uint32_t timeout )
{
    uint32_t old_ts = RtcGetTimerContext();
    uint64_t now = udrv_rtc_get_counter(SYS_RTC_COUNTER_PORT);
    udrv_rtc_cancel_alarm(SYS_RTC_COUNTER_PORT);
    if ( (old_ts + timeout) > now) {
        udrv_rtc_set_alarm(SYS_RTC_COUNTER_PORT, (old_ts + timeout - now), NULL);
    } else {
        udrv_rtc_set_alarm(SYS_RTC_COUNTER_PORT, 0, NULL);
    }
}

uint32_t RtcGetTimerValue( void )
{
    return (uint32_t)udrv_rtc_get_counter(SYS_RTC_COUNTER_PORT);
}

uint32_t RtcGetTimerElapsedTime( void )
{
    return (uint32_t)udrv_rtc_get_elapsed_time(SYS_RTC_COUNTER_PORT, RtcGetTimerContext());
}

void RtcSetMcuWakeUpTime( void )
{
    //TODO
}

int16_t RtcGetMcuWakeUpTime( void )
{
    return McuWakeUpTimeCal;
}

uint32_t RtcGetCalendarTime( uint16_t *milliseconds )
{
    uint64_t ts = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);

    *milliseconds = ts % 1000;

    return (uint32_t)(ts / 1000);
}

/*!
 * \brief RTC IRQ Handler of the RTC Alarm
 */
void RTC_IRQHandler( void )
{
    //TODO
}

void RtcBkupWrite( uint32_t data0, uint32_t data1 )
{
    service_nvm_set_delta_sec_to_nvm (data0);
    service_nvm_set_delta_subsec_to_nvm (data1);
}

void RtcBkupRead( uint32_t *data0, uint32_t *data1 )
{
    *data0 = service_nvm_get_delta_sec_from_nvm();
    *data1 = service_nvm_get_delta_subsec_from_nvm();
}

void RtcProcess( void )
{
    // Not used on this platform.
}

TimerTime_t RtcTempCompensation( TimerTime_t period, float temperature )
{
    return period;
}

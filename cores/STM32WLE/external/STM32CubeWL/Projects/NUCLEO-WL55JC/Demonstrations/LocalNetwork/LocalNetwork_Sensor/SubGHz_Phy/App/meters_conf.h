/**
  ******************************************************************************
  * @file    meters_conf.h
  * @author  MCD Application Team
  * @brief   Configuration for metering module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifndef __METERS_CONF_H__
#define __METERS_CONF_H__

/**
  * @brief Maximal period of measurement for slow sensors [ms].
  * This is the maximum period between two measurements if sensor is not connected.
  * If sensor is connected, the measurement is done just before transmit.
  * Slow sensors are: Humidity, Temperature, Pressure, Battery Voltage.
  */
#define METERS_SLOW_MAX_DELAY   (30*1000)

/**
  * @brief Enable sensors this long before reading out the measurement data [ms].
  */
#define METERS_SLOW_ENABLE_DELAY      150

/**
  * @brief Read out measurement data this long before NextGet from function void Meters_GetData() [ms].
  */
#define METERS_SLOW_PREMEASURE         10

/**
  * @brief Period of measurement of the ranging sensor [ms].
  * Measurement itself takes 33 ms.
  * Higher value will cripple the swipe detection, lower value increases consumption.
  */
#define METERS_RANGE_PERIOD           250

/**
  * @brief Time that the range sensor is blocked after out of range [ms].
  * When the sensor is out of range, it can sometimes throw values on the range limit which confuse
  * the swipe detection algorithm. This constant will block the sensor and swipe detection for a limited time.
  * Set to 0 to not block the swipe detection algorithm when sensor is out of range.
  */
#define METERS_RANGE_BLOCK_PERIOD    1000

/**
  * @brief Period of measurement for fast sensors [ms].
  * Fast sensors, magnetometer and accelerometer, are measured continuously.
  * This value affects multiple MotionXX libraries and some of them can misbehave for other frequencies than 50 Hz.
  */
#define METERS_FAST_PERIOD             20


#endif /* __METERS_CONF_H__ */

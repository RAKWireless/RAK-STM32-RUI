﻿/**
  @page PWR_STANDBY_RTC PWR_STANDBY_RTC example

  @verbatim
  ******************************************************************************
  * @file   PWR/PWR_STANDBY_RTC/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the PWR Standby RTC example.
  ******************************************************************************
  *
  * Copyright (c) 2020 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to enter the Standby mode and wake-up from this mode by using an external 
reset or the RTC wakeup timer.


In the associated software, the system clock is set to 48 MHz and the SysTick is
programmed to generate an interrupt each 1 ms.
The Low Speed Internal (LSI) clock is used as RTC clock source by default.
EXTI_Line20 is internally connected to the RTC Wakeup event.

The system automatically enters Standby mode 5 sec. after start-up. The RTC wake-up
is configured to generate an interrupt on rising edge about 33 sec. afterwards.
Current consumption in Standby mode with RTC feature enabled can be measured during that time.
More than half a minute is chosen to ensure current convergence to its lowest operating point.

After wake-up from Standby mode, program execution restarts in the same way as after
a software RESET.

Two leds LED2 and LED3 are used to monitor the system state as following:
 - LED3 ON: configuration failed (system will go to an infinite loop)
 - LED2 toggling: system in Run mode
 - LED2 off : system in Standby mode

These steps are repeated in an infinite loop.

@note To measure MCU current consumption on board STM32WL Nucleo,
      board configuration must be applied:
      - remove all jumpers on connector JP8 to avoid leakages between ST-Link circuitry and STM32WL device.
      - remove jumper JP1 and connect an amperemeter to measure current between the 2 connectors of the jumper.

@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled.

@note Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select 
      the RTC clock source; in this case the Backup domain will be reset in  
      order to modify the RTC Clock source, as consequence RTC registers (including 
      the backup registers) and RCC_CSR register are set to their reset values.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Power, PWR, Standby mode, Interrupt, EXTI, Wakeup, Low Power, RTC, External reset, LSI,

@par Directory contents

  - PWR/PWR_STANDBY_RTC/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  -  PWR/PWR_STANDBY_RTC/Inc/stm32wlxx_conf.h         HAL Configuration file
  -  PWR/PWR_STANDBY_RTC/stm32wlxx_it.h           Header for stm32wlxx_it.c
  -  PWR/PWR_STANDBY_RTC/Inc/main.h                         Header file for main.c
  -  PWR/PWR_STANDBY_RTC/Src/system_stm32wlxx.c       STM32WLxx system clock configuration file
  -  PWR/PWR_STANDBY_RTC/Src/stm32wlxx_it.c           Interrupt handlers
  -  PWR/PWR_STANDBY_RTC/Src/main.c                         Main program
  -  PWR/PWR_STANDBY_RTC/Src/stm32wlxx_hal_msp.c      HAL MSP module

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices

  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Use LED2 and LED1 connected respectively to PB.09 and LED1 pins

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

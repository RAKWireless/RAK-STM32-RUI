﻿/**
  @page PWR_EnterStandbyMode PWR standby example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/PWR/PWR_EnterStandbyMode/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR STANDBY mode example.
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

How to enter the Standby mode and wake up from this mode by using an external 
reset or a wakeup pin.

In the associated software, the system clock is set to 16 MHz.
An EXTI line is connected to the User push-button (B1) through PA.00 and configured to generate an 
interrupt on falling edge upon key press.

Request to enter in standby mode:
When a falling edge is detected on the EXTI line, an interrupt is generated. 
In the EXTI handler routine, the wake-up pin LL_PWR_WAKEUP_PIN1 is enabled and the 
corresponding wake-up flag cleared. Then, the system enters Standby mode causing 
LED2 to stop toggling.

Exit from Standby mode:
The user can wake-up the system in pressing the User push-button (B1) which is 
connected to the wake-up pin LL_PWR_WAKEUP_PIN1.
A falling edge on WKUP pin will wake-up the system from Standby.

Alternatively, an external reset (reset button on board) will wake-up system from Standby
as well as wake-up pin.

After wake-up from Standby mode, program execution restarts in the same way as 
after a reset and LED2 restarts toggling.
These steps are repeated in an infinite loop.

LED2 is used to monitor the system state as follows:
 - LED2 fast toggling (each 200ms): system in Run mode from reset (power on reset or reset pin while system was in Run mode)
 - LED2 slow toggling (each 500ms): system in Run mode after exiting from Standby mode
 - LED2 off: system in Standby mode

@note To measure MCU current consumption on board STM32WL Nucleo,
      board configuration must be applied:
      - remove all jumpers on connector JP8 to avoid leakages between ST-Link circuitry and STM32WL device.
      - remove jumper JP1 and connect an amperemeter to measure current between the 2 connectors of the jumper.

@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled.


@par Keywords

Power, PWR, Standby mode, Interrupt, EXTI, Wakeup, Low Power, External reset,

@par Directory contents 

  - PWR/PWR_EnterStandbyMode/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - PWR/PWR_EnterStandbyMode/Inc/main.h                  Header for main.c module
  - PWR/PWR_EnterStandbyMode/Inc/stm32_assert.h          Template file to include assert_failed function
  - PWR/PWR_EnterStandbyMode/Src/stm32wlxx_it.c          Interrupt handlers
  - PWR/PWR_EnterStandbyMode/Src/main.c                  Main program
  - PWR/PWR_EnterStandbyMode/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC
    board and can be easily tailored to any other supported device
    and development board.

  - NUCLEO-WL55JC RevC Set-up
    - LED2 connected to PB.09 pin
    - User push-button connected to pin PA.00 (External line 0)
    - WakeUp Pin LL_PWR_WAKEUP_PIN1 connected to PA.0

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

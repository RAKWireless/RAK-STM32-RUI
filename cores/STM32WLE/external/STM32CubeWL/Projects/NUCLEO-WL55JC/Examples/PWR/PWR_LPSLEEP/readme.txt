/**
  @page PWR_LPSLEEP Low Power sleep Mode Example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_LPSLEEP/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Low Power Sleep Mode example.
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

How to enter the Low-power sleep mode and wake up from this mode by using 
an interrupt.

In the associated software, the system clock is set to 48 MHz.
An EXTI line is connected to the user button through PA.00 and configured 
to generate an interrupt on falling edge upon key press.
 
The SysTick is programmed to generate an interrupt each 1 ms and in the SysTick 
interrupt handler, LED2 is toggled in order to indicate whether the MCU is in LP SLEEP mode 
or RUN mode.

5 seconds after start-up, the system automatically enters LP SLEEP mode and 
LED2 stops toggling.
The User push-button (B1) can be pressed at any time to wake-up the system. 
The software then comes back in RUN mode for 5 sec. before automatically entering LP SLEEP mode again. 

Two leds LED2 and LED3 are used to monitor the system state as following:
 - LED3 ON: configuration failed (system will go to an infinite loop)
 - LED2 toggling: system in RUN mode
 - LED2 off : system in LP SLEEP mode

These steps are repeated in an infinite loop.

@note To measure the current consumption in LP SLEEP mode, remove JP1 jumper 
      and connect an amperemeter to JP1 to measure IDD current.     
      
@note This example can not be used in DEBUG mode due to the fact 
      that the Cortex-M4 core is no longer clocked during low power mode 
      so debugging features are disabled.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@par Keywords

Power, PWR, Low Power, Sleep mode, Interrupt, Wakeup, External reset

@par Directory contents 

  - PWR/PWR_LPSLEEP/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32wlxx_conf.h         HAL Configuration file
  - PWR/PWR_LPSLEEP/Inc/stm32wlxx_it.h           Header for stm32wlxx_it.c
  - PWR/PWR_LPSLEEP/Inc/main.h                         Header file for main.c
  - PWR/PWR_LPSLEEP/Src/system_stm32wlxx.c       STM32WLxx system clock configuration file
  - PWR/PWR_LPSLEEP/Src/stm32wlxx_it.c           Interrupt handlers
  - PWR/PWR_LPSLEEP/Src/stm32wlxx_hal_msp.c      HAL MSP module
  - PWR/PWR_LPSLEEP/Src/main.c                         Main program

@par Hardware and Software environment

  - This example runs on STM32WLxx devices
      
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-WL55JC RevC set-up:
    - Use LED2 and LED3 connected respectively to PB.09 and PB.11 pins
    - Use the User push-button (B1) connected to pin PA.00 (External line 0)

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

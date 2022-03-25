﻿/**
  @page PWR_PVD PWR Programmable Voltage Detector (PVD) example
  
  @verbatim
  ******************************************************************************
  * @file    PWR/PWR_PVD/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWR Programmable Voltage Detector (PVD) example
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
How to configure the programmable voltage detector by using an external interrupt 
line. External DC supply must be used to supply Vdd.

In this example, EXTI line 16 is configured to generate an interrupt on each rising
or falling edge of the PVD output signal (which indicates that the Vdd voltage is
moving below or above the PVD threshold). As long as the voltage is above the 
target threshold (2.5V), LED2 is blinking with a 200 ms-period; when the voltage drops
below the threshold, LED2 stops blinking and remains constantly on (or appears
to be turned off if the voltage is getting really low); when the voltage moves back
above the target threshold, LED2 starts blinking again.

@note PVD thresholds have an hysteresis between rising and falling edges
      of approximatively 100mV. For Min/Typ/Max values of thresholds and hysteresis,
      refer to device datasheet.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Power, PWR, EXTI, PVD, Interrupt, Wakeup, External reset

@par Directory contents 

  - PWR/PWR_PVD/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - PWR/PWR_PVD/Inc/stm32wlxx_hal_conf.h     HAL Configuration file
  - PWR/PWR_PVD/Inc/stm32wlxx_it.h           Header for stm32wlxx_it.c
  - PWR/PWR_PVD/Inc/main.h                         Header file for main.c
  - PWR/PWR_PVD/Src/system_stm32wlxx.c       STM32WLxx system clock configuration file
  - PWR/PWR_PVD/Src/stm32wlxx_it.c           Interrupt handlers
  - PWR/PWR_PVD/Src/stm32wlxx_hal_msp.c      HAL MSP module
  - PWR/PWR_PVD/Src/main.c                         Main program

@par Hardware and Software environment

  - This example runs on STM32WLxx devices
    
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC
    board and can be easily tailored to any other supported device
    and development board.

  - NUCLEO-WL55JC RevC Set-up :
    - After that the software is flashed, 2 possible connections :
      - Solution 1: With USB cable connected:
        Keep JP4 to position STLNK (default), remove jumper JP1, apply power supply to JP1 connector on side marked "SoC"
      - Solution 2: Without USB cable:
        Move jumper JP4 to position E5V, apply power supply to Morpho connector CN7 pin 6 .       
    - LED2 (GREEN) connected to PB.09 pin indicates the behavior of
      the test software as explained above.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

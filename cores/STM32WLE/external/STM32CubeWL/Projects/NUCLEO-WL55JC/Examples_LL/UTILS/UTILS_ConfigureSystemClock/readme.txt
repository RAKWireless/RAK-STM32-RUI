/**
  @page UTILS_ConfigureSystemClock UTILS example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/UTILS/UTILS_ConfigureSystemClock/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the UTILS example.
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

Use of UTILS LL API to configure the system clock using PLL with HSI as source clock. 
The user application just needs to calculate the PLL parameters using STM32CubeMX and call the UTILS LL API.

System starts with clock used after reset.
Then, a system clock switch is done to PLL with HSI as PLL clock source. Automatically, FLASH latency
is tuned according to system constraints described in the reference manual.

User can easily set its own PLL parameters in changing global variable used to store them.

A LED2 toggle of 1sec provides this information that system is well configured to requested frequency.  

Anyway, user can connect on oscilloscope to MCO pin (PA.08) to check requested frequency: 
 - SYSCLK frequency with frequency value around @24MHz.

@par Keywords

Utils, system, Clock, HSI, PLL, flash latency, SYSCLK, frequency Oscilloscope


@par Directory contents 

  - UTILS/UTILS_ConfigureSystemClock/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - UTILS/UTILS_ConfigureSystemClock/Inc/main.h                  Header for main.c module
  - UTILS/UTILS_ConfigureSystemClock/Inc/stm32_assert.h          Template file to include assert_failed function
  - UTILS/UTILS_ConfigureSystemClock/Src/stm32wlxx_it.c          Interrupt handlers
  - UTILS/UTILS_ConfigureSystemClock/Src/main.c                  Main program
  - UTILS/UTILS_ConfigureSystemClock/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect the MCO pin to an oscilloscope to monitor the different waveforms:
      - PA.08: pin 16 in CN10 connector

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

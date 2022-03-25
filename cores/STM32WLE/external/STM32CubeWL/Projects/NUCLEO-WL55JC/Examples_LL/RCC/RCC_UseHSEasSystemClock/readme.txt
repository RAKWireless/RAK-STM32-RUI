/**
  @page RCC_UseHSEasSystemClock RCC Clock Config example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/RCC/RCC_UseHSEasSystemClock/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RCC HSE start example.
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

Use of the RCC LL API to start the HSE and use it as system clock.

At start-up, MSI clock is used as system clock (default clock after reset) and then Systick is 
configured at 1 ms after calculation of MSI frequency.

Then, HSE is started and we wait for ready state. System clock is set to HSE thanks to IT 
triggered by HSE ready.
- LED2 is turned ON to indicate that HSE is ready.
- LED2 is toggled with a timing of 1 second in case of error to switch SYSCLK to HSE or if HSE CSS
failure is detected (through NMI IT).


@par Keywords

System, RCC, PLL, PLLCLK, SYSCLK, HSE, Clock, Oscillator, HSI


@par Directory contents 

  - RCC/RCC_UseHSEasSystemClock/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - RCC/RCC_UseHSEasSystemClock/Inc/main.h                  Header for main.c module
  - RCC/RCC_UseHSEasSystemClock/Inc/stm32_assert.h          Template file to include assert_failed function
  - RCC/RCC_UseHSEasSystemClock/Src/stm32wlxx_it.c          Interrupt handlers
  - RCC/RCC_UseHSEasSystemClock/Src/main.c                  Main program
  - RCC/RCC_UseHSEasSystemClock/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC 
    board and can be easily tailored to any other supported device
    and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

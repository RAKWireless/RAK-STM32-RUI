/**
  @page RNG_GenerateRandomNumbers_IT RNG : Random Number Generation using IT
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/RNG/RNG_GenerateRandomNumbers_IT/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the RNG_GenerateRandomNumbers_IT example.
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

Configuration of the RNG to generate 32-bit long random numbers using interrupts. The peripheral initialization uses LL unitary service
functions for optimization purposes (performance and size).

Example execution:
After startup from reset and system configuration, RNG configuration is performed.
(Configure Main PLL to enable 48M domain, then enable PLLQ output mapped on 48MHz domain clock).

User is then asked to press User push-button (B1) (LED2 blinking fast).
On User push-button (B1) press, several (8) Random 32bit numbers are generated
(On each raised RNG interrupt, a random number is generated and retrieved from DR register).
Corresponding generated values are available and stored in a u32 array (aRandom32bit), 
whose content could be displayed using debugger (Watch or LiveWatch features).
After successful Random numbers generation, LED2 is turned On. 
In case of errors, LED2 is slowly blinking (1sec period).


@par Keywords

Analog, RNG, Random, FIPS PUB 140-2, Analog Random number generator, Entropy, Period, Interrupt


@par Directory contents 

  - RNG/RNG_GenerateRandomNumbers_IT/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - RNG/RNG_GenerateRandomNumbers_IT/Inc/main.h                  Header for main.c module
  - RNG/RNG_GenerateRandomNumbers_IT/Inc/stm32_assert.h          Template file to include assert_failed function
  - RNG/RNG_GenerateRandomNumbers_IT/Src/stm32wlxx_it.c          Interrupt handlers
  - RNG/RNG_GenerateRandomNumbers_IT/Src/main.c                  Main program
  - RNG/RNG_GenerateRandomNumbers_IT/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
 - Push User push-button (B1) and use Variable watch window from debugger to access to values of generated numbers.
   (A break point could be set on LED_On() call, at end of RandomNumbersGeneration_IT() function).

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

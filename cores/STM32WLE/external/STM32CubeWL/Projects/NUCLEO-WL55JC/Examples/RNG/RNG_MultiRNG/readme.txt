/**
  @page RNG_MultiRNG Multiple Random Numbers Generator example
  
  @verbatim
  ******************************************************************************
  * @file    RNG/RNG_MultiRNG/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of multiple random numbers generation example.
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

Configuration of the RNG using the HAL API. This example uses the RNG to generate 32-bit long random numbers.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 48 MHz.

The RNG peripheral configuration is ensured by the HAL_RNG_Init() function.
The latter is calling the HAL_RNG_MspInit() function which implements
the configuration of the needed RNG resources according to the used hardware (CLOCK, 
GPIO, DMA and NVIC). You may update this function to change RNG configuration.

After startup, user is asked to press User push-button (B1).
The 8-entry array aRandom32bit[] is filled up by 32-bit long random numbers 
at each User push-button (B1) press.

 
The random numbers can be displayed on the debugger in aRandom32bit variable.

In case of error, LED3 is toggling at a frequency of 1Hz.

@par Keywords

Analog, RNG, Random, FIPS PUB 140-2, Analog Random number generator, Entropy, Period

@par Directory contents 

  - RNG/RNG_MultiRNG/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - RNG/RNG_MultiRNG/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - RNG/RNG_MultiRNG/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - RNG/RNG_MultiRNG/Inc/main.h                  Header for main.c module
  - RNG/RNG_MultiRNG/Src/stm32wlxx_it.c          Interrupt handlers
  - RNG/RNG_MultiRNG/Src/main.c                  Main program
  - RNG/RNG_MultiRNG/Src/stm32wlxx_hal_msp.c     HAL MSP module 
  - RNG/RNG_MultiRNG/Src/system_stm32wlxx.c      STM32WLxx system source file

     
@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
  
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 

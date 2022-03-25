﻿/**
  @page DAC_GenerateConstantSignal_TriggerSW_Init DAC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/DAC/DAC_GenerateConstantSignal_TriggerSW_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC_GenerateConstantSignal_TriggerSW_Init example.
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

How to use the DAC peripheral to generate a constant voltage signal. This
example is based on the STM32WLxx DAC LL API. The peripheral 
initialization uses LL unitary service functions for optimization purposes
(performance and size).

Example configuration:
One DAC channel (DAC channel1) is configured to connect DAC channel output on GPIO pin
to get the samples from SW (no DMA transfer) and to get conversion trigger from SW.

Example execution:
From the main program execution, LED2 is toggling quickly while waiting for
user button press.
Then, the DAC is configured and activated: constant signal is generated on DAC output
indefinitely.
DAC channel output value is provided by SW, a new value is loaded
at each press on push button: LED2 toggles and the signal starts from 0, increased by a quarter of Vdda and
finishing at Vdda voltage.
Finally, LED2 is turned-on.

Connection needed:
None. 
Oscilloscope for monitoring DAC channel output (cf pin below).
Other peripheral used:
  1 GPIO for push button
  1 GPIO for DAC channel output PA.10 (Arduino connector CN8 pin A2, Morpho connector CN7 pin 32)

@par Keywords

Analog, DAC, Digital to Analog, Continuous conversion,  DMA, Sine-wave generation, Software Trigger


@par Directory contents 

  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Inc/main.h                  Header for main.c module
  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Src/main.c                  Main program
  - DAC/DAC_GenerateConstantSignal_TriggerSW_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WLXX devices.
    
  - This example has been tested with STM32WL55JCIx board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

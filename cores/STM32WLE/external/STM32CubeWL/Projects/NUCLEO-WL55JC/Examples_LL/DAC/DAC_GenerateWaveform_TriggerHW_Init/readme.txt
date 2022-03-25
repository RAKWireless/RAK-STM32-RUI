﻿/**
  @page DAC_GenerateWaveform_TriggerHW_Init DAC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/DAC/DAC_GenerateWaveform_TriggerHW_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC_GenerateWaveform_TriggerHW_Init example.
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

How to use the DAC peripheral to generate a voltage waveform from a digital data
stream transferred by DMA. This example is based on the STM32WLxx 
DAC LL API. The peripheral initialization uses LL initialization
functions to demonstrate LL init usage.

Example configuration:
One DAC channel (DAC channel1) is configured to connect DAC channel output on GPIO pin
to get the samples from DMA transfer and to get conversion trigger from timer.

Other peripherals configured in this example:
one DMA channel and one timer are configured to provide samples to be generated
by DAC peripheral:
sinus waveform, frequency 1kHz, amplitude Vdda.
(these settings are configurable by changing literals values in file header).

Example execution:
From the main program execution, LED2 is toggling quickly while waiting for
user button press.
DMA and timer are configured and activated to transfer data and trig DAC conversion.
Then, the DAC is configured and activated: waveform is generated on DAC output
indefinitely.
DAC channel output value is provided by DMA transfer, a new value is loaded
at each trigger from timer.
Finally, LED2 is turned-on.

Connection needed:
None. 
Oscilloscope for monitoring DAC channel output (cf pin below).
Other peripheral used:
  1 GPIO for push button
  1 GPIO for DAC channel output PA.10 (Arduino A2 connector CN8 pin 3, Morpho connector CN7 pin 32)
  For waveform voltage generation: 1 DMA channel, 1 timer.

@par Keywords

Analog, DAC, Digital to Analog, Continuous conversion,  DMA, Sine-wave generation, External Trigger


@par Directory contents 

  - DAC/DAC_GenerateWaveform_TriggerHW_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - DAC/DAC_GenerateWaveform_TriggerHW_Init/Inc/main.h                  Header for main.c module
  - DAC/DAC_GenerateWaveform_TriggerHW_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - DAC/DAC_GenerateWaveform_TriggerHW_Init/Src/main.c                  Main program
  - DAC/DAC_GenerateWaveform_TriggerHW_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

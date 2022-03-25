/**
  @page DAC_GenerateConstantSignal_TriggerSW_LP_Init DAC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC_GenerateConstantSignal_TriggerSW_LP_Init example.
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

How to use the DAC peripheral to generate a constant voltage signal with the DAC
low-power feature sample-and-hold. To be effective, a capacitor must be
connected to the DAC channel output and the sample-and-hold timings must be
tuned depending on the capacitor value. This example is based on the
STM32WLxx DAC LL API. The peripheral initialization uses
LL unitary service functions for optimization purposes (performance and size).

Example configuration:
One DAC channel (DAC channel1) is configured to connect DAC channel output on GPIO pin
to get the samples from SW (no DMA transfer) and to get conversion trigger from SW.
DAC low power feature sample-and-hold is enabled. Mode sample-and-hold timings
are set to an arbitrary value, in a real application they should be tuned
in function of capacitor value connected to DAC output (refer to reference manual).
Low speed clock (LSI: Low Speed Internal oscillator) is required
to drive DAC in low power mode sample-and-hold.

Example execution:
From the main program execution, LED2 is toggling quickly while waiting for
user button press.
Then, the DAC is configured and activated: constant signal is generated on DAC output
indefinitely.
DAC channel output value is provided by SW, a new value is loaded
at each press on push button: start from 0, increased by a quarter of Vdda and
finishing at Vdda voltage.
Finally, LED2 is turned-on.
Caution: If a capacitor is effectively connected to DAC channel output,
         the voltage appears as pseudo continuous (with refresh and hold variations).
         But if no capacitor is connected on DAC channel output,
         the voltage appears as discontinuous (phases with voltage grounded).

Connection needed:
External capacitor:
  Mode sample-and-hold requires an external capacitor
  to be connected between DAC channel output and ground.
  Capacitor value depends on load on DAC channel output and 
  sample-and-hold timings configured.
  GENERATOR_ #error "Specify capacitor typ value and naming in datasheet for the selected STM32 series"
Oscilloscope for monitoring DAC channel output (cf pin below).
Other peripheral used:
  1 GPIO for push button
  1 GPIO for DAC channel output PA.10 (Arduino connector CN8 pin A2, Morpho connector CN7 pin 32)
  
@par Keywords

Analog, DAC, Digital to Analog, Single conversion,  Software Trigger, Sample and Hold

@par Directory contents 

  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Inc/main.h                  Header for main.c module
  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Src/main.c                  Main program
  - DAC/DAC_GenerateConstantSignal_TriggerSW_LP_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


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

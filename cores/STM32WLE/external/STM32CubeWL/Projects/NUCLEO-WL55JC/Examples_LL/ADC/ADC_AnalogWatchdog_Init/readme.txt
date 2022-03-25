﻿/**
  @page ADC_AnalogWatchdog_Init ADC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/ADC/ADC_AnalogWatchdog_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC_AnalogWatchdog_Init example.
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

How to use an ADC peripheral with an ADC analog watchdog to monitor a channel 
and detect when the corresponding conversion data is outside the window 
thresholds.
This example is based on the STM32WLxx ADC LL API.
The peripheral initialization is done using LL unitary service functions
for optimization purposes (performance and size).

Example configuration:
ADC is configured to convert a single channel, in continuous conversion mode,
from SW trigger.
Analog watchdog is configured to monitor all channels on group regular
(therefore, including the selected channel), 
low threshold is set to 0V and high threshold is set to Vdda/2.
ADC interruption enabled: Analog watchdog 1.

Example execution:
From the main program execution, the ADC converts the selected channel continuously.
When conversion data is out of analog watchdog window, ADC interruption occurs.
Into analog watchdog callback function, a status variable is set
and LED2 is updated.
LED2 state:
 - LED remains turned-off if voltage is within AWD window (analog watchdog not triggered)
 - LED turned-on if voltage is out of AWD window
At each press on User push-button (B1), the ADC analog watchdog is rearmed to be ready
for another trig.

LED2 is blinking every 1 sec in case of error.

Note: In case of noise on voltage applied on ADC channel input (due to connectors and wires parasitics),
      ADC analog watchdog may trig at a voltage level with an uncertainty of tens of mV.

For debug: variables to monitor with debugger watch window:
 - "ubAnalogWatchdog1Status": analog watchdog state

Connection needed: use an external power supply, adjust supply voltage and connect 
it to analog input pin (cf pin below).

Other peripherals used:
  1 GPIO for User push-button (B1)
  1 GPIO for LED2
  1 GPIO for analog input: PB.02 (Arduino connector CN8 pin A1, Morpho connector CN7 pin 30)

@par Keywords

ADC, analog digital converter, analog, conversion, voltage, channel, analog input, trigger, analog watchdog, threshold, window

@par Directory contents 

  - ADC/ADC_AnalogWatchdog_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - ADC/ADC_AnalogWatchdog_Init/Inc/main.h                  Header for main.c module
  - ADC/ADC_AnalogWatchdog_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - ADC/ADC_AnalogWatchdog_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - ADC/ADC_AnalogWatchdog_Init/Src/main.c                  Main program
  - ADC/ADC_AnalogWatchdog_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


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

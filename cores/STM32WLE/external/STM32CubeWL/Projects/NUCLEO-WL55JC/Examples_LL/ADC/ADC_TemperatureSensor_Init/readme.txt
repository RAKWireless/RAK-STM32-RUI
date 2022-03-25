/**
  @page ADC_TemperatureSensor_Init ADC example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/ADC/ADC_TemperatureSensor_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC_TemperatureSensor_Init example.
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

How to use an ADC peripheral to perform a single ADC conversion on the 
internal temperature sensor and calculate the temperature in degrees Celsius. 
This example uses the polling programming model (for interrupt or DMA 
programming models, refer to other examples).

This example is based on the STM32WLxx ADC LL API.
The peripheral initialization is done using LL unitary service functions
for optimization purposes (performance and size).

Example configuration:
ADC is configured to convert a single channel, in single conversion mode,
from SW trigger.
Sequencer of group regular (default group available on ADC of all STM32 devices)
is configured to convert 1 channel: internal channel temperature sensor.

Example execution:
Program configures ADC and GPIO.
Then, program performs in infinite loop:
- start ADC conversion
- polls for conversion completion
- read conversion data
- compute temperature from raw data to physical values using LL ADC driver helper macro (unit: degree Celsius)
- turn-on LED2 during 0.5 sec

For debug: variables to monitor with debugger watch window:
- "uhADCxConvertedData": ADC group regular conversion data
- "hADCxConvertedData_Temperature_DegreeCelsius": Value of temperature (unit: degree Celsius)

In case of error, LED2 is blinking every 1 sec 

Connection needed:
None.

Other peripherals used:
  1 GPIO for LED2

@par Keywords

ADC, analog digital converter, analog, conversion, voltage, channel, analog input, trigger, temperature sensor

@par Directory contents 

  - ADC/ADC_TemperatureSensor_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - ADC/ADC_TemperatureSensor_Init/Inc/main.h                  Header for main.c module
  - ADC/ADC_TemperatureSensor_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - ADC/ADC_TemperatureSensor_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - ADC/ADC_TemperatureSensor_Init/Src/main.c                  Main program
  - ADC/ADC_TemperatureSensor_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


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

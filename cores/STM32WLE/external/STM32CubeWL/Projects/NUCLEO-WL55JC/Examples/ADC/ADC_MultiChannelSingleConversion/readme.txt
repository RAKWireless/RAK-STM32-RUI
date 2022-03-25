/**
  @page ADC_MultiChannelSingleConversion ADC example

  @verbatim
  ******************************************************************************
  * @file    Examples/ADC/ADC_MultiChannelSingleConversion/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC_MultiChannelSingleConversion example.
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
Use ADC to convert a several channels using sequencer in discontinuous mode, 
conversion data are transferred by DMA into an array, indefinitely (circular mode).

Example configuration:
The channels converted are one external channel and two internal 
channels (VrefInt and temperature sensors), in sequence conversion mode,
one by one from SW trigger.
DMA is configured to transfer conversion data in an array, in circular mode.

Example execution:
From the start, the ADC converts the selected channels in sequence, one by one
(discontinuous mode) at each trig from User push-button (B1) click.
DMA transfers conversion data to the array, DMA transfer complete interruption occurs.
Results array is updated indefinitely (DMA in circular mode).
LED2 is turned on when the DMA transfer is completed (results array full)
and turned off at next DMA half-transfer (result array first half updated).
When the ADC sequence is complete (the three ADC conversions are carried out), 
the voltages and temperature are computed and stored in variables:
    uhADCxConvertedData_VoltageGPIO_mVolt
    uhADCxConvertedData_VrefInt_mVolt
    hADCxConvertedData_Temperature_DegreeCelsius
    uhADCxConvertedData_VrefAnalog_mVolt
	
Note: If DMA buffer is full when user click on User push-button (B1), the buffer is reset
(to ease user observe behavior).

For debug: variables to monitor with debugger watch window:
 - "aADCxConvertedData": ADC group regular conversion data (array of data)

Connection needed:
None.
Note: Optionally, a voltage can be supplied to the analog input pin (cf pin below),
      between 0V and Vdda=3.3V, to perform a ADC conversion on a determined
      voltage level.
      Otherwise, this pin can be let floating (in this case ADC conversion data
      will be undetermined).

Other peripherals used:
  1 GPIO for LED
  1 GPIO for analog input: PB2 (Arduino connector CN8 pin A1, Morpho connector CN7 pin 30)
  1 GPIO for push button
  DMA

Board settings:
 - ADC is configured to convert one external channel ADC_CHANNEL_4
   (Arduino connector CN8 pin A1, Morpho connector CN7 pin 30) and the two internal ones ADC_CHANNEL_VREFINT,
   ADC_CHANNEL_TEMPSENSOR.
 - The voltage input on the ADC external channel can be provided by an external source
   connected to Arduino connector CN8 pin A1, Morpho connector CN7 pin 30.



NUCLEO-WL55JC RevC board LED is be used to monitor the program execution status:
 - Normal operation: LED2 is turned-on/off in function of ADC conversion
   result.
    - Toggling: "On" upon conversion completion (full DMA buffer filled)
                "Off" upon half conversion completion (half DMA buffer filled)
 - Error: In case of error, LED2 is toggling twice at a frequency of 1Hz.

@par Keywords

ADC, analog digital converter, analog, conversion, voltage, channel, analog input, sequencer, temperature sensor, VrefInt

@par Directory contents 

  - ADC/ADC_MultiChannelSingleConversion/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - ADC/ADC_MultiChannelSingleConversion/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - ADC/ADC_MultiChannelSingleConversion/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - ADC/ADC_MultiChannelSingleConversion/Inc/main.h                        Header for main.c module  
  - ADC/ADC_MultiChannelSingleConversion/Inc/stm32wlxx_conf.h        HAL configuration file
  - ADC/ADC_MultiChannelSingleConversion/Src/stm32wlxx_it.c          Interrupt handlers
  - ADC/ADC_MultiChannelSingleConversion/Src/stm32wlxx_hal_msp.c     HAL MSP module
  - ADC/ADC_MultiChannelSingleConversion/Src/main.c                        Main program
  - ADC/ADC_MultiChannelSingleConversion/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WLXX devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

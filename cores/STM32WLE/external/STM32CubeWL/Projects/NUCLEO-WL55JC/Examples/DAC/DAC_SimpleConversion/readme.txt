/**
  @page DAC_SimpleConversion DAC Simple Conversion example
  
  @verbatim
  ******************************************************************************
  * @file    DAC/DAC_SimpleConversion/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC Simple Conversion example.
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

How to use the DAC peripheral to do a simple conversion.

      - The example uses the DAC for a simple conversion in 8 bits right 
      	alignment of 0xFF value, the result of conversion can be seen by 
      	connecting PA10(DAC channel1) to an oscilloscope. 
      	The observed value is 3.3V.
      - The low power mode of DAC (sample and hold mode) can also be used while Cortex 
        is in sleep mode.
      - The tests steps are:
      - Step 0:
      	DAC:     normal power mode
      	Cortex:  run mode
      - Step 1:
      	DAC:     Low power mode
      	Cortex:  Sleep mode
      

NUCLEO-WL55JC RevC board's LEDs can be used to monitor the process status:
  - LED3 is ON and example is stopped (using infinite loop)
  when there is an error during process.

@par Keywords

Analog, DAC, Digital to Analog, Single conversion, Sample and Hold

@par Directory contents 

  - DAC/DAC_SimpleConversion/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - DAC/DAC_Simple_Conversion/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - DAC/DAC_Simple_Conversion/Inc/stm32wlxx_it.h          DMA interrupt handlers header file
  - DAC/DAC_Simple_Conversion/Inc/main.h                  Header for main.c module  
  - DAC/DAC_Simple_Conversion/Src/stm32wlxx_it.c          DMA interrupt handlers
  - DAC/DAC_Simple_Conversion/Src/main.c                  Main program
  - DAC/DAC_Simple_Conversion/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - DAC/DAC_Simple_Conversion/Src/system_stm32wlxx.c      STM32WLxx system source file
  

@par Hardware and Software environment  
  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up 	
    
      - Connect PA10 (DAC Channel1) (pin 32 in CN7) to an oscilloscope.
      - Press user button to switch between steps.
      - You may redo the tests by changing the sample and hold parameters 
        of the DAC.          
      

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */


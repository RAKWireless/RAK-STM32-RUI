/**
  @page TIM_DMA TIM DMA example
  
  @verbatim
  ******************************************************************************
  * @file    TIM/TIM_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM DMA example.
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

Use of the DMA with TIMER Update request 
to transfer data from memory to TIMER Capture Compare Register 3 (TIMx_CCR3).

  The following configuration values are used in this example:

    - TIM1CLK = SystemCoreClock
    - Counter repetition = 3 
    - Prescaler = 0 
    - TIM1 counter clock = SystemCoreClock
    - SystemCoreClock is set to 48 MHz for STM32WLxx

  The objective is to configure TIM1 channel 3 to generate complementary PWM 
  (Pulse Width Modulation) signal with a frequency equal to 17.57 KHz, and a variable 
  duty cycle that is changed by the DMA after a specific number of Update DMA request.

  The number of this repetitive requests is defined by the TIM1 Repetition counter,
  each 4 Update Requests, the TIM1 Channel 3 Duty Cycle changes to the next new 
  value defined by the aCCValue_Buffer.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32WL55JCIx Devices :
The CPU at 48 MHz  

  The PWM waveform can be displayed using an oscilloscope.
 
  In nominal mode (except at start) , it should looks like this :
    
       .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   
        ___________     _______         ___             ___________    __
      _|           |___|       |_______|   |___________|           |__|             
       <----57us -----><----57us -----><----57us -----><----57us ----->

	   
@note PWM signal frequency value mentioned above is theoretical (obtained when the system clock frequency 
      is exactly 48 MHz). Since the generated system clock frequency may vary from one board to another observed
      PWM signal frequency might be slightly different.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)

@note This example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

	  
@par Keywords

Timer, DMA, PWM, Frequency, Duty Cycle, Waveform, Oscilloscope, Output, Signal

@par Directory contents

  - TIM/TIM_DMA/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - TIM/TIM_DMA/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - TIM/TIM_DMA/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_DMA/Inc/main.h                  Header for main.c module  
  - TIM/TIM_DMA/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_DMA/Src/main.c                  Main program
  - TIM/TIM_DMA/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - TIM/TIM_DMA/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
  - In this example, the clock is set to 48 MHz.
    
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC 
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect the TIM1 pin to an oscilloscope to monitor the different waveforms: 
    - TIM1 CH3 (PA.10 (pin 32 in CN7 connector))

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

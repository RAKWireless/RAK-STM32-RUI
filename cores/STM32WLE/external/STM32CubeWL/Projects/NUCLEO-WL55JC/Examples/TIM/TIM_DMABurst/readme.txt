/**
  @page TIM_DMABurst TIM_DMABurst example
  
  @verbatim
  ******************************************************************************
  * @file    TIM/TIM_DMABurst/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM DMA Burst example.
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

How to update the TIMER channel 1 period and duty cycle using the TIMER DMA burst feature.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32WL55JCIx Devices :
The CPU at 48 MHz 
Every update DMA request, the DMA will do 3 transfers of half words into Timer 
registers beginning from ARR register.
On the DMA update request, 0x0FFF will be transferred into ARR, 0x0000 
will be transferred into RCR (if supported), 0x0555 will be transferred into CCR1. 

The TIM2CLK frequency is set to SystemCoreClock, to get TIM2 counter
clock at 8 MHz the Prescaler is computed as following:
- Prescaler = (TIM2CLK / TIM2 counter clock) - 1

SystemCoreClock is set to 48 MHz.

The TIM2 Frequency = TIM2 counter clock/(ARR + 1)
                   = 8 MHz / 4096 = 1.95 KHz

The TIM2 CCR1 register value is equal to 0x555, so the TIM2 Channel 1 generates a 
PWM signal with a frequency equal to 1.95 KHz and a duty cycle equal to 33.33%:
TIM2 Channel1 duty cycle = (TIM2_CCR1/ TIM2_ARR + 1)* 100 = 33.33%

The PWM waveform can be displayed using an oscilloscope.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then 
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note This example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

LED3 is ON when there are an error.

@par Keywords

Timer, DMA, Burst mode, Duty Cycle, Waveform, Oscilloscope, Output, Signal, PWM

@par Directory contents

  - TIM/TIM_DMABurst/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - TIM/TIM_DMABurst/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - TIM/TIM_DMABurst/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_DMABurst/Inc/main.h                  Header for main.c module  
  - TIM/TIM_DMABurst/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_DMABurst/Src/main.c                  Main program
  - TIM/TIM_DMABurst/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - TIM/TIM_DMABurst/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
  - In this example, the clock is set to 48 MHz.
    
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC 
    board and can be easily tailored to any other supported device 
    and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect the TIM2 output channel to an oscilloscope to monitor the different waveforms: 
    - TIM2 CH1 (PA.15 (pin 17 in CN7))

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

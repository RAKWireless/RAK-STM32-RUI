/**
  @page TIM_PWMOutput TIM PWM Output example
  
  @verbatim
  ******************************************************************************
  * @file    TIM/TIM_PWMOutput/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the PWM signals generation using TIM1
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

This example shows how to configure the TIM peripheral in PWM (Pulse Width Modulation) 
mode.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32WL55JCIx Devices :
The CPU at 48 MHz 

SystemCoreClock is set to 48 MHz for STM32WLxx Devices.

    In this example TIM1 input clock (TIM1CLK) is set to APB1 clock (PCLK1),
    since APB1 prescaler is equal to 1.
      TIM1CLK = PCLK1
      PCLK1 = HCLK
      => TIM1CLK = HCLK = SystemCoreClock

    To get TIM1 counter clock at 1 MHz, the prescaler is computed as follows:
       Prescaler = (TIM1CLK / TIM1 counter clock) - 1
       Prescaler = ((SystemCoreClock) /1 MHz) - 1

    To get TIM1 output clock at 25 KHz, the period (ARR)) is computed as follows:
       ARR = (TIM1 counter clock / TIM1 output clock) - 1
           = 39

    TIM1 Channel1 duty cycle = (TIM1_CCR1/ TIM1_ARR + 1)* 100 = 50%
    TIM1 Channel2 duty cycle = (TIM1_CCR2/ TIM1_ARR + 1)* 100 = 37.5%
    TIM1 Channel3 duty cycle = (TIM1_CCR3/ TIM1_ARR + 1)* 100 = 25%
    TIM1 Channel4 duty cycle = (TIM1_CCR4/ TIM1_ARR + 1)* 100 = 12.5%

LED3 is ON when there are an error.

The PWM waveforms can be displayed using an oscilloscope.

@note The duty cycles values mentioned above are theoretical (obtained when the system clock frequency is exactly 48 MHz).
      They might be slightly different depending on system clock frequency precision.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note This example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
	  

@par Keywords

Timer, Output, signal, PWM, Oscilloscope, Frequency, Duty cycle, Waveform

@par Directory contents

  - TIM/TIM_PWMOutput/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - TIM/TIM_PWMOutput/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - TIM/TIM_PWMOutput/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_PWMOutput/Inc/main.h                  Header for main.c module  
  - TIM/TIM_PWMOutput/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_PWMOutput/Src/main.c                  Main program
  - TIM/TIM_PWMOutput/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - TIM/TIM_PWMOutput/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
  - In this example, the clock is set to 48 MHz.
    
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC 
    board and can be easily tailored to any other supported device 
    and development board.      

  - NUCLEO-WL55JC RevC Set-up
   Connect the following pins to an oscilloscope to monitor the different waveforms:
        - TIM1_CH1 : PA.08 (pin 16 in CN10 connector)
        - TIM1_CH2 : PA.09 (pin 19 in CN10 connector)
        - TIM1_CH3 : PA.10 (pin 32 in CN7 connector)
        - TIM1_CH4 : PA.11 (pin 5 in CN10 connector)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

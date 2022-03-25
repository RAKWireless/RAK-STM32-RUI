/**
  @page TIM_InputCapture_Init TIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/TIM/TIM_InputCapture_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM_InputCapture_Init example.
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

Use of the TIM peripheral to measure a periodic signal frequency 
provided either by an external signal generator or by 
another timer instance. This example is based on the STM32WLxx TIM 
LL API. The peripheral initialization uses LL unitary service functions 
for optimization purposes (performance and size).
  
TIM1_CH1 is configured in input capture mode. The TIM1CLK frequency is set to 
its maximum value (Prescaler is /2 * 2 = 1) in order to get the best possible resolution.
So the TIM1 counter clock is SystemCoreClock.

SystemCoreClock is set to 48 MHz for STM32WLxx Devices.

The "uwMeasuredFrequency" variable contains the measured signal frequency.
It is calculated within the capture/compare 1 interrupt service routine.

The minimum frequency value to measure is TIM1 counter clock / TIMx_CCR1 MAX
                                              = 48 MHz / 65535

Due to TIM1 interrupt routine processing time (around 4.75us), the maximum
frequency value to measure is around 210 kHz.

TIM2_CH1 is configured to generate a PWM signal.  User push-button (B1) can be used to
change the frequency of this signal from 2 kHz up to 20 kHz by steps of 2 kHz.
It is then possible to run this example without a signal generator by connecting
TIM2_CH1 to TIM1_CH1.

@par Keywords

Timers, Frequency, Input, Capture, External Signal, Measurement

@par Directory contents 

  - TIM/TIM_InputCapture_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_InputCapture_Init/Inc/main.h                  Header for main.c module
  - TIM/TIM_InputCapture_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - TIM/TIM_InputCapture_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_InputCapture_Init/Src/main.c                  Main program
  - TIM/TIM_InputCapture_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - When no signal generator is used TIM2_CH1 can be connected to TIM1_CH1:
      - TIM1_CH1  PA8: connected to pin 16 of CN10 connector  
      - TIM2_CH1  PA5: connected to pin 11 of CN10 connector 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

/**
  @page TIM_BreakAndDeadtime_Init TIM example

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/TIM/TIM_BreakAndDeadtime_Init/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the TIM_BreakAndDeadtime_Init example.
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

Configuration of the TIM peripheral to
 generate three center-aligned PWM and complementary PWM signals,
 insert a defined deadtime value,
 use the break feature,
 and lock the break and dead-time configuration.
This example is based on the STM32WLxx TIM LL API. The peripheral initialization
uses LL initialization function to demonstrate LL Init.

TIM1CLK is fixed to 48 MHz, the TIM1 Prescaler is set to have
TIM1 counter clock = 10 MHz.

The TIM1 auto-reload is set to generate PWM signal at 100 Hz:

The Three Duty cycles are computed as the following description:
The channel 1 duty cycle is set to 50% so channel 1N is set to 50%.
The channel 2 duty cycle is set to 25% so channel 2N is set to 75%.
The channel 3 duty cycle is set to 12.5% so channel 3N is set to 87.5%.

A dead time equal to 4 us is inserted between
the different complementary signals, and the Lock level 1 is selected.
  - The OCx output signal is the same as the reference signal except for the rising edge,
    which is delayed relative to the reference rising edge.
  - The OCxN output signal is the opposite of the reference signal except for the rising
    edge, which is delayed relative to the reference falling edge

Note that calculated duty cycles apply to the reference signal (OCxREF) from
which outputs OCx and OCxN are generated. As dead time insertion is enabled the
duty cycle measured on OCx will be slightly lower.

The break Polarity is used at High level.

The TIM1 waveforms can be displayed using an oscilloscope.

@par Keywords

Timer, TIM, PWM, Signal, Duty cycle, Dead-time, Break-time, Break polarity, Oscilloscope.

@par Directory contents

  - TIM/TIM_BreakAndDeadtime_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_BreakAndDeadtime_Init/Inc/main.h                  Header for main.c module
  - TIM/TIM_BreakAndDeadtime_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - TIM/TIM_BreakAndDeadtime_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_BreakAndDeadtime_Init/Src/main.c                  Main program
  - TIM/TIM_BreakAndDeadtime_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect the TIM1 pins to an oscilloscope to monitor the different waveforms:
      - TIM1_CH1  PA8: connected to pin 16 of CN10 connector
      - TIM1_CH1N PA7: connected to pin 15 of CN10 connector
      - TIM1_CH2  PA9: connected to pin 19 of CN10 connector
      - TIM1_CH2N PB8: connected to pin 27 of CN10 connector
      - TIM1_CH3  PA10: connected to pin 32 of CN7 connector
      - TIM1_CH3N PB9: connected to pin 26 of CN10 connector

    - Connect the TIM1 break to the GND. To generate a break event, switch this
      pin level from 0V to 3.3V.
      - TIM1_BKIN  PA6: connected to pin 13 of CN10 connector

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

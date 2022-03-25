/**
  @page LPTIM_PulseCounter_Init LPTIM example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/LPTIM/LPTIM_PulseCounter_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPTIM_PulseCounter_Init example.
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

How to use the LPTIM peripheral in counter mode to generate a PWM output signal 
and update its duty cycle. This example is based on the STM32WLxx
LPTIM LL API. The peripheral is initialized with LL initialization 
function to demonstrate LL init usage.

To reduce power consumption, MCU enters stop mode after starting counting. Each
time the counter reaches the maximum value (Period/Autoreload), an interruption
is generated, the MCU is woken up from stop mode and LED2 toggles the last state.

In this example Period value is set to 1000, so each time the counter counts
(1000 + 1) rising edges on LPTIM1_IN1 pin, an interrupt is generated and LED2
toggles. If the external function generator is set to provide a square waveform at 1Khz,
the led will toggle each second.

In this example the internal clock provided to the LPTIM1 is LSI (32 kHz),
so the external input is sampled with LSI clock. In order not to miss any event,
the frequency of the changes on the external Input1 signal should never exceed the
frequency of the internal clock provided to the LPTIM1 (LSI for the
present example).

  #error "Define whether multicore is available on the selected STM32 series"

@par Keywords

Timer, Low Power, Pulse Counter, Stop mode, Interrupt

@par Directory contents 

  - LPTIM/LPTIM_PulseCounter_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - LPTIM/LPTIM_PulseCounter_Init/Inc/main.h                  Header for main.c module
  - LPTIM/LPTIM_PulseCounter_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - LPTIM/LPTIM_PulseCounter_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - LPTIM/LPTIM_PulseCounter_Init/Src/main.c                  Main program
  - LPTIM/LPTIM_PulseCounter_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.
    
  - Connect a square waveform generator to PC0 (pin 14 in CN10 connector).
    If the frequency of the signal is 1 kHz, LED2 toggles every second.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

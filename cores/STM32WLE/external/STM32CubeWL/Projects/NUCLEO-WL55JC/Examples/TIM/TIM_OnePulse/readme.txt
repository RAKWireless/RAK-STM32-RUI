/**
  @page TIM_OnePulse TIM One Pulse example
  
  @verbatim
  ******************************************************************************
  * @file    TIM/TIM_OnePulse/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM One Pulse example.      
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

This example shows how to use the TIMER peripheral to generate a single pulse when
a rising edge of an external signal is received on the TIMER Input pin.

At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32WL55JCIx Devices :
The CPU at 48 MHz 

Clock setup for TIM1
================================

  TIM1CLK = SystemCoreClock = 48 MHz.
  
  Prescaler = (TIM1CLK /TIM1 counter clock) - 1
  
  The prescaler value is computed in order to have TIM1 counter clock 
  set at 1000000 Hz.
  
  The Autoreload value is 65535 (TIM1->ARR), so the maximum frequency value to 
  trigger the TIM1 input is 1000000/65535 [Hz].
 
Configuration of TIM1 in One Pulse Mode
===================================================
 
  - The external signal is connected to TIM1_CH2 pin (PA9), 
    and a rising edge on this input is used to trigger the Timer.
  - The One Pulse signal is output on TIM1_CH1 (PA8).

  The delay value is fixed to:
   - Delay =  CCR1/TIM1 counter clock 
           = 16383 / 1000000 [sec]
           
  The pulse value is fixed to : 
   - Pulse value = (TIM_Period - TIM_Pulse)/TIM1 counter clock  
                 = (65535 - 16383) / 1000000 [sec]

  The one pulse waveform can be displayed using an oscilloscope and it looks
  like this.
LED3 is ON when there are an error.
  
                                ___
                               |   |
  CH2 _________________________|   |__________________________________________
 
                                             ___________________________
                                            |                           |
  CH1 ______________________________________|                           |_____
                               <---Delay----><------Pulse--------------->
@note The delay and pulse values mentioned above are theoretical (obtained when the system clock frequency is exactly 48 MHz).
      They might be slightly different depending on system clock frequency precision.

@par Keywords

Timer, Output, signals, One Pulse, PWM, Oscilloscope, External signal, Autoreload, Waveform

@par Directory contents

  - TIM/TIM_OnePulse/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - TIM/TIM_OnePulse/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - TIM/TIM_OnePulse/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - TIM/TIM_OnePulse/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OnePulse/Src/stm32wlxx_it.c          Interrupt handlers
  - TIM/TIM_OnePulse/Src/main.c                  Main program
  - TIM/TIM_OnePulse/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - TIM/TIM_OnePulse/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

   - This example runs on STM32WL55JCIx devices.
   - In this example, the clock is set to 48 MHz.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
   - Connect the external signal to the TIM1_CH2 pin (PA9) (pin 19 in CN10 connector)
   - Connect the TIM1_CH1 pin(PA8) (pin 16 in CN10 connector) to an oscilloscope to monitor the waveform.  


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files: Project->Rebuild all
 - Load project image: Project->Download and Debug
 - Run program: Debug->Go(F5) 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

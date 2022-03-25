/**
  @page GPIO_IOToggle GPIO IO Toggle example
  
  @verbatim
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the GPIO IO Toggle example.
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

How to configure and use GPIOs through the HAL API.

PB.09 and PB.15 IOs (configured in output pushpull mode) toggle in a forever loop.
On NUCLEO-WL55JC RevC board these IOs are connected to LED2 and LED1.

In this example, HCLK is configured at 48 MHz.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The example needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, GPIO, Input, Output, Alternate function, Push-pull, Toggle

@par Directory contents 

  - GPIO/GPIO_IOToggle/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - GPIO/GPIO_IOToggle/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - GPIO/GPIO_IOToggle/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - GPIO/GPIO_IOToggle/Inc/main.h                  Header for main.c module  
  - GPIO/GPIO_IOToggle/Src/stm32wlxx_it.c          Interrupt handlers
  - GPIO/GPIO_IOToggle/Src/stm32wlxx_hal_msp.c     HAL MSP file
  - GPIO/GPIO_IOToggle/Src/main.c                  Main program
  - GPIO/GPIO_IOToggle/Src/system_stm32wlxx.c      STM32WLxx system source file


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

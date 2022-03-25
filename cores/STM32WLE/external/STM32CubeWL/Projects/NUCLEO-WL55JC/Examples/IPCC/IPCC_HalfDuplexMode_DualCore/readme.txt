/**
  @page IPCC_HalfDuplexMode_DualCore IPCC Half Duplex Mode example

  @verbatim
  ******************************************************************************
  * @file    IPCC/IPCC_HalfDuplexMode_DualCore/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the IPCC Half Duplex Mode example.
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

How to transfer data between two processors using IPCC Half Duplex channel mode.

This example demonstrate the usage of the half duplex channel mode of IPCC as
described inside STM32WL5x reference manual (RM0453).

The half duplex mode is used in the case where one processor send communication data
followed by the other processor sending a response to each communication (ping - pong).

In half duplex channel mode, a dedicated memory location is assigned to the
communication in both direction. This is demonstrated using 16 char from 
0x2000FFF0 to 0x2000FFFF. This information is stored inside the 
__IO char *sharedBuffer. This shared buffer must be located inside the shared memory.

Only one channel is used by both processors (channel 0 is used by default and
this setting can be adapted by changing the value of ChannelId variable. This
value must be the same on both processor).

This example must be executed on the two processors of the STM32WLxx simultaneously.
Preliminary step: Flash memory must be loaded with CPU1 and CPU2 programs.
Procedure using IDE:
  1. Compile and flash the environment IPCC_HalfDuplex_CM4 on processor 1 side, then execute it (it will perform CPU2 boot)
  2. Compile and flash the environment IPCC_HalfDuplex_CM0PLUS on processor 2 side
  3. Perform a system reset (or SW reset of CPU2 program only)

Inside the IPCC_HalfDuplex_CM4 environment, processor 1:
  - Initialize the clock sources, the LEDs.
  - Start the processor 2.
  - Enable the IPCC notification on remote processor sending message.
  - For 1000 transactions,
    - Send a string containing the index of the ongoing transaction to remote processor.
    - Wait for the reception of the message from the remote processor.
    - Retrieve the content of the message from remote processor.
  - Disable the IPCC notification.

Inside the IPCC_HalfDuplex_CM0PLUS environment, processor 2:
  - Enable the IPCC notification on remote processor sending message.
  - Forever,
    - Wait for the reception of the message from the remote processor.
    - Retrieve the content of the message from remote processor.
    - Write the response in memory.
    - Send the response to remote processor.

This behavior is illustrated using LEDs.
  - LED_BLUE is associated to processor 1
  - LED_GREEN is associated to processor 2
  - LED_RED is associated to any error on both processor

  LED_BLUE and LED_GREEN must be blinking (each 100 transactions) for some seconds to illustrate the transaction between the 2 processors.
  Once 1000 transactions are done LED_BLUE and LED_GREEN are ON.

  If any error is encountered, the LED_RED is turned ON.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.
      
@par Keywords

System, IPCC, Half duplex, Dual core, Data transfer synchronisation

@par Directory contents

  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Src/main.c                  Main program
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Src/stm32wlxx_hal_msp.c     HAL MSP module
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Src/stm32wlxx_it.c          Interrupt handlers
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Inc/main.h                  Main program header file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Inc/stm32wlxx_hal_conf.h    HAL Configuration file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM0PLUS/Inc/stm32wlxx_nucleo_conf.h BSP Driver Configuration file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Src/main.c                      Main program
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Src/stm32wlxx_hal_msp.c         HAL MSP module
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Src/stm32wlxx_it.c              Interrupt handlers
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Inc/main.h                      Main program header file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Inc/stm32wlxx_hal_conf.h        HAL Configuration file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Inc/stm32wlxx_it.h              Interrupt handlers header file
  - IPCC/IPCC_HalfDuplexMode_DualCore/CM4/Inc/stm32wlxx_nucleo_conf.h     BSP Driver Configuration file
  - IPCC/IPCC_HalfDuplexMode_DualCore/Common/system_stm32wlxx.c           STM32WLxx system clock configuration file

@par Hardware and Software environment

  - This example runs on STM32WL55JCxx devices.

  - This example has been tested with STMicroelectronics NUCLEO-WL55JC
    boards and can be easily tailored to any other supported device
    and development board.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Load CPU1 test program, then execute it (it will perform CPU2 boot)
 - Load CPU2 test program
 - Perform a system reset (or SW reset of CPU2 program only)
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

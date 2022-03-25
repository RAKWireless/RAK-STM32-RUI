/**
  @page DMA_CopyFromFlashToMemory_Init DMA example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/DMA/DMA_CopyFromFlashToMemory_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DMA example.
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

How to use a DMA channel to transfer a word data buffer
from Flash memory to embedded SRAM. The peripheral initialization uses LL
initialization functions to demonstrate LL init usage.

At the beginning of the main program the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 48 MHz.

Then the LED_Init() function is used to initialize the LED2.

Then the Configure_DMA() function is used to configure the DMA1_Channel1 to transfer the contents of a 32-word data
buffer stored in Flash memory to the reception buffer declared in RAM.

The start of transfer is triggered by software(LL_DMA_EnableChannel()). DMA1_Channel1 memory-to-memory
transfer is enabled. Source and destination addresses incrementing is also enabled.
The transfer is started by setting the channel enable bit for DMA1_Channel1.
At the end of the transfer a Transfer Complete interrupt is generated since it
is enabled and the callback function (customized by user) is called.

Finally, aSRC_Const_Buffer and aDST_Buffer are compared through Buffercmp() in order to 
check buffers correctness.  

NUCLEO-WL55JC RevC's LED2 can be used to monitor the transfer status:
- LED2 is turned ON if the DMA data transfer is successfully completed.
- LED2 is blinking every 1 sec in case of error.

@par Keywords

System, DMA, Data Transfer, Memory to memory, Flash, SRAM


@par Directory contents 

  - DMA/DMA_CopyFromFlashToMemory_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - DMA/DMA_CopyFromFlashToMemory_Init/Inc/main.h                  Header for main.c module  
  - DMA/DMA_CopyFromFlashToMemory_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - DMA/DMA_CopyFromFlashToMemory_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - DMA/DMA_CopyFromFlashToMemory_Init/Src/main.c                  Main program
  - DMA/DMA_CopyFromFlashToMemory_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

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

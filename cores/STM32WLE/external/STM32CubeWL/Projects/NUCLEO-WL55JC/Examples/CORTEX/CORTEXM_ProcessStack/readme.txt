/**
  @page CORTEXM_ProcessStack Cortex-M4 Process Stack example

  @verbatim
  ******************************************************************************
  * @file    CORTEX/CORTEXM_ProcessStack/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the Cortex-M4 Mode Privilege example.
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

How to modify the Thread mode stack. Thread mode is entered on reset, and can be
entered as a result of an exception return.  

The associated program is used to:

1. Switch the Thread mode stack from Main stack to Process stack

2. Generate ISR (SVC) to confirm Stack pointer used under exception is Main Stack

3. Returning to main(), check is performed on current Stack to show cortex has switched back to Process
automatically.
In case of error, LED3 remains off. In case of success, LED2 is turned on.

To monitor the stack used a set of variables is available within the program. It is also
possible to use the 'Cortex register' window of the debugger.
 
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, Cortex, Process Stack, HCLK, Thread mode Stack, main stack, process stack, ISR, 

@par Directory contents 

  - CORTEX/CORTEXM_ProcessStack/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - CORTEX/CORTEXM_ProcessStack/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - CORTEX/CORTEXM_ProcessStack/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - CORTEX/CORTEXM_ProcessStack/Inc/main.h                  Header for main.c module
  - CORTEX/CORTEXM_ProcessStack/Src/stm32wlxx_it.c          Interrupt handlers
  - CORTEX/CORTEXM_ProcessStack/Src//stm32wlxx_hal_msp.c     HAL MSP file
  - CORTEX/CORTEXM_ProcessStack/Src/main.c                  Main program
  - CORTEX/CORTEXM_ProcessStack/Src/system_stm32wlxx.c      STM32WLxx system source file

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

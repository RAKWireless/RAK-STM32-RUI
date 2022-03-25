    /**
  @page CORTEXM_MPU Cortex-M4 MPU example

  @verbatim
  ******************************************************************************
  * @file    CORTEX/CORTEXM_MPU/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the CortexM MPU example.
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

Presentation of the MPU feature. This example configures a memory area as 
privileged read-only, and attempts to perform read and write operations in
different modes.

If the access is permitted LED2 is toggling. If the access is not permitted, 
a memory management fault is generated and LED3 is ON.

To generate an MPU memory fault exception due to an access right error, uncomment
the following line "PrivilegedReadOnlyArray[0] = 'e';" in the "stm32_mpu.c" file.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, Cortex, Memory regions, Privileged area, permitted access, memory management fault, MPU memory fault

@par Directory contents 

  - CORTEX/CORTEXM_MPU/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - CORTEX/CORTEXM_MPU/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - CORTEX/CORTEXM_MPU/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - CORTEX/CORTEXM_MPU/Inc/main.h                  Header for main.c module
  - CORTEX/CORTEXM_MPU/Inc/stm32_mpu.h             MPU management
  - CORTEX/CORTEXM_MPU/Src/stm32wlxx_it.c          Interrupt handlers
  - CORTEX/CORTEXM_MPU/Src//stm32wlxx_hal_msp.c     HAL MSP file
  - CORTEX/CORTEXM_MPU/Src/main.c                  Main program
  - CORTEX/CORTEXM_MPU/Src/system_stm32wlxx.c      stm32wlxx system source file
  - CORTEX/CORTEXM_MPU/Src/stm32_mpu.c             MPU management

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

/**
  @page FLASH_WriteProtection FLASH write protection

  @verbatim
  ******************************************************************************
  * @file    FLASH/FLASH_WriteProtection/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the FLASH write protection example.
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

How to configure and use the FLASH HAL API to enable and disable the write
protection of the internal Flash memory.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock (SYSCLK)
to run at 48 MHz.

  - If WRITE_PROTECTION_ENABLE is selected, the write protection will be enabled
    for the defined pages.
    To load the new option byte values, a system Reset is necessary, for this, the
    function HAL_FLASH_OB_Launch() is used.

  - If WRITE_PROTECTION_DISABLE is selected, the write protection will be disabled
    for the defined pages.
    To load the new option byte values, a system Reset is necessary, for this, the
    function HAL_FLASH_OB_Launch() is used.

  - If FLASH_PAGE_PROGRAM is selected, then an erase operation is done by filling
    the erase init structure giving the starting erase page and the number of
    pages to erase. At this stage, all these pages will be erased one by one separately.

    @note: if problem occurs on a page, erase will be stopped and faulty page will
    be returned to user (through variable 'PageError').

    Once this operation is finished, double-word programming operation will be performed
    in the Flash memory. The written data is then read back and checked.

NUCLEO-WL55JC RevC board's LED can be used to monitor the transfer status:
 - LED2 is ON when there are no errors detected after programming
    => should be the case when WRITE_PROTECTION_DISABLE flag is enabled
 - LED1 is ON when there are errors detected after programming
    => should be the case when WRITE_PROTECTION_ENABLE flag is enabled
 - LED3 is ON when there is an issue during erase, program or OB program procedure

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Memory, FLASH, write protection, AREA, Sector, Mass Erase

@par Directory contents

  - FLASH/FLASH_WriteProtection/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - FLASH/FLASH_WriteProtection/Inc/stm32wlxx_hal_conf.h        HAL Configuration file
  - FLASH/FLASH_WriteProtection/Inc/stm32wlxx_it.h              Header for stm32wlxx_it.c
  - FLASH/FLASH_WriteProtection/Inc/main.h                      Header for main.c module
  - FLASH/FLASH_WriteProtection/Src/stm32wlxx_it.c              Interrupt handlers
  - FLASH/FLASH_WriteProtection/Src/main.c                      Main program
  - FLASH/FLASH_WriteProtection/Src/stm32wlxx_hal_msp.c         MSP initialization and de-initialization
  - FLASH/FLASH_WriteProtection/Src/system_stm32wlxx.c          STM32WLxx system clock configuration file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

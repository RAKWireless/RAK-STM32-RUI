/**
  @page UTILS_ReadDeviceInfo UTILS example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/UTILS/UTILS_ReadDeviceInfo/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the UTILS example.
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

This example reads the UID, Device ID and Revision ID and saves 
them into a global information buffer.

Then UID, Device ID and Revision ID will be saved in following global variables:
- aShowDeviceID: Device identifier
- aShowRevisionID: Revision identifier (This field indicates the revision of the device. 
  For example, it is read as 0x1000 for Revision 1.0)
- aShowCoordinate: X and Y coordinates on the wafer expressed in BCD format
- aShowWaferNumber: WAF_NUM[7:0], Wafer number (8-bit unsigned number)
- aShowLotNumber: LOT_NUM[55:0], Lot number (ASCII encoded)

@par Keywords

System, Utils, Device info, UID, Device ID, Revision ID, Wafer, Lot number, 


@par Directory contents 

  - UTILS/UTILS_ReadDeviceInfo/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - UTILS/UTILS_ReadDeviceInfo/Inc/main.h                  Header for main.c module
  - UTILS/UTILS_ReadDeviceInfo/Inc/stm32_assert.h          Template file to include assert_failed function  
  - UTILS/UTILS_ReadDeviceInfo/Src/stm32wlxx_it.c          Interrupt handlers
  - UTILS/UTILS_ReadDeviceInfo/Src/main.c                  Main program
  - UTILS/UTILS_ReadDeviceInfo/Src/system_stm32wlxx.c      STM32WLxx system source file


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

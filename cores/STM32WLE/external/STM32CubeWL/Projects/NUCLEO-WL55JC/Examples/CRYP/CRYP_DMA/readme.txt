/**
  @page CRYP_DMA  Encrypt and Decrypt data using AES Algo in ECB chaining
   mode using DMA

  @verbatim
  ******************************************************************************
  * @file    CRYP/CRYP_DMA/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the CRYP AES Algorithm in ECB mode with DMA Example
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

How to use the AES peripheral to encrypt and decrypt data using AES 128
Algorithm with ECB chaining mode in DMA mode.

DMA is used to transfer data from memory to the AES processor
input as well as to transfer data from AES processor output to memory.

64-byte buffers are ciphered and deciphered (4 AES blocks)
Ciphering/Deciphering with a 128-bit long key is used with data type set to 8-bit (byte swapping).

This example unrolls as follows:
- AES Encryption (Plain Data --> Encrypted Data)
- AES Decryption with key derivation (Encrypted Data --> Decrypted Data)

Plain data, encrypted data and decrypted data are displayed on debugger terminal IO.
Note that when resorting to MDK-ARM KEIL IDE, plain data, encrypted data and decrypted
data are displayed on debugger as follows:  View --> Serial Viewer --> Debug (printf) Viewer.
The following hardware modifications are required to display the data on debugger for MDK-ARM :
    - The solder bridge : SB8 should be closed
    - The solder bridge : SB31 should be opened
When resorting to STM32CubeIDE:
Command Code is displayed on debugger as follows: Window--> Show View--> Console.
In Debug configuration : 
- Window\Debugger, select the Debug probe : ST-LINK(OpenOCD)
- window\ Startup,add the command "monitor arm semihosting enable"

When all ciphering and deciphering operations are successful, LED2 is turned on.
In case of ciphering or deciphering issue, LED3 toggle each 200ms.

The Plain data, encrypted data and decrypted data can be displayed on a PC
HyperTerminal using the UART. USE_VCP_CONNECTION=1 must be added in command line.

@par Keywords

Security, Cryptography, CRYPT, AES, ECB, DMA, cipher, UART


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents

  - CRYP/CRYP_DMA/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - CRYP/CRYP_DMA/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - CRYP/CRYP_DMA/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - CRYP/CRYP_DMA/Inc/main.h                  Header for main.c module
  - CRYP/CRYP_DMA/Src/stm32wlxx_it.c          Interrupt handlers
  - CRYP/CRYP_DMA/Src/main.c                  Main program
  - CRYP/CRYP_DMA/Src/stm32wlxx_hal_msp.c     HAL MSP module
  - CRYP/CRYP_DMA/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

   - This example runs on STM32WL55JCIx devices.

    - This example has been tested with a STM32WL55JCIx embedded on an
    NUCLEO-WL55JC RevC board and can be easily tailored to any other supported
    device and development board.


@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

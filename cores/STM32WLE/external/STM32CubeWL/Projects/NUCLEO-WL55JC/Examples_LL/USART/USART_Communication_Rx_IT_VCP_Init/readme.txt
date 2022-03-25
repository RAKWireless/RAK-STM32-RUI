/**
  @page USART_Communication_Rx_IT_VCP_Init USART Receiver example (IT Mode)
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/USART/USART_Communication_Rx_IT_VCP_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USART_Communication_Rx_IT_VCP_Init example.
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

This example shows how to configure GPIO and USART peripheral for receiving characters
from HyperTerminal (PC) in Asynchronous mode using Interrupt mode. Peripheral initialization is done
using LL initialization function to demonstrate LL init usage.

USART Peripheral is configured in asynchronous mode (115200 bauds, 8 data bit, 1 start bit, 1 stop bit, no parity).
No HW flow control is used.
GPIO associated to User push-button is linked with EXTI. 
USART RX Not Empty interrupt is enabled.
Virtual Com port feature of STLINK could be used for UART communication between board and PC.

Example execution:
When character is received on USART Rx line, a RXNE interrupt occurs. 
USART IRQ Handler routine is then checking received character value. 
On a specific value ('S' or 's'), LED2 is turned On. 
Received character is echoed on Tx line.
On press on push button, LED2 is turned Off.
In case of errors, LED2 is blinking.

@par Keywords

Connectivity, UART/USART, Asynchronous, RS-232, baud rate, Interrupt, HyperTerminal, Receiver, VCP

@par Directory contents 

  - USART/USART_Communication_Rx_IT_VCP_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - USART/USART_Communication_Rx_IT_VCP_Init/Inc/main.h                  Header for main.c module
  - USART/USART_Communication_Rx_IT_VCP_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - USART/USART_Communication_Rx_IT_VCP_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - USART/USART_Communication_Rx_IT_VCP_Init/Src/main.c                  Main program
  - USART/USART_Communication_Rx_IT_VCP_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    Please ensure that USART communication between the target MCU and ST-LINK MCU is properly enabled 
    on HW board in order to support Virtual Com Port (Default HW SB configuration allows use of VCP)

  - Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration 
    (115200 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control).

  - Launch the program. Enter characters on PC communication SW side.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

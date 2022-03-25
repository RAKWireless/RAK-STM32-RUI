/**
  @page USART_Communication_Tx_Init USART Transmitter example (Polling mode)
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/USART/USART_Communication_Tx_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USART_Communication_Tx_Init example.
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

This example shows how to configure GPIO and USART peripherals to send characters 
asynchronously to an HyperTerminal (PC) in Polling mode. If the transfer could not
be completed within the allocated time, a timeout allows to exit from the sequence
with a Timeout error code. This example is based on STM32WLxx USART LL API. Peripheral
initialization is done using LL unitary services functions for optimization purpose
(performance and size).

USART Peripheral is configured in asynchronous mode (115200 bauds, 8 data bit, 1 start bit, 1 stop bit, no parity).
No HW flow control is used.
GPIO associated to User push-button is linked with EXTI. 
Virtual Com port feature of STLINK could be used for UART communication between board and PC.

Example execution:
On press on push button , first character of buffer to be transmitted is written into USART Transmit Data Register (TDR) 
Program then starts polling on USART TXE flag before sending next character.
On last character, program polls on TC flag to ensure transmit of last character is completed.
At completion of Tx Buffer sending, LED2 is turned On.
In case of errors, LED2 is blinking (1sec period).

Program is written so that, any new press on User push-button will lead to new transmission of complete buffer.

@par Keywords

Connectivity, UART/USART, Asynchronous, RS-232, baud rate, Polling, HyperTerminal, Transmitter

@par Directory contents 

  - USART/USART_Communication_Tx_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - USART/USART_Communication_Tx_Init/Inc/main.h                  Header for main.c module
  - USART/USART_Communication_Tx_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - USART/USART_Communication_Tx_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - USART/USART_Communication_Tx_Init/Src/main.c                  Main program
  - USART/USART_Communication_Tx_Init/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.
    
  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    Connect USART1 TX/RX to respectively RX and TX pins of PC UART (could be done through a USB to UART adapter) :
    - Connect STM32 MCU board USART1 TX pin (GPIO PB.06 connected to pin 35 of connector CN10)
      to PC COM port RX signal
    - Connect STM32 MCU board USART1 RX pin (GPIO PB.07 connected to pin 37 of connector CN10)
      to PC COM port TX signal
    - Connect STM32 MCU board GND to PC COM port GND signal

  - Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration 
    (115200 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control).

  - Launch the program. Press on User push button on board to initiate data transfer.

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

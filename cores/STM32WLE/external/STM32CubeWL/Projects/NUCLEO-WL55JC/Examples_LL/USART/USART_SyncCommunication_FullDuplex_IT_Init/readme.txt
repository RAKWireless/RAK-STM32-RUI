/**
  @page USART_SyncCommunication_FullDuplex_IT_Init USART Synchronous Transmitter/Receiver example (IT mode)
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/USART/USART_SyncCommunication_FullDuplex_IT_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the USART_SyncCommunication_FullDuplex_IT_Init example.
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

Configuration of GPIO, USART, DMA and SPI peripherals to transmit 
bytes between a USART and an SPI (in slave mode) in Interrupt mode. This example is based on the STM32WLxx USART LL API 
(the SPI uses the DMA to receive/transmit characters sent from/received by the USART). The peripheral 
initialization uses LL unitary service functions for optimization purposes (performance and size).

This example works with only one NUCLEO-WL55JC RevC.

USART1 Peripheral is acts as Master using IT.
SPI1 Peripheral is configured in Slave mode using DMA.
GPIO associated to User push-button (B1) is linked with EXTI.

Example execution:

LED2 is blinking Fast (200ms) and wait User push-button (B1) action.
Press User push-button (B1) on BOARD start a Full-Duplex communication from USART using IT.
On USART1 side, Clock will be generated on SCK line, Transmission done on TX, reception on RX.
On SPI1 side, reception is done through the MOSI Line, transmission on MISO line.

At end of transmission, both received buffers are compared to expected ones.
In case of both transfers successfully completed, LED2 is turned on.
In case of errors, LED2 is blinking Slowly (1s).

@par Keywords

Connectivity, UART/USART, Synchronous, Interrupt, SPI interface, Receiver, Transmitter, full-duplex

@par Directory contents 

  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Inc/main.h                  Header for main.c module
  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Src/main.c                  Main program
  - USART/USART_SyncCommunication_FullDuplex_IT_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect USART1 SCK PA.08 to Slave SPI1 SCK PB.03
    - Connect USART1 TX PA.09 to Slave SPI1 MOSI PB.05
    - Connect USART1 RX PA.10 to Slave SPI1 MISO PB.04

Board connector:
  PA.08 :   connected to pin 16 of Morpho connector CN10
  PA.09 :   connected to pin 19 of Morpho connector CN10
  PA.10 :   connected to pin 32 of Morpho connector CN7
  PB.03 :   connected to pin 31 of Morpho connector CN10
  PB.05 :   connected to pin 29 of Morpho connector CN10
  PB.04 :   connected to pin 34 of Morpho connector CN7

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
 - Launch the program. Press on User push-button (B1) on board to initiate data transfers.

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

﻿/**
  @page UART_WakeUpFromStopUsingFIFO wake up from STOP mode example using UART 
        FIFO level through LPUART1 peripheral

  @verbatim
  ******************************************************************************
  * @file    UART/UART_WakeUpFromStopUsingFIFO/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the UART_WakeUpFromStopUsingFIFO example.
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

Configuration of an UART to wake up the MCU from Stop mode with a FIFO level
when a given stimulus is received.

Board: NUCLEO-WL55JC RevC
Tx Pin: PA.02
Rx Pin: PA.03
Virtual COM port available through ST-Link cable:
   _________________________
  |           ______________|                       _______________
  |          |USART         |                      | HyperTerminal |
  |          |              |                      |               |
  |          |           TX |______________________|RX             |
  |          |              |                      |               |
  |          |              |     ST-Link Cable    |               |
  |          |           RX |______________________|TX             |
  |          |              |                      |               |
  |          |______________|                      |_______________|
  |                         |
  |                         |
  |                         |
  |                         |
  |_STM32_Board_____________|

LED2 is ON when MCU is not in STOP mode and turn off when MCU is in STOP mode.
If the test fails or if there is an initialization or transfer error, LED2
transmits a sequence of three dots, three dashes, three dots.

At the beginning of the main program, the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for
STM32WL55JC Devices.

In the first part of the example, the LPUART1 is configured for
reception with Rx FIFO threshold set to one 1 QUARTER and the CPU enters into
Stop Mode. The UART FIFO threshold interrupt is enabled and, by default,
the UART FIFO full is disabled. The user has to send 2 bytes from the
HyperTerminal. After 2 received bytes, the UART FIFO will reach the quarter
level which will generate an interrupt and wake up the CPU.

In the second part of the example, the LPUART1 is configured for
reception with FIFO threshold interrupt disabled and FIFO full enabled.
Then the CPU goes to stop mode. The user has to send 8 bytes (size of the UART
FIFO) from the HyperTerminal. After 8 received bytes, the UART FIFO will be
full, which will generate an interrupt and wake up the CPU.

The LPUART1 is configured as follows:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits (7 data bit + 1 parity bit)
    - One Stop Bit
    - Odd parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Reception and transmission are enabled in the time

@note When the parity is enabled, the computed parity is inserted at the MSB
      position of the transmitted data.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be
      blocked. To change the SysTick interrupt priority you have to use
      HAL_NVIC_SetPriority() function.

@note The application needs to ensure that the SysTick time base is always set
      to 1 millisecond to have correct HAL operation.

@par Keywords

Connectivity, UART/USART, baud rate, Wake Up, Low Power, HyperTerminal, full-duplex, Interrupt
Transmitter, Receiver, Asynchronous

@par Directory contents

  - UART_WakeUpFromStopUsingFIFO/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - UART_WakeUpFromStopUsingFIFO/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - UART_WakeUpFromStopUsingFIFO/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - UART_WakeUpFromStopUsingFIFO/Inc/main.h                  Header for main.c module
  - UART_WakeUpFromStopUsingFIFO/Src/stm32wlxx_it.c          Interrupt handlers
  - UART_WakeUpFromStopUsingFIFO/Src/main.c                  Main program
  - UART_WakeUpFromStopUsingFIFO/Src/stm32wlxx_hal_msp.c     HAL MSP module
  - UART_WakeUpFromStopUsingFIFO/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JC devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC set-up
      Connect a USB cable between the ST-Link USB connector
      and PC to display data on the HyperTerminal.

  - Hyperterminal configuration:
    - Data Length = 7 Bits
    - One Stop Bit
    - Odd parity
    - BaudRate = 115200 baud
    - Flow control: None

@par How to use it?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
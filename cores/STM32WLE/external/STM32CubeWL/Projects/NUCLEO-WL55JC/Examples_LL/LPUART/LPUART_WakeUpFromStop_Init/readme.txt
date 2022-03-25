/**
  @page LPUART_WakeUpFromStop_Init LPUART example
  
  @verbatim
  ******************************************************************************
  * @file    Examples_LL/LPUART/LPUART_WakeUpFromStop_Init/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the LPUART_WakeUpFromStop_Init LPUART example.
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
  
Configuration of GPIO and LPUART peripherals to allow characters 
received on LPUART_RX pin to wake up the MCU from low-power mode. This example is based 
on the LPUART LL API. The peripheral initialization uses LL 
initialization function to demonstrate LL init usage.

LPUART Peripheral is configured in asynchronous mode (9600 bauds, 8 data bit, 1 start bit, 1 stop bit, no parity).
No HW flow control is used.
LPUART Clock is based on HSI.

Example execution:
After startup from reset and system configuration, LED2 is blinking quickly during 3 sec,
then MCU  enters "Stop 0" mode (LED2 off).
On first  character reception by the LPUART from PC Com port (ex: using HyperTerminal)
after "Stop 0" Mode period, MCU wakes up from "Stop 0" Mode.

Received character value is checked :
- On a specific value ('S' or 's'), LED2 is turned On and program ends.
- If different from 'S' or 's', program performs a quick LED2 blinks during 3 sec and 
  enters again "Stop 0" mode, waiting for next character to wake up.

In case of errors, LED2 is slowly blinking (1 sec period).

@par Keywords

Connectivity, LPUART, baud rate, RS-232, HyperTerminal, full-duplex,
Transmitter, Receiver, Asynchronous, Low Power

@par Directory contents 

  - LPUART/LPUART_WakeUpFromStop_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - LPUART/LPUART_WakeUpFromStop_Init/Inc/main.h                  Header for main.c module
  - LPUART/LPUART_WakeUpFromStop_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - LPUART/LPUART_WakeUpFromStop_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - LPUART/LPUART_WakeUpFromStop_Init/Src/main.c                  Main program
  - LPUART/LPUART_WakeUpFromStop_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    Example is delivered for using Virtual Com port feature of STLINK for connection between NUCLEO-WL55JC RevC and PC,
    GPIOs connected to LPUART1 TX/RX (PA2 and PA3) are automatically mapped
    on RX and TX pins of PC UART Com port selected on PC side (please ensure VCP com port is selected).

    - Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration 
      (9600 bauds, 8 bits data, 1 stop bit, no parity, no HW flow control). 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

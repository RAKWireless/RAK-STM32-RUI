/**
  @page I2C_TwoBoards_WakeUpFromStop_IT_Init I2C example (IT Mode)

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the I2C_TwoBoards_WakeUpFromStop_IT_Init I2C example (IT Mode).
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

How to handle the reception of a data byte from an I2C slave device in
Stop 1 mode by an I2C master device, both using interrupt mode. The
peripheral is initialized with LL unitary service functions to optimize for
performance and size.

This example guides you through the different configuration steps by mean of LL API
to configure GPIO and I2C peripherals using two NUCLEO-WL55JC RevC.

Boards: NUCLEO-WL55JC RevC (embeds a STM32WL55JC device)
SCL Pin: PA.12 (CN10, pin 3)
SDA Pin: PA.15 (CN7, pin 17)

   ______BOARD SLAVE_____                       _____BOARD MASTER_____
  |        ______________|                     |______________        |
  |       |I2C2          |                     |          I2C2|       |
  |       |              |                     |              |       |
  |       |          SCL |_____________________| SCL          |       |
  |       |              |                     |              |       |
  |       |              |                     |              |       |
  |       |          SDA |_____________________| SDA          |       |
  |       |______________|                     |______________|       |
  |         __           |                     |             __       |
  |        |__|          |                     |            |__|      |
  |        USER       GND|_____________________|GND         USER      |
  |___STM32WLxx_Nucleo___|                     |___STM32WLxx_Nucleo___|

The project is split in two parts the Master Board and the Slave Board
- Master Board
  I2C2 Peripheral is configured in Master mode with EXTI (Clock 100Khz).
  And GPIO associated to User push-button (B1) is linked with EXTI.
- Slave Board
  I2C2 Peripheral is configured in Slave mode with EXTI (Clock 100Khz,
  Own address 7-bit enabled, WakeUpFromStop).

The user can choose between Master and Slave through "#define SLAVE_BOARD"
in the "main.h" file:
- Comment "#define SLAVE_BOARD" to select Master board.
- Uncomment "#define SLAVE_BOARD" to select Slave board.

The user can disable internal pull-up by opening ioc file.
For that, user can follow the procedure :
1- Double click on the I2C_TwoBoards_WakeUpFromStop_IT_Init.ioc file
2- When CUBEMX tool is opened, select System Core category
3- Then in the configuration of GPIO/I2C2, change Pull-up to No pull-up and no pull-down for the both pins
4- Last step, generate new code thanks to button "GENERATE CODE"
The example is updated with no pull on each pin used for I2C communication

A first program launch, BOARD SLAVE is in Stop 1 mode and BOARD MASTER is waiting User action on User push-button (B1).
LED2 blinks quickly on BOARD MASTER to wait for user-button press.

Example execution:
Press the User push-button (B1) on BOARD MASTER to initiate a read request by Master.
This action will generate an I2C start condition with the Slave address and a read bit condition.
When address Slave match code is received on I2C2 of BOARD SLAVE, a wake up is initiate and an ADDR interrupt occurs.
I2C2 Slave IRQ Handler routine is then checking Address Match Code and direction Read.
This will allow Slave to enter in transmitter mode and then send a byte when TXIS interrupt occurs.
When byte is received on I2C2 of BOARD MASTER, an RXNE interrupt occurs.
When RXDR register is read, Master auto-generate a NACK and STOP condition
to inform the Slave that the transfer is finished.
The NACK condition generate a NACK interrupt in Slave side treated in the I2C2 Slave IRQ handler routine by a clear of NACK flag.
The STOP condition generate a STOP interrupt in both side (Slave and Master). Both I2C2 IRQ handler routine are then
clearing the STOP flag in both side.

LED2 is ON on Slave side if the byte is well transmitted.
LED2 is ON on Master side if the expected byte is well received.

In case of errors, LED2 is blinking slowly (1s).

@par Keywords

Connectivity, I2C, Communication, Transmission, Reception, SCL, SDA, Wake up, Interrupt

@par Directory contents

  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/main.h                  Header for main.c module
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/main.c                  Main program
  - I2C/I2C_TwoBoards_WakeUpFromStop_IT_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with STM32WL55JCIx board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect GPIOs connected to Board Slave I2C2 SCL/SDA (PA.12 and PA.15)
    to respectively Board Master SCL and SDA pins of I2C2 (PA.12 and PA.15).
      - I2C2_SCL  PA.12 (CN10, pin 3) : connected to I2C2_SCL PA.12 (CN10, pin 3)
      - I2C2_SDA  PA.15 (CN7, pin 17) : connected to I2C2_SDA PA.15 (CN7, pin 17)
    - Connect Master board GND to Slave Board GND

  - Launch the program.
  - Press User push-button (B1) to initiate a read request by Master
      then Slave after wake up from Stop 1 mode send a byte.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory (The user can choose between Master
   and Slave target through "#define SLAVE_BOARD" in the "main.h" file)
    o Comment "#define SLAVE_BOARD" and load the project in Master Board
    o Uncomment "#define SLAVE_BOARD" and load the project in Slave Board
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

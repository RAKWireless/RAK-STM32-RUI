/**
  @page I2C_OneBoard_Communication_DMAAndIT_Init I2C (Master DMA Mode)

  @verbatim
  ******************************************************************************
  * @file    Examples_LL/I2C/I2C_OneBoard_Communication_DMAAndIT_Init/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the I2C_OneBoard_Communication_DMAAndIT_Init I2C example (Master DMA Mode).
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

How to transmit data bytes from an I2C master device using DMA mode
to an I2C slave device using interrupt mode. The peripheral is initialized with
LL unitary service functions to optimize for performance and size.

This example guides you through the different configuration steps by mean of LL API
to configure GPIO, DMA and I2C peripherals using only one NUCLEO-WL55JC RevC.

The user can disable internal pull-up by opening ioc file.
For that, user can follow the procedure :
1- Double click on the I2C_OneBoard_Communication_DMAAndIT_Init.ioc file
2- When CUBEMX tool is opened, select System Core category
3- Then in the configuration of GPIO/I2C2, change Pull-up to No pull-up and no pull-down for the both pins
4- Same action in the configuration of GPIO/I2C3, change Pull-up to No pull-up and no pull-down for the both pins
5- Last step, generate new code thanks to button "GENERATE CODE"
The example is updated with no pull on each pin used for I2C communication

I2C2 Peripheral is configured in Slave mode with EXTI (Clock 400Khz, Own address 7-bit enabled).
I2C3 Peripheral is configured in Master mode with DMA (Clock 400Khz).
GPIO associated to User push-button is linked with EXTI.

LED2 blinks quickly to wait for user-button press.

Example execution:
Press the User push-button (B1) to initiate a write request by Master through Handle_I2C_Master() routine.
This action will generate an I2C start condition with the Slave address and a write bit condition.
When address Slave match code is received on I2C2, an ADDR interrupt occurs.
I2C2 IRQ Handler routine is then checking Address Match Code and direction Write.
This will allow Slave to enter in receiver mode and then acknowledge Master to send the bytes through DMA.
When acknowledge is received on I2C3, DMA transfer the data from flash memory buffer to I2C3 TXDR register.
This will allow Master to transmit a byte to the Slave.
Each time a byte is received on I2C2 (Slave), an RXNE interrupt occurs until a STOP condition.
And so each time the Slave acknowledge the byte received,
DMA transfer the next data from flash memory buffer to I2C3 TXDR register until Transfer completed.
Master auto-generate a Stop condition when DMA transfer is achieved.

The STOP condition generate a STOP interrupt and initiate the end of reception on Slave side.
I2C2 IRQ handler and Handle_I2C_Master() routine are then clearing the STOP flag in both side.

LED2 is On if data are well received.

In case of errors, LED2 is blinking slowly (1s).

@par Keywords

Connectivity, Communication, I2C, DMA, Interrupt, Master, Slave, Transmission, Reception, Fast mode


@par Directory contents

  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Inc/main.h                  Header for main.c module
  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Inc/stm32_assert.h          Template file to include assert_failed function
  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Src/stm32wlxx_it.c          Interrupt handlers
  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Src/main.c                  Main program
  - I2C/I2C_OneBoard_Communication_DMAAndIT_Init/Src/system_stm32wlxx.c      STM32WLxx system source file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect GPIOs connected to I2C2 SCL/SDA (PA.12 and PA.15)
    to respectively SCL and SDA pins of I2C3 (PC.0 and PC.1).
      - I2C2_SCL  PA.12 (CN10, pin 3) : connected to I2C3_SCL PC.0 (CN10, pin 14)
      - I2C2_SDA  PA.15 (CN7, pin 17) : connected to I2C3_SDA PC.1 (CN10, pin 23)

  - Launch the program. Press User push-button (B1) to initiate a write request by Master
      then Slave receive bytes.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */

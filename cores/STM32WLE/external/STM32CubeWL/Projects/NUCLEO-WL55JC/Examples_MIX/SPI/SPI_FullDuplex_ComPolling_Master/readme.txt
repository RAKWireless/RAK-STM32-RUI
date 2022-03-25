/**
  @page SPI_FullDuplex_ComPolling_Master SPI Two Boards Communication example
  
  @verbatim
  ******************************************************************************
  * @file    SPI/SPI_FullDuplex_ComPolling_Master/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the SPI Full Duplex Polling example.
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

Data buffer transmission/reception between two boards via SPI using Polling mode.

Board: NUCLEO-WL55JC RevC (embeds a STM32WL55JC device)
CLK Pin: PA5 (CN10, pin 11)
MISO Pin: PA6 (CN10, pin 13)
MOSI Pin: PA7 (CN10, pin 15)
   _________________________                       __________________________
  |           ______________|                      |______________           |
  |          |SPI1          |                      |          SPI1|          |
  |          |              |                      |              |          |
  |          |    CLK(PA.05)|______________________|(PA.05)CLK    |          |
  |          |              |                      |              |          |
  |          |   MISO(PA.06)|______________________|(PA.06)MISO   |          |
  |          |              |                      |              |          |
  |          |   MOSI(PA.07)|______________________|(PA.07)MOSI   |          |
  |          |              |                      |              |          |
  |          |______________|                      |______________|          |
  |      __                 |                      |                         |
  |     |__|                |                      |                         |
  |    User push-button (B1)     |                      |                         |
  |                      GND|______________________|GND                      |
  |                         |                      |                         |
  |_STM32WLxx Master________|                      |_STM32WLxx Slave_________|


At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 48 MHz.

The SPI peripheral configuration is ensured by the HAL_SPI_Init() function.
This later is calling the HAL_SPI_MspInit()function which core is implementing
the configuration of the needed SPI resources according to the used hardware (CLOCK & 
GPIO). You may update this function to change SPI configuration.
The Full-Duplex SPI transfer (16bit) is done using LL Driver functions 
LL_SPI_TransmitData16 and LL_SPI_ReceiveData16.

Example execution:
First step, press the User push-button (User push-button (B1)), this action initiates a Full-Duplex transfer 
between Master and Slave.
After end of transfer, aRxBuffer and aTxBuffer are compared through Buffercmp() in order to 
check buffers correctness.

STM32 board's LEDs can be used to monitor the transfer status:
 - LED1 toggles quickly on master board waiting User push-button (B1) to be pressed.
 - LED1 turns ON when the transmission process is complete.
 - LED2 turns ON when the reception process is complete.
 - LED3 turns ON when there is an error in transmission/reception process. 
 - LED3 toggles when there is a timeout error in transmission/reception process. 

@note You need to perform a reset on Slave board, then perform it on Master board
      to have the correct behaviour of this example.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Connectivity, SPI, Full-duplex, Transmission, Reception, Master, MISO, MOSI, Polling

@par Directory contents 

  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - SPI/SPI_FullDuplex_ComPolling_Master/Inc/main.h                  Header for main.c module  
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/stm32wlxx_it.c          Interrupt handlers
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/main.c                  Main program
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/system_stm32wlxx.c      stm32wlxx system source file
  - SPI/SPI_FullDuplex_ComPolling_Master/Src/stm32wlxx_hal_msp.c     HAL MSP file

@par Hardware and Software environment

  - This example runs on STM32WL55JCIx devices.

  - Take care to cable connection between Master and Slave Board:
    Cable shall be smaller than 5 cm and rigid if possible.

  - This example has been tested with NUCLEO-WL55JC RevC board and can be
    easily tailored to any other supported device and development board.

  - NUCLEO-WL55JC RevC Set-up
    - Connect Master board PA5 (CN10, pin 11) to Slave Board PA5 (CN10, pin 11)
    - Connect Master board PA6 (CN10, pin 13) to Slave Board PA6 (CN10, pin 13)
    - Connect Master board PA7 (CN10, pin 15) to Slave Board PA7 (CN10, pin 15)
    - Connect Master board GND to Slave Board GND

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files (master project) and load your image into target memory
    o Load the project in Master Board
 - Rebuild all files (slave project) and load your image into target memory
    o Load the project in Slave Board
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
 
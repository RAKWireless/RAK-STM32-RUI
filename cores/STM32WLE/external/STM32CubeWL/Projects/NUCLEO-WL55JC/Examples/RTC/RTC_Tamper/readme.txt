/**
  @page RTC_Tamper RTC Tamper Example

  @verbatim
  ******************************************************************************
  * @file    RTC/RTC_Tamper/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the RTC Tamper example.
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

Configuration of the tamper detection with backup registers erase.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 48 MHz.

The RTC peripheral configuration is ensured by the MX_RTC_Init() and MX_TAMP_RTC_Init functions.
HAL_RTC_MspInit()function which core is implementing the configuration of the needed RTC resources
according to the used hardware (CLOCK,PWR, RTC clock source and BackUp).
You may update this function to change RTC configuration.

@note LSE oscillator clock is used as RTC clock source (32.768 kHz) by default.

This example performs the following:
1. Connect a wire between Tamper 1 pin PC.13 (CN7, pin 23) and GND.
2. Run the software. It configures the Tamper 1 pin  and enables the Tamper 1 interrupt.
3. Software writes a data to a RTC Backup register, checks if the data are correctly written and waits for a Tamper 1 interrupt.
4. To generate a tamper detection (rising edge), please move the wire from GND to 3.3V.
5. The RTC backup register is reset and the Tamper interrupt is generated.
   The firmware then checks if the RTC Backup register is cleared.
6. LED2 turns ON, Test is OK.
   LED2 blinks, Test is KO.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, RTC, Tamper, Reset, LSE, Backup

@par Directory contents
  - RTC/RTC_Tamper/Inc/stm32wlxx_nucleo_conf.h     BSP configuration file
  - RTC/RTC_Tamper/Inc/stm32wlxx_hal_conf.h    HAL configuration file
  - RTC/RTC_Tamper/Inc/stm32wlxx_it.h          Interrupt handlers header file
  - RTC/RTC_Tamper/Inc/main.h                        Header for main.c module
  - RTC/RTC_Tamper/Src/stm32wlxx_it.c          Interrupt handlers
  - RTC/RTC_Tamper/Src/main.c                        Main program
  - RTC/RTC_Tamper/Src/stm32wlxx_hal_msp.c     HAL MSP module
  - RTC/RTC_Tamper/Src/system_stm32wlxx.c      STM32WLxx system source file


@par Hardware and Software environment
  - This example runs on STM32WL55JCIx devices.
  - This example has been tested with STMicroelectronics NUCLEO-WL55JC RevC
    board and can be easily tailored to any other supported device
    and development board.

@par How to use it ?
In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */


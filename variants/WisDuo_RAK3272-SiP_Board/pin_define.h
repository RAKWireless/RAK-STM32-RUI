#ifndef __PIN_DEFINE_H__
#define __PIN_DEFINE_H__

#include "variant.h"

#define RAK_PA0                 0
#define RAK_PA1                 1
#define RAK_PA2                 2
#define RAK_PA3                 3
#define RAK_PA4                 4
#define RAK_PA5                 5
#define RAK_PA6                 6
#define RAK_PA7                 7
#define RAK_PA8                 8
#define RAK_PA9                 9
#define RAK_PA10                10
#define RAK_PA11                11
#define RAK_PA12                12
#define RAK_PA13                13
#define RAK_PA14                14
#define RAK_PA15                15
#define RAK_PB0                 16
#define RAK_PB1                 17
#define RAK_PB2                 18
#define RAK_PB3                 19
#define RAK_PB4                 20
#define RAK_PB5                 21
#define RAK_PB6                 22
#define RAK_PB7                 23
#define RAK_PB8                 24
#define RAK_PB9                 25
#define RAK_PB10                26
#define RAK_PB11                27
#define RAK_PB12                28
#define RAK_PB13                29
#define RAK_PB14                30
#define RAK_PB15                31

#define GREEN_LED               RAK_PA0
#define BLUE_LED                RAK_PA1

#define I2C0_SDA                0xFF
#define I2C0_SCL                0xFF
#define I2C1_SDA                0xFF
#define I2C1_SCL                0xFF
#define I2C2_SDA                RAK_PA11
#define I2C2_SCL                RAK_PA12

#define SPIM1_NSS               RAK_PA4
#define SPIM1_MOSI              RAK_PA7
#define SPIM1_MISO              RAK_PA6
#define SPIM1_SCK               RAK_PA5

#define _ADC1                   PIN_A0 
#define _ADC2                   PIN_A1
#define _ADC3                   PIN_A2
#define _ADC4                   PIN_A3
#define _ADC5                   PIN_A4

#define SWDIO                   RAK_PA13
#define SWCLK                   RAK_PA14

#define             UART0_TXD_PIN                        0xFF
#define             UART0_RXD_PIN                        0xFF
#define             UART1_TXD_PIN                        RAK_PB7
#define             UART1_RXD_PIN                        RAK_PB6
#define             UART2_TXD_PIN                        RAK_PA2
#define             UART2_RXD_PIN                        RAK_PA3

#define             SPI_CSN_PIN                          SPIM1_NSS


#endif  // __PIN_DEFINE_H__

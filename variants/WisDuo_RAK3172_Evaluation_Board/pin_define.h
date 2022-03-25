#ifndef __PIN_DEFINE_H__
#define __PIN_DEFINE_H__

#include "variant.h"

#define GREEN_LED               PIN_LED1
#define BLUE_LED                PIN_LED2

#define I2C0_SDA                0xFF
#define I2C0_SCL                0xFF
#define I2C1_SDA                0xFF
#define I2C1_SCL                0xFF
#define I2C2_SDA                WB_I2C1_SDA
#define I2C2_SCL                WB_I2C1_SCL

#define SPIM1_NSS               WB_SPI_CS
#define SPIM1_MOSI              WB_SPI_MOSI
#define SPIM1_MISO              WB_SPI_MISO
#define SPIM1_SCK               WB_SPI_CLK

#define ADC1                    WB_A0
#define ADC2                    WB_A1
#define ADC3                    WB_IO4
#define ADC4                    WB_IO7
#define ADC5                    WB_IO5

#define SWDIO                   PA13
#define SWCLK                   PA14

#define             UART0_TXD_PIN                        0xFF
#define             UART0_RXD_PIN                        0xFF
#define             UART1_TXD_PIN                        PIN_SERIAL1_TX
#define             UART1_RXD_PIN                        PIN_SERIAL1_RX
#define             UART2_TXD_PIN                        PIN_SERIAL2_TX
#define             UART2_RXD_PIN                        PIN_SERIAL2_RX

#define             SPI_CSN_PIN                          SPIM1_NSS


#endif  // __PIN_DEFINE_H__

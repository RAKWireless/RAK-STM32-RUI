#ifndef _VARIANT_RAK3172_
#define _VARIANT_RAK3172_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

//TODO

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include <stdint.h>
#include "PinNames.h"
#include "pins_arduino.h"
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

extern const uint32_t g_ADigitalPinMap[]; 
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

#define PINS_COUNT           (29u)
#define NUM_DIGITAL_PINS     (27u)
#define NUM_ANALOG_INPUTS    (2u)
#define NUM_ANALOG_OUTPUTS   (0u)

                               // STM32WLE5     | RAK3172  | WisBlock | Comment
#define PA0                 0  // (GPIO)        | LED1     | LED1     |
#define PA1                 1  // (GPIO)        | LED2     | LED2     |
#define PA2                 2  // LPUART1_TX    | UART2_TX |          |
#define PA3                 3  // LPUART1_RX    | UART2_RX |          |
#define PA4                 4  // SPI1_NSS      | SPI_CS   | SPI_CS   |
#define PA5                 5  // SPI1_SCK      | SPI_CLK  | SPI_CLK  |
#define PA6                 6  // SPI1_MISO     | SPI_MISO | SPI_MISO |
#define PA7                 7  // SPI1_MOSI     | SPI_MOSI | SPI_MOSI |
#define PA8                 8  // (GPIO)        | IO2      | IO2      |
#define PA9                 9  // (GPIO)        | IO6      | IO6      |
#define PA10                10 // (ADC_IN6)     | IO7      | IO7      |
#define PA11                11 // I2C2_SDA      | I2C1_SDA | I2C1_SDA |
#define PA12                12 // I2C2_SCL      | I2C1_SCL | I2C1_SCL |
#define PA13                13 // SWDIO         | SWDIO    |          |
#define PA14                14 // SWCLK         | SWCLK    |          |
#define PA15                15 // (ADC_IN11)    | IO5      | IO5      |
#define PB0                 16 // VDD_TCXO      |          |          | TCXO
#define PB1                 17 // (GPIO)        |          |          | (RAK3172F)
#define PB2                 18 // (ADC_IN4)     | IO4      | IO4      |
#define PB3                 19 // (ADC_IN2)     | AIN0     | AN0      |
#define PB4                 20 // (ADC_IN3)     | AIN1     | AN1      | 
#define PB5                 21 // (GPIO)        | IO1      | IO1      |
#define PB6                 22 // USART1_TX     | UART1_TX | TXD1     |
#define PB7                 23 // USART1_RX     | UART1_RX | RXD1     |
#define PB8                 24 // GPIO_OUT      |          |          | RF_SW_EN (RAK3172F)
#define PB9                 25 // SPI2_NSS      |          |          | EXTFLASH (RAK3172F)
#define PB10                26 // SPI2_SCK      |          |          | EXTFLASH (RAK3172F)
#define PB11                27 // (GPIO)        | IO3      |          | (RAK3172F)
#define PB12                28 // GPIO_IN       |          |          | Identify High/Low band hardware
#define PB13                29 // I2C3_SCL      | I2C2_SCL | I2C2_SCL | (RAK3172F)
#define PB14                30 // I2C3_SDA      | I2C2_SDA | I2C2_SDA | (RAK3172F)
#define PB15                31 // (GPIO)        | LED3     | LED3     | (RAK3172F)
#define PC0                 32 // GPIO_OUT      |          |          | EXTFLASH WP (RAK3172F)
#define PC1                 33 // SPI2_MOSI     |          |          | EXTFLASH (RAK3172F)
#define PC2                 34 // SPI2_MISO     |          |          | EXTFLASH (RAK3172F)
#define PC3                 35 // GPIO_OUT      |          |          | EXTFLASH RST (RAK3172F)
#define PC4                 36 // (GPIO_OUT)    | PC4      | TXD0     | SW_UART (RAK3172F)
#define PC5                 37 // (GPIO_IN)     | PC5      | RXD0     | SW_UART (RAK3172F)
#define PC6                 38 // (GPIO)        |          |          | (RAK3172F)
#define PC13                45 // GPIO_OUT      |          |          | RF_SW_CTR (RAK3172F)
#define PC14                46 // RCC_OSC32_IN  |          |          | TCXO (RAK3172F)
#define PC15                47 // RCC_OSC32_OUT |          |          | TCXO (RAK3172F)
#define PH3                 115// BOOT0         | BOOT     | BOOT0    |

/*
 * WisBlock Base GPIO definitions
 */

#define WB_IO1                 PB5          // SLOT_A SLOT_B
#define WB_IO2                 PA8          // SLOT_A SLOT_B
#define WB_IO3                 PB11         // SLOT_C
#define WB_IO4                 PB2          // SLOT_C
#define WB_IO5                 PA15         // SLOT_D
#define WB_IO6                 PA9          // SLOT_D
#define WB_IO7                 PA10
#define WB_SW1                 0xFF         // IO_SLOT
#define WB_A0                  PB3          // IO_SLOT
#define WB_A1                  PB4          // IO_SLOT
#define WB_I2C1_SDA            PA11         // SENSOR_SLOT IO_SLOT
#define WB_I2C1_SCL            PA12         // SENSOR_SLOT IO_SLOT
#define WB_I2C2_SDA            PB14         // IO_SLOT
#define WB_I2C2_SCL            PB13         // IO_SLOT
#define WB_SPI_CS              PA4          // IO_SLOT
#define WB_SPI_CLK             PA5          // IO_SLOT
#define WB_SPI_MISO            PA6          // IO_SLOT
#define WB_SPI_MOSI            PA7          // IO_SLOT
#define WB_RXD0                PC5          // IO_SLOT
#define WB_TXD0                PC4          // IO_SLOT
#define WB_RXD1                PB7          // SLOT_A IO_SLOT
#define WB_TXD1                PB6          // SLOT_A IO_SLOT
#define WB_LED1                PA0          // IO_SLOT
#define WB_LED2                PA1          // IO_SLOT
#define WB_LED3                PB15         // IO_SLOT

// LEDs
#define PIN_LED1 WB_LED1//PA0
#define PIN_LED2 WB_LED2//PA1
#define PIN_LED3 WB_LED3//PB15

#define LED_BUILTIN PIN_LED1
#define LED_CONN PIN_LED2

#define LED_GREEN PIN_LED1
#define LED_BLUE PIN_LED2

#define LED_STATE_ON 1 // State when LED is litted

/*
 * Analog pins
 */
#define PIN_A0 WB_A0
#define PIN_A1 WB_A1
#define PIN_A2 PB2
#define PIN_A3 PA10
#define PIN_A4 PA15

#define A0 PIN_A0
#define A1 PIN_A1
#define A2 PIN_A2
#define A3 PIN_A3
#define A4 PIN_A4
 
/*
 * Serial interfaces
 */
#define PIN_SERIAL1_RX PB7
#define PIN_SERIAL1_TX PB6

#define PIN_SERIAL2_RX PA3
#define PIN_SERIAL2_TX PA2

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO WB_SPI_MISO
#define PIN_SPI_MOSI WB_SPI_MOSI
#define PIN_SPI_SCK  WB_SPI_CLK

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA WB_I2C1_SDA
#define PIN_WIRE_SCL WB_I2C1_SCL

#ifdef __cplusplus
}
#endif

#endif

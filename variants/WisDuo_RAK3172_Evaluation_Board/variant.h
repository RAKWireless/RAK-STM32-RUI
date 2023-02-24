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

#define PA0                 0//LED1
#define PA1                 1//LED2
#define PA2                 2//UART2_TX
#define PA3                 3//UART2_RX
#define PA4                 4//SPI1_NSS
#define PA5                 5//SPI1_SCK
#define PA6                 6//SPI1_MISO
#define PA7                 7//SPI1_MOSI
#define PA8                 8//IO2
#define PA9                 9//IO6 or I2C2_SCL
#define PA10                10//IO7 or I2C2_SDA
#define PA11                11//I2C1_SDA
#define PA12                12//I2C1_SCL
#define PA13                13//SWDIO
#define PA14                14//SWCLK
#define PA15                15//IO5
#define PB0                 16//PB0-VDD_TCXO(RAK3172_internal)
#define PB2                 18//IO4
#define PB3                 19//AN0
#define PB4                 20//AN1
#define PB5                 21//IO1
#define PB6                 22//UART1_TX
#define PB7                 23//UART1_RX
#define PB8                 24//NJG1801K75 RF switch(RAK3172_internal)
#define PB12                28//IO3
#define PC13                45//FE_CTRL1(RAK3172_internal)
#define PC14                46//PC14-OSC32_IN(RAK3172 internal)
#define PC15                47//PC15-OSC32_OUT(RAK3172 internal)
#define PH3                 115//BOOT0

/*
 * WisBlock Base GPIO definitions
 */

#define WB_IO1                 PB5          // SLOT_A SLOT_B
#define WB_IO2                 PA8          // SLOT_A SLOT_B
#define WB_IO3                 PB12         // SLOT_C
#define WB_IO4                 PB2          // SLOT_C
#define WB_IO5                 PA15         // SLOT_D
#define WB_IO6                 PA9          // SLOT_D
#define WB_IO7                 PA10
#define WB_SW1                 0xFF         // IO_SLOT
#define WB_A0                  PB3          // IO_SLOT
#define WB_A1                  PB4          // IO_SLOT
#define WB_I2C1_SDA            PA11         // SENSOR_SLOT IO_SLOT
#define WB_I2C1_SCL            PA12         // SENSOR_SLOT IO_SLOT
#define WB_I2C2_SDA            PA10         // IO_SLOT
#define WB_I2C2_SCL            PA9          // IO_SLOT
#define WB_SPI_CS              PA4          // IO_SLOT
#define WB_SPI_CLK             PA5          // IO_SLOT
#define WB_SPI_MISO            PA6          // IO_SLOT
#define WB_SPI_MOSI            PA7          // IO_SLOT
#define WB_RXD0                PB7          // IO_SLOT
#define WB_TXD0                PB6          // IO_SLOT
#define WB_RXD1                PA3          // SLOT_A IO_SLOT
#define WB_TXD1                PA2          // SLOT_A IO_SLOT
#define WB_LED1                PA0          // IO_SLOT
#define WB_LED2                PA1          // IO_SLOT

// LEDs
#define PIN_LED1 WB_LED1//PA0
#define PIN_LED2 WB_LED2//PA1

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
#define PIN_SERIAL1_RX WB_RXD0//PB7
#define PIN_SERIAL1_TX WB_TXD0//PB6

#define PIN_SERIAL2_RX WB_RXD1//PA3
#define PIN_SERIAL2_TX WB_TXD1//PA2

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
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA WB_I2C1_SDA
#define PIN_WIRE_SCL WB_I2C1_SCL

#ifdef __cplusplus
}
#endif

#endif

/**
 * @file        udrv_spimst.h
 * @brief       Provide a hardware independent SPI master driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.2
 */

#ifndef _UDRV_SPIMST_H_
#define _UDRV_SPIMST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "board_basic.h"

typedef enum  {
    UDRV_SPIMST_0 = 0x0,
    UDRV_SPIMST_1 = 0x1,
    UDRV_SPIMST_2 = 0x2,
    UDRV_SPIMST_3 = 0x3,
    UDRV_SPIMST_MAX = 0x4,
} udrv_spimst_port;

typedef enum {
    SPI_MST_CPHA_0          = 0,
    SPI_MST_CPHA_1          = 1
} ENUM_SPI_MST_CPHA_T;

typedef enum {
    SPI_MST_CPOL_0          = 0,
    SPI_MST_CPOL_1          = 1
} ENUM_SPI_MST_CPOL_T;

//The structure of SPI master function 
struct udrv_spimst_api {
    void (*SPIMST_INIT) (udrv_spimst_port port);
    void (*SPIMST_SETUP_MODE) (udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL);
    void (*SPIMST_SETUP_FREQ) (udrv_spimst_port port, uint32_t clk_Hz);
    void (*SPIMST_SETUP_BYTE_ORDER) (udrv_spimst_port port, bool msb_first);
    void (*SPIMST_DEINIT) (udrv_spimst_port port);
    int8_t (*SPIMST_TRX) (udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn);
    void (*SPIMST_SUSPEND) (void);
    void (*SPIMST_RESUME) (void);
};

/**
 * Initilize SPI bus to enable SPI operations.
 * 
 * @param   port       the specified serial port
 *              
 */
void udrv_spimst_init(udrv_spimst_port port);

/**
 * Setup SPI mode.
 * 
 * @param   port       the specified serial port
 * @param   CPHA       Serial Clock Phase. 
 *              0x00 - Serial clock toggles in middle of first data bit
 *              0x01 - Serial clock toggles at start of first data bit
 * @param   CPOL       Serial Clock Polarity. 
 *              0x00 - Inactive state of serial clock is low
 *              0x01 - Inactive state of serial clock is high, need pull up in the clock pin.
 *              
 */
void udrv_spimst_setup_mode(udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL);

/**
 * Setup SPI frequency.
 * 
 * @param   port       the specified serial port
 * @param   clk_Hz     SPI Clock (BUS 40MHz : 610 - 20M, BUS 80MHz : 1221 - 40MHzM)
 *              
 */
void udrv_spimst_setup_freq(udrv_spimst_port port, uint32_t clk_Hz);

/**
 * Setup SPI bit order.
 * 
 * @param   port       the specified serial port
 * @param   msb_first   (true : most significant byte first, false : least significatn byte first)
 *              
 */
void udrv_spimst_setup_byte_order(udrv_spimst_port port, bool msb_first);

/**
 * Deinitialize SPI bus to disable SPI operations
 * 
 * @param   port            the specified serial port
 */
void udrv_spimst_deinit(udrv_spimst_port port);

/**
 * Transmit and receive the spi data.
 * 
 * @param   port            the specified serial port
 * @param   write_data      Pointer to the data buffer to be written by the master.
 * @param   write_length    Size of the write data buffer exposed to the SPI master.
 * @param   read_data       Pointer to the data buffer to be read by the master.
 * @param   read_length     Size of the read data buffer exposed to the SPI master.
 * @param   csn             Chip select pin.
 *
 * @return  -1              The operation error.
 * @return   0              The operation completed successfully.
 */
int8_t udrv_spimst_trx(udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn);

/**
 * @brief   Suspend SPI master hardware before entering sleep mode.
 *
 */
void udrv_spimst_suspend();

/**
 * @brief   Resume SPI master hardware after leaving sleep mode.
 *
 */
void udrv_spimst_resume();

#ifdef __cplusplus
}
#endif

#endif // _UDRV_SPIMST_H_

/**
 * @file        udrv_twimst.h
 * @brief       Provide a hardware independent TWI master driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.2
 */

#ifndef _UDRV_TWIMST_H_
#define _UDRV_TWIMST_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>

typedef enum {
    UDRV_TWIMST_0 = 0x0,   
    UDRV_TWIMST_1 = 0x1,
    UDRV_TWIMST_2 = 0x2,
    UDRV_TWIMST_3 = 0x3,
    UDRV_TWIMST_MAX = 0x4,
} udrv_twimst_port;

struct udrv_twimst_api {
    void (*TWIMST_INIT) (udrv_twimst_port port);
    void (*TWIMST_DEINIT) (udrv_twimst_port port);
    void (*TWIMST_SETUP_FREQ) (udrv_twimst_port port, uint32_t clk_HZ);
    int32_t (*TWIMST_WRITE) (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t len);
    int32_t (*TWIMST_READ) (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t len);
    uint8_t (*TWIMST_SUSPEND) (void);
    uint8_t (*TWIMST_RESUME) (void);

};

void udrv_twimst_init (udrv_twimst_port port);
void udrv_twimst_deinit (udrv_twimst_port port);
void udrv_twimst_setup_freq (udrv_twimst_port port, uint32_t clk_Hz);

/*
 * Function udrv_twimst_write
 * @brief     attempts to become twi bus master and write a
 *            series of bytes to a device on the bus
 * @param     address: 7bit i2c device address
 * @param     data: pointer to byte array
 * @param     length: number of bytes in array
 * Output     error code
 */
int32_t udrv_twimst_write (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t length);

/*
 * Function udrv_twimst_read
 * @brief     attempts to become twi bus master and read a
 *            series of bytes from a device on the bus
 * @param     address: 7bit i2c device address
 * @param     data: pointer to byte array
 * @param     length: number of bytes to read into array
 * Output     error code
 */
int32_t udrv_twimst_read (udrv_twimst_port port, uint8_t address, uint8_t *data, uint16_t length);

void udrv_twimst_suspend (void);
void udrv_twimst_resume (void);

#ifdef __cplusplus
}
#endif

#endif //_UDRV_TWIMST_H_

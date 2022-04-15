#ifndef _UHAL_TWIMST_H_
#define _UHAL_TWIMST_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "pin_define.h"
#include "udrv_twimst.h"
#include "udrv_errno.h"

#include "stm32wlxx_hal.h"

void uhal_twimst_init(udrv_twimst_port port);
void uhal_twimst_deinit(udrv_twimst_port port);
void uhal_twimst_setup_freq(udrv_twimst_port port, uint32_t clk_Hz);
int32_t uhal_twimst_write(udrv_twimst_port port, uint8_t twi_addr, uint8_t *data, uint16_t len, bool send_stop);
int32_t uhal_twimst_read(udrv_twimst_port port, uint8_t twi_addr, uint8_t * data, uint16_t len);
void uhal_twimst_suspend(void);
void uhal_twimst_resume(void);
#endif  // #ifndef _UHAL_TWIMST_H_

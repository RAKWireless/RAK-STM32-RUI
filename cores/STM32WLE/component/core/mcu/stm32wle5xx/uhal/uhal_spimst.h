#ifndef _UHAL_SPIMST_H_
#define _UHAL_SPIMST_H_

#include <stdint.h>
#include <stddef.h>
#include "pin_define.h"
#include "udrv_spimst.h"

void uhal_spimst_init(udrv_spimst_port port);
void uhal_spimst_setup_mode(udrv_spimst_port port, ENUM_SPI_MST_CPHA_T CPHA, ENUM_SPI_MST_CPOL_T CPOL);
void uhal_spimst_setup_freq(udrv_spimst_port port, uint32_t clk_Hz);
void uhal_spimst_setup_byte_order(udrv_spimst_port port, bool msb_first);
void uhal_spimst_deinit(udrv_spimst_port port);
int8_t uhal_spimst_trx(udrv_spimst_port port, uint8_t *write_data, uint32_t write_length, uint8_t *read_data, uint32_t read_length, uint32_t csn);
void uhal_spimst_suspend(void);
void uhal_spimst_resume(void);
#endif  // #ifndef _UHAL_SPIMST_H_

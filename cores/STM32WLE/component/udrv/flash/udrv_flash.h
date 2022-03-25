/**
 * @file        udrv_flash.h
 * @brief       Provide a hardware independent flash driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.5
 */

#ifndef __UDRV_FLASH_H__
#define __UDRV_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"

void udrv_flash_init (void);

void udrv_flash_deinit (void);

int32_t udrv_flash_write (uint32_t addr, uint32_t len, uint8_t *buff);

int32_t udrv_flash_read (uint32_t addr, uint32_t len, uint8_t *buff);

int32_t udrv_flash_erase (uint32_t addr, uint32_t len);

uint32_t udrv_flash_get_page_size(void);

bool udrv_flash_check_addr_valid(uint32_t addr, uint32_t len);

void udrv_flash_suspend(void);

void udrv_flash_resume(void);

#ifdef __cplusplus
}
#endif

#endif  // __UDRV_FLASH_H__


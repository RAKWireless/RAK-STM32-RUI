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

typedef enum {
    UDRV_FLASH_EVENT_WRITE_START = 0,
    UDRV_FLASH_EVENT_WRITE_COMPLETE,
} udrv_flash_event_t;

typedef struct {
    uint32_t address;
    uint32_t length;
    int32_t result;
} udrv_flash_status_t;

typedef void (*udrv_flash_callback_t)(udrv_flash_event_t event,
                                     const udrv_flash_status_t *status);

void udrv_flash_init (void);

void udrv_flash_deinit (void);

int32_t udrv_flash_register_callback(udrv_flash_callback_t callback);

int32_t udrv_flash_write (uint32_t addr, uint32_t len, uint8_t *buff);

/** Program an already-erased, 8-byte-aligned Flash range without erasing. */
int32_t udrv_flash_program(uint32_t addr, uint32_t len, uint8_t *buff);

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


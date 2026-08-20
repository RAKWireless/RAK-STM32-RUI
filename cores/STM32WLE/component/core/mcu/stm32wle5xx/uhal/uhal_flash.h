#ifndef _UHAL_FLASH_H_
#define _UHAL_FLASH_H_

#include <stdint.h>
#include <stddef.h>
#include "udrv_flash.h"
#include "udrv_errno.h"
#include "stm32wlxx_hal.h"

void uhal_flash_init (void);

void uhal_flash_deinit (void);

int32_t uhal_flash_write (uint32_t addr, uint8_t *buff, uint32_t len);

int32_t uhal_flash_read (uint32_t addr, uint8_t *buff, uint32_t len);

int32_t uhal_flash_erase (uint32_t addr, uint32_t len);

uint32_t uhal_flash_get_page_size(void);

bool uhal_flash_check_addr_valid(uint32_t addr, uint32_t len);

void uhal_flash_suspend(void);

void uhal_flash_resume(void);

#ifndef RUI_BOOTLOADER
bool uhal_flash_eccd_nmi_handler(void);

void uhal_flash_eccd_early_recovery(void);

void uhal_flash_eccd_log_recovery(void);

bool uhal_flash_eccd_get_pending(uint32_t *page_address,
                                  uint32_t *fault_address);

void uhal_flash_eccd_complete_lora_recovery(int32_t result);


#endif

#endif  // #ifndef _UHAL_FLASH_H_

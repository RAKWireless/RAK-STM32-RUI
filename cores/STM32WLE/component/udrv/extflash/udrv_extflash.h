/**
 * @file    udrv_extflash.h
 * @brief   uDRV external flash interface (platform-independent API)
 *
 * Layering:
 *  - Application calls udrv_extflash_* only.
 *  - uHAL (platform-specific) implements actual SPI NOR access.
 *  - System power manager calls udrv_extflash_pm_suspend/resume (SYSTEM ONLY).
 */

#ifndef _UDRV_EXTFLASH_H_
#define _UDRV_EXTFLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*  Types                                                                      */
/* -------------------------------------------------------------------------- */

typedef enum {
    EXTFLASH_OK = 0,
    EXTFLASH_ERR_PARAM,
    EXTFLASH_ERR_TIMEOUT,
    EXTFLASH_ERR_HW,
    EXTFLASH_ERR_STATE,     /* e.g. called while suspended */
} EXTFLASH_STATUS_t;

typedef struct
{
    uint32_t total_size;      /* bytes */
    uint32_t sector_size;     /* bytes (typically 0x1000) */
    uint32_t page_size;       /* bytes (typically 256) */
    uint8_t  jedec_id[3];     /* manufacturer / memory type / capacity */
} EXTFLASH_INFO_t;

/* -------------------------------------------------------------------------- */
/*  Public API (Application)                                                   */
/* -------------------------------------------------------------------------- */

/**
 * @brief Initialize extflash service (expected once at system boot).
 * @param info Optional output info.
 * @return UDRV_RETURN_OK, UDRV_ALREADY_INIT, UDRV_INTERNAL_ERR, ...
 */
void udrv_extflash_init(void);

/**
 * @brief Query cached extflash info after init.
 */
int32_t udrv_extflash_get_info(EXTFLASH_INFO_t *info);

int32_t udrv_extflash_read(uint32_t addr, uint8_t *buf, uint32_t len);
int32_t udrv_extflash_write(uint32_t addr, const uint8_t *data, uint32_t len);

int32_t udrv_extflash_erase_sector(uint32_t addr);
int32_t udrv_extflash_chip_erase(void);

/* Partition erase helpers */
int32_t udrv_extflash_erase_bank_a(void);
int32_t udrv_extflash_erase_bank_b(void);
int32_t udrv_extflash_erase_log(void);

/* -------------------------------------------------------------------------- */
/*  System-only power hooks (called from udrv_powersave.c)                     */
/*  DO NOT call these from application.                                        */
/* -------------------------------------------------------------------------- */
int32_t udrv_extflash_pm_suspend(void);
int32_t udrv_extflash_pm_resume(void);

#ifdef __cplusplus
}
#endif

#endif /* _UDRV_EXTFLASH_H_ */


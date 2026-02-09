/**
 * @file    uhal_extflash.h
 * @brief   External SPI NOR Flash uHAL driver (STM32WLE5xx, SPI2)
 *
 * Design policy:
 *  - Application layer SHALL NOT control Deep Power-Down (DP) nor SPI2 clock gating.
 *  - System power manager (uDRV powersave) calls pm_suspend/pm_resume hooks.
 *  - uhal_extflash_init() is expected to be called once at boot.
 */

#ifndef _UHAL_EXTFLASH_H_
#define _UHAL_EXTFLASH_H_

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "udrv_extflash.h"

/* -------------------------------------------------------------------------- */
/*  External flash partition defines (per current design)                      */
/* -------------------------------------------------------------------------- */
/* Bank A/B for FUOTA staging (simulate dual image), Log for debug */
#ifndef EXTFLASH_BANK_SIZE
#define EXTFLASH_BANK_SIZE           0x032000u
#endif

#ifndef EXTFLASH_BANKA_ADDR
#define EXTFLASH_BANKA_ADDR          0x000000u
#endif
#ifndef EXTFLASH_BANKA_INFO_ADDR
#define EXTFLASH_BANKA_INFO_ADDR     (EXTFLASH_BANKA_ADDR)
#endif
#ifndef EXTFLASH_BANKA_HEAD_ADDR
#define EXTFLASH_BANKA_HEAD_ADDR     (EXTFLASH_BANKA_ADDR + 0x1000u)
#endif

#ifndef EXTFLASH_BANKB_ADDR
#define EXTFLASH_BANKB_ADDR          0x032000u
#endif
#ifndef EXTFLASH_BANKB_INFO_ADDR
#define EXTFLASH_BANKB_INFO_ADDR     (EXTFLASH_BANKB_ADDR)
#endif
#ifndef EXTFLASH_BANKB_HEAD_ADDR
#define EXTFLASH_BANKB_HEAD_ADDR     (EXTFLASH_BANKB_ADDR + 0x1000u)
#endif

/* User define block, eg Log storage */
#ifndef EXTFLASH_LOG_SIZE
#define EXTFLASH_LOG_SIZE            0x01C000u
#endif
#ifndef EXTFLASH_LOG_ADDR
#define EXTFLASH_LOG_ADDR            0x064000u
#endif

/* Optional sanity check for 512KB device (0x080000). */
#ifndef EXTFLASH_TOTAL_SIZE_BYTES
#define EXTFLASH_TOTAL_SIZE_BYTES   0x080000u
#endif
#if ((EXTFLASH_LOG_ADDR + EXTFLASH_LOG_SIZE) > EXTFLASH_TOTAL_SIZE_BYTES)
#error "EXTFLASH layout exceeds EXTFLASH_TOTAL_SIZE_BYTES"
#endif

/* -------------------------------------------------------------------------- */
/*  Types                                                                      */
/* -------------------------------------------------------------------------- */
#if 0
typedef enum {
    UHAL_EXTFLASH_OK = 0,
    UHAL_EXTFLASH_ERR_PARAM,
    UHAL_EXTFLASH_ERR_TIMEOUT,
    UHAL_EXTFLASH_ERR_HW,
    UHAL_EXTFLASH_ERR_STATE,     /* e.g. called while suspended */
    UHAL_EXTFLASH_ERR_UNINIT,
} uhal_extflash_status_t;

typedef struct {
    uint32_t total_size;   /* bytes */
    uint32_t sector_size;  /* bytes (typically 0x1000) */
    uint32_t page_size;    /* bytes (typically 256) */
    uint8_t  jedec_id[3];  /* manufacturer / memory type / capacity */
} EXTFLASH_INFO_t;
#endif
/* -------------------------------------------------------------------------- */
/*  Public API (Application-visible)                                           */
/* -------------------------------------------------------------------------- */

/**
 * @brief Initialize extflash driver. Expected to be called once at system boot.
 * @param info Optional output info pointer.
 */
EXTFLASH_STATUS_t uhal_extflash_init(EXTFLASH_INFO_t *info);

EXTFLASH_STATUS_t uhal_extflash_get_info(EXTFLASH_INFO_t *info);

EXTFLASH_STATUS_t uhal_extflash_read(uint32_t addr, uint8_t *buf, uint32_t len);
EXTFLASH_STATUS_t uhal_extflash_write(uint32_t addr, const uint8_t *data, uint32_t len);

EXTFLASH_STATUS_t uhal_extflash_erase_sector(uint32_t addr);
EXTFLASH_STATUS_t uhal_extflash_erase_range(uint32_t addr, uint32_t len);
EXTFLASH_STATUS_t uhal_extflash_chip_erase(void);

/* Partition erase helpers */
EXTFLASH_STATUS_t uhal_extflash_erase_bank_a(void);
EXTFLASH_STATUS_t uhal_extflash_erase_bank_b(void);
EXTFLASH_STATUS_t uhal_extflash_erase_log(void);

/* -------------------------------------------------------------------------- */
/*  System-only PM hooks (called from udrv_powersave.c)                        */
/* -------------------------------------------------------------------------- */
/**
 * @brief Prepare external flash for system sleep:
 *        - wait busy (best-effort)
 *        - enter Deep Power-Down
 *        - keep CS/WP/RST stable high
 *        - disable SPI2 clock
 *        - reset SPI2 peripheral + reset HAL handle state
 */
EXTFLASH_STATUS_t uhal_extflash_pm_suspend(void);

/**
 * @brief Restore external flash after wake:
 *        - enable SPI2 clock
 *        - re-init SPI (ensure MSPInit runs)
 *        - exit Deep Power-Down
 */
EXTFLASH_STATUS_t uhal_extflash_pm_resume(void);

#endif  // #ifndef _UHAL_EXTFLASH_H_

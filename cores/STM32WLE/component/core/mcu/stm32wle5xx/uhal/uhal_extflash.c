/**
 * @file    uhal_extflash.c
 * @brief   External SPI NOR Flash uHAL driver (STM32WLE5xx, SPI2)
 */

#include "uhal_extflash.h"
#include "stm32wlxx_hal.h"

/* -------------------------------------------------------------------------- */
/*  Board-specific pin/instance definitions                                    */
/* -------------------------------------------------------------------------- */

#ifndef EXTFLASH_SPI_INSTANCE
#define EXTFLASH_SPI_INSTANCE         SPI2
#endif

#ifndef EXTFLASH_CS_PORT
#define EXTFLASH_CS_PORT              GPIOB
#define EXTFLASH_CS_PIN               GPIO_PIN_9
#endif

#ifndef EXTFLASH_WP_PORT
#define EXTFLASH_WP_PORT              GPIOC
#define EXTFLASH_WP_PIN               GPIO_PIN_0
#endif

#ifndef EXTFLASH_RST_PORT
#define EXTFLASH_RST_PORT             GPIOC
#define EXTFLASH_RST_PIN              GPIO_PIN_3
#endif

/* Device defaults (MX25L4006E: 4Mbit = 512KB) */
#ifndef EXTFLASH_DEFAULT_TOTAL_SIZE
#define EXTFLASH_DEFAULT_TOTAL_SIZE   (512u * 1024u)
#endif

#ifndef EXTFLASH_DEFAULT_SECTOR_SIZE
#define EXTFLASH_DEFAULT_SECTOR_SIZE  (4u * 1024u)
#endif

#ifndef EXTFLASH_DEFAULT_PAGE_SIZE
#define EXTFLASH_DEFAULT_PAGE_SIZE    (256u)
#endif

/* Timeouts (ms) */
#define EXTFLASH_SPI_TIMEOUT_MS       100u
#define EXTFLASH_WRITE_TIMEOUT_MS     3000u
#define EXTFLASH_ERASE_TIMEOUT_MS     10000u

/* -------------------------------------------------------------------------- */
/*  JEDEC-compatible command set                                               */
/* -------------------------------------------------------------------------- */
#define CMD_READ_ID                   0x9Fu
#define CMD_READ_DATA                 0x03u
#define CMD_PAGE_PROGRAM              0x02u
#define CMD_WRITE_ENABLE              0x06u
#define CMD_READ_STATUS1              0x05u
#define CMD_SECTOR_ERASE_4K           0x20u
#define CMD_CHIP_ERASE                0xC7u
#define CMD_DEEP_POWERDOWN            0xB9u
#define CMD_RELEASE_FROM_DPD          0xABu

#define STATUS1_BUSY_MASK             0x01u

#define EXTFLASH_CS_LOW()    HAL_GPIO_WritePin(EXTFLASH_CS_PORT, EXTFLASH_CS_PIN, GPIO_PIN_RESET)
#define EXTFLASH_CS_HIGH()   HAL_GPIO_WritePin(EXTFLASH_CS_PORT, EXTFLASH_CS_PIN, GPIO_PIN_SET)

#define EXTFLASH_WP_HIGH()   HAL_GPIO_WritePin(EXTFLASH_WP_PORT, EXTFLASH_WP_PIN, GPIO_PIN_SET)
#define EXTFLASH_RST_HIGH()  HAL_GPIO_WritePin(EXTFLASH_RST_PORT, EXTFLASH_RST_PIN, GPIO_PIN_SET)

/* -------------------------------------------------------------------------- */
/*  Driver state                                                               */
/* -------------------------------------------------------------------------- */

typedef enum {
    EXTFLASH_STATE_UNINIT = 0,
    EXTFLASH_STATE_ACTIVE,
    EXTFLASH_STATE_SUSPENDED,
} extflash_state_t;

static SPI_HandleTypeDef      s_extflash_spi;
static EXTFLASH_INFO_t        s_extflash_info;
static extflash_state_t       s_state = EXTFLASH_STATE_UNINIT;
static bool                   s_in_dp = false;

/* -------------------------------------------------------------------------- */
/*  Local helpers                                                              */
/* -------------------------------------------------------------------------- */

static void extflash_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* CS -> output, idle high */
    GPIO_InitStruct.Pin   = EXTFLASH_CS_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(EXTFLASH_CS_PORT, &GPIO_InitStruct);
    EXTFLASH_CS_HIGH();

    /* WP / RST -> output, default high */
    GPIO_InitStruct.Pin   = EXTFLASH_WP_PIN | EXTFLASH_RST_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(EXTFLASH_WP_PORT, &GPIO_InitStruct);

    EXTFLASH_WP_HIGH();
    EXTFLASH_RST_HIGH();
}

/**
 * Ensure SPI2 is initialized and usable.
 * Note: We must NOT rely on "HAL_SPI_Init()" doing work unless handle state is RESET,
 * because MSPInit/clock enable is typically gated by handle state.
 */
static EXTFLASH_STATUS_t extflash_spi_ensure_ready(void)
{
    HAL_StatusTypeDef hs;

    /* If system PM disabled SPI2 clock, enable it here (PM resume does this too). */
    __HAL_RCC_SPI2_CLK_ENABLE();

    /* Force HAL to run full init/MSPInit by resetting handle state. */
    s_extflash_spi.State = HAL_SPI_STATE_RESET;
    s_extflash_spi.ErrorCode = HAL_SPI_ERROR_NONE;

    s_extflash_spi.Instance               = EXTFLASH_SPI_INSTANCE;
    s_extflash_spi.Init.Mode              = SPI_MODE_MASTER;
    s_extflash_spi.Init.Direction         = SPI_DIRECTION_2LINES;
    s_extflash_spi.Init.DataSize          = SPI_DATASIZE_8BIT;
    s_extflash_spi.Init.CLKPolarity       = SPI_POLARITY_LOW;
    s_extflash_spi.Init.CLKPhase          = SPI_PHASE_1EDGE;
    s_extflash_spi.Init.NSS               = SPI_NSS_SOFT;
    s_extflash_spi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
    s_extflash_spi.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    s_extflash_spi.Init.TIMode            = SPI_TIMODE_DISABLE;
    s_extflash_spi.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
    s_extflash_spi.Init.CRCPolynomial     = 7;

    hs = HAL_SPI_Init(&s_extflash_spi);
    if (hs != HAL_OK) {
        return EXTFLASH_ERR_HW;
    }
    return EXTFLASH_OK;
}

static EXTFLASH_STATUS_t extflash_write_enable(void)
{
    uint8_t cmd = CMD_WRITE_ENABLE;

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();
    return EXTFLASH_OK;
}

static EXTFLASH_STATUS_t extflash_wait_busy(uint32_t timeout_ms)
{
    uint8_t cmd = CMD_READ_STATUS1;
    uint8_t status;
    uint32_t start = HAL_GetTick();

    do {
        EXTFLASH_CS_LOW();
        if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
            EXTFLASH_CS_HIGH();
            return EXTFLASH_ERR_TIMEOUT;
        }
        if (HAL_SPI_Receive(&s_extflash_spi, &status, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
            EXTFLASH_CS_HIGH();
            return EXTFLASH_ERR_TIMEOUT;
        }
        EXTFLASH_CS_HIGH();

        if ((status & STATUS1_BUSY_MASK) == 0u) {
            return EXTFLASH_OK;
        }
    } while ((HAL_GetTick() - start) < timeout_ms);

    return EXTFLASH_ERR_TIMEOUT;
}

/* DP control is PRIVATE (system/app must not call directly) */
static EXTFLASH_STATUS_t extflash_enter_dp(void)
{
    uint8_t cmd = CMD_DEEP_POWERDOWN;

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    s_in_dp = true;
    return EXTFLASH_OK;
}

static EXTFLASH_STATUS_t extflash_exit_dp(void)
{
    uint8_t cmd = CMD_RELEASE_FROM_DPD;

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    /* typical tRES1/tRES2 ~ few us to ms; keep 1ms conservative */
    HAL_Delay(1);
    s_in_dp = false;
    return EXTFLASH_OK;
}

/* Common guard for I/O APIs */
static inline bool extflash_io_allowed(void)
{
    return (s_state == EXTFLASH_STATE_ACTIVE) && (s_in_dp == false);
}

/* -------------------------------------------------------------------------- */
/*  Public APIs                                                                */
/* -------------------------------------------------------------------------- */

EXTFLASH_STATUS_t uhal_extflash_init(EXTFLASH_INFO_t *info)
{
    EXTFLASH_STATUS_t st;
    uint8_t cmd;
    uint8_t id[3];

    if (s_state != EXTFLASH_STATE_UNINIT) {
        /* already initialized */
        if (info) { *info = s_extflash_info; }
        return EXTFLASH_OK;
    }

    extflash_gpio_init();

    st = extflash_spi_ensure_ready();
    if (st != EXTFLASH_OK) {
        return st;
    }

    /* Ensure out of DP (safe even if not in DP) */
    (void)extflash_exit_dp();

    /* Read JEDEC ID */
    cmd = CMD_READ_ID;
    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    if (HAL_SPI_Receive(&s_extflash_spi, id, sizeof(id), EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    s_extflash_info.total_size  = EXTFLASH_DEFAULT_TOTAL_SIZE;
    s_extflash_info.sector_size = EXTFLASH_DEFAULT_SECTOR_SIZE;
    s_extflash_info.page_size   = EXTFLASH_DEFAULT_PAGE_SIZE;
    s_extflash_info.jedec_id[0] = id[0];
    s_extflash_info.jedec_id[1] = id[1];
    s_extflash_info.jedec_id[2] = id[2];

    s_state = EXTFLASH_STATE_ACTIVE;
    s_in_dp = false;

    if (info) {
        *info = s_extflash_info;
    }
    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_get_info(EXTFLASH_INFO_t *info)
{
    if ((s_state == EXTFLASH_STATE_UNINIT) || (info == NULL)) {
        return EXTFLASH_ERR_PARAM;
    }
    *info = s_extflash_info;
    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_read(uint32_t addr, uint8_t *buf, uint32_t len)
{
    uint8_t cmd[4];

    if ((buf == NULL) || (len == 0u)) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_ERR_STATE;
    }
    if (!extflash_io_allowed()) {
        return EXTFLASH_ERR_HW;
    }

    cmd[0] = CMD_READ_DATA;
    cmd[1] = (uint8_t)((addr >> 16) & 0xFFu);
    cmd[2] = (uint8_t)((addr >> 8) & 0xFFu);
    cmd[3] = (uint8_t)(addr & 0xFFu);

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, cmd, sizeof(cmd), EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    if (HAL_SPI_Receive(&s_extflash_spi, buf, len, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_write(uint32_t addr, const uint8_t *data, uint32_t len)
{
    EXTFLASH_STATUS_t status;
    uint32_t remaining = len;
    uint32_t current_addr = addr;
    const uint8_t *current_data = data;

    if ((data == NULL) || (len == 0u)) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_ERR_STATE;
    }
    if (!extflash_io_allowed()) {
        return EXTFLASH_ERR_HW;
    }

    while (remaining > 0u) {
        uint32_t page_off   = current_addr % s_extflash_info.page_size;
        uint32_t page_space = s_extflash_info.page_size - page_off;
        uint32_t chunk      = (remaining < page_space) ? remaining : page_space;

        status = extflash_write_enable();
        if (status != EXTFLASH_OK) {
            return status;
        }

        uint8_t cmd[4];
        cmd[0] = CMD_PAGE_PROGRAM;
        cmd[1] = (uint8_t)((current_addr >> 16) & 0xFFu);
        cmd[2] = (uint8_t)((current_addr >> 8) & 0xFFu);
        cmd[3] = (uint8_t)(current_addr & 0xFFu);

        EXTFLASH_CS_LOW();
        if (HAL_SPI_Transmit(&s_extflash_spi, cmd, sizeof(cmd), EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
            EXTFLASH_CS_HIGH();
            return EXTFLASH_ERR_TIMEOUT;
        }
        if (HAL_SPI_Transmit(&s_extflash_spi, (uint8_t *)current_data, chunk, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
            EXTFLASH_CS_HIGH();
            return EXTFLASH_ERR_TIMEOUT;
        }
        EXTFLASH_CS_HIGH();

        status = extflash_wait_busy(EXTFLASH_WRITE_TIMEOUT_MS);
        if (status != EXTFLASH_OK) {
            return status;
        }

        current_addr += chunk;
        current_data += chunk;
        remaining    -= chunk;
    }

    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_erase_sector(uint32_t addr)
{
    EXTFLASH_STATUS_t status;
    uint8_t cmd[4];
    uint32_t sector_addr;

    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_ERR_STATE;
    }
    if (!extflash_io_allowed()) {
        return EXTFLASH_ERR_HW;
    }

    sector_addr = addr - (addr % s_extflash_info.sector_size);

    status = extflash_write_enable();
    if (status != EXTFLASH_OK) {
        return status;
    }

    cmd[0] = CMD_SECTOR_ERASE_4K;
    cmd[1] = (uint8_t)((sector_addr >> 16) & 0xFFu);
    cmd[2] = (uint8_t)((sector_addr >> 8) & 0xFFu);
    cmd[3] = (uint8_t)(sector_addr & 0xFFu);

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, cmd, sizeof(cmd), EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    return extflash_wait_busy(EXTFLASH_ERASE_TIMEOUT_MS);
}

/* Erase a region by sector */
EXTFLASH_STATUS_t uhal_extflash_erase_range(uint32_t addr, uint32_t len)
{
    EXTFLASH_STATUS_t st;
    uint32_t start;
    uint32_t end;
    uint32_t sector_sz = s_extflash_info.sector_size;

    if (len == 0u) {
        return EXTFLASH_OK;
    }
    if (sector_sz == 0u) {
        return EXTFLASH_ERR_HW;
    }

    start = addr - (addr % sector_sz);
    end = addr + len;
    if ((end % sector_sz) != 0u) {
        end += (sector_sz - (end % sector_sz));
    }

    if (end > s_extflash_info.total_size) {
        return EXTFLASH_ERR_PARAM;
    }

    for (uint32_t a = start; a < end; a += sector_sz) {
        st = uhal_extflash_erase_sector(a);
        if (st != EXTFLASH_OK) {
            return st;
        }
    }
    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_chip_erase(void)
{
    EXTFLASH_STATUS_t status;
    uint8_t cmd = CMD_CHIP_ERASE;

    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_ERR_PARAM;
    }
    if (s_state == EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_ERR_STATE;
    }
    if (!extflash_io_allowed()) {
        return EXTFLASH_ERR_HW;
    }

    status = extflash_write_enable();
    if (status != EXTFLASH_OK) {
        return status;
    }

    EXTFLASH_CS_LOW();
    if (HAL_SPI_Transmit(&s_extflash_spi, &cmd, 1, EXTFLASH_SPI_TIMEOUT_MS) != HAL_OK) {
        EXTFLASH_CS_HIGH();
        return EXTFLASH_ERR_TIMEOUT;
    }
    EXTFLASH_CS_HIGH();

    return extflash_wait_busy(EXTFLASH_ERASE_TIMEOUT_MS);
}

EXTFLASH_STATUS_t uhal_extflash_erase_bank_a(void)
{
    if (s_state == EXTFLASH_STATE_SUSPENDED) return EXTFLASH_ERR_STATE;
    return uhal_extflash_erase_range(EXTFLASH_BANKA_ADDR, EXTFLASH_BANK_SIZE);
}

EXTFLASH_STATUS_t uhal_extflash_erase_bank_b(void)
{
    if (s_state == EXTFLASH_STATE_SUSPENDED) return EXTFLASH_ERR_STATE;
    return uhal_extflash_erase_range(EXTFLASH_BANKB_ADDR, EXTFLASH_BANK_SIZE);
}

EXTFLASH_STATUS_t uhal_extflash_erase_log(void)
{
    if (s_state == EXTFLASH_STATE_SUSPENDED) return EXTFLASH_ERR_STATE;
    return uhal_extflash_erase_range(EXTFLASH_LOG_ADDR, EXTFLASH_LOG_SIZE);
}

/* -------------------------------------------------------------------------- */
/*  System-only PM hooks                                                       */
/* -------------------------------------------------------------------------- */

EXTFLASH_STATUS_t uhal_extflash_pm_suspend(void)
{
    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_OK;
    }
    if (s_state == EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_OK;
    }

    /* Best-effort wait busy */
    (void)extflash_wait_busy(EXTFLASH_WRITE_TIMEOUT_MS);

    /* Enter deep power-down */
    if (!s_in_dp) {
        (void)extflash_enter_dp();
    }

    /* Keep control pins stable high (avoid floating leakage) */
    EXTFLASH_CS_HIGH();
    EXTFLASH_WP_HIGH();
    EXTFLASH_RST_HIGH();

    /* Disable SPI2 IRQ if used */
    HAL_NVIC_DisableIRQ(SPI2_IRQn);
    HAL_NVIC_ClearPendingIRQ(SPI2_IRQn);
#if 0
    /* Reset SPI2 peripheral to clear state (does not touch GPIO) */
    __HAL_RCC_SPI2_FORCE_RESET();
    __HAL_RCC_SPI2_RELEASE_RESET();
#endif
    /* Disable SPI2 clock for lowest power */
    __HAL_RCC_SPI2_CLK_DISABLE();

    /* Force next HAL_SPI_Init to run MSPInit/clock enable path */
    s_extflash_spi.State = HAL_SPI_STATE_RESET;
    s_extflash_spi.ErrorCode = HAL_SPI_ERROR_NONE;

    s_state = EXTFLASH_STATE_SUSPENDED;
    return EXTFLASH_OK;
}

EXTFLASH_STATUS_t uhal_extflash_pm_resume(void)
{
    EXTFLASH_STATUS_t st;

    if (s_state == EXTFLASH_STATE_UNINIT) {
        return EXTFLASH_OK;
    }
    if (s_state != EXTFLASH_STATE_SUSPENDED) {
        return EXTFLASH_OK;
    }

    /* Re-enable SPI2 clock and init SPI (ensure MSPInit runs) */
#if 1
    st = extflash_spi_ensure_ready();
    if (st != EXTFLASH_OK) {
        return st;
    }
#endif

    /* Exit deep power-down so app can use extflash immediately */
    if (s_in_dp) {
        (void)extflash_exit_dp();
    } else {
        /* even if flag not set, safe to send release */
        (void)extflash_exit_dp();
    }

    s_state = EXTFLASH_STATE_ACTIVE;
    return EXTFLASH_OK;
}


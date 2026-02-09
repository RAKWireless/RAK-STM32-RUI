/**
 * @file    udrv_extflash.c
 * @brief   uDRV external flash interface (platform-independent API)
 */

#ifdef SUPPORT_EXTFLASH

#include "udrv_extflash.h"
#include "uhal_extflash.h"
#include "udrv_errno.h"
#include <stddef.h>

/* uDRV init state */
static bool s_udrv_extflash_inited = false;

/* -------------------------------------------------------------------------- */
/*  Mapping: uHAL status -> uDRV return code                                   */
/* -------------------------------------------------------------------------- */
static UDRV_RETURN_CODE _map_uhal_to_udrv(EXTFLASH_STATUS_t st)
{
    switch (st)
    {
    case EXTFLASH_OK:
        return UDRV_RETURN_OK;

    case EXTFLASH_ERR_PARAM:
        return UDRV_WRONG_ARG;

    case EXTFLASH_ERR_TIMEOUT:
        /* timeout can be "busy" (erase/program) or SPI transfer timeout */
        return UDRV_BUSY;

    case EXTFLASH_ERR_STATE:
        /* typically called while suspended by system powersave */
        return UDRV_TEMP_LOCKED;

    case EXTFLASH_ERR_HW:
    default:
        return UDRV_INTERNAL_ERR;
    }
}

/* Convert info struct (keep uDRV independent from uHAL layout changes) */
static void _copy_info(EXTFLASH_INFO_t *dst, const EXTFLASH_INFO_t *src)
{
    dst->total_size  = src->total_size;
    dst->sector_size = src->sector_size;
    dst->page_size   = src->page_size;
    dst->jedec_id[0] = src->jedec_id[0];
    dst->jedec_id[1] = src->jedec_id[1];
    dst->jedec_id[2] = src->jedec_id[2];
}

/* -------------------------------------------------------------------------- */
/*  Public API (Application)                                                   */
/* -------------------------------------------------------------------------- */


void udrv_extflash_init(void)
{
    EXTFLASH_INFO_t uinfo;
    EXTFLASH_STATUS_t st;

    if (s_udrv_extflash_inited)
    {
        /* already init: return OK */
        return UDRV_ALREADY_INIT;
    }

    st = uhal_extflash_init(&uinfo);
    if (st != EXTFLASH_OK)
    {
        return _map_uhal_to_udrv(st);
    }

    s_udrv_extflash_inited = true;

    return UDRV_RETURN_OK;
}

int32_t udrv_extflash_get_info(EXTFLASH_INFO_t *info)
{
    EXTFLASH_INFO_t uinfo;
    EXTFLASH_STATUS_t st;

    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    if (info == NULL)
    {
        return UDRV_WRONG_ARG;
    }

    st = uhal_extflash_get_info(&uinfo);
    if (st != EXTFLASH_OK)
    {
        return _map_uhal_to_udrv(st);
    }

    _copy_info(info, &uinfo);
    return UDRV_RETURN_OK;
}

int32_t udrv_extflash_read(uint32_t addr, uint8_t *buf, uint32_t len)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    if ((buf == NULL) || (len == 0u))
    {
        return UDRV_WRONG_ARG;
    }

    return _map_uhal_to_udrv(uhal_extflash_read(addr, buf, len));
}

int32_t udrv_extflash_write(uint32_t addr, const uint8_t *data, uint32_t len)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    if ((data == NULL) || (len == 0u))
    {
        return UDRV_WRONG_ARG;
    }

    return _map_uhal_to_udrv(uhal_extflash_write(addr, data, len));
}

int32_t udrv_extflash_erase_sector(uint32_t addr)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }

    return _map_uhal_to_udrv(uhal_extflash_erase_sector(addr));
}

int32_t udrv_extflash_chip_erase(void)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }

    return _map_uhal_to_udrv(uhal_extflash_chip_erase());
}

int32_t udrv_extflash_erase_bank_a(void)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    return _map_uhal_to_udrv(uhal_extflash_erase_bank_a());
}

int32_t udrv_extflash_erase_bank_b(void)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    return _map_uhal_to_udrv(uhal_extflash_erase_bank_b());
}

int32_t udrv_extflash_erase_log(void)
{
    if (!s_udrv_extflash_inited)
    {
        return UDRV_NOT_INIT;
    }
    return _map_uhal_to_udrv(uhal_extflash_erase_log());
}

/* -------------------------------------------------------------------------- */
/*  System-only power hooks (called from udrv_powersave.c)                     */
/* -------------------------------------------------------------------------- */

int32_t udrv_extflash_pm_suspend(void)
{
    /* If extflash never initialized, nothing to do */
    if (!s_udrv_extflash_inited)
    {
        return UDRV_RETURN_OK;
    }
    return _map_uhal_to_udrv(uhal_extflash_pm_suspend());
}

int32_t udrv_extflash_pm_resume(void)
{
    /* If extflash never initialized, nothing to do */
    if (!s_udrv_extflash_inited)
    {
        return UDRV_RETURN_OK;
    }
    return _map_uhal_to_udrv(uhal_extflash_pm_resume());
}

#endif //SUPPORT_EXTFLASH


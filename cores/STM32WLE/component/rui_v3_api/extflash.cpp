#include "extflash.h"

#ifdef SUPPORT_EXTFLASH

#include <stddef.h>
#include "udrv_extflash.h"

/* Default sector size fallback if info query fails */
#ifndef RAK_EXTFLASH_DEFAULT_SECTOR_SIZE
#define RAK_EXTFLASH_DEFAULT_SECTOR_SIZE 0x1000u
#endif

extflash::extflash(void)
{
    s_inited = false;
}

bool extflash::_ensure_init(void)
{
    if (s_inited)
    {
        return true;
    }

    /* uDRV extflash is expected to be initialized at system boot, but we keep
     * this wrapper robust by attempting init on first use.
     */
    udrv_extflash_init();
    s_inited = true;
    return true;
}

int32_t extflash::get(uint32_t addr, uint8_t *buf, uint32_t len)
{
    if (!_ensure_init())
    {
        return -1;
    }
    return udrv_extflash_read(addr, buf, len);
}

int32_t extflash::set(uint32_t addr, const uint8_t *data, uint32_t len)
{
    if (!_ensure_init())
    {
        return -1;
    }
    return udrv_extflash_write(addr, data, len);
}

int32_t extflash::info(RAK_EXTFLASH_INFO *info)
{
    if (!_ensure_init())
    {
        return -1;
    }
    return udrv_extflash_get_info((EXTFLASH_INFO_t *)info);
}

static uint32_t _align_down(uint32_t v, uint32_t a)
{
    if (a == 0u)
    {
        return v;
    }
    return (v / a) * a;
}

static uint32_t _align_up(uint32_t v, uint32_t a)
{
    if (a == 0u)
    {
        return v;
    }
    return ((v + a - 1u) / a) * a;
}

int32_t extflash::erase(uint32_t addr, uint32_t size)
{
    if (!_ensure_init())
    {
        return -1;
    }

    if (size == 0u)
    {
        /* Follow udrv behavior: treat as wrong argument if possible.
         * We cannot include udrv_errno.h here reliably in Arduino layer,
         * so use a generic negative return.
         */
        return -1;
    }

    EXTFLASH_INFO_t finfo;
    uint32_t sector_size = RAK_EXTFLASH_DEFAULT_SECTOR_SIZE;

    if (udrv_extflash_get_info(&finfo) == 0)
    {
        if (finfo.sector_size != 0u)
        {
            sector_size = finfo.sector_size;
        }

        if ((addr == 0u) && (size >= finfo.total_size) && (finfo.total_size != 0u))
        {
            return udrv_extflash_chip_erase();
        }
    }

    /* Expand to sector boundaries */
    uint32_t start = _align_down(addr, sector_size);
    uint32_t end   = _align_up(addr + size, sector_size);

    for (uint32_t a = start; a < end; a += sector_size)
    {
        int32_t rc = udrv_extflash_erase_sector(a);
        if (rc != 0)
        {
            return rc;
        }
    }

    return 0;
}

#endif /* SUPPORT_EXTFLASH */

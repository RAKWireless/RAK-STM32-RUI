#include <stdint.h>
#include "udrv_flash.h"
#include "uhal_flash.h"

bool udrv_flash_initialized = false;
#ifdef STM32WL55xx//XXX:4096 is too big for STM32WL
__attribute__((aligned(8))) static uint8_t page_buff[2048];
#elif PART_APOLLO3
__attribute__((aligned(8))) static uint8_t page_buff[8192];
#else
__attribute__((aligned(8))) static uint8_t page_buff[4096];
#endif

void udrv_flash_init (void) {
    if (udrv_flash_initialized == false) {
        uhal_flash_init();
        udrv_flash_initialized = true;
    }
}

void udrv_flash_deinit (void) {
    if (udrv_flash_initialized == true) {
        uhal_flash_deinit();
        udrv_flash_initialized = false;
    }
}
bool compare_page_buff(uint32_t addr,uint32_t len, uint8_t *buff)
{
    uint32_t page_size = udrv_flash_get_page_size();
    uint32_t buf_size = 1024;
    uint8_t flag = 0;
    uint8_t tmp_buff[buf_size];
    for(uint8_t i = 0;i<page_size/buf_size;i++)
    {
        if(len >= buf_size)
        {
            udrv_flash_read(addr + buf_size*i,buf_size,tmp_buff);
            if(memcmp(tmp_buff,buff + buf_size*i,buf_size) != 0)
                return false;
        }
        else
        {
            udrv_flash_read(addr + buf_size*i,len,tmp_buff);
            if(memcmp(tmp_buff,buff + buf_size*i,len) != 0)
                return false;
            break;
        }
        len -= buf_size;
    }
    return true;
}


int32_t udrv_flash_write (uint32_t addr, uint32_t len, uint8_t *buff) {
    uint32_t page_size = udrv_flash_get_page_size();
    uint32_t actual_addr, actual_len, curr_page, remaining;
    uint8_t *buffp;
#ifdef STM32WL55xx//XXX:4096 is too big for STM32WL
    if (page_size > 2048) {
#elif PART_APOLLO3
    if (page_size > 8192) {
#else
    if (page_size > 4096) {
#endif
        return -UDRV_BUFF_OVERFLOW;
    }

    if(compare_page_buff(addr,len,buff))
        return UDRV_RETURN_OK;

    if (addr % page_size != 0) {
        actual_addr = (addr / page_size) * page_size;
    } else {
        actual_addr = addr;
    }

    if ((len + (addr - actual_addr)) % page_size != 0) {
        actual_len = (((len + (addr - actual_addr)) / page_size) + 1) * page_size;
    } else {
        actual_len = len + (addr - actual_addr);
    }

    buffp = buff;
    remaining = len;
    for (curr_page = 0 ; curr_page < (actual_len/page_size) ; curr_page++) {
        uhal_flash_read(actual_addr + page_size*curr_page, page_buff, page_size);
        //handle the 1st page
        if (curr_page == 0) {
            if (len > (page_size - (addr - actual_addr))) {
                memcpy(page_buff+(addr - actual_addr), buffp, (page_size - (addr - actual_addr)));
                buffp += (page_size - (addr - actual_addr));
                remaining -= (page_size - (addr - actual_addr));
            } else {
                memcpy(page_buff+(addr - actual_addr), buffp, len);
                buffp += len;
                remaining -= len;
            }
        //handle the last page
        } else if ((curr_page) + 1 >= (actual_len/page_size) ) {
            memcpy(page_buff, buffp, remaining);
        } else {
            memcpy(page_buff, buffp, page_size);
            buffp += page_size;
            remaining -= page_size;
        }

        if (uhal_flash_erase(actual_addr + page_size*curr_page, page_size) != UDRV_RETURN_OK) {
            return -UDRV_INTERNAL_ERR;
        }

        if (uhal_flash_write(actual_addr + page_size*curr_page, page_buff, page_size) != UDRV_RETURN_OK) {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t udrv_flash_read (uint32_t addr, uint32_t len, uint8_t *buff) {
    uint32_t page_size = udrv_flash_get_page_size();
    uint32_t actual_addr, actual_len, curr_page, remaining;
    uint8_t *buffp;

#ifdef STM32WL55xx//XXX:4096 is too big for STM32WL
    if (page_size > 2048) {
#elif PART_APOLLO3
    if (page_size > 8192) {
#else
    if (page_size > 4096) {
#endif
        return -UDRV_BUFF_OVERFLOW;
    }

    if (addr % page_size != 0) {
        actual_addr = (addr / page_size) * page_size;
    } else {
        actual_addr = addr;
    }

    if ((len + (addr - actual_addr)) % page_size != 0) {
        actual_len = (((len + (addr - actual_addr)) / page_size) + 1) * page_size;
    } else {
        actual_len = len + (addr - actual_addr);
    }

    buffp = buff;
    remaining = len;
    for (curr_page = 0 ; curr_page < (actual_len/page_size) ; curr_page++) {
        uhal_flash_read(actual_addr + page_size*curr_page, page_buff, page_size);
        //handle the 1st page
        if (curr_page == 0) {
            if (len > (page_size - (addr - actual_addr))) {
                memcpy(buffp, page_buff+(addr - actual_addr), (page_size - (addr - actual_addr)));
                buffp += (page_size - (addr - actual_addr));
                remaining -= (page_size - (addr - actual_addr));
            } else {
                memcpy(buffp, page_buff+(addr - actual_addr), len);
                buffp += len;
                remaining -= len;
            }
        //handle the last page
        } else if ((curr_page) + 1 >= (actual_len/page_size) ) {
            memcpy(buffp, page_buff, remaining);
        } else {
            memcpy(buffp, page_buff, page_size);
            buffp += page_size;
            remaining -= page_size;
        }
    }

    return UDRV_RETURN_OK;
}

int32_t udrv_flash_erase (uint32_t addr, uint32_t len) {
    uint32_t page_size = udrv_flash_get_page_size();

    if (addr & 0x3) {
        return -UDRV_ADDR_NOT_ALIGNED;
    }

    if (len % page_size) {
        return -UDRV_LEN_NOT_ALIGNED;
    }

    return uhal_flash_erase(addr, len);
}

uint32_t udrv_flash_get_page_size(void) {
    return uhal_flash_get_page_size();
}

bool udrv_flash_check_addr_valid(uint32_t addr, uint32_t len) {
    return uhal_flash_check_addr_valid(addr, len);
}

void udrv_flash_suspend(void) {
    udrv_flash_suspend();
}

void udrv_flash_resume(void) {
    udrv_flash_resume();
}

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "udrv_flash.h"
#include "uhal_flash.h"
#ifndef RUI_BOOTLOADER
#include "udrv_serial.h"
#endif

bool udrv_flash_initialized = false;
static bool udrv_flash_write_in_progress = false;
static udrv_flash_callback_t udrv_flash_callback = NULL;
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

int32_t udrv_flash_register_callback(udrv_flash_callback_t callback)
{
    udrv_flash_callback = callback;
    return UDRV_RETURN_OK;
}

static void udrv_flash_notify(udrv_flash_event_t event,
                              const udrv_flash_status_t *status)
{
#ifndef RUI_BOOTLOADER
    if (event == UDRV_FLASH_EVENT_WRITE_START)
    {
        udrv_serial_log_printf(
            "+EVT:FLASH_WRITE_START,ADDR:0x%08lX,LEN:%lu\r\n",
            (unsigned long)status->address,
            (unsigned long)status->length);
    }
    else
    {
        udrv_serial_log_printf(
            "+EVT:FLASH_WRITE_DONE,ADDR:0x%08lX,LEN:%lu,RESULT:%ld\r\n",
            (unsigned long)status->address,
            (unsigned long)status->length,
            (long)status->result);
    }
#endif

    if (udrv_flash_callback != NULL)
    {
        udrv_flash_callback(event, status);
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
    int32_t ret = UDRV_RETURN_OK;
    udrv_flash_status_t status;

    if (udrv_flash_write_in_progress)
    {
        return -UDRV_BUSY;
    }
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
    status.address = actual_addr;
    status.length = actual_len;
    status.result = UDRV_RETURN_OK;
    udrv_flash_write_in_progress = true;
    udrv_flash_notify(UDRV_FLASH_EVENT_WRITE_START, &status);

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
            ret = -UDRV_INTERNAL_ERR;
            break;
        }

        if (uhal_flash_write(actual_addr + page_size*curr_page, page_buff, page_size) != UDRV_RETURN_OK) {
            ret = -UDRV_INTERNAL_ERR;
            break;
        }
    }

    status.result = ret;
    udrv_flash_notify(UDRV_FLASH_EVENT_WRITE_COMPLETE, &status);
    udrv_flash_write_in_progress = false;

    return ret;
}

int32_t udrv_flash_program(uint32_t addr, uint32_t len, uint8_t *buff)
{
    int32_t ret;
    udrv_flash_status_t status;

    if (udrv_flash_write_in_progress)
    {
        return -UDRV_BUSY;
    }

    if ((buff == NULL) || (len == 0U) ||
        ((addr & 0x7U) != 0U) || ((len & 0x7U) != 0U) ||
        ((((uintptr_t)buff) & 0x7U) != 0U))
    {
        return -UDRV_INTERNAL_ERR;
    }

    status.address = addr;
    status.length = len;
    status.result = UDRV_RETURN_OK;
    udrv_flash_write_in_progress = true;
    udrv_flash_notify(UDRV_FLASH_EVENT_WRITE_START, &status);

    ret = uhal_flash_write(addr, buff, len);
    if ((ret == UDRV_RETURN_OK) &&
        (memcmp((const void *)(uintptr_t)addr, buff, len) != 0))
    {
        ret = -UDRV_INTERNAL_ERR;
    }

    status.result = ret;
    udrv_flash_notify(UDRV_FLASH_EVENT_WRITE_COMPLETE, &status);
    udrv_flash_write_in_progress = false;
    return ret;
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

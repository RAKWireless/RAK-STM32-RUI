#ifdef SUPPORT_AT
#include <string.h>

#include "atcmd.h"
#include "atcmd_misc.h"
#include "udrv_errno.h"
#include "mcu_basic.h"
#ifdef RUI_BOOTLOADER
#include "service_nvm.h"
#endif

#ifndef RUI_BOOTLOADER
int At_Factory (SERIAL_PORT port, char *cmd, stParam *param) {
    if (param->argc == 0) {
        uint8_t buff[4096];

        udrv_flash_read(MCU_SYS_CONFIG_NVM_ADDR, udrv_flash_get_page_size(), buff);
        udrv_flash_erase(MCU_FACTORY_DEFAULT_NVM_ADDR, udrv_flash_get_page_size());
        udrv_flash_write(MCU_FACTORY_DEFAULT_NVM_ADDR, udrv_flash_get_page_size(), buff);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif

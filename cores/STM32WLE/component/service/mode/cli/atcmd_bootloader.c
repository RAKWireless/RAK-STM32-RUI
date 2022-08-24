#ifdef SUPPORT_AT
#include <string.h>

#include "atcmd.h"
#include "atcmd_bootloader.h"
#include "udrv_errno.h"
#include "mcu_basic.h"
#ifdef RUI_BOOTLOADER
#include "service_nvm.h"
#endif

#ifdef RUI_BOOTLOADER
int At_Bootstatus (SERIAL_PORT port, char *cmd, stParam *param) {
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("DFU mode\r\n");
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif

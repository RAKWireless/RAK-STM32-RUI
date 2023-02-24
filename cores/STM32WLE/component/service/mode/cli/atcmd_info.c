#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_info.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "service_lora_arssi.h"

int At_Rssi (SERIAL_PORT port, char *cmd, stParam *param) {
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_rssi());
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Arssi(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if(param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        chan_rssi iterator;
        int i = 0;
        atcmd_printf("%s=", cmd);
        while (service_lora_get_arssi(&iterator) == -UDRV_CONTINUE) {
            if (iterator.mask) {
                if(i++)
                {
                    atcmd_printf(",");
                }    
                atcmd_printf("%d:%d", iterator.chan, iterator.rssi);
            }
        }
        atcmd_printf("\r\n");
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
    
}

int At_Snr (SERIAL_PORT port, char *cmd, stParam *param) {
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_snr());
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif

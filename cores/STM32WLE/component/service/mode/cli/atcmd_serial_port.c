#ifdef SUPPORT_AT
#include <string.h>
#include "atcmd.h"
#include "atcmd_serial_port.h"
#include "udrv_errno.h"
#include "udrv_dfu.h"
#include "udrv_serial.h"
#include "service_mode.h"

int At_Lock (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("AT+LOCK=unlocked\r\n");

        return AT_OK;
    } else if (param->argc == 0) {
        udrv_serial_lock();

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Pword (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t passwd[9];
        int32_t len;

        if ((len = udrv_serial_get_passwd(passwd, 9)) > 0) {
            atcmd_printf("%s=", cmd);
            for(uint8_t i = 0 ; i < len ; i++) {
                atcmd_printf("%c", passwd[i]);
            }
            atcmd_printf("\r\n");

            return AT_OK;
	} else {
            return AT_ERROR;
	}
        
    } else if (param->argc == 1) {
        int32_t ret;

	if (strlen(param->argv[0]) == 0 || strlen(param->argv[0]) > 8) {
            return AT_PARAM_ERROR;
	}

        if ((ret = udrv_serial_set_passwd(param->argv[0], strlen(param->argv[0]))) == UDRV_RETURN_OK) {
            return AT_OK;
	} else if (ret == -UDRV_WRONG_ARG) {
            return AT_PARAM_ERROR;
	} else {
            return AT_ERROR;
	}
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Baud (SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_nvm_get_baudrate_from_nvm());
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t baud;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        baud = strtoul(param->argv[0], NULL, 10);
#ifdef stm32wle5xx
        if (baud > 115200)
            return AT_PARAM_ERROR;
#endif

        udrv_serial_init(port, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);

	ret = service_nvm_set_baudrate_to_nvm(baud);
        if (ret == UDRV_RETURN_OK) {
            return AT_OK;
        } else {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_AtCmdMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    SERVICE_MODE_TYPE old_mode;

    if (param->argc == 0)
    {
        if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_CLI)
        {
            atcmd_printf("OK\r\n");
            if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_CLI)) != UDRV_RETURN_OK)
            {
                return AT_ERROR;
            }

            switch (old_mode)
            {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                case SERVICE_MODE_TYPE_TRANSPARENT:
                {
                    service_mode_transparent_deinit(port);
                    break;
                }
#endif
#endif
                case SERVICE_MODE_TYPE_PROTOCOL:
                {
                    service_mode_proto_deinit(port);
                    break;
                }
                default:
                {
                    break;
                }
            }

            service_mode_cli_init(port);
        }
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_ApiMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    SERVICE_MODE_TYPE old_mode;

    if (param->argc == 0)
    {
        if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_PROTOCOL)
        {
            atcmd_printf("OK\r\n");
            if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_PROTOCOL)) != UDRV_RETURN_OK)
            {
                return AT_ERROR;
            }
            switch (old_mode)
            {
                case SERVICE_MODE_TYPE_CLI:
                {
                    service_mode_cli_deinit(port);
                    break;
                }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                case SERVICE_MODE_TYPE_TRANSPARENT:
                {
                    service_mode_transparent_deinit(port);
                    break;
                }
#endif
#endif
                default:
                {
                    break;
                }
            }

            service_mode_proto_init(port);
        }
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

#ifdef SUPPORT_PASSTHRU
int At_TransparentMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    SERVICE_MODE_TYPE old_mode;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_nvm_get_tp_port_from_nvm(port));
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint8_t tp_port;

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        tp_port = strtoul(param->argv[0], NULL, 10);

        if (tp_port < 1 || tp_port > 223)
        {
            return AT_PARAM_ERROR;
        }

        ret = service_nvm_set_tp_port_to_nvm(port, tp_port);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else
        {
            return AT_ERROR;
        }
    }
    else if (param->argc == 0)
    {
        if (service_lora_get_njs() == false)
        {
            return AT_NO_NETWORK_JOINED;
        }

        if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_TRANSPARENT)
        {
            atcmd_printf("OK\r\n");
            if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_TRANSPARENT)) != UDRV_RETURN_OK)
            {
                return AT_ERROR;
            }
            switch (old_mode)
            {
                case SERVICE_MODE_TYPE_CLI:
                {
                    service_mode_cli_deinit(port);
                    break;
                }
                case SERVICE_MODE_TYPE_PROTOCOL:
                {
                    service_mode_proto_deinit(port);
                    break;
                }
                default:
                {
                    break;
                }
            }

            service_mode_transparent_init(port);
        }
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif

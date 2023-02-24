#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_key_id.h"
#include "udrv_errno.h"
#include "service_lora.h"

static void dump_hex2str(uint8_t *buf , uint8_t len)
{
    for(uint8_t i=0; i<len; i++) {
        atcmd_printf("%02X", buf[i]);
    }
    atcmd_printf("\r\n");
}

//AT Command Keys, IDs and EUIs Management Function
int At_AppEui (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[8];
        if (service_lora_get_app_eui(rbuff, 8) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 8);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 16) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 16 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 8 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            lora_id[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_app_eui(lora_id, 8);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_AppKey (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[16];
        if (service_lora_get_app_key(rbuff, 16) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 16);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 32) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 32 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 16 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            lora_id[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_app_key(lora_id, 16);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_AppSKey (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[16];
        if (service_lora_get_app_skey(rbuff, 16) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 16);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 32) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 32 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 16 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            lora_id[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_app_skey(lora_id, 16);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_DevAddr (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[4];
        if (service_lora_get_dev_addr(rbuff, 4) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        for (int i = 0 ; i < 4 ; i++) {
            atcmd_printf("%02X", rbuff[i]);
        }
        atcmd_printf("\r\n");
        return AT_OK;
    } else if (param->argc == 1) {
        char dev_addr[4];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 8) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 8 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 4 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            dev_addr[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_dev_addr(dev_addr, 4);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_DevEui (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[8];
        if (service_lora_get_dev_eui(rbuff, 8) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 8);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 16) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 16 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 8 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            lora_id[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_dev_eui(lora_id, 8);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_NetId (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[4];
        if (service_lora_get_net_id(rbuff, 4) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        //XXX: These 3 bytes are MSB first!
        atcmd_printf("%s=", cmd);
        for(int i = 2 ; i >= 0 ; i--) {
            atcmd_printf("%02X", rbuff[i]);
        }
        atcmd_printf("\r\n");
        return AT_OK;
    //} else if (param->argc == 1) {
    //    char lora_id[8];
    //    char hex_num[3] = {0};

    //    if (strlen(param->argv[0]) != 8) {
    //        return AT_PARAM_ERROR;
    //    }

    //    for (int i = 0 ; i < 8 ; i++) {
    //        if (!isxdigit(param->argv[0][i])) {
    //            return AT_PARAM_ERROR;
    //        }
    //    }

    //    //XXX: These 4 bytes are MSB first!
    //    for (int i = 0 ; i < 4 ; i++) {
    //        memcpy(hex_num, &param->argv[0][i*2], 2);
    //        lora_id[3-i] = strtoul(hex_num, NULL, 16);
    //    }

    //    if (service_lora_set_nwk_id(lora_id, 4) == UDRV_RETURN_OK) {
    //        return AT_OK;
    //    } else {
    //        return AT_ERROR;
    //    }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_NwkSKey (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[16];
        if (service_lora_get_nwk_skey(rbuff, 16) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 16);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 32) {
            return AT_PARAM_ERROR;
	}

        for (int i = 0 ; i < 32 ; i++) {
            if (!isxdigit(param->argv[0][i])) {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0 ; i < 16 ; i++) {
            memcpy(hex_num, &param->argv[0][i*2], 2);
            lora_id[i] = strtoul(hex_num, NULL, 16);
        }

        ret = service_lora_set_nwk_skey(lora_id, 16);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_McRootkey (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint8_t rbuff[16];
        if (service_lora_get_McRoot_key(rbuff) != true) {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 16);
        return AT_OK;
    } else if (param->argc == 1) {
        char lora_id[32];
        char hex_num[3] = {0};
        int32_t ret;

	if (strlen(param->argv[0]) != 32) {
            return AT_PARAM_ERROR;
	}
 
    } else {
        return AT_PARAM_ERROR;
    }
}

#endif
#endif

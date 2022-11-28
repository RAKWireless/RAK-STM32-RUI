
#include <string.h>

#include "atcmd.h"
#include "atcmd_general.h"
#include "udrv_errno.h"
#include "udrv_system.h"
#include "mcu_basic.h"
#include "service_debug.h"
#ifdef RUI_BOOTLOADER
#include "uhal_flash.h"
#include "service_nvm.h"
#endif

#ifdef SUPPORT_BLE
#include "ble_gap.h"
#endif

#ifndef RUI_BOOTLOADER
extern const char *sw_version;
extern const char *model_id;
extern const char *chip_id;
extern const char *build_date;
extern const char *build_time;
extern const char *repo_info;
extern const char *cli_version;
extern const char *api_version;
#endif
extern const char BOOT_VERSION;

int At_Dfu (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) {
#ifdef RUI_BOOTLOADER
        uhal_enter_dfu();
#else
        udrv_enter_dfu();
#endif

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}


//AT Command General Function
int At_Attention (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) {
        /* Do nothing. */
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}


#ifdef SUPPORT_AT
int At_Debug (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d",cmd,service_get_debug_level());
        atcmd_printf("\r\n");
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint8_t level;
        if (0 != at_check_digital_uint32_t(param->argv[0], &level))
            return AT_PARAM_ERROR;
        if(level > 1 )
            return AT_PARAM_ERROR;
        service_set_debug_level(level);
        return AT_OK;
    }
    else
    {
        return AT_ERROR;
    }
    
}


int At_Reboot (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) {
#ifdef RUI_BOOTLOADER
        uhal_sys_reboot();
#else
        udrv_system_reboot();
#endif
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Restore(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;

    if (param->argc != 0)
        return AT_PARAM_ERROR;

#ifdef RUI_BOOTLOADER
    ret = uhal_flash_erase(MCU_SYS_CONFIG_NVM_ADDR, uhal_flash_get_page_size());
#else
#ifdef SUPPORT_LORA
    ret = service_lora_set_lora_default();
#else
    ret = service_nvm_set_default_config_to_nvm();
#endif
#endif
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
}

#ifndef RUI_BOOTLOADER
int At_Echo (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) {
        if (service_nvm_get_atcmd_echo_from_nvm() == 0) {
            service_nvm_set_atcmd_echo_to_nvm(1);
        } else {
            service_nvm_set_atcmd_echo_to_nvm(0);
        }
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }

}

int At_FSn (SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t rbuff[18];

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        if (service_nvm_get_sn_from_nvm(rbuff, 18) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=",cmd);
        for (int i = 0 ; i < 18 ; i++) {
            atcmd_printf("%c", rbuff[i]);
        }
        atcmd_printf("\r\n");
        return AT_OK;
    } else if (param->argc == 1) {
        int32_t ret;

	if (strlen(param->argv[0]) < 1 || strlen(param->argv[0]) > 18) {
            return AT_PARAM_ERROR;
	}

        if (service_nvm_get_sn_from_nvm(rbuff, 18) != UDRV_RETURN_OK) {
            return AT_ERROR;
        } else {
            for (int i = 0 ; i < 18 ; i++) {
                if (rbuff[i] != 0) {
                    return AT_ERROR;
                }
            }
        }

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!(param->argv[0][i] >= 0x30 && param->argv[0][i] <= 0x39) &&
			    !(param->argv[0][i] >= 0x41 && param->argv[0][i] <= 0x5A) &&
			    !(param->argv[0][i] >= 0x61 && param->argv[0][i] <= 0x7A)) {
                return AT_PARAM_ERROR;
            }
        }

        ret = service_nvm_set_sn_to_nvm(param->argv[0], strlen(param->argv[0]));
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Sn (SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t rbuff[18];

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        if (service_nvm_get_sn_from_nvm(rbuff, 18) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }
        atcmd_printf("%s=",cmd);
        for (int i = 0 ; i < 18 ; i++) {
            atcmd_printf("%c", rbuff[i]);
        }
        atcmd_printf("\r\n");
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Bootver (SERIAL_PORT port, char *cmd, stParam *param)
{
    char boot_version[33];
    memset(boot_version,'\0',33);
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        memcpy(boot_version,&BOOT_VERSION,32);
        atcmd_printf("%s=%s\r\n", cmd, boot_version);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetBat (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        float bat_lvl;

        service_battery_get_batt_level(&bat_lvl);
        atcmd_printf("%s=%f\r\n", cmd, bat_lvl);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetSysVolt (SERIAL_PORT port, char *cmd, stParam *param)
{       
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        float sys_lvl;
            
        service_battery_get_SysVolt_level(&sys_lvl);
        atcmd_printf("%s=%f\r\n", cmd, sys_lvl);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    } 
}

int At_GetFwBuildTime (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s-%s\r\n", cmd, build_date, build_time);

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetFwRepoInfo (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, repo_info);

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetFwVersion (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, sw_version);

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetCliVersion (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, cli_version);

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetApiVersion (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, api_version);

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetHwModel (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, model_id);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetHwID (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%s\r\n", cmd, chip_id);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Alias (SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t rbuff[16];

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) 
    {
        if (service_nvm_get_atcmd_alias_from_nvm(rbuff, 16) != UDRV_RETURN_OK) 
            return AT_ERROR;
        atcmd_printf("%s=", cmd);
        for (int i = 0 ; i < 16 ; i++)
            atcmd_printf("%c", rbuff[i]);
        atcmd_printf("\r\n");
        return AT_OK;
    } 
    else if (param->argc == 1) 
    {
        int32_t ret;
        if (strlen(param->argv[0]) < 1 || strlen(param->argv[0]) > 16) 
            return AT_PARAM_ERROR;
        if (service_nvm_get_atcmd_alias_from_nvm(rbuff, 16) != UDRV_RETURN_OK)
            return AT_ERROR;
        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (param->argv[0][i] < 0x20 || param->argv[0][i] > 0x7E) {
                return AT_PARAM_ERROR;
            }
        } 
        ret = service_nvm_set_atcmd_alias_to_nvm(param->argv[0], strlen(param->argv[0]));
        if (ret == UDRV_RETURN_OK)
            return AT_OK;
        else
            return AT_ERROR;
    } 
    else 
        return AT_PARAM_ERROR;
}
#endif

#ifdef rak3172
int At_GetUid (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        uint32_t uid0, uid1, uid2;
	uhal_sys_get_uid(&uid0, &uid1, &uid2);
        atcmd_printf("%s=%08x%08x%08x\r\n", cmd, uid2, uid1, uid0);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}
#endif

#ifdef SUPPORT_BLE
int At_BLEMac (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        ble_gap_addr_t gap_addr;
        sd_ble_gap_addr_get(&gap_addr);
        int i,len = sizeof(gap_addr.addr)/sizeof(uint8_t);
        atcmd_printf("%s=", cmd);
        for (int i=len;i>0;i--)
        {
            atcmd_printf("%02x",gap_addr.addr[i-1]);
            if(i-1 != 0)
                atcmd_printf(":");
        }
        atcmd_printf("\r\n");
        return AT_OK;
    } 
    else if (param->argc == 1)
    {
        int32_t ret;
        if (strlen(param->argv[0]) != 12)
            return AT_PARAM_ERROR;
        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if ((param->argv[0][i] < 0x30 || param->argv[0][i] > 0x39) && 
                (param->argv[0][i] < 0x41 || param->argv[0][i] > 0x46) && 
                (param->argv[0][i] < 0x61 || param->argv[0][i] > 0x66)) {
                return AT_PARAM_ERROR;
            }
        }
        if(udrv_ble_set_macaddress(param->argv[0]) != UDRV_RETURN_OK)
            return AT_ERROR;

        if(service_nvm_set_ble_mac_to_nvm(param->argv[0],strlen(param->argv[0])) != UDRV_RETURN_OK)
            return AT_ERROR;

        return AT_OK;
    }
    else 
        return AT_PARAM_ERROR;

}

#endif
#endif

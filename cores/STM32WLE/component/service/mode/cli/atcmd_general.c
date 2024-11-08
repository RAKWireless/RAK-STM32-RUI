#include <string.h>

#include "atcmd.h"
#include "atcmd_general.h"
#include "udrv_errno.h"
#include "udrv_system.h"
#include "mcu_basic.h"
#include "service_debug.h"
#include "service_nvm.h"
#ifdef RUI_BOOTLOADER
#include "uhal_flash.h"
#endif

#ifdef SUPPORT_BLE
#ifndef rak11720
#include "ble_gap.h"
#else
#include "hci_core_ps.h"
#endif
#endif
#include "board_basic.h"
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
    if(service_lora_set_lora_default() != UDRV_RETURN_OK)
        return AT_ERROR;
#ifdef LORA_STACK_104
    ret = service_nvm_set_cfg_to_nvm() | service_nvm_set_lora_nvm_data_to_nvm();
#else
    ret = service_nvm_set_cfg_to_nvm();
#endif
#else
    if(service_nvm_set_default_config_to_nvm() != UDRV_RETURN_OK)
        return AT_ERROR;
    ret = service_nvm_set_cfg_to_nvm();
#endif
#endif
    if (ret == UDRV_RETURN_OK)
    {
#ifdef RUI_BOOTLOADER
        uhal_sys_reboot();
#else
        udrv_system_reboot();
#endif
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

int At_GetCusFwVersion (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        char ver[33];
        ver[32] = '\0';
        service_nvm_get_firmware_ver_from_nvm(ver,32);
        atcmd_printf("%s=%s\r\n", cmd, ver);
        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_GetCliVersion (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
         char ver[33];
        ver[32] = '\0';
        service_nvm_get_cli_ver_from_nvm(ver,32);
        atcmd_printf("%s=%s\r\n", cmd, ver);

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
        char model[33];
        model[32] = '\0';
        service_nvm_get_hwmodel_from_nvm(model,32);
        atcmd_printf("%s=%s\r\n", cmd, model);

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

#if defined(rak3172) || defined(rak3172T)
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
        #ifndef rak11720
        ble_gap_addr_t gap_addr;
        sd_ble_gap_addr_get(&gap_addr);
        int i,len = sizeof(gap_addr.addr)/sizeof(uint8_t);
        #else
        uint8_t addr[6];
        uint8_t *pBda;
        pBda = HciGetBdAddr();
        BdaCpy(addr, pBda);
        int i,len = sizeof(addr)/sizeof(uint8_t);
        #endif
        atcmd_printf("%s=", cmd);
        for (int i=len;i>0;i--)
        {
            #ifndef rak11720
            atcmd_printf("%02x",gap_addr.addr[i-1]);
            #else
            atcmd_printf("%02x",addr[i-1]);
            #endif
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

int At_BLEDTM (SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("BLEDTM\r\n");
        return AT_OK;
    }
    else if (param->argc == 0)
    {
        if(strlen(param->argv[0])%2)
            return AT_PARAM_ERROR;
        service_mode_cli_deinit(DEFAULT_SERIAL_CONSOLE);
        uint8_t serial_buf[256];
        uint8_t serial_ascii_buf[512];
        uint8_t cnt = 0;
        uint32_t hci_recv_bytes;
        while(1)
        {
            if(udrv_serial_read_available(DEFAULT_SERIAL_CONSOLE))
            {
                udrv_serial_read(DEFAULT_SERIAL_CONSOLE, serial_buf+cnt, 1);
                cnt++;
                if(serial_buf[cnt-1] == '\n')
                {
                    serial_buf[--cnt] = '\0';
                    if(serial_buf[cnt-1] == '\r')
                        serial_buf[--cnt] = '\0';
                    if(cnt == 0)
                        continue;
                    if(strncasecmp("at+atm",serial_buf,6) == 0)
                        break;    
                    memset(serial_ascii_buf,'\0',sizeof(serial_ascii_buf));
                    for(int i = 0;i<cnt;i++)
                    {
                        sprintf(serial_ascii_buf+2*i,"%x",serial_buf[i] & 0xF0);
                        sprintf(serial_ascii_buf+2*i+1,"%x",serial_buf[i] & 0x0F);
                    }
                    uhal_ble_hci_write(serial_ascii_buf,cnt*2);
                    memset(serial_ascii_buf,'\0',sizeof(serial_ascii_buf));
                    if (uhal_ble_hci_read(serial_ascii_buf,&hci_recv_bytes) == UDRV_RETURN_OK)
                    {
                        udrv_serial_write(DEFAULT_SERIAL_CONSOLE,serial_ascii_buf,hci_recv_bytes);
                        atcmd_printf("\r\n");
                    }
                    cnt = 0;
                    memset(serial_buf,'\0',sizeof(serial_buf));
                }
            }
        }
        service_mode_cli_init(DEFAULT_SERIAL_CONSOLE);
        return AT_OK;
    }
    else if (param->argc == 2)
    {
        if(strlen(param->argv[0])%2)
            return AT_PARAM_ERROR;
        service_mode_cli_deinit(DEFAULT_SERIAL_CONSOLE);
        int power;
        uint8_t hci_recv[256];
        uint32_t hci_recv_bytes;

        sscanf(param->argv[1],"%d",&power);
#ifdef rak11720
        uhal_ble_set_dtm_txpower(power);
#else
        uhal_ble_set_txpower(power);
#endif
        uhal_ble_hci_write(param->argv[0],strlen(param->argv[0]));
        uhal_ble_hci_read(hci_recv,&hci_recv_bytes);
        atcmd_printf("%s=",cmd);
        for(int i = 0;i<hci_recv_bytes;i++)
            atcmd_printf("%02X",hci_recv[i]);
        atcmd_printf("\r\n");
        return AT_OK;
    }

    else
        return AT_PARAM_ERROR;

}

#endif
#endif

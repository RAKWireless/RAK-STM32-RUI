#include "board_basic.h"
#include "udrv_errno.h"
#include "udrv_flash.h"
#include "service_nvm.h"

PRE_rui_cfg_t g_rui_cfg_t;
#if defined(LORA_STACK_104) && defined(SUPPORT_LORA)
lora_mac_nvm_data_t g_lora_mac_nvm_data;
#endif
int32_t service_nvm_set_cfg_to_nvm()
{
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
#ifdef SUPPORT_LORA
#ifdef LORA_STACK_104
int32_t service_nvm_set_lora_nvm_data_to_nvm()
{
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}

void service_lora_mac_nvm_data_reset(void)
{
    memset(&g_lora_mac_nvm_data,0,sizeof(lora_mac_nvm_data_t));
    return UDRV_RETURN_OK;
}
#endif
#endif
/***********************************************************/
/* RUI Mode                                                */
/***********************************************************/

SERVICE_MODE_TYPE service_nvm_get_mode_type_from_nvm(SERIAL_PORT port) {
    return g_rui_cfg_t.mode_type[port];
}

int32_t service_nvm_set_mode_type_to_nvm(SERIAL_PORT port, SERVICE_MODE_TYPE mode_type) {
    g_rui_cfg_t.mode_type[port] = mode_type;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_serial_passwd_from_nvm(uint8_t *passwd, uint32_t len) {
    if (len < 9) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(passwd, g_rui_cfg_t.serial_passwd, 9);

    return strlen(g_rui_cfg_t.serial_passwd);
}
int32_t service_nvm_set_serial_passwd_to_nvm(uint8_t *passwd, uint32_t len) {
    if (len > 8) {
        return -UDRV_WRONG_ARG;
    }
    memset(g_rui_cfg_t.serial_passwd, 0, sizeof(g_rui_cfg_t.serial_passwd));
    memcpy(g_rui_cfg_t.serial_passwd, passwd, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_sleep_time_from_nvm(void) {
    return g_rui_cfg_t.auto_sleep_time;
}

int32_t service_nvm_set_auto_sleep_time_to_nvm(uint32_t time) {
    g_rui_cfg_t.auto_sleep_time = time;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_auto_sleep_level_from_nvm(void) {
    return g_rui_cfg_t.g_rui_cfg_ex.auto_sleep_level;
}
uint8_t service_nvm_set_auto_sleep_level_to_nvm(uint32_t level) {
    g_rui_cfg_t.g_rui_cfg_ex.auto_sleep_level = level;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}



uint8_t service_nvm_get_firmware_ver_from_nvm(uint8_t *buff, uint32_t len) {
    if (len < sizeof(g_rui_cfg_t.firmware_ver)) {
        return -UDRV_BUFF_OVERFLOW;
    }
    memcpy(buff, g_rui_cfg_t.firmware_ver, sizeof(g_rui_cfg_t.firmware_ver));
    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_firmware_ver_to_nvm(uint8_t *buff, uint32_t len) {
    if (len > 32 || len == 0) {
        return -UDRV_WRONG_ARG;
    }
    for (int i = 0 ; i < len ; i++)
    {
        if ((uint8_t)buff[i] < 0x20 || (uint8_t)buff[i] > 0x7E) {
            return -UDRV_WRONG_ARG;
        }
    }
    memset(g_rui_cfg_t.firmware_ver, 0 , sizeof(g_rui_cfg_t.firmware_ver));
    memcpy(g_rui_cfg_t.firmware_ver, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint8_t service_nvm_get_hwmodel_from_nvm(uint8_t *buff, uint32_t len) {
    if (len < sizeof(g_rui_cfg_t.hwmodel)) {
        return -UDRV_BUFF_OVERFLOW;
    }
    memcpy(buff, g_rui_cfg_t.hwmodel, sizeof(g_rui_cfg_t.hwmodel));
    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_hwmodel_to_nvm(uint8_t *buff, uint32_t len) {
    if (len > 32 || len == 0) {
        return -UDRV_WRONG_ARG;
    }
    for (int i = 0 ; i < len ; i++)
    {
        if ((uint8_t)buff[i] < 0x20 || (uint8_t)buff[i] > 0x7E) {
            return -UDRV_WRONG_ARG;
        }
    }
    memset(g_rui_cfg_t.hwmodel, 0 , sizeof(g_rui_cfg_t.hwmodel));
    memcpy(g_rui_cfg_t.hwmodel, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint8_t service_nvm_get_cli_ver_from_nvm(uint8_t *buff, uint32_t len) {
    if (len < sizeof(g_rui_cfg_t.hwmodel)) {
        return -UDRV_BUFF_OVERFLOW;
    }
    memcpy(buff, g_rui_cfg_t.cli_ver, sizeof(g_rui_cfg_t.cli_ver));
    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_cli_ver_to_nvm(uint8_t *buff, uint32_t len) {
    if (len > 32 || len == 0 ) {
        return -UDRV_WRONG_ARG;
    }
    for (int i = 0 ; i < len ; i++)
    {
        if ((uint8_t)buff[i] < 0x20 || (uint8_t)buff[i] > 0x7E) {
            return -UDRV_WRONG_ARG;
        }
    }
    memset(g_rui_cfg_t.cli_ver, 0 , sizeof(g_rui_cfg_t.cli_ver));
    memcpy(g_rui_cfg_t.cli_ver, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
/***********************************************************/
/* User Data                                               */
/***********************************************************/

int32_t service_nvm_write_user_data (uint32_t offset, uint8_t *buff, uint32_t len) {
    if (offset > (MCU_CERT_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR)) {
        return -UDRV_WRONG_ARG;
    }

    if (len > (MCU_CERT_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR - offset)) {
        return -UDRV_WRONG_ARG;
    }

    return udrv_flash_write(SERVICE_NVM_USER_DATA_NVM_ADDR+offset, len, buff);
}
int32_t service_nvm_read_user_data (uint32_t offset, uint8_t *buff, uint32_t len) {
    if (offset > (MCU_CERT_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR)) {
        return -UDRV_WRONG_ARG;
    }

    if (len > (MCU_CERT_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR - offset)) {
        return -UDRV_WRONG_ARG;
    }

    return udrv_flash_read(SERVICE_NVM_USER_DATA_NVM_ADDR+offset, len, buff);
}
/***********************************************************/
/* RTC                                                     */
/***********************************************************/

uint32_t service_nvm_get_delta_sec_from_nvm (void) {
    return g_rui_cfg_t.g_rtc_delta_t.seconds;
}

int32_t service_nvm_set_delta_sec_to_nvm (uint32_t sec) {
    g_rui_cfg_t.g_rtc_delta_t.seconds = sec;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_delta_subsec_from_nvm (void) {
    return g_rui_cfg_t.g_rtc_delta_t.subseconds;
}

int32_t service_nvm_set_delta_subsec_to_nvm (uint32_t subsec) {
    g_rui_cfg_t.g_rtc_delta_t.subseconds = subsec;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERIAL_WLOCK_STATE  service_nvm_get_lock_status_from_nvm(SERIAL_PORT Port) {
        return g_rui_cfg_t.serial_lock_status[Port];
}
int32_t service_nvm_set_lock_status_to_nvm(SERIAL_PORT Port, SERIAL_WLOCK_STATE wlock_state) {
    g_rui_cfg_t.serial_lock_status[Port] = wlock_state;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_baudrate_from_nvm(void) {
    return g_rui_cfg_t.baudrate;
}

int32_t service_nvm_set_baudrate_to_nvm(uint32_t baudrate) {
    g_rui_cfg_t.baudrate = baudrate;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_atcmd_alias_from_nvm(uint8_t *buff, uint32_t len) {
    if (len < sizeof(g_rui_cfg_t.alias)) {
        return -UDRV_BUFF_OVERFLOW;
    }
    memcpy(buff, g_rui_cfg_t.alias, sizeof(g_rui_cfg_t.alias));
    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_atcmd_alias_to_nvm(uint8_t *buff, uint32_t len) {
    if (len > 16) {
        return -UDRV_WRONG_ARG;
    }

    if (len != 16) {
        memset(g_rui_cfg_t.alias, 0 , 16);
    }
    for (int i = 0 ; i < len ; i++)
    {
        if ((uint8_t)buff[i] < 0x20 || (uint8_t)buff[i] > 0x7E) {
            return -UDRV_WRONG_ARG;
        }
    }
    memcpy(g_rui_cfg_t.alias, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_sn_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 18) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.sn, 18);

    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_sn_to_nvm (uint8_t *buff, uint32_t len) {
    if (len > 18) {
        return -UDRV_WRONG_ARG;
    }

    if (len != 18) {
        memset(g_rui_cfg_t.sn, 0 , 18);
    }
    memcpy(g_rui_cfg_t.sn, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_atcmd_echo_from_nvm(void) {
    return g_rui_cfg_t.atcmd_echo;
}

int32_t service_nvm_set_atcmd_echo_to_nvm(uint8_t atcmd_echo) {
    g_rui_cfg_t.atcmd_echo = atcmd_echo;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint32_t service_nvm_set_debug_level_to_nvm(uint8_t level)
{
    g_rui_cfg_t.debug_level = level;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_debug_level_from_nvm()
{
    return g_rui_cfg_t.debug_level;
}
#ifdef SUPPORT_BLE
/***********************************************************/
/* BLE                                                     */
/***********************************************************/
uint8_t service_nvm_set_ble_mac_to_nvm(uint8_t *buff, uint32_t len)
{
    if (strlen(buff) != 12) {
        return -UDRV_WRONG_ARG;
    }
    for (int i = 0 ; i < len ; i++)
    {
        if ((buff[i] < 0x30 || buff[i] > 0x39) &&
            (buff[i] < 0x41 || buff[i] > 0x46) &&
            (buff[i] < 0x61 || buff[i] > 0x66)) {
                return -UDRV_WRONG_ARG;
        }
    }
    memcpy(g_rui_cfg_t.g_ble_cfg_t.mac,buff,sizeof(g_rui_cfg_t.g_ble_cfg_t.mac));
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_ble_mac_from_nvm(uint8_t *buff, uint32_t len)
{
    if (len != sizeof(g_rui_cfg_t.g_ble_cfg_t.mac)) {
        return -UDRV_BUFF_OVERFLOW;
    }
    memcpy(buff, g_rui_cfg_t.g_ble_cfg_t.mac, sizeof(g_rui_cfg_t.g_ble_cfg_t.mac));
    return UDRV_RETURN_OK;
}
#endif
#ifndef NO_LORA_SUPPORT
/***********************************************************/
/* LoRa                                                    */
/***********************************************************/
SERVICE_LORA_BAND service_nvm_get_band_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.region;
}

int32_t service_nvm_set_band_to_nvm (SERVICE_LORA_BAND band) {
    g_rui_cfg_t.g_lora_cfg_t.region = band;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_mask_from_nvm (uint16_t *mask) {
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 ) || defined( REGION_LA915 )
    memcpy(mask, g_rui_cfg_t.g_lora_cfg_t.ch_mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return UDRV_RETURN_OK;
#else
    return -UDRV_INTERNAL_ERR;
#endif

}
int32_t service_nvm_set_mask_to_nvm (uint16_t *mask) {
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 ) || defined( REGION_LA915 )
    memcpy(g_rui_cfg_t.g_lora_cfg_t.ch_mask, mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
#else
    return -UDRV_INTERNAL_ERR;
#endif
}

int32_t service_nvm_get_app_eui_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 8) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.app_eui, 8);

    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_app_eui_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 8) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.app_eui, buff, 8);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_app_key_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 16) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.app_key, 16);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_app_key_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 16) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.app_key, buff, 16);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
int32_t service_nvm_get_app_skey_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 16) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.app_skey, 16);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_app_skey_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 16) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.app_skey, buff, 16);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_dev_addr_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 4) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.dev_addr, 4);

    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_dev_addr_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 4) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.dev_addr, buff, 4);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_dev_eui_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 8) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.dev_eui, 8);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_dev_eui_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 8) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.dev_eui, buff, 8);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
int32_t service_nvm_get_net_id_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 4) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.nwk_id, 4);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_net_id_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 4) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.nwk_id, buff, 4);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_nwk_skey_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 16) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_cfg_t.nwk_skey, 16);

    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_nwk_skey_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 16) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_lora_cfg_t.nwk_skey, buff, 16);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_retry_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.retry;
}

int32_t service_nvm_set_retry_to_nvm (uint8_t retry) {
    g_rui_cfg_t.g_lora_cfg_t.retry = retry;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CONFIRM_MODE service_nvm_get_cfm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.confirm;
}

int32_t service_nvm_set_cfm_to_nvm (SERVICE_LORA_CONFIRM_MODE cfm) {
    g_rui_cfg_t.g_lora_cfg_t.confirm = cfm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
SERVICE_LORA_WORK_MODE service_nvm_get_nwm_from_nvm (void) {
    return g_rui_cfg_t.lora_work_mode;
}

int32_t service_nvm_set_nwm_to_nvm (SERVICE_LORA_WORK_MODE nwm) {
    g_rui_cfg_t.lora_work_mode = nwm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_JOIN_MODE service_nvm_get_njm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_mode;
}

int32_t service_nvm_set_njm_to_nvm (SERVICE_LORA_JOIN_MODE njm) {
    g_rui_cfg_t.g_lora_cfg_t.join_mode = njm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_adr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.adr;
}
int32_t service_nvm_set_adr_to_nvm (bool adr) {
    g_rui_cfg_t.g_lora_cfg_t.adr = adr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CLASS service_nvm_get_class_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.device_class;
}

int32_t service_nvm_set_class_to_nvm (SERVICE_LORA_CLASS device_class) {
    g_rui_cfg_t.g_lora_cfg_t.device_class = device_class;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.dr;
}

int32_t service_nvm_set_dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.dr = dr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
SERVICE_LORA_DATA_RATE service_nvm_get_rx2dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dr;
}

int32_t service_nvm_set_rx2dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dr = dr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


uint32_t service_nvm_get_jn1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn1dl;
}

int32_t service_nvm_set_jn1dl_to_nvm (uint32_t jn1dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn1dl = jn1dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_jn2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn2dl;
}
int32_t service_nvm_set_jn2dl_to_nvm (uint32_t jn2dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn2dl = jn2dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_rx2fq_to_nvm(uint32_t freq)
{
    g_rui_cfg_t.g_lora_cfg_t.rx2fq = freq;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx2fq_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_cfg_t.rx2fq ;
}

bool service_nvm_get_pub_nwk_mode_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.pub_nwk_mode;
}
int32_t service_nvm_set_pub_nwk_mode_to_nvm (bool pnm) {
    g_rui_cfg_t.g_lora_cfg_t.pub_nwk_mode = pnm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx1dl;
}

int32_t service_nvm_set_rx1dl_to_nvm (uint32_t rx1dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx1dl = rx1dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dl;
}

int32_t service_nvm_set_rx2dl_to_nvm (uint32_t rx2dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dl = rx2dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint8_t service_nvm_get_txpower_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.tx_power;
}

int32_t service_nvm_set_txpower_to_nvm (uint8_t txp) {
    g_rui_cfg_t.g_lora_cfg_t.tx_power = txp;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_linkcheck_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode;
}

int32_t service_nvm_set_linkcheck_to_nvm (uint8_t mode) {
    g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode = mode;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_ping_slot_periodicity_from_nvm() {
    return g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity;
}
int32_t service_nvm_set_ping_slot_periodicity_to_nvm(uint8_t periodicity) {
    g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity = periodicity;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_join_start_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_start;
}

int32_t service_nvm_set_join_start_to_nvm(bool join_start) {
    g_rui_cfg_t.g_lora_cfg_t.join_start = join_start;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_auto_join_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join;
}

int32_t service_nvm_set_auto_join_to_nvm(bool auto_join) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join = auto_join;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint32_t service_nvm_get_auto_join_period_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_period;
}

int32_t service_nvm_set_auto_join_period_to_nvm(uint32_t auto_join_period) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_period = auto_join_period;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_max_cnt_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt;
}

int32_t service_nvm_set_auto_join_max_cnt_to_nvm(uint32_t auto_join_max_cnt) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt = auto_join_max_cnt;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_lbt_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_enable;
}
int32_t service_nvm_set_lbt_to_nvm(uint8_t enable)
{
    g_rui_cfg_t.g_rui_cfg_ex.lbt_enable = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int16_t service_nvm_get_lbt_rssi_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi;
}

int32_t service_nvm_set_lbt_rssi_to_nvm(int16_t rssi)
{
    g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi = rssi;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_lbt_scantime_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime;
}
int32_t service_nvm_set_lbt_scantime_to_nvm(uint32_t time)
{
    g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime = time;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

#ifdef LORA_STACK_104
uint16_t service_nvm_get_DevNonce_from_nvm()
{
    return g_lora_mac_nvm_data.loramac_crypto_nvm.DevNonce;
}

int32_t service_nvm_set_DevNonce_to_nvm(uint16_t devnonce)
{
    g_lora_mac_nvm_data.loramac_crypto_nvm.DevNonce = devnonce;
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}


int32_t service_nvm_set_IsCertPortOn_to_nvm(uint8_t IsCertPortOn)
{
    g_rui_cfg_t.g_rui_cfg_ex.IsCertPortOn = IsCertPortOn;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint8_t service_nvm_get_IsCertPortOn_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.IsCertPortOn;

}

int32_t service_nvm_set_crypto_to_nvm(LoRaMacCryptoNvmData_t * crypto)
{
    memcpy(&g_lora_mac_nvm_data.loramac_crypto_nvm,crypto,sizeof(LoRaMacCryptoNvmData_t));
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

LoRaMacCryptoNvmData_t * service_nvm_get_crypto_from_nvm(void)
{
    return &g_lora_mac_nvm_data.loramac_crypto_nvm;
}

int32_t service_nvm_set_macgroup1_to_nvm(LoRaMacNvmDataGroup1_t * macgroup1)
{
    memcpy(&g_lora_mac_nvm_data.loramac_macgroup1,macgroup1,sizeof(LoRaMacNvmDataGroup1_t));
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}
LoRaMacNvmDataGroup1_t * service_nvm_get_macgroup1_from_nvm(void)
{
    return &g_lora_mac_nvm_data.loramac_macgroup1;
}

int32_t service_nvm_set_macgroup2_to_nvm(LoRaMacNvmDataGroup2_t * macgroup2)
{
    memcpy(&g_lora_mac_nvm_data.loramac_macgroup2,macgroup2,sizeof(LoRaMacNvmDataGroup2_t));
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}

LoRaMacNvmDataGroup2_t * service_nvm_get_macgroup2_from_nvm(void)
{
    return &g_lora_mac_nvm_data.loramac_macgroup2;
}

int32_t service_nvm_set_sec_element_to_nvm(SecureElementNvmData_t * SecureElement)
{
    memcpy(&g_lora_mac_nvm_data.loramac_secureelement,SecureElement,sizeof(SecureElementNvmData_t));
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}
SecureElementNvmData_t * service_nvm_get_sec_element_from_nvm(void)
{
    return &g_lora_mac_nvm_data.loramac_secureelement;
}

int32_t service_nvm_set_regionchannels_to_nvm(ChannelParams_t * Channels)
{
    memcpy(&g_lora_mac_nvm_data.loramac_channels,Channels,sizeof(ChannelParams_t)*REGION_NVM_MAX_NB_CHANNELS);
    return udrv_flash_write(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
}

ChannelParams_t * service_nvm_get_regionchannels_from_nvm(void)
{
    return &g_lora_mac_nvm_data.loramac_channels;
}
#endif

McSession_t *service_nvm_get_multicast_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.McSession_group;
}

int32_t service_nvm_set_multicast_to_nvm(McSession_t *McSession) {
    memcpy(g_rui_cfg_t.g_lora_cfg_t.McSession_group, McSession ,4*sizeof(McSession_t));

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_tp_port_from_nvm(SERIAL_PORT port) {
    return g_rui_cfg_t.g_lora_cfg_t.tp_port[port];
}

int32_t service_nvm_set_tp_port_to_nvm(SERIAL_PORT port, uint8_t tp_port) {
    if (tp_port >= 1 && tp_port <= 223) {
        g_rui_cfg_t.g_lora_cfg_t.tp_port[port] = tp_port;
    } else {
        return -UDRV_WRONG_ARG;
    }

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint32_t service_nvm_get_chs_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_cfg_t.chs;
}

uint32_t service_nvm_set_chs_to_nvm(uint32_t frequency)
{
    g_rui_cfg_t.g_lora_cfg_t.chs = frequency;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_freq_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency;
}

int32_t service_nvm_set_freq_to_nvm (uint32_t freq) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = freq;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_sf_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact;
}
int32_t service_nvm_set_sf_to_nvm (uint8_t spreadfact) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact = spreadfact;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_bandwidth_from_nvm (void) {
    if( g_rui_cfg_t.lora_work_mode == 0)
    {
        return g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth ;
    }
    else
    {
       return g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw ;
    }
}
int32_t service_nvm_set_bandwidth_to_nvm (uint32_t bandwidth) {

    if( g_rui_cfg_t.lora_work_mode == 0)
    {
        g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth = bandwidth;
    }
    else if ( g_rui_cfg_t.lora_work_mode == 2)
    {
        g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw = bandwidth;
    }

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_codingrate_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate;
}

int32_t service_nvm_set_codingrate_to_nvm (uint8_t codingrate) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = codingrate;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint16_t service_nvm_get_preamlen_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen;
}
int32_t service_nvm_set_preamlen_to_nvm (uint16_t preamlen) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = preamlen;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_powerdbm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm;
}

int32_t service_nvm_set_powerdbm_to_nvm (uint8_t powerdbm) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = powerdbm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_crypt_enable_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable;
}

int32_t service_nvm_set_crypt_enable_to_nvm (bool crypt_enable) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = crypt_enable;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
int32_t service_nvm_get_crypt_key_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 16) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_rui_cfg_ex.crypt_key16, 16);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_crypt_key_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 16) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_rui_cfg_ex.crypt_key16, buff, 16);
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


int32_t service_nvm_get_crypt_IV_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 16) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_rui_cfg_ex.crypt_IV, 16);

    return UDRV_RETURN_OK;
}
int32_t service_nvm_set_crypt_IV_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 16) {
        return -UDRV_WRONG_ARG;
    }
    memcpy(g_rui_cfg_t.g_rui_cfg_ex.crypt_IV, buff, 16);
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_fdev_to_nvm(uint32_t fdev)
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = fdev;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_bitrate_to_nvm(uint32_t bitrate)
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate = bitrate;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_bitrate_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate;
}
uint32_t service_nvm_get_fdev_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.deviation;
}

uint32_t service_nvm_set_dcs_to_nvm(uint8_t dutycycle)
{
    g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable = dutycycle;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_dcs_from_nvm()
{
    return g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable;
}

bool service_nvm_get_iqinverted_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.iqinverted;
}

int32_t service_nvm_set_iqinverted_to_nvm(bool iqinverted)
{
    g_rui_cfg_t.g_rui_cfg_ex.iqinverted = iqinverted;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
uint32_t service_nvm_get_symbol_timeout_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout;
}

int32_t service_nvm_set_symbol_timeout_to_nvm(uint32_t symbol_timeout)
{
    g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout = symbol_timeout;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_fix_length_payload_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload;
}

int32_t service_nvm_set_fix_length_payload_to_nvm(bool enable)
{
    g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint16_t service_nvm_get_syncword_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.syncword;
}
int32_t service_nvm_set_syncword_to_nvm( uint16_t syncword)
{
    g_rui_cfg_t.g_rui_cfg_ex.syncword = syncword;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_CAD_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.CAD;
}

int32_t service_nvm_set_CAD_to_nvm(uint8_t enable)
{
    g_rui_cfg_t.g_rui_cfg_ex.CAD = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_certi_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.certif;
}

int32_t service_nvm_set_certi_to_nvm(uint8_t enable)
{
    g_rui_cfg_t.g_rui_cfg_ex.certif = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
#endif
#ifdef SUPPORT_LORA
#ifdef LORA_STACK_104
void service_lora_mac_nvm_data_init(void) {
    udrv_flash_read(MCU_CERT_CONFIG_NVM_ADDR, sizeof(lora_mac_nvm_data_t), (uint8_t *)&g_lora_mac_nvm_data);
    if (*(uint32_t*)&g_lora_mac_nvm_data.loramac_crypto_nvm.FCntList.FCntUp == 0xFFFFFFFF) {
        memset(&g_lora_mac_nvm_data,0,sizeof(lora_mac_nvm_data_t));
    }
    return UDRV_RETURN_OK;
}
#endif
#endif


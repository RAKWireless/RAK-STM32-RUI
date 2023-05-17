#include <stdint.h>
#include "board_basic.h"
#include "udrv_errno.h"
#include "udrv_flash.h"
#include "service_nvm.h"
#include <stdio.h>
#ifdef SUPPORT_LORA
#include "service_lora_multicast.h"
#include "service_lora_p2p.h"
#endif
extern char *sw_version;
extern char *model_id;
extern char *cli_version;

PRE_rui_cfg_t g_rui_cfg_t;
#define SERVICE_RUI_CONFIG_CRC32(x) Crc32(((uint8_t*)x)+sizeof(uint32_t),sizeof(PRE_rui_cfg_t)-sizeof(uint32_t))
#define SERVICE_STORE_CRC32(x) Crc32(((uint8_t*)x)+sizeof(uint32_t),sizeof(STORE_REOGANIZED)-sizeof(uint32_t))

static void service_nvm_data_recovery_from_legacy(uint32_t data_flash_addr, PRE_rui_cfg_t *rui_cfg_cur);
void service_nvm_data_add_to_legacy(PRE_rui_cfg_t *rui_cfg_cur);
void MemPrint( uint8_t *buf, uint32_t len)
{
    for( uint32_t i = 0; i < len; )
    {
        udrv_serial_log_printf("%08X %6d | ",i,i);
        for( uint32_t j = 0; j < 4 && i + j*4 <= len ; j++ )
        {
            udrv_serial_log_printf("%02X%02X%02X%02X ",buf[i+j*4+3],buf[i+j*4+2],buf[i+j*4+1],buf[i+j*4]);
        }
        udrv_serial_log_printf("\r\n");
        i+=16;
    }
}

int32_t service_nvm_set_default_config_to_nvm(void) {
    uint8_t passwd[8] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};
    PRE_rui_cfg_t factory_default;
    bool factory_default_exist = false;

    udrv_flash_read(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&factory_default);

    if( factory_default.magic_num == RUI_CFG_MAGIC_NUM && factory_default.version_code == RUI_CFG_VERSION_CODE)
    {
        factory_default_exist = true;
    }
    else
    {
        //Try to recovery default data from legacy version
        service_nvm_data_recovery_from_legacy(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR,(uint8_t *)&factory_default);
        if( factory_default.magic_num == RUI_CFG_MAGIC_NUM && factory_default.version_code == RUI_CFG_VERSION_CODE )
        {
            //If data recovery from legacy version successfully, store new default data to flash
            //udrv_flash_write(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&factory_default);
            factory_default_exist = true;
        }
    }
    
    memset(&g_rui_cfg_t, 0, sizeof(PRE_rui_cfg_t));

    if( factory_default_exist )
    {
        memcpy(&g_rui_cfg_t,&factory_default,sizeof(PRE_rui_cfg_t));
        return UDRV_RETURN_OK;
        //return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
    }
    g_rui_cfg_t.magic_num = RUI_CFG_MAGIC_NUM;
    g_rui_cfg_t.version_code = RUI_CFG_VERSION_CODE;

    for (int i = 0 ; i < SERIAL_MAX ; i++) {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
        g_rui_cfg_t.g_lora_cfg_t.tp_port[i] = 1;
#endif
#endif
        switch ((SERIAL_PORT)i) {
            case SERIAL_UART0:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_UART0_MODE;
                break;
            }
            case SERIAL_UART1:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_UART1_MODE;
                break;
            }
            case SERIAL_UART2:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_UART2_MODE;
                break;
            }
#ifdef SUPPORT_USB
            case SERIAL_USB0:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_USB0_MODE;
                break;
            }
#endif
#ifdef SUPPORT_BLE
            case SERIAL_BLE0:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_BLE0_MODE;
                break;
            }
#endif
#ifdef SUPPORT_NFC
            case SERIAL_NFC:
            {
                g_rui_cfg_t.mode_type[i] = DEFAULT_SERIAL_NFC_MODE;
                break;
            }
#endif
            default:
            {
                /* impossible to be here */
                return -UDRV_INTERNAL_ERR;
            }
        }
    }
    g_rui_cfg_t.baudrate = DEFAULT_SERIAL_BAUDRATE;
#ifdef SUPPORT_BLE
    memset(g_rui_cfg_t.g_ble_cfg_t.mac,0x00,sizeof(g_rui_cfg_t.g_ble_cfg_t.mac));
#endif

    memcpy(g_rui_cfg_t.serial_passwd, passwd, 8);
    g_rui_cfg_t.auto_sleep_time = 0;
    g_rui_cfg_t.atcmd_echo = 0;
    g_rui_cfg_t.debug_level = 0;
#ifdef SUPPORT_LORA
    /* lora work mode */
    g_rui_cfg_t.lora_work_mode = SERVICE_LORAWAN;

    /* lorawan configuration */
    #ifdef rak3172
    /* Only RAK3172 supports hardware high and low frequency detection */
    uint8_t hardware_freq = 0;
    hardware_freq =  BoardGetHardwareFreq();
    if(hardware_freq)
    {
        g_rui_cfg_t.g_lora_cfg_t.region = SERVICE_LORA_EU868;
    }
    else
    {
        g_rui_cfg_t.g_lora_cfg_t.region = SERVICE_LORA_CN470;
        for( int i = 0; i < REGION_NVM_CHANNELS_MASK_SIZE; i ++)
            g_rui_cfg_t.g_lora_cfg_t.ch_mask[i] = 0xffff;
    }
    #else
    g_rui_cfg_t.g_lora_cfg_t.region = SERVICE_LORA_EU868;
    #endif
    g_rui_cfg_t.g_lora_cfg_t.join_mode = SERVICE_LORA_OTAA;
    g_rui_cfg_t.g_lora_cfg_t.device_class = SERVICE_LORA_CLASS_A;
    g_rui_cfg_t.g_lora_cfg_t.confirm = SERVICE_LORA_NO_ACK;
    g_rui_cfg_t.g_lora_cfg_t.retry = 0;
    g_rui_cfg_t.g_lora_cfg_t.adr = true;
    g_rui_cfg_t.g_lora_cfg_t.dr = SERVICE_LORA_DR_0;
    g_rui_cfg_t.g_lora_cfg_t.tx_power = 0;
    g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable = true;
    g_rui_cfg_t.g_lora_cfg_t.jn1dl = 5000;
    g_rui_cfg_t.g_lora_cfg_t.jn2dl = 6000;
    g_rui_cfg_t.g_lora_cfg_t.rx1dl = 1000;
    g_rui_cfg_t.g_lora_cfg_t.rx2dl = 2000;
    g_rui_cfg_t.g_lora_cfg_t.pub_nwk_mode = true;
    g_rui_cfg_t.g_lora_cfg_t.join_start = false;
    g_rui_cfg_t.g_lora_cfg_t.auto_join = false;
    g_rui_cfg_t.g_lora_cfg_t.auto_join_period = 8;
    g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt = 0;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_enable = 0;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi = -80;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime = 5;
    g_rui_cfg_t.g_rui_cfg_ex.auto_sleep_level = 1;
    memset(g_rui_cfg_t.g_lora_cfg_t.McSession_group,0x00,4*sizeof(McSession_t));

    /* lora p2p configuration */
#ifdef rak3172
    /* Only RAK3172 supports hardware high and low frequency detection */
    hardware_freq =  BoardGetHardwareFreq();
    if(hardware_freq)
    {
        g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = 868000000; 
    }
    else
    {
        g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = 470000000; 
    }
#else
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = 868000000; // 150MHz - 960MHz
#endif
    g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact = 7;// 6 - 12
    g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth = 0; // 0 - 9 
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = 0;// 0: 4/5, 1: 4/6, 2: 4/7, 3: 4/8
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = 8;  // 2 - 65535
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = 14; // 5 - 22
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = false;
    g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate = 4915;
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = 5000 ;
    g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw = 20000 ;
    g_rui_cfg_t.g_rui_cfg_ex.iqinverted = false;
    g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout = 0;
    g_rui_cfg_t.g_rui_cfg_ex.syncword = LORA_MAC_PRIVATE_SYNCWORD;
    g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload = false;
    memset(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key, 0x00, sizeof(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key));
#endif
    if(sizeof(g_rui_cfg_t.firmware_ver) > strlen(sw_version))
    {
        memset(g_rui_cfg_t.firmware_ver,0x00,sizeof(g_rui_cfg_t.firmware_ver));
        memcpy(g_rui_cfg_t.firmware_ver,sw_version,strlen(sw_version));
    }
    else
        memcpy(g_rui_cfg_t.firmware_ver,sw_version,32);

    if(sizeof(g_rui_cfg_t.hwmodel) > strlen(model_id))
    {
        memset(g_rui_cfg_t.hwmodel,0x00,sizeof(g_rui_cfg_t.hwmodel));
        memcpy(g_rui_cfg_t.hwmodel,model_id,strlen(model_id));
    }
    else
        memcpy(g_rui_cfg_t.hwmodel,model_id,32);

    if(sizeof(g_rui_cfg_t.cli_ver) > strlen(cli_version))
    {
        memset(g_rui_cfg_t.cli_ver,0x00,sizeof(g_rui_cfg_t.cli_ver));
        memcpy(g_rui_cfg_t.cli_ver,cli_version,strlen(cli_version));
    }
    else
        memcpy(g_rui_cfg_t.cli_ver,cli_version,32);
    
    
    //return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
    return UDRV_RETURN_OK;
}

void service_nvm_init_config(void) {
    udrv_flash_read(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
    //Try to recovery legacy user data
    service_nvm_data_recovery_from_legacy(SERVICE_NVM_RUI_CONFIG_NVM_ADDR,&g_rui_cfg_t);
    if( g_rui_cfg_t.magic_num == RUI_CFG_MAGIC_NUM && g_rui_cfg_t.version_code == RUI_CFG_VERSION_CODE)
    {
        //udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
        return UDRV_RETURN_OK;
    }
    else
        service_nvm_set_default_config_to_nvm();
}

/***********************************************************/
/* RUI Mode                                                */
/***********************************************************/

SERVICE_MODE_TYPE service_nvm_get_mode_type_from_nvm(SERIAL_PORT port) {
    return g_rui_cfg_t.mode_type[port];
}

int32_t service_nvm_set_mode_type_to_nvm(SERIAL_PORT port, SERVICE_MODE_TYPE mode_type) {
    if (mode_type == g_rui_cfg_t.mode_type[port])
        return UDRV_RETURN_OK;
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
    if (memcmp(g_rui_cfg_t.serial_passwd,passwd,len) == 0)
        return UDRV_RETURN_OK;
    memset(g_rui_cfg_t.serial_passwd, 0, sizeof(g_rui_cfg_t.serial_passwd));
    memcpy(g_rui_cfg_t.serial_passwd, passwd, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_sleep_time_from_nvm(void) {
    return g_rui_cfg_t.auto_sleep_time;
}

int32_t service_nvm_set_auto_sleep_time_to_nvm(uint32_t time) {
    if (g_rui_cfg_t.auto_sleep_time == time)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.auto_sleep_time = time;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_auto_sleep_level_from_nvm(void) {
    return g_rui_cfg_t.g_rui_cfg_ex.auto_sleep_level;
}

uint8_t service_nvm_set_auto_sleep_level_to_nvm(uint32_t level) {
    if (g_rui_cfg_t.g_rui_cfg_ex.auto_sleep_level == level)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.firmware_ver,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.hwmodel,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.cli_ver,buff,len) == 0)
        return UDRV_RETURN_OK;
    memset(g_rui_cfg_t.cli_ver, 0 , sizeof(g_rui_cfg_t.cli_ver));
    memcpy(g_rui_cfg_t.cli_ver, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

/***********************************************************/
/* User Data                                               */
/***********************************************************/

int32_t service_nvm_write_user_data (uint32_t offset, uint8_t *buff, uint32_t len) {
    if (offset > (SERVICE_NVM_RUI_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR)) {
        return -UDRV_WRONG_ARG;
    }

    if (len > (SERVICE_NVM_RUI_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR - offset)) {
        return -UDRV_WRONG_ARG;
    }

    return udrv_flash_write(SERVICE_NVM_USER_DATA_NVM_ADDR+offset, len, buff);
}

int32_t service_nvm_read_user_data (uint32_t offset, uint8_t *buff, uint32_t len) {
    if (offset > (SERVICE_NVM_RUI_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR)) {
        return -UDRV_WRONG_ARG;
    }

    if (len > (SERVICE_NVM_RUI_CONFIG_NVM_ADDR - SERVICE_NVM_USER_DATA_NVM_ADDR - offset)) {
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
    if(g_rui_cfg_t.g_rtc_delta_t.seconds == sec)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rtc_delta_t.seconds = sec;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_delta_subsec_from_nvm (void) {
    return g_rui_cfg_t.g_rtc_delta_t.subseconds;
}

int32_t service_nvm_set_delta_subsec_to_nvm (uint32_t subsec) {
    if(g_rui_cfg_t.g_rtc_delta_t.subseconds == subsec)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rtc_delta_t.subseconds = subsec;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERIAL_WLOCK_STATE  service_nvm_get_lock_status_from_nvm(SERIAL_PORT Port) {
        return g_rui_cfg_t.serial_lock_status[Port];
}

int32_t service_nvm_set_lock_status_to_nvm(SERIAL_PORT Port, SERIAL_WLOCK_STATE wlock_state) {
    if(g_rui_cfg_t.serial_lock_status[Port] == wlock_state)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.serial_lock_status[Port] = wlock_state;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_baudrate_from_nvm(void) {
    return g_rui_cfg_t.baudrate;
}

int32_t service_nvm_set_baudrate_to_nvm(uint32_t baudrate) {
    if(g_rui_cfg_t.baudrate == baudrate)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.alias,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.sn,buff,len) == 0)
        return UDRV_RETURN_OK;
    memcpy(g_rui_cfg_t.sn, buff, len);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_atcmd_echo_from_nvm(void) {
    return g_rui_cfg_t.atcmd_echo;
}

int32_t service_nvm_set_atcmd_echo_to_nvm(uint8_t atcmd_echo) {
    if(g_rui_cfg_t.atcmd_echo == atcmd_echo)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.atcmd_echo = atcmd_echo;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_debug_level_to_nvm(uint8_t level)
{
    if(g_rui_cfg_t.debug_level == level)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_ble_cfg_t.mac,buff,sizeof(g_rui_cfg_t.g_ble_cfg_t.mac)) == 0)
        return UDRV_RETURN_OK;
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

#ifdef SUPPORT_LORA
/***********************************************************/
/* LoRa                                                    */
/***********************************************************/
SERVICE_LORA_BAND service_nvm_get_band_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.region;
}

int32_t service_nvm_set_band_to_nvm (SERVICE_LORA_BAND band) {
    if(g_rui_cfg_t.g_lora_cfg_t.region == band)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.region = band;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
int32_t service_nvm_get_mask_from_nvm (uint16_t *mask) {
    memcpy(mask, g_rui_cfg_t.g_lora_cfg_t.ch_mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_mask_to_nvm (uint16_t *mask) {
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.ch_mask,mask,sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask)) == 0)
        return UDRV_RETURN_OK;
    memcpy(g_rui_cfg_t.g_lora_cfg_t.ch_mask, mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
#endif

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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.app_eui,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.app_key,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.app_skey,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.dev_addr,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.dev_eui,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.nwk_id,buff,len) == 0)
        return UDRV_RETURN_OK;
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
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.nwk_skey,buff,len) == 0)
        return UDRV_RETURN_OK;
    memcpy(g_rui_cfg_t.g_lora_cfg_t.nwk_skey, buff, 16);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_retry_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.retry;
}

int32_t service_nvm_set_retry_to_nvm (uint8_t retry) {
    if(g_rui_cfg_t.g_lora_cfg_t.retry == retry)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.retry = retry;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CONFIRM_MODE service_nvm_get_cfm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.confirm;
}

int32_t service_nvm_set_cfm_to_nvm (SERVICE_LORA_CONFIRM_MODE cfm) {
    if(g_rui_cfg_t.g_lora_cfg_t.confirm == cfm)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.confirm = cfm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_WORK_MODE service_nvm_get_nwm_from_nvm (void) {
    return g_rui_cfg_t.lora_work_mode;
}

int32_t service_nvm_set_nwm_to_nvm (SERVICE_LORA_WORK_MODE nwm) {
    if(g_rui_cfg_t.lora_work_mode == nwm)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.lora_work_mode = nwm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_JOIN_MODE service_nvm_get_njm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_mode;
}

int32_t service_nvm_set_njm_to_nvm (SERVICE_LORA_JOIN_MODE njm) {
    if(g_rui_cfg_t.g_lora_cfg_t.join_mode == njm)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.join_mode = njm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_adr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.adr;
}

int32_t service_nvm_set_adr_to_nvm (bool adr) {
    if(g_rui_cfg_t.g_lora_cfg_t.adr == adr)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.adr = adr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CLASS service_nvm_get_class_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.device_class;
}

int32_t service_nvm_set_class_to_nvm (SERVICE_LORA_CLASS device_class) {
    if(g_rui_cfg_t.g_lora_cfg_t.device_class == device_class)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.device_class = device_class;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.dr;
}

int32_t service_nvm_set_dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    if(g_rui_cfg_t.g_lora_cfg_t.dr == dr)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.dr = dr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_rx2dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dr;
}

int32_t service_nvm_set_rx2dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    if(g_rui_cfg_t.g_lora_cfg_t.rx2dr == dr)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.rx2dr = dr;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


uint32_t service_nvm_get_jn1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn1dl;
}

int32_t service_nvm_set_jn1dl_to_nvm (uint32_t jn1dl) {
    if(g_rui_cfg_t.g_lora_cfg_t.jn1dl == jn1dl)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.jn1dl = jn1dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_jn2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn2dl;
}

int32_t service_nvm_set_jn2dl_to_nvm (uint32_t jn2dl) {
    if(g_rui_cfg_t.g_lora_cfg_t.jn2dl == jn2dl)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.jn2dl = jn2dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_rx2fq_to_nvm(uint32_t freq)
{
    if(g_rui_cfg_t.g_lora_cfg_t.rx2fq == freq)
        return UDRV_RETURN_OK;
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
    if(g_rui_cfg_t.g_lora_cfg_t.pub_nwk_mode == pnm)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.pub_nwk_mode = pnm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx1dl;
}

int32_t service_nvm_set_rx1dl_to_nvm (uint32_t rx1dl) {
    if(g_rui_cfg_t.g_lora_cfg_t.rx1dl == rx1dl)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.rx1dl = rx1dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dl;
}

int32_t service_nvm_set_rx2dl_to_nvm (uint32_t rx2dl) {
    if(g_rui_cfg_t.g_lora_cfg_t.rx2dl == rx2dl)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.rx2dl = rx2dl;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_txpower_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.tx_power;
}

int32_t service_nvm_set_txpower_to_nvm (uint8_t txp) {
    if(g_rui_cfg_t.g_lora_cfg_t.tx_power == txp)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.tx_power = txp;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_linkcheck_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode;
}

int32_t service_nvm_set_linkcheck_to_nvm (uint8_t mode) {
    if(g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode == mode)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode = mode;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_ping_slot_periodicity_from_nvm() {
    return g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity;
}

int32_t service_nvm_set_ping_slot_periodicity_to_nvm(uint8_t periodicity) {
    if(g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity == periodicity)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity = periodicity;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_join_start_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_start;
}

int32_t service_nvm_set_join_start_to_nvm(bool join_start) {
    if(g_rui_cfg_t.g_lora_cfg_t.join_start == join_start)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.join_start = join_start;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_auto_join_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join;
}

int32_t service_nvm_set_auto_join_to_nvm(bool auto_join) {
    if(g_rui_cfg_t.g_lora_cfg_t.auto_join == auto_join)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.auto_join = auto_join;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_period_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_period;
}

int32_t service_nvm_set_auto_join_period_to_nvm(uint32_t auto_join_period) {
    if(g_rui_cfg_t.g_lora_cfg_t.auto_join_period == auto_join_period)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.auto_join_period = auto_join_period;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_max_cnt_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt;
}

int32_t service_nvm_set_auto_join_max_cnt_to_nvm(uint32_t auto_join_max_cnt) {
    if(g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt == auto_join_max_cnt)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt = auto_join_max_cnt;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_freq_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency;
}

int32_t service_nvm_set_freq_to_nvm (uint32_t freq) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency == freq)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = freq;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_sf_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact;
}

int32_t service_nvm_set_sf_to_nvm (uint8_t spreadfact) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact == spreadfact)
        return UDRV_RETURN_OK;
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
        if(g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth == bandwidth)
            return UDRV_RETURN_OK;
        g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth = bandwidth;
    }
    else if ( g_rui_cfg_t.lora_work_mode == 2)
    {
        if(g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw == bandwidth)
            return UDRV_RETURN_OK;
        g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw = bandwidth;
    }

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_codingrate_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate;
}

int32_t service_nvm_set_codingrate_to_nvm (uint8_t codingrate) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate == codingrate)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = codingrate;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint16_t service_nvm_get_preamlen_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen;
}

int32_t service_nvm_set_preamlen_to_nvm (uint16_t preamlen) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen == preamlen)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = preamlen;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_powerdbm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm;
}

int32_t service_nvm_set_powerdbm_to_nvm (uint8_t powerdbm) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm == powerdbm)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = powerdbm;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_crypt_enable_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable;
}

int32_t service_nvm_set_crypt_enable_to_nvm (bool crypt_enable) {
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable == crypt_enable)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = crypt_enable;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_crypt_key_from_nvm (uint8_t *buff, uint32_t len) {
    if (len < 8) {
        return -UDRV_BUFF_OVERFLOW;
    }

    memcpy(buff, g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key, 8);

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_crypt_key_to_nvm (uint8_t *buff, uint32_t len) {
    if (len != 8) {
        return -UDRV_WRONG_ARG;
    }
    if(memcmp(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key,buff,len) == 0)
        return UDRV_RETURN_OK;
    memcpy(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key, buff, 8);

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

McSession_t *service_nvm_get_multicast_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.McSession_group;
}

int32_t service_nvm_set_multicast_to_nvm(McSession_t *McSession) {
    if(memcmp(g_rui_cfg_t.g_lora_cfg_t.McSession_group,McSession,4*sizeof(McSession_t)) == 0)
        return UDRV_RETURN_OK;
    memcpy(g_rui_cfg_t.g_lora_cfg_t.McSession_group, McSession ,4*sizeof(McSession_t));

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_tp_port_from_nvm(SERIAL_PORT port) {
    return g_rui_cfg_t.g_lora_cfg_t.tp_port[port];
}

int32_t service_nvm_set_tp_port_to_nvm(SERIAL_PORT port, uint8_t tp_port) {
    if (tp_port >= 1 && tp_port <= 223) {
        if(g_rui_cfg_t.g_lora_cfg_t.tp_port[port] == tp_port)
            return UDRV_RETURN_OK;
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
    if(g_rui_cfg_t.g_lora_cfg_t.chs == frequency)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_cfg_t.chs = frequency;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


uint32_t service_nvm_set_fdev_to_nvm(uint32_t fdev) 
{
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.deviation == fdev)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = fdev;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_bitrate_to_nvm(uint32_t bitrate) 
{
    if(g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate == bitrate)
        return UDRV_RETURN_OK;
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
    if(g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable == dutycycle)
        return UDRV_RETURN_OK;
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
    if(g_rui_cfg_t.g_rui_cfg_ex.iqinverted == iqinverted)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.iqinverted = iqinverted;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_symbol_timeout_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout;
}

int32_t service_nvm_set_symbol_timeout_to_nvm(uint32_t symbol_timeout)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout == symbol_timeout)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.symbol_timeout = symbol_timeout;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_fix_length_payload_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload;
}

int32_t service_nvm_set_fix_length_payload_to_nvm(bool enable)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload == enable)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.fix_length_payload = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint16_t service_nvm_get_syncword_from_nvm(void)
{
    return g_rui_cfg_t.g_rui_cfg_ex.syncword;
}

int32_t service_nvm_set_syncword_to_nvm( uint16_t syncword)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.syncword == syncword)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.syncword = syncword;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int32_t service_nvm_get_lbt_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_enable;
}

int32_t service_nvm_set_lbt_to_nvm(uint8_t enable)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.lbt_enable == enable)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_enable = enable;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

int16_t service_nvm_get_lbt_rssi_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi;
}

int32_t service_nvm_set_lbt_rssi_to_nvm(int16_t rssi)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi == rssi)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_rssi = rssi;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_lbt_scantime_from_nvm()
{
    return g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime;
}

int32_t service_nvm_set_lbt_scantime_to_nvm(uint32_t time)
{
    if(g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime == time)
        return UDRV_RETURN_OK;
    g_rui_cfg_t.g_rui_cfg_ex.lbt_scantime = time;
    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


#endif

static void service_nvm_data_recovery_from_legacy(uint32_t data_flash_addr, PRE_rui_cfg_t *rui_cfg_cur)
{
    uint8_t data_legacy[800];
    uint32_t version_code = 0;
    #define DATA_ADDR(LegacyOffset) (data_legacy + LegacyOffset)

    //Get the software version of user data
    udrv_flash_read(data_flash_addr, sizeof(data_legacy), data_legacy );
    if( rui_cfg_cur->magic_num == RUI_CFG_MAGIC_NUM )
        version_code = rui_cfg_cur->version_code;
    #if defined(rak3172) || defined(rak3172_sip) || defined(rak4630) || defined(rak11720) //V99 V87 V85 only support 3172 / 3172-sip / 4630
    //Check legacy version v99
    if( *((uint32_t*)(data_legacy + ELEM_OFS_V99_magic)) == 0xEDD1E)
    {
        version_code = RUI_VERSION_CODE_V99;
    }
    //Check legacy version v87
    if( *((uint32_t*)(data_legacy + ELEM_OFS_V87_crc_verify)) == Crc32(((uint8_t*)&g_rui_cfg_t)+sizeof(uint32_t),RUI_CFG_V87_SZ-sizeof(uint32_t)) )
    {
        version_code = RUI_VERSION_CODE_V87;
    }
    //Check legacy version v85
    if( *((uint32_t*)(data_legacy + ELEM_OFS_V85_crc_verify)) == Crc32(((uint8_t*)&g_rui_cfg_t)+sizeof(uint32_t),RUI_CFG_V85_SZ-sizeof(uint32_t)) )
    {
        version_code = RUI_VERSION_CODE_V85;
    }
    #endif

    memset(rui_cfg_cur, 0, sizeof(PRE_rui_cfg_t));
    //When version code is matched, can move user data to current firmware. The way of moving should be define when develop new version.
    //Also need to consider default values for items that do not exist in older version in rui_cfg_t.
    if( version_code == 0 )
    {
        //The historical version could not be determined
        return;
    }
    #if defined(rak3172) || defined(rak3172_sip) || defined(rak4630) || defined(rak11720) //V87 and V85 , V99 only support 3172/3172-sip/4630
    else if( version_code == RUI_VERSION_CODE_V85 )
    {
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->lora_work_mode,    DATA_ADDR(ELEM_OFS_V85_lora_work_mode),     sizeof(rui_cfg_cur->lora_work_mode) );
        memcpy(&rui_cfg_cur->g_lora_p2p_cfg_t,  DATA_ADDR(ELEM_OFS_V85_g_lora_p2p_cfg_t),   sizeof(rui_cfg_cur->g_lora_p2p_cfg_t) );
        #endif
        #ifdef SUPPORT_BLE
        memcpy(&rui_cfg_cur->g_ble_cfg_t,       DATA_ADDR(ELEM_OFS_V85_g_ble_cfg_t),        sizeof(rui_cfg_cur->g_ble_cfg_t) );
        #endif
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->g_lora_cfg_t,      DATA_ADDR(ELEM_OFS_V85_g_lora_cfg_t),       sizeof(rui_cfg_cur->g_lora_cfg_t) );
        #endif
        memcpy(&rui_cfg_cur->g_rtc_delta_t,     DATA_ADDR(ELEM_OFS_V85_g_rtc_delta_t),      sizeof(rui_cfg_cur->g_rtc_delta_t) );
        memcpy(rui_cfg_cur->mode_type,          DATA_ADDR(ELEM_OFS_V85_mode_type),          sizeof(rui_cfg_cur->mode_type) );
        memcpy(&rui_cfg_cur->baudrate,          DATA_ADDR(ELEM_OFS_V85_baudrate),           sizeof(rui_cfg_cur->baudrate) );
        memcpy(&rui_cfg_cur->atcmd_echo,        DATA_ADDR(ELEM_OFS_V85_atcmd_echo),         sizeof(rui_cfg_cur->atcmd_echo) );
        memcpy(rui_cfg_cur->serial_passwd,      DATA_ADDR(ELEM_OFS_V85_serial_passwd),      sizeof(rui_cfg_cur->serial_passwd) );
        memcpy(&rui_cfg_cur->auto_sleep_time,   DATA_ADDR(ELEM_OFS_V85_auto_sleep_time),    sizeof(rui_cfg_cur->auto_sleep_time) );
        memcpy(rui_cfg_cur->sn,                 DATA_ADDR(ELEM_OFS_V85_sn),                 sizeof(rui_cfg_cur->sn) );
        memcpy(rui_cfg_cur->alias,              DATA_ADDR(ELEM_OFS_V85_alias),              sizeof(rui_cfg_cur->alias) );
        //The following does not exist in this historical release
        memset(&rui_cfg_cur->serial_lock_status,0,sizeof(rui_cfg_cur->serial_lock_status));
        service_nvm_data_add_to_legacy(rui_cfg_cur);
    }
    else if( version_code == RUI_VERSION_CODE_V87 )
    {
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->lora_work_mode,    DATA_ADDR(ELEM_OFS_V87_lora_work_mode),     sizeof(rui_cfg_cur->lora_work_mode) );
        memcpy(&rui_cfg_cur->g_lora_p2p_cfg_t,  DATA_ADDR(ELEM_OFS_V87_g_lora_p2p_cfg_t),   sizeof(rui_cfg_cur->g_lora_p2p_cfg_t) );
        #endif
        #ifdef SUPPORT_BLE
        memcpy(&rui_cfg_cur->g_ble_cfg_t,       DATA_ADDR(ELEM_OFS_V87_g_ble_cfg_t),        sizeof(rui_cfg_cur->g_ble_cfg_t) );
        #endif
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->g_lora_cfg_t,      DATA_ADDR(ELEM_OFS_V87_g_lora_cfg_t),       sizeof(rui_cfg_cur->g_lora_cfg_t) );
        #endif
        memcpy(&rui_cfg_cur->g_rtc_delta_t,     DATA_ADDR(ELEM_OFS_V87_g_rtc_delta_t),      sizeof(rui_cfg_cur->g_rtc_delta_t) );
        memcpy(rui_cfg_cur->mode_type,          DATA_ADDR(ELEM_OFS_V87_mode_type),          sizeof(rui_cfg_cur->mode_type) );
        memcpy(rui_cfg_cur->serial_lock_status, DATA_ADDR(ELEM_OFS_V87_serial_lock_status), sizeof(rui_cfg_cur->serial_lock_status) );
        memcpy(&rui_cfg_cur->baudrate,          DATA_ADDR(ELEM_OFS_V87_baudrate),           sizeof(rui_cfg_cur->baudrate) );
        memcpy(&rui_cfg_cur->atcmd_echo,        DATA_ADDR(ELEM_OFS_V87_atcmd_echo),         sizeof(rui_cfg_cur->atcmd_echo) );
        memcpy(rui_cfg_cur->serial_passwd,      DATA_ADDR(ELEM_OFS_V87_serial_passwd),      sizeof(rui_cfg_cur->serial_passwd) );
        memcpy(&rui_cfg_cur->auto_sleep_time,   DATA_ADDR(ELEM_OFS_V87_auto_sleep_time),    sizeof(rui_cfg_cur->auto_sleep_time) );
        memcpy(rui_cfg_cur->sn,                 DATA_ADDR(ELEM_OFS_V87_sn),                 sizeof(rui_cfg_cur->sn) );
        memcpy(rui_cfg_cur->alias,              DATA_ADDR(ELEM_OFS_V87_alias),              sizeof(rui_cfg_cur->alias) );
        service_nvm_data_add_to_legacy(rui_cfg_cur);
    }
    else if( version_code == RUI_VERSION_CODE_V99 )
    {
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->lora_work_mode,    DATA_ADDR(ELEM_OFS_V99_lora_work_mode),     sizeof(rui_cfg_cur->lora_work_mode) );
        memcpy(&rui_cfg_cur->g_lora_p2p_cfg_t,  DATA_ADDR(ELEM_OFS_V99_g_lora_p2p_cfg_t),   sizeof(rui_cfg_cur->g_lora_p2p_cfg_t) );
        #endif
        #ifdef SUPPORT_BLE
        memcpy(&rui_cfg_cur->g_ble_cfg_t,       DATA_ADDR(ELEM_OFS_V99_g_ble_cfg_t),        sizeof(rui_cfg_cur->g_ble_cfg_t) );
        #endif
        #ifdef SUPPORT_LORA
        memcpy(&rui_cfg_cur->g_lora_cfg_t,      DATA_ADDR(ELEM_OFS_V99_g_lora_cfg_t),       sizeof(rui_cfg_cur->g_lora_cfg_t) );
        #endif
        memcpy(&rui_cfg_cur->g_rtc_delta_t,     DATA_ADDR(ELEM_OFS_V99_g_rtc_delta_t),      sizeof(rui_cfg_cur->g_rtc_delta_t) );
        memcpy(rui_cfg_cur->mode_type,          DATA_ADDR(ELEM_OFS_V99_mode_type),          sizeof(rui_cfg_cur->mode_type) );
        memcpy(rui_cfg_cur->serial_lock_status, DATA_ADDR(ELEM_OFS_V99_serial_lock_status), sizeof(rui_cfg_cur->serial_lock_status) );
        memcpy(&rui_cfg_cur->baudrate,          DATA_ADDR(ELEM_OFS_V99_baudrate),           sizeof(rui_cfg_cur->baudrate) );
        memcpy(&rui_cfg_cur->atcmd_echo,        DATA_ADDR(ELEM_OFS_V99_atcmd_echo),         sizeof(rui_cfg_cur->atcmd_echo) );
        memcpy(rui_cfg_cur->serial_passwd,      DATA_ADDR(ELEM_OFS_V99_serial_passwd),      sizeof(rui_cfg_cur->serial_passwd) );
        memcpy(&rui_cfg_cur->auto_sleep_time,   DATA_ADDR(ELEM_OFS_V99_auto_sleep_time),    sizeof(rui_cfg_cur->auto_sleep_time) );
        memcpy(rui_cfg_cur->sn,                 DATA_ADDR(ELEM_OFS_V99_sn),                 sizeof(rui_cfg_cur->sn) );
        memcpy(rui_cfg_cur->alias,              DATA_ADDR(ELEM_OFS_V99_alias),              sizeof(rui_cfg_cur->alias) );
        service_nvm_data_add_to_legacy(rui_cfg_cur);
    }
    #endif
    else if( version_code == RUI_VERSION_CODE_LATEST )
    {
        memcpy(rui_cfg_cur,                     data_legacy,                                sizeof(PRE_rui_cfg_t) );
        //add new config
#ifdef SUPPORT_LORA
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.iqinverted == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.iqinverted = false;
        if(rui_cfg_cur->g_rui_cfg_ex.symbol_timeout > SYMBTIMEOUT_MAX)
            rui_cfg_cur->g_rui_cfg_ex.symbol_timeout = 0;
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.syncword_dirty_byte == 0xFF)
        {
            rui_cfg_cur->g_rui_cfg_ex.syncword = LORA_MAC_PRIVATE_SYNCWORD;
            rui_cfg_cur->g_rui_cfg_ex.syncword_dirty_byte =0;
        }
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.fix_length_payload == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.fix_length_payload = false;
#endif
        if(*(uint8_t*)&rui_cfg_cur->debug_level == 0xFF)
            rui_cfg_cur->debug_level = 0;

        if(*(uint8_t*)&rui_cfg_cur->firmware_ver == 0xFF)
        {
            memset(rui_cfg_cur->firmware_ver,'\0',sizeof(rui_cfg_cur->firmware_ver));
            memcpy(rui_cfg_cur->firmware_ver,sw_version,strlen(sw_version));
        }

        if(*(uint8_t*)&rui_cfg_cur->hwmodel == 0xFF)
        {
            memset(rui_cfg_cur->hwmodel,'\0',sizeof(rui_cfg_cur->hwmodel));
            memcpy(rui_cfg_cur->hwmodel,model_id,strlen(model_id));
        }

        if(*(uint8_t*)&rui_cfg_cur->cli_ver == 0xFF)
        {
            memset(rui_cfg_cur->cli_ver,'\0',sizeof(rui_cfg_cur->cli_ver));
            memcpy(rui_cfg_cur->cli_ver,cli_version,strlen(cli_version));
        }
#ifdef SUPPORT_LORA
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_enable == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_enable = 0;
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_rssi == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_rssi = -80;
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_scantime == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_scantime = 5;
#endif
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level = 1;
    }
    else
    {
        //The historical version could not be determined
        return;
    }
    //The user data move from legacy version successfully, then can check value of "magic_num" and "version_code" to see the result.
    rui_cfg_cur->magic_num = RUI_CFG_MAGIC_NUM;
    rui_cfg_cur->version_code = RUI_CFG_VERSION_CODE;

}
void service_nvm_data_add_to_legacy(PRE_rui_cfg_t *rui_cfg_cur)
{
#ifdef SUPPORT_LORA
    rui_cfg_cur->g_rui_cfg_ex.iqinverted = false;
    rui_cfg_cur->g_rui_cfg_ex.symbol_timeout = 0;
    rui_cfg_cur->g_rui_cfg_ex.syncword = LORA_MAC_PRIVATE_SYNCWORD;
    rui_cfg_cur->g_rui_cfg_ex.syncword_dirty_byte =0;
    rui_cfg_cur->g_rui_cfg_ex.fix_length_payload = false;
#endif
    rui_cfg_cur->debug_level = 0;
    memset(rui_cfg_cur->firmware_ver,'\0',sizeof(rui_cfg_cur->firmware_ver));
    memcpy(rui_cfg_cur->firmware_ver,sw_version,strlen(sw_version));
    memset(rui_cfg_cur->hwmodel,'\0',sizeof(rui_cfg_cur->hwmodel));
    memcpy(rui_cfg_cur->hwmodel,model_id,strlen(model_id));
    memset(rui_cfg_cur->cli_ver,'\0',sizeof(rui_cfg_cur->cli_ver));
    memcpy(rui_cfg_cur->cli_ver,cli_version,strlen(cli_version));
#ifdef SUPPORT_LORA
    rui_cfg_cur->g_rui_cfg_ex.lbt_enable = 0;
    rui_cfg_cur->g_rui_cfg_ex.lbt_rssi = -80;
    rui_cfg_cur->g_rui_cfg_ex.lbt_scantime = 5;
    rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level = 1;
#endif
}


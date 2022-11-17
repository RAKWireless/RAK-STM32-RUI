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

rui_cfg_t g_rui_cfg_t;

#define SERVICE_RUI_CONFIG_CRC32(x) Crc32(((uint8_t*)x)+sizeof(uint32_t),sizeof(rui_cfg_t)-sizeof(uint32_t))

int32_t service_nvm_store_config(uint32_t flash_addr, rui_cfg_t *cfg);
int32_t service_nvm_read_config(uint32_t flash_addr, rui_cfg_t *cfg);

void MemPrint( uint8_t *buf, uint32_t len)
{
    for( uint32_t i = 0; i < len; )
    {
        udrv_serial_log_printf("%08X %06d | ",i,i);
        for( uint32_t j = 0; j < 4 && i + j*4 < len ; j++)
        {
            udrv_serial_log_printf("%02X%02X%02X%02X ",buf[i+j+3],buf[i+j+2],buf[i+j+1],buf[i+j]);
        }
        udrv_serial_log_printf("\r\n");
        i+=16;
    }
}

int32_t service_nvm_set_default_config_to_nvm(void) {
    uint8_t passwd[8] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};
    rui_cfg_t factory_default;
    bool factory_default_exist = false;

    // udrv_flash_read(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&factory_default);
    service_nvm_read_config(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR,&factory_default);

    if( factory_default.magic_num == RUI_CFG_MAGIC_NUM )
    {
        factory_default_exist = true;
    }
    
    memset(&g_rui_cfg_t, 0, sizeof(rui_cfg_t));

    if( factory_default_exist )
    {
        memcpy(&g_rui_cfg_t,&factory_default,sizeof(rui_cfg_t));
        return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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
    g_rui_cfg_t.auto_sleep_time = 1;
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
    g_rui_cfg_t.g_lora_p2p_cfg_t.iqinverted = false;
    g_rui_cfg_t.g_lora_p2p_cfg_t.symbol_timeout = 0;
    g_rui_cfg_t.g_lora_p2p_cfg_t.syncword = LORA_MAC_PUBLIC_SYNCWORD;
    g_rui_cfg_t.g_lora_p2p_cfg_t.fix_length_payload = false;
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

void service_nvm_init_config(void) {
    // udrv_serial_log_printf("service_nvm_init_config\r\n");
    service_nvm_read_config(SERVICE_NVM_RUI_CONFIG_NVM_ADDR,&g_rui_cfg_t);
    // udrv_serial_log_printf("Get magic num %08X\r\n",g_rui_cfg_t.magic_num);
    if (g_rui_cfg_t.magic_num != RUI_CFG_MAGIC_NUM )
    {
        // udrv_serial_log_printf("Set default config\r\n");
        service_nvm_set_default_config_to_nvm();
    }
}

/***********************************************************/
/* RUI Mode                                                */
/***********************************************************/

SERVICE_MODE_TYPE service_nvm_get_mode_type_from_nvm(SERIAL_PORT port) {
    return g_rui_cfg_t.mode_type[port];
}

int32_t service_nvm_set_mode_type_to_nvm(SERIAL_PORT port, SERVICE_MODE_TYPE mode_type) {
    g_rui_cfg_t.mode_type[port] = mode_type;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_sleep_time_from_nvm(void) {
    return g_rui_cfg_t.auto_sleep_time;
}

int32_t service_nvm_set_auto_sleep_time_to_nvm(uint32_t time) {
    g_rui_cfg_t.auto_sleep_time = time;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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
    g_rui_cfg_t.g_rtc_delta_t.seconds = sec;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_delta_subsec_from_nvm (void) {
    return g_rui_cfg_t.g_rtc_delta_t.subseconds;
}

int32_t service_nvm_set_delta_subsec_to_nvm (uint32_t subsec) {
    g_rui_cfg_t.g_rtc_delta_t.subseconds = subsec;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERIAL_WLOCK_STATE  service_nvm_get_lock_status_from_nvm(SERIAL_PORT Port) {
        return g_rui_cfg_t.serial_lock_status[Port];
}

int32_t service_nvm_set_lock_status_to_nvm(SERIAL_PORT Port, SERIAL_WLOCK_STATE wlock_state) {
    g_rui_cfg_t.serial_lock_status[Port] = wlock_state;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_baudrate_from_nvm(void) {
    return g_rui_cfg_t.baudrate;
}

int32_t service_nvm_set_baudrate_to_nvm(uint32_t baudrate) {
    g_rui_cfg_t.baudrate = baudrate;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_atcmd_echo_from_nvm(void) {
    return g_rui_cfg_t.atcmd_echo;
}

int32_t service_nvm_set_atcmd_echo_to_nvm(uint8_t atcmd_echo) {
    g_rui_cfg_t.atcmd_echo = atcmd_echo;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_set_debug_level_to_nvm(uint8_t level)
{
    g_rui_cfg_t.debug_level = level;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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
    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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
    g_rui_cfg_t.g_lora_cfg_t.region = band;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
int32_t service_nvm_get_mask_from_nvm (uint16_t *mask) {
    memcpy(mask, g_rui_cfg_t.g_lora_cfg_t.ch_mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_mask_to_nvm (uint16_t *mask) {
    memcpy(g_rui_cfg_t.g_lora_cfg_t.ch_mask, mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    memcpy(g_rui_cfg_t.g_lora_cfg_t.app_eui, buff, 8);

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_retry_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.retry;
}

int32_t service_nvm_set_retry_to_nvm (uint8_t retry) {
    g_rui_cfg_t.g_lora_cfg_t.retry = retry;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_CONFIRM_MODE service_nvm_get_cfm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.confirm;
}

int32_t service_nvm_set_cfm_to_nvm (SERVICE_LORA_CONFIRM_MODE cfm) {
    g_rui_cfg_t.g_lora_cfg_t.confirm = cfm;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_WORK_MODE service_nvm_get_nwm_from_nvm (void) {
    return g_rui_cfg_t.lora_work_mode;
}

int32_t service_nvm_set_nwm_to_nvm (SERVICE_LORA_WORK_MODE nwm) {
    g_rui_cfg_t.lora_work_mode = nwm;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_JOIN_MODE service_nvm_get_njm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_mode;
}

int32_t service_nvm_set_njm_to_nvm (SERVICE_LORA_JOIN_MODE njm) {
    g_rui_cfg_t.g_lora_cfg_t.join_mode = njm;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

bool service_nvm_get_adr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.adr;
}

int32_t service_nvm_set_adr_to_nvm (bool adr) {
    g_rui_cfg_t.g_lora_cfg_t.adr = adr;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_CLASS service_nvm_get_class_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.device_class;
}

int32_t service_nvm_set_class_to_nvm (SERVICE_LORA_CLASS device_class) {
    g_rui_cfg_t.g_lora_cfg_t.device_class = device_class;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.dr;
}

int32_t service_nvm_set_dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.dr = dr;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_rx2dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dr;
}

int32_t service_nvm_set_rx2dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dr = dr;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}


uint32_t service_nvm_get_jn1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn1dl;
}

int32_t service_nvm_set_jn1dl_to_nvm (uint32_t jn1dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn1dl = jn1dl;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_jn2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn2dl;
}

int32_t service_nvm_set_jn2dl_to_nvm (uint32_t jn2dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn2dl = jn2dl;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_set_rx2fq_to_nvm(uint32_t freq)
{
    g_rui_cfg_t.g_lora_cfg_t.rx2fq = freq;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_rx1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx1dl;
}

int32_t service_nvm_set_rx1dl_to_nvm (uint32_t rx1dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx1dl = rx1dl;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_rx2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dl;
}

int32_t service_nvm_set_rx2dl_to_nvm (uint32_t rx2dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dl = rx2dl;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_txpower_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.tx_power;
}

int32_t service_nvm_set_txpower_to_nvm (uint8_t txp) {
    g_rui_cfg_t.g_lora_cfg_t.tx_power = txp;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_linkcheck_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode;
}

int32_t service_nvm_set_linkcheck_to_nvm (uint8_t mode) {
    g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode = mode;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_ping_slot_periodicity_from_nvm() {
    return g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity;
}

int32_t service_nvm_set_ping_slot_periodicity_to_nvm(uint8_t periodicity) {
    g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity = periodicity;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

bool service_nvm_get_join_start_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_start;
}

int32_t service_nvm_set_join_start_to_nvm(bool join_start) {
    g_rui_cfg_t.g_lora_cfg_t.join_start = join_start;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

bool service_nvm_get_auto_join_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join;
}

int32_t service_nvm_set_auto_join_to_nvm(bool auto_join) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join = auto_join;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_period_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_period;
}

int32_t service_nvm_set_auto_join_period_to_nvm(uint32_t auto_join_period) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_period = auto_join_period;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_max_cnt_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt;
}

int32_t service_nvm_set_auto_join_max_cnt_to_nvm(uint32_t auto_join_max_cnt) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt = auto_join_max_cnt;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_freq_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency;
}

int32_t service_nvm_set_freq_to_nvm (uint32_t freq) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = freq;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_sf_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact;
}

int32_t service_nvm_set_sf_to_nvm (uint8_t spreadfact) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact = spreadfact;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_codingrate_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate;
}

int32_t service_nvm_set_codingrate_to_nvm (uint8_t codingrate) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = codingrate;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint16_t service_nvm_get_preamlen_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen;
}

int32_t service_nvm_set_preamlen_to_nvm (uint16_t preamlen) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = preamlen;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_powerdbm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm;
}

int32_t service_nvm_set_powerdbm_to_nvm (uint8_t powerdbm) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = powerdbm;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

bool service_nvm_get_crypt_enable_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable;
}

int32_t service_nvm_set_crypt_enable_to_nvm (bool crypt_enable) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = crypt_enable;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    memcpy(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key, buff, 8);

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

McSession_t *service_nvm_get_multicast_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.McSession_group;
}

int32_t service_nvm_set_multicast_to_nvm(McSession_t *McSession) {
    memcpy(g_rui_cfg_t.g_lora_cfg_t.McSession_group, McSession ,4*sizeof(McSession_t));

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_rui_get_chs_from_nvm(void) 
{
    return g_rui_cfg_t.g_lora_cfg_t.chs;
}

uint32_t service_rui_set_chs_to_nvm(uint32_t frequency) 
{
    g_rui_cfg_t.g_lora_cfg_t.chs = frequency;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}


uint32_t service_nvm_set_fdev_to_nvm(uint32_t fdev) 
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = fdev;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_set_bitrate_to_nvm(uint32_t bitrate) 
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate = bitrate;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
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

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint8_t service_nvm_get_dcs_from_nvm()
{
    return g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable;
}

bool service_nvm_get_iqinverted_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.iqinverted;
}

int32_t service_nvm_set_iqinverted_to_nvm(bool iqinverted)
{

    g_rui_cfg_t.g_lora_p2p_cfg_t.iqinverted = iqinverted;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint32_t service_nvm_get_symbol_timeout_from_nvm(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.symbol_timeout;
}

int32_t service_nvm_set_symbol_timeout_to_nvm(uint32_t symbol_timeout)
{

    g_rui_cfg_t.g_lora_p2p_cfg_t.symbol_timeout = symbol_timeout;

    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

bool service_nvm_get_fix_length_payload(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.fix_length_payload;
}

int32_t service_nvm_set_fix_length_payload(bool enable)
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.fix_length_payload = enable;
    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

uint16_t service_nvm_get_syncword(void)
{
    return g_rui_cfg_t.g_lora_p2p_cfg_t.syncword;
}

int32_t service_nvm_set_syncword( uint16_t syncword)
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.syncword = syncword;
    return service_nvm_store_config( SERVICE_NVM_RUI_CONFIG_NVM_ADDR, &g_rui_cfg_t);
}

#endif


#define ARRAY_CPY(Array1,Array2)    memcpy(Array1,Array2,sizeof(Array1))
typedef struct
{
    uint32_t crc_verify;
    uint32_t store_size;
    uint32_t magic_num;
    uint32_t version_code;

#ifdef SUPPORT_LORA
    uint8_t lora_work_mode;
    // -- follow as S_LORAP2P_PARAM g_lora_p2p_cfg_t;
    uint32_t lorap2p_cfg_Frequency;
    uint8_t  lorap2p_cfg_Spreadfact;
    uint16_t  lorap2p_cfg_Bandwidth; 
    uint8_t  lorap2p_cfg_Codingrate; 
    uint16_t  lorap2p_cfg_Preamlen; 
    uint8_t  lorap2p_cfg_Powerdbm;	
    uint8_t  lorap2p_cfg_p2p_workmode;
    bool lorap2p_cfg_crypt_enable;
    uint8_t lorap2p_cfg_crypt_key[8];
    uint32_t lorap2p_cfg_bitrate;
    uint32_t lorap2p_cfg_deviation;
    uint32_t lorap2p_cfg_fsk_rxbw;

    // follow as lora_cfg_t g_lora_cfg_t;
    SERVICE_LORA_BAND lora_cfg_region;
    uint8_t lora_cfg_dev_eui[8];
    uint8_t lora_cfg_app_eui[8];
    uint8_t lora_cfg_app_key[16];
    uint8_t lora_cfg_app_skey[16];
    uint8_t lora_cfg_dev_addr[4];
    uint8_t lora_cfg_nwk_id[4];
    uint8_t lora_cfg_nwk_skey[16];
    uint32_t lora_cfg_multi_dev_addr;
    uint8_t lora_cfg_multi_nwks_key[16];
    uint8_t lora_cfg_multi_apps_key[16];
    bool lora_cfg_MulticastEnable;
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
    uint16_t lora_cfg_ch_mask[REGION_NVM_CHANNELS_MASK_SIZE];
#endif
    SERVICE_LORA_JOIN_MODE lora_cfg_join_mode;
    SERVICE_LORA_CLASS lora_cfg_device_class;
    uint8_t lora_cfg_confirm;
    uint8_t lora_cfg_retry;
    SERVICE_LORA_DATA_RATE lora_cfg_dr;
    SERVICE_LORA_DATA_RATE lora_cfg_rx2dr;
    bool lora_cfg_adr;
    uint8_t lora_cfg_tx_power;
    uint8_t lora_cfg_DutycycleEnable;
    uint32_t lora_cfg_jn1dl;
    uint32_t lora_cfg_jn2dl;
    uint32_t lora_cfg_rx1dl;
    uint32_t lora_cfg_rx2dl;
    uint32_t lora_cfg_rx2fq;
    bool lora_cfg_pub_nwk_mode;
    uint8_t lora_cfg_linkcheck_mode;
    uint8_t lora_cfg_ping_slot_periodicity;
    bool lora_cfg_join_start;
    bool lora_cfg_auto_join;
    uint32_t lora_cfg_auto_join_period;
    uint32_t lora_cfg_auto_join_max_cnt;
    McSession_t lora_cfg_McSession_group[4];
    uint32_t lora_cfg_chs;
    uint8_t lora_cfg_tp_port[SERIAL_MAX];
#endif

#ifdef SUPPORT_BLE
    // follow as ble_central_cfg_t g_ble_cfg_t;
    uint8_t ble_central_cfg_work_mode;  // 0:ble peripheral  1:ble central  2:ble observer 
    uint8_t ble_central_cfg_long_range_enable;
    uint8_t ble_central_cfg_mac[12];
    uint8_t ble_central_cfg_reserve[14];
#endif

    // follow as rtc_delta_t g_rtc_delta_t;
    uint32_t rtc_delta_seconds;
    uint32_t rtc_delta_subseconds;
    
    SERVICE_MODE_TYPE mode_type[SERIAL_MAX];
    SERIAL_WLOCK_STATE serial_lock_status[SERIAL_MAX];

#ifdef RAK5010_EVB
    // follow as cellular_cfg_t g_cellular_cfg_t
    uint8_t cellular_server_ip[20];
    uint8_t cellular_server_port[20];    	
    uint8_t cellular_operator_long_data[20]; 
    uint8_t cellular_operator_short_data[20]; 
    uint8_t cellular_operator_apn_data[20];
    uint8_t cellular_operator_net_data[20];
    uint8_t cellular_hologram_card_num[20];
#endif

    uint32_t baudrate;
    uint8_t atcmd_echo;
    uint8_t serial_passwd[9];
    uint32_t auto_sleep_time;
    uint8_t sn[18];
    uint8_t alias[16];
    uint8_t debug_level;
    uint8_t firmware_ver[32];
    uint8_t hwmodel[32];
    uint8_t cli_ver[32];

    //Follows are added at g_lora_p2p_cfg_t by Shadcai in 2022-9-22
    bool lorap2p_cfg_iqinverted;
    uint32_t lorap2p_cfg_symbol_timeout;
    uint16_t lorap2p_cfg_syncword;
    bool lorap2p_cfg_fix_length_payload;

    //If there are new parameters in the CFG, declare a new variable of the same type before here.
}STORE_REOGANIZED;

#define SERVICE_STORE_CRC32(x) Crc32(((uint8_t*)x)+sizeof(uint32_t),sizeof(STORE_REOGANIZED)-sizeof(uint32_t))

int32_t service_nvm_store_config(uint32_t flash_addr, rui_cfg_t *cfg)
{
    STORE_REOGANIZED store;
    store.store_size                            = sizeof(STORE_REOGANIZED);
    store.version_code                          = cfg->version_code;
#ifdef SUPPORT_LORA
    store.lora_work_mode                        = cfg->lora_work_mode;
    // -- follow as S_LORAP2P_PARAM g_lora_p2p_cfg_t;
    store.lorap2p_cfg_Frequency                 = cfg->g_lora_p2p_cfg_t.Frequency;
    store.lorap2p_cfg_Spreadfact                = cfg->g_lora_p2p_cfg_t.Spreadfact;
    store.lorap2p_cfg_Bandwidth                 = cfg->g_lora_p2p_cfg_t.Bandwidth;
    store.lorap2p_cfg_Codingrate                = cfg->g_lora_p2p_cfg_t.Codingrate;
    store.lorap2p_cfg_Preamlen                  = cfg->g_lora_p2p_cfg_t.Preamlen;
    store.lorap2p_cfg_Powerdbm                  = cfg->g_lora_p2p_cfg_t.Powerdbm;
    store.lorap2p_cfg_p2p_workmode              = cfg->g_lora_p2p_cfg_t.p2p_workmode;
    store.lorap2p_cfg_crypt_enable              = cfg->g_lora_p2p_cfg_t.crypt_enable ;
    ARRAY_CPY(store.lorap2p_cfg_crypt_key       , cfg->g_lora_p2p_cfg_t.crypt_key);
    store.lorap2p_cfg_bitrate                   = cfg->g_lora_p2p_cfg_t.bitrate;
    store.lorap2p_cfg_deviation                 = cfg->g_lora_p2p_cfg_t.deviation;
    store.lorap2p_cfg_fsk_rxbw                  = cfg->g_lora_p2p_cfg_t.fsk_rxbw;

    // follow as lora_cfg_t g_lora_cfg_t;
    store.lora_cfg_region                       = cfg->g_lora_cfg_t.region;
    ARRAY_CPY(store.lora_cfg_dev_eui            , cfg->g_lora_cfg_t.dev_eui);
    ARRAY_CPY(store.lora_cfg_app_eui            , cfg->g_lora_cfg_t.app_eui);
    ARRAY_CPY(store.lora_cfg_app_key            , cfg->g_lora_cfg_t.app_key);
    ARRAY_CPY(store.lora_cfg_app_skey           , cfg->g_lora_cfg_t.app_skey);
    ARRAY_CPY(store.lora_cfg_dev_addr           , cfg->g_lora_cfg_t.dev_addr);
    ARRAY_CPY(store.lora_cfg_nwk_id             , cfg->g_lora_cfg_t.nwk_id);
    ARRAY_CPY(store.lora_cfg_nwk_skey           , cfg->g_lora_cfg_t.nwk_skey);
    store.lora_cfg_multi_dev_addr               = cfg->g_lora_cfg_t.multi_dev_addr;
    ARRAY_CPY(store.lora_cfg_multi_nwks_key     , cfg->g_lora_cfg_t.multi_nwks_key);
    ARRAY_CPY(store.lora_cfg_multi_apps_key     , cfg->g_lora_cfg_t.multi_apps_key);
    store.lora_cfg_MulticastEnable              = cfg->g_lora_cfg_t.MulticastEnable;
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
    ARRAY_CPY(store.lora_cfg_ch_mask            , cfg->g_lora_cfg_t.ch_mask);
#endif
    store.lora_cfg_join_mode                    = cfg->g_lora_cfg_t.join_mode;
    store.lora_cfg_device_class                 = cfg->g_lora_cfg_t.device_class;
    store.lora_cfg_confirm                      = cfg->g_lora_cfg_t.confirm;
    store.lora_cfg_retry                        = cfg->g_lora_cfg_t.retry;
    store.lora_cfg_dr                           = cfg->g_lora_cfg_t.dr;
    store.lora_cfg_rx2dr                        = cfg->g_lora_cfg_t.rx2dr;
    store.lora_cfg_adr                          = cfg->g_lora_cfg_t.adr;
    store.lora_cfg_tx_power                     = cfg->g_lora_cfg_t.tx_power;
    store.lora_cfg_DutycycleEnable              = cfg->g_lora_cfg_t.DutycycleEnable;
    store.lora_cfg_jn1dl                        = cfg->g_lora_cfg_t.jn1dl;
    store.lora_cfg_jn2dl                        = cfg->g_lora_cfg_t.jn2dl;
    store.lora_cfg_rx1dl                        = cfg->g_lora_cfg_t.rx1dl;
    store.lora_cfg_rx2dl                        = cfg->g_lora_cfg_t.rx2dl;
    store.lora_cfg_rx2fq                        = cfg->g_lora_cfg_t.rx2fq;
    store.lora_cfg_pub_nwk_mode                 = cfg->g_lora_cfg_t.pub_nwk_mode;
    store.lora_cfg_linkcheck_mode               = cfg->g_lora_cfg_t.linkcheck_mode;
    store.lora_cfg_ping_slot_periodicity        = cfg->g_lora_cfg_t.ping_slot_periodicity;
    store.lora_cfg_join_start                   = cfg->g_lora_cfg_t.join_start;
    store.lora_cfg_auto_join                    = cfg->g_lora_cfg_t.auto_join;
    store.lora_cfg_auto_join_period             = cfg->g_lora_cfg_t.auto_join_period;
    store.lora_cfg_auto_join_max_cnt            = cfg->g_lora_cfg_t.auto_join_max_cnt;
    ARRAY_CPY(store.lora_cfg_McSession_group    , cfg->g_lora_cfg_t.McSession_group);
    store.lora_cfg_chs                          = cfg->g_lora_cfg_t.chs;
    ARRAY_CPY(store.lora_cfg_tp_port            , cfg->g_lora_cfg_t.tp_port);
#endif

#ifdef SUPPORT_BLE
    // follow as ble_central_cfg_t g_ble_cfg_t;
    store.ble_central_cfg_work_mode             = cfg->g_ble_cfg_t.work_mode;
    store.ble_central_cfg_long_range_enable     = cfg->g_ble_cfg_t.long_range_enable;
    ARRAY_CPY(store.ble_central_cfg_mac         ,cfg->g_ble_cfg_t.mac );
    ARRAY_CPY(store.ble_central_cfg_reserve     , cfg->g_ble_cfg_t.reserve);
#endif

    // follow as rtc_delta_t g_rtc_delta_t;
    store.rtc_delta_seconds                     = cfg->g_rtc_delta_t.seconds;
    store.rtc_delta_subseconds                  = cfg->g_rtc_delta_t.subseconds;
    
    ARRAY_CPY(store.mode_type                   , cfg->mode_type);
    ARRAY_CPY(store.serial_lock_status          , cfg->serial_lock_status);
#ifdef RAK5010_EVB
    // follow as cellular_cfg_t g_cellular_cfg_t;
    ARRAY_CPY(store.cellular_server_ip          , cfg->g_cellular_cfg_t.server_ip);
    ARRAY_CPY(store.cellular_server_port        , cfg->g_cellular_cfg_t.server_port);    	
    ARRAY_CPY(store.cellular_operator_long_data , cfg->g_cellular_cfg_t.operator_long_data); 
    ARRAY_CPY(store.cellular_operator_short_data, cfg->g_cellular_cfg_t.operator_short_data); 
    ARRAY_CPY(store.cellular_operator_apn_data  , cfg->g_cellular_cfg_t.operator_apn_data);
    ARRAY_CPY(store.cellular_operator_net_data  , cfg->g_cellular_cfg_t.operator_net_data);
    ARRAY_CPY(store.cellular_hologram_card_num  , cfg->g_cellular_cfg_t.hologram_card_num);
#endif
    store.baudrate                              = cfg->baudrate;
    store.atcmd_echo                            = cfg->atcmd_echo;
    ARRAY_CPY(store.serial_passwd               , cfg->serial_passwd);
    store.auto_sleep_time                       = cfg->auto_sleep_time;
    ARRAY_CPY(store.sn                          , cfg->sn);
    ARRAY_CPY(store.alias                       , cfg->alias);
    store.debug_level                           = cfg->debug_level;
    ARRAY_CPY(store.firmware_ver                , cfg->firmware_ver);
    ARRAY_CPY(store.hwmodel                     , cfg->hwmodel);
    ARRAY_CPY(store.cli_ver                     , cfg->cli_ver);

#ifdef SUPPORT_LORA
    store.lorap2p_cfg_iqinverted                = cfg->g_lora_p2p_cfg_t.iqinverted;
    store.lorap2p_cfg_symbol_timeout            = cfg->g_lora_p2p_cfg_t.symbol_timeout;
    store.lorap2p_cfg_syncword                  = cfg->g_lora_p2p_cfg_t.syncword;
    store.lorap2p_cfg_fix_length_payload        = cfg->g_lora_p2p_cfg_t.fix_length_payload;
#endif

    //If there are new parameters in the CFG, add the code for the transformation before here.
    //Cacluate the CRC
    store.crc_verify = Crc32(((uint8_t*)&store)+sizeof(uint32_t),store.store_size-sizeof(uint32_t));
    return udrv_flash_write(flash_addr, sizeof(store), &store );
}

int32_t service_nvm_read_config(uint32_t flash_addr, rui_cfg_t *cfg)
{
    STORE_REOGANIZED store;
    uint32_t crc_cacluated;
    int32_t ret;

    ret = udrv_flash_read(flash_addr, sizeof(store), &store );
    if( UDRV_RETURN_OK != ret )
    {
        return ret;
    }
    
    // check the CRC
    // If the calculated CRC matches the stored CRC, set the value of magic_num.
    // Another should setting the magic_num to 0 tells the caller this case.
    cfg->magic_num = 0;
    //If the value of store_size is outside the reasonable range, there may be no data or data has been lost
    if( store.store_size == 0 || store.store_size > 0x800 )
    {
        // udrv_serial_log_printf("Fail store size \r\n");
        return UDRV_NOT_FOUND;
    }
    crc_cacluated = Crc32(((uint8_t*)&store)+sizeof(uint32_t),store.store_size-sizeof(uint32_t));
    if (store.crc_verify == crc_cacluated )
    {
        cfg->magic_num = RUI_CFG_MAGIC_NUM;
    }
    else
    {
        cfg->magic_num = 0;
        return UDRV_NOT_FOUND;
    }
    //Recognize config data
    cfg->version_code                           = store.version_code;
#ifdef SUPPORT_LORA
    cfg->lora_work_mode                         = store.lora_work_mode;
    // -- follow as S_LORAP2P_PARAM g_lora_p2p_cfg_t;
    cfg->g_lora_p2p_cfg_t.Frequency             = store.lorap2p_cfg_Frequency;
    cfg->g_lora_p2p_cfg_t.Spreadfact            = store.lorap2p_cfg_Spreadfact;
    cfg->g_lora_p2p_cfg_t.Bandwidth             = store.lorap2p_cfg_Bandwidth;
    cfg->g_lora_p2p_cfg_t.Codingrate            = store.lorap2p_cfg_Codingrate;
    cfg->g_lora_p2p_cfg_t.Preamlen              = store.lorap2p_cfg_Preamlen;
    cfg->g_lora_p2p_cfg_t.Powerdbm              = store.lorap2p_cfg_Powerdbm;
    cfg->g_lora_p2p_cfg_t.p2p_workmode          = store.lorap2p_cfg_p2p_workmode;
    cfg->g_lora_p2p_cfg_t.crypt_enable          = store.lorap2p_cfg_crypt_enable;
    ARRAY_CPY(cfg->g_lora_p2p_cfg_t.crypt_key   , store.lorap2p_cfg_crypt_key);
    cfg->g_lora_p2p_cfg_t.bitrate               = store.lorap2p_cfg_bitrate;
    cfg->g_lora_p2p_cfg_t.deviation             = store.lorap2p_cfg_deviation;
    cfg->g_lora_p2p_cfg_t.fsk_rxbw              = store.lorap2p_cfg_fsk_rxbw;

    // follow as lora_cfg_t g_lora_cfg_t;
    cfg->g_lora_cfg_t.region                    = store.lora_cfg_region;
    ARRAY_CPY(cfg->g_lora_cfg_t.dev_eui         , store.lora_cfg_dev_eui);
    ARRAY_CPY(cfg->g_lora_cfg_t.app_eui         , store.lora_cfg_app_eui);
    ARRAY_CPY(cfg->g_lora_cfg_t.app_key         , store.lora_cfg_app_key);
    ARRAY_CPY(cfg->g_lora_cfg_t.app_skey        , store.lora_cfg_app_skey);
    ARRAY_CPY(cfg->g_lora_cfg_t.dev_addr        , store.lora_cfg_dev_addr);
    ARRAY_CPY(cfg->g_lora_cfg_t.nwk_id          , store.lora_cfg_nwk_id);
    ARRAY_CPY(cfg->g_lora_cfg_t.nwk_skey        , store.lora_cfg_nwk_skey);
    cfg->g_lora_cfg_t.multi_dev_addr            = store.lora_cfg_multi_dev_addr;
    ARRAY_CPY(cfg->g_lora_cfg_t.multi_nwks_key  , store.lora_cfg_multi_nwks_key);
    ARRAY_CPY(cfg->g_lora_cfg_t.multi_apps_key  , store.lora_cfg_multi_apps_key);
    cfg->g_lora_cfg_t.MulticastEnable           = store.lora_cfg_MulticastEnable;
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
    ARRAY_CPY(cfg->g_lora_cfg_t.ch_mask         , store.lora_cfg_ch_mask);
#endif
    cfg->g_lora_cfg_t.join_mode                 = store.lora_cfg_join_mode;
    cfg->g_lora_cfg_t.device_class              = store.lora_cfg_device_class;
    cfg->g_lora_cfg_t.confirm                   = store.lora_cfg_confirm;
    cfg->g_lora_cfg_t.retry                     = store.lora_cfg_retry;
    cfg->g_lora_cfg_t.dr                        = store.lora_cfg_dr;
    cfg->g_lora_cfg_t.rx2dr                     = store.lora_cfg_rx2dr;
    cfg->g_lora_cfg_t.adr                       = store.lora_cfg_adr;
    cfg->g_lora_cfg_t.tx_power                  = store.lora_cfg_tx_power;
    cfg->g_lora_cfg_t.DutycycleEnable           = store.lora_cfg_DutycycleEnable;
    cfg->g_lora_cfg_t.jn1dl                     = store.lora_cfg_jn1dl;
    cfg->g_lora_cfg_t.jn2dl                     = store.lora_cfg_jn2dl;
    cfg->g_lora_cfg_t.rx1dl                     = store.lora_cfg_rx1dl;
    cfg->g_lora_cfg_t.rx2dl                     = store.lora_cfg_rx2dl;
    cfg->g_lora_cfg_t.rx2fq                     = store.lora_cfg_rx2fq;
    cfg->g_lora_cfg_t.pub_nwk_mode              = store.lora_cfg_pub_nwk_mode;
    cfg->g_lora_cfg_t.linkcheck_mode            = store.lora_cfg_linkcheck_mode;
    cfg->g_lora_cfg_t.ping_slot_periodicity     = store.lora_cfg_ping_slot_periodicity;
    cfg->g_lora_cfg_t.join_start                = store.lora_cfg_join_start;
    cfg->g_lora_cfg_t.auto_join                 = store.lora_cfg_auto_join;
    cfg->g_lora_cfg_t.auto_join_period          = store.lora_cfg_auto_join_period;
    cfg->g_lora_cfg_t.auto_join_max_cnt         = store.lora_cfg_auto_join_max_cnt;
    ARRAY_CPY(cfg->g_lora_cfg_t.McSession_group , store.lora_cfg_McSession_group);
    cfg->g_lora_cfg_t.chs                       = store.lora_cfg_chs;
    ARRAY_CPY(cfg->g_lora_cfg_t.tp_port         , store.lora_cfg_tp_port);
#endif

#ifdef SUPPORT_BLE
    // follow as ble_central_cfg_t g_ble_cfg_t;
    cfg->g_ble_cfg_t.work_mode                  = store.ble_central_cfg_work_mode;
    cfg->g_ble_cfg_t.long_range_enable          = store.ble_central_cfg_long_range_enable;
    ARRAY_CPY(cfg->g_ble_cfg_t.mac              , store.ble_central_cfg_mac);
    ARRAY_CPY(cfg->g_ble_cfg_t.reserve          , store.ble_central_cfg_reserve);
#endif

    // follow as rtc_delta_t g_rtc_delta_t;
    cfg->g_rtc_delta_t.seconds                  = store.rtc_delta_seconds;
    cfg->g_rtc_delta_t.subseconds               = store.rtc_delta_subseconds;
    ARRAY_CPY(cfg->mode_type                    , store.mode_type);
    ARRAY_CPY(cfg->serial_lock_status           , store.serial_lock_status);
#ifdef RAK5010_EVB
    // follow as cellular_cfg_t g_cellular_cfg_t;
    ARRAY_CPY(cfg->g_cellular_cfg_t.server_ip   , store.cellular_server_ip);
    ARRAY_CPY(cfg->g_cellular_cfg_t.server_port , store.cellular_server_port);    	
    ARRAY_CPY(cfg->g_cellular_cfg_t.operator_long_data  , store.cellular_operator_long_data); 
    ARRAY_CPY(cfg->g_cellular_cfg_t.operator_short_data , store.cellular_operator_short_data); 
    ARRAY_CPY(cfg->g_cellular_cfg_t.operator_apn_data   , store.cellular_operator_apn_data);
    ARRAY_CPY(cfg->g_cellular_cfg_t.operator_net_data   , store.cellular_operator_net_data);
    ARRAY_CPY(cfg->g_cellular_cfg_t.hologram_card_num   , store.cellular_hologram_card_num);
#endif
    cfg->baudrate                               = store.baudrate;
    cfg->atcmd_echo                             = store.atcmd_echo;
    ARRAY_CPY(cfg->serial_passwd                , store.serial_passwd);
    cfg->auto_sleep_time                        = store.auto_sleep_time;
    ARRAY_CPY(cfg->sn                           , store.sn);
    ARRAY_CPY(cfg->alias                        , store.alias);
    cfg->debug_level                            = store.debug_level;
    ARRAY_CPY(cfg->firmware_ver                 , store.firmware_ver);
    ARRAY_CPY(cfg->hwmodel                      , store.hwmodel);
    ARRAY_CPY(cfg->cli_ver                      , store.cli_ver);

#ifdef SUPPORT_LORA
    cfg->g_lora_p2p_cfg_t.iqinverted            = store.lorap2p_cfg_iqinverted;
    cfg->g_lora_p2p_cfg_t.symbol_timeout        = store.lorap2p_cfg_symbol_timeout;
    cfg->g_lora_p2p_cfg_t.syncword              = store.lorap2p_cfg_syncword;
    cfg->g_lora_p2p_cfg_t.fix_length_payload    = store.lorap2p_cfg_fix_length_payload;
#endif

    //If there are new parameters in the CFG, add the code for the transformation before here.
    return ret;
}

#include <stdint.h>
#include "board_basic.h"
#include "udrv_errno.h"
#include "udrv_flash.h"
#include "service_nvm.h"
#ifdef SUPPORT_LORA
#include "service_lora_multicast.h"
#endif

rui_cfg_t g_rui_cfg_t;

#define SERVICE_RUI_CONFIG_CRC32 Crc32(((uint8_t*)&g_rui_cfg_t)+sizeof(uint32_t),sizeof(rui_cfg_t)-sizeof(uint32_t))

static bool service_nvm_verify_crc32(void) {
    return (g_rui_cfg_t.crc_verify == SERVICE_RUI_CONFIG_CRC32);
}

int32_t service_nvm_set_default_config_to_nvm(void) {
    uint8_t passwd[8] = {0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30};
    rui_cfg_t factory_default;
    bool factory_default_exist = true;

    udrv_flash_read(SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&factory_default);
    if (factory_default.crc_verify != Crc32(((uint8_t*)&factory_default)+sizeof(uint32_t),sizeof(rui_cfg_t)-sizeof(uint32_t))) {
        factory_default_exist = false;
    }

    memset(&g_rui_cfg_t, 0, sizeof(rui_cfg_t));

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

    memcpy(g_rui_cfg_t.serial_passwd, passwd, 8);
    g_rui_cfg_t.auto_sleep_time = 0;
    g_rui_cfg_t.atcmd_echo = 0;
#ifdef SUPPORT_LORA
    /* lora work mode */
    g_rui_cfg_t.lora_work_mode = SERVICE_LORAWAN;

    /* lorawan configuration */
    if (factory_default_exist) {
        g_rui_cfg_t.g_lora_cfg_t.region = factory_default.g_lora_cfg_t.region;
        memcpy(g_rui_cfg_t.g_lora_cfg_t.dev_eui, factory_default.g_lora_cfg_t.dev_eui, 8);
        memcpy(g_rui_cfg_t.g_lora_cfg_t.app_eui, factory_default.g_lora_cfg_t.app_eui, 8);
        memcpy(g_rui_cfg_t.g_lora_cfg_t.app_key, factory_default.g_lora_cfg_t.app_key, 16);
        memcpy(g_rui_cfg_t.g_lora_cfg_t.app_skey, factory_default.g_lora_cfg_t.app_skey, 16);
        memcpy(g_rui_cfg_t.g_lora_cfg_t.dev_addr, factory_default.g_lora_cfg_t.dev_addr, 4);
        memcpy(g_rui_cfg_t.g_lora_cfg_t.nwk_skey, factory_default.g_lora_cfg_t.nwk_skey, 16);
        memcpy(g_rui_cfg_t.sn, factory_default.sn, 18);
    } else {
        g_rui_cfg_t.g_lora_cfg_t.region = SERVICE_LORA_EU868;
    }
    g_rui_cfg_t.g_lora_cfg_t.join_mode = SERVICE_LORA_OTAA;
    g_rui_cfg_t.g_lora_cfg_t.device_class = SERVICE_LORA_CLASS_A;
    g_rui_cfg_t.g_lora_cfg_t.confirm = SERVICE_LORA_ACK;
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
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = 868000000; // 150MHz - 960MHz
    g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact = 7;// 6 - 12
    g_rui_cfg_t.g_lora_p2p_cfg_t.Bandwidth = 125; // 125 kHz, 250 kHz, 500 kHz
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = 0;// 0: 4/5, 1: 4/6, 2: 4/7, 3: 4/8
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = 8;  // 2 - 65535
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = 14; // 5 - 22
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = false;
    g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate = 4915;
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = 5000 ;
    g_rui_cfg_t.g_lora_p2p_cfg_t.fsk_rxbw = 20000 ;
    memset(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key, 0x00, sizeof(g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_key));
#endif

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

void service_nvm_init_config(void) {
    udrv_flash_read(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
    if (!service_nvm_verify_crc32()) {
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_sleep_time_from_nvm(void) {
    return g_rui_cfg_t.auto_sleep_time;
}

int32_t service_nvm_set_auto_sleep_time_to_nvm(uint32_t time) {
    int32_t ret;
    bool restart = false;
    if (g_rui_cfg_t.auto_sleep_time == 0 && time != 0) {
        restart = true;
    }

    g_rui_cfg_t.auto_sleep_time = time;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    if ((ret = udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t)) == UDRV_RETURN_OK) {
        if (restart) {
            udrv_system_user_app_timer_stop();
            udrv_system_user_app_timer_start(time, NULL);
        }
    } else {
        return ret;
    }
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_delta_subsec_from_nvm (void) {
    return g_rui_cfg_t.g_rtc_delta_t.subseconds;
}

int32_t service_nvm_set_delta_subsec_to_nvm (uint32_t subsec) {
    g_rui_cfg_t.g_rtc_delta_t.subseconds = subsec;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERIAL_WLOCK_STATE  service_nvm_get_lock_status_from_nvm(SERIAL_PORT Port) {
        return g_rui_cfg_t.serial_lock_status[Port];
}

int32_t service_nvm_set_lock_status_to_nvm(SERIAL_PORT Port, SERIAL_WLOCK_STATE wlock_state) {
    g_rui_cfg_t.serial_lock_status[Port] = wlock_state;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_baudrate_from_nvm(void) {
    return g_rui_cfg_t.baudrate;
}

int32_t service_nvm_set_baudrate_to_nvm(uint32_t baudrate) {
    g_rui_cfg_t.baudrate = baudrate;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_atcmd_echo_from_nvm(void) {
    return g_rui_cfg_t.atcmd_echo;
}

int32_t service_nvm_set_atcmd_echo_to_nvm(uint8_t atcmd_echo) {
    g_rui_cfg_t.atcmd_echo = atcmd_echo;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

#ifdef SUPPORT_LORA
/***********************************************************/
/* LoRa                                                    */
/***********************************************************/
SERVICE_LORA_BAND service_nvm_get_band_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.region;
}

int32_t service_nvm_set_band_to_nvm (SERVICE_LORA_BAND band) {
    g_rui_cfg_t.g_lora_cfg_t.region = band;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
int32_t service_nvm_get_mask_from_nvm (uint16_t *mask) {
    memcpy(mask, g_rui_cfg_t.g_lora_cfg_t.ch_mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    return UDRV_RETURN_OK;
}

int32_t service_nvm_set_mask_to_nvm (uint16_t *mask) {
    memcpy(g_rui_cfg_t.g_lora_cfg_t.ch_mask, mask, sizeof(g_rui_cfg_t.g_lora_cfg_t.ch_mask));

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_retry_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.retry;
}

int32_t service_nvm_set_retry_to_nvm (uint8_t retry) {
    g_rui_cfg_t.g_lora_cfg_t.retry = retry;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CONFIRM_MODE service_nvm_get_cfm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.confirm;
}

int32_t service_nvm_set_cfm_to_nvm (SERVICE_LORA_CONFIRM_MODE cfm) {
    g_rui_cfg_t.g_lora_cfg_t.confirm = cfm;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_WORK_MODE service_nvm_get_nwm_from_nvm (void) {
    return g_rui_cfg_t.lora_work_mode;
}

int32_t service_nvm_set_nwm_to_nvm (SERVICE_LORA_WORK_MODE nwm) {
    g_rui_cfg_t.lora_work_mode = nwm;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_JOIN_MODE service_nvm_get_njm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_mode;
}

int32_t service_nvm_set_njm_to_nvm (SERVICE_LORA_JOIN_MODE njm) {
    g_rui_cfg_t.g_lora_cfg_t.join_mode = njm;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_adr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.adr;
}

int32_t service_nvm_set_adr_to_nvm (bool adr) {
    g_rui_cfg_t.g_lora_cfg_t.adr = adr;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_CLASS service_nvm_get_class_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.device_class;
}

int32_t service_nvm_set_class_to_nvm (SERVICE_LORA_CLASS device_class) {
    g_rui_cfg_t.g_lora_cfg_t.device_class = device_class;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.dr;
}

int32_t service_nvm_set_dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.dr = dr;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

SERVICE_LORA_DATA_RATE service_nvm_get_rx2dr_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dr;
}

int32_t service_nvm_set_rx2dr_to_nvm (SERVICE_LORA_DATA_RATE dr) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dr = dr;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


uint32_t service_nvm_get_jn1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn1dl;
}

int32_t service_nvm_set_jn1dl_to_nvm (uint32_t jn1dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn1dl = jn1dl;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_jn2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.jn2dl;
}

int32_t service_nvm_set_jn2dl_to_nvm (uint32_t jn2dl) {
    g_rui_cfg_t.g_lora_cfg_t.jn2dl = jn2dl;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_rx2fq_to_nvm(uint32_t freq)
{
    g_rui_cfg_t.g_lora_cfg_t.rx2fq = freq;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx1dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx1dl;
}

int32_t service_nvm_set_rx1dl_to_nvm (uint32_t rx1dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx1dl = rx1dl;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_rx2dl_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.rx2dl;
}

int32_t service_nvm_set_rx2dl_to_nvm (uint32_t rx2dl) {
    g_rui_cfg_t.g_lora_cfg_t.rx2dl = rx2dl;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_txpower_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.tx_power;
}

int32_t service_nvm_set_txpower_to_nvm (uint8_t txp) {
    g_rui_cfg_t.g_lora_cfg_t.tx_power = txp;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_linkcheck_from_nvm (void) {
    return g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode;
}

int32_t service_nvm_set_linkcheck_to_nvm (uint8_t mode) {
    g_rui_cfg_t.g_lora_cfg_t.linkcheck_mode = mode;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_ping_slot_periodicity_from_nvm() {
    return g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity;
}

int32_t service_nvm_set_ping_slot_periodicity_to_nvm(uint8_t periodicity) {
    g_rui_cfg_t.g_lora_cfg_t.ping_slot_periodicity = periodicity;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_join_start_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.join_start;
}

int32_t service_nvm_set_join_start_to_nvm(bool join_start) {
    g_rui_cfg_t.g_lora_cfg_t.join_start = join_start;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_auto_join_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join;
}

int32_t service_nvm_set_auto_join_to_nvm(bool auto_join) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join = auto_join;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_period_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_period;
}

int32_t service_nvm_set_auto_join_period_to_nvm(uint32_t auto_join_period) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_period = auto_join_period;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_auto_join_max_cnt_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt;
}

int32_t service_nvm_set_auto_join_max_cnt_to_nvm(uint32_t auto_join_max_cnt) {
    g_rui_cfg_t.g_lora_cfg_t.auto_join_max_cnt = auto_join_max_cnt;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_get_freq_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency;
}

int32_t service_nvm_set_freq_to_nvm (uint32_t freq) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Frequency = freq;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_sf_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact;
}

int32_t service_nvm_set_sf_to_nvm (uint8_t spreadfact) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Spreadfact = spreadfact;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_codingrate_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate;
}

int32_t service_nvm_set_codingrate_to_nvm (uint8_t codingrate) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Codingrate = codingrate;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint16_t service_nvm_get_preamlen_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen;
}

int32_t service_nvm_set_preamlen_to_nvm (uint16_t preamlen) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Preamlen = preamlen;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_powerdbm_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm;
}

int32_t service_nvm_set_powerdbm_to_nvm (uint8_t powerdbm) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.Powerdbm = powerdbm;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

bool service_nvm_get_crypt_enable_from_nvm (void) {
    return g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable;
}

int32_t service_nvm_set_crypt_enable_to_nvm (bool crypt_enable) {
    g_rui_cfg_t.g_lora_p2p_cfg_t.crypt_enable = crypt_enable;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

McSession_t *service_nvm_get_multicast_from_nvm(void) {
    return g_rui_cfg_t.g_lora_cfg_t.McSession_group;
}

int32_t service_nvm_set_multicast_to_nvm(McSession_t *McSession) {
    memcpy(g_rui_cfg_t.g_lora_cfg_t.McSession_group, McSession ,4*sizeof(McSession_t));

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_rui_get_chs_from_nvm(void) 
{
    return g_rui_cfg_t.g_lora_cfg_t.chs;
}

uint32_t service_rui_set_chs_to_nvm(uint32_t frequency) 
{
    g_rui_cfg_t.g_lora_cfg_t.chs = frequency;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}


uint32_t service_nvm_set_fdev_to_nvm(uint32_t fdev) 
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.deviation = fdev;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint32_t service_nvm_set_bitrate_to_nvm(uint32_t bitrate) 
{
    g_rui_cfg_t.g_lora_p2p_cfg_t.bitrate = bitrate;

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
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

    g_rui_cfg_t.crc_verify = SERVICE_RUI_CONFIG_CRC32;

    return udrv_flash_write(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}

uint8_t service_nvm_get_dcs_from_nvm()
{
    return g_rui_cfg_t.g_lora_cfg_t.DutycycleEnable;
}

#endif

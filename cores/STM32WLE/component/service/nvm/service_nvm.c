#include "board_basic.h"
#include "udrv_errno.h"
#include "udrv_flash.h"
#include "service_nvm.h"
extern char *sw_version;
extern char *model_id;
extern char *cli_version;

extern PRE_rui_cfg_t g_rui_cfg_t;
#if defined(LORA_STACK_104) && defined(SUPPORT_LORA)
extern lora_mac_nvm_data_t g_lora_mac_nvm_data;
#endif
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
#ifndef NO_LORA_SUPPORT
    /* lora work mode */
#ifdef SUPPORT_LORA
    g_rui_cfg_t.lora_work_mode = SERVICE_LORAWAN;
#else
    g_rui_cfg_t.lora_work_mode = SERVICE_LORA_P2P;
#endif
    /* lorawan configuration */
    #if defined(rak3172) || defined(rak3172T)
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
#if defined(LORA_STACK_104) && defined(SUPPORT_LORA)
    g_rui_cfg_t.g_rui_cfg_ex.IsCertPortOn = 1;
    memset(&g_lora_mac_nvm_data,0,sizeof(lora_mac_nvm_data_t));
#endif
    memset(g_rui_cfg_t.g_lora_cfg_t.McSession_group,0x00,4*sizeof(McSession_t));

    /* lora p2p configuration */
#if defined(rak3172) || defined(rak3172T)
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
    memset(g_rui_cfg_t.g_rui_cfg_ex.crypt_key16, 0x00, sizeof(g_rui_cfg_t.g_rui_cfg_ex.crypt_key16));
    memset(g_rui_cfg_t.g_rui_cfg_ex.crypt_IV, 0x00, sizeof(g_rui_cfg_t.g_rui_cfg_ex.crypt_IV));
    g_rui_cfg_t.g_rui_cfg_ex.CAD = 0;
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
#ifndef SUPPORT_LORA
#ifdef SUPPORT_LORA_P2P
        if(g_rui_cfg_t.lora_work_mode == SERVICE_LORAWAN)
            g_rui_cfg_t.lora_work_mode = SERVICE_LORA_P2P;
#endif
#endif
#ifndef SUPPORT_LORA_P2P
#ifdef SUPPORT_LORA
        if(g_rui_cfg_t.lora_work_mode != SERVICE_LORAWAN)
            g_rui_cfg_t.lora_work_mode = SERVICE_LORAWAN;
#endif
#endif
        return UDRV_RETURN_OK;
    }
    else
        service_nvm_set_default_config_to_nvm();
}

static void service_nvm_data_recovery_from_legacy(uint32_t data_flash_addr, PRE_rui_cfg_t *rui_cfg_cur)
{
    uint8_t data_legacy[800];
    uint32_t version_code = 0;
    #define DATA_ADDR(LegacyOffset) (data_legacy + LegacyOffset)

    //Get the software version of user data
    udrv_flash_read(data_flash_addr, sizeof(data_legacy), data_legacy );
    if( rui_cfg_cur->magic_num == RUI_CFG_MAGIC_NUM )
        version_code = rui_cfg_cur->version_code;

    memset(rui_cfg_cur, 0, sizeof(PRE_rui_cfg_t));
    //When version code is matched, can move user data to current firmware. The way of moving should be define when develop new version.
    //Also need to consider default values for items that do not exist in older version in rui_cfg_t.
    if( version_code == 0 )
    {
        //The historical version could not be determined
        return;
    }
    else if( version_code == RUI_VERSION_CODE_LATEST )
    {
        memcpy(rui_cfg_cur,                     data_legacy,                                sizeof(PRE_rui_cfg_t) );
        //add new config
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
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level = 1;

#ifndef NO_LORA_SUPPORT
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
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_enable == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_enable = 0;
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_rssi == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_rssi = -80;
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.lbt_scantime == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.lbt_scantime = 5;
#ifdef LORA_STACK_104
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.IsCertPortOn == 0xFF)
            rui_cfg_cur->g_rui_cfg_ex.IsCertPortOn = 1;
#endif

        
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.crypt_key16 == 0xFF000000)
        {
            memset(rui_cfg_cur->g_rui_cfg_ex.crypt_key16,0,sizeof(rui_cfg_cur->g_rui_cfg_ex.crypt_key16));
            memcpy(rui_cfg_cur->g_rui_cfg_ex.crypt_key16,rui_cfg_cur->g_lora_p2p_cfg_t.crypt_key,sizeof(rui_cfg_cur->g_lora_p2p_cfg_t.crypt_key));
        }   
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.crypt_IV == 0xFF)
        {
            memset(rui_cfg_cur->g_rui_cfg_ex.crypt_IV,0,sizeof(rui_cfg_cur->g_rui_cfg_ex.crypt_IV));
        }
        if(*(uint8_t*)&rui_cfg_cur->g_rui_cfg_ex.CAD == 0xFF)
        {
            rui_cfg_cur->g_rui_cfg_ex.CAD = 0;
        }
#endif
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
    rui_cfg_cur->debug_level = 0;
    memset(rui_cfg_cur->firmware_ver,'\0',sizeof(rui_cfg_cur->firmware_ver));
    memcpy(rui_cfg_cur->firmware_ver,sw_version,strlen(sw_version));
    memset(rui_cfg_cur->hwmodel,'\0',sizeof(rui_cfg_cur->hwmodel));
    memcpy(rui_cfg_cur->hwmodel,model_id,strlen(model_id));
    memset(rui_cfg_cur->cli_ver,'\0',sizeof(rui_cfg_cur->cli_ver));
    memcpy(rui_cfg_cur->cli_ver,cli_version,strlen(cli_version));
#ifndef NO_LORA_SUPPORT
    rui_cfg_cur->g_rui_cfg_ex.iqinverted = false;
    rui_cfg_cur->g_rui_cfg_ex.symbol_timeout = 0;
    rui_cfg_cur->g_rui_cfg_ex.syncword = LORA_MAC_PRIVATE_SYNCWORD;
    rui_cfg_cur->g_rui_cfg_ex.syncword_dirty_byte =0;
    rui_cfg_cur->g_rui_cfg_ex.fix_length_payload = false;
    rui_cfg_cur->g_rui_cfg_ex.lbt_enable = 0;
    rui_cfg_cur->g_rui_cfg_ex.lbt_rssi = -80;
    rui_cfg_cur->g_rui_cfg_ex.lbt_scantime = 5;
    rui_cfg_cur->g_rui_cfg_ex.auto_sleep_level = 1;
    memset(rui_cfg_cur->g_rui_cfg_ex.crypt_key16,0,sizeof(rui_cfg_cur->g_rui_cfg_ex.crypt_key16));
    memset(rui_cfg_cur->g_rui_cfg_ex.crypt_IV,0,sizeof(rui_cfg_cur->g_rui_cfg_ex.crypt_IV));
    rui_cfg_cur->g_rui_cfg_ex.CAD =0;
#endif
}


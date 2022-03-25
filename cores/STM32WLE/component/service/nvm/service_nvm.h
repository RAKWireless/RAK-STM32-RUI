/**
 * @file        service_nvm.h
 * @brief       Provide NVM service layer.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.5
 */

#ifndef __SERVICE_NVM_H__
#define __SERVICE_NVM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"
#include "mcu_basic.h"
#ifndef RUI_BOOTLOADER
#ifdef SUPPORT_LORA
#include "service_lora.h"
#include "service_lora_multicast.h"
#endif
#include "service_mode.h"
#endif
#include "udrv_serial.h"

#define SERVICE_NVM_RUI_CONFIG_NVM_ADDR         MCU_SYS_CONFIG_NVM_ADDR
#define SERVICE_NVM_USER_DATA_NVM_ADDR          MCU_USER_DATA_NVM_ADDR
#define SERVICE_NVM_FACTORY_DEFAULT_NVM_ADDR    MCU_FACTORY_DEFAULT_NVM_ADDR

#ifndef RUI_BOOTLOADER
void service_nvm_init_config(void);

int32_t service_nvm_set_default_config_to_nvm(void);

/***********************************************************/
/* RUI Mode                                                */
/***********************************************************/

SERVICE_MODE_TYPE service_nvm_get_mode_type_from_nvm(SERIAL_PORT port);

int32_t service_nvm_set_mode_type_to_nvm(SERIAL_PORT port, SERVICE_MODE_TYPE mode_type);

SERIAL_WLOCK_STATE service_nvm_get_lock_status_from_nvm(SERIAL_PORT Port);

int32_t service_nvm_set_lock_status_to_nvm(SERIAL_PORT Port, SERIAL_WLOCK_STATE wlock_state);

uint32_t service_nvm_get_baudrate_from_nvm(void);

int32_t service_nvm_set_baudrate_to_nvm(uint32_t baudrate);

uint8_t service_nvm_get_atcmd_echo_from_nvm(void);

int32_t service_nvm_set_atcmd_echo_to_nvm(uint8_t atcmd_echo);

int32_t service_nvm_get_serial_passwd_from_nvm(uint8_t *passwd, uint32_t len);

int32_t service_nvm_set_serial_passwd_to_nvm(uint8_t *passwd, uint32_t len);

uint32_t service_nvm_get_auto_sleep_time_from_nvm(void);

int32_t service_nvm_set_auto_sleep_time_to_nvm(uint32_t time);

int32_t service_nvm_get_atcmd_alias_from_nvm(uint8_t *buff, uint32_t len);

int32_t service_nvm_set_atcmd_alias_to_nvm(uint8_t *buff, uint32_t len);

/***********************************************************/
/* User Data                                               */
/***********************************************************/

int32_t service_nvm_write_user_data (uint32_t offset, uint8_t *buff, uint32_t len);

int32_t service_nvm_read_user_data (uint32_t offset, uint8_t *buff, uint32_t len);

/***********************************************************/
/* RTC                                                     */
/***********************************************************/

uint32_t service_nvm_get_delta_sec_from_nvm (void);

int32_t service_nvm_set_delta_sec_to_nvm (uint32_t sec);

uint32_t service_nvm_get_delta_subsec_from_nvm (void);

int32_t service_nvm_set_delta_subsec_to_nvm (uint32_t subsec);

#ifdef SUPPORT_LORA
/***********************************************************/
/* LoRa                                                    */
/***********************************************************/
SERVICE_LORA_BAND service_nvm_get_band_from_nvm (void);

int32_t service_nvm_set_band_to_nvm (SERVICE_LORA_BAND band);

#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
int32_t service_nvm_get_mask_from_nvm (uint16_t *mask);

int32_t service_nvm_set_mask_to_nvm (uint16_t *mask);
#endif

int32_t service_nvm_get_app_eui_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_app_eui_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_app_key_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_app_key_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_app_skey_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_app_skey_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_dev_addr_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_dev_addr_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_dev_eui_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_dev_eui_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_net_id_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_net_id_to_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_get_nwk_skey_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_nwk_skey_to_nvm (uint8_t *buff, uint32_t len);

uint8_t service_nvm_get_retry_from_nvm (void);

int32_t service_nvm_set_retry_to_nvm (uint8_t retry);

SERVICE_LORA_CONFIRM_MODE service_nvm_get_cfm_from_nvm (void);

int32_t service_nvm_set_cfm_to_nvm (SERVICE_LORA_CONFIRM_MODE cfm);

SERVICE_LORA_JOIN_MODE service_nvm_get_njm_from_nvm (void);

int32_t service_nvm_set_njm_to_nvm (SERVICE_LORA_JOIN_MODE njm);

bool service_nvm_get_adr_from_nvm (void);

int32_t service_nvm_set_adr_to_nvm (bool adr);

SERVICE_LORA_CLASS service_nvm_get_class_from_nvm (void);

int32_t service_nvm_set_class_to_nvm (SERVICE_LORA_CLASS device_class);

SERVICE_LORA_DATA_RATE service_nvm_get_dr_from_nvm (void);

int32_t service_nvm_set_dr_to_nvm (SERVICE_LORA_DATA_RATE dr);

SERVICE_LORA_DATA_RATE service_nvm_get_rx2dr_from_nvm (void);

int32_t service_nvm_set_rx2dr_to_nvm (SERVICE_LORA_DATA_RATE dr);

uint32_t service_nvm_get_jn1dl_from_nvm (void);

int32_t service_nvm_set_jn1dl_to_nvm (uint32_t jn1dl);

uint32_t service_nvm_get_jn2dl_from_nvm (void);

int32_t service_nvm_set_jn2dl_to_nvm (uint32_t jn2dl);

bool service_nvm_get_pub_nwk_mode_from_nvm (void);

int32_t service_nvm_set_pub_nwk_mode_to_nvm (bool pnm);

uint32_t service_nvm_get_rx1dl_from_nvm (void);

int32_t service_nvm_set_rx1dl_to_nvm (uint32_t rx1dl);

uint32_t service_nvm_get_rx2dl_from_nvm (void);

int32_t service_nvm_set_rx2dl_to_nvm (uint32_t rx2dl);

uint8_t service_nvm_get_txpower_from_nvm (void);

int32_t service_nvm_set_txpower_to_nvm (uint8_t txp);

uint8_t service_nvm_get_linkcheck_from_nvm (void) ;

int32_t service_nvm_set_linkcheck_to_nvm (uint8_t mode) ;

uint8_t service_nvm_get_ping_slot_periodicity_from_nvm();

int32_t service_nvm_set_ping_slot_periodicity_to_nvm(uint8_t periodicity);

bool service_nvm_get_join_start_from_nvm(void);

int32_t service_nvm_set_join_start_to_nvm(bool join_start);

bool service_nvm_get_auto_join_from_nvm(void);

int32_t service_nvm_set_auto_join_to_nvm(bool auto_join);

uint32_t service_nvm_get_auto_join_period_from_nvm(void);

int32_t service_nvm_set_auto_join_period_to_nvm(uint32_t auto_join_period);

uint32_t service_nvm_get_auto_join_max_cnt_from_nvm(void);

int32_t service_nvm_set_auto_join_max_cnt_to_nvm(uint32_t auto_join_period);

uint32_t service_nvm_get_freq_from_nvm (void);

int32_t service_nvm_set_freq_to_nvm (uint32_t freq);

uint8_t service_nvm_get_sf_from_nvm (void);

int32_t service_nvm_set_sf_to_nvm (uint8_t spreadfact);

uint32_t service_nvm_get_bandwidth_from_nvm (void);

int32_t service_nvm_set_bandwidth_to_nvm (uint32_t bandwidth);

uint8_t service_nvm_get_codingrate_from_nvm (void);

int32_t service_nvm_set_codingrate_to_nvm (uint8_t codingrate);

uint16_t service_nvm_get_preamlen_from_nvm (void);

int32_t service_nvm_set_preamlen_to_nvm (uint16_t preamlen);

uint8_t service_nvm_get_powerdbm_from_nvm (void);

int32_t service_nvm_set_powerdbm_to_nvm (uint8_t powerdbm);

bool service_nvm_get_crypt_enable_from_nvm (void);

int32_t service_nvm_set_crypt_enable_to_nvm (bool crypt_enable);

int32_t service_nvm_get_crypt_key_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_crypt_key_to_nvm (uint8_t *buff, uint32_t len);

McSession_t *service_nvm_get_multicast_from_nvm(void);

int32_t service_nvm_set_multicast_to_nvm(McSession_t *McSession);

uint8_t service_nvm_get_tp_port_from_nvm(SERIAL_PORT port);

int32_t service_nvm_set_tp_port_to_nvm(SERIAL_PORT port, uint8_t tp_port);

uint32_t service_rui_get_chs_from_nvm(void);

uint32_t service_rui_set_chs_to_nvm(uint32_t frequency);

uint32_t service_nvm_set_fdev_to_nvm(uint32_t fdev) ;

uint32_t service_nvm_set_bitrate_to_nvm(uint32_t bitrate) ;

uint32_t service_nvm_get_bitrate_from_nvm(void) ;

uint32_t service_nvm_get_fdev_from_nvm(void) ;

uint32_t service_nvm_set_dcs_to_nvm(uint8_t dutycycle);

uint8_t service_nvm_get_dcs_from_nvm(void);

int32_t service_nvm_get_sn_from_nvm (uint8_t *buff, uint32_t len);

int32_t service_nvm_set_sn_to_nvm (uint8_t *buff, uint32_t len);

uint32_t service_nvm_set_rx2fq_to_nvm(uint32_t freq);

uint32_t service_nvm_get_rx2fq_from_nvm(void);

#endif

#endif

#ifdef __cplusplus
}
#endif

#endif  // __SERVICE_NVM_H__


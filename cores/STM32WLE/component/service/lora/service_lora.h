/**
 * @file        service_lora.h
 * @brief       Provide LoRa service layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.5
 */

#ifndef __SERVICE_LORA_H__
#define __SERVICE_LORA_H__

#ifdef SUPPORT_LORA

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "pin_define.h"
#include "LoRaMac.h"
#include "LoRaMacTypes.h"
#include "LmHandlerTypes.h"
#include "secure-element.h"

#define SERVICE_LORA_DLINK_BUFF_SIZE 256

#define LORAWAN_VERSION "LoRaWAN 1.0.3"

#define SERVICE_LORA_CHANNEL_ALL 0U
#define SERVICE_LORA_CHANNEL_0_63 0x00ff
#define SERVICE_LORA_CHANNEL_0_7 (1 << 0)
#define SERVICE_LORA_CHANNEL_8_15 (1 << 1)
#define SERVICE_LORA_CHANNEL_16_23 (1 << 2)
#define SERVICE_LORA_CHANNEL_24_31 (1 << 3)
#define SERVICE_LORA_CHANNEL_32_39 (1 << 4)
#define SERVICE_LORA_CHANNEL_40_47 (1 << 5)
#define SERVICE_LORA_CHANNEL_48_55 (1 << 6)
#define SERVICE_LORA_CHANNEL_56_63 (1 << 7)
#define SERVICE_LORA_CHANNEL_80_87 (1 << 10)
#define SERVICE_LORA_CHANNEL_88_95 (1 << 11)

    typedef enum _SERVICE_LORA_MAC_CMD
    {
        SERVICE_LORA_MAC_CMD_NONE,
        SERVICE_LORA_MAC_CMD_DEVICE_TIME,
        SERVICE_LORA_MAC_CMD_PING_SLOT_INFO,
    } SERVICE_LORA_MAC_CMD;

    typedef enum _SERVICE_LORA_CLASS_B_STATE
    {
        SERVICE_LORA_CLASS_B_S0,
        SERVICE_LORA_CLASS_B_S1,
        SERVICE_LORA_CLASS_B_S2,
        SERVICE_LORA_CLASS_B_S3,
        SERVICE_LORA_CLASS_B_COMPLETED,
    } SERVICE_LORA_CLASS_B_STATE;

    typedef enum _TIMEREQ_STATE
    {
       TIMEREQ_DISABLED,
       TIMEREQ_ENABLED
    } TIMEREQ_STATE;

    typedef struct SERVICE_LORA_RECEIVE
    {
        /*!
         * Application port
         */
        uint8_t Port;
        /*!
         * Downlink datarate
         */
        uint8_t RxDatarate;
        /*!
         * Pointer to the received data stream
         */
        uint8_t *Buffer;
        /*!
         * Size of the received data stream
         */
        uint8_t BufferSize;

        /*!
         * Rssi of the received packet
         */
        int16_t Rssi;
        /*!
         * Snr of the received packet
         */
        int8_t Snr;

        /*!
         * The downlink counter value for the received frame
         */
        uint32_t DownLinkCounter;
    } SERVICE_LORA_RECEIVE_T;

    typedef void (*service_lora_recv_cb)(SERVICE_LORA_RECEIVE_T *data);
    typedef void (*service_lora_join_cb)(int32_t status);
    typedef void (*service_lora_send_cb)(int32_t status);

    typedef enum _SERVICE_LORA_TX_POWER
    {
        SERVICE_LORA_TX_POWER_0 = TX_POWER_0,
        SERVICE_LORA_TX_POWER_1 = TX_POWER_1,
        SERVICE_LORA_TX_POWER_2 = TX_POWER_2,
        SERVICE_LORA_TX_POWER_3 = TX_POWER_3,
        SERVICE_LORA_TX_POWER_4 = TX_POWER_4,
        SERVICE_LORA_TX_POWER_5 = TX_POWER_5,
        SERVICE_LORA_TX_POWER_6 = TX_POWER_6,
        SERVICE_LORA_TX_POWER_7 = TX_POWER_7,
        SERVICE_LORA_TX_POWER_8 = TX_POWER_8,
        SERVICE_LORA_TX_POWER_9 = TX_POWER_9,
        SERVICE_LORA_TX_POWER_10 = TX_POWER_10,
        SERVICE_LORA_TX_POWER_11 = TX_POWER_11,
        SERVICE_LORA_TX_POWER_12 = TX_POWER_12,
        SERVICE_LORA_TX_POWER_13 = TX_POWER_13,
        SERVICE_LORA_TX_POWER_14 = TX_POWER_14,
        SERVICE_LORA_TX_POWER_15 = TX_POWER_15,
        SERVICE_LORA_TX_POWER_MAX = TX_POWER_15,
    } SERVICE_LORA_TX_POWER;

    typedef struct sbeacon_bgw
    {
        uint16_t GPS_coordinate;
        uint32_t latitude;
        uint32_t longitude;
        uint32_t net_ID;
        uint32_t gateway_ID;
    } beacon_bgw_t;

    typedef struct sdelay_send
    {
        uint8_t buffer[256];
        uint16_t len;
        uint8_t flag;
    }delay_send_t;

    typedef enum _SERVICE_LORA_WORK_MODE
    {
        SERVICE_LORA_P2P = 0,
        SERVICE_LORAWAN = 1,
        SERVICE_LORA_FSK = 2
    } SERVICE_LORA_WORK_MODE;

    typedef enum _LINK_CHECK_MODE
    {
        LINK_CHECK_DISABLE = 0,
        LINK_CHECK_ONCE = 1,
        LINK_CHECK_EVERYTIME = 2
    } LINK_CHECK_MODE;

    typedef enum _SERVICE_LORA_CONFIRM_MODE
    {
        SERVICE_LORA_NO_ACK = 0,
        SERVICE_LORA_ACK = 1,
    } SERVICE_LORA_CONFIRM_MODE;

    typedef enum _SERVICE_LORA_JOIN_MODE
    {
        SERVICE_LORA_ABP = 0,
        SERVICE_LORA_OTAA = 1,
    } SERVICE_LORA_JOIN_MODE;

    typedef enum _SERVICE_LORA_DATA_RATE
    {
        SERVICE_LORA_DR_0 = DR_0,
        SERVICE_LORA_DR_1 = DR_1,
        SERVICE_LORA_DR_2 = DR_2,
        SERVICE_LORA_DR_3 = DR_3,
        SERVICE_LORA_DR_4 = DR_4,
        SERVICE_LORA_DR_5 = DR_5,
        SERVICE_LORA_DR_6 = DR_6,
        SERVICE_LORA_DR_7 = DR_7,
        SERVICE_LORA_DR_8 = DR_8,
        SERVICE_LORA_DR_9 = DR_9,
        SERVICE_LORA_DR_10 = DR_10,
        SERVICE_LORA_DR_11 = DR_11,
        SERVICE_LORA_DR_12 = DR_12,
        SERVICE_LORA_DR_13 = DR_13,
        SERVICE_LORA_DR_14 = DR_14,
        SERVICE_LORA_DR_15 = DR_15,
    } SERVICE_LORA_DATA_RATE;

    typedef enum _SERVICE_LORA_CH_EIGHT_MODE
    {
        SERVICE_LORA_CH_EIGHT_MODE_0,
        SERVICE_LORA_CH_EIGHT_MODE_1,
        SERVICE_LORA_CH_EIGHT_MODE_2,
        SERVICE_LORA_CH_EIGHT_MODE_3,
        SERVICE_LORA_CH_EIGHT_MODE_4,
        SERVICE_LORA_CH_EIGHT_MODE_5,
        SERVICE_LORA_CH_EIGHT_MODE_6,
        SERVICE_LORA_CH_EIGHT_MODE_7,
        SERVICE_LORA_CH_EIGHT_MODE_8
    } SERVICE_LORA_CH_EIGHT_MODE;

    typedef struct _SERVICE_LORA_SEND_INFO
    {
        uint8_t port;
        bool retry_valid;
        uint8_t retry;
        bool confirm_valid;
        SERVICE_LORA_CONFIRM_MODE confirm;
    } SERVICE_LORA_SEND_INFO;

    typedef enum _SERVICE_LORA_CLASS
    {
        SERVICE_LORA_CLASS_A = 0,
        SERVICE_LORA_CLASS_B = 1,
        SERVICE_LORA_CLASS_C = 2,
    } SERVICE_LORA_CLASS;

    typedef enum _AS923_SUB_BAND
    {
        AS923_1 = 1,
        AS923_2 = 2,
        AS923_3 = 3,
        AS923_4 = 4
    } AS923_SUB_BAND;

    /*!
 * LoRaMAC region enumeration
 */
    typedef enum _SERVICE_LORA_BAND
    {
        /*!
     * AS band on 923MHz     SERVICE_LORA_AS923-1
     */
        SERVICE_LORA_AS923 = LORAMAC_REGION_AS923,
        /*!
     * Australian band on 915MHz
     */
        SERVICE_LORA_AU915 = LORAMAC_REGION_AU915,
        /*!
     * Chinese band on 470MHz
     */
        SERVICE_LORA_CN470 = LORAMAC_REGION_CN470,
        /*!
     * Chinese band on 779MHz
     */
        SERVICE_LORA_CN779 = LORAMAC_REGION_CN779,
        /*!
     * European band on 433MHz
     */
        SERVICE_LORA_EU433 = LORAMAC_REGION_EU433,
        /*!
     * European band on 868MHz
     */
        SERVICE_LORA_EU868 = LORAMAC_REGION_EU868,
        /*!
     * South korean band on 920MHz
     */
        SERVICE_LORA_KR920 = LORAMAC_REGION_KR920,
        /*!
     * India band on 865MHz
     */
        SERVICE_LORA_IN865 = LORAMAC_REGION_IN865,
        /*!
     * North american band on 915MHz
     */
        SERVICE_LORA_US915 = LORAMAC_REGION_US915,
#ifndef LEGACY
        /*!
     * Russia band on 864MHz
     */
        SERVICE_LORA_RU864 = LORAMAC_REGION_RU864,
#else
    /*!
     * North american band on 915MHz with a maximum of 16 channels
     */
    SERVICE_LORA_US915_HYBRID = LORAMAC_REGION_US915_HYBRID,
#endif

    /*
     * 10 - 19  Reserved for lorawan protocol stack ,after 20 used by RAK 
     */
       SERVICE_LORA_AS923_2 = 20,

       SERVICE_LORA_AS923_3 = 21,

       SERVICE_LORA_AS923_4 = 22,

    } SERVICE_LORA_BAND;

    LmHandlerErrorStatus_t LmHandlerPackageRegister( uint8_t id, void *params );
    bool LmHandlerPackageIsInitialized( uint8_t id );
    bool LmHandlerPackageIsRunning( uint8_t id );
    void LmHandlerPackagesProcess( void );

    int32_t service_lora_init(SERVICE_LORA_BAND band);

    SERVICE_LORA_BAND service_lora_get_band(void);

    int32_t service_lora_set_band(SERVICE_LORA_BAND band);

#if defined(REGION_CN470) || defined(REGION_US915) || \
    defined(REGION_AU915)
    int32_t service_lora_get_mask(uint16_t *mask);

    int32_t service_lora_set_mask(uint16_t *mask, bool commit);
#endif

    int32_t service_lora_get_app_eui(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_app_eui(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_app_key(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_app_key(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_app_skey(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_app_skey(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_dev_addr(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_dev_addr(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_dev_eui(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_dev_eui(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_net_id(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_nwk_id(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_nwk_skey(uint8_t *buff, uint32_t len);

    int32_t service_lora_set_nwk_skey(uint8_t *buff, uint32_t len);

    int32_t service_lora_get_McRoot_key(uint8_t *buff);

    int32_t service_lora_set_lora_default(void);

    uint8_t service_lora_get_retry(void);

    int32_t service_lora_set_retry(uint8_t retry);

    SERVICE_LORA_CONFIRM_MODE service_lora_get_cfm(void);

    int32_t service_lora_set_cfm(SERVICE_LORA_CONFIRM_MODE cfm);

    bool service_lora_get_cfs(void);

    int32_t service_lora_join(int32_t param1, int32_t param2, int32_t param3, int32_t param4);

    SERVICE_LORA_WORK_MODE service_lora_get_nwm(void);

    int32_t service_lora_set_nwm(SERVICE_LORA_WORK_MODE nwm);

    SERVICE_LORA_JOIN_MODE service_lora_get_njm(void);

    int32_t service_lora_set_njm(SERVICE_LORA_JOIN_MODE njm, bool commit);

    bool service_lora_get_njs(void);

    int32_t service_lora_send(uint8_t *buff, uint32_t len, SERVICE_LORA_SEND_INFO info, bool blocking);

    bool service_lora_get_adr(void);

    int32_t service_lora_set_adr(bool adr, bool commit);

    SERVICE_LORA_CLASS service_lora_get_class(void);

    SERVICE_LORA_CLASS service_lora_get_real_class_from_stack(void);

    int32_t service_lora_set_class(SERVICE_LORA_CLASS device_class, bool commit);

    bool service_lora_get_dcs(void);

    int32_t service_lora_set_dcs(uint8_t dutycycle, bool commit );

    SERVICE_LORA_DATA_RATE service_lora_get_dr(void);

    int32_t service_lora_set_dr(SERVICE_LORA_DATA_RATE dr, bool commit);

    uint32_t service_lora_get_jn1dl(void);

    int32_t service_lora_set_jn1dl(uint32_t jn1dl, bool commit);

    uint32_t service_lora_get_jn2dl(void);

    int32_t service_lora_set_jn2dl(uint32_t jn2dl, bool commit);

    bool service_lora_get_pub_nwk_mode(void);

    int32_t service_lora_set_pub_nwk_mode(bool pnm, bool commit);

    uint32_t service_lora_get_rx1dl(void);

    int32_t service_lora_set_rx1dl(uint32_t rx1dl, bool commit);

    uint32_t service_lora_get_rx2dl(void);

    int32_t service_lora_set_rx2dl(uint32_t rx2dl, bool commit);

    uint8_t service_lora_get_txpower(void);

    int32_t service_lora_set_txpower(uint8_t txp, bool commit);

    uint8_t service_lora_get_ping_slot_periodicity(void);

    int32_t service_lora_set_ping_slot_periodicity(uint8_t periodicity);

    uint32_t service_lora_get_beacon_freq(void);

    uint32_t service_lora_get_beacon_time(void);

    int16_t service_lora_get_rssi(void);

    int8_t service_lora_get_snr(void);

    int32_t service_lora_get_local_time(char *local_time);

    uint32_t service_lora_get_lorawan_version(char **version);

    uint32_t service_lora_get_rx2freq(void);

    uint32_t service_lora_set_rx2freq(uint32_t freq,bool commit);

    uint32_t service_lora_set_rx2dr(SERVICE_LORA_DATA_RATE datarate, bool commit);

    SERVICE_LORA_DATA_RATE service_lora_get_rx2dr(void);

    int32_t service_lora_set_linkcheck(uint8_t mode);

    uint8_t service_lora_get_linkcheck(void);

    void service_lora_lptp_send_callback(int status);

    int32_t service_lora_lptp_send(uint8_t port, bool ack, uint8_t *p_data, uint16_t len);

    bool service_lora_get_join_start(void);

    int32_t service_lora_set_join_start(bool join_start);

    bool service_lora_get_auto_join(void);

    int32_t service_lora_set_auto_join(bool auto_join);

    uint32_t service_lora_get_auto_join_period(void);

    int32_t service_lora_set_auto_join_period(uint32_t auto_join_period);

    uint32_t service_lora_get_auto_join_max_cnt(void);

    int32_t service_lora_set_auto_join_max_cnt(uint32_t auto_join_period);

    int32_t service_lora_get_last_recv(uint8_t *port, uint8_t *buff, uint32_t len);

    int32_t service_lora_set_che(uint8_t sub_band);

    int32_t service_lora_get_che(void);

    beacon_bgw_t service_lora_get_beacon_gwspecific(void);

    int32_t service_lora_get_chs(void);

    int32_t service_lora_set_chs(uint32_t frequency);

    int32_t service_lora_register_recv_cb(service_lora_recv_cb callback);

    int32_t service_lora_register_join_cb(service_lora_join_cb callback);

    int32_t service_lora_register_send_cb(service_lora_send_cb callback);

    uint32_t service_lora_get_beacon_dr(void);

    SERVICE_LORA_CLASS_B_STATE service_lora_get_class_b_state(void);

    int32_t service_lora_query_txPossible(int16_t len);

    void service_lora_suspend(void);

    void service_lora_resume(void);

    uint8_t service_lora_get_timereq(void);

    int32_t service_lora_set_timereq(uint8_t mode);

    void service_lora_systemMaxRxError(void);

    int32_t service_lora_get_lbt();
    int32_t service_lora_set_lbt(uint8_t enable);
    int16_t service_lora_get_lbt_rssi();
    int32_t service_lora_set_lbt_rssi(int16_t rssi);
    uint32_t service_lora_get_lbt_scantime();
    int32_t service_lora_set_lbt_scantime(uint32_t time);

#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif // __SERVICE_LORA_H__

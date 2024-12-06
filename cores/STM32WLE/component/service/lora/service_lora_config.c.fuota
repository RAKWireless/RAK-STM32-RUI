#ifdef SUPPORT_LORA

#include "udrv_errno.h"
#include "service_lora.h"
#include "Region.h"
#include "service_lora_test.h"
#include "LoRaMac.h"
#include "service_nvm.h"
extern PRE_rui_cfg_t g_rui_cfg_t;

#include "LmHandler.h"
#include "LmhPackage.h"

#ifndef PKG_MAX_NUMBER
#define PKG_MAX_NUMBER                              4
#endif
#define OVER_THE_AIR_ACTIVATION                            1
LmhPackage_t *LmHandlerPackages_fuota[PKG_MAX_NUMBER];
SERVICE_LORA_BAND service_lora_fuota_get_band();

static TimerTime_t DutyCycleWaitTime = 0;
static bool IsUplinkTxPending = false;
volatile bool IsClockSynched = false;

static CommissioningParams_t CommissioningParams =
{
    .IsOtaaActivation = OVER_THE_AIR_ACTIVATION,
    .DevEui = { 0 },  // Automatically filed from secure-element
    .JoinEui = { 0 }, // Automatically filed from secure-element
    .SePin = { 0 },   // Automatically filed from secure-element
    .NetworkId = ( uint32_t )0,
    .DevAddr = ( uint32_t )0x00000000,
};

static LmHandlerTxParams_t TxParams =
{
    .CommissioningParams = &CommissioningParams,
    .MsgType = LORAMAC_HANDLER_UNCONFIRMED_MSG,
    .AckReceived = 0,
    .Datarate = DR_0,
    .UplinkCounter = 0,
    .AppData =
    {
        .Port = 0,
        .BufferSize = 0,
        .Buffer = NULL,
    },
    .TxPower = TX_POWER_0,
    .Channel = 0,
};


int32_t service_lora_get_app_eui(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_app_eui_from_nvm(buff, len);
}

int32_t service_lora_set_app_eui(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_JOIN_EUI;
    mibReq.Param.JoinEui = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_app_eui_to_nvm(buff, len);
}

int32_t service_lora_get_app_key(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_app_key_from_nvm(buff, len);
}

int32_t service_lora_set_app_key(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_APP_KEY;
    mibReq.Param.AppKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_NWK_KEY;
    mibReq.Param.NwkKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_app_key_to_nvm(buff, len);
}

int32_t service_lora_get_app_skey(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_app_skey_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 16)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 16);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_APP_S_KEY;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, mibReq.Param.AppSKey, 16);
        return UDRV_RETURN_OK;
    }
    }
}

int32_t service_lora_set_app_skey(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_APP_S_KEY;
    mibReq.Param.AppSKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    {
        service_lora_mac_nvm_data_reset();
        service_nvm_set_lora_nvm_data_to_nvm();
        restore_abp_config();
    }

    return service_nvm_set_app_skey_to_nvm(buff, len);
}

int32_t service_lora_get_dev_addr(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
        case SERVICE_LORA_ABP:
            return service_nvm_get_dev_addr_from_nvm(buff, len);
        case SERVICE_LORA_OTAA:
        default:
        {
            MibRequestConfirm_t mibReq;

            if (len < 4)
            {
                return -UDRV_INTERNAL_ERR;
            }

            if (service_lora_get_njs() == false)
            {
                memset(buff, 0, 4);
                return UDRV_RETURN_OK;
            }

            mibReq.Type = MIB_DEV_ADDR;
            if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }

            *(uint32_t *)buff = __builtin_bswap32(mibReq.Param.DevAddr);
            return UDRV_RETURN_OK;
        }
    }
}

int32_t service_lora_set_dev_addr(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_DEV_ADDR;
    mibReq.Param.DevAddr = __builtin_bswap32(*(uint32_t *)buff);
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    {
        service_lora_mac_nvm_data_reset();
        service_nvm_set_lora_nvm_data_to_nvm();
        restore_abp_config();
    }

    return service_nvm_set_dev_addr_to_nvm(buff, len);
}


int32_t service_lora_get_dev_eui(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_dev_eui_from_nvm(buff, len);
}

int32_t service_lora_set_dev_eui(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    /* P2P mode will also set deveui, which is used as a unique ID */
    if(SERVICE_LORAWAN==service_lora_get_nwm())
    {
        MibRequestConfirm_t mibReq;
        LoRaMacStatus_t status;

        mibReq.Type = MIB_DEV_EUI;
        mibReq.Param.DevEui = buff;
        if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
        {
            if (status == LORAMAC_STATUS_BUSY) {
                return -UDRV_BUSY;
            } else {
                return -UDRV_INTERNAL_ERR;
            }
        }
    }
    return service_nvm_set_dev_eui_to_nvm(buff, len);
}

SERVICE_LORA_WORK_MODE service_lora_get_nwm(void)
{
    return service_nvm_get_nwm_from_nvm();
}

int32_t service_lora_set_nwm(SERVICE_LORA_WORK_MODE nwm)
{

    switch (nwm)
    {
    case SERVICE_LORA_P2P:
    case SERVICE_LORAWAN:
    case SERVICE_LORA_FSK:
        break;
    default:
        return -UDRV_INTERNAL_ERR;
    }

    service_nvm_set_nwm_to_nvm(nwm);

    return UDRV_RETURN_OK;
}

SERVICE_LORA_JOIN_MODE service_lora_get_njm(void)
{
    return service_nvm_get_njm_from_nvm();
}

bool service_lora_get_njs(void)
{
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_NETWORK_ACTIVATION;
    status = LoRaMacMibGetRequestConfirm(&mibReq);

    if (status == LORAMAC_STATUS_OK)
    {
        if (mibReq.Param.NetworkActivation == ACTIVATION_TYPE_NONE)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

uint8_t service_lora_get_retry(void)
{
    return service_nvm_get_retry_from_nvm();
}

int32_t service_lora_set_retry(uint8_t retry)
{
    if(retry>7)
        return -UDRV_WRONG_ARG;
    return service_nvm_set_retry_to_nvm(retry);
}

SERVICE_LORA_CONFIRM_MODE service_lora_get_cfm(void)
{
    return service_nvm_get_cfm_from_nvm();
}

int32_t service_lora_set_cfm(SERVICE_LORA_CONFIRM_MODE cfm)
{
    return service_nvm_set_cfm_to_nvm(cfm);
}

int32_t service_lora_get_nwk_skey(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_nwk_skey_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 16)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 16);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_NWK_S_ENC_KEY;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, mibReq.Param.NwkSEncKey, 16);
        return UDRV_RETURN_OK;
    }
    }
}


int32_t service_lora_set_nwk_skey(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_F_NWK_S_INT_KEY;
    mibReq.Param.FNwkSIntKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_S_NWK_S_INT_KEY;
    mibReq.Param.SNwkSIntKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_NWK_S_ENC_KEY;
    mibReq.Param.NwkSEncKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    {
        service_lora_mac_nvm_data_reset();
        service_nvm_set_lora_nvm_data_to_nvm();
        restore_abp_config();
    }

    return service_nvm_set_nwk_skey_to_nvm(buff, len);
}

int32_t service_lora_get_net_id(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_net_id_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 4)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 4);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_NET_ID;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, (uint8_t *)&mibReq.Param.NetID, 4);
        return UDRV_RETURN_OK;
    }
    }
}


int32_t service_lora_get_McRoot_key(uint8_t *buff)
{
#ifndef LORA_STACK_104
    return Get_McRoot_Key(buff);
#endif
}

bool service_lora_get_adr(void)
{
    return service_nvm_get_adr_from_nvm();
}

int32_t service_lora_set_adr(bool adr, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_ADR;
    mibReq.Param.AdrEnable = adr;
    status = LoRaMacMibSetRequestConfirm(&mibReq);

    if(status == LORAMAC_STATUS_PARAMETER_INVALID) {
        return -UDRV_WRONG_ARG;
    } else if(status == LORAMAC_STATUS_BUSY) {
        return -UDRV_BUSY;
    }

    if (commit)
    {
        return service_nvm_set_adr_to_nvm(adr);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

SERVICE_LORA_CLASS service_lora_get_class(void)
{
    return service_nvm_get_class_from_nvm();
}


bool service_lora_get_dcs(void)
{
    // GetPhyParams_t getPhy;
    // PhyParam_t phyParam;

    // getPhy.Attribute = PHY_DUTY_CYCLE;
    // phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    // return (uint32_t)phyParam.Value;
    return service_nvm_get_dcs_from_nvm();
}

int32_t service_lora_set_dcs(uint8_t dutycycle, bool commit )
{
    LoRaMacTestSetDutyCycleOn(dutycycle);

    if(commit)
    {
        return service_nvm_set_dcs_to_nvm(dutycycle);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

SERVICE_LORA_DATA_RATE service_lora_get_dr(void)
{
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_CHANNELS_DATARATE;
    status = LoRaMacMibGetRequestConfirm(&mibReq);
    //return service_nvm_get_dr_from_nvm();
    return mibReq.Param.ChannelsDatarate;
}

uint32_t service_lora_get_jn1dl(void)
{
    return service_nvm_get_jn1dl_from_nvm();
}

int32_t service_lora_set_jn1dl(uint32_t jn1dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_JOIN_ACCEPT_DELAY_1;
    mibReq.Param.JoinAcceptDelay1 = jn1dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_jn1dl_to_nvm(jn1dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}
uint32_t service_lora_get_jn2dl(void)
{
    return service_nvm_get_jn2dl_from_nvm();
}

int32_t service_lora_set_jn2dl(uint32_t jn2dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_JOIN_ACCEPT_DELAY_2;
    mibReq.Param.JoinAcceptDelay2 = jn2dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_jn2dl_to_nvm(jn2dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}
bool service_lora_get_pub_nwk_mode(void)
{
    return service_nvm_get_pub_nwk_mode_from_nvm();
}

int32_t service_lora_set_pub_nwk_mode(bool pnm, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_PUBLIC_NETWORK;
    mibReq.Param.EnablePublicNetwork = pnm;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_pub_nwk_mode_to_nvm(pnm);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}
uint32_t service_lora_get_rx1dl(void)
{
    if ((service_lora_get_njm() == SERVICE_LORA_OTAA) && service_lora_get_njs())
    {
        MibRequestConfirm_t mibReq;

        mibReq.Type = MIB_RECEIVE_DELAY_1;
        if (LoRaMacMibGetRequestConfirm(&mibReq) == LORAMAC_STATUS_OK)
        {
            return mibReq.Param.ReceiveDelay1;
        }
    }
    else
    {
        return service_nvm_get_rx1dl_from_nvm();
    }
}
int32_t service_lora_set_rx1dl(uint32_t rx1dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_RECEIVE_DELAY_1;
    mibReq.Param.ReceiveDelay1 = rx1dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RECEIVE_DELAY_2;
    mibReq.Param.ReceiveDelay2 = rx1dl + 1000;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        if ((ret = service_nvm_set_rx2dl_to_nvm(rx1dl + 1000)) != UDRV_RETURN_OK)
        {
            return ret;
        }
        return service_nvm_set_rx1dl_to_nvm(rx1dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}
uint32_t service_lora_get_rx2dl(void)
{
    return service_nvm_get_rx2dl_from_nvm();
}

int32_t service_lora_set_rx2dl(uint32_t rx2dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_RECEIVE_DELAY_2;
    mibReq.Param.ReceiveDelay2 = rx2dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RECEIVE_DELAY_1;
    mibReq.Param.ReceiveDelay1 = rx2dl - 1000;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        if ((ret = service_nvm_set_rx1dl_to_nvm(rx2dl - 1000)) != UDRV_RETURN_OK)
        {
            return ret;
        }
        return service_nvm_set_rx2dl_to_nvm(rx2dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}
uint8_t service_lora_get_txpower(void)
{
    return service_nvm_get_txpower_from_nvm();
}
uint8_t service_lora_get_ping_slot_periodicity(void)
{
    return service_nvm_get_ping_slot_periodicity_from_nvm();
}

int32_t service_lora_set_ping_slot_periodicity(uint8_t periodicity)
{
    return service_nvm_set_ping_slot_periodicity_to_nvm(periodicity);
}
uint32_t service_lora_get_beacon_freq(void)
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    getPhy.Attribute = PHY_BEACON_CHANNEL_FREQ;
    phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    return (uint32_t)phyParam.Value;
}


uint32_t service_lora_get_beacon_dr(void)
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    getPhy.Attribute = PHY_BEACON_CHANNEL_DR;
    phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    return (uint32_t)phyParam.Value;
}

static uint8_t rak3172_sprintf(char *local_time,char * fmt, ...)
{
    va_list aptr;

    va_start (aptr, fmt);
    tiny_vsnprintf_like(local_time,24,fmt, aptr);
    va_end (aptr);
}

int32_t service_lora_get_local_time(char *local_time)
{
    struct tm localtime;
    SysTime_t UnixEpoch = SysTimeGet();

    UnixEpoch.Seconds -= 18; /*removing leap seconds*/
    SysTimeLocalTime(UnixEpoch.Seconds, &localtime);
#ifdef rak3172
    rak3172_sprintf(local_time,"%02dh%02dm%02ds on %02d/%02d/%04d", localtime.tm_hour, localtime.tm_min, localtime.tm_sec, localtime.tm_mon + 1, localtime.tm_mday, localtime.tm_year + 1900);
#else
    sprintf(local_time, "%02dh%02dm%02ds on %02d/%02d/%04d", localtime.tm_hour, localtime.tm_min, localtime.tm_sec, localtime.tm_mon + 1, localtime.tm_mday, localtime.tm_year + 1900);
#endif

    return UDRV_RETURN_OK;
}
uint32_t service_lora_get_rx2freq(void)
{
    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    return mibReq.Param.Rx2Channel.Frequency;
}
uint32_t service_lora_set_rx2freq(uint32_t freq,bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Param.Rx2Channel.Frequency = freq;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        if (commit)
        {
            return service_nvm_set_rx2fq_to_nvm(freq);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }


}
uint32_t service_lora_set_rx2dr(SERVICE_LORA_DATA_RATE datarate, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RXC_CHANNEL;
    mibReq.Param.RxCChannel.Datarate = (uint8_t)datarate;

    status = LoRaMacMibSetRequestConfirm(&mibReq);

    mibReq.Type = MIB_RX2_CHANNEL;
    mibReq.Param.Rx2Channel.Datarate = (uint8_t)datarate;

    status = LoRaMacMibSetRequestConfirm(&mibReq);
    if (status == LORAMAC_STATUS_OK)
    {
        if (commit)
        {
            return service_nvm_set_rx2dr_to_nvm(datarate);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }
    else if (status == LORAMAC_STATUS_PARAMETER_INVALID)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}
SERVICE_LORA_DATA_RATE service_lora_get_rx2dr(void)
{
    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    return mibReq.Param.Rx2Channel.Datarate;
    //return service_nvm_get_rx2dr_from_nvm();
}

uint8_t service_lora_get_linkcheck(void)
{
    return service_nvm_get_linkcheck_from_nvm();
}

int32_t service_lora_set_linkcheck(uint8_t mode)
{
    if(mode>2)
    {
        return -UDRV_WRONG_ARG;
    }
    return service_nvm_set_linkcheck_to_nvm(mode);
}

bool service_lora_get_join_start(void)
{
    return service_nvm_get_join_start_from_nvm();
}

int32_t service_lora_set_join_start(bool join_start)
{
    return service_nvm_set_join_start_to_nvm(join_start);
}

bool service_lora_get_auto_join(void)
{
    return service_nvm_get_auto_join_from_nvm();
}

int32_t service_lora_set_auto_join(bool auto_join)
{
    return service_nvm_set_auto_join_to_nvm(auto_join);
}

uint32_t service_lora_get_auto_join_period(void)
{
    return service_nvm_get_auto_join_period_from_nvm();
}
int32_t service_lora_set_auto_join_period(uint32_t auto_join_period)
{
    return service_nvm_set_auto_join_period_to_nvm(auto_join_period);
}

uint32_t service_lora_get_auto_join_max_cnt(void)
{
    return service_nvm_get_auto_join_max_cnt_from_nvm();
}

int32_t service_lora_set_auto_join_max_cnt(uint32_t auto_join_max_cnt)
{
    return service_nvm_set_auto_join_max_cnt_to_nvm(auto_join_max_cnt);
}

int32_t service_lora_get_lbt()
{
    return service_nvm_get_lbt_from_nvm();
}

int32_t service_lora_set_lbt(uint8_t enable)
{
    return service_nvm_set_lbt_to_nvm(enable);
}

int16_t service_lora_get_lbt_rssi()
{
    return service_nvm_get_lbt_rssi_from_nvm();
}

int32_t service_lora_set_lbt_rssi(int16_t rssi)
{
    return service_nvm_set_lbt_rssi_to_nvm(rssi);
}

uint32_t service_lora_get_lbt_scantime()
{
    return service_nvm_get_lbt_scantime_from_nvm();
}

int32_t service_lora_set_lbt_scantime(uint32_t time)
{
    return service_nvm_set_lbt_scantime_to_nvm(time);
}
uint16_t service_lora_get_DevNonce()
{
    return service_nvm_get_DevNonce_from_nvm();
}

int32_t service_lora_set_DevNonce(uint16_t devnonce)
{
    return service_nvm_set_DevNonce_to_nvm(devnonce);
}

int32_t service_lora_set_IsCertPortOn(bool IsCertPortOn)
{
    if(IsCertPortOn)
        return service_nvm_set_IsCertPortOn_to_nvm(1);
    else
        return service_nvm_set_IsCertPortOn_to_nvm(0);
}

uint8_t service_lora_get_IsCertPortOn(void)
{
    return service_nvm_get_IsCertPortOn_from_nvm();
}

SERVICE_LORA_BAND service_lora_get_band(void)
{
    return service_nvm_get_band_from_nvm();
}

int32_t service_lora_get_chs(void)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if ((band != SERVICE_LORA_AU915) && (band != SERVICE_LORA_US915) && (band != SERVICE_LORA_CN470) && (band != SERVICE_LORA_LA915))
    {
        return -UDRV_INTERNAL_ERR;
    }
    return service_nvm_get_chs_from_nvm();
}


bool service_lora_region_isActive(SERVICE_LORA_BAND band)
{
    if( RegionIsActive( band ) == false )
    {
        if(band == SERVICE_LORA_AS923 || band == SERVICE_LORA_AS923_2 || band == SERVICE_LORA_AS923_3 || band == SERVICE_LORA_AS923_4)
        {
            if( RegionIsActive( SERVICE_LORA_AS923 ) == false )
                return false;
        }
        else
            return false;
    }
    return true;
}

#ifdef LORA_STACK_104

static uint32_t crc_cal(uint8_t * data,uint32_t size)
{
    uint32_t calculatedCrc32 = Crc32Init();
    for( uint16_t i = 0; i < ( size - sizeof( uint32_t ) ); i++ )
    {
        calculatedCrc32 = Crc32Update( calculatedCrc32, data +i, 1 );
    }
    calculatedCrc32 = Crc32Finalize( calculatedCrc32 );
    return calculatedCrc32;
}
void restore_abp_config(void)
{
    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_NVM_CTXS;
    LoRaMacMibGetRequestConfirm( &mibReq );
    LoRaMacNvmData_t* nvm = mibReq.Param.Contexts;
    LoRaMacCryptoNvmData_t * crypto = service_nvm_get_crypto_from_nvm();
    LoRaMacNvmDataGroup1_t * macgroup1 = service_nvm_get_macgroup1_from_nvm();
    LoRaMacNvmDataGroup2_t * macgroup2 = service_nvm_get_macgroup2_from_nvm();
    SecureElementNvmData_t * secureelement = service_nvm_get_sec_element_from_nvm();
    ChannelParams_t * regionchannels = service_nvm_get_regionchannels_from_nvm();

    if(crc_cal(crypto,sizeof(LoRaMacCryptoNvmData_t)) == crypto->Crc32)
        memcpy(&(nvm->Crypto),crypto,sizeof(LoRaMacCryptoNvmData_t));

    if(crc_cal(macgroup1,sizeof(LoRaMacNvmDataGroup1_t)) == macgroup1->Crc32)
        memcpy(&(nvm->MacGroup1),macgroup1,sizeof(LoRaMacNvmDataGroup1_t));

    if(crc_cal(macgroup2,sizeof(LoRaMacNvmDataGroup2_t)) == macgroup2->Crc32)
        memcpy(&(nvm->MacGroup2),macgroup2,sizeof(LoRaMacNvmDataGroup2_t));

    if(crc_cal(secureelement,sizeof(SecureElementNvmData_t)) == secureelement->Crc32)
        memcpy(&(nvm->SecureElement),secureelement,sizeof(SecureElementNvmData_t));
    
    for (int8_t i=0;i<REGION_NVM_MAX_NB_CHANNELS;i++) {
        if ( regionchannels[i].Frequency != 0 )
            nvm->RegionGroup2.Channels[i].Rx1Frequency = regionchannels[i].Rx1Frequency;
    }

}

#endif

static bool LmHandlerFuotaPackageIsInitialized( uint8_t id )
{
    if (( id < PKG_MAX_NUMBER ) && ( LmHandlerPackages_fuota[id]->IsInitialized != NULL ))
    {
        return LmHandlerPackages_fuota[id]->IsInitialized( );
    }
    else
    {
        return false;
    }
}

void LmHandlerFuotaPackagesProcess( void )
{
    for( int8_t i = 0; i < PKG_MAX_NUMBER; i++ )
    {
        if( ( LmHandlerPackages_fuota[i] != NULL ) &&
            ( LmHandlerPackages_fuota[i]->Process != NULL ) &&
            ( LmHandlerFuotaPackageIsInitialized( i ) != false ) )
        {
            LmHandlerPackages_fuota[i]->Process( );
        }
    }
}


static LoRaMacPrimitives_t LoRaMacPrimitives;
static LoRaMacCallback_t LoRaMacCallbacks_fuota;
int32_t service_fuota_nvm_init()
{
    udrv_flash_read(SERVICE_NVM_RUI_CONFIG_NVM_ADDR, sizeof(PRE_rui_cfg_t), (uint8_t *)&g_rui_cfg_t);
}
int32_t service_fuota_lora_config()    
{
    uint8_t buff[16];

    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_ABP_LORAWAN_VERSION;
    mibReq.Param.AbpLrWanVersion.Value = 0x01000400;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -1;
    }


    SERVICE_LORA_BAND band = service_lora_fuota_get_band();
    uint16_t channel_mask[REGION_NVM_CHANNELS_MASK_SIZE] = {0};
    if(band == SERVICE_LORA_EU868)
    {
        if(service_nvm_get_chs_from_nvm()==0)
        {
            channel_mask[0] = LC( 1 ) + LC( 2 ) + LC( 3 );
        }
        else
        {
            //Check whether the frequency meets the requirements
            mibReq.Type = MIB_CHANNELS;
            LoRaMacMibGetRequestConfirm(&mibReq);

            for(int i=0;i<4;i++)
            {
                if(service_lora_get_chs() == mibReq.Param.ChannelList[i].Frequency)
                {
                    channel_mask[0]=LC( i+1 );
                    break;
                }
                if(i==3)
                {
                    return -2;
                }
            }
            mibReq.Type = MIB_CHANNELS_MASK;
            mibReq.Param.ChannelsMask = channel_mask;
            if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -3;
            }

            mibReq.Type = MIB_CHANNELS_DEFAULT_MASK;
            mibReq.Param.ChannelsMask = channel_mask;
            if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -4;
            }

        }
    }

    mibReq.Type = MIB_NETWORK_ACTIVATION;
    if(LoRaMacMibGetRequestConfirm(&mibReq) == LORAMAC_STATUS_OK)
    {
        if (mibReq.Param.NetworkActivation == ACTIVATION_TYPE_ABP)
        {
            mibReq.Param.NetworkActivation = ACTIVATION_TYPE_NONE;
        }
    }
    LoRaMacMibSetRequestConfirm(&mibReq);

    service_nvm_get_dev_eui_from_nvm(buff, 8);
    mibReq.Type = MIB_DEV_EUI;
    mibReq.Param.DevEui = buff;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -5;
    }
    service_nvm_get_app_eui_from_nvm(buff, 8);
    mibReq.Type = MIB_JOIN_EUI;
    mibReq.Param.JoinEui = buff;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -6;
    }

    service_nvm_get_app_key_from_nvm(buff, 16);
    mibReq.Type = MIB_APP_KEY;
    mibReq.Param.AppKey = buff;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -7;
    }

    mibReq.Type = MIB_NWK_KEY;
    mibReq.Param.NwkKey = buff;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -8;
    }

service_lora_setup_multicast();
    mibReq.Type = MIB_DEVICE_CLASS;
    if(service_lora_get_class() == SERVICE_LORA_CLASS_A)
        mibReq.Param.Class = CLASS_A;
    else if(service_lora_get_class() == SERVICE_LORA_CLASS_B)
        mibReq.Param.Class = CLASS_B;
    else if(service_lora_get_class() == SERVICE_LORA_CLASS_C)
        mibReq.Param.Class = CLASS_C;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -9;
    }

    service_lora_set_adr(service_nvm_get_adr_from_nvm(), false);
    service_lora_set_rx2dr(service_nvm_get_rx2dr_from_nvm(), false);
    service_lora_set_rx2freq(service_nvm_get_rx2fq_from_nvm(), false);
    service_lora_set_jn1dl(service_nvm_get_jn1dl_from_nvm(), false);
    service_lora_set_pub_nwk_mode(service_nvm_get_pub_nwk_mode_from_nvm(), false);
    service_lora_set_rx1dl(service_nvm_get_rx1dl_from_nvm(), false);
    service_lora_set_dcs(service_nvm_get_dcs_from_nvm(), false);

    mibReq.Type = MIB_NVM_CTXS;
    LoRaMacMibGetRequestConfirm( &mibReq );
    LoRaMacNvmData_t* nvm = mibReq.Param.Contexts;
    nvm->Crypto.DevNonce = service_lora_get_DevNonce();

    nvm->MacGroup2.IsCertPortOn = service_lora_get_IsCertPortOn();

    // Update the DEFAULT_SYSTEM_MAX_RX_ERROR
    mibReq.Type = MIB_SYSTEM_MAX_RX_ERROR;
    mibReq.Param.SystemMaxRxError = 25;
    LoRaMacMibSetRequestConfirm( &mibReq );


}

int32_t service_lora_fuota_join(void)
{
    LoRaMacStatus_t status;
    uint8_t rbuff[16];
    SERVICE_LORA_JOIN_MODE njm = SERVICE_LORA_OTAA;
    MlmeReq_t mlmeReq;
    mlmeReq.Type = MLME_JOIN;
    mlmeReq.Req.Join.Datarate = service_nvm_get_dr_from_nvm();
    mlmeReq.Req.Join.NetworkActivation = ACTIVATION_TYPE_OTAA;

    status = LoRaMacMlmeRequest(&mlmeReq);
    if(status == LORAMAC_STATUS_OK)
    {
        MibRequestConfirm_t mibReq;
        mibReq.Type = MIB_NVM_CTXS;
        LoRaMacMibGetRequestConfirm( &mibReq );
        LoRaMacNvmData_t* nvm = mibReq.Param.Contexts;
        service_lora_set_DevNonce(nvm->Crypto.DevNonce);
        return 1;
    }
    return 0;
        
}

SERVICE_LORA_BAND service_lora_fuota_get_band()
{
    SERVICE_LORA_BAND band = service_nvm_get_band_from_nvm();
    if(band == SERVICE_LORA_AS923 || band == SERVICE_LORA_AS923_2 || band == SERVICE_LORA_AS923_3 || band == SERVICE_LORA_AS923_4)
        band = SERVICE_LORA_AS923;
    return band;
}

LmHandlerErrorStatus_t LmHandlerSend( LmHandlerAppData_t *appData, LmHandlerMsgTypes_t isTxConfirmed )
{
    LoRaMacStatus_t status;
    McpsReq_t mcpsReq;
    LoRaMacTxInfo_t txInfo;
    SERVICE_LORA_DATA_RATE dr = service_nvm_get_dr_from_nvm();

    TxParams.MsgType = isTxConfirmed;
    mcpsReq.Type = ( isTxConfirmed == LORAMAC_HANDLER_UNCONFIRMED_MSG ) ? MCPS_UNCONFIRMED : MCPS_CONFIRMED;
    mcpsReq.Req.Unconfirmed.Datarate = dr;
    if( LoRaMacQueryTxPossible( appData->BufferSize, &txInfo ) != LORAMAC_STATUS_OK )
    {
        // Send empty frame in order to flush MAC commands
        mcpsReq.Type = MCPS_UNCONFIRMED;
        mcpsReq.Req.Unconfirmed.fBuffer = NULL;
        mcpsReq.Req.Unconfirmed.fBufferSize = 0;
    }
    else
    {
        mcpsReq.Req.Unconfirmed.fPort = appData->Port;
        mcpsReq.Req.Unconfirmed.fBufferSize = appData->BufferSize;
        mcpsReq.Req.Unconfirmed.fBuffer = appData->Buffer;
    }
    TxParams.AppData = *appData;
    TxParams.Datarate = dr;
    MlmeReq_t mlmeReq;
    mlmeReq.Type = MLME_DEVICE_TIME;
    LoRaMacMlmeRequest(&mlmeReq);

    status = LoRaMacMcpsRequest( &mcpsReq );
    DutyCycleWaitTime = mcpsReq.ReqReturn.DutyCycleWaitTime;

    if( status == LORAMAC_STATUS_OK )
    {
        IsUplinkTxPending = false;
        return LORAMAC_HANDLER_SUCCESS;
    }
    else
    {
        return LORAMAC_HANDLER_ERROR;
    }

}


#endif

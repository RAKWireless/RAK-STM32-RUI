#ifdef SUPPORT_LORA

#include "RAKLorawan.h"

RAKLorawan::RAKLorawan() {
}

bool RAKLorawan::join() {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_join(1, -1, -1, -1) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::join(uint8_t join_start, uint8_t auto_join, uint8_t auto_join_period, uint8_t auto_join_cnt) {
    if ( join_start != 0 && join_start != 1)
    {
        return false;
    }

    if ( auto_join != 0 && auto_join != 1)
    {
        return false;
    }

    if ( auto_join_period < 7 || auto_join_period > 255)
    {
        return false;
    }

    if ( auto_join_cnt < 0 || auto_join_cnt > 255)
    {
        return false;
    }
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_join(join_start, auto_join, auto_join_period, auto_join_cnt) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::send(uint8_t length, uint8_t *payload, uint8_t fport, bool confirm, uint8_t retry) {
    SERVICE_LORA_SEND_INFO info;

    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    info.port = fport;

    info.retry_valid = true;
    info.retry = retry;

    info.confirm_valid = true;
    if (confirm) {
        info.confirm = SERVICE_LORA_ACK;
    } else {
        info.confirm = SERVICE_LORA_NO_ACK;
    }

    if (service_lora_send(payload, length, info, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::send(uint8_t length, uint8_t *payload, uint8_t fport, bool confirm) {
    SERVICE_LORA_SEND_INFO info;

    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    info.port = fport;

    info.retry_valid = false;

    info.confirm_valid = true;
    if (confirm) {
        info.confirm = SERVICE_LORA_ACK;
    } else {
        info.confirm = SERVICE_LORA_NO_ACK;
    }

    if (service_lora_send(payload, length, info, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::send(uint8_t length, uint8_t *payload, uint8_t fport) {
    SERVICE_LORA_SEND_INFO info;

    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    info.port = fport;

    info.retry_valid = false;
    info.confirm_valid = false;

    if (service_lora_send(payload, length, info, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

// Obsoleted
//int32_t RAKLorawan::recv(uint8_t length, uint8_t *payload, uint8_t *fport) {
//    return service_lora_get_last_recv(fport, payload, length);
//}

uint8_t RAKLorawan::rety::get() {
    return service_lora_get_retry();
}

bool RAKLorawan::rety::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_retry(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::lpsend(uint8_t port, bool ack, uint8_t *payload, int length) {
    if (service_lora_lptp_send(port, ack, payload, length) != UDRV_RETURN_OK) {
       return false;
    } else {
       return true;
    }
}

bool RAKLorawan::usend(uint8_t port, bool confirm, uint8_t retry, uint8_t *payload, uint8_t length) {
}

bool RAKLorawan::registerRecvCallback(service_lora_recv_cb callback) {
    if (service_lora_register_recv_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::registerJoinCallback(service_lora_join_cb callback) {
    if (service_lora_register_join_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::registerSendCallback(service_lora_send_cb callback) {
    if (service_lora_register_send_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::registerLinkCheckCallback(service_lora_linkcheck_cb callback) {
    if (service_lora_register_linkcheck_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//appeui
bool RAKLorawan::appeui::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_app_eui(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::appeui::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_app_eui(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//appkey
bool RAKLorawan::appkey::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_app_key(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::appkey::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_app_key(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//appskey
bool RAKLorawan::appskey::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_app_skey(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::appskey::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_app_skey(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//daddr
bool RAKLorawan::daddr::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_dev_addr(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::daddr::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_dev_addr(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//deui
bool RAKLorawan::deui::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_dev_eui(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::deui::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_dev_eui(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//netid
bool RAKLorawan::netid::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_net_id(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//nwskey
bool RAKLorawan::nwkskey::get(uint8_t *buf, uint32_t len) {
    if (service_lora_get_nwk_skey(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::nwkskey::set(uint8_t *buf, uint32_t len) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
        return false;
    if (service_lora_set_nwk_skey(buf, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//cfm
bool RAKLorawan::cfm::get() {
    switch (service_lora_get_cfm()) {
        case SERVICE_LORA_NO_ACK:
            return (bool)0;
        case SERVICE_LORA_ACK:
        default:
            return (bool)1;
    }
}

bool RAKLorawan::cfm::set(bool value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_cfm((SERVICE_LORA_CONFIRM_MODE)value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//cfs
bool RAKLorawan::cfs::get() {
    return service_lora_get_cfs();
}

//njm
bool RAKLorawan::njm::get() {
    switch (service_lora_get_njm()) {
        case SERVICE_LORA_ABP:
            return (bool)0;
        case SERVICE_LORA_OTAA:
        default:
            return (bool)1;
    }
}

bool RAKLorawan::njm::set(bool value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_njm((SERVICE_LORA_JOIN_MODE)value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//njs
bool RAKLorawan::njs::get() {
    return service_lora_get_njs();
}

//adr
bool RAKLorawan::adr::get() {
    return service_lora_get_adr();
}

bool RAKLorawan::adr::set(bool value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_adr(value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//deviceClass
uint8_t RAKLorawan::deviceClass::get() {
    return service_lora_get_class();
}

bool RAKLorawan::deviceClass::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (value < SERVICE_LORA_CLASS_A || value > SERVICE_LORA_CLASS_C) {
        return false;
    }

    if (service_lora_set_class((SERVICE_LORA_CLASS)value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//dcs
bool RAKLorawan::dcs::get() {
    return service_lora_get_dcs();
}

bool RAKLorawan::dcs::set(uint8_t dutyCycle) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_dcs(dutyCycle, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//dr
uint8_t RAKLorawan::dr::get() {
    return (uint8_t)service_lora_get_dr();
}

bool RAKLorawan::dr::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_dr((SERVICE_LORA_DATA_RATE)value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//jn1dl
int RAKLorawan::jn1dl::get() {
    return (int)(service_lora_get_jn1dl());
}

bool RAKLorawan::jn1dl::set(int value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (value <= 0 || value > 15000) {
        return false;
    }

    if (value >= service_lora_get_jn2dl()) {
        return false;
    }

    if (service_lora_set_jn1dl((uint32_t)(value), true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//jn2dl
int RAKLorawan::jn2dl::get() {
    return (int)(service_lora_get_jn2dl());
}

bool RAKLorawan::jn2dl::set(int value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (value <= 0 || value > 15000) {
        return false;
    }

    if (value <= service_lora_get_jn1dl()) {
        return false;
    }

    if (service_lora_set_jn2dl((uint32_t)(value), true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//pnm
bool RAKLorawan::pnm::get() {
    return service_lora_get_pub_nwk_mode();
}

bool RAKLorawan::pnm::set(bool value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_pub_nwk_mode(value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//rx1dl
int RAKLorawan::rx1dl::get() {
    return (int)(service_lora_get_rx1dl());
}

bool RAKLorawan::rx1dl::set(int value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (value <= 0 || value > 15000) {
        return false;
    }

    if (value >= service_lora_get_rx2dl()) {
        return false;
    }

    if (service_lora_set_rx1dl((uint32_t)(value), true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//rx2dl
int RAKLorawan::rx2dl::get() {
    return (int)(service_lora_get_rx2dl());
}

bool RAKLorawan::rx2dl::set(int value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (value <= 0 || value > 15000) {
        return false;
    }

    if (value <= service_lora_get_rx1dl()) {
        return false;
    }

    if (service_lora_set_rx2dl((uint32_t)(value), true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//rx2dr
uint8_t RAKLorawan::rx2dr::get() {
    return (uint8_t)service_lora_get_rx2dr();
}

bool RAKLorawan::rx2dr::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_rx2dr((SERVICE_LORA_DATA_RATE)value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//rx2fq
long RAKLorawan::rx2fq::get() {
    return (long)service_lora_get_rx2freq();
}

bool RAKLorawan::rx2fq::set(int value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_rx2freq((uint32_t)(value), true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//txp
uint8_t RAKLorawan::txp::get() {
    return (int)service_lora_get_txpower();
}

bool RAKLorawan::txp::set(uint8_t value){
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_txpower((uint32_t)value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//pgslot
uint8_t RAKLorawan::pgslot::get() {
    return (uint8_t)service_lora_get_ping_slot_periodicity();
}

bool RAKLorawan::pgslot::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_ping_slot_periodicity(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//bfreq
float RAKLorawan::bfreq::get() {
    return (float)service_lora_get_beacon_freq();
}

//btime
long RAKLorawan::btime::get() {
    return (long)service_lora_get_beacon_time();
}

//bgw
beacon_bgw_t RAKLorawan::bgw::get() {
    return service_lora_get_beacon_gwspecific();
}

//RSSI
int RAKLorawan::rssi::get() {
    return (int)service_lora_get_rssi();
}

//SNR
int RAKLorawan::snr::get() {
    return (int)service_lora_get_snr();
}

//ltime
String RAKLorawan::ltime::get() {
    char value[30] = {0};

    if (service_lora_get_local_time(value) == UDRV_RETURN_OK) {
        return value;
    } else {
        return "get local time fail";
    }
}

//ver
String RAKLorawan::ver::get() {
    char *value;
    service_lora_get_lorawan_version(&value);
    return value;
}

//msak
bool RAKLorawan::mask::get(uint16_t *buff) {
    if (service_lora_get_mask(buff) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::mask::set(uint16_t *value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if(service_lora_set_mask(value, true) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//band
int32_t RAKLorawan::band::get() {
    switch (service_lora_get_band())
    {
        case SERVICE_LORA_EU433:
            return 0;
        case SERVICE_LORA_CN470:
            return 1;
#ifndef LEGACY
        case SERVICE_LORA_RU864:
            return 2;
#endif
        case SERVICE_LORA_IN865:
            return 3;
        case SERVICE_LORA_EU868:
            return 4;
        case SERVICE_LORA_US915:
            return 5;
        case SERVICE_LORA_AU915:
            return 6;
        case SERVICE_LORA_KR920:
            return 7;
        case SERVICE_LORA_AS923:
            return 8;
#ifdef LEGACY
        case SERVICE_LORA_US915_HYBRID:
#endif
        case SERVICE_LORA_AS923_2:
            return 9;
        case SERVICE_LORA_AS923_3:
            return 10;
        case SERVICE_LORA_AS923_4:
            return 11;
        case SERVICE_LORA_LA915:
            return 12;
        default:
            return -1;
    }
}

bool RAKLorawan::band::set(uint8_t value) {
    SERVICE_LORA_BAND band;

    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    switch (value)
    {
        case 0:
            band = SERVICE_LORA_EU433;
            break;
        case 1:
            band = SERVICE_LORA_CN470;
            break;
        case 2:
#ifndef LEGACY
            band = SERVICE_LORA_RU864;
            break;
#else
            return false;
#endif
        case 3:
            band = SERVICE_LORA_IN865;
            break;
        case 4:
            band = SERVICE_LORA_EU868;
            break;
        case 5:
            band = SERVICE_LORA_US915;
            break;
        case 6:
            band = SERVICE_LORA_AU915;
            break;
        case 7:
            band = SERVICE_LORA_KR920;
            break;
        case 8:
            band = SERVICE_LORA_AS923;
            break;
        case 9 : 
            band = SERVICE_LORA_AS923_2;
            break;
        case 10:
            band = SERVICE_LORA_AS923_3;
            break;
         case 11:
            band = SERVICE_LORA_AS923_4;
            break;
        case 12:
            band = SERVICE_LORA_LA915;
            break;
        default:
            return false;
    }

    if (service_lora_set_band(band) == UDRV_RETURN_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//linkcheck
uint32_t RAKLorawan::linkcheck::get() {
    return service_lora_get_linkcheck();
}

bool RAKLorawan::linkcheck::set(uint8_t value) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    if (service_lora_set_linkcheck((uint32_t)value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//nwm
int RAKLorawan::nwm::get() {
    return (int)service_lora_get_nwm();
}

bool RAKLorawan::nwm::set() {
    if (SERVICE_LORAWAN != service_lora_get_nwm()) {
        if (service_lora_set_nwm(SERVICE_LORAWAN) == UDRV_RETURN_OK) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

//Multicast
bool RAKLorawan::addmulc(RAK_LORA_McSession session) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }

    //create McSession_t instance
    McSession_t McSession;
    McSession.Devclass = session.McDevclass;
    McSession.Address = session.McAddress;
    memcpy(McSession.McAppSKey, session.McAppSKey, 16);
    memcpy(McSession.McNwkSKey, session.McNwkSKey, 16);
    McSession.Frequency = session.McFrequency;
    McSession.Datarate = session.McDatarate;
    McSession.Periodicity = session.McPeriodicity;
    McSession.GroupID = session.McGroupID;

    if (service_lora_addmulc(McSession) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }

}

bool RAKLorawan::rmvmulc(uint32_t devAddr) {
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return false;
    }
    if (service_lora_rmvmulc(devAddr) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::lstmulc(RAK_LORA_McSession *iterator) {
    if (service_lora_lstmulc((McSession_t *)iterator) == -UDRV_CONTINUE) {
        return true;
    } else {
        return false;
    }
}

bool RAKLorawan::arssi(RAK_LORA_chan_rssi *iterator) {
    if (service_lora_get_arssi((chan_rssi *)iterator) == -UDRV_CONTINUE) {
        return true;
    } else {
        return false;
    }
}

#endif

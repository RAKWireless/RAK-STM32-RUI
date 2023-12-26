#ifdef SUPPORT_LORA_P2P

#include "RAKLoRa.h"

RAKLoraP2P::RAKLoraP2P()
{

}
//pfreq
uint32_t RAKLoraP2P::pfreq::get() {
    return service_lora_p2p_get_freq();
}

bool RAKLoraP2P::pfreq::set(uint32_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_freq(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//psf
uint8_t RAKLoraP2P::psf::get() {
    return service_lora_p2p_get_sf();
}

bool RAKLoraP2P::psf::set(uint8_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_sf(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

//pbw
uint32_t RAKLoraP2P::pbw::get() {
    return service_lora_p2p_get_bandwidth();
}

bool RAKLoraP2P::pbw::set(uint32_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_bandwidth(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//pcr
uint8_t RAKLoraP2P::pcr::get() {
    return service_lora_p2p_get_codingrate();
}

bool RAKLoraP2P::pcr::set(uint8_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_codingrate(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//ppl
uint16_t RAKLoraP2P::ppl::get() {
    return service_lora_p2p_get_preamlen();
}

bool RAKLoraP2P::ppl::set(uint16_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_preamlen(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//ptp
uint8_t RAKLoraP2P::ptp::get() {
    return service_lora_p2p_get_powerdbm();
}
//precv
bool RAKLoraP2P::precv(uint32_t timeout) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_recv(timeout) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::ptp::set(uint8_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_powerdbm(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//psend
bool RAKLoraP2P::psend(uint8_t length, uint8_t *payload) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }
    bool cad_enable = service_lora_p2p_get_CAD();
    if (service_lora_p2p_send(payload, length, cad_enable) == UDRV_RETURN_OK) {
        return true;
    }

    return false;
}

bool RAKLoraP2P::psend(uint8_t length, uint8_t *payload, bool cad_enable ) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_send(payload, length, cad_enable) == UDRV_RETURN_OK) {
        return true;
    }

    return false;
}
//encry
bool RAKLoraP2P::encry::get() {
    return service_lora_p2p_get_crypto_enable();
}

bool RAKLoraP2P::encry::set(bool value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_crypto_enable(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//enckey
bool RAKLoraP2P::enckey::get(uint8_t *buff, uint32_t len) {
    if (service_lora_p2p_get_crypto_key(buff, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::enckey::set(uint8_t *buff, uint32_t len) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_crypto_key(buff, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//CRYPIV
bool RAKLoraP2P::enciv::get(uint8_t *buff, uint32_t len) {
    if (service_lora_p2p_get_crypto_IV(buff, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::enciv::set(uint8_t *buff, uint32_t len) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_crypto_IV(buff, len) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//pbr
uint32_t RAKLoraP2P::pbr::get() {
    return service_lora_p2p_get_bitrate();
}

bool RAKLoraP2P::pbr::set(uint32_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_bitrate(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}
//pfdev
uint32_t RAKLoraP2P::pfdev::get() {
    return service_lora_p2p_get_fdev();
}

bool RAKLoraP2P::pfdev::set(uint32_t value) {
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_fdev(value) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::iqInver::get()
{
    return service_lora_p2p_get_iqinverted();
}
bool RAKLoraP2P::iqInver::set(bool iqInver)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_iqinverted(iqInver) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint32_t RAKLoraP2P::syncword::get()
{
    return service_lora_p2p_get_syncword();
}
bool RAKLoraP2P::syncword::set(uint32_t syncword)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }
    if( service_lora_p2p_set_syncword(syncword & 0xffff) == UDRV_RETURN_OK)
    {
        return true;
    }
    return false;
}

uint32_t RAKLoraP2P::rfFrequency::get()
{
    return service_lora_p2p_get_freq();
}
bool RAKLoraP2P::rfFrequency::set(uint32_t frequency)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_freq(frequency) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint8_t RAKLoraP2P::txOutputPower::get()
{
    return service_lora_p2p_get_powerdbm();
}
bool RAKLoraP2P::txOutputPower::set(uint8_t power_level)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_powerdbm(power_level) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint32_t RAKLoraP2P::bandwidth::get()
{
    return service_lora_p2p_get_bandwidth();
}
bool RAKLoraP2P::bandwidth::set(uint32_t bandwidth)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_bandwidth(bandwidth) != UDRV_RETURN_OK) 
        return false;
    return true;
}
uint8_t RAKLoraP2P::speradingFactor::get()
{
    return service_lora_p2p_get_sf();
}
bool RAKLoraP2P::speradingFactor::set(uint8_t sf)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_sf(sf) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint8_t RAKLoraP2P::codingrate::get()
{
    return service_lora_p2p_get_codingrate();
}
bool RAKLoraP2P::codingrate::set(uint8_t cr)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_codingrate(cr) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint16_t RAKLoraP2P::preambleLength::get()
{
    return service_lora_p2p_get_preamlen();
}
bool RAKLoraP2P::preambleLength::set(uint16_t length)
{
    if (SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }

    if (service_lora_p2p_set_preamlen(length) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

uint32_t RAKLoraP2P::symbolTimeout::get()
{
    return service_lora_p2p_get_symbol_timeout();
}

bool RAKLoraP2P::symbolTimeout::set(uint32_t time)
{
    if(SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }
    if( service_lora_p2p_set_symbol_timeout(time) == UDRV_RETURN_OK)
    {
        return true;
    }
    return false;
}

bool RAKLoraP2P::fixLengthPayload::get()
{
    return service_lora_p2p_get_fix_length_payload();
}

bool RAKLoraP2P::fixLengthPayload::set(bool enable)
{
    if(SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }
    if( service_lora_p2p_set_fix_length_payload(enable) == UDRV_RETURN_OK)
    {
        return true;
    }
    return false;
}

bool RAKLoraP2P::cad::get()
{
    return service_lora_p2p_get_CAD();
}

bool RAKLoraP2P::cad::set(bool enable)
{
    if(SERVICE_LORAWAN == service_lora_p2p_get_nwm())
    {
        return false;
    }
    if( service_lora_p2p_set_CAD(enable) == UDRV_RETURN_OK)
    {
        return true;
    }
    return false;
}

//nwm
int RAKLoraP2P::nwm::get() {
    return (int)service_lora_p2p_get_nwm();
}

bool RAKLoraP2P::nwm::set() {
    if (SERVICE_LORA_P2P != service_lora_p2p_get_nwm()) {
        if (service_lora_p2p_set_nwm(SERVICE_LORA_P2P) == UDRV_RETURN_OK) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}


bool RAKLoraP2P::registerPRecvCallback(service_lora_p2p_recv_cb_type callback) {
    if (service_lora_p2p_register_recv_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::registerPSendCallback(service_lora_p2p_send_cb_type callback) {
    if (service_lora_p2p_register_send_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}

bool RAKLoraP2P::registerPSendCADCallback(service_lora_p2p_send_CAD_cb_type callback) {
    if (service_lora_p2p_register_send_CAD_cb(callback) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
}


#endif

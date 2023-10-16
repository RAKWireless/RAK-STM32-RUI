#ifdef SUPPORT_LORA_P2P

#include "RAKLoRa.h"

RAKLoraP2P::RAKLoraP2P()
{

}

bool RAKLoraP2P::iqInver::get()
{
    return service_lora_p2p_get_iqinverted();
}
bool RAKLoraP2P::iqInver::set(bool iqInver)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if (SERVICE_LORAWAN == service_lora_get_nwm())
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
    if(SERVICE_LORAWAN == service_lora_get_nwm())
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
    if(SERVICE_LORAWAN == service_lora_get_nwm())
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
    if(SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return false;
    }
    if( service_lora_p2p_set_CAD(enable) == UDRV_RETURN_OK)
    {
        return true;
    }
    return false;
}



#endif

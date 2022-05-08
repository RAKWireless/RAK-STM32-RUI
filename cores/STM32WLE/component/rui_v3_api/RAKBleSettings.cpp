#include "RAKBleSettings.h"

RAKBleSettings::RAKBleSettings() {}

void RAKBleSettings::blemode(RAK_BLE_SERVICE_MODE ble_mode){
    udrv_ble_switch_service_mode((drv_ble_service_mode)ble_mode);
}

bool RAKBleSettings::txPower::set(int8_t txpwr) {
    udrv_ble_set_txpower((drv_ble_tx_power_t)txpwr);
    return true;
}

int8_t RAKBleSettings::txPower::get() {
    return udrv_ble_get_txpower();
}

bool RAKBleSettings::advertiseInterval::set(int32_t adv_interval) {
    if(udrv_ble_set_adv_interval(adv_interval) == 0)
        return true;
    else return false;
}

int32_t RAKBleSettings::advertiseInterval::get() {
    return udrv_ble_get_adv_interval();
}

bool RAKBleSettings::broadcastName::set(char *ble_name, uint8_t device_name_length) {
    
    if(udrv_ble_set_device_name(ble_name, device_name_length) == 0)
        return true;
    else return false;
}

char* RAKBleSettings::broadcastName::get() {
    return udrv_ble_get_device_name();
}

bool RAKBleAdvertise::start(uint8_t adv_time) {

    if(udrv_ble_advertising_start(adv_time) == 0)
        return true;
    else return false;
}

bool RAKBleAdvertise::stop() {

    if(udrv_ble_advertising_stop() == 0)
        return true;
    else return false;
}

bool RAKBleAdvertise::status() {
    return (bool)udrv_ble_advertising_status();
}

char* RAKBleMac::get(void) {
    udrv_ble_get_macaddress(devmac);
    devmac[13] = '\0';
    return (char *)devmac;

}

char* RAKBleMac::get(uint8_t pos) {
    udrv_ble_get_macaddress(devmac);
    memcpy(twomac, devmac+2*pos, 2);
    twomac[2] = '\0';
    return (char *)twomac;
}


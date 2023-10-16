#ifdef SUPPORT_BLE

#include "RAKBleUart.h"

RAKBleUart::RAKBleUart() {
}

void RAKBleUart::start(uint8_t adv_time) {
    udrv_ble_stop();
    udrv_ble_services_start();
    udrv_ble_advertising_start(adv_time);
}

void RAKBleUart::stop() {
    udrv_ble_stop();
}


bool RAKBleUart::available() {
    return (bool)!!udrv_ble_nus_available();
}

char RAKBleUart::read() {
    char read_data;
    udrv_ble_nus_read((uint8_t *)&read_data, 1);

    return read_data;
}

void RAKBleUart::write(uint8_t *data, uint16_t size) {
    udrv_ble_nus_write(data, size);
}

void RAKBleUart::setPIN(uint8_t *key, uint16_t size)
{
    udrv_nus_set_keypairing(key, size);
}

void RAKBleUart::setPermission(RAK_CHARS_SECURITY_REQ permission)
{
    udrv_nus_set_permission((chars_security_req)permission);
}

#endif

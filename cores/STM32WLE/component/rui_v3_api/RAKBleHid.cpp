#include "RAKBleHid.h"

RAKBleHid::RAKBleHid() {}

void RAKBleHid::start()
{
    udrv_ble_hid_start();
}

void RAKBleHid::sendkey(uint8_t key_len, uint8_t * key_pattern)
{
    udrv_ble_hid_keys_send(key_len, key_pattern);
}

void RAKBleHid::setKeyboardCallback(void (*userFunc) (uint16_t, uint8_t))
{
    udrv_ble_keyboard_handler ((BLE_KEYBOARD_HANDLER)userFunc);
}

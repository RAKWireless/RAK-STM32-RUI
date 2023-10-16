#ifdef SUPPORT_BLE

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <inttypes.h>
#include "RAKBleCus.h"

using namespace std;

void RAKBleCustom::init()
{
  udrv_ble_cus_init();
}

void RAKBleCustom::start()
{
  udrv_ble_cus_start();
}

RAKBleService::RAKBleService(uint8_t service_uuid[])
{
  memcpy(RAKBleService::serviceUUID, service_uuid, 16);
}

void RAKBleService::begin()
{
  udrv_cus_services_init(serviceUUID);
}

RAKBleCharacteristic::RAKBleCharacteristic(uint16_t characteristicUUID)
{
  RAKBleCharacteristic::characteristicUUID = characteristicUUID;
}

void RAKBleCharacteristic::setProperties(RAK_CHARS_PROPERTIES prop)
{
  RAKBleCharacteristic::characteristicProperties = (chars_properties)prop;
}

void RAKBleCharacteristic::setPermission(RAK_CHARS_SECURITY_REQ read_write_perm)
{
  RAKBleCharacteristic::characteristicPermission = (chars_security_req)read_write_perm;
}

void RAKBleCharacteristic::setFixedLen(uint16_t fixed_len)
{
  RAKBleCharacteristic::len = fixed_len;
}

void RAKBleCharacteristic::begin()
{
  udrv_cus_add_char(characteristicUUID, characteristicProperties, characteristicPermission, len);
}

void RAKBleCharacteristic::notify(uint8_t *notify_data)
{
  udrv_cus_notify(notify_data, characteristicUUID);
}

void RAKBleCharacteristic::write(uint8_t *send_data)
{
  udrv_cus_write(send_data, characteristicUUID);
}

bool RAKBleCharacteristic::notifyEnabled()
{
  return udrv_cus_is_notifyEnabled(characteristicUUID);
}

void RAKBleCharacteristic::setCccdWriteCallback(void (*userFunc) (uint16_t, uint8_t *))
{
  udrv_ble_cus_register_notify_handler((BLE_CUS_NOTIFY_HANDLER)userFunc);
}

void RAKBleCharacteristic::setWriteCallback(void (*userFunc) (uint16_t, uint8_t *))
{
  udrv_ble_cus_register_send_handler((BLE_CUS_SEND_HANDLER)userFunc);
}

#endif

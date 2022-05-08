#include "RAKBleBeacon.h"

RAKBleBeacon::RAKBleBeacon() {}

bool RAKBleBeacon::iBeacon::iBeaconUuid::set(uint8_t beaconUuid[])
{
   if (udrv_ble_set_beacon_uuid(beaconUuid) == 0)
        return true;
    else
        return false;
}

bool RAKBleBeacon::iBeacon::iBeaconMajor::set(uint16_t major_value)
{
  if (udrv_ble_set_beacon_major(major_value) == 0)
        return true;
    else
        return false;
}

bool RAKBleBeacon::iBeacon::iBeaconMinor::set( uint16_t minor_value)
{
  if (udrv_ble_set_beacon_minor(minor_value) == 0)
        return true;
    else
        return false;
}
bool RAKBleBeacon::iBeacon::iBeaconPower::set(int8_t ibeacon_power)
{
  if (udrv_ble_set_beacon_power(ibeacon_power) == 0)
        return true;
    else
        return false;
}

bool cusPayload::set(uint8_t cus_adv_data[], uint8_t cus_adv_len)
{
     if (udrv_ble_set_beacon_custom_payload(cus_adv_data, cus_adv_len) == 0)
        return true;
    else
        return false;
}
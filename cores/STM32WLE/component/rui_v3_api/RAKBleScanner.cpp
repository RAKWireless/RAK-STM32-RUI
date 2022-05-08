#include "RAKBleScanner.h"

RAKBleScanner::RAKBleScanner() {}

void RAKBleScanner::start(uint16_t timeout_sec)
{
    udrv_ble_scan_start(timeout_sec);
}

bool RAKBleScanner::setInterval(uint16_t scan_interval, uint16_t scan_window)
{
    if (udrv_ble_set_scan_interval_window(scan_interval, scan_window) == 0)
        return true;
    else
        return false;
}

void RAKBleScanner::setScannerCallback(void (*userFunc) (int8_t, uint8_t *, uint8_t *, uint16_t))
{
    udrv_ble_scan_data_handler ((BLE_SCAN_DATA_HANDLER)userFunc);
}

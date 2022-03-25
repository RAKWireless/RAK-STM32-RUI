#ifndef __RAK_BLE_SCANNER_H__
#define __RAK_BLE_SCANNER_H__

#include "udrv_ble.h"

class RAKBleScanner
{
public:
  RAKBleScanner();
  /**@addtogroup	BLE_Scanner
   * @{
   */

  /**@par	Description
   *		Start scanning for BLE peripherals in range and parsing the advertising data that is being sent out by the peripherals
   * @par	Syntax
   * 		api.ble.scanner.start(timeout_sec)
   * @param	timeout_sec	field is scanning stop after x seconds. if timeout_sec= 0, always scanning on
   * @return	void
   */
  void start(uint16_t timeout_sec);

  /**@par	Description
   *		With BLE scanner , you specify a scan window (how long to scan) and interval (how long to wait between scans).
   * @par	Syntax
   * 		api.ble.scanner.setInterval(scan_interval, scan_window);
   * @param	scan_interval	Defines at what intervals scanner is started. (3ms ~ 40960ms)
   * @param	scan_winodw	Defines how long to scan at each interval (3ms ~ 40960ms)
   * @return	TRUE for success SET,FALSE for SET fail(Type: bool)
   */
  bool setInterval(uint16_t scan_interval, uint16_t scan_window);

  /**@par	Description
   *		This API is used to register a callback function, so that application can be notified on receiving scan data.
   * @par	Syntax
   *		api.ble.scanner.setScannerCallback(userFunc)
   * @param	userFunc	callback
   * @return	void
   */
  void setScannerCallback(void (*userFunc) (int8_t, uint8_t *, uint8_t *, uint16_t));

  /**@example	example_ble_scanner/src/app.cpp
   */

  /**@}*/
private:
};
#endif

#ifdef SUPPORT_BLE
/**@file	RAKBle.h
 *
 * @brief	The nested class wrapper file for ble
 * @author	RAKwireless
 * @version	0.0.0
 * @data	2021.5
 */
#ifndef __RAKBLE_H__
#define __RAKBLE_H__

#include "RAKBleUart.h"
#include "RAKBleSettings.h"
#include "RAKBleBeacon.h"
#include "RAKBleCus.h"
#include "RAKBleScanner.h"

#ifndef	RUI_SDK
#include "RAKBleHid.h"
#endif
class RAKBle {
  public:
    RAKBle(void);
    class RAKBleUart uart;

    class RAKBleSettings settings;
    class RAKBleAdvertise advertise;
    class RAKBleMac mac;
    class RAKBleBeacon beacon;
    class RAKBleCustom custom;
    class RAKBleScanner scanner;
    #ifndef	RUI_SDK
    class RAKBleHid hid;
    #endif
    /**@addtogroup  BLE_func
     * @{
     */
    /**@par Description
     *      Provide users to disconnect the existing connection.
     * @par Syntax
     *      api.ble.stop()
     * @return  void
     */
    void stop(void);
    void registerCallback(Event event,BLE_HANDLER callback);
    
};
#endif

#endif

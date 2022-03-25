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
    class RAKBleCustomer customer;
    class RAKBleScanner scanner;
    #ifndef	RUI_SDK
    class RAKBleHid hid;
    #endif
};

#endif


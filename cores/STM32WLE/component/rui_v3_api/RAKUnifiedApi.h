#ifndef __RAK_UNIFIED_API_H__
#define __RAK_UNIFIED_API_H__

#include "RAKSystem.h"
#ifdef SUPPORT_BLE
#include "RAKBle.h"
#endif
#ifdef SUPPORT_NFC
#include "RAKNfc.h"
#endif

#ifdef SUPPORT_LORA
#include "RAKLorawan.h"
#endif

#include "RAKOneWireSerial.h"

#include "RAKProtocol.h"

class RAKUnifiedApi {

  public:
    RAKUnifiedApi();
    class RAKSystem system;
#ifdef SUPPORT_BLE
    class RAKBle ble;
#endif
#ifdef SUPPORT_NFC
    class RAKNfc nfc;
#endif
#ifdef SUPPORT_LORA
    class RAKLorawan lorawan;
#endif

    RAKProtocol apiMode;
};
extern RAKUnifiedApi api;

#endif

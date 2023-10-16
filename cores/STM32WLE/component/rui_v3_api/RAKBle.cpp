#ifdef SUPPORT_BLE

#include "RAKBle.h"

RAKBle::RAKBle() {

}

void RAKBle::registerCallback(Event event,BLE_HANDLER callback) {
 
    udrv_ble_register_callback_handler (event,callback);
  
}
 
void RAKBle::stop() {
    udrv_ble_stop();
}

#endif

#ifdef SUPPORT_NFC
#include "RAKNfc.h"

RAKNfc::RAKNfc()
{
}

void RAKNfc::init(bool wakeup, bool atMode,rak_nfc_t4t_callback callback)
{
    udrv_nfc_init(wakeup, atMode,(udrv_nfc_t4t_callback)callback);
}

void RAKNfc::close()
{
    udrv_nfc_close();
}

void RAKNfc::send(RAK_NFC_RECORD_TYPE record_type, const uint8_t* payload1, uint32_t size1, const uint8_t* payload2, uint32_t size2)
{
    if(record_type == TXT) {
	if (size1 != 2 || size2 > 244)
	    return;
        udrv_nfc_send_txt(payload1, size1, payload2, size2);
    } else if (record_type == APP) {
	if (size1 + size2 > 246)
	    return;
        udrv_nfc_send_app(payload1, size1, payload2, size2);
    } else {
        return;
    }
}

void RAKNfc::send(RAK_NFC_RECORD_TYPE record_type, RAK_NFC_URI_ID uri_type, const uint8_t* payload, uint32_t size)
{
    if(record_type == URI) {
	if (size > 246 || size == 0)
	    return;
        udrv_nfc_send_uri((UDRV_NFC_URI_ID)uri_type, payload, size);
    } else {
        return;
    }
}
#endif

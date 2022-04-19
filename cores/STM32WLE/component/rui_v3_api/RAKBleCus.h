#ifndef __RAK_BLE_CUS_H__
#define __RAK_BLE_CUS_H__

#include <inttypes.h>
#include "WString.h"

#include "RAKBleUart.h"
#include "udrv_ble.h"

using namespace std;

/**@addtogroup	Customize_Service
 * @{
 */

/**@par	Description
 *
 */
class RAKBleService
{
  protected:
  private:
    uint8_t serviceUUID[16];
  public:
    /**@par	Description
     *		Provide developers to create a new BLE service and construct an instance of BLEService.
     * @par	Syntax
     * 		RAKBleService hrms = RAKBleService(service_uuid[])
     * @param	service_uuid[]	create a 128-bit base UUID, and the 3rd and 4th byte means Service 16bit UUID
     * @return	void
     */
    RAKBleService(uint8_t service_uuid[]);

    /**@par	Description
     * `	Before construct an instance BLECharacteristic, need to construct an instance BLEServices and execute .begin()
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleService hrms = RAKBleService(service_uuid[])
       @endverbatim

     * @par	Syntax
     *		hrms.begin()
     * @return	void
     */
    void begin();
};
 
/**@par	Description
 *
 */
class RAKBleCharacteristic
{
  protected:
  private:
    uint16_t characteristicUUID;
    uint32_t characteristicProperties;
    uint8_t characteristicPermission;
    uint16_t len;
  public:
    /**@par	Description
     *		Create a new BLE Characteristic associated with this service.
     * @par	Syntax
     *		RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
     * @param	characteristicUUID	The base is the same as the base uuid used when construct an instance BLEService, only provided the 3rd and 4th byte means characteristic (16bit UUID)
     */
    RAKBleCharacteristic(uint16_t characteristicUUID);

    /**@par	Description
     *		Set the characteristic properties
     *
     * @note	Users should create your own instance to use this api\n
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.setProperties(prop)
     * @param	prop	currently supports (CHR_PROPS_NOTIFY/CHR_PROPS_READ)
     * @return	void
     */
    void setProperties(RAK_CHARS_PROPERTIES prop);

    /**@par	Description
     *		sets the security for the characteristic
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.setPermission(read_write_perm)
     * @param	read_write_perm		RAK_SET_OPEN
     * @return	void
     */
    void setPermission(RAK_CHARS_SECURITY_REQ read_write_perm);

    /**@par	Description
     *		indicates how many bytes this characteristic has
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.setFixedLen(fixed_len)
     * @param	fixed_len	the length of the incoming data for notify or write
     * @return	void
     */
    void setFixedLen(uint16_t fixed_len);

    /**@par	Description
     *		After adding the characteristic, must call .begin() to complete the configuration action
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.begin()		
     * @return	void
     */
    void begin();

    /**@par	Description
     *		Provide information to send notifications to the connector
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.notify(notify_data)
     * @param	notify_data	an array to send as a series of bytes
     * @return	void
     */
    void notify(uint8_t *notify_data);

    /**@par	Description
     *		Data is written by the application to provide the peer connector for read data
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.write(send_data)
     * @param	send_data	an array to send as a series of bytes
     * @return	void
     */
    void write(uint8_t *send_data);

    /**@par	Description
     *		Confirm whether the current connection has enabled notification
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.notifyEnabled()
     * @return	bool
     * @retval	TRUE  : The mobile apps notification is enabled
     * @retval	FALSE : The mobile apps notification is not enabled
     */
    bool notifyEnabled(void);

    /**@par	Description
     *		This API is used to register a callback function, so that application can be notified on BLE notify data to peer connector
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.setCccWriteCallback(userFunc)	
     * @param	userFunc	callback function
     * @return	void
     */
    void setCccdWriteCallback(void (*userFunc) (uint16_t, uint8_t *));

    /**@par	Description
     *		This API is used to register a callback function so that the application can trigger a notification event when the peer connector reads data .(data written by the application and ready to be read)
     *
     * @note	Users should create your own instance to use this api
     * @verbatim
       RAKBleCharacteristic bslc = RAKBleCharacteristic(characteristicUUID)
       @endverbatim

     * @par	Syntax
     *		bslc.setWriteCallback(userFunc)
     * @param	userFunc	callback function
     * @return	void
     */
    void setWriteCallback(void (*userFunc) (uint16_t, uint8_t *));
};

/**@par	Description
 *
 */
class RAKBleCustomer {
  public:
    /**@par	Description
     *		Initialize the basic work of BLE custom services
     * @par	Syntax
     *		api.ble.customer.init()
     * @return	void
     */
    void init();

    /**@par	Description
     *		After completing all services and characteristic settings, start custom services.
     * @par	Syntax
     *		api.ble.customer.start()
     * @return	void	
     */
    void start();
  private:
};

/**@example	BLE_Customer_Service/src/app.cpp
 *
 */

/**@}*/

#endif





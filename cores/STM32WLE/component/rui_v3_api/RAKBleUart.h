/**@file       RAKBleUart.h
 *
 * @par	Description
 *		       
 * @author      RAKwireless
 * @version     0.0.0
 * @date        2021.5
 */
#ifndef __RAK_BLE_UART_H__
#define __RAK_BLE_UART_H__

#ifdef SUPPORT_BLE

#include "udrv_ble.h"

/**@addtogroup	RUI_Ble_Data_Type
 * @{
 */

typedef enum
{
    RAK_SET_OPEN = 1, 		///< Set sec_mode pointed to by ptr to require no protection, open link
    RAK_SET_ENC_NO_MITM = 2,	///< Set sec_mode pointed to by ptr to require encryption, but no MITM protection
    RAK_SET_ENC_WITH_MITM = 3	///< Set sec_mode pointed to by ptr to require encryption and MITM protection
} RAK_CHARS_SECURITY_REQ;

typedef enum
{
    RAK_CHR_PROPS_READ = 2,	///< Set the charactristic property to be Read
    RAK_CHR_PROPS_NOTIFY = 16,	///< Set the charactristic property to be Notify
} RAK_CHARS_PROPERTIES;

/**@}*/

class RAKBleUart {
  public:
    RAKBleUart();

    /**@addtogroup	BLE_Uart
     * @{
     */

    /**@par	Description
     *		To start the BLE UART Service
     * @par	Syntax
     * 		api.ble.uart.start()
     * @return	void
     */
    void start(void);

    /**@par	Description
     * 		To stop the BLE UART Service
     * @par	Syntax
     * 		api.ble.uart.stop()
     * @return	void
     * @par	Example
     * @verbatim
     void setup()
     {
       api.ble.uart.stop();
     }

     void loop()
     {
     }
     
       @endverbatim
     */
    void stop(void);

    /**@par	Description
     *		To check if there is any incoming Byte from BLE UART Service
     * @par	Syntax
     * 		api.ble.uart.available()
     * @return	bool
     * @retval	TRUE  : receive data from the ble device
     * @retval	FALSE : nothing to get
     */
    bool available(void);

    /**@par	Description
     * 		Reads incoming Byte from BLE UART Service
     * @par	Syntax
     * 		api.ble.uart.read()
     * @return  The first byte of incoming Ble data available(Type: char)
     */
    char read(void);

    /**@par	Description
     *		This API is used to write data and send it to the connected device via BLE	
     * @par	Syntax
     * 		api.ble.uart.write(data, size)
     * @param	data	an array to send as a series of bytes
     * @param	size	the date length that write to the ble device
     *
     * @return	void
     */
    void write(uint8_t *data, uint16_t size = 6);

    /**@par	Description
     *		Used to set of passkey with BLE pairing	
     * @par	Syntax
     * 		api.ble.uart.setPIN(key, size)
     * @param	key	the key to set the passkey(6 digits only)		
     * @param	size the length of key(can only be 6)
     *
     * @return	void
     */
    void setPIN(uint8_t *key, uint16_t size);
	
    /**@par	Description
     * 		To access BLE Uart is to require man-in-the-middle protection
     * @par	Syntax
     * 		api.ble.uart.setPermission(permission)
     * @param	permisssion	This will cause apps to perform pairing with static PIN we set\n
     * 				RAK_SET_ENC_WITH_MITM\n
     * 				RAK_SET_ENC_NO_MITM
     * @return	void
     */
    void setPermission(RAK_CHARS_SECURITY_REQ permission);

    /**@example BLE_Uart/src/app.cpp	
     */

    /** @} */

  private:
    char *localData;
    uint32_t localLength;
    uint32_t readCount = 0;
};

#endif

#endif

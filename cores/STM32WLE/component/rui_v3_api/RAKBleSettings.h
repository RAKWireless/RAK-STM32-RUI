#ifndef __RAK_BLE_SETTINGS_H__
#define __RAK_BLE_SETTINGS_H__

#ifdef SUPPORT_BLE

#include "udrv_ble.h"
#include "WString.h"

/**@addtogroup	RUI_Ble_Data_Type
 * @{
 */

typedef enum
{
    RAK_BLE_UART_MODE = 0,	///< Switch to uart advertisement mode
    RAK_BLE_BEACON_MODE = 1	///< Switch to beacon mode
} RAK_BLE_SERVICE_MODE;

/**@}*/

class RAKBleSettings {
  public:
    RAKBleSettings();
    /**@addtogroup	BLE_Setting
     * @{
     */

    /**@par	Description
     *
     */
    class txPower {
      public:
	/**@par	Description
	 *	Set the current transmit power level for the module's radio
	 * @par	Syntax
	 *	api.ble.settings.txPower.set(txpwr)
	 *
	 * @param	txpwr	The TX power level (dBm), which can be one of the following values (from lowest to higher transmit power):\n
0~8 , -4,-8,-12,-16,-20,-40
   * @return	bool
	 * @retval	TRUE for success
	 * @retval	FALSE for failure
	 */
        bool set(int8_t txpwr);

	/**@par	Description
	 *	Get the current transmit power level (in dBm)
	 * @par	Syntax
	 *	api.ble.settings.txPower.get()
	 * @return	the current transmit power 
	 */
        int8_t get();
    };

    /**@par	Description
     *
     */
    class advertiseInterval {
      public:
	/**@par	Description
	 *	Set advertisement interval is used to set the time interval between two consecutive advertisements of Bluetooth low energy peripherals.
	 * @par	Syntax
	 *	api.bel.setting.advertiseInterval.set(adv_interval)
	 *
	 * @param	adv_interval	20ms ~10240ms
   * @return	bool
	 * @retval	TRUE for success
	 * @retval	FALSE for failure
	 */
        bool set(int32_t adv_interval);

	/**@par	Description
	 *	Get the current advertisement interval.
	 * @par	Syntax
	 *	api.ble.settings.advertiseInterval.get()
	 * @return	Return the current advertisement interval(20ms ~10240ms)
	 */
        int32_t get();
    };
    
    /**@par	Description
     *
     */
    class broadcastName {
      public:

	/**@par	Description
	 *	Set the name for this device. Used in advertisements and as the Device Name available to a connected peer.
	 * @par	Syntax
	 *	api.ble.settings.broadcastName.set(ble_name, device_name_length)
	 *
	 * @param	ble_name	setting device name an array of data to send as bytes
	 * @param	device_name_length	the number of bytes to transmit
   * @return	bool
	 * @retval	TRUE for success
	 * @retval	FALSE for failure
	 */
        bool set(char *ble_name, uint8_t device_name_length);

	/**@par	Description
	 *	Get the current BLE Device Name
	 * @par	Syntax
	 *	api.ble.settings.broadcastName.get()
	 * @return	the current BLE Device Name
	 */
        char* get();
    };

    /**@}*/
    
    /**@par	Description
     *		Support current BLE UART Service mode switch to beacon mode
     * @ingroup	BLE_Setting
     * @par	Syntax
     * 		api.ble.settings.blemode(ble_mode)
     * @param	ble_mode	RAK_BLE_BEACON_MODE	
     * @return	void
     */
    void blemode(RAK_BLE_SERVICE_MODE ble_mode);

    //instance
    class txPower txPower;
    class advertiseInterval advertiseInterval;
    class broadcastName broadcastName;

  private:
    char *localData;
    uint32_t localLength;
    uint32_t readCount = 0;
};

/**@addtogroup BLE_Setting
 * @{
 */

/**@par	Description
 *
 */
class RAKBleAdvertise {
  public:
    /**@par	Description
     *		Used to start advertising when after configuring BLE settings
     * @par	Syntax
     * 		api.ble.advertise.start(adv_time)
     * @param	adv_time	advertising timeout in seconds. If x = 0, advertising never stops
     * @return	bool
     * @retval	TRUE for start advertising success
     * @retval	FALSE for for start advertising failure
     */
    bool start(uint8_t adv_time);

    /**@par	Description
     *		Used to stop advertising
     * @par	Syntax
     *		api.ble.advertise.stop()
     @return	bool
     @retval	TRUE for stop advertising success
     @retval	FALSE for for stop advertising failure
     * @par	Example
     * @verbatim
     void setup()
     {
       api.ble.advertise.stop();
     }

     void loop()
     {
     }  
     
       @endverbatim
     */
    bool stop();

    /**@par	Description
     *		
     * @par	Syntax
     * 		api.ble.advertise.status()
     *
     * @return	bool
     * @retval	TRUE  : the device is in advertising
     * @retval	FALSE : the device is stop advertis
     */
    bool status();
};
/**@}*/


class RAKBleMac {
  public:
    /**@par	Description
     *		Get the current Device MAC Address
     * @ingroup	BLE_MAC
     * @note	If MAC is 6 bytes and x is passed as 2, the return value will be position [2] in the array. 
If x is NOT passed, the function will default to returning a string, all uppercase
     * @par	Syntax
     * 		api.ble.mac.get()\n
     * 		api.ble.mac.get(pos)
     *
     * @param	pos	single byte, array location	
     * @return	the current BLE MAC Address
     */
    char* get(uint8_t pos);
    char* get(void);
    /**@par Description
     *      Set the current Device MAC Address
     * @ingroup BLE_MAC
     * @par Syntax
     *      api.ble.mac.set(mac)\n
     * @param   mac  the BLE mac address
     * @return  bool
     * @retval  TRUE for success
     * @retval  FALSE for failure
     */
    bool set(char *mac);
  private:
    uint8_t devmac[13];
    uint8_t twomac[3];
};

/**@example	BLE_Configuration/src/app.cpp
 */

#endif

#endif

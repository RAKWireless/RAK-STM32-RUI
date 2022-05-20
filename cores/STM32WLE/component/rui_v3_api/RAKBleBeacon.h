#ifndef __RAK_BLE_BEACON_H__
#define __RAK_BLE_BEACON_H__

#ifdef SUPPORT_BLE

#include "udrv_ble.h"

class cusPayload
{
  public:
    /**@par	Description
     *		Provide developer control all data for BLE Beacon advertising, allow function to support full 31 byte payload.
     * @ingroup	I_Beacon
     * @par	Syntax
     * 		api.ble.beacon.custom.payload.set(cus_adv_data[], cus_adv_len)
     * @param	cus_adv_data[]	set the advertising payload (MAX 31 bytes)
     * @param	cus_adv_len	the number of bytes to advertising data
     * @return	bool
     * @retval	TRUE for success
     * @retval	FALSE for failure
     */
    bool set(uint8_t cus_adv_data[], uint8_t cus_adv_len);
  
  private:
};

class cusAdv
{
  public:
    class cusPayload payload;
  
  private:
};

class RAKBleBeacon
{
public:

  class iBeacon
  {
  public:

    class iBeaconUuid
    {
    public:
      /**@par		Description
       *		Application developers should define a UUID specific to their
app and deployment use case. 
       * @ingroup	Beacon_UUID
       * @par		Syntax
       *		api.ble.beacon.ibeacon.uuid.set(beaconUuid)
       * @param		beaconUuid	define 16 bytes
       * @return	bool
	     * @retval	TRUE for success
	     * @retval	FALSE for failure
       */
      bool set(uint8_t beaconUuid[]);
    };

    class iBeaconMajor
    {
    public:
      /**@par		Description
       *		Further specifies a specific iBeacon and use case. For example,
this could define a sub-region within a larger region defined by
the UUID.
       * @ingroup	Beacon_Major
       * @par		Syntax
       *		api.ble.beacon.ibeacon.major.set(major_value)
       * @param		major_value	set major (define 2 bytes)
       * @return	bool
	     * @retval	TRUE for success
	     * @retval	FALSE for failure
       */
      bool set(uint16_t major_value);
    };

    class iBeaconMinor
    {
    public:
      /**@par		Description
       *		Allows further subdivision of region or use case, specified by the
application developer
       * @ingroup	Beacon_Minor
       * @par		Syntax
       *		api.ble.beacon.ibeacon.minor.set(minor_value)
       * @param		minor_value	set minor (define 2 bytes)
       * @return	bool
	     * @retval	TRUE for success
	     * @retval	FALSE for failure
       */
      bool set(uint16_t minor_value);
    };

    class iBeaconPower
    {
    public:
      /**@par		Description
       *		Provides information about the measured power value expected at 1 meter from the beacon.
       * @ingroup	Beacon_Power
       * @par		Syntax
       *		api.ble.beacon.ibeacon.power.set(ibeacon_power)
       * @param		ibeacon_power	display measured power value (RSSI)
       * @return	bool
	     * @retval	TRUE for success
	     * @retval	FALSE for failure
       */
      bool set(int8_t ibeacon_power);
    };


    class iBeaconUuid uuid;
    class iBeaconMajor major;
    class iBeaconMinor minor;
    class iBeaconPower power;

  };

  RAKBleBeacon();
  class cusAdv custom;
  class iBeacon ibeacon;

private:
};
/**@example	BLE_Beacon/src/app.cpp
 */

/**@example	BLE_Beacon_Custom_Payload/src/app.cpp
 */

#endif

#endif

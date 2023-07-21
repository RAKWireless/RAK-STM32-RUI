#ifndef __RAK_LORA_H__
#define __RAK_LORA_H__

#ifdef SUPPORT_LORA

#include <cstdint>
#include "WString.h"
#include <cstring>

#include "udrv_errno.h"
#include "service_lora.h"
#include "service_lora_test.h"
#include "service_lora_p2p.h"
#include "service_lora_multicast.h"
#include "service_battery.h"
#include "service_lora_arssi.h"

/**@addtogroup	RUI_Lorawan_Data_Type
 * @{
 */

class RAKLoraP2P
{
public:
  RAKLoraP2P();

  class iqInver
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the IQ inversion
	 *
	 * @par	Syntax
	 *	api.lora.iqInver.get();
   * @return	IQ inversion(Type: bool)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode iqInversion %s\r\n", api.lora.iqInver.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode iqInversion = %s\r\n", api.lora.iqInver.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

	 */
    bool get();
    /**@par	Description
	 *     	This api allows the user to set the IQ inversion
	 *
	 * @par	Syntax
	 *	api.lora.iqInver.set(value);
	 * @param	value	the P2P iqInversion(Type: bool)
   * @return	bool
	 * @retval	TRUE for setting P2P iqInversion success
	 * @retval	FALSE for setting P2P iqInversion failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode iqInversion %s\r\n", api.lora.iqInver.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode iqInversion = %s\r\n", api.lora.iqInver.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

	 */
    bool set(bool iqInver);
  };

  class syncword
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the syncword
	 *
	 * @par	Syntax
	 *	api.lora.syncword.get();
   * @return	syncword(Type: uint)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode syncword %s\r\n", api.lora.syncword.set(LORA_MAC_PUBLIC_SYNCWORD) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode syncword = %04x\r\n", api.lora.syncword.get());

           delay(1000);
       }

           @endverbatim

	 */
    uint32_t get();
    /**@par	Description
	 *     	This api allows the user to set the syncword
	 *
	 * @par	Syntax
	 *	api.lora.syncword.set(value);
	 * @param	value	the P2P syncword(Type: int 16bit)
   * @return	bool
	 * @retval	TRUE for setting P2P syncword success
	 * @retval	FALSE for setting P2P syncword failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode syncword %s\r\n", api.lora.syncword.set(LORA_MAC_PUBLIC_SYNCWORD) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode syncword = %04x\r\n", api.lora.syncword.get());

           delay(1000);
       }

           @endverbatim

	 */
    bool set(uint32_t syncword);
  };

  class rfFrequency
  {
  public:
    /**@par	Description
	 *     	This api allows to get the P2P frequency
	 *
	 * @par	Syntax
	 *	api.lora.rfFrequency.get()
	 *
	 * @return	The frequency for P2P mode	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");   
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.rfFrequency.set(868000000) ? "Success" : "Fail");   
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lora.rfFrequency.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();
    /**@par	Description
	 *     	This api allows to set the P2P frequency
	 *
	 * @par	Syntax
	 *	api.lora.rfFrequency.set(frequency)
	 *
	 * @param	The frequency for P2P mode	
   * @return	bool
	 * @retval	TRUE for setting frequency success
	 * @retval	FALSE for setting frequency failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");   
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.rfFrequency.set(868000000) ? "Success" : "Fail");   
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lora.rfFrequency.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint32_t frequency);
  };

  class txOutputPower
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P TX output Power(5-22)
	 *
	 * @par	Syntax
	 *	api.lora.txOutputPower.get()
	 *
	 * @return	The Tx power for P2P mode
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.txOutputPower.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lora.txOutputPower.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();
    /**@par	Description
	 *     	This api allows to set P2P TX output Power(5-22)
	 *
	 * @par	Syntax
	 *	api.lora.txOutputPower.set(value)
	 * @param	value	the P2P Tx output power
   * @return	bool
	 * @retval	TRUE for setting P2P Tx output power success
	 * @retval	FALSE for setting P2P Tx output power failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.txOutputPower.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lora.txOutputPower.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t power_level);
  };

  class bandwidth
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Bandwidth(125,250,500)
	 *
	 * @par	Syntax
	 *	api.lora.bandwidth.get()
	 *	
	 * @return	The P2P bandwidth	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.bandwidth.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lora.bandwidth.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();
    /**@par	Description
	 *     	This api allows to set P2P Bandwidth(125,250,500)
	 *
	 * @par	Syntax
	 *	api.lora.bandwidth.set(bandwidth)
	 *	
	 * @param	value	the P2P bandwidth
   * @return	bool
	 * @retval	TRUE for setting P2P bandwidth success
	 * @retval	FALSE for setting P2P bandwidth failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.bandwidth.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lora.bandwidth.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint32_t bandwidth);
  };

  class speradingFactor
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Spreading Factor (6,7, 8,9, 10, 11, 12)
	 *
	 * @par	Syntax
	 *	api.lora.speradingFactor.get()
	 *
	 * @return	The P2P spreading factor
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.speradingFactor.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lora.speradingFactor.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();
    /**@par	Description
	 *     	This api allows to set P2P Spreading Factor (6,7, 8,9, 10, 11, 12)
	 *
	 * @par	Syntax
	 *	api.lora.speradingFactor.set(sf)
	 *
	 * @param	value	the P2P spreading factor
   * @return	bool
	 * @retval	TRUE for setting P2P spreading factor success
	 * @retval	FALSE for setting P2P spreading factor failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.speradingFactor.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lora.speradingFactor.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t sf);
  };

  class codingrate
  {
  public:
    /**@par	Description
	 *     	This api allows to get coding rate for the P2P mode
	 *
	 * @par	Syntax
	 *	api.lora.codingrate.get()
	 *
	 * @return	The coding rate 	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode coding rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lorawan.pcr.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();
    /**@par	Description
	 *     	This api allows to set coding rate for the P2P mode
	 *
	 * @par	Syntax
	 *	api.lora.codingrate.set()
	 *
	 * @param	value	the coding rate for P2P mode	
   * @return	bool
	 * @retval	TRUE for setting code rate success
	 * @retval	FALSE for setting code rate failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode coding rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lorawan.pcr.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t cr);
  };

  class preambleLength
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Preamble Length (2-65535)
	 *
	 * @par	Syntax
	 *	api.lora.preambleLength.get()
	 *
	 * @return  The Preamble length 	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.preambleLength.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lora.preambleLength.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint16_t get();
    /**@par	Description
	 *     	This api allows to set P2P Preamble Length (2-65535)
	 *
	 * @par	Syntax
	 *	api.lora.preambleLength.set(length)
	 *
	 * @param	value	the P2P preamble length(2-65536)
   * @return	bool
	 * @retval	TRUE for setting P2P preamble length success
	 * @retval	FALSE for setting preamble length failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.preambleLength.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lora.preambleLength.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint16_t length);
  };

  class symbolTimeout
  {
  public:
    /**@par	Description
	 *     	This api allows to get symbol timeout (0 - SYMBTIMEOUT_MAX)
	 *
	 * @par	Syntax
	 *	api.lora.symbolTimeout.get()
	 *
	 * @returni	The symbol timeout	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode symbol timeout %s\r\n", api.lora.symbolTimeout.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode symbol timeout = %d\r\n", api.lora.symbolTimeout.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();
    /**@par	Description
	 *     	This api allows to get symbol timeout (0 - SYMBTIMEOUT_MAX)
	 *
	 * @par	Syntax
	 *	api.lora.symbolTimeout.set()
	 *
	 * @return	value	the P2P symbol timeout	
   * @return	bool
	 * @retval	TRUE for setting P2P preamble length success
	 * @retval	FALSE for setting preamble length failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode symbol timeout %s\r\n", api.lora.symbolTimeout.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode symbol timeout = %d\r\n", api.lora.symbolTimeout.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint32_t time);
  };

  class fixLengthPayload
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the fix Length payload switch
	 *
	 * @par	Syntax
	 *	api.lora.fixLengthPayload.get();
   * @return	fix length payload switch status(Type: bool)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode fix Length payload %s\r\n", api.lora.fixLengthPayload.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode fix Length payload switch = %s\r\n", api.lora.fixLengthPayload.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

	 */
    bool get();
    /**@par	Description
	 *     	This api allows the user to set the fix Length payload switch
	 *
	 * @par	Syntax
	 *	api.lora.fixLengthPayload.get();
	 * @param	value	the fix Length payload(Type: bool)
   * @return	bool
	 * @retval	TRUE for setting P2P fixLengthPayload success
	 * @retval	FALSE for setting P2P fixLengthPayload failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode fix Length payload %s\r\n", api.lora.fixLengthPayload.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode fix Length payload switch = %s\r\n", api.lora.fixLengthPayload.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

	 */
    bool set(bool enable);
  };
  class cad
  {
    public:
        /**@par Description
     *      This api allows the user to get the Channel Activity Detection status
     *
     * @par Syntax
     *  api.lora.cad.get();
   * @return    Channel Activity Detection status(Type: bool)
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode fix Length payload %s\r\n", api.lora.cad.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode fix Length payload switch = %s\r\n", api.lora.cad.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

     */
    bool get();
    /**@par Description
     *      This api allows the user to set the Channel Activity Detection status
     *
     * @par Syntax
     *  api.lora.cad.set();
     * @param   value   Channel Activity Detection status(bool)
   * @return    bool
     * @retval  TRUE for setting P2P Channel Activity Detection success
     * @retval  FALSE for setting P2P Channel Activity Detection failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode fix Length payload %s\r\n", api.lora.cad.set(true) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode fix Length payload switch = %s\r\n", api.lora.cad.get()?"true":"false");

           delay(1000);
       }

           @endverbatim

     */

    bool set(bool enable);
  };
  iqInver iqInver;
  syncword syncword;
  rfFrequency rfFrequency;
  txOutputPower txOutputPower;
  bandwidth bandwidth;
  speradingFactor speradingFactor;
  codingrate codingrate;
  preambleLength preambleLength;
  symbolTimeout symbolTimeout;
  fixLengthPayload fixLengthPayload;
  cad cad;

};

#endif

#endif //end RAKLoRa.h

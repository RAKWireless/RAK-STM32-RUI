#ifndef __RAK_LORA_H__
#define __RAK_LORA_H__

#ifdef SUPPORT_LORA_P2P
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

  /**@par   Description
     *      This api provides configuration frequency for the P2P mode
     * @ingroup     P2P
     */
  class pfreq
  {
  public:
    /**@par Description
     *      This api allows to get the P2P frequency  Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pfreq.get()
     *
     * @return  The frequency for P2P mode
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lora.pfreq.get());

           delay(1000);
       }

           @endverbatim
     */
    uint32_t get();

    /**@par Description
     *      This api allows to set the P2P frequency Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pfreq.set(value)
     *
     * @param   value the frequency for P2P mode
   * @return    bool
     * @retval  TRUE for setting frequency success
     * @retval  FALSE for setting frequency failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lora.pfreq.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint32_t value);
  };

  /**@par   Description
     *      This api provides a configuration Spreading Factor for the P2P mode Note:This API will be deleted in the future
     * @ingroup     P2P
     */
  class psf
  {
  public:
    /**@par Description
     *      This api allows to get P2P Spreading Factor (6,7, 8,9, 10, 11, 12)
     *
     * @par Syntax
     *  api.lora.psf.get()
     *
     * @return  The P2P spreading factor
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lora.psf.get());

           delay(1000);
       }

           @endverbatim
     */
    uint8_t get();

    /**@par Description
     *      This api allows to set P2P Spreading Factor (6,7, 8,9, 10, 11, 12) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.psf.set(value)
     *
     * @param   value   the P2P spreading factor
   * @return    bool
     * @retval  TRUE for setting P2P spreading factor success
     * @retval  FALSE for setting P2P spreading factor failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lora.psf.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint8_t value);
  };

  /**@par   Description
     *      This api provides configuration Bandwidth for the P2P mode
     * @ingroup     P2P
     */
  class pbw
  {
  public:
    /**@par Description
     *      This api allows to get P2P Bandwidth(125,250,500) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pbw.get()
     *  
     * @return  The P2P bandwidth   
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lora.pbw.get());

           delay(1000);
       }

           @endverbatim
     */
    uint32_t get();
    /**@par Description
     *      This api allow to set P2P Bandwidth(125,250,500) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pbw.set(value)
     *
     * @param   value   the P2P bandwidth
   * @return    bool
     * @retval  TRUE for setting P2P bandwidth success
     * @retval  FALSE for setting P2P bandwidth failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lora.pbw.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint32_t value);
  };
  /**@par   Description
     *      This api provides the configuration code rate for the P2P mode
     * @ingroup     P2P
     */
  class pcr
  {
  public:
    /**@par Description
     *      This api allows to get code rate for the P2P mode Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pcr.get()
     *
     * @return  The code rate   
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lora.pcr.get());

           delay(1000);
       }

           @endverbatim
     */
    uint8_t get();
    /**@par Description
     *      This api allows to set code rate for the P2P mode Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.pcr.set(value)
     *
     * @param   value   the code rate for P2P mode
   * @return    bool
     * @retval  TRUE for setting code rate success
     * @retval  FALSE for setting code rate failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lora.pcr.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint8_t value);
  };
  /**@par   Description
     *      This api provides configuration Preamble Length for the P2P mode Note:This API will be deleted in the future
     * @ingroup     P2P
     */
  class ppl
  {
  public:
    /**@par Description
     *      This api allows to get P2P Preamble Length (2-65535)
     *
     * @par Syntax
     *  api.lora.ppl.get()
     *
     * @returni The Preamble length
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lora.ppl.get());

           delay(1000);
       }

           @endverbatim
     */
    uint16_t get();
    /**@par Description
     *      This api allows to set P2P Preamble Length (2-65535) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.ppl.set(value)
     *
     * @param   value   the P2P preamble length(2-65536)
   * @return    bool
     * @retval  TRUE for setting P2P preamble length success
     * @retval  FALSE for setting preamble length failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lora.ppl.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint16_t value);
  };
  /**@par   Description
     *      This api provides configuration Power for the P2P mode
     * @ingroup     P2P
     */
  class ptp
  {
  public:
    /**@par Description
     *      This api allows to get P2P TX Power(5-22) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.ptp.get()
     *
     * @return  The Tx power for P2P mode
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lora.ptp.get());

           delay(1000);
       }

           @endverbatim
     */
    uint8_t get();
    /**@par Description
     *      This api allows to set P2P TX Power(5-22) Note:This API will be deleted in the future
     *
     * @par Syntax
     *  api.lora.ptp.set(value)
     * @param   value   the P2P Tx power
   * @return    bool
     * @retval  TRUE for setting P2P Tx power success
     * @retval  FALSE for setting P2P Tx power failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lora.ptp.get());

           delay(1000);
       }

           @endverbatim
     */
    bool set(uint8_t value);
  };

  /**@par   Description
     *      This api configures P2P mode encryption
     * @ingroup     P2P
     */
  class encry
  {
  public:
    /**@par Description
     *      This api allows to get the status of P2P mode encryption
     *
     * @par Syntax
     *  api.lora.encry.get()
   * @return    bool
     * @retval  TRUE  : P2P mode encryption is enable
     * @retval  FALSE : P2P mode encryption is disable
     * @par         Example
         * @verbatim
       long startTime;
       char * node_encrypt_key = "aaaabbbbccccdddd";
       uint8_t encrypt_buff[16];

       void setup()
       {
           Serial.begin(115200);
           startTime = millis();

           Serial.println("P2P Start");
           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
       
           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");

       api.lora.enckey.get(encrypt_buff, 16);
       Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");
         
           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);
         
           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
             Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }

           @endverbatim
     */
    bool get();
    /**@par Description
     *      This api allows to enable or disable P2P mode encryption
     *
     * @par Syntax
     *  api.lora.encry.set(value)
     *
     * @param   value   the status of P2P mode encryption
   * @return    bool
     * @retval  TRUE  : for Setting status of encryption success
     * @retval  FALSE : for setting status of encryption failure
     * @par         Example
         * @verbatim
       long startTime;
       char *  node_encrypt_key = "aaaabbbbccccdddd";
       uint8_t encrypt_buff[16];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
       
           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");

           api.lora.enckey.get(encrypt_buff, 16);
           Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
           Serial.println("");
         
           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);
         
           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }
       }
         @endverbatim
     */
    bool set(bool value);
  };


  /**@par   Description
     *      This api will encrypt the date being sent and received
     * @ingroup     P2P
     */
  class enckey
  {
  public:
    /**@par Description
     *      This api allows to get the key of P2P mode encryption
     *
     * @par Syntax
     *  api.lora.enckey.get(buff, len)
     *
         * @param       buff    the buffer to store encryption key
         * @param       len the length of encryption key(must be 16 bytes)
   * @return    bool
     * @retval  TRUE for getting encryption key success
     * @retval  FALSE for getting encryption key failure
     * @par         Example
         * @verbatim
       long startTime;
       char * node_encrypt_key = "aaaabbbbccccdddd";
       uint8_t encrypt_buff[16];

       void setup()
       {
           Serial.begin(115200);
           startTime = millis();

           Serial.println("P2P Start");
           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
       
           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");

       api.lora.enckey.get(encrypt_buff, 16);
       Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");
         
           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);
         
           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
     */
    bool get(uint8_t *buff, uint32_t len);
    /**@par Description
     *      This api allows to set the key of P2P mode encryption
     *
     * @par Syntax
     *  api.lora.enckey.set(buff, len)
     *
         * @param       buff    the buffer to set encryption key
         * @param       len the length of encryption key(must be 16 bytes)
   * @return    bool
     * @retval  TRUE for setting encryption key success
     * @retval  FALSE for setting encryption failure
     * @par         Example
         * @verbatim
       long startTime;
       char * node_encrypt_key = "aaaabbbbccccdddd";
       uint8_t encrypt_buff[16];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
       Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
       
           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");
       api.lora.enckey.get(encrypt_buff, 16);
       Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");
         
           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);
         
           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
     */
    bool set(uint8_t *buff, uint32_t len);
  };

  class enciv
  {
    public:
        /**@par Description
     *      This api allows to get the IV of P2P mode encryption
     *
     * @par Syntax
     *  api.lora.enciv.get(buff, len)
     *
         * @param       buff    the buffer to store encryption IV
         * @param       len the length of encryption IV(must be 16 bytes)
   * @return    bool
     * @retval  TRUE for getting encryption IV success
     * @retval  FALSE for getting encryption IV failure
     * @par         Example
         * @verbatim
       long startTime;
       char * node_encrypt_key = "aaaabbbbccccdddd";
       char * node_encrypt_IV = "ddddccccbbbbaaaa";
       uint8_t encrypt_buff[16];

       void setup()
       {
           Serial.begin(115200);
           startTime = millis();

           Serial.println("P2P Start");

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
                      Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption IV %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_IV, 16) ? "Success" : "Fail");

           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");
           api.lora.enckey.get(encrypt_buff, 16);
       Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");
            api.lora.enciv.get(encrypt_buff, 16);
       Serial.printf("P2P encryption IV = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");


           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);

           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {

             Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
     */

      bool get(uint8_t *buff, uint32_t len);
   /**@par Description
     *      This api allows to set the IV of P2P mode encryption
     *
     * @par Syntax
     *  api.lora.enciv.set(buff, len)
     *
         * @param       buff    the buffer to set encryption IV
         * @param       len the length of encryption IV(must be 16 bytes)
   * @return    bool
     * @retval  TRUE for setting encryption IV success
     * @retval  FALSE for setting encryption failure
     * @par         Example
         * @verbatim
       long startTime;
       char * node_encrypt_key = "aaaabbbbccccdddd";
       char * node_encrypt_IV = "ddddccccbbbbaaaa";
       uint8_t encrypt_buff[16];

       void setup()
       {
           Serial.begin(115200);
           startTime = millis();

           Serial.println("P2P Start");

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
                      Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption status %s\r\n", api.lora.encry.set(1) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_key, 16) ? "Success" : "Fail");
           Serial.printf("Set P2P mode encryption IV %s\r\n\r\n", api.lora.enckey.set((uint8_t *)node_encrypt_IV, 16) ? "Success" : "Fail");

           Serial.printf("P2P encryption status = %s\r\n", api.lora.encry.get() ? "Enbale" : "Disable");
           api.lora.enckey.get(encrypt_buff, 16);
       Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");
            api.lora.enciv.get(encrypt_buff, 16);
       Serial.printf("P2P encryption IV = 0x");
           for (int i = 0 ; i < 16 ; i++) {
               Serial.printf("%02X", encrypt_buff[i]);
           }
       Serial.println("");


           randomSeed(millis());
       }

       void loop()
       {
           uint8_t payload[] = "payload";

           int rxDelay = random(3000, 5000);

           // Receive P2P data every 10 seconds
           if(millis() - startTime >= 10*1000) {
             Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
             startTime = millis();
             Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {

             Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
     */

      bool set(uint8_t *buff, uint32_t len);
  };

  /**@par   Description
     *      This api configures the P2P FSK modem bitrate (600b/s-307200b/s)
     * @ingroup     P2P
     */
  class pbr
  {
  public:
    /**@par Description
     *      This api allows to get the P2P FSK modem bitrate (600b/s-307200b/s)
     *
     * @par Syntax
     *  api.lora.pbr.get()
     *
   * @return The P2P FSK modem bitrate
     */
    uint32_t get();

    /**@par Description
     *      This api allows to set the P2P FSK modem bitrate (600b/s-307200b/s)
     *
     * @par Syntax
     *  api.lora.pbr.set(value)
     *
         * @param       value
     * @return
     */
    bool set(uint32_t value);
  };

  /**@par   Description
     *      This api configures the P2P FSK modem frequency deviation
     * @ingroup     P2P
     */
  class pfdev
  {
  public:
    /**@par Description
     *      This api allows to get the P2P FSK modem frequency deviation
     *
     * @par Syntax
     *  api.lora.pfdev.get()
     *
     * @return  The P2P FSK modem frequency deviation
     */
    uint32_t get();

    /**@par Description
     *      This api allows to set the P2P FSK modem frequency deviation
     *
     * @par Syntax
     *  api.lora.pfdev.set(value)
     *
         * @param       value
     * @return
     */
    bool set(uint32_t value);
  };


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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");   
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");   
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode coding rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lora.pcr.get());

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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode coding rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lora.pcr.get());

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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
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

  class nwm
  {
  public:
    /**@par Description
     *      This api allows to get the network working mode
     *
     * @par Syntax
     *  api.lora.nwm.get()
     *
     * @return  the netwok working mode
     * @retval  0   P2P mode
     * @retval  1   LoRaWan mode
     * @retval  2   FSK mode
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the network working mode %s\r\n", api.lora.nwm.set() ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network working mode = %s\r\n", api.lora.nwm.get() ? "LoRaWan" : "P2P");

           delay(1000);
       }

           @endverbatim
     */
    int get();

    /**@par Description
     *      This api allows to set the lora P2P mode
     *
     * @par Syntax
     *  api.lora.nwm.set()
     *
     * @param   value   the network working mode
   * @return    bool
     * @retval  TRUE for setting network working mode success
     * @retval  FALSE for setting network working mode failure
     * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the network working mode %s\r\n", api.lora.nwm.set() ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network working mode = %s\r\n", api.lora.nwm.get() ? "LoRaWan" : "P2P");

           delay(1000);
       }

           @endverbatim
     */
    bool set();
  };


  /**@par   Description
     *          This API is used to enter P2P RX mode for a specified period.
     *
     * @ingroup P2P
     * @par Syntax
     *          api.lora.precv(uint32_t timeout)
     *
     * @param   timeout     the duration of P2P Rx mode in milli-seconds, except the following magic input:
     *                          - 65535: Stay in RX mode until a packet is received.
     *                          - 65534: Stay in RX mode until api.lora.precv(0) is called.
     *                          - 65533: Stay in RX mode, but still can do TX without calling api.lora.precv(0).
     * @return  bool
     * @retval  TRUE for entering P2P Rx mode success
     * @retval  FALSE for entering P2P Rx mode failure
     * @par         Example
     * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.println("P2P Start");

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
      }
       void loop()
       {
           Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(5000) ? "Success" : "Fail");
       
           delay(6000);
       }

           @endverbatim
     */
  bool precv(uint32_t timeout);
  /**@par   Description
     *      This api provides the way to P2P send data
     *
     * @ingroup P2P
     * @par Syntax
     *      api.lora.psend(length, payload)
     *      api.lora.psend(length, payload,cad_enable)
     *
     * @param   length      the length of the payload
     * @param   payload     the data send to the other device
     * @param   bool        Channel Activity Detection enable
     * @return  bool
     * @retval  TRUE for sending data success
     * @retval  FALSE for sending data failure
     * @par         Example
     * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.println("P2P Start");

           Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           uint8_t payload[] = "payload";
           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload,true)? "Success" : "Fail");

           delay(5000);
       }

           @endverbatim
     */
  bool psend(uint8_t length, uint8_t *payload);
  bool psend(uint8_t length, uint8_t *payload,bool cad_enable);


  /**@par   Description
     *          This API is used to register a callback function,
                so that application can be notified on receiving P2P data.
     *
     * @ingroup P2P
     * @par Syntax
     *          api.lora.registerPRecvCallback(service_lora_p2p_recv_cb_type callback)
     * @param   The callback function
     * @return  bool
     * @retval  TRUE for setting callback function success
     * @retval  FALSE for setting callback function failure
     * @par     Example
     * @verbatim
       void recv_cb(rui_lora_p2p_recv_t data) {
         if (data.Status == LORA_P2P_RXDONE) {
           Serial.printf("P2P receive:");
           for (int i = 0; i < data.BufferSize; i++) {
             Serial.printf(" %02X", data.Buffer[i]);
           }
           Serial.printf(", RSSI: %d, SNR: %d\r\n", data.Rssi, data.Snr);
         }
         else if (data.Status == LORA_P2P_RXTIMEOUT) {
           Serial.println("P2P receive timeout");
         }
         else if (data.Status == LORA_P2P_RXERROR) {
           Serial.println("P2P receive CRC error");
         }
       }

       void send_cb(void) {
         Serial.println("I send something");
       }

       long startTime;

       void setup()
       {
         Serial.begin(115200);

         delay(2000);
         startTime = millis();

         Serial.println("P2P Start");

         Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
         Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
         Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
         Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
         Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");

         api.lora.registerPRecvCallback(recv_cb);
         api.lora.registerPSendCallback(send_cb);

         randomSeed(millis());
       }

       void loop()
       {
         uint8_t payload[] = "payload";

         int rxDelay = random(3000, 5000);

         // Receive P2P data every 10 seconds
         if(millis() - startTime >= 10*1000) {
           Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
           startTime = millis();
           Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
           delay(rxDelay);
         } else {

           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
           delay(1000);
         }

       }
       @endverbatim
     */
  bool registerPRecvCallback(service_lora_p2p_recv_cb_type callback);
  /**@par   Description
     *          This API is used to register a callback function,
                so that application can be notified when P2P uplink process is done.
     *
     * @ingroup P2P
     * @par Syntax
     *          api.lora.registerPSendCallback(service_lora_p2p_send_cb_type callback)
     * @param   The callback function
     * @return  bool
     * @retval  TRUE for setting callback function success
     * @retval  FALSE for setting callback function failure
     * @par     Example
     * @verbatim
       void recv_cb(rui_lora_p2p_recv_t data) {
         if (data.Status == LORA_P2P_RXDONE) {
           Serial.printf("P2P receive:");
           for (int i=0; i<data.BufferSize; i++) {
             Serial.printf(" %02X", data.Buffer[i]);
           }
           Serial.printf(", RSSI: %d, SNR: %d\r\n", data.Rssi, data.Snr);
         }
         else if (data.Status == LORA_P2P_RXTIMEOUT) {
           Serial.println("P2P receive timeout");
         }
         else if (data.Status == LORA_P2P_RXERROR) {
           Serial.println("P2P receive CRC error");
         }
       }

       void send_cb(void) {
         Serial.println("I send something");
       }

       long startTime;

       void setup()
       {
         Serial.begin(115200);

         delay(2000);
         startTime = millis();

         Serial.println("P2P Start");

         Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
         Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
         Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
         Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
         Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");
       
         api.lora.registerPRecvCallback(recv_cb);
         api.lora.registerPSendCallback(send_cb);
       
         randomSeed(millis());
       }
       
       void loop()
       {
         uint8_t payload[] = "payload";
       
         int rxDelay = random(3000, 5000);
       
         // Receive P2P data every 10 seconds
         if(millis() - startTime >= 10*1000) {
           Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
           startTime = millis();
           Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
           delay(rxDelay);
         } else {
         
           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
           delay(1000);
         }
       
       }       
       @endverbatim
     */
  bool registerPSendCallback(service_lora_p2p_send_cb_type callback);
  /**@par   Description
     *          This API is used to register a callback function,
                so that application can be notified when P2P uplink process is done.
     *
     * @ingroup P2P
     * @par Syntax
     *          api.lora.registerPSendCallback(service_lora_p2p_send_cb_type callback)
     * @param   The callback function
     * @return  bool
     * @retval  TRUE for setting callback function success
     * @retval  FALSE for setting callback function failure
     * @par     Example
     * @verbatim
       void recv_cb(rui_lora_p2p_recv_t data) {
         Serial.println("Receive something");
       }

       void send_cb(void) {
         Serial.println("I send something");
       }

       void cad_cb(bool detect) {
         if(detect)
           Serial.println("detect Activity");
         else
           Serial.println("no Activity");

       }


       long startTime;

       void setup()
       {
         Serial.begin(115200);

         delay(2000);
         startTime = millis();

         Serial.println("P2P Start");

         Serial.printf("Set Node device work mode %s\r\n", api.lora.nwm.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode frequency %s\r\n", api.lora.pfreq.set(868000000) ? "Success" : "Fail");
         Serial.printf("Set P2P mode spreading factor %s\r\n", api.lora.psf.set(12) ? "Success" : "Fail");
         Serial.printf("Set P2P mode bandwidth %s\r\n", api.lora.pbw.set(125) ? "Success" : "Fail");
         Serial.printf("Set P2P mode code rate %s\r\n", api.lora.pcr.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode preamble length %s\r\n", api.lora.ppl.set(8) ? "Success" : "Fail");
         Serial.printf("Set P2P mode tx power %s\r\n", api.lora.ptp.set(22) ? "Success" : "Fail");

         api.lora.registerPRecvCallback(recv_cb);
         api.lora.registerPSendCallback(send_cb);
         api.lora.registerPSendCADCallback(cad_cb);

         randomSeed(millis());
       }

       void loop()
       {
         uint8_t payload[] = "payload";

         int rxDelay = random(3000, 5000);

         // Receive P2P data every 10 seconds
         if(millis() - startTime >= 10*1000) {
           Serial.printf("P2P Rx start for %d millisSconds\r\n", rxDelay);
           startTime = millis();
           Serial.printf("P2P set Rx mode %s\r\n",api.lora.precv(rxDelay) ? "Success" : "Fail");
           delay(rxDelay);
         } else {

           Serial.printf("P2P send %s\r\n", api.lora.psend(sizeof(payload), payload)? "Success" : "Fail");
  delay(1000);
         }

       }
       @endverbatim
     */
  bool registerPSendCADCallback(service_lora_p2p_send_CAD_cb_type callback);

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
  pfreq pfreq;
  psf psf;
  pbw pbw;
  pcr pcr;
  ppl ppl;
  ptp ptp;
  encry encry;
  enckey enckey;
  enciv  enciv;
  pbr pbr;
  pfdev pfdev;
  nwm nwm;

};

#endif

#endif //end RAKLoRa.h

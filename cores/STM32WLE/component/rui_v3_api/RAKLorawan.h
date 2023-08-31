#ifndef __RAK_LORAWAN_H__
#define __RAK_LORAWAN_H__

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

using namespace std;

/**@addtogroup	RUI_Lorawan_Data_Type
 * @{
 */

/**@par	Description
 * 	The regions of LoRa
 */
typedef enum
{
  RAK_REGION_EU433 = 0, ///< EU433
  RAK_REGION_CN470 = 1, ///< CN470 ~ 510
  RAK_REGION_RU864 = 2, ///< RU864 ~ 870
  RAK_REGION_IN865 = 3, ///< IN865 ~ 867
  RAK_REGION_EU868 = 4, ///< EU863 ~ 870
  RAK_REGION_US915 = 5, ///< US902 ~ 928
  RAK_REGION_AU915 = 6, ///< AU915 ~ 928
  RAK_REGION_KR920 = 7, ///< KR920 ~ 923
  RAK_REGION_AS923 = 8, ///< AS923-1
  RAK_REGION_AS923_2 = 9, ///< AS923-2
  RAK_REGION_AS923_3 = 10, ///< AS923-3
  RAK_REGION_AS923_4 = 11, ///< AS923-4
} RAK_LORA_BAND;

/**@par	Description
 *	The LoRaWan network join modes	
 */
typedef enum
{
  RAK_LORA_ABP = 0, ///< activation by personalization
  RAK_LORA_OTAA = 1 ///< over-the-air activation
} RAK_LORA_JOIN_MODE;

/**@par	Description
 * 	The LoRaWan working modes
 */
typedef enum
{
  RAK_LORA_P2P = 0, ///< Switch to P2P mode
  RAK_LORAWAN = 1,  ///< Switch to LoRaWan mode
  RAK_LORA_FSK = 2, ///< Switch to FSK mode
} RAK_LORA_WORK_MODE;

/**@par	Description
 * 	The status of confirm mode
 */
typedef enum
{
  RAK_LORA_NO_ACK = 0, ///< The device will not get received data from network
  RAK_LORA_ACK = 1,    ///< The device will get received data from network
} RAK_LORA_CONFIRM_MODE;

/**@par	Description
 * 	The LoRaWan classes
 */
typedef enum
{
  RAK_LORA_CLASS_A = 0, ///< The LoRaWan will work in Class A
  RAK_LORA_CLASS_B = 1, ///< The LoRaWan will work in Class B
  RAK_LORA_CLASS_C = 2, ///< The LoRaWan will work in Class C
} RAK_LORA_CLASS;

/**@par	Description
 * 	The structure of a multicast group
 */
typedef struct
{
  uint8_t McDevclass;     ///< The device class of a multicast group
  uint32_t McAddress;     ///< The address of a multicast group
  uint8_t McAppSKey[16];  ///< The application session key of a multicast group
  uint8_t McNwkSKey[16];  ///< The Network session key of a multicast group
  uint32_t McFrequency;   ///< The frequency of a multicast group
  int8_t McDatarate;      ///< The data rate of a multicast group
  uint16_t McPeriodicity; ///< The periodicity of a multicast group
  int8_t McGroupID;       ///< The group ID of a multicast group
  uint8_t entry;          ///< The entry of a multicast group
} RAK_LORA_McSession;

/**@par	Description
 *	The structure of a rssi data
 */
typedef struct
{
  uint32_t chan; ///< The channel of a rssi
  uint16_t mask; ///< The mask of a rssi
  int8_t rssi;   ///< The rssi on reception
} RAK_LORA_chan_rssi;

/**@}*/

class RAKLorawan
{

public:
  RAKLorawan();

  /**@par	Description
     *      	This api does a join request to the network
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *      	api.lorawan.join()
     * @return	bool
     * @retval	TRUE for success
     * @retval	FALSE for join failure
     * @par     Example
     * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
       }

           @endverbatim
     */
  bool join();

  /**@par	Description
     *          This api provides the way to send data on a dedicated port number
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *          api.lorawan.send(length, payload, fport)
     *          api.lorawan.send(length, payload, fport, confirm)
     *          api.lorawan.send(length, payload, fport, confirm, retry)
     *
     * @param   length		the length of the payload
     * @param   payload		the date to uplink
     * @param   fport		allow 1 ~ 223
     * @param	confirm		Override cfm setting to get confirm message from gateway (just for this time)
     * @param	retry		Override rety setting to retry if sending failed (just for this time)
     * @return	bool
     * @retval	TRUE for sending uplink success
     * @retval	FALSE for sending uplink
     * @par         Example
     * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t payload[] = "example";

           if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
               Serial.println("Send Success");
           } else {
               Serial.println("Send fail");

           }

           delay(5000);
       }

           @endverbatim
     */
  bool send(uint8_t length, uint8_t *payload, uint8_t fport, bool confirm, uint8_t retry);
  bool send(uint8_t length, uint8_t *payload, uint8_t fport, bool confirm);
  bool send(uint8_t length, uint8_t *payload, uint8_t fport);

  /**@par	Description
     * 		This api gets or sets the times of retransmission of Confirm packet data
     * @ingroup		Joining_and_Sending
     */
  class rety
  {
  public:
    /**@par	Description
         *     	This api allows to get the times of retransmission of Confirm packet data
	 *
	 * @par	Syntax
	 *	api.lorawan.rety.get()
	 * @return	the retry times for retransmission	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the times of retansmission %s\n\r", api.lorawan.rety.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The time of retransmission = %d\n\r", api.lorawan.rety.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows to set the times of retransmission of Confirm packet data
	 *
	 * @par	Syntax
	 *	api.lorawan.rety.set(value)
	 *
	 * @note	Cant only input 0 ~ 7 times
	 * @param	value	the retry times for retransmission
   * @return	bool
	 * @retval	TRUE for setting retry time success
	 * @retval	FALSE for setting retry times failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the times of retansmission %s\n\r", api.lorawan.rety.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The times of retransmission = %d\n\r", api.lorawan.rety.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *      	This api provides a way to send long packet(1024 bytes) text data
     *
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *      	api.lorawan.lpsend(port, ack, payload, length)
     * @param	port	application port to be transmitted
     * @param	ack	indicate this is a confirmed message or not
     * @param	payload	the date you want to send
     * @param	length	the length of the paylaod
     * @return	bool
     * @retval	TRUE for sending data success
     * @retval	FALSE for sending data failure
     * @par     Example
     * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t payload[] = "12345678901234567890";

           if (api.lorawan.lpsend(129, 1, payload, sizeof(payload))) {
               Serial.println("Send Success");
           } else {
               Serial.println("Send fail");

           }

           delay(5000);
       }

           @endverbatim
     */
  bool lpsend(uint8_t port, bool ack, uint8_t *payload, int length);

  /**@par	Description
     *      
     *
     * @par	Syntax
     *      	api.lorawan.usend(port, confirm, retry, payload, length)
     * @param	port
     * @param	confirm
     * @param	retry
     * @param	payload
     * @param	length
     * @return
     */
  bool usend(uint8_t port, bool confirm, uint8_t retry, uint8_t *payload, uint8_t length);

  /**@par	Description
     *          This API is used to register a callback function,
                so that application can be notified on receiving LoRaWAN data.
     *
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *      	api.lorawan.registerRecvCallback(service_lora_recv_cb callback)
     * @param	The callgback function
     * @return	bool
     * @retval	TRUE for setting callback function success
     * @retval	FALSE for setting callback function failure
     * @par	Example
     * @verbatim
     void recv_cb(SERVICE_LORA_RECEIVE_T *data) {
       Serial.println("Something received!");
       for (int i = 0 ; i < data->BufferSize ; i++) {
         Serial.printf("%x", data->Buffer[i]);
       }
       Serial.print("\r\n");
     }

     void join_cb(int32_t status) {
       Serial.printf("Join status: %d\r\n", status);
     }
     
     void send_cb(int32_t status) {
       Serial.printf("Send status: %d\r\n", status);
     }

     // OTAA Device EUI MSB
     uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
     // OTAA Application EUI MSB
     uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
     // OTAA Application Key MSB
     uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

     void setup()
     {
         Serial.begin(115200);

         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);

         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.join();
         api.lorawan.registerRecvCallback(recv_cb);
	 api.lorawan.registerJoinCallback(join_cb);
         api.lorawan.registerSendCallback(send_cb);

         //wait for Join success
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
     }

     void loop()
     {
         uint8_t payload[] = "example";

         if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
             Serial.println("Send Success");
         } else {
             Serial.println("Send fail");

         }

         delay(5000);
     }



       @endverbatim
     */
  bool registerRecvCallback(service_lora_recv_cb callback);

  /**@par	Description
     *          This API is used to register a callback function,
                so that application can be notified when joining process is done.
     *
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *      	api.lorawan.registerJoinCallback(service_lora_join_cb callback)
     * @param	The callgback function
     * @return	bool
     * @retval	TRUE for setting callback function success
     * @retval	FALSE for setting callback function failure
     * @par	Example
     * @verbatim
     void recv_cb(SERVICE_LORA_RECEIVE_T *data) {
       Serial.println("Something received!");
       for (int i = 0 ; i < data->BufferSize ; i++) {
         Serial.printf("%x", data->Buffer[i]);
       }
       Serial.print("\r\n");
     }

     void join_cb(int32_t status) {
       Serial.printf("Join status: %d\r\n", status);
     }
     
     void send_cb(int32_t status) {
       Serial.printf("Send status: %d\r\n", status);
     }

     // OTAA Device EUI MSB
     uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
     // OTAA Application EUI MSB
     uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
     // OTAA Application Key MSB
     uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

     void setup()
     {
         Serial.begin(115200);

         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);

         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.join();
         api.lorawan.registerRecvCallback(recv_cb);
	 api.lorawan.registerJoinCallback(join_cb);
         api.lorawan.registerSendCallback(send_cb);

         //wait for Join success
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
     }

     void loop()
     {
         uint8_t payload[] = "example";

         if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
             Serial.println("Send Success");
         } else {
             Serial.println("Send fail");

         }

         delay(5000);
     }



       @endverbatim
     */
  bool registerJoinCallback(service_lora_join_cb callback);

  /**@par	Description
     *          This API is used to register a callback function,
                so that application can be notified when uplink process is done.
     *
     * @ingroup	Joining_and_Sending
     * @par	Syntax
     *      	api.lorawan.registerSendCallback(service_lora_send_cb callback)
     * @param	The callback function
     * @return	bool
     * @retval	TRUE for setting callback function success
     * @retval	FALSE for setting callback function failure
     * @par	Example
     * @verbatim
     void recv_cb(SERVICE_LORA_RECEIVE_T *data) {
       Serial.println("Something received!");
       for (int i = 0 ; i < data->BufferSize ; i++) {
         Serial.printf("%x", data->Buffer[i]);
       }
       Serial.print("\r\n");
     }

     void join_cb(int32_t status) {
       Serial.printf("Join status: %d\r\n", status);
     }
     
     void send_cb(int32_t status) {
       Serial.printf("Send status: %d\r\n", status);
     }

     // OTAA Device EUI MSB
     uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
     // OTAA Application EUI MSB
     uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
     // OTAA Application Key MSB
     uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

     void setup()
     {
         Serial.begin(115200);

         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);

         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.join();
         api.lorawan.registerRecvCallback(recv_cb);
	 api.lorawan.registerJoinCallback(join_cb);
         api.lorawan.registerSendCallback(send_cb);

         //wait for Join success
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
     }

     void loop()
     {
         uint8_t payload[] = "example";

         if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
             Serial.println("Send Success");
         } else {
             Serial.println("Send fail");

         }

         delay(5000);
     }



       @endverbatim
     */
  bool registerSendCallback(service_lora_send_cb callback);

  /**@par	Description
     *          This API is used to register a callback function,
                so that application can be notified on receiving P2P data.
     *
     * @ingroup	P2P
     * @par	Syntax
     *      	api.lorawan.registerPRecvCallback(service_lora_p2p_recv_cb_type callback)
     * @param	The callback function
     * @return	bool
     * @retval	TRUE for setting callback function success
     * @retval	FALSE for setting callback function failure
     * @par 	Example
     * @verbatim
       void recv_cb(rui_lora_p2p_recv_t data) {
         Serial.println("Receive something");
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
         
         Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
         Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
         Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
         Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
         Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       
         api.lorawan.registerPRecvCallback(recv_cb);
         api.lorawan.registerPSendCallback(send_cb);
       
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
           Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
           delay(rxDelay);
         } else {
         
           Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
           delay(1000);
         }
       
       }       
       @endverbatim
     */
  bool registerPRecvCallback(service_lora_p2p_recv_cb_type callback);

  /**@par	Description
     *          This API is used to register a callback function,
                so that application can be notified when P2P uplink process is done.
     *
     * @ingroup	P2P
     * @par	Syntax
     *      	api.lorawan.registerPSendCallback(service_lora_p2p_send_cb_type callback)
     * @param	The callback function
     * @return	bool
     * @retval	TRUE for setting callback function success
     * @retval	FALSE for setting callback function failure
     * @par 	Example
     * @verbatim
       void recv_cb(rui_lora_p2p_recv_t data) {
         Serial.println("Receive something");
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
         
         Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
         Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
         Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
         Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
         Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
         Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       
         api.lorawan.registerPRecvCallback(recv_cb);
         api.lorawan.registerPSendCallback(send_cb);
       
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
           Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
           delay(rxDelay);
         } else {
         
           Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
           delay(1000);
         }
       
       }       
       @endverbatim
     */
  bool registerPSendCallback(service_lora_p2p_send_cb_type callback);

  /**@par	Description
     *      	view or change the LoRAWAN APPEUI and use it to setup the LoRAWAN connection	
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class appeui
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the global application identifier
	 *
	 * @par	Syntax
	 *	api.lorawan.appeui.get(buf, len)
	 * @param	buf	the buffer to get AppEUI
	 * @param	len	the length of AppEUI(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for getting AppEUI successfully
	 * @retval	FALSE for getting AppEUI failure
	 * @par         Example
         * @verbatim
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA

           if(api.lorawan.appeui.set(node_app_eui, 8) == true)
               Serial.println("LoRaWan AppEUI set success");
           else
               Serial.println("LoRaWan AppEUI set fail");
       }

       void loop()
       {
           uint8_t buff[8];

           if(api.lorawan.appeui.get(buff, 8) == true) {
               Serial.print("LoRaWan AppEUI = 0x");
               for(int i = 0; i < 8; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan APPEUI get fail");
           }

           delay(1000);
       }

           @endverbatim

	 */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the global application identifier
	 *
	 * @par	Syntax
	 *	api.lorawan.appeui.set(buf, len)
	 * @param	buf	the buffer to set AppEUI
	 * @param	len	the length of AppEUI(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for setting AppEUI successfully
	 * @retval	FALSE for setting AppEUI failure
	 * @par		Example
	 * @verbatim
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};	
        
       void setup()
       {
           Serial.begin(115200);
       
           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA
       
           if(api.lorawan.appeui.set(node_app_eui, 8) == true)
               Serial.println("LoRaWan AppEUI set success");
           else
               Serial.println("LoRaWan AppEUI set fail");
       }
       
       void loop()
       {
           uint8_t buff[8];
       
           if(api.lorawan.appeui.get(buff, 8) == true) {
               Serial.print("LoRaWan AppEUI = 0x");
               for(int i = 0; i < 8; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan AppEUI get fail");
           }
       
           delay(1000);
       }

   @endverbatim
	 */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		view or change the LoRAWAN APPKEY and  use it to setup the LoRAWAN connection
     * @ingroup		Keys_IDs_and_EUI_Management	 
     */
  class appkey
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the application key
	 *
	 * @par	Syntax
	 *	api.lorawan.appkey.get(buf, len)
	 * @param	buf	the buffer to get AppKey
	 * @param	len	the length of AppKey(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for getting AppKey successfully
	 * @retval	FALSE for getting Appkey failure
	 * @par         Example
         * @verbatim
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA

           if(api.lorawan.appkey.set(node_app_key, 16) == true)
               Serial.println("LoRaWan AppKey set success");
           else
               Serial.println("LoRaWan AppKey set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.appkey.get(buff, 16) == true) {
               Serial.print("LoRaWan AppKey = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan AppKey get fail");
           }

           delay(1000);
       }

           @endverbatim
         */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the application key
	 *
	 * @par	Syntax
	 *	api.lorawan.appkey.set(buf, len);
	 * @param	buf	the buffer to set AppKey
	 * @param	len	the length of AppKey(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for setting AppKey successfully
	 * @retval	FALSE for setting Appkey failure
	 * @par         Example
         * @verbatim
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA

           if(api.lorawan.appkey.set(node_app_key, 16) == true)
               Serial.println("LoRaWan AppKey set success");
           else
               Serial.println("LoRaWan AppKey set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.appkey.get(buff, 16) == true) {
               Serial.print("LoRaWan AppKey = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan AppKey get fail");
           }

           delay(1000);
       }

           @endverbatim
         */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		This api allows the user to get or set the application session key	
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class appskey
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the application session key
	 * @par	Syntax
	 *	api.lorawan.appskey.get(buf, len);
	 * @note	This function can only work in ABP mode
	 * @param	buf	the buffer to get AppSKey
	 * @param	len	the length of AppSKey(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for getting AppSKey successfully
	 * @retval	FALSE for getting AppSKey failure
	 * @par         Example
         * @verbatim
       // ABP Application Session Key
       uint8_t node_app_skey[16] = {0x25, 0xC4, 0xF1, 0xD1, 0x78, 0xC8, 0x8D, 0x01, 0xA8, 0x80, 0xC2, 0x79, 0xA7, 0x9F, 0x34, 0x3B};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.appskey.set(node_app_skey, 16) == true)
               Serial.println("LoRaWan AppSKey set success");
           else
               Serial.println("LoRaWan AppSKey set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.appskey.get(buff, 16) == true) {
               Serial.print("LoRaWan AppSKey = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan AppSKey get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the application session key
	 *
	 * @par	Syntax
	 *	api.lorawan.appskey.set(buf, len)
	 * @param	buf	The buffer to get AppSKey
	 * @param	len	the length of AppSkey(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for getting AppSKey successfully
	 * @retval	FALSE for getting AppSKey failure
	 * @par         Example
         * @verbatim
       // ABP Application Session Key
       uint8_t node_app_skey[16] = {0x25, 0xC4, 0xF1, 0xD1, 0x78, 0xC8, 0x8D, 0x01, 0xA8, 0x80, 0xC2, 0x79, 0xA7, 0x9F, 0x34, 0x3B};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.appskey.set(node_app_skey, 16) == true)
               Serial.println("LoRaWan AppSKey set success");
           else
               Serial.println("LoRaWan AppSKey set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.appskey.get(buff, 16) == true) {
               Serial.print("LoRaWan AppSKey = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan AppSKey get fail");
           }

           delay(1000);
       }

           @endverbatim

	 */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		This api allows the user to access the device address
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class daddr
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the device address
	 *
	 * @par	Syntax
	 *	api.lorawan.daddr.get(buf, len);
	 * @note	This function can only work in ABP mode
	 * @param	buf	the buffer to get device address
	 * @param	len	the length of device address(must be 4 bytes)
   * @return	bool
	 * @retval	TRUE for getting device address successfully
	 * @retval	FALSE for getting device address failure
	 * @par         Example
         * @verbatim
       // ABP Device Address
       uint8_t node_dev_addr[4] = {0x05, 0x05, 0x06, 0x06};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.daddr.set(node_dev_addr, 4) == true)
               Serial.println("LoRaWan device address set success");
           else
               Serial.println("LoRaWan device address set fail");
       }

       void loop()
       {
           uint8_t buff[4];

           if(api.lorawan.daddr.get(buff, 4) == true) {
               Serial.print("LoRaWan device address = 0x");
               for(int i = 0; i < 4; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan device address get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the device address
	 *
	 * @par	Syntax
	 *	api.lorawan.daddr.set(buf, len);
	 * @param	buf	the buffer to set device address
	 * @param	len	the length of device address(must be 4 bytes)
   * @return	bool
	 * @retval	TRUE for setting device address successfully
	 * @retval	FALSE for setting device address failure
	 * @par         Example
         * @verbatim
       // ABP Device Address
       uint8_t node_dev_addr[4] = {0x05, 0x05, 0x06, 0x06};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.daddr.set(node_dev_addr, 4) == true)
               Serial.println("LoRaWan device address set success");
           else
               Serial.println("LoRaWan device address set fail");
       }

       void loop()
       {
           uint8_t buff[4];

           if(api.lorawan.daddr.get(buff, 4) == true) {
               Serial.print("LoRaWan device address = 0x");
               for(int i = 0; i < 4; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan device address get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		view or change the LoRAWAN DEUI and  use it to setup the LoRAWAN connection
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class deui
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the global end-device ID
	 *
	 * @par	Syntax
	 *	api.lorawan.deui.get(buf, len)
	 * @param	buf	the buffer to get device EUI
	 * @param	len	the length of device EUI(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for getting device EUI successfully
	 * @retval	FALSE for getting device EUI failure
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA

           if(api.lorawan.deui.set(node_device_eui, 8) == true)
               Serial.println("LoRaWan device EUI set success");
           else
               Serial.println("LoRaWan device EUI set fail");
       }

       void loop()
       {
           uint8_t buff[8];

           if(api.lorawan.deui.get(buff, 8) == true) {
               Serial.print("LoRaWan device EUI = 0x");
               for(int i = 0; i < 8; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan device EUI get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the global end-device ID
	 *
	 * @par	Syntax
	 *	api.lorawan.deui.set(buf, len)
	 * @param	buf	the buffer to set device EUI
	 * @param	len	the length of device EUI(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for setting device EUI successfully
	 * @retval	FALSE for setting device EUI failure
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_OTAA); // Set LoRaWan join mode to OTAA

           if(api.lorawan.deui.set(node_device_eui, 8) == true)
               Serial.println("LoRaWan device EUI set success");
           else
               Serial.println("LoRaWan device EUI set fail");
       }

       void loop()
       {
           uint8_t buff[8];

           if(api.lorawan.deui.get(buff, 8) == true) {
               Serial.print("LoRaWan device EUI = 0x");
               for(int i = 0; i < 8; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan device EUI get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		This api allows the user to access the network identifier(NetID)
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class netid
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the network identifier(NetID)
	 *
	 * @par	Syntax
	 *	api.lorawan.netid.get(buf, len)
	 * @note	Even though the length of network identifier(NetID) is 3 bytes, you should give 4-bytes buffer for natural alignment
	 * @param	buf	the buffer to get network identifier(NetID)
	 * @param	len	the length of network identifier(NetID)(must be 3 bytes)
   * @return	bool
	 * @retval	TRUE for getting network identifier(NetID) successfully
	 * @retval	FALSE for getting network identifier(NetID) failure
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t buff[4];

           if(api.lorawan.netid.get(buff, 4) == true) {
               Serial.print("LoRaWan network identfier(NetID) = 0x");
               for(int i = 0; i < 3; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan network identifer(NetID) get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		This api allows the user to get or set the network session key
     * @ingroup		Keys_IDs_and_EUI_Management
     */
  class nwkskey
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the network session key
	 *
	 * @par	Syntax
	 *	api.lorawan.nwkskey.get(buf, len)
	 * @note	This function can only work in ABP mode0
	 * @param	buf	the buffer to get network session key
	 * @param	len	the length of network session key(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for getting network session key successfully
	 * @retval	FALSE for getting network session key failure
	 * @par         Example
         * @verbatim
       // ABP Network Session Key
       uint8_t node_nwk_skey[16] = {0xD6, 0x03, 0x37, 0xAC, 0x97, 0x4C, 0x43, 0x2F, 0xF3, 0x7A, 0xF9, 0xA7, 0x9B, 0xE8, 0x50, 0xF7};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.nwkskey.set(node_nwk_skey, 16) == true)
               Serial.println("LoRaWan network session key set success");
           else
               Serial.println("LoRaWan network session key set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.nwkskey.get(buff, 16) == true) {
               Serial.print("LoRaWan network session key = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan network session key get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint8_t *buf, uint32_t len);

    /**@par	Description
	 *     	This api allows the user to set the network session key
	 *
	 * @par	Syntax
	 *	api.lorawan.nwkskey.set(buf, len)
	 * @param	buf	the buffer to set network session key
	 * @param	len	the length of network session key(must be 16 bytes)
   * @return	bool
	 * @retval	TRUE for setting network session key successfully
	 * @retval	FALSE for setting network session key failure
	 * @par         Example
         * @verbatim
       // ABP Network Session Key
       uint8_t node_nwk_skey[16] = {0xD6, 0x03, 0x37, 0xAC, 0x97, 0x4C, 0x43, 0x2F, 0xF3, 0x7A, 0xF9, 0xA7, 0x9B, 0xE8, 0x50, 0xF7};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.njm.set(RAK_LORA_ABP); // Set LoRaWan join mode to ABP

           if(api.lorawan.nwkskey.set(node_nwk_skey, 16) == true)
               Serial.println("LoRaWan network session key set success");
           else
               Serial.println("LoRaWan network session key set fail");
       }

       void loop()
       {
           uint8_t buff[16];

           if(api.lorawan.nwkskey.get(buff, 16) == true) {
               Serial.print("LoRaWan network session key = 0x");
               for(int i = 0; i < 16; i++) {
                   Serial.printf("%02X", buff[i]);
               }
               Serial.println("");
           } else {
               Serial.println("LoRaWan network session key get fail");
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t *buf, uint32_t len);
  };

  /**@par	Description
     *		This api allows the user to access the notification on received data coming from the network
     * @ingroup		Joining_and_Sending
     */
  class cfm
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the notification on received data coming from the network
	 *
	 * @par	Syntax
	 *	api.lorawan.cfm.get()
   * @return	bool
	 * @retval	TRUE  : LoRaWan uplink is not on confirm mode
	 * @retval	FALSE : LoRaWan uplink is on confirm mode
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);
           
           Serial.printf("Set confirm mode status %s\n\r", api.lorawan.cfm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Packet is %s\n\r", api.lorawan.cfm.get() ? "CONFIRMED" : "UNCONFIRMED");
	   
           delay(1000);
       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *     	This api allows the user to set the notification on received data coming from the network
	 *
	 * @par	Syntax
	 *	api.lorawan.cfm.set(value)
	 * @param	value	the mode of confirm mode to set 
   * @return	bool
	 * @retval	TRUE for setting confirm mode success
	 * @retval	FALSE for setting confirm mode failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set confirm mode status %s\n\r", api.lorawan.cfm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Packet is %s\n\r", api.lorawan.cfm.get() ? "CONFIRMED" : "UNCONFIRMED");

           delay(1000);
       }

           @endverbatim
	 */
    bool set(bool value);
  };

  /**@par	Description
     *		This api allows the user to access the status of the last “SEND” command
     * @ingroup		Joining_and_Sending
     */
  class cfs
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the status of the last “SEND” command
	 *
	 * @par	Syntax
	 *	api.lorawan.cfs.get();
	 * @note	This api can only work when Confirm mode is on
   * @return	bool
	 * @retval	TRUE  : Confirm Succes
	 * @retval	FALSE : Confirm Failure
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t payload[] = "example";
           
           if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
               Serial.println("Send Success");
               Serial.printf("Send confirm %s\r\n", api.lorawan.cfs.get() ? "Success" : "Fail");
           
           } else {
               Serial.println("Send fail");
  
           }
           
           delay(5000);
       }

           @endverbatim
	 */
    bool get();
  };

  /**@par	Description
     *		This api allows the user to access the network join mode
     * @ingroup		Joining_and_Sending
     */
  class njm
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the network join mode
	 *
	 * @par	Syntax
	 *	api.lorawan.njm.get()
	 * @return	bool
	 * @retval	TRUE  : OTAA
	 * @retval	FALSE : ABP
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set network join mode %s\n\r", api.lorawan.njm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network join mode is %s\n\r", api.lorawan.cfm.get() ? "OTAA" : "ABP");

           delay(1000);
       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *     	This api allows the user to set the network join mode
	 *
	 * @par	Syntax
	 *	api.lorawan.njm.set(value)
	 * @param	value	the mode of network join mode \n
	 * 			ABP:   0\n
	 * 			OTAA:  1
	 * @return	bool
	 * @retval	TRUE for setting network join mode success
	 * @retval	FALSE for setting network join mode failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set network join mode %s\n\r", api.lorawan.njm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network join mode is %s\n\r", api.lorawan.njm.get() ? "OTAA" : "ABP");

           delay(1000);
       }

           @endverbatim
	 */
    bool set(bool value);
  };

  /**@par	Description
     *		This api allows the user to access the current status of the LoRa® link
     * @ingroup		Joining_and_Sending
     */
  class njs
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the current status of the LoRa® link
	 *
	 * @par	Syntax
	 *	api.lorawan.njs.get()
   * @return	bool
   * @retval	TRUE  : Netwok	join
   * @retval	FALSE : Network not join
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
       }

           @endverbatim
	 */
    bool get();
  };

  /**@par	Description
     *		This api allows the user to access the adaptive data rate
     * @ingroup		Network
     * @note		The default value of the ADR is 1 (enabled)
     */
  class adr
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the adaptive data rate
	 *
	 * @par	Syntax
	 *	api.lorawan.adr.get()
	 *
   * @return	bool
	 * @retval	TRUE  : enable adaptive data rate	
	 * @retval	FALSE : disable adaptive data rate
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set adaptive data rate %s\r\n", api.lorawan.adr.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Adaptive data rate is  %s\r\n", api.lorawan.adr.get() ? "Enable" : "Disable");
           delay(1000);
       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *     	This api allows the user to set the adaptive data rate
	 *
	 * @par	Syntax
	 *	api.lorawan.adr.set(value)
	 *
	 * @param	value	the status of adaptive data rate
   * @return	bool
	 * @retval	TRUE  for setting status of adr success
	 * @retval	FALSE for setting status of adr failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set adaptive data rate %s\r\n", api.lorawan.adr.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Adaptive data rate is  %s\r\n", api.lorawan.adr.get() ? "Enable" : "Disable");
           delay(1000);
       }

           @endverbatim

	 */
    bool set(bool value);
  };

  /**@par	Description
     *		This api allows the user to access the LoRaWAN® class
     * @ingroup		Network
     */
  class deviceClass
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the LoRaWAN® class
	 *
	 * @par	Syntax
	 *	api.lorawan.deviceClass.get()
	 *
	 * @return	the LoRaWan class(Type: int)
	 * @retval	0	Class A
	 * @retval	1	Class B
	 * @retval	2	Class C
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set device class to Class_A  %s\r\n", api.lorawan.deviceClass.set(RAK_LORA_CLASS_A) ? "Success" : "Fail");
       }

       void loop()
       {
           switch(api.lorawan.deviceClass.get()) {
               case 0:
                   Serial.println("Device is in Class A");      
                   break;
               case 1:
                   Serial.println("Device is in Class B");
                   break;
               case 2:
                   Serial.println("Device is in Class C");
                   break;
           }

           delay(1000);
       }

           @endverbatim

	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows the user to set the LoRaWAN® class
	 *
	 * @par	Syntax
	 *	api.lorawan.deviceClass.set(value)
	 *
	 * @param	value	the LoRaWan class
   * @return	bool
	 * @retval	TRUE  for setting LoRaWan class success
	 * @retval	FALSE for setting LoRaWan class failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set device class to Class_A  %s\r\n", api.lorawan.deviceClass.set(RAK_LORA_CLASS_A) ? "Success" : "Fail");
       }

       void loop()
       {
           switch(api.lorawan.deviceClass.get()) {
               case 0:
                   Serial.println("Device is in Class A");
                   break;
               case 1:
                   Serial.println("Device is in Class B");
                   break;
               case 2:
                   Serial.println("Device is in Class C");
                   break;
           }

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to access the duty cycle parameter
     * @ingroup		Network
     */
  class dcs
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the duty cycle parameter
	 *
	 * @par	Syntax
	 *	api.lorawan.dcs.get()
	 *
   * @return	bool
	 * @retval	TRUE  : enable duty cycle
	 * @retval	FALSE : disable duty cycle
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Enable duty cycle  %s\r\n", api.lorawan.dcs.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Duty cycle is  %s\r\n", api.lorawan.adr.get() ? "Enable" : "Disable");
           delay(1000);
       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *      This api allows the user to set the duty cycle paramter
	 * @par Syntax
	 *      api.lorawan.dcs.set(dutyCycle)
	 *
	 * @param	dutyCycle	the LoRaWan duty cycle
   * @return	bool
	 * @retval	TRUE for setting duty cycle success
	 * @retval	FALSE for setting duty cycle failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Enable duty cycle  %s\r\n", api.lorawan.dcs.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Duty cycle is  %s\r\n", api.lorawan.adr.get() ? "Enable" : "Disable");
           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t dutyCycle);
  };

  /**@par	Description
     *		This api allows the user to access the data rate
     * @ingroup		Network
     */
  class dr
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the data rate
	 *
	 * @par	Syntax
	 *	api.lorawan.dr.get()
	 * @return	the data rate	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the data rate  %s\r\n", api.lorawan.dr.set(5) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The data rate is %d\r\n", api.lorawan.dr.get());
           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows the user to set the data rate
	 *
	 * @par	Syntax
	 *	api.lorawan.dr.set(value)
	 *
	 * @param	value	the data rate
   * @return	bool
	 * @retval	TRUE for setting data rate success
	 * @retval	FALSE for setting date rate failure
   * 
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the data rate  %s\r\n", api.lorawan.dr.set(5) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The data rate is %d\r\n", api.lorawan.dr.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to access the join delay on RX window 1 
     * @ingroup		Network
     */
  class jn1dl
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the join delay on RX window 1
	 *
	 * @par	Syntax
	 *	api.lorawan.jn1dl.get()
	 *
	 * @return	the join delay on RX window 1(Type: int)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the join delay on RX window 1  %s\r\n", api.lorawan.jn1dl.set(5) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The join delay on RX window 1 is %d\r\n", api.lorawan.jn1dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    int get();

    /**@par	Description
	 *     	This api allows the user to set the join delay on RX window 1
	 *
	 * @par	Syntax
	 *	api.lorawan.jn1dl.set(value)
	 *
	 * @param	value	the join delay on RX window 1
   * @return	bool
	 * @retval	TRUE for setting join delay success
	 * @retval	FALSE for setting join delay failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the join delay on RX window 1  %s\r\n", api.lorawan.jn1dl.set(5000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The join delay on RX window 1 is %d\r\n", api.lorawan.jn1dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(int value);
  };

  /**@par	Description
     *		This api allows the user to access the join delay on RX window 2
     * @ingroup		Network
     */
  class jn2dl
  {
  public:
    /**@par	Description
	 *     	This api allows the user to access the join delay on RX window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.jn2dl.get()
	 *
	 * @return	the join delay on RX window 2(Type: bool)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);
       }

       void loop()
       {
           Serial.printf("The join delay on RX window 2 is %d\r\n", api.lorawan.jn2dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    int get();

    /**@par	Description
	 *     	This api allows the user to set the join delay on RX window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.jn2dl.set(value)
	 *
	 * @param	value	the join delay on RX window 2
   * @return	bool
	 * @retval	TRUE for setting join delay success
	 * @retval	FALSE for setting join delay failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the join delay on RX window 2  %s\r\n", api.lorawan.jn2dl.set(5000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The join delay on RX window 2 is %d\r\n", api.lorawan.jn2dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(int value);
  };

  /**@par	Description
     *		This api allows the user to access the public network mode
     * @ingroup		Network
     */
  class pnm
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the public network mode
	 *
	 * @par	Syntax
	 *	api.lorawan.pnm.get()
	 *
   * @return	bool
	 * @retval	TRUE  : On
	 * @retval	FALSE : Off
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the public network mode  %s\r\n", api.lorawan.pnm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The public network mode is  %d\r\n", api.lorawan.pnm.get() ? "On" : "Off");
           delay(1000);
       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *     	This api allows the user to set the public network mode
	 *
	 * @par	Syntax
	 *	api.lorawan.pnm.set(value)
	 *
	 * @param	value	the public network mode
   * @return	bool
	 * @retval	TRUE for setting public network mode success
	 * @retval	FALSE for setting public network mode failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the public network mode  %s\r\n", api.lorawan.pnm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The public network mode is  %d\r\n", api.lorawan.pnm.get() ? "On" : "Off");
           delay(1000);
       }

           @endverbatim
	 */
    bool set(bool value);
  };

  /**@par	Description
     *		This api allows the user to access the delay of the received window 1 (
     * @ingroup		Network
     */
  class rx1dl
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the delay of the received window 1
	 *
	 * @par	Syntax
	 *	api.lorawan.rx1dl.get()
	 *
	 * @return	the delay of the received window 1	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the received delay on RX window 1  %s\r\n", api.lorawan.rx1dl.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The received delay on RX window 1 is %d\r\n", api.lorawan.rx1dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    int get();

    /**@par	Description
	 *     	This api allows the user to set the delay of the received window 1
	 *
	 * @par	Syntax
	 *	api.lorawan.rx1dl.set(value)
	 * @param	value	the delay of the received window 1
   * @return	bool
	 * @retval	TRUE for setting delay success
	 * @retval	FALSE for setting delay failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the received delay on RX window 1  %s\r\n", api.lorawan.rx1dl.set(1000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The received delay on RX window 1 is %d\r\n", api.lorawan.rx1dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(int value);
  };

  /**@par	Description
     *		This api allows the user to access the delay of the received window 2 
     * @ingroup		Network
     */
  class rx2dl
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the delay of the received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2dl.get()
	 *
	 * @return	the delay of the received window 2	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);
       }

       void loop()
       {
           Serial.printf("The received delay on RX window 2 is %d\r\n", api.lorawan.rdx2dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    int get();

    /**@par	Description
	 *     	This api allows the user to set the delay of the received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2dl.set(value)
	 * @param	value	the delay of the received window 2
   * @return	bool
	 * @retval	TRUE for setting delay success
	 * @retval	FALSE for setting delay failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the received delay on RX window 2  %s\r\n", api.lorawan.rx2dl.set(2000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The received delay on RX window 2 is %d\r\n", api.lorawan.rx2dl.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(int value);
  };

  /**@par	Description
     *		This api allows the user to access the data rate of received window 2
     * @ingroup		Network
     */
  class rx2dr
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the data rate of received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2dr.get()
	 *
	 * @return	the data rate of received window 2
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the data rate of received window 2 %s\r\n", api.lorawan.rx2dr.set(5) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The data rate of received window 2 is %d\r\n", api.lorawan.rx2dr.get());
           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows the user to set the data rate of received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2dr.set(value)
	 *
	 * @param	value	the date rate of received window 2
   * @return	bool
	 * @retval	TRUE for setting data rate success
	 * @retval	FALSE for setting data rate failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the data rate of received window 2 %s\r\n", api.lorawan.rx2dr.set(5) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The data rate of received window 2 is %d\r\n", api.lorawan.rx2dr.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to access the frequency of the received window 2
     * @ingroup		Network
     */
  class rx2fq
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the frequency of the received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2fq.get()
	 *
	 * @return	the frequency of the received window 2
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);
       }

       void loop()
       {
           Serial.printf("The frequency of received window 2 is %d\r\n", api.lorawan.rx2fq.get());
           delay(1000);
       }

           @endverbatim
	 */
    long get();

    /**@par	Description
	 *     	This api allows the user to set the frequency of the received window 2
	 *
	 * @par	Syntax
	 *	api.lorawan.rx2fq.set(value)
	 * @param	value	the frequency of the received window 2
   * @return	bool
	 * @retval	TRUE for setting frequency success
	 * @retval	FALSE for setting frequency failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the frequency on RX window 2  %s\r\n", api.lorawan.rx2fq.set(869535000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The frequency on RX window 2 is %d\r\n", api.lorawan.rx2fq.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(int value);
  };

  /**@par	Description
     *		This api allows the user to access the transmit power
     * @ingroup		Network
     */
  class txp
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the transmit power
	 *
	 * @par	Syntax
	 *	api.lorawan.txp.get()
	 *
	 * @return	the LoRaWan transmit power 
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the transmit power %s\r\n", api.lorawan.txp.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The transmit power is %d\r\n", api.lorawan.txp.get());
           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows the user to set the transmit power
	 *
	 * @par	Syntax
	 *	api.lorawan.txp.set(value)
	 *
	 * @param	value	the LoRaWan transmit power
   * @return	bool
	 * @retval	TRUE for setting transmit power successs
	 * @retval	FALSE for setting transmit power failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the transmit power %s\r\n", api.lorawan.txp.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("The transmit power is %d\r\n", api.lorawan.txp.get());
           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to get or set the unicast ping slot periodicity
     * @ingroup		Class_B
     */
  class pgslot
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the unicast ping slot periodicity
	 *
	 * @par	Syntax
	 *	api.lorawan.pgslot.get()
	 *
	 * @return	the ping slot periodicity
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.deviceClass.set(1);
           Serial.printf("Set the unicast ping slot periodicity %s\r\n", api.lorawan.pgslot.set(0) ? "Success" : "Fail");
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           Serial.printf("The unicast ping slot peridicity is %d\r\n", api.lorawan.pgslot.get());
           delay(1000);
       }
           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows the user to set the unicast ping slot periodicity
	 *
	 * @par	Syntax
	 *	api.lorawan.pgslot.set(value)
	 *
	 * @param	value	the unicast ping slot periodicity	
   * @return	bool
	 * @retval	TRUE for setting ping slot periodicity success
	 * @retval	FALSE for setting ping slot periodicity failure
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.deviceClass.set(1);
           Serial.printf("Set the unicast ping slot periodicity %s\r\n", api.lorawan.pgslot.set(0) ? "Success" : "Fail");
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           Serial.printf("The unicast ping slot peridicity is %d\r\n", api.lorawan.pgslot.get());
           delay(1000);
       }
           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to access the current beacon (default broadcast) frequency	
     * @ingroup		Class_B
     */
  class bfreq
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the current beacon (default broadcast) frequency
	 *
	 * @par	Syntax
	 *	api.lorawan.bfreq.get()
	 *
	 * @return	the current beacon frequency(Type: long)
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.deviceClass.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           Serial.printf("The current beacon freqency =  %.0f\r\n", api.lorawan.bfreq.get());
           delay(1000);
       }
           @endverbatim
	 */
    float get();
  };

  /**@par	Description
     *		This api(a) allows the user to access the current beacon time(b)
     * @ingroup		Class_B
     */
  class btime
  {
  public:
    /**@par	Description
	 *     	This api(a) allows the user to get the current beacon time(b)
	 *
	 * @par	Syntax
	 *	api.lorawan.btime.get()
	 *
	 * @return	the current beacon time(b)
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.deviceClass.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           Serial.printf("The current beacon time = %l\r\n", api.lorawan.btime.get());
           delay(1000);
       }
           @endverbatim
	 */
    long get();
  };

  /**@par	Description
     *		This api(a) allows the user to access the gateway GPS coordinate, NetID and GwID(b)
     * @ingroup		Class_B
     */
  class bgw
  {
  public:
    /**@par	Description
	 *     	This api(a) allows the user to access the gateway GPS coordinate, NetID and GwID(b)
	 *
	 * @par	Syntax
	 *	api.lorawan.bgw.get()
	 * @return	beacon_bgw_t
	 * @par		Example
	 * @verbatim
       
       beacon_bgw_t beaconBGW;
       
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
       
       void setup()
       {
         //Serial.begin(115200);
       
         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);

         api.lorawan.band.set(4);
         api.lorawan.deviceClass.set(1);
         api.lorawan.njm.set(1);
         api.lorawan.join();
       
         //Wait for Join success 
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
       }
       
       void loop()
       {
         beaconBGW = api.lorawan.bgw.get();
       
         Serial.printf("GPS Coordinate = %u\r\n", (unsigned int)beaconBGW.GPS_coordinate);
         Serial.printf("Latitude = %f\r\n", (float)beaconBGW.latitude*(float)90/(float)8388607);
         Serial.printf("longitude = %f\r\n", (float)beaconBGW.longitude*(float)180/(float)8388607);
         Serial.printf("Net ID = %u\r\n", (unsigned int)beaconBGW.net_ID);
         Serial.printf("Gateway ID = %u\r\n", (unsigned int)beaconBGW.gateway_ID);
       
         delay(1000);
       }
	   @endverbatim
	 */
    beacon_bgw_t get();
  };

  /**@par	Description
     *		This api allows the user to access the RSSI on reception
     * @ingroup		Information
     * @note		When the connection is successful and get the RSSI of the last received packet
     */
  class rssi
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the RSSI on reception
	 *
	 * @par	Syntax
	 *	api.lorawan.rssi.get()
	 *
	 * @return	the RSSI on reception(Type: int)	
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t payload[] = "example";

           if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
               Serial.println("Send Success");
	       Serial.printf("LoRaWan RSSI = %d\r\n", api.lorawan.rssi.get());

           } else {
               Serial.println("Send fail");
           }

           delay(5000);
       }

           @endverbatim
	 */
    int get();
  };

  /**@par	Description
     *		This api allows the user to access the SNR of the last received packet 
     * @ingroup		Information
     * @note		When the connection is successful and get the SNR of the last received packet
     */
  class snr
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the SNR of the last received packet
	 *
	 * @par	Syntax
	 *	api.lorawan.snr.get()
	 *
	 * @return	the SNR of the last received packet(Type: int)
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           uint8_t payload[] = "example";

           if (api.lorawan.send(sizeof(payload), payload, 129, true, 1)) {
               Serial.println("Send Success");
               Serial.printf("LoRaWan SNR = %d\r\n", api.lorawan.snr.get());

           } else {
               Serial.println("Send fail");
           }

           delay(5000);
       }

           @endverbatim
	 */
    int get();
  };

  /**@par	Description
     *		This api(a) allows the user to access the local time in a UTC format
     * @ingroup		Class_B
     */
  class ltime
  {
  public:
    /**@par	Description
	 *     	This api(a) allows the user to get the local time in a UTC format 
	 *
	 * @par	Syntax
	 *	api.lorawan.ltime.get()
	 *
	 * @return	the local time in a UTC format (Type: bool)
	 * @par         Example
         * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.appeui.set(node_app_eui, 8);
           api.lorawan.appkey.set(node_app_key, 16);
           api.lorawan.deui.set(node_device_eui, 8);

           api.lorawan.band.set(4);
           api.lorawan.njm.set(1);
           api.lorawan.deviceClass.set(1);
           api.lorawan.join();

           //wait for Join success
           while (api.lorawan.njs.get() == 0)
           {
             Serial.print("Waiting for Lorawan join...");
             api.lorawan.join();
             delay(10000);
           }
       }

       void loop()
       {
           Serial.printf("The local time(UTC) is %s\r\n", api.lorawan.ltime.get().c_str());
           delay(1000);
       }
           @endverbatim
	 */
    String get();
  };

  /**@par	Description
     *		This api allows the user to get the lorawan version
     * @ingroup		Information
     */
  class ver
  {
  public:
    /**@par	Description
	 *     	This api allows the user to get the lorawan version
	 *
	 * @par	Syntax
	 *	api.lorawan.ver.get()
	 *
	 * @return	the LoRaWan version(Type: String)
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);
       }

       void loop()
       {
           Serial.printf("The LoRaWan version is %s\r\n", api.lorawan.ver.get().c_str());
           delay(1000);
       }

           @endverbatim
	 */
    String get();
  };

  /**@par	Description
     *		This api configures the channel of the device by setting the hexadecimal 
channel mask
     * @ingroup		Supplement
     */
  class mask
  {
  public:
    /**@par	Description
	 *     	This api allows the user to set the channel mask, close or open the channel
	 *
	 * @par	Syntax
	 *	api.lorawan.mask.get(buff)
	 *
	 * @param	buff	the buffer to store channel mask
   * @return	bool
	 * @retval	TRUE fot getting channel mask success
	 * @retval	FALSE for setting channel mask failure
	 * @par         Example
         * @verbatim
       uint16_t maskBuff = 0x0003;
       
       void setup()
       {
           Serial.begin(115200);

           api.lorawan.band.set(5);
           Serial.printf("Set channel mask %s\r\n", api.lorawan.mask.set(&maskBuff) ? "Success" : "Fail");

       }

       void loop()
       {
           
           Serial.printf("Get channel mask %s\r\n", api.lorawan.mask.get(&maskBuff) ? "Success" : "Fail");
           Serial.printf("Channel mask = %04X\r\n", maskBuff);
           delay(1000);
       }

           @endverbatim
	 */
    bool get(uint16_t *buff);

    /**@par	Description
	 *     	This api allows the user to get the channel mask, close or open the channel
	 *
	 * @par	Syntax
	 *	api.lorawan.mask.set(value)
	 *
	 * @param	value	the buffer to set the channel mask
   * @return	bool
	 * @retval	TRUE for setting channel mask success
	 * @retval	FALSE for setting channel mask failure
	 * @par         Example
         * @verbatim
       uint16_t maskBuff = 0x0003;

       void setup()
       {
           Serial.begin(115200);

           api.lorawan.band.set(5);
           Serial.printf("Set channel mask %s\r\n", api.lorawan.mask.set(&maskBuff) ? "Success" : "Fail");

       }

       void loop()
       {

           Serial.printf("Get channel mask %s\r\n", api.lorawan.mask.get(&maskBuff) ? "Success" : "Fail");
           Serial.printf("Channel mask = %04X\r\n", maskBuff);
           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint16_t *value);
  };

  /**@par	Description
     *		This api set number corresponding to active regions
     * @ingroup		Supplement
     * @note		0: EU433\n
     *                  1: CN470\n 
     *                  2: RU864\n 
     *                  3: IN865\n 
     *                  4: EU868\n 
     *                  5: US915\n 
     *                  6: AU915\n 
     *                  7: KR920\n 
     *                  8: AS923-1\n 
     *                  9: AS923-2\n
     *                  10:AS923-3\n 
     *                  11:AS923-4 
     */
  class band
  {
  public:
    /**@par	Description
	 *     	This api get number corresponding to active regions	
	 *
	 * @par	Syntax
	 *	api.lorawan.band.get()
	 *
	 * @return	the active region
	 * @retval	0	EU433
	 * @retval	1	CN470
	 * @retval	2	RU864
	 * @retval	3	IN865
	 * @retval	4	EU868
	 * @retval	5	US915
	 * @retval	6	AU915
	 * @retval	7	KR920
	 * @retval	8	AS923-1
   * @retval	9	AS923-2
   * @retval	10 AS923-3
   * @retval	11 AS923-4
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set LoRa region %s\r\n", api.lorawan.band.set(4) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("LoRa region = %d\r\n", api.lorawan.band.get());

           delay(1000);
       }

           @endverbatim
	 */
    int32_t get();

    /**@par	Description
	 *     	This api set number corresponding to active regions
	 *
	 * @par	Syntax
	 *	api.lorawan.band.set(value)
	 *
	 * @param	value	the active region to set
   * @return	bool
	 * @retval	TRUE for setting active region success
	 * @retval	FALSE for setting active region failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set LoRa region %s\r\n", api.lorawan.band.set(4) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("LoRa region = %d\r\n", api.lorawan.band.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api allows the user to Verify Network Link Status
     * @ingroup		Network
     */
  class linkcheck
  {
  public:
    /**@par	Description
	 *     	This api allows the user to Verify Network Link Status
	 *
	 * @par	Syntax
	 *	api.lorawan.linkcheck.get()
	 *
	 * @return	The mode of Verifying network link status
	 * @retval	0	disable link check
	 * @retval	1	execute link check one time
	 * @retval	2	module will automatically execute one time link check after every upload of data
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Verifying network link status %s\r\n", api.lorawan.linkcheck.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network link status = %d\r\n", api.lorawan.linkcheck.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();

    /**@par	Description
	 *     	This api allows the user to set Network Link Status
	 *
	 * @par	Syntax
	 *	api.lorawan.linkcheck.set(value)
	 *
	 * @param	value	the mode of Verifying network link status
   * @return	bool
	 * @retval	TRUE for setting mode of verifying network link status success
	 * @retval	FALSE for setting mode of verifying network link status failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Verifying network link status %s\r\n", api.lorawan.linkcheck.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network link status = %d\r\n", api.lorawan.linkcheck.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		Switch to point-to-point mode, or LoRaWAN mode, or FSK mode [0:Point to point, 1:LoRaWAN, 2:FSK]
     * @ingroup		P2P
     */
  class nwm
  {
  public:
    /**@par	Description
	 *     	This api allows to get the network working mode (0 = P2P, 1 = LoRaWAN, 2 = FSK)
	 *
	 * @par	Syntax
	 *	api.lorawan.nwm.get()
	 *
	 * @return	the netwok working mode 
	 * @retval	0	P2P mode
	 * @retval	1	LoRaWan mode	
   * @retval	2	FSK mode	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the network working mode %s\r\n", api.lorawan.nwm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network working mode = %s\r\n", api.lorawan.nwm.get() ? "LoRaWan" : "P2P");

           delay(1000);
       }

           @endverbatim
	 */
    int get();

    /**@par	Description
	 *     	This api allows to set the network working mode (0 = P2P, 1 = LoRaWAN, 2 = FSK)
	 *
	 * @par	Syntax
	 *	api.lorawan.nwm.set(value)
	 *
	 * @param	value	the network working mode
   * @return	bool
	 * @retval	TRUE for setting network working mode success
	 * @retval	FALSE for setting network working mode failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set the network working mode %s\r\n", api.lorawan.nwm.set(1) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("Network working mode = %s\r\n", api.lorawan.nwm.get() ? "LoRaWan" : "P2P");

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api provides configuration frequency for the P2P mode
     * @ingroup		P2P
     */
  class pfreq
  {
  public:
    /**@par	Description
	 *     	This api allows to get the P2P frequency  Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pfreq.get()
	 *
	 * @return	The frequency for P2P mode	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");   
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");   
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lorawan.pfreq.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();

    /**@par	Description
	 *     	This api allows to set the P2P frequency Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pfreq.set(value)
	 *
	 * @param	value the frequency for P2P mode
   * @return	bool
	 * @retval	TRUE for setting frequency success
	 * @retval	FALSE for setting frequency failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode frequency = %d\r\n", api.lorawan.pfreq.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint32_t value);
  };

  /**@par	Description
     *		This api provides a configuration Spreading Factor for the P2P mode Note:This API will be deleted in the future
     * @ingroup		P2P
     */
  class psf
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Spreading Factor (6,7, 8,9, 10, 11, 12)
	 *
	 * @par	Syntax
	 *	api.lorawan.psf.get()
	 *
	 * @return	The P2P spreading factor
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lorawan.psf.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows to set P2P Spreading Factor (6,7, 8,9, 10, 11, 12) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.psf.set(value)
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
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode spreading factor = %d\r\n", api.lorawan.psf.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api provides configuration Bandwidth for the P2P mode
     * @ingroup		P2P
     */
  class pbw
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Bandwidth(125,250,500) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pbw.get()
	 *	
	 * @return	The P2P bandwidth	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lorawan.pbw.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint32_t get();

    /**@par	Description
	 *     	This api allow to set P2P Bandwidth(125,250,500) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pbw.set(value)
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
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode bandwith = %d\r\n", api.lorawan.pbw.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint32_t value);
  };

  /**@par	Description
     *		This api provides the configuration code rate for the P2P mode
     * @ingroup		P2P
     */
  class pcr
  {
  public:
    /**@par	Description
	 *     	This api allows to get code rate for the P2P mode Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pcr.get()
	 *
	 * @return	The code rate 	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
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
	 *     	This api allows to set code rate for the P2P mode Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.pcr.set(value)
	 *
	 * @param	value	the code rate for P2P mode	
   * @return	bool
	 * @retval	TRUE for setting code rate success
	 * @retval	FALSE for setting code rate failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode code rate = %d\r\n", api.lorawan.pcr.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *		This api provides configuration Preamble Length for the P2P mode Note:This API will be deleted in the future
     * @ingroup		P2P
     */
  class ppl
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P Preamble Length (2-65535)
	 *
	 * @par	Syntax
	 *	api.lorawan.ppl.get()
	 *
	 * @returni	The Preamble length 	
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lorawan.ppl.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint16_t get();

    /**@par	Description
	 *     	This api allows to set P2P Preamble Length (2-65535) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.ppl.set(value)
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
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode preamble length = %d\r\n", api.lorawan.ppl.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint16_t value);
  };

  /**@par	Description
     *		This api provides configuration Power for the P2P mode
     * @ingroup		P2P
     */
  class ptp
  {
  public:
    /**@par	Description
	 *     	This api allows to get P2P TX Power(5-22) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.ptp.get()
	 *
	 * @return	The Tx power for P2P mode
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lorawan.ptp.get());

           delay(1000);
       }

           @endverbatim
	 */
    uint8_t get();

    /**@par	Description
	 *     	This api allows to set P2P TX Power(5-22) Note:This API will be deleted in the future
	 *
	 * @par	Syntax
	 *	api.lorawan.ptp.set(value)
	 * @param	value	the P2P Tx power
   * @return	bool
	 * @retval	TRUE for setting P2P Tx power success
	 * @retval	FALSE for setting P2P Tx power failure
	 * @par         Example
         * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P mode tx power = %d\r\n", api.lorawan.ptp.get());

           delay(1000);
       }

           @endverbatim
	 */
    bool set(uint8_t value);
  };

  /**@par	Description
     *          This API is used to enter P2P RX mode for a specified period.
     *
     * @ingroup	P2P
     * @par	Syntax
     *      	api.lorawan.precv(uint32_t timeout)
     *
     * @param	timeout		the duration of P2P Rx mode in milli-seconds, except the following magic input:
     *                          - 65535: Stay in RX mode until a packet is received.
     *                          - 65534: Stay in RX mode until api.lorawan.precv(0) is called.
     *                          - 65533: Stay in RX mode, but still can do TX without calling api.lorawan.precv(0).
     * @return	bool
     * @retval	TRUE for entering P2P Rx mode success
     * @retval	FALSE for entering P2P Rx mode failure
     * @par         Example
     * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.println("P2P Start");
         
           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(5000) ? "Success" : "Fail");
	   
           delay(6000);
       }

           @endverbatim
     */
  bool precv(uint32_t timeout);

  //instance
  rety rety;
  appeui appeui;
  appkey appkey;
  appskey appskey;
  daddr daddr;
  deui deui;
  netid netid;
  nwkskey nwkskey;
  cfm cfm;
  cfs cfs;
  njm njm;
  njs njs;
  adr adr;
  deviceClass deviceClass;
  dcs dcs;
  dr dr;
  jn1dl jn1dl;
  jn2dl jn2dl;
  pnm pnm;
  rx1dl rx1dl;
  rx2dl rx2dl;
  rx2dr rx2dr;
  rx2fq rx2fq;
  txp txp;
  pgslot pgslot;
  bfreq bfreq;
  btime btime;
  bgw bgw;
  rssi rssi;
  snr snr;
  ltime ltime;
  ver ver;
  mask mask;
  band band;
  linkcheck linkcheck;
  nwm nwm;
  pfreq pfreq;
  psf psf;
  pbw pbw;
  pcr pcr;
  ppl ppl;
  ptp ptp;

  /**@par	Description
     * 		This api provides the way to P2P send data
     *   
     * @ingroup	P2P
     * @par	Syntax
     *  	api.lorawan.psend(length, payload)
     *
     * @param   length		the length of the payload
     * @param   payload		the data send to the other device
     * @return	bool
     * @retval	TRUE for sending data success
     * @retval	FALSE for sending data failure
     * @par         Example
     * @verbatim
       void setup()
       {
           Serial.begin(115200);

           Serial.println("P2P Start");

           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
       }

       void loop()
       {
           uint8_t payload[] = "payload";
           Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail"); 

           delay(5000);
       }

           @endverbatim
     */
  bool psend(uint8_t length, uint8_t *payload);

  /**@par	Description
     *		This api configures P2P mode encryption
     * @ingroup		P2P
     */
  class encry
  {
  public:
    /**@par	Description
	 *     	This api allows to get the status of P2P mode encryption
	 *
	 * @par	Syntax
	 *	api.lorawan.encry.get()
   * @return	bool
	 * @retval	TRUE  : P2P mode encryption is enable
	 * @retval	FALSE : P2P mode encryption is disable
	 * @par         Example
         * @verbatim
       long startTime;
       uint8_t node_encrypt_key[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t encrypt_buff[8];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption status %s\r\n", api.lorawan.encry.set(1) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lorawan.enckey.set(node_encrypt_key, 8) ? "Success" : "Fail");
	   
           Serial.printf("P2P encryption status = %s\r\n", api.lorawan.encry.get() ? "Enbale" : "Disable");

	   api.lorawan.enckey.get(encrypt_buff, 8);
	   Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 8 ; i++) {
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
             Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }

           @endverbatim
	 */
    bool get();

    /**@par	Description
	 *     	This api allows to enable or disable P2P mode encryption
	 *
	 * @par	Syntax
	 *	api.lorawan.encry.set(value)
	 *
	 * @param	value	the status of P2P mode encryption
   * @return	bool
	 * @retval	TRUE  : for Setting status of encryption success
	 * @retval	FALSE : for setting status of encryption failure
	 * @par         Example
         * @verbatim
       long startTime;
       uint8_t node_encrypt_key[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t encrypt_buff[8];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption status %s\r\n", api.lorawan.encry.set(1) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lorawan.enckey.set(node_encrypt_key, 8) ? "Success" : "Fail");
	   
           Serial.printf("P2P encryption status = %s\r\n", api.lorawan.encry.get() ? "Enbale" : "Disable");

	   api.lorawan.enckey.get(encrypt_buff, 8);
	   Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 8 ; i++) {
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
             Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }
       }
         @endverbatim
	 */
    bool set(bool value);
  };

  /**@par	Description
     *		This api will encrypt the date being sent and received
     * @ingroup		P2P
     */
  class enckey
  {
  public:
    /**@par	Description
	 *     	This api allows to get the key of P2P mode encryption
	 *
	 * @par	Syntax
	 *	api.lorawan.enckey.get(buff, len)
	 *
         * @param       buff	the buffer to store encryption key
         * @param       len	the length of encryption key(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for getting encryption key success
	 * @retval	FALSE for getting encryption key failure
	 * @par         Example
         * @verbatim
       long startTime;
       uint8_t node_encrypt_key[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t encrypt_buff[8];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption status %s\r\n", api.lorawan.encry.set(1) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lorawan.enckey.set(node_encrypt_key, 8) ? "Success" : "Fail");
	   
           Serial.printf("P2P encryption status = %s\r\n", api.lorawan.encry.get() ? "Enbale" : "Disable");

	   api.lorawan.enckey.get(encrypt_buff, 8);
	   Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 8 ; i++) {
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
             Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
	 */
    bool get(uint8_t *buff, uint32_t len);

    /**@par	Description
	 *     	This api allows to set the key of P2P mode encryption
	 *
	 * @par	Syntax
	 *	api.lorawan.enckey.set(buff, len)
	 *
         * @param       buff	the buffer to set encryption key
         * @param       len	the length of encryption key(must be 8 bytes)
   * @return	bool
	 * @retval	TRUE for setting encryption key success
	 * @retval	FALSE for setting encryption failure
	 * @par         Example
         * @verbatim
       long startTime;
       uint8_t node_encrypt_key[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t encrypt_buff[8];
       
       void setup()
       {
           Serial.begin(115200);
           startTime = millis();
         
           Serial.println("P2P Start");
           
           Serial.printf("Set Node device work mode %s\r\n", api.lorawan.nwm.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode frequency %s\r\n", api.lorawan.pfreq.set(868000000) ? "Success" : "Fail");
           Serial.printf("Set P2P mode spreading factor %s\r\n", api.lorawan.psf.set(12) ? "Success" : "Fail");
           Serial.printf("Set P2P mode bandwidth %s\r\n", api.lorawan.pbw.set(125) ? "Success" : "Fail");
           Serial.printf("Set P2P mode code rate %s\r\n", api.lorawan.pcr.set(0) ? "Success" : "Fail");
           Serial.printf("Set P2P mode preamble length %s\r\n", api.lorawan.ppl.set(8) ? "Success" : "Fail");
           Serial.printf("Set P2P mode tx power %s\r\n", api.lorawan.ptp.set(22) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption status %s\r\n", api.lorawan.encry.set(1) ? "Success" : "Fail");
	   Serial.printf("Set P2P mode encryption Key %s\r\n\r\n", api.lorawan.enckey.set(node_encrypt_key, 8) ? "Success" : "Fail");
	   
           Serial.printf("P2P encryption status = %s\r\n", api.lorawan.encry.get() ? "Enbale" : "Disable");

	   api.lorawan.enckey.get(encrypt_buff, 8);
	   Serial.printf("P2P encryption Key = 0x");
           for (int i = 0 ; i < 8 ; i++) {
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
             Serial.printf("P2P set Rx mode %s\r\n",api.lorawan.precv(rxDelay) ? "Success" : "Fail");
             delay(rxDelay);
           } else {
           
             Serial.printf("P2P send %s\r\n", api.lorawan.psend(sizeof(payload), payload)? "Success" : "Fail");
             delay(1000);
           }

       }
         @endverbatim
	 */
    bool set(uint8_t *buff, uint32_t len);
  };

  encry encry;
  enckey enckey;

  /**@par	Description
     *		This api configures the P2P FSK modem bitrate (600b/s-307200b/s)
     * @ingroup		P2P
     */
  class pbr
  {
  public:
    /**@par	Description
	 *     	This api allows to get the P2P FSK modem bitrate (600b/s-307200b/s)
	 *
	 * @par	Syntax
	 *	api.lorawan.pbr.get()
	 *
   * @return The P2P FSK modem bitrate
	 */
    uint32_t get();

    /**@par	Description
	 *     	This api allows to set the P2P FSK modem bitrate (600b/s-307200b/s)
	 *
	 * @par	Syntax
	 *	api.lorawan.pbr.set(value)
	 *
         * @param       value
	 * @return	
	 */
    bool set(uint32_t value);
  };

  /**@par	Description
     *		This api configures the P2P FSK modem frequency deviation
     * @ingroup		P2P
     */
  class pfdev
  {
  public:
    /**@par	Description
	 *     	This api allows to get the P2P FSK modem frequency deviation
	 *
	 * @par	Syntax
	 *	api.lorawan.pfdev.get()
	 *
	 * @return	The P2P FSK modem frequency deviation
	 */
    uint32_t get();

    /**@par	Description
	 *     	This api allows to set the P2P FSK modem frequency deviation
	 *
	 * @par	Syntax
	 *	api.lorawan.pfdev.set(value)
	 *
         * @param       value
	 * @return	
	 */
    bool set(uint32_t value);
  };

  pbr pbr;
  pfdev pfdev;

  /**@par	Description
     * 		This command adds a new multicast group configure multicast parameters
     * @ingroup	Multicast
     * @par	Syntax
     * 		api.lorawan.addmulc(session)
     * @param	session		The structure of session
     * @return	bool
     * @retval	TRUE for adding multicast group success
     * @retval	FALSE for adding multicast group failure
     * @par	Example
     * @verbatim
       void setup()
       {
         Serial.begin(115200);
       
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x88};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x0E};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E};
       
       
       
       //LoRaWan Multicast Session
       
       uint8_t node_mc_address[4] = {0x01, 0x02, 0x03, 0x04};
       uint8_t node_mc_AppSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t node_mc_NwkSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       
       RAK_LORA_McSession session = {
           .McDevclass = 2,
           .McAddress = node_mc_address[0]<<24 | node_mc_address[1]<<16 | node_mc_address[2]<<8 | node_mc_address[3],
           .McFrequency = 869525000,
           .McDatarate = 0,
           .McPeriodicity = 0,
           .McGroupID = 2,
           .entry = 0,
       };
         memcpy(session.McAppSKey, node_mc_AppSKey, 16);
         memcpy(session.McNwkSKey, node_mc_NwkSKey, 16);
       
         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);
          
         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.deviceClass.set(2);
         api.lorawan.join();
       
         //Wait for Join success 
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
       
         api.lorawan.adr.set(true);
         api.lorawan.rety.set(1);
         api.lorawan.cfm.set(1);
       
         //LoRaWAN Multicast Setting
         if(api.lorawan.addmulc(session) == true) {
           Serial.println("Add Multicast Success");
         } else {
           Serial.println("Add Multicast Fail");
         }
         
       }
       
       void loop()
       {
       
       }
       @endverbatim
     */
  bool addmulc(RAK_LORA_McSession session);

  /**@par	Description
     * 		This command allows the removal of a configured multicast group
     * @ingroup	Multicast
     * @par	Syntax
     * 		api.lorawan.rmvmulc(devAddr)
     *
     * @param	devAddr		the address to remvoe a multicast group
     * @return	bool
     * @retval	TRUE for removing success
     * @retval	FALSE for removing failure
     * @par	Example
     * @verbatim
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x88};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x0E};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E};
       
       //LoRaWan Multicast Session
       uint8_t node_mc_address[4] = {0x01, 0x02, 0x03, 0x04};
       uint8_t node_mc_AppSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t node_mc_NwkSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       

       void setup()
       {
         Serial.begin(115200);
       
         RAK_LORA_McSession session = {
             .McDevclass = 2,
             .McAddress = node_mc_address[0]<<24 | node_mc_address[1]<<16 | node_mc_address[2]<<8 | node_mc_address[3],
             .McFrequency = 869525000,
             .McDatarate = 0,
             .McPeriodicity = 0,
             .McGroupID = 2,
             .entry = 0,
         };
         memcpy(session.McAppSKey, node_mc_AppSKey, 16);
         memcpy(session.McNwkSKey, node_mc_NwkSKey, 16);
       
         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);
          
         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.deviceClass.set(2);
         api.lorawan.join();
       
         //Wait for Join success 
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
       
         api.lorawan.adr.set(true);
         api.lorawan.rety.set(1);
         api.lorawan.cfm.set(1);
       
         //LoRaWAN Multicast Setting
         if(api.lorawan.addmulc(session) == true) {
           Serial.println("Add Multicast Success");
         } else {
           Serial.println("Add Multicast Fail");
         }
         
       }
       
       void loop()
       {
         if(millis() > 100000) {
            Serial.printf("Remove a multicast group %s\r\n", api.lorawan.rmvmulc(node_mc_address[0]<<24 | node_mc_address[1]<<16 | node_mc_address[2]<<8 | node_mc_address[3]));
          } 
       }
       @endverbatim
     */
  bool rmvmulc(uint32_t devAddr);

  /**@par	Description
     * 		This command can view current configured multicast group information
     * @ingroup	Multicast
     * @par	Syntax
     *		api.lorawan.lstmulc(&multicast_list)
     *
     * @param	multicast_list 	a RAK_LORA_McSession variable
     * @return	bool
     * @retval	TRUE for getting multicast list success
     * @retval	FALSE for getting multicast failure
     * @par	Example
     * @verbatim
       void setup()
       {
         Serial.begin(115200);
       
       // OTAA Device EUI MSB
       uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x88};
       // OTAA Application EUI MSB
       uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x0E};
       // OTAA Application Key MSB
       uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3E};
       
       
       
       //LoRaWan Multicast Session
       
       uint8_t node_mc_address[4] = {0x01, 0x02, 0x03, 0x04};
       uint8_t node_mc_AppSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       uint8_t node_mc_NwkSKey[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
       
       RAK_LORA_McSession session = {
           .McDevclass = 2,
           .McAddress = node_mc_address[0]<<24 | node_mc_address[1]<<16 | node_mc_address[2]<<8 | node_mc_address[3],
           .McFrequency = 869525000,
           .McDatarate = 0,
           .McPeriodicity = 0,
           .McGroupID = 2,
           .entry = 0,
       };
         memcpy(session.McAppSKey, node_mc_AppSKey, 16);
         memcpy(session.McNwkSKey, node_mc_NwkSKey, 16);
       
         api.lorawan.appeui.set(node_app_eui, 8);
         api.lorawan.appkey.set(node_app_key, 16);
         api.lorawan.deui.set(node_device_eui, 8);
          
         api.lorawan.band.set(4);
         api.lorawan.njm.set(1);
         api.lorawan.deviceClass.set(2);
         api.lorawan.join();
       
         //Wait for Join success 
         while (api.lorawan.njs.get() == 0)
         {
           Serial.print("Waiting for Lorawan join...");
           api.lorawan.join();
           delay(10000);
         }
       
         api.lorawan.adr.set(true);
         api.lorawan.rety.set(1);
         api.lorawan.cfm.set(1);
       
         //LoRaWAN Multicast Setting
         if(api.lorawan.addmulc(session) == true) {
           Serial.println("Add Multicast Success");
         } else {
           Serial.println("Add Multicast Fail");
         }
         
       }
       
       void loop()
       {
         RAK_LORA_McSession multicast_list;

         Serial.println("Get all multicast groups");
         while (api.lorawan.lstmulc(&multicast_list) == true) {
           if (multicast_list.McDevclass != 0) {
             Serial.printf("Device class = %d\r\n", multicast_list.McDevclass);
             Serial.printf("Device address = %08X\r\n", multicast_list.McAddress);
       
             Serial.print("Multicast AppSKey = 0x");
             for (int i=0; i<16; i++) {
               Serial.printf("%02X", multicast_list.McAppSKey[i]);
             }
             Serial.println("");
       
             Serial.print("Multicast NwkSKey = 0x");
             for (int i=0; i<16; i++) {
               Serial.printf("%02X", multicast_list.McNwkSKey[i]);
             }
             Serial.println("");
       
             Serial.printf("Frequency = %d\r\n", multicast_list.McFrequency);
             Serial.printf("Data rate = %d\r\n", multicast_list.McDatarate);
             Serial.printf("Periodicity = %d\r\n", multicast_list.McPeriodicity);
             Serial.printf("Group ID = %d\r\n", multicast_list.McGroupID);
             Serial.printf("Entry = %d\r\n", multicast_list.entry);
           }
         }
       
         delay(5000);
       
       }
       
       @endverbatim
     */
  bool lstmulc(RAK_LORA_McSession *iterator);

  /**@par	Description
     * 		This command can access all open channel rssi
     * @ingroup	Information
     * @par	Syntax
     * 		api.lorawan.arssi(chan_arssi)
     *
     * @param	chan_arssi	the struture array to store arssi
     * @return	bool
     * @retval	TRUE for getting arssi success
     * @retval	FALSE for getting arssi failure
     * @par	Example
     * @verbatim
     // OTAA Device EUI MSB
     uint8_t node_device_eui[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
     // OTAA Application EUI MSB
     uint8_t node_app_eui[8] = {0x0E, 0x0D, 0x0D, 0x01, 0x0E, 0x01, 0x02, 0x03};
     // OTAA Application Key MSB
     uint8_t node_app_key[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
          
     void setup()
     {
       Serial.begin(115200);
     
       api.lorawan.appeui.set(node_app_eui, 8);
       api.lorawan.appkey.set(node_app_key, 16);
       api.lorawan.deui.set(node_device_eui, 8);
       api.lorawan.band.set(4);
     
       api.lorawan.njm.set(1);
       api.lorawan.join();
       
       //Wait for Join success
       while (api.lorawan.njs.get() == 0)
       {
         Serial.print("Waiting for Lorawan join...");
         api.lorawan.join();
         delay(10000);
       }
     }
     
     void loop()
     {
       RAK_LORA_chan_rssi chan_arssi;
     
       Serial.print("Get All open channel RSSI =");
       while (api.lorawan.arssi(&chan_arssi) == true) {
         if (chan_arssi.mask != 0) {
           Serial.printf("channel : %d,mask : %d, rssi : %d\r\n", chan_arssi.chan, chan_arssi.mask, chan_arssi.rssi);
         }
       }
       Serial.print("\r\n");

       delay(5000);
     } 
       @endverbatim
     */
  bool arssi(RAK_LORA_chan_rssi *iterator);
};

#endif

#endif //end lorawan.h

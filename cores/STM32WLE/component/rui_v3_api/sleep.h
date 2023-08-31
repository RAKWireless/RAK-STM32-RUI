/**@file	sleep.h
 *
 * @brief	The c++ wrapper for sleep functions
 * @author	RAKwireless
 * @version	0.0.0
 * @date	2021.5
 */
#ifndef __SLEEP_H_
#define __SLEEP_H_

#include "udrv_powersave.h"
#include "udrv_gpio.h"
#include "udrv_system.h"
#include "udrv_rtc.h"
#include "service_nvm.h"
#include "udrv_errno.h"

/**@addtogroup	RUI_System_Data_Type
 * @{
 */

/**@par Description
 *      modes that trigger the device when sleeping
 */
typedef enum
{
  RUI_WAKEUP_RISING_EDGE,	///< Trigger wakeup during rising edge.
  RUI_WAKEUP_FALLING_EDGE,	///< Trigger wakeup during falling edge.
} RUI_WAKEUP_TRIGGER_MODE;

/**@}*/

class sleep {
  public:
  sleep();

  /**@par	Description
   *    	Sleep the cpu
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.cpu();
   * @param   	ms_time(optional) Duration for cpu to sleep. No parameter means sleeping until the next interrupt.
   * @retval  	void
   * @par 	Example
   * @verbatim	
     void setup()
     {
     }

     void loop()
     {
       api.system.sleep.cpu(1000); 
     }
     @endverbatim	
   */
  void cpu(int ms_time);
  void cpu(uint32_t ms_time);
  void cpu();

#ifdef SUPPORT_LORA
  void lora(uint32_t ms_time);

  /**@par	Description
   *    	Sleep lora.
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.lora();
   * @param   ms_time(optional)	Duration for lora to sleep
   * @retval  void
   * @par       Example
   * @verbatim
     void setup()
     {
     }

     void loop()
     {
       api.system.sleep.lora(1000);
     }
     @endverbatim
   */
  void lora(int ms_time);
#endif

  /**@par	Description
   *      	Sleep all component.
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.all();
   * @param   ms_time(optional)	Duration for all component to sleep. No parameter means sleeping until the next interrupt.
   * @retval  void
   * @par       Example
   * @verbatim
     void setup()
     {
     }

     void loop()
     {
       api.system.sleep.all(1000);
     }
     @endverbatim
   */
  void all(int ms_time);
  void all(uint32_t ms_time);
  void all();

  /**@par	Description
   *	        Setup the sleep function
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.setup(mode);
   * @param  	mode 		This decide to use Rising or Falling trigger mode
   * @param  	pin		This is the pin to be chosen as the wakeup source
   *
   * @retval void
   * @par       Example
   * @verbatim
     void setup()
     {
       api.system.sleep.setup(RUI_WAKEUP_FALLING_EDGE);
     }

     void loop()
     {
       api.system.sleep.all(1000);
     }
     @endverbatim
   */
  void setup(RUI_WAKEUP_TRIGGER_MODE mode, uint32_t pin);
};

/**@par	Description
   * 		This api gets or sets the low power mode
   * @ingroup		Powersave
   */
class lpm
{
public:
  /**@par	Description
       *     	This api allows to get the low power mode
       *
       * @par	Syntax
       *	api.system.lpm.get()
       * @retval	1 for low power mode enabled
       * @retval	0 for low power mode disabled
       * @par         Example
       * @verbatim
     void setup()
     {
         Serial.begin(115200);

         Serial.printf("Set the low power mode %s\n\r", api.system.lpm.set(1) ? "Success" : "Fail");
     }

     void loop()
     {
         Serial.printf("The low power mode = %d\n\r", api.system.lpm.get());

         delay(1000);
     }

         @endverbatim
       */
  uint8_t get();

  /**@par	Description
       *     	This api allows to set the low power mode
       *
       * @par	Syntax
       *	api.system.lpm.set(value)
       *
       * @note	Only 0 or 1 is acceptable
       * @param	value	0 or 1
 * @return	bool
       * @retval	TRUE for setting low power mode success
       * @retval	FALSE for setting low power mode failure
       * @par         Example
       * @verbatim
     void setup()
     {
         Serial.begin(115200);

         Serial.printf("Set the low power mode %s\n\r", api.system.lpm.set(1) ? "Success" : "Fail");
     }

     void loop()
     {
         Serial.printf("The low power mode = %d\n\r", api.system.lpm.get());

         delay(1000);
     }

         @endverbatim
       */
  bool set(uint8_t value);
};

#endif

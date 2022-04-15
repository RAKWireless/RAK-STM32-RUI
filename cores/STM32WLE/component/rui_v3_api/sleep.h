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

/**@addtogroup	RUI_System_Data_Type
 * @{
 */

/**@par Description
 *      modes that trigger the device when sleeping
 */
typedef enum
{
  RUI_WAKEUP_RISING_EDGE,	///< Trigger device when rising.
  RUI_WAKEUP_FALLING_EDGE,	///< Trigger device when falling.
} RUI_WAKEUP_TRIGGER_MODE;

/**@}*/

class sleep {
  public:
  sleep();

  void cpu(uint32_t ms_time);

  /**@par	Description
   *    	Sleep the cpu with default no timeout
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.cpu();
   * @param   	ms_time(optional) Duration for cpu to sleep(default = no timeout)
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
  void cpu(int ms_time = POWERSAVE_NO_TIMEOUT);

  void lora(uint32_t ms_time);

  /**@par	Description
   *    	Sleep lora with default no timeout.
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.lora();
   * @param   ms_time(optional)	Duration for lora to sleep(default = no timeout)
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
  void lora(int ms_time = POWERSAVE_NO_TIMEOUT);

  void all(uint32_t ms_time);

  /**@par	Description
   *      	Sleep all component with default no timeout.
   * @ingroup	Powersave
   * @par	Syntax
   *      	api.system.sleep.all();
   * @param   ms_time(optional)	Duration for all component to sleep(default = no timeout)	
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
  void all(int ms_time = POWERSAVE_NO_TIMEOUT);

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
#endif

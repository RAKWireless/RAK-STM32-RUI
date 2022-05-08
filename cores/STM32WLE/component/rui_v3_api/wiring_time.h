#ifndef __WIRING_TIME_H__
#define __WIRING_TIME_H__

#include "udrv_delay.h"

/**@addtogroup	Time
 * @{ */
/**@par	Description
 *     	Pauses the program for the amount of time (in milliseconds) specified as parameter.
 * 	        (There are 1000 milliseconds in a second.)
 * @par	Syntax
 *	delay(ms);
 * @param	ms	the number of milliseconds to pause 	        
 * @par     Example
 * @verbatim
   unsigned long myTime;

   void setup() {
     Serial.begin(115200);
   }
   void loop() {
     Serial.print("Time: ");
     myTime = millis();
   
     Serial.println(myTime); // prints time since program started
     delay(1000);          // wait a second so as not to send massive amounts of data
   }
   @endverbatim
 */
#define delay udrv_app_delay_ms

/**@par	Description
 *     	Pauses the program for the amount of time (in microseconds) specified by 
 * 		the parameter. There are a thousand microseconds in a millisecond and a 
 * 		million microseconds in a second
 * @par	Syntax
 *	delayMicroseconds(us);
 * @param	us 	the number of microseconds to pause
 * @par     Example
 * @verbatim
   unsigned long time;

   void setup() {
     Serial.begin(115200);
   }
   void loop() {
     Serial.print("Time: ");
     time = micros();
   
     Serial.println(time); //prints time since program started
     delayMircoseconds(1000);          // wait a second so as not to send massive amounts of data
   }
   @endverbatim
 */
#define delayMicroseconds udrv_app_delay_us 

/**@par	Description
 *      	Returns the number of milliseconds passed since the device began
 * 		running the current program
 * @par	Syntax
 *	micros();
 * @return	Number of milliseconds passed since the program started(Type: unsigned long)
 * @par     Example
 * @verbatim
   unsigned long myTime;

   void setup() {
     Serial.begin(115200);
   }
   void loop() {
     Serial.print("Time: ");
     myTime = millis();
   
     Serial.println(myTime); // prints time since program started
     delay(1000);          // wait a second so as not to send massive amounts of data
   }
   @endverbatim
 */
unsigned long millis();

/**@par	Description
 *     	Returns the number of microseconds since the device  began 
 * 		running the current program
 * @par	Syntax
 *	millis();
 * @return	the number of microseconds since the device began running the current program(Type: unsigned long)
 * @par     Example
 * @verbatim
   unsigned long time;

   void setup() {
     Serial.begin(115200);
   }
   void loop() {
     Serial.print("Time: ");
     time = micros();
   
     Serial.println(time); //prints time since program started
     delayMircoseconds(1000);          // wait a second so as not to send massive amounts of data
   }
   @endverbatim
 */
unsigned long micros();

#endif // __WIRING_TIME_H__

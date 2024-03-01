/**@file    wdt.h 
 * 
 * @brief   The C++ wrapper for watch dog functions
 * @author  RAKwireless
 * @version 0.0.0
 * @data    2022.9
 */

#ifndef __WDT_H__
#define __WDT_H__

#include "udrv_wdt.h"

class wdt {
  private:
  public:
    wdt();

    /**@addtogroup  Watchdog
     * @{
     */
    /**@par Description
     *          Initialize the watchdog
     * @par Syntax
     *          api.system.wdt.enable();
     * @param   reload_value        Setting the reload value, Units:milliseconds
     * @return  void
     * @par     Example
     * @verbatim
       void setup() {
         api.system.wdt.enable(10000); //10 seconds for watchdog to feed, otherwise reset occurs.
       }

       void loop() {
         api.system.wdt.feed();
       }
       @endverbatim
     */
    void enable(int reload_value);
    /**@addtogroup  Watchdog
     * @{
     */
    /**@par Description
     *          Feed the watchdog
     * @par Syntax
     *          api.system.wdt.feed();
     * @return  void
     * @par     Example
     * @verbatim
       void setup() {
         api.system.wdt.enable(10000);
       }

       void loop() {
         api.system.wdt.feed();
       }
       @endverbatim
     */
    void feed(void);

};

#endif // __WDT_H__


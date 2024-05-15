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
     * @param   reload_value        Setting the reload value, only accept following values: 15ms, 30ms, 60ms, 120ms, 250ms, 500ms, 1s, 2s, 4s, and 8s, Units:milliseconds
     * @return  void
     * @par     Example
     * @verbatim
       void setup() {
         api.system.wdt.enable(8000); //8 seconds for watchdog to feed, otherwise reset occurs.
       }

       void loop() {
         api.system.wdt.reset();
       }
       @endverbatim
     */
    void enable(int reload_value);
    /**@addtogroup  Watchdog
     * @{
     */
    /**@par Description
     *          Reset the watchdog Timer
     * @par Syntax
     *          api.system.wdt.reset();
     * @return  void
     * @par     Example
     * @verbatim
       void setup() {
         api.system.wdt.enable(8000);
       }

       void loop() {
         api.system.wdt.reset();
       }
       @endverbatim
     */
    void reset(void);

};

#endif // __WDT_H__


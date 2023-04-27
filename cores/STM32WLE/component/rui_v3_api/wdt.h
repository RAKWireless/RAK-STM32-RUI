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

    void enable(int reset_timer);
    void disable(void);
    void reset(void);

};

#endif // __WDT_H__


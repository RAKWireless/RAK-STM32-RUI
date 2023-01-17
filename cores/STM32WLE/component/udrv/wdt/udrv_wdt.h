#ifndef _UDRV_WDT_H_
#define _UDRV_WDT_H_

#ifdef __cplusplus
extern "C" {
#endif

void udrv_wdt_feed(void);

void udrv_wdt_init(void);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _UDRV_WDT_H_

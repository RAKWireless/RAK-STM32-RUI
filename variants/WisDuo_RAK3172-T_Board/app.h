#ifndef __APP_H__
#define __APP_H__

#include <stdint.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC void rui_setup();
EXTERNC void rui_loop();
EXTERNC void app_cli_handler(uint8_t ch);

#undef EXTERNC

#endif

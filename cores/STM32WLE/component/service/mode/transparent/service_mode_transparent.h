#ifndef __SERVICE_MODE_TRANSPARENT_H__
#define __SERVICE_MODE_TRANSPARENT_H__

#ifdef __cplusplus
extern "C" {
#endif

//standard libary include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "udrv_serial.h"

#define TP_BUFFER_SIZE   (512)

#define TP_ESCAPE_CHAR '+'

typedef enum _TP_STATE{
    TP_STATE_DEFAULT = 0,          /* the last char is not the escape char */
    TP_STATE_PREPARE_1 = 1,        /* the last char is the escape char */
    TP_STATE_PREPARE_2 = 2,        /* the last two chars are successive two escape chars */
    TP_STATE_MAX = 3,
}TP_STATE;

typedef enum _TP_EVENT{
    TP_EVENT_RECV_A_NORMAL_CHAR = 0,
    TP_EVENT_RECV_A_ESCAPE_CHAR = 1,
    TP_EVENT_MAX = 2,
}TP_EVENT;

typedef TP_STATE (*tp_event_handler)(SERIAL_PORT port, TP_STATE state, uint8_t ch);

void service_mode_transparent_handler(SERIAL_PORT port, uint8_t ch);
void service_mode_transparent_init(SERIAL_PORT port);
void service_mode_transparent_deinit(SERIAL_PORT port);

#ifdef __cplusplus
}
#endif

#endif /* __SERVICE_MODE_TRANSPARENT_H__ */


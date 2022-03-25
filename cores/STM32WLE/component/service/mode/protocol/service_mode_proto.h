#ifndef __SERVICE_MODE_PROTO_H__
#define __SERVICE_MODE_PROTO_H__

#ifdef __cplusplus
extern "C" {
#endif

//standard libary include
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "udrv_serial.h"

//#define PROTO_BUFFER_SIZE          (65536)
#define PROTO_BUFFER_SIZE          (256)//FIXME: (65536 is too big for RAM consumption!)
#define PROTO_START_DELIMITER      0x7E
#define PROTO_UPPER_LAYER_NUM_MAX  256

#define PROTO_PKT_TIMEOUT          (3000)

#define PROTO_USE_POPCOUNT_CHKSUM

typedef void (*SERVICE_MODE_PROTOCOL_HANDLER) (int, uint8_t *, uint16_t);

typedef struct _proto_upper_layer_info
{
    SERVICE_MODE_PROTOCOL_HANDLER request_handler;
    SERVICE_MODE_PROTOCOL_HANDLER response_handler;
} proto_upper_layer_info;

typedef enum _PROTO_STATE{
    PROTO_STATE_DEFAULT = 0,
    PROTO_STATE_RECV_DELIMITER = 1,
    PROTO_STATE_RECV_LEN_1 = 2,
    PROTO_STATE_RECV_LEN_2 = 3,
    PROTO_STATE_RECV_FRAME_TYPE = 4,
    PROTO_STATE_RECV_FLAG = 5,
    PROTO_STATE_RECV_PAYLOAD = 6,
#ifdef PROTO_USE_POPCOUNT_CHKSUM
    PROTO_STATE_RECV_CHKSUM = 7,
#else
    PROTO_STATE_RECV_CRC_1 = 8,
    PROTO_STATE_RECV_CRC_2 = 9,
    PROTO_STATE_RECV_CRC_3 = 10,
    PROTO_STATE_RECV_CRC_4 = 11,
#endif
    PROTO_STATE_CRC_ERROR = 12,
    PROTO_STATE_MAX = 13,
}PROTO_STATE;

typedef enum _PROTO_EVENT{
    PROTO_EVENT_RECV_A_NORMAL_CHAR = 0,
    PROTO_EVENT_RECV_THE_DELIMITER = 1,
    PROTO_EVENT_MAX = 2,
}PROTO_EVENT;

typedef PROTO_STATE (*proto_event_handler)(SERIAL_PORT port, PROTO_STATE state, uint8_t ch);

#define PROTO_FLAG_RESPONSE           0x01

typedef struct proto_packet_header_{
    uint8_t start_delimiter;
    uint16_t length;
    uint8_t frame_type;
    uint8_t flag;
} __attribute__ ((packed)) proto_packet_header;

typedef struct proto_packet_tailer_{
#ifdef PROTO_USE_POPCOUNT_CHKSUM
    uint8_t chksum;
#else
    uint32_t crc;
#endif
} __attribute__ ((packed)) proto_packet_tailer;

void service_mode_proto_recv(SERIAL_PORT port, uint8_t ch);
void service_mode_proto_send(SERIAL_PORT port, uint8_t flag, uint8_t frame_type, uint8_t *payload, uint16_t length, SERVICE_MODE_PROTOCOL_HANDLER response_handler);
int32_t service_mode_proto_register(uint8_t frame_type, SERVICE_MODE_PROTOCOL_HANDLER request_handler);
int32_t service_mode_proto_deregister(uint8_t frame_type);
void service_mode_proto_init(SERIAL_PORT port);
void service_mode_proto_deinit(SERIAL_PORT port);

#ifdef __cplusplus
}
#endif

#endif /* __SERVICE_MODE_PROTO_H__ */


#include <stdint.h>
#include "service_mode_proto.h"
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_rtc.h"
#include "service_mode.h"
#include "service_mode_proto_builtin_handler.h"
//#include "nrf_log.h"

typedef struct _proto_arrived_packet_info
{
    uint64_t last_recv_time;
    SERIAL_PORT port;
    PROTO_STATE curr_state;
#ifdef PROTO_USE_POPCOUNT_CHKSUM
    uint8_t chksum;
#else
    uint32_t crc32;
#endif
    uint32_t sgCurPos;
    uint16_t len;
    uint8_t flag;
    uint8_t frame_type;
    char sgProtoBuffer[PROTO_BUFFER_SIZE+1];
} proto_arrived_packet_info;

static proto_arrived_packet_info arrived_pkt_info[SERIAL_MAX];

static proto_upper_layer_info proto_upper_layer_table[PROTO_UPPER_LAYER_NUM_MAX];

static uint32_t proto_wlock_cnt[SERIAL_MAX];

static void proto_wake_lock(SERIAL_PORT port) {
    udrv_powersave_wake_lock();
    proto_wlock_cnt[port]++;
}

static void proto_wake_unlock(SERIAL_PORT port) {
    if (proto_wlock_cnt > 0) {
        udrv_powersave_wake_unlock();
        proto_wlock_cnt[port]--;
    }
}

static void proto_wake_unlock_all(SERIAL_PORT port) {
    while (proto_wlock_cnt[port] > 0) {
        udrv_powersave_wake_unlock();
        proto_wlock_cnt[port]--;
    }
}

static void proto_rst_handler(void *p_context) {
    memset(((proto_arrived_packet_info *)p_context)->sgProtoBuffer, 0x00, PROTO_BUFFER_SIZE+1);
    ((proto_arrived_packet_info *)p_context)->sgCurPos = 0;
    ((proto_arrived_packet_info *)p_context)->curr_state = PROTO_STATE_DEFAULT;
    ((proto_arrived_packet_info *)p_context)->last_recv_time = 0;//Keep start time zero
    proto_wake_unlock_all(((proto_arrived_packet_info *)p_context)->port);
}

static PROTO_STATE proto_normal_handler(SERIAL_PORT port, PROTO_STATE state, uint8_t ch) {
    switch (state) {
        case PROTO_STATE_DEFAULT:
        {
            /* Discard this byte. */
            return PROTO_STATE_DEFAULT;
        }
        case PROTO_STATE_RECV_DELIMITER:
        {
            arrived_pkt_info[port].len = ((uint16_t)ch << 8) & 0xFF00;
            return PROTO_STATE_RECV_LEN_1;
        }
        case PROTO_STATE_RECV_LEN_1:
        {
            arrived_pkt_info[port].len = arrived_pkt_info[port].len | (((uint16_t)ch << 0) & 0x00FF);
            return PROTO_STATE_RECV_LEN_2;
        }
        case PROTO_STATE_RECV_LEN_2:
        {
            arrived_pkt_info[port].frame_type = ch;
            return PROTO_STATE_RECV_FRAME_TYPE;
        }
        case PROTO_STATE_RECV_FRAME_TYPE:
        {
            arrived_pkt_info[port].flag = ch;
            return PROTO_STATE_RECV_FLAG;
        }
        case PROTO_STATE_RECV_FLAG:
        {
            if (arrived_pkt_info[port].len > 0) {
                /* buffer the input char */
                if ( (PROTO_BUFFER_SIZE-1) > arrived_pkt_info[port].sgCurPos ) {
                    arrived_pkt_info[port].sgProtoBuffer[arrived_pkt_info[port].sgCurPos++] = ch;
                    arrived_pkt_info[port].sgProtoBuffer[arrived_pkt_info[port].sgCurPos] = 0x00;
                }
		if (--arrived_pkt_info[port].len == 0) {
                    /* payload receiving is finished */
                    return PROTO_STATE_RECV_PAYLOAD;
                } else {
                    /* payload receiving is not finished yet */
                    return state;
                }
            } else {
                /* there is no payload and this is the checksum */
#ifdef PROTO_USE_POPCOUNT_CHKSUM
                uint32_t calculatedCrc32 = 0;
                arrived_pkt_info[port].chksum = ch;

                calculatedCrc32 = __builtin_popcount(arrived_pkt_info[port].frame_type);
                calculatedCrc32 += __builtin_popcount(arrived_pkt_info[port].flag);
                for (int i = 0 ; i < arrived_pkt_info[port].sgCurPos ; i++) {
                    calculatedCrc32 += __builtin_popcount(arrived_pkt_info[port].sgProtoBuffer[i]);
                }
//NRF_LOG_ERROR("%s(): calculatedCrc32=0x%x", __func__, (uint8_t)calculatedCrc32);
//NRF_LOG_ERROR("%s(): crc32=0x%x", __func__, arrived_pkt_info[port].chksum);
                if (calculatedCrc32 == arrived_pkt_info[port].chksum) {
                    return PROTO_STATE_RECV_CHKSUM;
                } else {
                    return PROTO_STATE_CRC_ERROR;
                }
#else
                arrived_pkt_info[port].crc32 = ((uint32_t)ch << 24) & 0xFF000000;
                return PROTO_STATE_RECV_CRC_1;
#endif
            }
        }
        case PROTO_STATE_RECV_PAYLOAD:
        {
#ifdef PROTO_USE_POPCOUNT_CHKSUM
            uint32_t calculatedCrc32 = 0;
            arrived_pkt_info[port].chksum = ch;

            calculatedCrc32 = __builtin_popcount(arrived_pkt_info[port].frame_type);
            calculatedCrc32 += __builtin_popcount(arrived_pkt_info[port].flag);
            for (int i = 0 ; i < arrived_pkt_info[port].sgCurPos ; i++) {
                calculatedCrc32 += __builtin_popcount(arrived_pkt_info[port].sgProtoBuffer[i]);
            }
//NRF_LOG_ERROR("%s(): calculatedCrc32=0x%x", __func__, (uint8_t)calculatedCrc32);
//NRF_LOG_ERROR("%s(): crc32=0x%x", __func__, arrived_pkt_info[port].chksum);
            if ((uint8_t)calculatedCrc32 == arrived_pkt_info[port].chksum) {
                return PROTO_STATE_RECV_CHKSUM;
            } else {
                return PROTO_STATE_CRC_ERROR;
            }
#else
            arrived_pkt_info[port].crc32 = ((uint32_t)ch << 24) & 0xFF000000;
            return PROTO_STATE_RECV_CRC_1;
#endif
        }
#ifndef PROTO_USE_POPCOUNT_CHKSUM
        case PROTO_STATE_RECV_CRC_1:
        {
            arrived_pkt_info[port].crc32 = arrived_pkt_info[port].crc32 | (((uint32_t)ch << 16) & 0x00FF0000);
            return PROTO_STATE_RECV_CRC_2;
        }
        case PROTO_STATE_RECV_CRC_2:
        {
            arrived_pkt_info[port].crc32 = arrived_pkt_info[port].crc32 | (((uint32_t)ch << 8) & 0x0000FF00);
            return PROTO_STATE_RECV_CRC_3;
        }
        case PROTO_STATE_RECV_CRC_3:
        {
            uint32_t calculatedCrc32 = 0;
            arrived_pkt_info[port].crc32 = arrived_pkt_info[port].crc32 | (((uint32_t)ch << 0) & 0x000000FF);

            calculatedCrc32 = Crc32Init();
            calculatedCrc32 = Crc32Update(calculatedCrc32, &arrived_pkt_info[port].frame_type, 1);
            calculatedCrc32 = Crc32Update(calculatedCrc32, &arrived_pkt_info[port].flag, 1);
            calculatedCrc32 = Crc32Update(calculatedCrc32, arrived_pkt_info[port].sgProtoBuffer, arrived_pkt_info[port].sgCurPos);
            calculatedCrc32 = Crc32Finalize(calculatedCrc32);

//NRF_LOG_ERROR("%s(): calculatedCrc32=0x%x", __func__, calculatedCrc32);
//NRF_LOG_ERROR("%s(): crc32=0x%x", __func__, arrived_pkt_info[port].crc32);
            if (calculatedCrc32 == arrived_pkt_info[port].crc32) {
                return PROTO_STATE_RECV_CRC_4;
            } else {
                return PROTO_STATE_CRC_ERROR;
            }
        }
#endif
        default:
        {
            return state;
        }
    }
}

static PROTO_STATE proto_delimiter_handler(SERIAL_PORT port, PROTO_STATE state, uint8_t ch) {
    switch (state) {
        case PROTO_STATE_DEFAULT:
#ifdef PROTO_USE_POPCOUNT_CHKSUM
        case PROTO_STATE_RECV_CHKSUM:
#else
        case PROTO_STATE_RECV_CRC_4:
#endif
        case PROTO_STATE_CRC_ERROR:
        {
            arrived_pkt_info[port].sgCurPos = 0;//clear data buffer
            arrived_pkt_info[port].last_recv_time = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);//record start time!
            proto_wake_lock(port);
            return PROTO_STATE_RECV_DELIMITER;
        }
        default:
        {
            return state;
        }
    }
}

proto_event_handler proto_transitions[PROTO_STATE_MAX][PROTO_EVENT_MAX] = {
    [PROTO_STATE_DEFAULT]             = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_delimiter_handler,},
    [PROTO_STATE_RECV_DELIMITER]      = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_LEN_1]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_LEN_2]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_FRAME_TYPE]     = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_FLAG]           = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_PAYLOAD]        = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
#ifdef PROTO_USE_POPCOUNT_CHKSUM
    [PROTO_STATE_RECV_CHKSUM]         = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
#else
    [PROTO_STATE_RECV_CRC_1]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_CRC_2]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_CRC_3]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_normal_handler,},
    [PROTO_STATE_RECV_CRC_4]          = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_delimiter_handler,},
#endif
    [PROTO_STATE_CRC_ERROR]           = { [PROTO_EVENT_RECV_A_NORMAL_CHAR] = proto_normal_handler,
                                          [PROTO_EVENT_RECV_THE_DELIMITER] = proto_delimiter_handler,},
};

static PROTO_EVENT proto_ch2evt(uint8_t ch) {
    switch (ch) {
        case PROTO_START_DELIMITER:
        {
            return PROTO_EVENT_RECV_THE_DELIMITER;
        }
        default:
        {
            return PROTO_EVENT_RECV_A_NORMAL_CHAR;
        }
    }
}

void service_mode_proto_recv(SERIAL_PORT port, uint8_t ch) {
    proto_event_handler event_handler;

    if (arrived_pkt_info[port].last_recv_time != 0) {
        if ((udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT) - arrived_pkt_info[port].last_recv_time) > PROTO_PKT_TIMEOUT) {
            proto_rst_handler(&arrived_pkt_info[port]);//Timeout! Reset state machine!
        }
    }

    event_handler = proto_transitions[arrived_pkt_info[port].curr_state][proto_ch2evt(ch)];

    if (event_handler) {
        arrived_pkt_info[port].curr_state = event_handler(port, arrived_pkt_info[port].curr_state, ch);
#ifdef PROTO_USE_POPCOUNT_CHKSUM
        if (arrived_pkt_info[port].curr_state == PROTO_STATE_RECV_CHKSUM) {
#else
        if (arrived_pkt_info[port].curr_state == PROTO_STATE_RECV_CRC_4) {
#endif
            arrived_pkt_info[port].curr_state = PROTO_STATE_DEFAULT;
            arrived_pkt_info[port].last_recv_time = 0;//Whole process is finished. Erase start time.

            if (arrived_pkt_info[port].flag & PROTO_FLAG_RESPONSE) {//This is a response frame
                if (proto_upper_layer_table[arrived_pkt_info[port].frame_type].response_handler != NULL) {
                    proto_upper_layer_table[arrived_pkt_info[port].frame_type].response_handler(port, arrived_pkt_info[port].sgProtoBuffer, arrived_pkt_info[port].sgCurPos);
                }
            } else {//This is a request frame
                if (proto_upper_layer_table[arrived_pkt_info[port].frame_type].request_handler != NULL) {
                    proto_upper_layer_table[arrived_pkt_info[port].frame_type].request_handler(port, arrived_pkt_info[port].sgProtoBuffer, arrived_pkt_info[port].sgCurPos);
                }
            }
            proto_wake_unlock_all(port);
        }
    } else {
        arrived_pkt_info[port].sgCurPos = 0;//clear data buffer
        arrived_pkt_info[port].curr_state = PROTO_STATE_DEFAULT;
        proto_wake_unlock_all(port);
    }
}
#ifdef SUPPORT_BINARY
void service_mode_proto_send(SERIAL_PORT port, uint8_t flag, uint8_t frame_type, uint8_t *payload, uint16_t length, SERVICE_MODE_PROTOCOL_HANDLER response_handler) {
    proto_packet_header header;
    proto_packet_tailer tailer;
    uint32_t calculatedCrc32 = 0;
    SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm(port);

    if (mode != SERVICE_MODE_TYPE_PROTOCOL) {
        return;
    }

    header.start_delimiter = 0x7E;
    header.length = __builtin_bswap16(length);
    header.flag = flag;
    header.frame_type = frame_type;

#ifdef PROTO_USE_POPCOUNT_CHKSUM
    calculatedCrc32 += __builtin_popcount(frame_type);
    calculatedCrc32 += __builtin_popcount(flag);
    for (int i = 0 ; i < length ; i++) {
        calculatedCrc32 += __builtin_popcount(payload[i]);
    }
    tailer.chksum = (uint8_t)calculatedCrc32;
#else
    calculatedCrc32 = Crc32Init();
    calculatedCrc32 = Crc32Update(calculatedCrc32, &frame_type, 1);
    calculatedCrc32 = Crc32Update(calculatedCrc32, &flag, 1);
    calculatedCrc32 = Crc32Update(calculatedCrc32, payload, length);
    calculatedCrc32 = Crc32Finalize(calculatedCrc32);
    tailer.crc = __builtin_bswap32(calculatedCrc32);
#endif

    proto_upper_layer_table[frame_type].response_handler = response_handler;

//{
//for (int i = 0 ; i < sizeof(header) ; i++) {
//    NRF_LOG_ERROR("%s(): header=0x%02x", __func__, *(((uint8_t *)&header)+i));
//}
//
//for (int i = 0 ; i < length ; i++) {
//    NRF_LOG_ERROR("%s(): payload=0x%02x", __func__, *(payload+i));
//}
//
//for (int i = 0 ; i < sizeof(tailer) ; i++) {
//    NRF_LOG_ERROR("%s(): tailer=0x%02x", __func__, *(((uint8_t *)&tailer)+i));
//}
//}

    udrv_serial_write(port, &header, sizeof(header));
    udrv_serial_write(port, payload, length);
    udrv_serial_write(port, &tailer, sizeof(tailer));
}
#endif

int32_t service_mode_proto_register(uint8_t frame_type, SERVICE_MODE_PROTOCOL_HANDLER request_handler) {
    if (proto_upper_layer_table[frame_type].request_handler == NULL) {
        proto_upper_layer_table[frame_type].request_handler = request_handler;
        return UDRV_RETURN_OK;
    } else {
        return -UDRV_OCCUPIED;
    }
}

int32_t service_mode_proto_deregister(uint8_t frame_type) {
    proto_upper_layer_table[frame_type].request_handler = NULL;
    return UDRV_RETURN_OK;
}

void service_mode_proto_init(SERIAL_PORT port) {
    arrived_pkt_info[port].port = port;
    memset(arrived_pkt_info[port].sgProtoBuffer, 0x00, PROTO_BUFFER_SIZE+1);
    arrived_pkt_info[port].sgCurPos = 0;//clear data buffer
    arrived_pkt_info[port].curr_state = PROTO_STATE_DEFAULT;
    arrived_pkt_info[port].last_recv_time = 0;//Keep start time zero

    //Register built-in handler
    service_mode_proto_register(0x00, service_mode_proto_echo_request_handler);
    service_mode_proto_register(0x01, service_mode_proto_atcmd_request_handler);
}

void service_mode_proto_deinit(SERIAL_PORT port) {
}

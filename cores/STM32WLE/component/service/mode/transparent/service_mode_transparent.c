#if defined(SUPPORT_LORA) && defined(SUPPORT_PASSTHRU)
#include <stdint.h>
#include "service_mode_transparent.h"
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_timer.h"
#include "service_lora.h"
#include "service_mode.h"

static uint8_t tp_inst_cnt = 0;

typedef struct _tp_arrived_byte_stream_info
{
    SERIAL_PORT port;
    TP_STATE state;
    uint32_t sgCurPos;
    uint32_t no_nwk_cnt;
    char sgTpBuffer[TP_BUFFER_SIZE+1];
} tp_arrived_byte_stream_info;

static tp_arrived_byte_stream_info arrived_byte_stream_info[SERIAL_MAX];

static void lora_handler(void *p_context) {
    SERVICE_LORA_SEND_INFO info;
    int32_t ret;

    for (int i = 0 ; i < SERIAL_MAX ; i++) {
        if (service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i) != SERVICE_MODE_TYPE_TRANSPARENT) {
            continue;
        }

        if (arrived_byte_stream_info[(SERIAL_PORT)i].sgCurPos) {
            info.port = service_nvm_get_tp_port_from_nvm((SERIAL_PORT)i);
            info.retry_valid = false;
            info.confirm_valid = false;

            if ((ret = service_lora_send(arrived_byte_stream_info[(SERIAL_PORT)i].sgTpBuffer, arrived_byte_stream_info[(SERIAL_PORT)i].sgCurPos, info, false)) == UDRV_RETURN_OK) {
                memset(arrived_byte_stream_info[(SERIAL_PORT)i].sgTpBuffer, 0x00, TP_BUFFER_SIZE+1);
                arrived_byte_stream_info[(SERIAL_PORT)i].sgCurPos = 0;
                arrived_byte_stream_info[(SERIAL_PORT)i].no_nwk_cnt = 0;
            } else if (ret == -UDRV_NO_WAN_CONNECTION) {
                if (++(arrived_byte_stream_info[(SERIAL_PORT)i].no_nwk_cnt) > 5) {
                    /* escape now immediately */
                    service_mode_transparent_deinit((SERIAL_PORT)i);
                    service_mode_cli_init((SERIAL_PORT)i);
                    service_nvm_set_mode_type_to_nvm((SERIAL_PORT)i, SERVICE_MODE_TYPE_CLI);
                }
            }
        }
    }
}

static TP_STATE tp_normal_handler(SERIAL_PORT port, TP_STATE state, uint8_t ch) {
    /* buffer the input char */
    if ( (TP_BUFFER_SIZE-1) > arrived_byte_stream_info[port].sgCurPos ) {
        arrived_byte_stream_info[port].sgTpBuffer[(arrived_byte_stream_info[port].sgCurPos)++] = ch;
        arrived_byte_stream_info[port].sgTpBuffer[arrived_byte_stream_info[port].sgCurPos] = 0x00;
    }

    switch (ch) {
        case TP_ESCAPE_CHAR:
        {
            /* keep the current state */
            return state;
        }
        default:
        {
            /* reset to default state */
            return TP_STATE_DEFAULT;
        }
    }
}

static TP_STATE tp_escape_handler(SERIAL_PORT port, TP_STATE state, uint8_t ch) {
    switch (state) {
        case TP_STATE_DEFAULT:
        {
            return tp_normal_handler(port, TP_STATE_PREPARE_1, ch);
        }
        case TP_STATE_PREPARE_1:
        {
            return tp_normal_handler(port, TP_STATE_PREPARE_2, ch);
        }
        case TP_STATE_PREPARE_2:
        {
            /* escape now immediately */
            service_mode_transparent_deinit(port);
            service_mode_cli_init(port);
            service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_CLI);
            return TP_STATE_DEFAULT;
        }
    }
}

tp_event_handler tp_transitions[TP_STATE_MAX][TP_EVENT_MAX] = {
    [TP_STATE_DEFAULT] = { [TP_EVENT_RECV_A_NORMAL_CHAR] = tp_normal_handler,
                           [TP_EVENT_RECV_A_ESCAPE_CHAR] = tp_escape_handler,},
    [TP_STATE_PREPARE_1] = { [TP_EVENT_RECV_A_NORMAL_CHAR] = tp_normal_handler,
                           [TP_EVENT_RECV_A_ESCAPE_CHAR] = tp_escape_handler,},
    [TP_STATE_PREPARE_2] = { [TP_EVENT_RECV_A_NORMAL_CHAR] = tp_normal_handler,
                           [TP_EVENT_RECV_A_ESCAPE_CHAR] = tp_escape_handler,},
};

static TP_EVENT tp_ch2evt(uint8_t ch) {
    switch (ch) {
        case TP_ESCAPE_CHAR:
        {
            return TP_EVENT_RECV_A_ESCAPE_CHAR;
        }
        default:
        {
            return TP_EVENT_RECV_A_NORMAL_CHAR;
        }
    }
}

void service_mode_transparent_handler(SERIAL_PORT port, uint8_t ch) {
    tp_event_handler event_handler = tp_transitions[arrived_byte_stream_info[port].state][tp_ch2evt(ch)];
    if (event_handler) {
        arrived_byte_stream_info[port].state = event_handler(port, arrived_byte_stream_info[port].state, ch);
    } else {
        arrived_byte_stream_info[port].state = TP_STATE_DEFAULT;
    }
}

void service_mode_transparent_init(SERIAL_PORT port) {
    memset(arrived_byte_stream_info[port].sgTpBuffer, 0x00, TP_BUFFER_SIZE+1);
    arrived_byte_stream_info[port].sgCurPos = 0;
    arrived_byte_stream_info[port].state = TP_STATE_DEFAULT;
    arrived_byte_stream_info[port].no_nwk_cnt = 0;

    tp_inst_cnt++;
    if (tp_inst_cnt == 1) {
        udrv_system_timer_stop(SYSTIMER_TRANSPARENT_MODE);
        udrv_system_timer_create(SYSTIMER_TRANSPARENT_MODE, lora_handler, HTMR_PERIODIC);
        udrv_system_timer_start(SYSTIMER_TRANSPARENT_MODE, 3000, NULL);
    }
}

void service_mode_transparent_deinit(SERIAL_PORT port) {
    tp_inst_cnt--;
    if (tp_inst_cnt == 0) {
        udrv_system_timer_stop(SYSTIMER_TRANSPARENT_MODE);
    }
}
#endif

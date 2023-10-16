#include "Arduino.h"
#include "RAKProtocol.h"
#include "service_mode_proto.h"

RAKProtocol::RAKProtocol()
{
    
}

void
RAKProtocol::send(RAK_SERIAL_PORT port, uint8_t flag, uint8_t frame_type, uint8_t * payload,
		  uint16_t length, RAK_PROTO_HANDLER response_handler)
{
    service_mode_proto_send((SERIAL_PORT)port, flag, frame_type, payload, length, response_handler);
}

int32_t
RAKProtocol::registerHandler(uint8_t frame_type,
			     RAK_PROTO_HANDLER request_handler)
{
    if (service_mode_proto_register(frame_type, request_handler) ==
	UDRV_RETURN_OK) {
	return 0;
    } else {
	return -1;
    }
}

int32_t
RAKProtocol::deregisterHandler(uint8_t frame_type)
{
    service_mode_proto_deregister(frame_type);
    return 0;
}

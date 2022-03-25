#ifndef	__RAKPROTOCOL_H__
#define	__RAKPROTOCOL_H__

#include <stdint.h>

typedef enum
{
    RAK_SERIAL_UART0 = 0,       // Use UART0 for I/O
    RAK_SERIAL_UART1,           // Use UART1 for I/O
    RAK_SERIAL_UART2,           // Use UART2 for I/O
#ifdef SUPPORT_USB
    RAK_SERIAL_USB0,            // Use USB0 for I/O
#endif
#ifdef SUPPORT_BLE
    RAK_SERIAL_BLE0,            // Use BLE for I/O
#endif
    RAK_SERIAL_MAX,
} RAK_SERIAL_PORT;

typedef void    (*RAK_PROTO_HANDLER)(int, uint8_t *, uint16_t);

class           RAKProtocol {
  private:

  public:
    RAKProtocol();

    /**@par	Description
     *      	This API is used to generate API mode packet.
     * @ingroup	Api_Mode
     *
     * @par	Syntax
     * 		api.apiMode.send(port, flag, frame_type, payload, length, response_handler);
     *
     * @param   port                   The port this packet is sent to \n
     *						List:\n 
     *						RAK_SERIAL_UART0\n 
     *						RAK_SERIAL_UART1\n
     *						RAK_SERIAL_UART2\n
     *						RAK_SERIAL_USB0\n
     *						RAK_SERIAL_BLE0\n
     * @param   flag                   flag header of API mode protocol
     * @param   frame_type             frame type header of API mode protocol
     * @param   payload                packet payload
     * @param   length                 packet length
     * @param   response_handler       one-time handler for this API mode request
     * @verbatim
       void setup()
       {
         Serial2.begin(115200);
         Serial1.begin(115200, RAK_API_MODE);
       }

       void loop()
       {
         //Payload length inside payload 0x0000; Flag 0x00; AT CMD ID 16
         uint8_t buff[] = {0x00, 0x00, 0x00, 0x10};

         api.apiMode.send(RAK_SERIAL_UART1, 0x00, 0x01, buff, 4, NULL);
         delay(1000);
       }
           @endverbatim
     */
    void            send(RAK_SERIAL_PORT port, uint8_t flag, uint8_t frame_type,
			 uint8_t * payload, uint16_t length,
			 RAK_PROTO_HANDLER response_handler);

    /**@par	Description
     *      	This API is used to register a new frame type for API mode stack.
     * @ingroup	Api_Mode
     *
     * @par	Syntax
     * 		api.apiMode.registerHandler(frame_type, request_handler);
     *
     * @param   frame_type             frame type header of API mode protocol
     * @param   request_handler        request handler for this frame type
     *
     */
    int32_t         registerHandler(uint8_t frame_type,
				    RAK_PROTO_HANDLER request_handler);

    /**@par	Description
     *      	This API is used to deregister a frame type for API mode stack.
     * @ingroup	Api_Mode
     *
     * @par	Syntax
     * 		api.apiMode.deregisterHandler(frame_type);
     *
     * @param   frame_type             frame type header of API mode protocol
     *
     */
    int32_t         deregisterHandler(uint8_t frame_type);
};

#endif				// __RAKPROTOCOL_H__

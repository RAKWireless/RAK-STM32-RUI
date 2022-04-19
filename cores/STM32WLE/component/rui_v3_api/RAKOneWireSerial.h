#ifndef __RAK_ONEWIRESERIAL_H__
#define __RAK_ONEWIRESERIAL_H__

#include <cstdint>
#include "WString.h"
#include <cstring>

#include "udrv_errno.h"
#include "udrv_serial.h"
#include "HardwareSerial.h"

using namespace std;

typedef struct RAK_ONEWIRE_SERIAL_RECEIVE
{
    /*!
     * Pointer to the received data stream
     */
    uint8_t *Buffer;
    /*!
     * Size of the received data stream
     */
    uint8_t BufferSize;
} RAK_ONEWIRE_SERIAL_RECEIVE_T;

typedef void (*rak_onewire_serial_recv_cb)(SERIAL_PORT port, RAK_ONEWIRE_SERIAL_RECEIVE_T *data);

class RAKOneWireSerial
{
  protected:
  private:
    uint32_t pin;
    SERIAL_PORT serialPort;
  public:
    /**@par	Description
     *      	This API chooses the pin number for one wire serial and prepare the callback function for receiving data
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	OneWireSerial(pin, callback)
     *
     * @param   pin		the pin number 
     * @param   callback	the callback for receiving data
     */
    RAKOneWireSerial(uint32_t pin, rak_onewire_serial_recv_cb callback);

    void begin(uint32_t baud, uint8_t config, RAK_SERIAL_MODE mode = RAK_DEFAULT_MODE); 
#if defined(SUPPORT_LORA) && defined(SUPPORT_PASSTHRU)
    /**@par	Description
     *      	This API sets the speed (baud rate) for the serial communication.
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.begin(baud);\n
     * 		Serial.begin(baud, mode);
     *
     * @param	baud		The baudrate to set for the Serial
     * @param   mode(optinal)   The mode that use UART in different way (if not assigned, RAK_DEFAULT_MODE is chosen) \n
     *				List:\n
     *				RAK_AT_MODE\n
     *				RAK_API_MODE\n
     *				RAK_PASS_MODE\n
     *				RAK_CUSTOM_MODE\n
     *				RAK_DEFAULT_MODE
     */
#else
    /**@par	Description
     *      	This API sets the speed (baud rate) for the serial communication.
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.begin(baud);\n
     * 		Serial.begin(baud, mode);
     *
     * @param	baud		The baudrate to set for the Serial
     * @param   mode(optinal)   The mode that use UART in different way (if not assigned, RAK_DEFAULT_MODE is chosen) \n
     *				List:\n
     *				RAK_AT_MODE\n
     *				RAK_API_MODE\n
     *				RAK_CUSTOM_MODE\n
     *				RAK_DEFAULT_MODE
     */
#endif
    void begin(uint32_t baud, RAK_SERIAL_MODE mode = RAK_DEFAULT_MODE) { begin(baud, SERIAL_8N1, mode);}

    /**@par	Description
     *          This API is used to write a byte sequence to a specified one wire serial port.
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *          Serial.write(buf, size)
     *
     * @param	buf	an array to send as a series of bytes
     * @param	size	the number of bytes to be sent from the array
     *
     * @return  number of bytes sent successfully(Type: size_t)
     */
    size_t write(const uint8_t *buf, size_t size);

    /**@par	Description
     *      	This API is used to get the number of bytes available for reading from
     * 		the specified one wire serial port.
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.available();
     *
     * @retval	the number of bytes available for reading from the specified one wire serial port(Type: int)
     */
    int available(void);

    /**@par	Description
     *      	Reads incoming one wire serial data
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.read()
     *
     * @return	The first byte of incoming one wire serial data available(Type: int32_t)
     * @retval	-1	Read fail,get nothing from the specified one wire serial port
     */
    int read(void);

    /**@par	Description
     *      	This API closes the one wire serial port
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.end()
     */
    void end(void);
};

#endif //end RAKOneWireSerial.h

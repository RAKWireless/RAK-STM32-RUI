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

typedef void (*rak_onewire_serial_recv_cb)(SERIAL_PORT port,SERIAL_UART_EVT event);

class RAKOneWireSerial : public Stream
{
  protected:
  private:
    uint32_t pin;
    SERIAL_PORT serialPort;
  public:

    /**@par	Description
     *      	This API chooses the pin number for one wire serial and prepare the callback function for receiving data
     *      	One Wire Serial is supported by hardware, only support the following pin.
     *      	UART1_TXD_PIN
     *      	UART1_RXD_PIN
     *      	NOTE: RAK11720 is not supported One Wire Serial since hardware is not supported
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	OneWireSerial(pin, callback)
     *
     * @param   pin		the pin number 
     * @param   callback	the callback for receiving data
     * @verbatim
       void int_handler(SERIAL_PORT port,SERIAL_UART_EVT event)
       {
           Serial.printf("event:%u\r\n",event);
           if(event == SERIAL_UART_TX_DONE)
               Serial.println("SERIAL_UART_TX_DONE");
           if(event == SERIAL_UART_RX_DONE)
               Serial.println("SERIAL_UART_RX_DONE");
           if(event == SERIAL_UART_ERROR)
               Serial.println("SERIAL_UART_ERROR");
       }

       RAKOneWireSerial onewire(UART1_RXD_PIN,int_handler);

       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
     */
    RAKOneWireSerial(uint32_t pin, rak_onewire_serial_recv_cb callback);
    using Print::write; //pull in write(str) and write(buf, size) from Print

    size_t write(uint8_t n) {return write(&n, 1);}

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
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
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
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
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
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            onewire.write("data\r\n",4);
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
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
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
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
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.write("data\r\n");
            while(onewire.available())
            {
                char a = onewire.read();
                Serial.printf("%c",a);
            }
       }
     @endverbatim
     */
    int read(void);

    /**@par	Description
     *      	This API closes the one wire serial port
     * @ingroup	One_Wire_Serial
     *
     * @par	Syntax
     *      	Serial.end()
     * @verbatim
       RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
       void setup()
       {
           Serial.begin(115200);
           onewire.begin(115200, RAK_CUSTOM_MODE);
       }

       void loop()
       {
            onewire.end();
       }
     @endverbatim
     */
    void end(void);
    /**@par Description
     *          Waits for the transmission of outgoing serial data to complete.
     *
     * @par Syntax
     *          Serial.flush();
     * @return  void
     * @par     Example
     * @verbatim
     RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
     void setup() {
         Serial.begin(115200);
         onewire.begin(115200, RAK_CUSTOM_MODE);
     }

     void loop() {
         onewire.write("data\r\n");
         onewire.flush();
     }
     @endverbatim
     */
    virtual void flush(void);
    /**@par Description
     *          Returns the next byte (character) of incoming serial data without removing it from the internal serial buffer. That is,
     *      successive calls to peek() will return the same character, as will the next call to read().
     * @par Syntax
     *          Serial.peek();
     * @return  The first byte of incoming serial data available (or -1 if no data is available)(Type: int)
     * @par Example
     * @verbatim
     RAKOneWireSerial onewire(UART1_RXD_PIN,NULL);
     void setup() {
         Serial.begin(115200);
         onewire.begin(115200, RAK_CUSTOM_MODE);
     }

     void loop() {
        while(onewire.available())
        {
            Serial.print("Peek the Byte = ");
            Serial.println(onewire.peek());
            char a = onewire.read();
            Serial.printf("%c",a);
        }

     }
     @endverbatim
     */
    virtual int peek(void);
};

#endif //end RAKOneWireSerial.h

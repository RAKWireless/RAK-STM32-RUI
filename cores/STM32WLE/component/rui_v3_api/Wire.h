#ifndef __WIRE_NEW_H__
#define __WIRE_NEW_H__

#include "Stream.h"
#include "udrv_twimst.h"

#define TWI_BUFFER_MAX 64

class TwoWire : public Stream
{
  private:
    udrv_twimst_port port;
    uint8_t slaveAddress;

    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

  public:
    TwoWire(udrv_twimst_port);

    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int );  
    virtual size_t write(uint8_t value);
    
    /**@addtogroup	Wire	
     * @{
     */
    /**@par	Description
     *      	Initiate the Wire library and join the I2C bus as a master
     * @par	Syntax
     *      	Wire.begin();
     * @return	void
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }
  
       void loop() {
       }
       @endverbatim
     */
    void begin(void);

    /**@par	Description
     *      	End the I2C bus
     * @par	Syntax
     *      	Wire.end();
     * @return	void
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.end();
       }
       @endverbatim
     */
    void end(void);

    /**@par	Description
     *      	This function modifies the clock frequency for I2C communication. 
     * 		I2C slave devices have no minimum working clock frequency, however 100KHz is usually the baseline
     * @par	Syntax
     *      	Wire.setClock(freq);
     * @param	freq		the value (in Hertz) of desired communication clock. 
     * 				Accepted values are 100000 (standard mode) and 400000 (fast mode)
     * @return	void
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
	 Wire.setClock(400000);
       }

       void loop() {
       }
       @endverbatim
     */
    void setClock(uint32_t freq);

    /**@par	Description
     *      	Begin a transmission to the I2C slave device with the given address. Subsequently, 
     * 		queue bytes for transmission with the write() function and transmit them by calling endTransmission()
     * @par	Syntax
     *      	Wire.beginTransmission(address);
     * @param	address		the 7-bit address of the device to transmit to
     * @return  void
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }
  
       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();
       }
       @endverbatim
     */
    void beginTransmission(uint8_t address);

    /**@par	Description
     *      	Ends a transmission to a slave device that was begun by beginTransmission() 
     * 		and transmits the bytes that were queued by write()
     * @par	Syntax
     *      	Wire.endTransmission();\n
     * 		Wire.endTransmission(sendStop);
     * @param	sendStop(optional)	true will send a stop message, releasing the bus after transmission.\n
     * 					false will send a restart, keeping the connection active(default = false) 
     *
     * @retval	0		success
     * @retval	1		fail
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();
       }
       @endverbatim
     */
    uint32_t endTransmission(uint8_t sendStop = true);

    /**@par	Description
     *      	Used by the master to request bytes from a slave device. The bytes may then be retrieved with the available() and read() functions
     * @par	Syntax
     *      	Wire.requestFrom(address, quantity);\n
     * 		Wire.requestFrom(address, quantity, sensStop);
     * @param	address		the 7-bit address of the device to request bytes from
     * @param	quantity	the number of bytes to request
     * @param	sendStop	true will send a stop message after the request, releasing the bus.\n
     * 				false will continually send a restart after the request, keeping the connection active(default = false)
     *
     * @return	the number of bytes returned from the slave device(Type: byte)
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();

         Wire.requestFrom(0b1110000, 6);

         while(Wire.available()) {
           char c = Wire.read();
           Serial.print(c);
         }
         delay(5000);

       }
       @endverbatim

     */
    uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop);

    /**@par	Description
     *      	Writes data to a slave device
     * @note	in-between calls to beginTransmission() and endTransmission()
     * @par	Syntax
     *      	Wire.write(value);\n
     * 		Wire.write(data, size);
     * @param	value		a value to send as a single byte
     * @param	data		an array of data to send as bytes
     * @param	size		the number of bytes to transmit
     *
     * @return	write() will return the number of bytes written, though reading that number is optional(Type: byte)
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();
	 
         Wire.requestFrom(0b1110000, 6);

         while(Wire.available()) {
           char c = Wire.read();   
           Serial.print(c);
	 }
         delay(5000);

       }
       @endverbatim
     */
    virtual size_t write(const uint8_t *data, size_t size);

    /**@par	Description
     *      	Returns the number of bytes available for retrieval with read()
     * @par	Syntax
     *      	Wire.availavle()
     * @return	The number of bytes available for reading 	
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();

         Wire.requestFrom(0b1110000, 6);

         while(Wire.available()) {
           char c = Wire.read();
           Serial.print(c);
         }
         delay(5000);

       }
       @endverbatim
     */
    virtual int available(void);

    /**@par	Description
     *      	Reads a byte that was transmitted from a slave device to a master 
     * @par	Syntax
     *      	Wire.read()
     * @note	read() inherits from the Stream utility class
     * @return	The next byte received
     * @par     Example
     * @verbatim
       void setup() {
         Wire.begin();
       }

       void loop() {
         Wire.beginTransmission(0b1110000);
         Wire.write(0x35);
         Wire.endTransmission();

         Wire.requestFrom(0b1110000, 6);

         while(Wire.available()) {
           char c = Wire.read();
           Serial.print(c);
         }
         delay(5000);

       }
       @endverbatim
     */
    virtual int read(void);

    /** @} */

    virtual int peek(void);
    virtual void flush(void);
    void beginTransmission(int);
    
    
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n)          { return write((uint8_t)n); }
    inline size_t write(unsigned int n)  { return write((uint8_t)n); }
    inline size_t write(int n)           { return write((uint8_t)n); }
    using Print::write;

   
};

extern TwoWire Wire;
extern TwoWire Wire1;

#endif


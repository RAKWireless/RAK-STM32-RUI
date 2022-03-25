#ifndef __SPI_H__
#define __SPI_H__

#include "udrv_spimst.h"
#include "Arduino.h"

#define SPI_HAS_TRANSACTION 1

#define SPI_MODE0 0x00
#define SPI_MODE1 0x01
#define SPI_MODE2 0x02
#define SPI_MODE3 0x03

#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16
#define SPI_CLOCK_DIV32  32
#define SPI_CLOCK_DIV64  64
#define SPI_CLOCK_DIV128 128
#define SPI_CLOCK_DIV256 256
#define SPI_CLOCK_DIV512 512

class SPISettings
{
    private:
	uint32_t clockFreq;
	uint8_t dataMode;
	uint8_t bitOrder;	
	friend class SPIClass;

    public:
	SPISettings(uint32_t clock, BitOrder bitOrder, uint8_t dataMode) {
	    this->clockFreq = clock;
	    this->bitOrder =  bitOrder;
	    this->dataMode = dataMode;
	}

	SPISettings() {
	    this->clockFreq = 4000000;
	    this->bitOrder = MSBFIRST;
	    this->dataMode = SPI_MODE0;
	}

};

class SPIClass 
{
    private:
	udrv_spimst_port port;
	bool isInitialized;
	uint8_t bitOrder;

    public:
	SPIClass(udrv_spimst_port port);

	uint8_t transfer(uint8_t data);
	void transfer(const void *tx_buf, void *rx_buf, size_t count);
        
	/**@addtogroup	SPI
	 * @{
	 */

	/**@par	Description
	 * 	Initializes the SPI bus by setting SCK, MOSI, and SS to outputs, pulling SCK and MOSI low, and SS high
	 * @par	Syntax
	 *	SPI.begin()
	 * @return	void
	 */
	void begin();

	/**@par	Description
	 *	Disables the SPI bus  
	 * @par	Syntax
	 *	SPI.end()
	 * @return	void
	 */
	void end();

	/**@par	Description
	 *	SPI transfer is based on a simultaneous send and receive: the received data is returned in receivedVal16. 
	 * @par	Syntax
	 *	receivedVal16 = SPI.transfer16(val16)
	 * @param	val16	the two bytes variable to send out over the bus
	 * @return	the received data
	 */
	uint16_t transfer16(uint16_t data);

	/**@par	Description
	 *	SPI transfer is based on a simultaneous send and receive: the received data is returned in receivedVal. In case of buffer transfers the received data is stored in the buffer in-place.
	 * @par	Syntax
	 *	receivedVal = SPI.transfer(val)\n
	 *	SPI.transfer(buffer, size)
	 * @param	val	the byte to send out over the bus
	 * @param	buffer	the array of data to be transferred
	 * @return	the received data
	 */
	void transfer(void *buf, size_t count);

	/**@par	Description
	 *	Initializes the SPI bus using the defined SPISettings 
	 * @par	Syntax
	 *	SPI.beginTransactions(mySetting)
	 * @param	mySetting	the chosen settings according to SPISettings
	 * @return	void
	 */
	void beginTransaction(SPISettings settings);

	/**@par	Description
	 * 	Stop using the SPI bus
	 * @par	Syntax
	 *	SPI.endTransaction()
	 * @return	void
	 */
	void endTransaction();

	/**@par	Description
	 *	Sets the order of the bits shifted out of and into the SPI bus, either LSBFIRST (least-significant bit first) or MSBFIRST (most-significant bit first) 
	 * @par	Syntax
	 *	SPI.setBitOrder(order)
	 * @param	order	either LSBFIRST or MSBFIRST
	 * @return	void
	 */
	void setBitOrder(BitOrder order);

	/**@par	Description
	 *	Sets the SPI data mode: that is, clock polarity and phase 
	 * @par	Syntax	
	 *	SPI.setDataMode(mode)
	 * @param	mode	SPI_MODE0\n
				SPI_MODE1\n
				SPI_MODE2\n
				SPI_MODE3
	 * @return	void
	 */
	void setDataMode(uint8_t mode);

	/**@par	Description
	 *	Sets the SPI clock divider relative to the system clock 
	 * @par	Syntax
	 *	SPI.setClockDivider(divider)
	 * @param	divider		SPI_CLOCK_DIV2\n
					SPI_CLOCK_DIV4\n
					SPI_CLOCK_DIV8\n
					SPI_CLOCK_DIV16\n
					SPI_CLOCK_DIV32\n
					SPI_CLOCK_DIV64\n
					SPI_CLOCK_DIV128	
					SPI_CLOCK_DIV256	
	 * @return	void
	 */
	void setClockDivider(uint32_t uc_div);

	/**@}*/

	/**@par	Description
	 * 
	 * @par	Syntax
	 *
	 * @return void
	 */
	void usingInterrupt();

};

extern SPIClass SPI;

#endif //end SPI.h

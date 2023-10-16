#ifdef SUPPORT_SPI

#include "SPI.h"

#ifdef SUPPORT_SPI
SPIClass SPI(DEFAULT_SPIMST_PORT);

SPIClass::SPIClass(udrv_spimst_port port)
{
    SPIClass::port = port;
    isInitialized = false;
    bitOrder = MSBFIRST;
}

void SPIClass::begin()
{
    if(isInitialized) 
	return;
    udrv_spimst_init(port);    
}

void SPIClass::end()
{
    udrv_spimst_deinit(port);
    isInitialized = false;
}

void SPIClass::beginTransaction(SPISettings settings)
{
    udrv_spimst_deinit(port);

    udrv_spimst_setup_freq(port, settings.clockFreq);
    udrv_spimst_setup_byte_order(port, settings.bitOrder);
    switch(settings.dataMode)
    {
        case SPI_MODE0:
            udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_0);
            break;
        case SPI_MODE1:
            udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_1);
            break;
        case SPI_MODE2:
            udrv_spimst_setup_mode(port, SPI_MST_CPHA_1, SPI_MST_CPOL_0);
            break;
        case SPI_MODE3:
            udrv_spimst_setup_mode(port, SPI_MST_CPHA_1, SPI_MST_CPOL_1);
            break;
        default:
            udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_0);
            break;
    };
    bitOrder = settings.bitOrder;
   

    udrv_spimst_init(port);    
}

//FIXME not work as expected
void SPIClass::endTransaction()
{
    udrv_spimst_deinit(port);
    isInitialized = false;
}

void SPIClass::setBitOrder(BitOrder order)
{
    udrv_spimst_setup_byte_order(port, order);
    bitOrder = order;
}

void SPIClass::setClockDivider(uint32_t div)
{
    if (div >= SPI_CLOCK_DIV512) {
	udrv_spimst_setup_freq(port, 125000);
    } else if (div >= SPI_CLOCK_DIV256) {
	udrv_spimst_setup_freq(port, 250000);
    } else if (div >= SPI_CLOCK_DIV128) {
	udrv_spimst_setup_freq(port, 500000);
    } else if (div >= SPI_CLOCK_DIV64) {
	udrv_spimst_setup_freq(port, 1000000);
    } else if (div >= SPI_CLOCK_DIV32) {
	udrv_spimst_setup_freq(port, 2000000);
    } else if (div >= SPI_CLOCK_DIV16) {
	udrv_spimst_setup_freq(port, 4000000);
    } else if (div >= SPI_CLOCK_DIV8) {
	udrv_spimst_setup_freq(port, 8000000);
    } else {
	udrv_spimst_setup_freq(port, 125000);
    }
}

void SPIClass::setDataMode(uint8_t mode)
{
    switch(mode)
    {
	case SPI_MODE0:
	    udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_0);
	    break;
	case SPI_MODE1:
	    udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_1);
	    break;
	case SPI_MODE2:
	    udrv_spimst_setup_mode(port, SPI_MST_CPHA_1, SPI_MST_CPOL_0);
	    break;
	case SPI_MODE3:
	    udrv_spimst_setup_mode(port, SPI_MST_CPHA_1, SPI_MST_CPOL_1);
	    break;
	default:
		udrv_spimst_setup_mode(port, SPI_MST_CPHA_0, SPI_MST_CPOL_0);
	    break;
    };
}

void SPIClass::transfer(void *buf, size_t count)
{
    transfer(buf, buf, count);
}


uint8_t SPIClass::transfer(uint8_t data)
{
    transfer(&data, 1);
    return data;
}

void SPIClass::transfer(const void *tx_buf, void *rx_buf, size_t count)
{
    uint8_t *tx_buf8 = (uint8_t *)tx_buf;
    uint8_t *rx_buf8 = (uint8_t *)rx_buf;
    udrv_spimst_trx(port, tx_buf8, count, rx_buf8, count, SPI_CSN_PIN);
}


uint16_t SPIClass::transfer16(uint16_t data)
{
    union { uint16_t val; struct { uint8_t lsb; uint8_t msb; }; } t;
  
    t.val = data;
  
    if (bitOrder == LSBFIRST) {
      t.lsb = transfer(t.lsb);
      t.msb = transfer(t.msb);
    } else {
      t.msb = transfer(t.msb);
      t.lsb = transfer(t.lsb);
    }
  
    return t.val;
}
#endif

#endif

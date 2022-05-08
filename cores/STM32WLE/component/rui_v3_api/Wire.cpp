#include "Wire.h"
#include "udrv_serial.h"
#include "udrv_errno.h"

TwoWire Wire(UDRV_TWIMST_0);

// Initialize Class Variables //////////////////////////////////////////////////

uint8_t TwoWire::rxBuffer[TWI_BUFFER_MAX];
uint8_t TwoWire::rxBufferIndex = 0;
uint8_t TwoWire::rxBufferLength = 0;

uint8_t TwoWire::txBuffer[TWI_BUFFER_MAX];
uint8_t TwoWire::txBufferIndex = 0;
uint8_t TwoWire::txBufferLength = 0;

TwoWire::TwoWire(udrv_twimst_port port) {
    TwoWire::port = port;
}

void TwoWire::begin(void)
{
    rxBufferIndex = 0;
    rxBufferLength = 0;
  
    txBufferIndex = 0;
    txBufferLength = 0;
	
    udrv_twimst_init(port);
}

void TwoWire::end(void)
{
    udrv_twimst_deinit(port);
}

void TwoWire::setClock(uint32_t clock)
{
    udrv_twimst_setup_freq(port, clock);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize, uint8_t sendStop)
{
  // clamp to buffer length
  if(quantity > TWI_BUFFER_MAX){
    quantity = TWI_BUFFER_MAX;
  }
  int32_t ret = udrv_twimst_read(port, slaveAddress, rxBuffer, quantity);
//  udrv_serial_printf(ATCMD_IO_SERIAL_PORT, "udrv_twimst_read ret=%d\r\n", ret);
    
  if (!ret == 0)
  {
    return 0;
  }

  rxBufferIndex = 0;
  rxBufferLength = quantity;
  return quantity;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
	return requestFrom((uint8_t)address, (uint8_t)quantity, (uint32_t)0, (uint8_t)0, (uint8_t)sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{
    txBufferIndex = 0;
    txBufferLength = 0;

    slaveAddress = address;
}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t)address);
}

uint32_t TwoWire::endTransmission(uint8_t sendStop)
{
  int32_t ret = udrv_twimst_write(port, slaveAddress, txBuffer, txBufferLength, sendStop);
//  udrv_serial_printf(ATCMD_IO_SERIAL_PORT, "udrv_twimst_read ret=%d\r\n", ret);

  // reset tx buffer iterator vars
  txBufferIndex = 0;
  txBufferLength = 0;

  if (!ret == UDRV_RETURN_OK)
  {
    return 1;
  }

  return 0; //
}

size_t TwoWire::write(uint8_t data)
{
    if(txBufferLength >= TWI_BUFFER_MAX) {
      return 0;
    }
    // put byte in tx buffer
    txBuffer[txBufferIndex] = data;
    ++txBufferIndex;
    // update amount in buffer   
    txBufferLength = txBufferIndex;
    return 1;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
    for(size_t i = 0; i < quantity; ++i){
      write(data[i]);
    }

    return quantity;
}

int TwoWire::available(void)
{
  return rxBufferLength - rxBufferIndex;
}

int TwoWire::read(void)
{
   int32_t value = -1;
  // get each successive byte on each call
  if(rxBufferIndex < rxBufferLength){
    value = rxBuffer[rxBufferIndex];
    ++rxBufferIndex;
  }

  return value;
}

int TwoWire::peek()
{
}

void TwoWire::flush()
{
}



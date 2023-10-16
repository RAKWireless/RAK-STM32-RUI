/*
  PDM.cpp - library to interface with nRF52840 PDM peripheral
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2019 Arduino SA

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "PDM.h"
 


#define DEFAULT_PDM_GAIN     20
 

PDMClass::PDMClass(int dinPin, int clkPin, int pwrPin) :
  _dinPin(dinPin),
  _clkPin(clkPin),
  _pwrPin(pwrPin),
  _onReceive(NULL)
{
}

PDMClass::~PDMClass()
{
}

void PDMClass::setPins(int dataPin, int clkPin, int pwrPin)
{
  _dinPin = dataPin;
  _clkPin = clkPin;
  _pwrPin = pwrPin;
}

int PDMClass::begin(int channels, long sampleRate)
{
  _channels = channels;

  // // Enable high frequency oscillator if not already enabled
  // //udrv_pdm_enable();
  
  // configure the sample rate and channels
  if(udrv_pdm_set_rate(sampleRate) == 0)
	  return 0;
  if(udrv_pdm_set_channel(channels) == 0)
	  return 0;

  setGain(DEFAULT_PDM_GAIN);  
 
  // configure the I/O and mux
  pinMode(_clkPin, OUTPUT);
  digitalWrite(_clkPin, LOW);

  pinMode(_dinPin, INPUT);
  udrv_pdm_psel_connect(digitalPinToPinName(_clkPin),digitalPinToPinName(_dinPin));

  // clear events and enable PDM interrupts
  udrv_pdm_event_clear(UDRV_PDM_EVENT_STARTED);
  udrv_pdm_event_clear(UDRV_PDM_EVENT_END);
  udrv_pdm_event_clear(UDRV_PDM_EVENT_STOPPED);
  udrv_pdm_int_enable();

  if (_pwrPin > -1) {
    // power the mic on
    pinMode(_pwrPin, OUTPUT);
    digitalWrite(_pwrPin, HIGH);
  }
  // clear the buffer
  _doubleBuffer.reset();
  // set the PDM IRQ priority and enable
  udrv_pdm_set_nvic();

  //set the buffer for transfer
  udrv_pdm_buffer_set((uint32_t*)_doubleBuffer.data(), _doubleBuffer.availableForWrite() / (sizeof(int16_t) * _channels));
  _doubleBuffer.swap();
  // enable and trigger start task
  udrv_pdm_enable();
  udrv_pdm_event_clear(UDRV_PDM_EVENT_STARTED);
  udrv_pdm_task_trigger(UDRV_PDM_TASK_START); 
  return 1;
}

void PDMClass::end()
{
  // disable PDM and IRQ
  udrv_pdm_disable();

  udrv_pdm_disable_nvic();

  if (_pwrPin > -1) {
    // power the mic off
    digitalWrite(_pwrPin, LOW);
    pinMode(_pwrPin, INPUT);
  }

  // Don't disable high frequency oscillator since it could be in use by RADIO

  // unconfigure the I/O and un-mux
  udrv_pdm_psel_disconnect();

  pinMode(_clkPin, INPUT);
}

int PDMClass::available()
{
  udrv_pdm_disable_nvic();

  size_t avail = _doubleBuffer.available();

  udrv_pdm_enable_nvic();

  return avail;
}

int PDMClass::read(void* buffer, size_t size)
{
  udrv_pdm_disable_nvic();

  int read = _doubleBuffer.read(buffer, size);

  udrv_pdm_enable_nvic();

  return read;
}

void PDMClass::onReceive(void(*function)(void))
{
  _onReceive = function;
}

void PDMClass::setGain(int gain)
{
  udrv_pdm_set_gain(gain);
}

void PDMClass::setBufferSize(int bufferSize)
{
  _doubleBuffer.setSize(bufferSize);
}

void PDMClass::IrqHandler()
{
  if (udrv_pdm_event_check(UDRV_PDM_EVENT_STARTED)) {
    udrv_pdm_event_clear(UDRV_PDM_EVENT_STARTED);

    if (_doubleBuffer.available() == 0) {
      // switch to the next buffer
      udrv_pdm_buffer_set((uint32_t*)_doubleBuffer.data(), _doubleBuffer.availableForWrite() / (sizeof(int16_t) * _channels));

      // make the current one available for reading
      _doubleBuffer.swap(_doubleBuffer.availableForWrite());

      // call receive callback if provided
      if (_onReceive) {
        _onReceive();
      }
    } else {
      // buffer overflow, stop
      udrv_pdm_disable();
    }
  } 
  else if (udrv_pdm_event_check(UDRV_PDM_EVENT_STOPPED)) 
  {
    udrv_pdm_event_clear(UDRV_PDM_EVENT_STOPPED);
  } 
  else if (udrv_pdm_event_check(UDRV_PDM_EVENT_END)) 
  {
    udrv_pdm_event_clear(UDRV_PDM_EVENT_END);
  }
}

extern "C"
{
  __attribute__((__used__)) void PDM_IRQHandler(void)
  {
    PDM.IrqHandler();
  }
}
 
#ifndef PIN_PDM_DIN
#define PIN_PDM_DIN -1
#endif

#ifndef PIN_PDM_CLK
#define PIN_PDM_CLK -1
#endif

#ifndef PIN_PDM_PWR
#define PIN_PDM_PWR -1
#endif

PDMClass PDM(PIN_PDM_DIN, PIN_PDM_CLK, PIN_PDM_PWR);



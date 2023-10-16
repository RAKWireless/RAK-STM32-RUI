#include "ruiTop.h"
#include "variant.h"


unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
  unsigned long startMicros = systick_micros();

  // wait for any previous pulse to end 
  while(digitalRead(pin) == state) {
    if((systick_micros() - startMicros) > timeout)
      return 0;
  }

  // wait for the pulse to start
  while(digitalRead(pin) != state) {
    if((systick_micros() - startMicros) > timeout)
      return 0;
  }
  unsigned long startPulse = systick_micros();

  // wait for the pulse to stop
  unsigned long stopPulse;
  while(digitalRead(pin) == state) {
    stopPulse = systick_micros();
    if((stopPulse - startMicros) > timeout)
      return 0;
  }
  return stopPulse - startPulse;
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
  unsigned long startMicros = systick_micros();

  // wait for any previous pulse to end
  while(digitalRead(pin) == state) {
    if((systick_micros() - startMicros) > timeout)
      return 0;
  }

  // wait for the pulse to start
  while(digitalRead(pin) != state) {
    if((systick_micros() - startMicros) > timeout)
      return 0;
  }
  unsigned long startPulse = systick_micros();

  // wait for the pulse to stop
  unsigned long stopPulse;
  while(digitalRead(pin) == state) {
    stopPulse = systick_micros();
    if((stopPulse - startMicros) > timeout)
      return 0;
  }
  return stopPulse - startPulse;
}

#include "ruiTop.h"
#include "variant.h"

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
  unsigned long startMicros = micros();

  while(digitalRead(pin) == state) {
    if((micros() - startMicros) > timeout)
      return 0;
  }

  while(digitalRead(pin) != state) {
    if((micros() - startMicros) > timeout)
      return 0;
  }

  unsigned long startPulse = micros();
  while(digitalRead(pin) == state) {
  }
  return micros() - startPulse; 	
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
  unsigned long startMicros = micros();

  while(digitalRead(pin) == state) {
    if((micros() - startMicros) > timeout)
      return 0;
  }

  while(digitalRead(pin) != state) {
    if((micros() - startMicros) > timeout)
      return 0;
  }

  unsigned long startPulse = micros();
  while(digitalRead(pin) == state) {
  }
  return micros() - startPulse;
}

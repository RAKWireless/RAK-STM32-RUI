#include "ruiTop.h"
#include "udrv_gpio.h"
#include "variant.h"

void pinMode(uint8_t pin, uint8_t mode)
{

  if (mode == INPUT) {
    udrv_gpio_set_dir((uint32_t)pin, GPIO_DIR_IN);
    udrv_gpio_set_pull((uint32_t)pin, GPIO_PULL_NONE);
  } else if (mode == INPUT_PULLUP) { 
    udrv_gpio_set_dir((uint32_t)pin, GPIO_DIR_IN);
    udrv_gpio_set_pull((uint32_t)pin, GPIO_PULL_UP);
  } else {
    udrv_gpio_set_dir((uint32_t)pin, GPIO_DIR_OUT);  
  }
}

void digitalWrite(uint8_t pin, uint8_t val)
{
  if (val == LOW) {
    udrv_gpio_set_logic((uint32_t)pin, GPIO_LOGIC_LOW);
  } else {
    udrv_gpio_set_logic((uint32_t)pin, GPIO_LOGIC_HIGH);
  }
}

int digitalRead(uint8_t pin)
{
  if(udrv_gpio_get_logic((uint32_t)pin) == GPIO_LOGIC_LOW)
    return LOW;
  return HIGH;
}

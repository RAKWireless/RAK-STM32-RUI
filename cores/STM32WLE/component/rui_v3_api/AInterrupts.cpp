#include "ruiTop.h"
#include "udrv_system.h"
#include "udrv_gpio.h"

bool isInterrupt = true;
uint32_t mask = -1;

void interrupts()
{
  if(isInterrupt == true)
    return;
  isInterrupt = true;
  udrv_system_critical_section_end(&mask);
}

void noInterrupts()
{
  if(isInterrupt == false)
    return;
  isInterrupt = false;
  udrv_system_critical_section_begin(&mask);
}

void attachInterrupt(uint32_t interruptNum, void (*userFunc)(void), int mode)
{
  switch (mode) {
    case HIGH:
      udrv_gpio_intc_trigger_mode(interruptNum, GPIO_INTC_HIGH_LEVEL);
      break;
    case LOW:
      udrv_gpio_intc_trigger_mode(interruptNum, GPIO_INTC_LOW_LEVEL);
      break;
    case RISING:
      udrv_gpio_intc_trigger_mode(interruptNum, GPIO_INTC_RISING_EDGE);
      break;
    case FALLING:
      udrv_gpio_intc_trigger_mode(interruptNum, GPIO_INTC_FALLING_EDGE);
      break;
    case CHANGE:
      udrv_gpio_intc_trigger_mode(interruptNum, GPIO_INTC_RISING_FALLING_EDGE);
      break;
    default:
      return;
  }
  udrv_gpio_register_isr(interruptNum, (gpio_isr_func)userFunc);
}

void detachInterrupt(uint32_t interruptNum)
{
  udrv_gpio_intc_clear(interruptNum);
}

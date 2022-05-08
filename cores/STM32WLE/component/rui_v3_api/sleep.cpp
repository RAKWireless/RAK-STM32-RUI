#include "sleep.h"

sleep::sleep() {
}

void sleep::cpu(uint32_t ms_time) {
  udrv_mcu_sleep_ms(ms_time);
}

void sleep::cpu(int ms_time) {
  udrv_mcu_sleep_ms((uint32_t)ms_time);
}

void sleep::lora(uint32_t ms_time) {
  udrv_radio_sleep_ms(ms_time);
}

void sleep::lora(int ms_time) {
  udrv_radio_sleep_ms((uint32_t)ms_time);
}

void sleep::all(uint32_t ms_time) {
  udrv_sleep_ms(ms_time);
}

void sleep::all(int ms_time) {
  udrv_sleep_ms((uint32_t)ms_time);
}

void sleep::setup(RUI_WAKEUP_TRIGGER_MODE mode, uint32_t pin) {
  if (mode == RUI_WAKEUP_RISING_EDGE) {
      udrv_gpio_set_wakeup_mode(GPIO_INTC_RISING_EDGE);
  } else if (mode == RUI_WAKEUP_FALLING_EDGE) {
      udrv_gpio_set_wakeup_mode(GPIO_INTC_FALLING_EDGE);
  }
  udrv_gpio_set_wakeup_disable_all();
  udrv_gpio_set_wakeup_enable(pin);
}

#include "sleep.h"

extern bool udrv_powersave_early_wakeup;

sleep::sleep() {
}

void sleep::cpu() {
  udrv_mcu_sleep_ms(0);
  udrv_system_event_consume();
}

void sleep::cpu(uint32_t ms_time) {
  uint64_t start, end;

  if (ms_time == 0) {
    return;
  }

  udrv_mcu_sleep_ms(ms_time);
  udrv_system_event_consume();
}

void sleep::cpu(int ms_time) {
  uint64_t start, end;

  if (ms_time == 0) {
    return;
  }

  udrv_mcu_sleep_ms((uint32_t)ms_time);
  udrv_system_event_consume();
}

bool sleep::registerWakeupCallback(POWER_SAVE_HANDLER callback)
{
    if ( udrv_register_wakeup_callback(callback) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}

#ifdef SUPPORT_LORA
void sleep::lora(uint32_t ms_time) {
  if (ms_time == 0) {
    return;
  }

  udrv_radio_sleep_ms(ms_time);
}

void sleep::lora(int ms_time) {
  if (ms_time == 0) {
    return;
  }

  udrv_radio_sleep_ms((uint32_t)ms_time);
}
#endif

void sleep::all() {
  udrv_sleep_ms(0);
  udrv_system_event_consume();
}

void sleep::all(uint32_t ms_time) {
  uint64_t start, end;

  if (ms_time == 0) {
    return;
  }

  udrv_sleep_ms(ms_time);
  udrv_system_event_consume();
}

void sleep::all(int ms_time) {
  uint64_t start, end;

  if (ms_time == 0) {
    return;
  }

  udrv_sleep_ms((uint32_t)ms_time);
  udrv_system_event_consume();
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

uint8_t lpm::get() {
  return (uint8_t)service_nvm_get_auto_sleep_time_from_nvm();
}

bool lpm::set(uint8_t value) {
  if (service_nvm_set_auto_sleep_time_to_nvm((uint32_t)value) == UDRV_RETURN_OK)
  {
      return true;
  }
  else
  {
      return false;
  }
}

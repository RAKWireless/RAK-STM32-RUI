#ifndef __UHAL_GPIO_H__
#define __UHAL_GPIO_H__

#include <stdbool.h>

#include "udrv_gpio.h"
#include "stm32wlxx_hal.h"

#define M_MAX_GPIO_PIN          (48)

void uhal_gpio_init(uint32_t pin, gpio_dir_t dir, gpio_pull_t pull, gpio_logic_t logic);
void uhal_gpio_set_dir(uint32_t pin, gpio_dir_t dir);
gpio_dir_t uhal_gpio_get_dir(uint32_t pin);
void uhal_gpio_set_pull(uint32_t pin, gpio_pull_t pull);
void uhal_gpio_set_logic(uint32_t pin, gpio_logic_t logic);
gpio_logic_t uhal_gpio_get_logic(uint32_t pin);
void uhal_gpio_toggle_logic(uint32_t pin);
void uhal_gpio_intc_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode);
int32_t uhal_gpio_register_isr(uint32_t pin, gpio_isr_func handler);
void uhal_gpio_intc_clear(uint32_t pin);
void uhal_gpio_set_wakeup_enable(uint32_t pin);
void uhal_gpio_set_wakeup_disable(uint32_t pin);
void uhal_gpio_set_wakeup_mode(gpio_intc_trigger_mode_t mode);
void uhal_gpio_suspend(void);
void uhal_gpio_resume(void);

#endif  // __UHAL_GPIO_H__

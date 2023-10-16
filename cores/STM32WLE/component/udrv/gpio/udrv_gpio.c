#include <stdint.h>
#include "udrv_gpio.h"
#include "uhal_gpio.h"

void udrv_gpio_init(uint32_t pin, gpio_dir_t dir, gpio_pull_t pull, gpio_logic_t logic) {
    uhal_gpio_init(pin, dir, pull, logic);
}

void udrv_gpio_set_dir(uint32_t pin, gpio_dir_t dir) {

    uhal_gpio_set_dir(pin, dir);
}

void udrv_gpio_set_pull(uint32_t pin, gpio_pull_t pull) {
    
    uhal_gpio_set_pull(pin, pull);
}

void udrv_gpio_set_logic(uint32_t pin, gpio_logic_t logic) {
    
    uhal_gpio_set_logic(pin, logic);
}

gpio_logic_t udrv_gpio_get_logic(uint32_t pin) {
    
    return uhal_gpio_get_logic(pin);
}

void udrv_gpio_toggle_logic(uint32_t pin) {
    
    uhal_gpio_toggle_logic(pin);
}

void udrv_gpio_intc_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode) {
    
    uhal_gpio_intc_trigger_mode(pin, mode);
}

int32_t udrv_gpio_register_isr(uint32_t pin, gpio_isr_func handler) {
    
    int32_t ret = 0;

    ret = uhal_gpio_register_isr(pin, handler);

    return ret;
}

void udrv_gpio_intc_clear(uint32_t pin) {
    
    uhal_gpio_intc_clear(pin);
}


void udrv_gpio_set_wakeup_enable(uint32_t pin) {

    uhal_gpio_set_wakeup_enable(pin);
}

void udrv_gpio_set_wakeup_disable(uint32_t pin) {

    uhal_gpio_set_wakeup_disable(pin);
}

void udrv_gpio_set_wakeup_disable_all(void) {
    for (int i = 0 ; i < M_MAX_GPIO_PIN ; i++) {
        uhal_gpio_set_wakeup_disable(i);
    }
}

void udrv_gpio_set_wakeup_mode(gpio_intc_trigger_mode_t mode) {

    uhal_gpio_set_wakeup_mode(mode);
}

void udrv_gpio_suspend(void) {
    uhal_gpio_suspend();
    return;
}

void udrv_gpio_resume(void) {
    uhal_gpio_resume();
    return;
}

void udrv_gpio_handler_handler (void *pdata) {
    uhal_gpio_handler_handler(pdata);
}

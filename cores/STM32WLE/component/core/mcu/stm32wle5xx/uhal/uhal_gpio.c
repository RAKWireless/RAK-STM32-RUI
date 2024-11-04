#include "uhal_gpio.h"
#include "pin_define.h"
#include "udrv_serial.h"
#include "udrv_system.h"
#include "udrv_errno.h"
#include "stm32wlxx_ll_gpio.h"

#define GPIO_BASE_ADDR 0x48000000UL
#define GPIO_BASE_OFFSET 0x00000400UL
#define GPIO_NUMBER 16

extern bool udrv_powersave_in_sleep;
extern bool udrv_powersave_early_wakeup;
static udrv_system_event_t rui_gpio_int_event[GPIO_NUMBER];
static gpio_isr_func sg_gpio_isr[M_MAX_GPIO_PIN];
static GPIO_InitTypeDef gpio[M_MAX_GPIO_PIN];
static gpio_intc_trigger_mode_t uhal_gpio_wakeup_mode = GPIO_INTC_RISING_FALLING_EDGE;

typedef struct uhal_gpio_status {
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
    uint32_t Alternate;
    bool wakeup_source;
} uhal_gpio_status_t;

static uhal_gpio_status_t gpio_status[M_MAX_GPIO_PIN];

void uhal_gpio_handler_handler(void *pdata)
{
    if (sg_gpio_isr[(uint32_t)pdata]) {
        sg_gpio_isr[(uint32_t)pdata]((uint32_t)pdata);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    uint16_t pin = 1;
    uint8_t pin_number = 0;
    while(!(pin & GPIO_Pin))
    {
        pin <<= 1;
        pin_number++;
    }
    //uint8_t pin_number = log2(GPIO_Pin);

    if (pin_number >= M_MAX_GPIO_PIN) {
        return;
    }

    udrv_powersave_in_sleep = false;

    rui_gpio_int_event[pin_number].request = UDRV_SYS_EVT_OP_GPIO_INTERRUPT;
    rui_gpio_int_event[pin_number].p_context = (void *)pin_number;
    udrv_system_event_produce(&rui_gpio_int_event[pin_number]);
}

static void gpio_wakeup_handler(void) {
    udrv_powersave_in_sleep = false;
    udrv_powersave_early_wakeup = true;
}

GPIO_TypeDef* PinToGPIOx(uint32_t pin) {
    if(pin % GPIO_NUMBER == 0 && pin != 0) 
        return GPIO_BASE_ADDR + ((pin / GPIO_NUMBER) * GPIO_BASE_OFFSET); 
    return (GPIO_BASE_ADDR + ((pin / GPIO_NUMBER) * GPIO_BASE_OFFSET)); 
}

uint16_t PinToGPIO_Pin(uint32_t pin) {
    uint8_t pin_number = pin % GPIO_NUMBER;
    return 1 << pin_number;
    //return pow(2, pin_number);
}

void uhal_gpio_init(uint32_t pin, gpio_dir_t dir, gpio_pull_t pull, gpio_logic_t logic) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    gpio[pin].Pin = PinToGPIO_Pin(pin);
    gpio[pin].Speed = GPIO_SPEED_FREQ_HIGH;

    if (pull == GPIO_PULL_DOWN) {
        gpio[pin].Pull = GPIO_PULLDOWN;
    } else if (pull == GPIO_PULL_UP) {
        gpio[pin].Pull = GPIO_PULLUP;
    } else if (pull == GPIO_PULL_NONE) {
        gpio[pin].Pull = GPIO_NOPULL;
    }

    if(dir == GPIO_DIR_OUT) {
        gpio[pin].Mode = GPIO_MODE_OUTPUT_PP;
    } else if (dir == GPIO_DIR_IN) {
        gpio[pin].Mode = GPIO_MODE_INPUT;
    }

    HAL_GPIO_Init(PinToGPIOx(pin), &gpio[pin]);

    if (logic == GPIO_LOGIC_LOW) {
        HAL_GPIO_WritePin(PinToGPIOx(pin), PinToGPIO_Pin(pin), GPIO_PIN_RESET);
    } else if (logic == GPIO_LOGIC_HIGH) {
        HAL_GPIO_WritePin(PinToGPIOx(pin), PinToGPIO_Pin(pin), GPIO_PIN_SET);
    }
}

void uhal_gpio_set_dir(uint32_t pin, gpio_dir_t dir) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    gpio[pin].Pin = PinToGPIO_Pin(pin);
    gpio[pin].Speed = GPIO_SPEED_FREQ_HIGH;
    gpio[pin].Pull = GPIO_NOPULL;

    if(dir == GPIO_DIR_OUT) {
        gpio[pin].Mode = GPIO_MODE_OUTPUT_PP;
    } else if (dir == GPIO_DIR_IN) {
        gpio[pin].Mode = GPIO_MODE_INPUT; 
    }

    HAL_GPIO_Init(PinToGPIOx(pin), &gpio[pin]);

}

gpio_dir_t uhal_gpio_get_dir(uint32_t pin){
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if(gpio[pin].Mode == GPIO_MODE_OUTPUT_PP) {
        return GPIO_DIR_OUT;
    } else if (gpio[pin].Mode == GPIO_MODE_INPUT) {
        return GPIO_DIR_IN;
    } 
}

void uhal_gpio_set_pull(uint32_t pin, gpio_pull_t pull) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    HAL_GPIO_DeInit(PinToGPIOx(pin), PinToGPIO_Pin(pin));

    if (pull == GPIO_PULL_DOWN) {
        gpio[pin].Pull = GPIO_PULLDOWN;
    } else if (pull == GPIO_PULL_UP) {
        gpio[pin].Pull = GPIO_PULLUP;
    } else if (pull == GPIO_PULL_NONE) {
        gpio[pin].Pull = GPIO_NOPULL;
    }

    HAL_GPIO_Init(PinToGPIOx(pin), &gpio[pin]);
}

void uhal_gpio_set_logic(uint32_t pin, gpio_logic_t logic) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if (logic == GPIO_LOGIC_LOW) {
        HAL_GPIO_WritePin(PinToGPIOx(pin), PinToGPIO_Pin(pin), GPIO_PIN_RESET);
    } else if (logic == GPIO_LOGIC_HIGH) {
        HAL_GPIO_WritePin(PinToGPIOx(pin), PinToGPIO_Pin(pin), GPIO_PIN_SET);
    }
}

gpio_logic_t uhal_gpio_get_logic(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    if (HAL_GPIO_ReadPin(PinToGPIOx(pin), PinToGPIO_Pin(pin)) == GPIO_PIN_RESET) {
        return GPIO_LOGIC_LOW;
    } else {
        return GPIO_LOGIC_HIGH;
    }
}

void uhal_gpio_toggle_logic(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    HAL_GPIO_TogglePin(PinToGPIOx(pin), PinToGPIO_Pin(pin));
}

void uhal_gpio_intc_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    /*GPIO init*/
    gpio[pin].Pin = PinToGPIO_Pin(pin);
    gpio[pin].Speed = GPIO_SPEED_FREQ_HIGH;

    switch (mode) {
        case GPIO_INTC_HIGH_LEVEL:
        case GPIO_INTC_RISING_EDGE:
            //gpio[pin].Pull = GPIO_PULLDOWN;
            gpio[pin].Mode = GPIO_MODE_IT_RISING;
            break;
        case GPIO_INTC_LOW_LEVEL:
        case GPIO_INTC_FALLING_EDGE:
            //gpio[pin].Pull = GPIO_PULLUP;
            gpio[pin].Mode = GPIO_MODE_IT_FALLING;
            break;
        default:
            //gpio[pin].Pull = GPIO_PULLDOWN;
            gpio[pin].Mode = GPIO_MODE_IT_RISING_FALLING;
            break;
    }

    switch(LL_GPIO_GetPinPull(PinToGPIOx(pin), PinToGPIO_Pin(pin))) {
        case LL_GPIO_PULL_NO:
            break;
        case LL_GPIO_PULL_UP:
            gpio[pin].Pull = GPIO_PULLUP;
            break;
        case LL_GPIO_PULL_DOWN:
            gpio[pin].Pull = GPIO_PULLDOWN;
            break;
    }

    HAL_GPIO_Init(PinToGPIOx(pin), &gpio[pin]);

    /*NVIC init*/
    uint8_t pin_number = pin % GPIO_NUMBER;
    if (pin_number == 0) {
        HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI0_IRQn);   
    } else if (pin_number == 1) {
        HAL_NVIC_SetPriority(EXTI1_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI1_IRQn);   
    } else if (pin_number == 2) {
        HAL_NVIC_SetPriority(EXTI2_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI2_IRQn);   
    } else if (pin_number == 3) {
        HAL_NVIC_SetPriority(EXTI3_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI3_IRQn);   
    } else if (pin_number == 4) {
        HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI4_IRQn);   
    } else if (pin_number >= 5 && pin_number <= 9) {
        HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);   
    } else if (pin_number >= 10 && pin_number <= 15) { 
        HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
        HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);   
    }
}

static void uhal_gpio_wakeup_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode) {
    uhal_gpio_intc_trigger_mode(pin, mode);
}

int32_t uhal_gpio_register_isr(uint32_t pin, gpio_isr_func handler) {
    uint8_t pin_number = pin % GPIO_NUMBER;
    //uint8_t pin_number = log2(PinToGPIO_Pin(pin));
    if (pin_number >= M_MAX_GPIO_PIN) {
        return -UDRV_WRONG_ARG;
    }

    if (!sg_gpio_isr[pin_number]) 
        sg_gpio_isr[pin_number] = handler;
    return 0;
}

void uhal_gpio_intc_clear(uint32_t pin) {
    uint8_t pin_number = pin % GPIO_NUMBER;
    if (pin_number >= M_MAX_GPIO_PIN) {
        return;
    }

    sg_gpio_isr[pin_number] = NULL;
}

void uhal_gpio_set_wakeup_enable(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    gpio_status[pin].wakeup_source = true;
}

void uhal_gpio_set_wakeup_disable(uint32_t pin) {
    if (pin >= M_MAX_GPIO_PIN) {
        return;
    }

    gpio_status[pin].wakeup_source = false;
}

void uhal_gpio_set_wakeup_mode(gpio_intc_trigger_mode_t mode) {
    uhal_gpio_wakeup_mode = mode;
}

void uhal_gpio_suspend(void) {
    for (int i = 0 ; i < M_MAX_GPIO_PIN ; i++) {
        if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7 &&
			i != 8 && i != 9 && i != 10 && i != 11 && i != 12 && i != 13 && i != 14 && i != 15 &&
			i != 18 && i != 19 && i != 20 && i != 21 && i != 22 && i != 23 &&
			/*i != 24 && */i != 28/* && i != 45*/) {
            continue;
        }

        if (sg_gpio_isr[i] != NULL) {
            continue;
        }

        gpio_status[i].Mode = gpio[i].Mode;
        gpio_status[i].Pull = gpio[i].Pull;
        gpio_status[i].Speed = gpio[i].Speed;
        gpio_status[i].Alternate = gpio[i].Alternate;

        if (gpio_status[i].wakeup_source == true) 
        {
            uhal_gpio_wakeup_trigger_mode(i, uhal_gpio_wakeup_mode);    
            uhal_gpio_register_isr(i, gpio_wakeup_handler);
            continue;
        }

        //gpio[i].Mode = GPIO_MODE_ANALOG;
        //gpio[i].Pull = GPIO_NOPULL;

        //HAL_GPIO_Init(PinToGPIOx(i), &gpio[i]);
    }
    return;
}

void uhal_gpio_resume(void) {
    for (int i = 0 ; i < M_MAX_GPIO_PIN ; i++) {
        if (i != 0 && i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7 &&
			i != 8 && i != 9 && i != 10 && i != 11 && i != 12 && i != 13 && i != 14 && i != 15 &&
			i != 18 && i != 19 && i != 20 && i != 21 && i != 22 && i != 23 &&
			/*i != 24 && */i != 28/* && i != 45*/) {
            continue;
        }

        if (sg_gpio_isr[i] != NULL) {
            continue;
        }

        gpio[i].Mode = gpio_status[i].Mode;
        gpio[i].Pull = gpio_status[i].Pull;
        gpio[i].Speed = gpio_status[i].Speed;
        gpio[i].Alternate = gpio_status[i].Alternate;

        HAL_GPIO_Init(PinToGPIOx(i), &gpio[i]);
    }
}


#include "uhal_pwm.h"
#include "udrv_pwm.h"
#include "udrv_errno.h"

TIM_HandleTypeDef htim;

TIM_MasterConfigTypeDef sMasterConfig = {0};
TIM_OC_InitTypeDef sConfigOC = {0};
TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

static uint32_t uhal_pwm_period = PERIOD_8BIT;
static uint32_t uhal_pwm_freq_hz = 490;

#define PRESCALER_VALUE     (uint32_t)(((SystemCoreClock) / (uhal_pwm_period * uhal_pwm_freq_hz)) -1)

static UDRV_PWM_RESOLUTION pwm_resolution = UDRV_PWM_RESOLUTION_8BIT;
static UTIL_TIMER_Object_t uhal_pwm_timer_id;

typedef struct uhal_pwm_status {
    bool initialized;
    bool enabled;
    uint32_t freq_hz;
    uint8_t is_invert;
    uint32_t pin;
    uint32_t duty;
} uhal_pwm_status_t;

static uhal_pwm_status_t pwm_status[UDRV_PWM_MAX];

static void uhal_pwm_pin_init(uint32_t pin) {
    if (pin != 0  && pin != 1  && pin != 8  && pin != 9 && pin != 10 &&
        pin != 15) {
        return;
    }

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    GPIO_InitStruct.Pin = PinToGPIO_Pin(pin);
    if (pin == 0 || pin == 1 || pin == 15) {
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
    } else {
        GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
    }

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

static void uhal_pwm_pin_deinit(uint32_t pin) {
    HAL_GPIO_DeInit(GPIOA, PinToGPIO_Pin(pin));    
}

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
}

UDRV_PWM_RESOLUTION uhal_pwm_get_resolution (void) {
    return pwm_resolution;
}

void uhal_pwm_set_resolution (UDRV_PWM_RESOLUTION resolution) {
    if (resolution > UDRV_PWM_RESOLUTION_14BIT) {
        return;
    }
    pwm_resolution = resolution;
}

static void pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin) {

    if (pin == 0 || pin == 1 || pin == 15) {
        htim.Instance = TIM2;
    } else {
        htim.Instance = TIM1;
    }
    uhal_pwm_freq_hz = freq_hz;

    htim.Init.Prescaler = PRESCALER_VALUE;
    htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim.Init.Period = uhal_pwm_period - 1;
    htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim.Init.RepetitionCounter = 0;
    htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_PWM_Init(&htim) != HAL_OK)
    {
      Error_Handler();
    }

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

    if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
    {
      Error_Handler();
    }
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    switch (pin) {
        case 0:
        case 15:
            if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 1:
        case 9:
            if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 10:
            if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 8:
            if (HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
            {
              Error_Handler();
            }
            break;
    }
    sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
    sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
    sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
    sBreakDeadTimeConfig.DeadTime = 0;
    sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
    sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
    sBreakDeadTimeConfig.BreakFilter = 0;
    sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
    sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
    sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
    sBreakDeadTimeConfig.Break2Filter = 0;
    sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
    sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
    if (HAL_TIMEx_ConfigBreakDeadTime(&htim, &sBreakDeadTimeConfig) != HAL_OK)
    {
      Error_Handler();
    }
  
    uhal_pwm_pin_init(pin);
}

void uhal_pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_init(port, freq_hz, is_invert, pin);

    pwm_status[port].initialized = true;
    pwm_status[port].freq_hz = freq_hz;
    pwm_status[port].is_invert = is_invert;
    pwm_status[port].pin = pin;
}

static void pwm_deinit(udrv_pwm_port port) {
    HAL_TIM_PWM_DeInit(&htim); 
}

void uhal_pwm_deinit(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_deinit(port);
    uhal_pwm_pin_deinit(pwm_status[port].pin);

    pwm_status[port].initialized = false;
}

static void pwm_enable(udrv_pwm_port port) {
    switch (pwm_status[port].pin) {
        case 0:
        case 15:
            if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 1:
        case 9:
            if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_2) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 10:
            if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_3) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 8:
            if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_4) != HAL_OK)
            {
              Error_Handler();
            }
            break;
    }
}

void uhal_pwm_enable(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_enable(port);
    pwm_status[port].enabled = true;

}

static void pwm_disable(udrv_pwm_port port) {
    switch (pwm_status[port].pin) {
        case 0:
        case 15:
            if (HAL_TIM_PWM_Stop(&htim, TIM_CHANNEL_1) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 1:
        case 9:
            if (HAL_TIM_PWM_Stop(&htim, TIM_CHANNEL_2) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 10:
            if (HAL_TIM_PWM_Stop(&htim, TIM_CHANNEL_3) != HAL_OK)
            {
              Error_Handler();
            }
            break;
        case 8:
            if (HAL_TIM_PWM_Stop(&htim, TIM_CHANNEL_4) != HAL_OK)
            {
              Error_Handler();
            }
            break;
    }
}

void uhal_pwm_disable(udrv_pwm_port port) {
    if (port >= UDRV_PWM_MAX) {
        return;
    }

    pwm_disable(port);
    pwm_status[port].enabled = false;
}

void uhal_pwm_suspend(void) {
}

void uhal_pwm_resume(void) {
    for (int i = UDRV_PWM_0 ; i < UDRV_PWM_MAX ; i++) {
        if (pwm_status[i].initialized == true) {
            pwm_init(i, pwm_status[i].freq_hz, pwm_status[i].is_invert, pwm_status[i].pin);
    }
        if (pwm_status[i].enabled == true) {
        pwm_enable(i);
        uhal_pwm_set_duty(i, pwm_status[i].duty);
    }
    }

}

int32_t uhal_pwm_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    if (UTIL_TIMER_Create(&uhal_pwm_timer_id, 0xFFFFFFFFU, UTIL_TIMER_ONESHOT, tmr_handler, NULL) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_pwm_timer_start (uint32_t count, void *m_data) {
    if (UTIL_TIMER_SetPeriod(&uhal_pwm_timer_id, count) == UTIL_TIMER_OK)
    {
        if (UTIL_TIMER_Start(&uhal_pwm_timer_id) == UTIL_TIMER_OK)
        {
            return UDRV_RETURN_OK;
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }

}

int32_t uhal_pwm_timer_stop (void) {
    if (UTIL_TIMER_Stop(&uhal_pwm_timer_id) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_pwm_set_duty(udrv_pwm_port port, uint32_t duty) {
    pwm_disable(port);
    pwm_deinit(port);

    switch (pwm_resolution) {
        case UDRV_PWM_RESOLUTION_8BIT:
            if (duty > 255) {
                return -UDRV_WRONG_ARG;
        } else {
                uhal_pwm_period = PERIOD_8BIT;
                htim.Init.Period = PERIOD_8BIT - 1;
        }
            break;
        case UDRV_PWM_RESOLUTION_10BIT:
            if (duty > 1023) {
                return -UDRV_WRONG_ARG;
        } else {
                uhal_pwm_period = PERIOD_10BIT;
                htim.Init.Period = PERIOD_10BIT - 1;
        }
            break;
        case UDRV_PWM_RESOLUTION_12BIT:
            if (duty > 4095) {
                return -UDRV_WRONG_ARG;
        } else {
                uhal_pwm_period = PERIOD_12BIT;
                htim.Init.Period = PERIOD_12BIT - 1;
        }
            break;
        case UDRV_PWM_RESOLUTION_14BIT:
            if (duty > 16383) {
                return -UDRV_WRONG_ARG;
        } else {
                uhal_pwm_period = PERIOD_14BIT;
                htim.Init.Period = PERIOD_14BIT - 1;
        }
            break;
        default:
        return -UDRV_INTERNAL_ERR;
    }
    sConfigOC.Pulse = duty;

    pwm_init(port, pwm_status[port].freq_hz, pwm_status[port].is_invert, pwm_status[port].pin);
    pwm_enable(port);
}


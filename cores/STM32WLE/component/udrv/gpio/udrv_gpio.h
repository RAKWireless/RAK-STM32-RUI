/**
 * @file        udrv_gpio.h
 * @brief       Provide a hardware independent GPIO driver layer for API layer to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.2
 */

#ifndef __UDRV_GPIO_H__
#define __UDRV_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "pin_define.h"

typedef void (*gpio_isr_func) (uint32_t irq_num);

typedef enum
{
    GPIO_DIR_IN         = 0,        /**< GPIO direction INPUT */
    GPIO_DIR_OUT        = 1,        /**< GPIO direction OUTPUT */
} gpio_dir_t;

typedef enum
{
    GPIO_PULL_DOWN      = 0,        /**< GPIO Pull Down */
    GPIO_PULL_UP        = 1,         /**< GPIO Pull Up */
    GPIO_PULL_NONE      = 2,
    GPIO_PULL_ERROR     = 3,
} gpio_pull_t;

//typedef enum
//{
//    GPIO_DRIVING_WEAK       = 0,         /**< GPIO weak driving strenght */
//    GPIO_DRIVING_STRONG     = 1          /**< GPIO strong driving streght */
//} gpio_driving_strengh_t;

typedef enum
{
    GPIO_LOGIC_LOW    = 0,         /**< GPIO logic state LOW */
    GPIO_LOGIC_HIGH   = 1          /**< GPIO logic state HIGH */
} gpio_logic_t;


typedef enum
{
    GPIO_INTC_HIGH_LEVEL    = 2,
    GPIO_INTC_RISING_EDGE   = 3,
    GPIO_INTC_LOW_LEVEL     = 4,
    GPIO_INTC_FALLING_EDGE  = 5,
    GPIO_INTC_RISING_FALLING_EDGE  = 6,
} gpio_intc_trigger_mode_t;

/**
 * @brief   Initialize a GPIO pin.
 *
 * @param   pin                             GPIO pin number.
 * @param   dir                             The GPIO direction(in or out).
 * @param   pull                            GPIO pull up or down.
 * @param   logic                           GPIO logic high or low.
 *
 */
void udrv_gpio_init(uint32_t pin, gpio_dir_t dir, gpio_pull_t pull, gpio_logic_t logic);

/**
 * @brief   Set GPIO direction.
 *
 * @param   pin                             GPIO pin number.
 * @param   dir                             The GPIO direction(in or out).
 *
 */
void udrv_gpio_set_dir(uint32_t pin, gpio_dir_t dir);

/**
 * @brief   Setup GPIO input pull down or pull up or none.
 *
 * @param   pin                             GPIO pin number.
 * @param   pull                            GPIO pull up or down.
 *
 */
void udrv_gpio_set_pull(uint32_t pin, gpio_pull_t pull);

/**
 * @brief   Setup GPIO output logic.
 *
 * @param   pin                             GPIO pin number.
 * @param   logic                           GPIO logic high or low.
 *
 */
void udrv_gpio_set_logic(uint32_t pin, gpio_logic_t logic);

/**
 * @brief   Get GPIO logic status.
 *
 * @param   pin                             GPIO pin number.
 *
 * @return   0                              GPIO logic state LOW.
 *           1                              GPIO logic state HIGH.              
 */
gpio_logic_t udrv_gpio_get_logic(uint32_t pin);

/**
 * @brief   Toggle GPIO output logic.
 *
 * @param   pin                             GPIO pin number.
 *
 */
void udrv_gpio_toggle_logic(uint32_t pin);

/**
 * @brief   Setting gpio interrupt trigger mode
 *
 * @param   pin                             GPIO pin number.
 * @param   mode                            gpio input interrupt trigger mode.
 *
 */
void udrv_gpio_intc_trigger_mode(uint32_t pin, gpio_intc_trigger_mode_t mode);

/**
 * @brief   Setting an interrupt handler that interrupt occurs.
 *
 * @param   pin                             GPIO pin number.
 * @param   handler                         A pointer to an interrupt handler that interrupt occurs.
 *
 * @return  -1                              The operation error.
 * @return   0                              The operation completed successfully.         
 */
int32_t udrv_gpio_register_isr(uint32_t pin, gpio_isr_func handler);

/**
 * @brief   clear the interrupt trigger.
 *
 * @param   pin                             GPIO pin number.
 *
 */
void udrv_gpio_intc_clear(uint32_t pin);

/**
 * @brief   Enable GPIO wake up pmu.
 *
 * @param   pin                             GPIO pin number.
 *
 */
void udrv_gpio_set_wakeup_enable(uint32_t pin);

/**
 * @brief   Disable GPIO wake up pmu.
 *
 * @param   pin                             GPIO pin number.
 *
 */
void udrv_gpio_set_wakeup_disable(uint32_t pin);

/**
 * @brief   Disable all GPIO wake up pmu.
 *
 */
void udrv_gpio_set_wakeup_disable_all(void);

/**
 * @brief   Set the wakeup trigger mode.
 *
 * @param   mode                        Interrupt mode.
 *
 */
void udrv_gpio_set_wakeup_mode(gpio_intc_trigger_mode_t mode);

/**
 * @brief   Suspend GPIO hardware before entering sleep mode.
 *
 */
void udrv_gpio_suspend();

/**
 * @brief   Resume GPIO hardware after leaving sleep mode.
 *
 */
void udrv_gpio_resume();

void udrv_gpio_handler_handler (void *pdata);

#ifdef __cplusplus
}
#endif

#endif  // __UDRV_GPIO_H__

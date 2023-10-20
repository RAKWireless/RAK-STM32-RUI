#include "udrv_pwm.h"
#include "udrv_errno.h"
#include "uhal_pwm.h"
#include "uhal_timer.h"
//#include "udrv_serial.h"

static udrv_pwm_port curr_port = UDRV_PWM_MAX;
static void udrv_pwm_handler(void *p_context) {
    //udrv_serial_log_printf("pwm_port=%u\r\n", *(udrv_pwm_port *)p_context);
    uhal_pwm_disable(*(udrv_pwm_port *)p_context);
    uhal_pwm_deinit(*(udrv_pwm_port *)p_context);
}

void udrv_pwm_init(udrv_pwm_port port, uint32_t freq_hz, uint8_t is_invert, uint32_t pin) {
    uhal_pwm_init(port, freq_hz, is_invert, pin);
}

void udrv_pwm_deinit(udrv_pwm_port port) {
    uhal_pwm_deinit(port);
}

int32_t udrv_pwm_set_duty(udrv_pwm_port port, uint32_t duty) {
    return uhal_pwm_set_duty(port, duty);
}

int32_t udrv_pwm_enable(udrv_pwm_port port, uint32_t duration) {
        uhal_pwm_enable(port);
        curr_port = port;
        if (duration != PWM_NO_TIMEOUT) {
            uhal_pwm_timer_create(udrv_pwm_handler, HTMR_ONESHOT);
            uhal_pwm_timer_start(duration, (void *)&curr_port);
        }
}

void udrv_pwm_disable(udrv_pwm_port port) {
    uhal_pwm_timer_stop();
    uhal_pwm_disable(port);
}

void udrv_pwm_suspend(void) {
    uhal_pwm_suspend();
}

void udrv_pwm_resume(void) {
    uhal_pwm_resume();
}

UDRV_PWM_RESOLUTION udrv_pwm_get_resolution (void) {
    return uhal_pwm_get_resolution();
}
void udrv_pwm_set_resolution (UDRV_PWM_RESOLUTION resolution) {
    uhal_pwm_set_resolution(resolution);
}

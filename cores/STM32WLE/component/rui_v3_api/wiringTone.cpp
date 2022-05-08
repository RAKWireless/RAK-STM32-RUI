#include "ruiTop.h"
#include "udrv_pwm.h"
#include "udrv_timer.h"
#include "variant.h"

bool PWM_isUsed = false;

void noTone(uint8_t pin)
{
  udrv_pwm_disable((udrv_pwm_port)0);
  udrv_pwm_deinit((udrv_pwm_port)0);
  PWM_isUsed = false;
}


void tone(uint8_t pin, uint32_t freq, uint64_t duration)
{
  // get resolution	
  uint32_t dutyMax;
  switch (udrv_pwm_get_resolution())
  {
    case UDRV_PWM_RESOLUTION_8BIT:
      dutyMax = 256;
      break;
    case UDRV_PWM_RESOLUTION_10BIT:
      dutyMax = 1024;
      break;
    case UDRV_PWM_RESOLUTION_12BIT:
      dutyMax = 4096;
      break;
    case UDRV_PWM_RESOLUTION_14BIT:
      dutyMax = 16384;
      break;
    default:
      dutyMax = 256;
      break;
  }

  // check if port is used
  if (PWM_isUsed)
    noTone(pin);
  udrv_pwm_init((udrv_pwm_port)0, freq, 1, pin);

  // overload for duration
  if(duration == 0) {
      udrv_pwm_enable((udrv_pwm_port)0, PWM_NO_TIMEOUT);
  } else {
      udrv_pwm_enable((udrv_pwm_port)0, duration);
  }
  udrv_pwm_set_duty((udrv_pwm_port)0, (uint32_t)dutyMax/2);
  PWM_isUsed = true;
}

void analogWrite(uint8_t pin, int val)
{
  // check if port is used
  if (PWM_isUsed)
    noTone(pin);

  udrv_pwm_init((udrv_pwm_port)0, 490, 1, pin);
  udrv_pwm_enable((udrv_pwm_port)0, PWM_NO_TIMEOUT);
  udrv_pwm_set_duty((udrv_pwm_port)0, (uint32_t)val);
  PWM_isUsed = true;
}

void analogWriteResolution(uint8_t bits)
{
    if (!bits || bits > 14) {
        return;
    }

    if (bits <= 8) {
        udrv_pwm_set_resolution(UDRV_PWM_RESOLUTION_8BIT);
    } else if (bits <= 10) {
        udrv_pwm_set_resolution(UDRV_PWM_RESOLUTION_10BIT);
    } else if (bits <= 12) {
        udrv_pwm_set_resolution(UDRV_PWM_RESOLUTION_12BIT);
    } else {//bits <= 14
        udrv_pwm_set_resolution(UDRV_PWM_RESOLUTION_14BIT);
    }
}

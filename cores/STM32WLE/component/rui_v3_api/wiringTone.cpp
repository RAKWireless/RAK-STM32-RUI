#include "ruiTop.h"
#include "udrv_pwm.h"
#include "udrv_timer.h"
#include "variant.h"

struct used_pwm_ports
{
    uint8_t cur_port = 0;
    uint8_t pins[UDRV_PWM_MAX] = {0};
}used_pwm_ports;

void noTone(uint8_t pin)
{
    int i;
    for(i=0;i<UDRV_PWM_MAX;i++)
    {
        if(used_pwm_ports.pins[i] == pin)
        {
            udrv_pwm_disable((udrv_pwm_port)i);
            udrv_pwm_deinit((udrv_pwm_port)i);
            used_pwm_ports.pins[i] =0;
        }

    }
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

    int i;
    for(i=0;i<UDRV_PWM_MAX;i++)
    {
        if(used_pwm_ports.pins[i] == pin || used_pwm_ports.pins[i] ==0)
        {
            used_pwm_ports.cur_port = i;
            used_pwm_ports.pins[i] = pin;
            break;
        }
        if(i == UDRV_PWM_MAX-1)
        {
            used_pwm_ports.cur_port = 0;
            used_pwm_ports.pins[0] = pin;
        }
    }

  udrv_pwm_disable((udrv_pwm_port)used_pwm_ports.cur_port);
  udrv_pwm_deinit((udrv_pwm_port)used_pwm_ports.cur_port);
  udrv_pwm_init((udrv_pwm_port)used_pwm_ports.cur_port, freq, 1, pin);

  // overload for duration
  if(duration == 0) {
      udrv_pwm_enable((udrv_pwm_port)used_pwm_ports.cur_port, PWM_NO_TIMEOUT);
  } else {
      udrv_pwm_enable((udrv_pwm_port)used_pwm_ports.cur_port, duration);
  }
  udrv_pwm_set_duty((udrv_pwm_port)used_pwm_ports.cur_port, (uint32_t)dutyMax/2);
}

void analogWrite(uint8_t pin, int val)
{
    int i;
    for(i=0;i<UDRV_PWM_MAX;i++)
    {
        if(used_pwm_ports.pins[i] == pin || used_pwm_ports.pins[i] ==0)
        {
            used_pwm_ports.cur_port = i;
            used_pwm_ports.pins[i] = pin;
            break;
        }
        if(i == UDRV_PWM_MAX-1)
        {
            used_pwm_ports.cur_port = 0;
            used_pwm_ports.pins[0] = pin;
        }

    }
    udrv_pwm_disable((udrv_pwm_port)used_pwm_ports.cur_port);
    udrv_pwm_deinit((udrv_pwm_port)used_pwm_ports.cur_port);
    udrv_pwm_init((udrv_pwm_port)used_pwm_ports.cur_port, 490, 1, pin);
    udrv_pwm_enable((udrv_pwm_port)used_pwm_ports.cur_port, PWM_NO_TIMEOUT);
    udrv_pwm_set_duty((udrv_pwm_port)used_pwm_ports.cur_port, (uint32_t)val);
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

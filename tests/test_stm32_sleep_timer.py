"""Host regression for STM32 shared sleep-timer recreation after early wakes.

Contribution by Antoine Lefebvre, Novations AGL inc.
"""
from pathlib import Path
import os
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
SDK = Path(os.environ.get('RUI_STM32_CORE', str(ROOT / 'cores/STM32WLE')))
TIMER = SDK / 'external/STM32CubeWL/Utilities/timer'
UHAL = SDK / 'component/core/mcu/stm32wle5xx/uhal'


@unittest.skipUnless((TIMER / 'stm32_timer.c').is_file(), 'Requires STM32 RUI source; set RUI_STM32_CORE')
class SleepTimerTests(unittest.TestCase):
    def test_early_wake_keeps_radio_button_and_measurement_timers(self):
        with tempfile.TemporaryDirectory() as folder:
            p = Path(folder)
            (p / 'cmsis_compiler.h').write_text('')
            (p / 'utilities_conf.h').write_text('''
extern uint32_t mock_irq_mask;
#define UTILS_ENTER_CRITICAL_SECTION() uint32_t saved_irq_mask = mock_irq_mask; mock_irq_mask = 1
#define UTILS_EXIT_CRITICAL_SECTION() mock_irq_mask = saved_irq_mask
''')
            # Compile the unchanged SDK sleep adapter, substituting only the
            # hardware declarations. Its timer create/stop/start code is real.
            shutil.copyfile(UHAL / 'uhal_powersave.c', p / 'uhal_powersave.c')
            (p / 'radio_conf.h').write_text('')
            (p / 'udrv_errno.h').write_text('#define UDRV_RETURN_OK 0\n#define UDRV_INTERNAL_ERR 1\n')
            (p / 'uhal_powersave.h').write_text('''
#include "stm32_timer.h"
typedef void (*timer_handler)(void *);
typedef enum { HTMR_ONESHOT, HTMR_PERIODIC } TimerMode_E;
int32_t uhal_ps_timer_create(timer_handler, TimerMode_E);
int32_t uhal_ps_timer_start(uint32_t, void *);
int32_t uhal_ps_timer_stop(void);
#define CRITICAL_SECTION_BEGIN() UTILS_ENTER_CRITICAL_SECTION()
#define CRITICAL_SECTION_END() UTILS_EXIT_CRITICAL_SECTION()
#define HAL_SuspendTick() ((void)0)
#define HAL_ResumeTick() ((void)0)
#define LL_PWR_ClearFlag_C1STOP_C1STB() ((void)0)
#define HAL_PWREx_EnterSTOP1Mode(x) ((void)(x))
#define HAL_PWREx_EnterSTOP2Mode(x) ((void)(x))
#define PWR_STOPENTRY_WFI 0
#define SystemClock_Config() ((void)0)
''')
            (p / 'test.c').write_text(r'''
#include <assert.h>
#include <stdio.h>
#include "uhal_powersave.h"
extern bool TimerExists(UTIL_TIMER_Object_t *);
uint32_t mock_irq_mask;
static uint32_t now, context;
static UTIL_TIMER_Status_t ok(void) { return UTIL_TIMER_OK; }
static UTIL_TIMER_Status_t start(uint32_t t) { (void)t; return UTIL_TIMER_OK; }
static uint32_t set_context(void) { return context = now; }
static uint32_t get_context(void) { return context; }
static uint32_t elapsed(void) { return now - context; }
static uint32_t get_now(void) { return now; }
static uint32_t minimum(void) { return 1; }
static uint32_t identity(uint32_t t) { return t; }
const UTIL_TIMER_Driver_s UTIL_TimerDriver = {
 ok, ok, start, ok, set_context, get_context, elapsed, get_now, minimum, identity, identity
};
static unsigned measurement_calls, radio_calls, sleep_calls;
static void measurement_callback(void *p) { (void)p; ++measurement_calls; }
static void radio_callback(void *p) { (void)p; ++radio_calls; }
static void callback(void *p) { (void)p; ++sleep_calls; }
static void button_callback(void *p) { (void)p; }
static void timed_sleep(void) {
 /* Exact timer sequence from udrv_sleep_ms, including wake before entry. */
 assert(uhal_ps_timer_create(callback, HTMR_ONESHOT) == 0);
 assert(uhal_ps_timer_stop() == 0);
 assert(uhal_ps_timer_start(250, NULL) == 0);
}
int main(void) {
 UTIL_TIMER_Object_t periodic = {0}, radio = {0}, button = {0};
 UTIL_TIMER_Init();
 /* Creation before any application timer exists must also be safe. */
 assert(uhal_ps_timer_create(callback, HTMR_ONESHOT) == 0);
 UTIL_TIMER_Create(&periodic, 900000, UTIL_TIMER_ONESHOT, measurement_callback, NULL);
 UTIL_TIMER_Start(&periodic);
 UTIL_TIMER_Create(&radio, 1000, UTIL_TIMER_ONESHOT, radio_callback, NULL);
 UTIL_TIMER_Start(&radio);
 timed_sleep();
 now = 10; /* Button IRQ wakes sleep early; original sleep timer remains linked. */
 UTIL_TIMER_Create(&button, 100, UTIL_TIMER_PERIODIC, button_callback, NULL);
 UTIL_TIMER_Start(&button);
 timed_sleep();
 assert(TimerExists(&button));
 assert(TimerExists(&periodic) && TimerExists(&radio));
 assert(mock_irq_mask == 0);
 mock_irq_mask = 1;
 timed_sleep();
 assert(mock_irq_mask == 1);
 mock_irq_mask = 0;
 for (unsigned i = 0; i < 20; ++i) {
  ++now;
  timed_sleep();
  assert(TimerExists(&periodic) && TimerExists(&radio) && TimerExists(&button));
 }
 assert(uhal_ps_timer_create(NULL, HTMR_ONESHOT) == -1);
 assert(mock_irq_mask == 0);
 now = 300;
 UTIL_TIMER_IRQ_Handler();
 assert(sleep_calls == 1);
 now = 1001;
 UTIL_TIMER_IRQ_Handler();
 assert(radio_calls == 1 && measurement_calls == 0);
 now = 900001;
 UTIL_TIMER_IRQ_Handler();
 assert(measurement_calls == 1);
 puts("Early-wake retries preserve timers and radio/measurement callbacks fire");
 return 0;
}
''')
            include = ['-I' + str(p), '-I' + str(TIMER)]
            for source in [TIMER / 'stm32_timer.c', p / 'uhal_powersave.c']:
                subprocess.run(['cc', '-std=c99', *include, '-c', str(source),
                                '-o', str(p / (source.stem + '.o'))], check=True)
            objects = [str(p / 'stm32_timer.o'), str(p / 'uhal_powersave.o')]
            subprocess.run(['cc', '-std=c99', '-Wall', '-Wextra', '-Werror',
                            *include, '-c', str(p / 'test.c'),
                            '-o', str(p / 'test.o')], check=True)
            subprocess.run(['cc', *objects, str(p / 'test.o'),
                            '-o', str(p / 'test')], check=True)
            subprocess.run([str(p / 'test')], check=True, timeout=10)


if __name__ == '__main__':
    unittest.main()

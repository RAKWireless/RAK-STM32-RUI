#include "service_debug.h"
#include "udrv_serial.h"
#include "stdarg.h"
#ifdef rak3172
#include "main.h"
#endif


#define DEBUG_LEVEL_OPEN         1
#define ERROR_LEVEL_CLOSED		 0


void service_debug(const char *fmt, ...)
{
    uint8_t debug_level ;
    char debug_buf[512];
    va_list aptr;

    debug_level = service_get_debug_level();

    switch (debug_level)
    {
        case DEBUG_LEVEL_OPEN:
            va_start (aptr, fmt);
            vsprintf (debug_buf, fmt, aptr);
            va_end (aptr);
            udrv_serial_log_printf(debug_buf);
            break;
        case ERROR_LEVEL_CLOSED:
            break;
        default:
            break;
    }
}

uint32_t service_set_debug_level(uint8_t level)
{
    return service_nvm_set_debug_level_to_nvm(level); 
}

uint8_t service_get_debug_level(void)
{
    return service_nvm_get_debug_level_from_nvm();
}


void service_debug_swo(const char *fmt, ...)
{
    #ifdef rak3172
    uint8_t debug_level ;
    uint8_t i = 0; 
    char debug_buf[512];
    va_list aptr;

    __HAL_RCC_GPIOB_CLK_ENABLE();
    debug_level = service_get_debug_level();

    switch (debug_level)
    {
        case DEBUG_LEVEL_OPEN:
            va_start (aptr, fmt);
            vsprintf (debug_buf, fmt, aptr);
            va_end (aptr);
            while(debug_buf[i])
            {
                ITM_SendChar((uint32_t)debug_buf[i]);
                i++;
            }
            break;
        case ERROR_LEVEL_CLOSED:
            break;
        default:
            break;
    }
    #endif
}


#ifdef SUPPORT_AT
#include <string.h>
#include "atcmd.h"
#include "atcmd_general.h"
#include "udrv_errno.h"
#include "udrv_system.h"

extern uint32_t orig_auto_sleep_time;

int At_Sleep(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0) 
    {
        udrv_sleep_ms(0);
        return AT_OK;   
    }
    else if (param->argc == 1)
    {
        uint32_t input;
        char * input_s = "4294967295";
        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }
 
        input = strtoul(param->argv[0], NULL, 10);
        if (input == 0xFFFFFFFFUL)
        {
            if(strcmp(param->argv[0],input_s))
                return AT_PARAM_ERROR;
        }
        if (input == 0)
        {
            return AT_PARAM_ERROR;
        }
        udrv_sleep_ms(input);
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_AutoSleep(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_nvm_get_auto_sleep_time_from_nvm());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t input;

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        input = strtoul(param->argv[0], NULL, 10);

        if (input != 0 && input != 1)
        {
            return AT_PARAM_ERROR;
        }

        ret = service_nvm_set_auto_sleep_time_to_nvm(input);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else
        {
            return AT_ERROR;
        }
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}
#endif


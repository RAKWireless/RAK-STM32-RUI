#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_cert.h"
#include "service_lora_test.h"
#include "udrv_errno.h"

static uint32_t lct;

int At_Trssi(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    int16_t rssiVal;

    if (param->argc == 0)
    {
        if ((ret = service_lora_trssi(&rssiVal)) == UDRV_RETURN_OK)
        {
            atcmd_printf("%s=%d\r\n", cmd, rssiVal);
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
	else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

int At_Ttone(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;

    if (param->argc == 0)
    {
        if ((ret = service_lora_ttone()) == UDRV_RETURN_OK)
        {
            atcmd_printf("Tx tone");
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

int At_Ttx(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    uint32_t nb_packet;

    if (param->argc == 1)
    {   
        if (0 != at_check_digital_uint32_t(param->argv[0], &nb_packet))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if ((ret = service_lora_ttx(nb_packet)) == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

int At_Trx(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    uint32_t nb_packet;

    if (param->argc == 1)
    {   
        if (0 != at_check_digital_uint32_t(param->argv[0],&nb_packet))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if ((ret = service_lora_trx(nb_packet)) == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

int At_Tconf(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    testParameter_t Param;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        service_lora_get_tconf(&Param);
        atcmd_printf("%s=%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d:%d\r\n", cmd, Param.frequency, Param.power, Param.bandwidth, Param.datarate, Param.coderate, Param.lna,
                     Param.paBoost, Param.modem, Param.payloadLen, Param.fdev, Param.lowDrOpt, Param.BTproduct);
        return AT_OK;
    }
    else if (param->argc == 12)
    {
        if (0 != at_check_digital_uint32_t(param->argv[0], &Param.frequency))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }
        if (0 != at_check_digital_uint32_t(param->argv[1],&Param.power))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[2], &Param.bandwidth))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[3], &Param.datarate))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[4], &Param.coderate))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[5], &Param.lna))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[6], &Param.paBoost))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[7], &Param.modem))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[8], &Param.payloadLen))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[9], &Param.fdev))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[10], &Param.lowDrOpt))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[11], &Param.BTproduct))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if ((ret = service_lora_set_tconf(&Param)) == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

int At_Tth(SERIAL_PORT port, char *cmd, stParam *param)
{
    testParameter_t Param;
    uint32_t freq_start;
    uint32_t freq_stop;
    uint32_t hp_step;
    uint32_t nb_tx;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        service_lora_get_tconf(&Param);
        atcmd_printf("%s=%d:%d:%d:%d\r\n", cmd, Param.freq_start,Param.freq_stop,Param.hp_step,Param.nb_tx);
        return AT_OK;
    }
    else if (param->argc == 4)
    {
        if (0 != at_check_digital_uint32_t(param->argv[0], &Param.freq_start))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }
        if (0 != at_check_digital_uint32_t(param->argv[1],&Param.freq_stop))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[2], &Param.hp_step))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[3], &Param.nb_tx))
        { 
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }
        
        if(Param.freq_start > Param.freq_stop)
        {
            return AT_PARAM_ERROR;
        }

        return service_lora_tth(&Param);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_Toff(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0)
    {
        service_lora_toff();
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_Certif(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 0)
    {
        if (service_lora_certification(1) == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else
        {
            return AT_ERROR;
        }
    }
    else if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, lct);
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        lct = strtoul(param->argv[0], NULL, 10);
        if (lct != 0 && lct != 1)
        {
            return AT_PARAM_ERROR;
        }

        if (service_lora_certification(lct) == UDRV_RETURN_OK)
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

int At_Cw(SERIAL_PORT port, char *cmd, stParam *param)
{
    LORA_TEST_DEBUG();
    int32_t ret;
    testCwParameter_t Param;
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        service_lora_get_cw(&Param);
        atcmd_printf("%s=%d:%d:%d\r\n", cmd, Param.frequency, Param.txpower, Param.txTimeout);
        return AT_OK;
    }
    else if (param->argc == 3)
    {
        if (0 != at_check_digital_uint32_t(param->argv[0], &Param.frequency))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }
        if (0 != at_check_digital_uint32_t(param->argv[1], &Param.txpower))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if (0 != at_check_digital_uint32_t(param->argv[2], &Param.txTimeout))
        {
            LORA_TEST_DEBUG();
            return AT_PARAM_ERROR;
        }

        if ((ret = service_lora_set_cw(&Param)) == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
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

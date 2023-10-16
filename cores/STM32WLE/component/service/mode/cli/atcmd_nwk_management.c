#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_nwk_management.h"
#include "udrv_errno.h"
#include "service_lora.h"

int At_ADR (SERIAL_PORT port, char *cmd, stParam *param) {

    UDRV_RETURN_CODE status;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_adr());
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t adr;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        adr = strtoul(param->argv[0], NULL, 10);
        if (adr != 0 && adr != 1) {
            return AT_PARAM_ERROR;
        }

        status = service_lora_set_adr((bool)adr, true);

        if (status == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (status == -UDRV_BUSY) 
        {
            return AT_BUSY_ERROR;
        }
        else if (status == -UDRV_WRONG_ARG)
        {
            return AT_PARAM_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_Class (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        switch (service_lora_get_class()) {
            case SERVICE_LORA_CLASS_A:
                atcmd_printf("%s=A\r\n", cmd);
                break;
            case SERVICE_LORA_CLASS_B:
                switch (service_lora_get_class_b_state()) {
                    case SERVICE_LORA_CLASS_B_S0:
                        atcmd_printf("%s=B:S0\r\n", cmd);
                        break;
                    case SERVICE_LORA_CLASS_B_S1:
                        atcmd_printf("%s=B:S1\r\n", cmd);
                        break;
                    case SERVICE_LORA_CLASS_B_S2:
                        atcmd_printf("%s=B:S2\r\n", cmd);
                        break;
                    case SERVICE_LORA_CLASS_B_S3:
                        atcmd_printf("%s=B:S3\r\n", cmd);
                        break;
                    case SERVICE_LORA_CLASS_B_COMPLETED:
                    default:
                        atcmd_printf("%s=B\r\n", cmd);
                        break;
                }
                break;
            case SERVICE_LORA_CLASS_C:
                atcmd_printf("%s=C\r\n", cmd);
                break;
            default:
                return AT_ERROR;
        }
        return AT_OK;
    } else if (param->argc == 1) {
        if (!strcasecmp(param->argv[0], "A")) {
            if (service_lora_set_class(SERVICE_LORA_CLASS_A, true) == UDRV_RETURN_OK) {
                return AT_OK;
            }
        }

        if (!strcasecmp(param->argv[0], "B")) {
            if (service_lora_set_class(SERVICE_LORA_CLASS_B, true) == UDRV_RETURN_OK) {
                return AT_OK;
            }
        }

        if (!strcasecmp(param->argv[0], "C")) {
            if (service_lora_set_class(SERVICE_LORA_CLASS_C, true) == UDRV_RETURN_OK) {
                return AT_OK;
            }
        }

        return AT_PARAM_ERROR;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_DCS (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_dcs());
        return AT_OK;
    } else {
        uint8_t dcs;
        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }
        dcs = strtoul(param->argv[0], NULL, 10);
        if((dcs!=0)&&(dcs !=1))
        {
            return AT_PARAM_ERROR;
        }
        return service_lora_set_dcs(dcs,true);
    }
}

int At_DataRate (SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_dr());
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t dr;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        dr = strtoul(param->argv[0], NULL, 10);
        //if (dr < SERVICE_LORA_DR_0 || dr > SERVICE_LORA_DR_15) {
        //    return AT_PARAM_ERROR;
        //}

        ret = service_lora_set_dr((SERVICE_LORA_DATA_RATE)dr, true);
        if (ret == UDRV_RETURN_OK) {
            return AT_OK;
        } else if (ret == -UDRV_WRONG_ARG) {
            return AT_PARAM_ERROR;
        } else {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin1JoinDelay (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_jn1dl()/1000);//change unit from ms to s
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t jn1dl;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        jn1dl = strtoul(param->argv[0], NULL, 10);
        if (jn1dl < 1 || jn1dl > 14) {//unit is second
            return AT_PARAM_ERROR;
        }

        if (jn1dl >= service_lora_get_jn2dl()/1000) {//change unit from ms to s
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_jn1dl(jn1dl*1000, true) != UDRV_RETURN_OK) {//change unit from s to ms
            return AT_ERROR;
        }

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin2JoinDelay (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_jn2dl()/1000);//change unit from ms to s
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t jn2dl;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }
        
        jn2dl = strtoul(param->argv[0], NULL, 10);
        if (jn2dl < 2 || jn2dl > 15) {//unit is Second
            return AT_PARAM_ERROR;
        }

        if (jn2dl <= service_lora_get_jn1dl()/1000) {//change unit from ms to s
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_jn2dl(jn2dl*1000, true) != UDRV_RETURN_OK) {//change unit from s to ms
            return AT_ERROR;
        }

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_PubNwkMode (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_pub_nwk_mode());
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t pnm;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        pnm = strtoul(param->argv[0], NULL, 10);
        if (pnm != 0 && pnm != 1) {
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_pub_nwk_mode((bool)pnm, true) != UDRV_RETURN_OK) {
            return AT_ERROR;
        }

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin1Delay (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_rx1dl()/1000);//change unit from ms to s
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t rx1dl;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        rx1dl = strtoul(param->argv[0], NULL, 10);
        if (rx1dl < 1 || rx1dl > 15) {//unit is second
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_rx1dl(rx1dl*1000, true) != UDRV_RETURN_OK) {//change unit from s to ms
            return AT_ERROR;
        }

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin2Delay (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_rx2dl()/1000);//change unit from ms to s
        return AT_OK;
    } else if (param-> argc == 1) {
        uint32_t rx2dl;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        rx2dl = strtoul(param->argv[0], NULL, 10);
        if (rx2dl < 2 || rx2dl > 16) {//unit is second
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_rx2dl(rx2dl*1000, true) != UDRV_RETURN_OK) {//change unit from s to ms
            return AT_ERROR;
        }

        return AT_OK;
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin2DataRate (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_rx2dr());
        return AT_OK;
    } else if (param->argc == 1) {
        uint32_t dr;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
	}

        dr = strtoul(param->argv[0], NULL, 10);
        //if (dr < SERVICE_LORA_DR_0 || dr > SERVICE_LORA_DR_7) {
        //    return AT_PARAM_ERROR;
        //}

        ret = service_lora_set_rx2dr((SERVICE_LORA_DATA_RATE)dr, true);
        if (ret == UDRV_RETURN_OK) {
            return AT_OK;
        } else if (ret == -UDRV_WRONG_ARG) {
            return AT_PARAM_ERROR;
        } else {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_RxWin2Freq (SERIAL_PORT port, char *cmd, stParam *param) 
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    int32_t ret;

    if(param->argc == 1 && !strcmp(param->argv[0], "?")) 
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_rx2freq());
        return AT_OK;
    } 
    else if(param->argc == 1)
    {
        uint32_t freq;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) 
        {
            if (!isdigit(*(param->argv[0]+i))) 
            {
                return AT_PARAM_ERROR;
            }
	    }
        freq = strtoul(param->argv[0], NULL, 10);

        ret = service_lora_set_rx2freq(freq, true);

        if (ret == UDRV_RETURN_OK) {
            return AT_OK;
        } else if (ret == -UDRV_WRONG_ARG) {
            return AT_PARAM_ERROR;
        } else {
            return AT_ERROR;
        }
    }
    else 
    {
        return AT_PARAM_ERROR;
    }
}


int At_TxPower (SERIAL_PORT port, char *cmd, stParam *param) {
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?")) {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_txpower());
        return AT_OK;
    } else if (param->argc == 1) {
        uint8_t txp;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        txp = (uint8_t)strtoul(param->argv[0], NULL, 10);

        if (txp > SERVICE_LORA_TX_POWER_MAX) {
            return AT_PARAM_ERROR;
	}

        ret = service_lora_set_txpower(txp, true);
        if (ret == UDRV_RETURN_OK) {
            return AT_OK;
	} else if (ret == -UDRV_WRONG_ARG) {
            return AT_PARAM_ERROR;
        } else {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

int At_LinkCheck(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_linkcheck());
        return AT_OK;
    }
    else
    {
        uint8_t linkcheck_mode;

        if (0 != at_check_digital_uint32_t(param->argv[0], &linkcheck_mode))
        {
            return AT_PARAM_ERROR;
        }

        if(linkcheck_mode>2)
        {
            return AT_PARAM_ERROR;
        }


        return service_lora_set_linkcheck(linkcheck_mode);
    }
}

int At_Timereq(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret = AT_OK;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_timereq());
        return AT_OK;
    }
    else
    {
        uint8_t timereq_mode;

        if (0 != at_check_digital_uint32_t(param->argv[0], &timereq_mode))
        {
            return AT_PARAM_ERROR;
        }
        if(timereq_mode>1)
        {
            return AT_PARAM_ERROR;
        }
        ret =  service_lora_set_timereq(timereq_mode);       
    }
    return at_error_code_form_udrv(ret);
}

int At_Lbt(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret = AT_OK;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_lbt());
        return AT_OK;
    }
    else
    {
        uint8_t enable;

        if (0 != at_check_digital_uint32_t(param->argv[0], &enable))
        {
            return AT_PARAM_ERROR;
        }
        if(enable>1)
        {
            return AT_PARAM_ERROR;
        }
        ret =  service_lora_set_lbt(enable);       
    }
    return at_error_code_form_udrv(ret);

}

int At_LbtRssi(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret = AT_OK;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_lbt_rssi());
        return AT_OK;
    }
    else
    {
        int16_t rssi;
        rssi = atoi(param->argv[0]);
        ret =  service_lora_set_lbt_rssi(rssi);       
    }
    return at_error_code_form_udrv(ret);

}

int At_LbtScantime(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret = AT_OK;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_lbt_scantime());
        return AT_OK;
    }
    else
    {
        uint32_t time;

        if (0 != at_check_digital_uint32_t(param->argv[0], &time))
        {
            return AT_PARAM_ERROR;
        }
        ret =  service_lora_set_lbt_scantime(time);       
    }
    return at_error_code_form_udrv(ret);

}



#endif
#endif

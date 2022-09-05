#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_p2p.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "service_lora_test.h"
#include "board.h"

static void dump_hex2str(uint8_t *buf, uint8_t len)
{
    for (uint8_t i = 0; i < len; i++)
    {
        atcmd_printf("%02X", buf[i]);
    }
    atcmd_printf("\r\n");
}

int At_NwkWorkMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_nwm());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        if (strlen(param->argv[0]) != 1)
            return AT_PARAM_ERROR;

        if ((param->argv[0][0] == '0') || (param->argv[0][0] == '1')||(param->argv[0][0] == '2'))
        {
            if (service_lora_set_nwm((SERVICE_LORA_WORK_MODE)atoi(param->argv[0])) == UDRV_RETURN_OK) {
                return AT_OK;
            } else {
                return AT_ERROR;
            }
        }
        else
        {
            return AT_PARAM_ERROR;
        }
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pFreq(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_freq());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint8_t status = 0;
        uint32_t frequency;

        if (0 != at_check_digital_uint32_t(param->argv[0], &frequency))
            return AT_PARAM_ERROR;

        if ((frequency < 150e6) || (frequency > 960e6))
            return AT_PARAM_ERROR;

        status =  service_lora_p2p_set_freq(frequency);
        return at_error_code_form_udrv(status);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pSF(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_sf());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t spreading_factor;

        if (0 != at_check_digital_uint32_t(param->argv[0], &spreading_factor))
            return AT_PARAM_ERROR;

        if ((spreading_factor < 5) || (spreading_factor > 12))
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_sf((uint8_t)spreading_factor) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pBW(SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t status = 0;

    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_bandwidth());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t bandwidth;

        if (0 != at_check_digital_uint32_t(param->argv[0], &bandwidth))
            return AT_PARAM_ERROR;
        
        if (SERVICE_LORA_FSK == service_lora_get_nwm())
        {
           if(bandwidth < 4800 || bandwidth > 467000 )
           return AT_PARAM_ERROR;
        }
        else
        {
            if(bandwidth > 9 )
            return AT_PARAM_ERROR;
        }

        status = service_lora_p2p_set_bandwidth(bandwidth);
        return at_error_code_form_udrv(status);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pCR(SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t status = 0;
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_codingrate());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t coding_rate;

        if (0 != at_check_digital_uint32_t(param->argv[0], &coding_rate))
            return AT_PARAM_ERROR;

        status = service_lora_p2p_set_codingrate((uint8_t)coding_rate) ;
        
        return at_error_code_form_udrv(status);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pPL(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_preamlen());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t preamble_length;

        if (0 != at_check_digital_uint32_t(param->argv[0], &preamble_length))
            return AT_PARAM_ERROR;

        if(preamble_length< 5)
            return AT_PARAM_ERROR;

        if(preamble_length > 65535)
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_preamlen((uint16_t)preamble_length) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pTP(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_powerdbm());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t txpower;

        if (0 != at_check_digital_uint32_t(param->argv[0], &txpower))
            return AT_PARAM_ERROR;

        if ((txpower < 5) || (txpower > 22))
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_powerdbm((uint8_t)txpower) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pSend(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        return AT_PARAM_ERROR;
    }
    else if (param->argc == 1)
    {
        uint32_t datalen;
        uint8_t lora_data[256];
        
        datalen = strlen(param->argv[0]);
        if ((datalen % 2) || (datalen > 2 * 256))
            return AT_PARAM_ERROR;
       
        if (0 != at_check_hex_param(param->argv[0], datalen, lora_data))
            return AT_PARAM_ERROR;
       
        if (-UDRV_BUSY == service_lora_p2p_send(lora_data, datalen / 2))
            return AT_BUSY_ERROR;

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pRecv(SERIAL_PORT port, char *cmd, stParam *param)
{
    uint8_t status;

    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc == 1)
    {
        uint32_t timeout;

        if (0 != at_check_digital_uint32_t(param->argv[0], &timeout))
            return AT_PARAM_ERROR;

        if (timeout > 65535)
            return AT_PARAM_ERROR;

        status = service_lora_p2p_recv(timeout);
     
        return at_error_code_form_udrv(status);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pCrypt(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_crypto_enable());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t crypto_enable;

        if (0 != at_check_digital_uint32_t(param->argv[0], &crypto_enable))
            return AT_PARAM_ERROR;

        if (crypto_enable > 1)
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_crypto_enable((bool)crypto_enable) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2pKey(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        uint8_t rbuff[8];
        if (service_lora_p2p_get_crypto_key(rbuff, 8) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }
        atcmd_printf("%s=", cmd);
        dump_hex2str(rbuff, 8);
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t datalen;
        uint8_t crypt_key[8];

        datalen = strlen(param->argv[0]);
        if (datalen != 16)
            return AT_PARAM_ERROR;

        if (0 != at_check_hex_param(param->argv[0], 16, crypt_key))
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_crypto_key(crypt_key, 8) != UDRV_RETURN_OK)
            return AT_ERROR;

        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_P2p(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=", cmd);
        atcmd_printf("%u:", service_lora_p2p_get_freq());
        atcmd_printf("%u:", service_lora_p2p_get_sf());
        atcmd_printf("%u:", service_lora_p2p_get_bandwidth());  
        atcmd_printf("%u:", service_lora_p2p_get_codingrate());
        atcmd_printf("%u:", service_lora_p2p_get_preamlen());
        atcmd_printf("%u\r\n",service_lora_p2p_get_powerdbm());
        return AT_OK;
    }
    else if (param->argc == 6)
    {
        uint32_t frequency;
        if (0 != at_check_digital_uint32_t(param->argv[0], &frequency))
            return AT_PARAM_ERROR;
        if ((frequency < 150e6) || (frequency > 960e6))
            return AT_PARAM_ERROR;
        if (service_lora_p2p_set_freq(frequency) != UDRV_RETURN_OK)
        {
            return at_error_code_form_udrv(service_lora_p2p_set_freq(frequency));
        }
        
        uint32_t spreading_factor;
        if (0 != at_check_digital_uint32_t(param->argv[1], &spreading_factor))
            return AT_PARAM_ERROR;
        if ((spreading_factor < 5) || (spreading_factor > 12))
            return AT_PARAM_ERROR;
        if (service_lora_p2p_set_sf((uint8_t)spreading_factor) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }

        uint32_t bandwidth;
        if (0 != at_check_digital_uint32_t(param->argv[2], &bandwidth))
            return AT_PARAM_ERROR;
        if (service_lora_p2p_set_bandwidth(bandwidth) != UDRV_RETURN_OK)
        {
            return at_error_code_form_udrv(service_lora_p2p_set_bandwidth(bandwidth));
        }

        uint32_t coding_rate;
        if (0 != at_check_digital_uint32_t(param->argv[3], &coding_rate))
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_codingrate((uint8_t)coding_rate) != UDRV_RETURN_OK)
        {
            return at_error_code_form_udrv(service_lora_p2p_set_codingrate((uint8_t)coding_rate));
        }

        uint32_t preamble_length;
        if (0 != at_check_digital_uint32_t(param->argv[4], &preamble_length))
            return AT_PARAM_ERROR;

        if ( preamble_length < 5 || preamble_length > 65535)
            return AT_PARAM_ERROR;
        if (service_lora_p2p_set_preamlen((uint16_t)preamble_length) != UDRV_RETURN_OK)
        {
            return at_error_code_form_udrv(service_lora_p2p_set_preamlen((uint16_t)preamble_length));
        }

        uint32_t txpower;
        if (0 != at_check_digital_uint32_t(param->argv[5], &txpower))
            return AT_PARAM_ERROR;  
        if ((txpower < 5) || (txpower > 22))
            return AT_PARAM_ERROR;
        if (service_lora_p2p_set_powerdbm((uint8_t)txpower) != UDRV_RETURN_OK)
        {
            return at_error_code_form_udrv(service_lora_p2p_set_powerdbm((uint8_t)txpower));
        }

        return AT_OK;
    }else
    {
        return AT_PARAM_ERROR;
    }
}


int At_Pbr(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORA_FSK != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_bitrate());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t bitrate;

        if (0 != at_check_digital_uint32_t(param->argv[0], &bitrate))
            return AT_PARAM_ERROR;

        if(bitrate < 600 || bitrate > 300000)
        {
            return AT_PARAM_ERROR;
        }
        
        if (service_lora_p2p_set_bitrate(bitrate) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }

}

int At_Pfdev(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORA_FSK != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_fdev());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t fdev;

        if (0 != at_check_digital_uint32_t(param->argv[0], &fdev))
        {
            return AT_PARAM_ERROR;
        }
        if( fdev < 600 || fdev > 200000)
            return AT_PARAM_ERROR;

        if (service_lora_p2p_set_fdev(fdev) != UDRV_RETURN_OK)
        {
            return AT_ERROR;
        }
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif


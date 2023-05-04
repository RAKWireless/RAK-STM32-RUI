#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_p2p.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "service_lora_test.h"
#include "service_lora_p2p.h"
#include "service_runtimeConfig.h"
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
                atcmd_printf("OK");
                udrv_system_reboot();
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
        if (get_useRuntimeConfigP2P())
        {
            runtimeConfigP2P_t runtimeConfigP2P;
            get_runtimeConfigP2P(&runtimeConfigP2P);
            atcmd_printf("%s=", cmd);
            atcmd_printf("%u:", runtimeConfigP2P.frequency);
            atcmd_printf("%u:", runtimeConfigP2P.spreading_factor);
            atcmd_printf("%u:", runtimeConfigP2P.bandwidth);  
            atcmd_printf("%u:", runtimeConfigP2P.coding_rate);
            atcmd_printf("%u:", runtimeConfigP2P.preamble_length);
            atcmd_printf("%u\r\n", runtimeConfigP2P.txpower);
        }
        else
	   	{
            atcmd_printf("%s=", cmd);
            atcmd_printf("%u:", service_lora_p2p_get_freq());
            atcmd_printf("%u:", service_lora_p2p_get_sf());
            atcmd_printf("%u:", service_lora_p2p_get_bandwidth());
            atcmd_printf("%u:", service_lora_p2p_get_codingrate());
            atcmd_printf("%u:", service_lora_p2p_get_preamlen());
            atcmd_printf("%u\r\n",service_lora_p2p_get_powerdbm());
        }
        return AT_OK;
    }
    else if (param->argc == 6 || (param->argc == 7 && !strcmp(param->argv[6],"0")))
    {
        uint32_t frequency,spreading_factor,bandwidth,coding_rate,preamble_length,txpower;
        uint32_t o_frequency,o_spreading_factor,o_bandwidth,o_coding_rate,o_preamble_length,o_txpower;
        uint8_t udrv_code;

        // Preserve current p2p parameters
        o_frequency = service_lora_p2p_get_freq();
        o_spreading_factor = service_lora_p2p_get_sf();
        o_bandwidth = service_lora_p2p_get_bandwidth();
        o_coding_rate = service_lora_p2p_get_codingrate();
        o_preamble_length = service_lora_p2p_get_preamlen();
        o_txpower = service_lora_p2p_get_powerdbm();

        // Exchange parameters
        if (0 != at_check_digital_uint32_t(param->argv[0], &frequency))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[1], &spreading_factor))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[2], &bandwidth))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[3], &coding_rate))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[4], &preamble_length))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[5], &txpower))
            return AT_PARAM_ERROR;

        if ((frequency < 150e6) || (frequency > 960e6))
            return AT_PARAM_ERROR;

        if ( spreading_factor < 5 || spreading_factor > 12)
            return AT_PARAM_ERROR;

        if (coding_rate > 3)
            return AT_PARAM_ERROR;

        if(preamble_length< 5 || preamble_length > 65535)
            return AT_PARAM_ERROR;

        if (txpower < 5 || txpower > 22)
            return AT_PARAM_ERROR;

        // Check and save parameters
        udrv_code = service_lora_p2p_set_freq(frequency);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_set_sf((uint8_t)spreading_factor);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_set_bandwidth(bandwidth);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_set_codingrate((uint8_t)coding_rate);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_set_preamlen((uint16_t)preamble_length);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_set_powerdbm((uint8_t)txpower);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P_CHECK_ERROR_CODE;

        set_useRuntimeConfigP2P(false);
        return AT_OK;

        STEP_ATP2P_CHECK_ERROR_CODE:
        //Restore the previous parameters
        service_lora_p2p_set_freq(o_frequency);
        service_lora_p2p_set_sf((uint8_t)o_spreading_factor);
        service_lora_p2p_set_bandwidth(o_bandwidth);
        service_lora_p2p_set_codingrate((uint8_t)o_coding_rate);
        service_lora_p2p_set_preamlen((uint16_t)o_preamble_length);
        service_lora_p2p_set_powerdbm((uint8_t)o_txpower);
        //Check and return error code
        return at_error_code_form_udrv(udrv_code);
    }
    else if (param->argc == 7 && !strcmp(param->argv[6],"1")) { //for runtime setting
        uint32_t frequency,spreading_factor,bandwidth,coding_rate,preamble_length,txpower;
        uint32_t o_frequency,o_spreading_factor,o_bandwidth,o_coding_rate,o_preamble_length,o_txpower;
        uint8_t udrv_code;
        bool o_useRuntimeConfig = get_useRuntimeConfigP2P();
        runtimeConfigP2P_t runtimeConfigP2P;

        // Preserve current p2p parameters
        if (o_useRuntimeConfig) {
            get_runtimeConfigP2P(&runtimeConfigP2P);
            o_frequency = runtimeConfigP2P.frequency;
            o_spreading_factor = runtimeConfigP2P.spreading_factor;
            if (SERVICE_LORA_P2P == service_lora_get_nwm()) {
                o_bandwidth = runtimeConfigP2P.bandwidth;
            }
            else if (SERVICE_LORA_FSK == service_lora_get_nwm()) {
                o_bandwidth = runtimeConfigP2P.fsk_rxbw;
            }
            o_coding_rate = runtimeConfigP2P.coding_rate;
            o_preamble_length = runtimeConfigP2P.preamble_length;
            o_txpower = runtimeConfigP2P.txpower;
        }
        else {
            o_frequency = service_lora_p2p_get_freq();
            o_spreading_factor = service_lora_p2p_get_sf();
            o_bandwidth = service_lora_p2p_get_bandwidth();
            o_coding_rate = service_lora_p2p_get_codingrate();
            o_preamble_length = service_lora_p2p_get_preamlen();
            o_txpower = service_lora_p2p_get_powerdbm();
        }

        // Exchange parameters
        if (0 != at_check_digital_uint32_t(param->argv[0], &frequency))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[1], &spreading_factor))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[2], &bandwidth))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[3], &coding_rate))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[4], &preamble_length))
            return AT_PARAM_ERROR;
        if (0 != at_check_digital_uint32_t(param->argv[5], &txpower))
            return AT_PARAM_ERROR;

        // Compatible old SPEC for bandwidth
        if (SERVICE_LORA_P2P == service_lora_get_nwm()) {
            if( bandwidth == 125 ) {
                bandwidth = 0;
            }
            else if( bandwidth == 250 ) {
                bandwidth = 1;
            }
            else if( bandwidth == 500 ) {
                bandwidth = 2;
            }
        }

        // Check parameters
        udrv_code = service_lora_p2p_check_runtime_freq(frequency);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_check_runtime_sf((uint8_t)spreading_factor);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_check_runtime_bandwidth(bandwidth);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_check_runtime_codingrate((uint8_t)coding_rate);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_check_runtime_preamlen((uint16_t)preamble_length);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;
        udrv_code = service_lora_p2p_check_runtime_powerdbm((uint8_t)txpower);
        if( udrv_code != UDRV_RETURN_OK)
            goto STEP_ATP2P2_CHECK_ERROR_CODE;

        runtimeConfigP2P.frequency = frequency;
        runtimeConfigP2P.spreading_factor = (uint8_t)spreading_factor;
        if (SERVICE_LORA_P2P == service_lora_get_nwm()) {
            runtimeConfigP2P.bandwidth = bandwidth;
        }
        else if (SERVICE_LORA_FSK == service_lora_get_nwm()) {
            runtimeConfigP2P.fsk_rxbw = bandwidth;
        }
        runtimeConfigP2P.coding_rate = (uint8_t)coding_rate;
        runtimeConfigP2P.preamble_length = (uint16_t)preamble_length;
        runtimeConfigP2P.txpower = (uint8_t)txpower;

        set_runtimeConfigP2P(&runtimeConfigP2P);
        set_useRuntimeConfigP2P(true);
        service_lora_p2p_config();
        return AT_OK;

        STEP_ATP2P2_CHECK_ERROR_CODE:
        //Restore the previous parameters
        if (!o_useRuntimeConfig) {
            service_lora_p2p_set_freq(o_frequency);
            service_lora_p2p_set_sf((uint8_t)o_spreading_factor);
            service_lora_p2p_set_bandwidth(o_bandwidth);
            service_lora_p2p_set_codingrate((uint8_t)o_coding_rate);
            service_lora_p2p_set_preamlen((uint16_t)o_preamble_length);
            service_lora_p2p_set_powerdbm((uint8_t)o_txpower);
        }
        //Check and return error code
        return at_error_code_form_udrv(udrv_code);
    }
	else {
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

int At_iqInver(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_iqinverted()?1:0);
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t val;
        bool iqinverted;

        if (0 != at_check_digital_uint32_t(param->argv[0], &val))
            return AT_PARAM_ERROR;

        if(val == 0)
            iqinverted = false;
        else if( val == 1)
            iqinverted = true;
        else
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_iqinverted(iqinverted);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_syncword(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%04x\r\n", cmd, service_lora_p2p_get_syncword());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint16_t syncword;

        if (0 != at_check_hex_uint16(param->argv[0], &syncword))
            return AT_PARAM_ERROR;

        int32_t ret =  service_lora_p2p_set_syncword(syncword);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_rfFrequency(SERIAL_PORT port, char *cmd, stParam *param)
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
        uint32_t frequency;

        if (0 != at_check_digital_uint32_t(param->argv[0], &frequency))
            return AT_PARAM_ERROR;

        int32_t ret =  service_lora_p2p_set_freq(frequency);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_txOutputPower(SERIAL_PORT port, char *cmd, stParam *param)
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
        
        if (txpower < 5 || txpower > 22)
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_powerdbm((uint8_t)txpower);
        return at_error_code_form_udrv(ret);

        return AT_OK;
    }
    return AT_PARAM_ERROR;
}

int At_bandwidth(SERIAL_PORT port, char *cmd, stParam *param)
{
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

        int32_t ret = service_lora_p2p_set_bandwidth(bandwidth);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_speradingFactor(SERIAL_PORT port, char *cmd, stParam *param)
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

        if ( spreading_factor < 5 || spreading_factor > 12)
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_sf((uint8_t)spreading_factor);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_codingrate(SERIAL_PORT port, char *cmd, stParam *param)
{
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

        if (coding_rate > 3)
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_codingrate((uint8_t)coding_rate) ;
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_preambleLength(SERIAL_PORT port, char *cmd, stParam *param)
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

        if(preamble_length< 5 || preamble_length > 65535)
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_preamlen((uint16_t)preamble_length);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_symbolTimeout(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_symbol_timeout());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t symbolTimeout;

        if (0 != at_check_digital_uint32_t(param->argv[0], &symbolTimeout))
            return AT_PARAM_ERROR;

        if(symbolTimeout > SYMBTIMEOUT_MAX)
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_symbol_timeout((uint16_t)symbolTimeout);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

int At_fixLengthPayload(SERIAL_PORT port, char *cmd, stParam *param)
{    
    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_p2p_get_fix_length_payload()?1:0);
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t val;
        bool fixLengthPayloadOn;

        if (0 != at_check_digital_uint32_t(param->argv[0], &val))
            return AT_PARAM_ERROR;

        if(val == 0)
            fixLengthPayloadOn = false;
        else if( val == 1)
            fixLengthPayloadOn = true;
        else
            return AT_PARAM_ERROR;

        int32_t ret = service_lora_p2p_set_fix_length_payload(fixLengthPayloadOn);
        return at_error_code_form_udrv(ret);
    }
    return AT_PARAM_ERROR;
}

#endif
#endif


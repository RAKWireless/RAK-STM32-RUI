#ifdef SUPPORT_AT
#ifdef SUPPORT_LORA
#include "atcmd_multicast.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "atcmd.h"
#include "service_lora_multicast.h"
#include "string.h"

//at+addmulc=C:11223344:11223344556677881122334455667788:11223344556677881122334455667788
//at+lstmulc=?
//at+rmvmulc=11223344
int At_Addmulc(SERIAL_PORT port, char *cmd, stParam *param)
{
    int32_t ret;
    McSession_t McSession;

    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if( param->argc < 4 || param->argc > 7)
        return AT_PARAM_ERROR;

    if ((strcmp(param->argv[0],"b") == 0) || (strcmp(param->argv[0],"B") == 0))
        McSession.Devclass = 1;
    else if((strcmp(param->argv[0],"c") == 0) || (strcmp(param->argv[0],"C") == 0))
        McSession.Devclass = 2;
    else
        return AT_PARAM_ERROR;

    if( 0 != at_check_hex_uint32(param->argv[1],&McSession.Address) )
        return AT_PARAM_ERROR;
    if( 0 != at_check_hex_param(param->argv[2],32,McSession.McNwkSKey) )
        return AT_PARAM_ERROR;
    if( 0 != at_check_hex_param(param->argv[3],32,McSession.McAppSKey) )
        return AT_PARAM_ERROR;

    //Set default value parameters 
    McSession.Frequency = 0;
    McSession.Datarate = 0;
    McSession.Periodicity = 0;

    //Frequency point and DR must be set at the same time
    if(param->argc == 5)
        return AT_PARAM_ERROR;
    if(param->argc >= 6)
    {
        uint32_t Datarate_u32;
        if( 0 != at_check_digital_uint32_t(param->argv[4], &McSession.Frequency) )
            return AT_PARAM_ERROR;
        if(param->argv[5][0] == '0')
        {
            if (!strcmp(param->argv[5], "0"))
                Datarate_u32 = 0;
            else if( 0 != at_check_digital_uint32_t( param->argv[5] + 1, &Datarate_u32))
                return AT_PARAM_ERROR;
        }
        else
        {
            if( 0 != at_check_digital_uint32_t( param->argv[5], &Datarate_u32))
                return AT_PARAM_ERROR;
        }

        McSession.Datarate = Datarate_u32;
    }

    if ((param->argc == 7))
    {
        uint32_t Periodicity_u32;
        if( 0 != at_check_digital_uint32_t( param->argv[6], &Periodicity_u32))
            return AT_PARAM_ERROR;
        if( Periodicity_u32 > 7)
            return AT_PARAM_ERROR;
        if(McSession.Devclass == 1)
            McSession.Periodicity = (uint16_t)Periodicity_u32;
        if(McSession.Devclass == 2 && Periodicity_u32 > 0)
            return AT_PARAM_ERROR;
    }

    ret = service_lora_addmulc(McSession);
    
    return at_error_code_form_udrv(ret);
}

int At_Rmvmulc(SERIAL_PORT port, char *cmd, stParam *param)
{
    uint32_t addr;
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    
    if (param->argc != 1 )
    {
        /* This command is unreadable and can only be set */
        return AT_PARAM_ERROR;
    }
    if( 0 != at_check_hex_uint32(param->argv[0],&addr) )
        return AT_PARAM_ERROR;
    if(service_lora_rmvmulc(addr) != AT_OK)
        return AT_PARAM_ERROR;
    return AT_OK;
}

int At_Lstmulc(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    McSession_t McSession ;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        uint8_t i=1;
        while (service_lora_lstmulc(&McSession) == -UDRV_CONTINUE) {
            if(i>1)
            {
                atcmd_printf(",");
            }
            //atcmd_printf("MC%d:", i);
            if(McSession.Address==0)
            {
                atcmd_printf("0:");
            }
            else
            {
                if (McSession.Devclass == 1)
                {
                    atcmd_printf("B:");
                }
                else 
                {
                    atcmd_printf("C:");
                }
            }
            atcmd_printf("%08X:", McSession.Address);

            for (int j = 0; j < 16; j++)
            {
                atcmd_printf("%02X", McSession.McNwkSKey[j]);
            }
            atcmd_printf(":");

            for (int j = 0; j < 16; j++)
            {
                atcmd_printf("%02X", McSession.McAppSKey[j]);
            }
            atcmd_printf(":");

            atcmd_printf("%09d:", McSession.Frequency);
            atcmd_printf("%02d:", McSession.Datarate);
            atcmd_printf("%d", McSession.Periodicity);
            i++;
        }
        atcmd_printf("\r\n");
        return AT_OK;
    }
    else /* This command can only be queried, not set */
    {
        return AT_PARAM_ERROR;
    }
}
#endif
#endif

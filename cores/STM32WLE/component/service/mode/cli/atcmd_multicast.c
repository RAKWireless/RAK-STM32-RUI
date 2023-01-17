#ifdef SUPPORT_LORA
#include "atcmd_multicast.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "atcmd.h"
#include "service_lora_multicast.h"
#include "string.h"

//at+addmulc=C,11223344,11223344556677881122334455667788,11223344556677881122334455667788
//at+lstmulc=?
//at+rmvmulc=11223344
int At_Addmulc(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    uint8_t McAppSKey[16], McNwkSKey[16], Address[4];
    char hex_num[5] = {0};

    McSession_t McSession;
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        /* This command is unreadable and can only be set */
        return AT_PARAM_ERROR;
    }
    else if (param->argc >= 4)
    {
        if ((strcmp(param->argv[0],"b") == 0) || (strcmp(param->argv[0],"B") == 0))
        {
            McSession.Devclass = 1;
            // if(param->argc != 7)
            // return AT_PARAM_ERROR;
        }
        else if((strcmp(param->argv[0],"c") == 0) || (strcmp(param->argv[0],"C") == 0))
        {
            McSession.Devclass = 2;
        }
        else
        {
            return AT_PARAM_ERROR;
        }

        if((strlen(param->argv[2])!=32)||(strlen(param->argv[3])!=32)||(strlen(param->argv[1])!=8))
        {
            return AT_PARAM_ERROR;
        }

        for (int i = 0; i < 4; i++)
        {
            memcpy(hex_num, &param->argv[1][i * 2], 2);
            Address[i] = strtoul(hex_num, NULL, 16);
        }

        McSession.Address = Address[0] << 24 | Address[1] << 16 | Address[2] << 8 | Address[3];

        for (int i = 0; i < 16; i++)
        {
            memcpy(hex_num, &param->argv[2][i * 2], 2);
            McNwkSKey[i] = strtoul(hex_num, NULL, 16);
        }

        for (int i = 0; i < 16; i++)
        {
            memcpy(hex_num, &param->argv[3][i * 2], 2);
            McAppSKey[i] = strtoul(hex_num, NULL, 16);
        }
        memcpy(McSession.McAppSKey, McAppSKey, 16);
        memcpy(McSession.McNwkSKey, McNwkSKey, 16);

        //Set default value parameters 
        if(param->argc == 4)
        {
            McSession.Frequency = 0;
            McSession.Datarate = 0;
            if(McSession.Devclass == 1)
                McSession.Periodicity = 0;
            else
                McSession.Periodicity = 0;
        }

        //Frequency point and DR must be set at the same time 
        if(param->argc == 5)
        {
            //if(strlen(param->argv[4])!=9)
            return AT_PARAM_ERROR;
            //McSession.Frequency = strtoul(param->argv[4], 0, 10);
        }
        if(param->argc >= 6)
        {
            if((strlen(param->argv[5])>2)||(strlen(param->argv[4])!=9))
            return AT_PARAM_ERROR;
            McSession.Frequency = strtoul(param->argv[4], 0, 10);
            McSession.Datarate = strtoul(param->argv[5], 0, 10);
            McSession.Periodicity =0;
        }

        if ((param->argc == 7)&&(McSession.Devclass == 1))
        {
            if(strlen(param->argv[6])!=1)
            return AT_PARAM_ERROR;
            McSession.Periodicity = strtoul(param->argv[6], 0, 10);
            if(McSession.Periodicity>7)
            return AT_PARAM_ERROR;
        }
        return service_lora_addmulc(McSession);
       
    }
    else
    {
        return AT_PARAM_ERROR;
    }

}

int At_Rmvmulc(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    char hex_num[5] = {0};
    uint8_t Address[4];
    uint32_t addr;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        /* This command is unreadable and can only be set */
        return AT_PARAM_ERROR;
    }
    else if (param->argc == 1)
    {
        if(strlen(param->argv[0])!=8)
        {
            return AT_PARAM_ERROR;
        }
        for (int i = 0; i < 4; i++)
        {
            memcpy(hex_num, &param->argv[0][i * 2], 2);
            Address[i] = strtoul(hex_num, NULL, 16);
        }
        addr = Address[0] << 24 | Address[1] << 16 | Address[2] << 8 | Address[3];
        if(service_lora_rmvmulc(addr) != AT_OK)
        return AT_PARAM_ERROR;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
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

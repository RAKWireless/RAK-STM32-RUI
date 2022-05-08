#ifdef SUPPORT_LORA
#include <string.h>

#include "atcmd.h"
#include "atcmd_supplement.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "service_nvm.h"
#include "udrv_powersave.h"

#if defined(REGION_CN470) || defined(REGION_US915) || \
    defined(REGION_AU915)
int At_Mask(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;
    SERVICE_LORA_BAND band = service_lora_get_band();

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        uint16_t ch_mask;
        int32_t freq;

        if (UDRV_RETURN_OK == service_lora_get_mask(&ch_mask))
        {
            atcmd_printf("%s=%04X", cmd, ch_mask);
            if ((freq = service_lora_get_chs()) > 0) {
                atcmd_printf("(single channel mode: %d)", freq);
            }
            atcmd_printf("\r\n");
        }
        else
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint16_t mask_param;

        if (0 != at_check_hex_uint16(param->argv[0], &mask_param))
            return AT_PARAM_ERROR;

        if( band == SERVICE_LORA_US915 || band == SERVICE_LORA_AU915)
        {
            if(mask_param>255)
                return AT_PARAM_ERROR;
        }

        ret = service_lora_set_mask(&mask_param, true);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret = -UDRV_BUSY)
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

int At_Che(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {

        uint16_t ch_mask;
        int32_t freq;

        if (UDRV_RETURN_OK == service_lora_get_mask(&ch_mask))
        {
            uint32_t i = 1, j = 1;
            atcmd_printf("%s=", cmd);
            do {
                if (ch_mask & 1) {
                    if (j != 1) {
                        atcmd_printf(":");
                    }
                    atcmd_printf("%u", i);
                    j++;
                }
                i++;
            } while ((ch_mask = ch_mask >> 1) != 0);
            if ((freq = service_lora_get_chs()) > 0) {
                atcmd_printf("(single channel mode: %d)", freq);
            }
            atcmd_printf("\r\n");
        }
        else
        {
            return AT_ERROR;
        }

        return AT_OK;
    }
    else if (param->argc > 0 && param->argc <= 12)//0 enabls all sub-bands; 1-12 for 12 different sub-bands
    {
        uint32_t input;
        uint16_t mask_param = 0;
        int32_t ret;

        for (int i = 0 ; i < param->argc ; i++) {
            for (int j = 0 ; j < strlen(param->argv[i]) ; j++)
            {
                if (!isdigit(*(param->argv[i] + j)))
                {
                    return AT_PARAM_ERROR;
                }
            }
            input = strtoul(param->argv[i], NULL, 10);

            if (input > 12) {//AT+CHE supports 0-12
                return AT_PARAM_ERROR;
            }

            SERVICE_LORA_BAND band = service_lora_get_band();
            
            if(band == SERVICE_LORA_US915 || band == SERVICE_LORA_AU915)
            {
                if(input > 8)
                    return AT_PARAM_ERROR;
            }

            switch (input) {
                case 0:
                {
                    mask_param |= 0x0000;
                    break;
                }
                case 1:
                {
                    mask_param |= 0x0001;
                    break;
                }
                case 2:
                {
                    mask_param |= 0x0002;
                    break;
                }
                case 3:
                {
                    mask_param |= 0x0004;
                    break;
                }
                case 4:
                {
                    mask_param |= 0x0008;
                    break;
                }
                case 5:
                {
                    mask_param |= 0x0010;
                    break;
                }
                case 6:
                {
                    mask_param |= 0x0020;
                    break;
                }
                case 7:
                {
                    mask_param |= 0x0040;
                    break;
                }
                case 8:
                {
                    mask_param |= 0x0080;
                    break;
                }
                case 9:
                {
                    mask_param |= 0x0100;
                    break;
                }
                case 10:
                {
                    mask_param |= 0x0200;
                    break;
                }
                case 11:
                {
                    mask_param |= 0x0400;
                    break;
                }
                case 12:
                {
                    mask_param |= 0x0800;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        ret = service_lora_set_mask(&mask_param, true);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret = -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else
        {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}

#endif

int At_Band(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=", cmd);
        switch (service_lora_get_band())
        {
        case SERVICE_LORA_EU433:
            atcmd_printf("0\r\n");
            break;
        case SERVICE_LORA_CN470:
            atcmd_printf("1\r\n");
            break;
#ifndef LEGACY
        case SERVICE_LORA_RU864:
            atcmd_printf("2\r\n");
            break;
#endif
        case SERVICE_LORA_IN865:
            atcmd_printf("3\r\n");
            break;
        case SERVICE_LORA_EU868:
            atcmd_printf("4\r\n");
            break;
        case SERVICE_LORA_US915:
            atcmd_printf("5\r\n");
            break;
        case SERVICE_LORA_AU915:
            atcmd_printf("6\r\n");
            break;
        case SERVICE_LORA_KR920:
            atcmd_printf("7\r\n");
            break;
        case SERVICE_LORA_AS923:
            atcmd_printf("8\r\n");
            break;
        case SERVICE_LORA_AS923_2:
            atcmd_printf("9\r\n");
            break;
        case SERVICE_LORA_AS923_3:
            atcmd_printf("10\r\n");
            break;
        case SERVICE_LORA_AS923_4:
            atcmd_printf("11\r\n");
            break;
#ifdef LEGACY
        case SERVICE_LORA_US915_HYBRID:
#endif
        default:
            return AT_ERROR;
        }
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t input;
        SERVICE_LORA_BAND band;

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        input = strtoul(param->argv[0], NULL, 10);

        switch (input)
        {
        case 0:
            band = SERVICE_LORA_EU433;
            break;
        case 1:
            band = SERVICE_LORA_CN470;
            break;
        case 2:
#ifndef LEGACY
            band = SERVICE_LORA_RU864;
            break;
#else
            return AT_PARAM_ERROR;
#endif
        case 3:
            band = SERVICE_LORA_IN865;
            break;
        case 4:
            band = SERVICE_LORA_EU868;
            break;
        case 5:
            band = SERVICE_LORA_US915;
            break;
        case 6:
            band = SERVICE_LORA_AU915;
            break;
        case 7:
            band = SERVICE_LORA_KR920;
            break;
        case 8:
            band = SERVICE_LORA_AS923;
            break;
        case 9 :
            band = SERVICE_LORA_AS923_2;
            break;
        case 10 :
            band = SERVICE_LORA_AS923_3;
            break;
        case 11 :
            band = SERVICE_LORA_AS923_4;
            break;   
        default:
            return AT_PARAM_ERROR;
        }

        ret = service_lora_set_band(band);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
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

int At_Chs(SERIAL_PORT port, char *cmd, stParam *param)
{
    if(SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        int32_t freq;

        if((freq = service_lora_get_chs()) < 0) {
            return AT_ERROR;
        }
        atcmd_printf("%s=%d\r\n", cmd, service_lora_get_chs());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t freq;

        for (int i = 0 ; i < strlen(param->argv[0]) ; i++) {
            if (!isdigit(*(param->argv[0]+i))) {
                return AT_PARAM_ERROR;
            }
        }

        freq = strtoul(param->argv[0], NULL, 10);
        if (service_lora_set_chs(freq) == UDRV_RETURN_OK) {
            return AT_OK;
        } else {
            return AT_ERROR;
        }
    } else {
        return AT_PARAM_ERROR;
    }
}
#endif

//int At_DelBLEBonds(SERIAL_PORT port, char *cmd, stParam *param)
//{
//    if (param->argc == 0)
//    {
//        udrv_ble_delete_bonds();
//        udrv_system_reboot();
//        return AT_OK;
//    }
//    else
//    {
//        return AT_PARAM_ERROR;
//    }
//}

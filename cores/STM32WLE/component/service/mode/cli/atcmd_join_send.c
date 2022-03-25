#ifdef SUPPORT_LORA
#include <string.h>

#include "service_mode_cli.h"
#include "atcmd.h"
#include "atcmd_join_send.h"
#include "udrv_errno.h"
#include "service_lora.h"
#include "udrv_spimst.h"
#include "udrv_gpio.h"

static void dump_hex2str(uint8_t *buf, uint8_t len)
{
    for (uint8_t i = 0; i < len; i++)
    {
        atcmd_printf("%02X", buf[i]);
    }
    atcmd_printf("\r\n");
}

static void loraWaitOnBusy(void)
{
    while (udrv_gpio_get_logic(46 /*BUSY*/) == 1)
    {
        atcmd_printf("GPIO #46 is HIGH\n");
        udrv_delay_ms(100);
    }
}

static void loraSendCmd(uint8_t cmd, uint32_t len)
{
    uint32_t err_code;
    uint8_t m_tx_buf; /**< TX buffer. */
    uint8_t m_rx_buf; /**< RX buffer. */

    loraWaitOnBusy();
    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_LOW);

    atcmd_printf("cmd=0x%x\r\n", cmd);

    m_tx_buf = cmd;
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = 0;
    for (int i = 0; i < len; i++)
    {
        err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
        atcmd_printf("m_rx_buf=0x%x\r\n", m_rx_buf);
    }

    atcmd_printf("=====\r\n");

    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_HIGH);
    loraWaitOnBusy();
}

static void loraReadReg(uint16_t addr, uint32_t len)
{
    uint32_t err_code;
    uint8_t m_tx_buf; /**< TX buffer. */
    uint8_t m_rx_buf; /**< RX buffer. */

    loraWaitOnBusy();
    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_LOW);

    atcmd_printf("readreg=0x%x\r\n", addr);

    m_tx_buf = 0x1D; //Read reg
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = (addr & 0xFF00) >> 8;
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = (addr & 0x00FF);
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = 0;
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);

    m_tx_buf = 0;
    for (int i = 0; i < len; i++)
    {
        err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
        atcmd_printf("m_rx_buf=0x%x\r\n", m_rx_buf);
    }

    atcmd_printf("=====\r\n");

    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_HIGH);
    loraWaitOnBusy();
}

static void loraWriteReg(uint16_t addr, uint8_t *buf, uint32_t len)
{
    uint32_t err_code;
    uint8_t m_tx_buf; /**< TX buffer. */
    uint8_t m_rx_buf; /**< RX buffer. */

    loraWaitOnBusy();
    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_LOW);

    atcmd_printf("writereg=0x%x\r\n", addr);

    m_tx_buf = 0x0D; //Write reg
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = (addr & 0xFF00) >> 8;
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    m_tx_buf = (addr & 0x00FF);
    err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
    //atcmd_printf("err_code=0x%x\r\n", err_code);

    //m_tx_buf = 0;
    //err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);

    m_rx_buf = 0;
    for (int i = 0; i < len; i++)
    {
        m_tx_buf = *(buf + i);
        err_code = udrv_spimst_trx((udrv_spimst_port)LORA_IO_SPI_PORT, (uint8_t *)&m_tx_buf, 1, (uint8_t *)&m_rx_buf, 1, 0);
        atcmd_printf("m_tx_buf=0x%x\r\n", m_tx_buf);
    }

    atcmd_printf("=====\r\n");

    udrv_gpio_set_logic(42 /*NSS*/, GPIO_LOGIC_HIGH);
    loraWaitOnBusy();
}

int At_Retry(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd,service_lora_get_retry());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint8_t retry_times ;
        if (0 != at_check_digital_uint32_t(param->argv[0], &retry_times))
            return AT_PARAM_ERROR;

        if(retry_times>7)
            return AT_PARAM_ERROR;

        return service_lora_set_retry(retry_times);
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_CfMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd,service_lora_get_cfm());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t mode;

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        mode = strtoul(param->argv[0], NULL, 10);
        if (mode != 0 && mode != 1)
        {
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_cfm((SERVICE_LORA_CONFIRM_MODE)mode) == UDRV_RETURN_OK)
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

int At_CfStatus(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_cfs());
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_Join(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;
    int32_t val[4] = {-1, -1, -1, -1};

    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        val[0] = service_lora_get_join_start();
        val[1] = service_lora_get_auto_join();
        val[2] = service_lora_get_auto_join_period();
        val[3] = service_lora_get_auto_join_max_cnt();
        atcmd_printf("%s=%d:%d:%d:%d\r\n", cmd, val[0], val[1], val[2], val[3]);
        return AT_OK;
    }
    else if (param->argc <= 4)
    {
        for (int i = 0; i < param->argc; i++)
        {
            for (int j = 0; j < strlen(param->argv[i]); j++)
            {
                if (!isdigit(*(param->argv[i] + j)))
                {
                    return AT_PARAM_ERROR;
                }
            }
        }

        for (int i = 0; i < param->argc; i++)
        {
            val[i] = (int32_t)strtoul(param->argv[i], NULL, 10);
        }

        if (param->argc == 0)
        {
            val[0] = 1;
        }

        if (param->argc > 0 && (val[0] != 0 && val[0] != 1))
        {
            return AT_PARAM_ERROR;
        }

        if (param->argc > 1 && (val[1] != 0 && val[1] != 1))
        {
            return AT_PARAM_ERROR;
        }

        if (param->argc > 2 && (val[2] < 7 || val[2] > 255))
        {
            return AT_PARAM_ERROR;
        }

        if (param->argc > 3 && (val[3] < 0 || val[3] > 255))
        {
            return AT_PARAM_ERROR;
        }

        ret = service_lora_join(val[0], val[1], val[2], val[3]);
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

int At_NwkJoinMode(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_njm());
        return AT_OK;
    }
    else if (param->argc == 1)
    {
        uint32_t mode;

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        mode = strtoul(param->argv[0], NULL, 10);
        if (mode != 0 && mode != 1)
        {
            return AT_PARAM_ERROR;
        }

        if (service_lora_set_njm((SERVICE_LORA_JOIN_MODE)mode, true) == UDRV_RETURN_OK)
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

int At_NwkJoinStatus(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        atcmd_printf("%s=%u\r\n", cmd, service_lora_get_njs());
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_Recv(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        uint8_t buff[SERVICE_LORA_DLINK_BUFF_SIZE], port;
        int32_t len;

        len = service_lora_get_last_recv(&port, buff, SERVICE_LORA_DLINK_BUFF_SIZE);
        atcmd_printf("%s=%u:", cmd, port);
        dump_hex2str(buff, len);
        return AT_OK;
    }
    else
    {
        return AT_PARAM_ERROR;
    }
}

int At_Send(SERIAL_PORT port, char *cmd, stParam *param)
{
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        return AT_MODE_NO_SUPPORT;
    }
    int32_t ret;

    if (param->argc == 2)
    {
        SERVICE_LORA_SEND_INFO info;
        uint32_t digit;
        uint8_t buff[4], port, data[CLI_BUFFER_SIZE];
        char hex_num[3] = {0};

        digit = strlen(param->argv[0]);
        for (int i = 0 ; i < digit ; i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        port = atoi(param->argv[0]);

        if (port < 1 || port > 223)
        {
            return AT_PARAM_ERROR;
        }

        info.port = port;
        info.retry = 8;

        digit = strlen(param->argv[1]);
        if (digit % 2 != 0)
        {
            return AT_PARAM_ERROR;
        }

        if (digit == 0 || digit > 500) {
            return AT_PARAM_ERROR;
        }

        for (int i = 0 ; i < digit ; i++)
        {
            if (!isxdigit(*(param->argv[1] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        for (int i = 0; i < (digit / 2); i++)
        {
            memcpy(hex_num, param->argv[1] + i * 2, 2);
            data[i] = strtoul(hex_num, NULL, 16);
        }

        info.confirm_valid = false;
        info.retry_valid = false;

        // uint8_t CurrentPossiblePayloadSize = service_lora_query_txPossible( digit / 2);
        // atcmd_printf("(MaxAppSize %d)\r\n", CurrentPossiblePayloadSize);
        // if( CurrentPossiblePayloadSize < (digit / 2) )
        // {
        //     atcmd_printf("(MaxPayloadSize %d)\r\n", CurrentPossiblePayloadSize);
        //     return AT_PARAM_ERROR;
        // }
              
        ret = service_lora_send(data, digit / 2, info, false);
        if (ret == UDRV_RETURN_OK)
        {
            return AT_OK;
        }
        else if (ret == -UDRV_NO_WAN_CONNECTION)
        {
            return AT_NO_NETWORK_JOINED;
        }
        else if (ret == -UDRV_BUSY)
        {
            return AT_BUSY_ERROR;
        }
        else if(ret == -UDRV_WRONG_ARG )
        {
            return AT_PARAM_ERROR;
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

int At_Lpsend(SERIAL_PORT port, char *cmd, stParam *param)
{
    uint16_t lp_port,lp_ack;
    uint16_t lp_len;
    uint8_t lp_buffer[1024];
    if (param->argc == 1 && !strcmp(param->argv[0], "?"))
    {
        return  AT_PARAM_ERROR;
    }
    else
    { 
        if(param->argc!=3)
        {
            return  AT_PARAM_ERROR;
        }

        for (int i = 0; i < strlen(param->argv[0]); i++)
        {
            if (!isdigit(*(param->argv[0] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }
        for (int i = 0; i < strlen(param->argv[1]); i++)
        {
            if (!isdigit(*(param->argv[1] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }
        for (int i = 0; i < strlen(param->argv[2]); i++)
        {
            if (!isdigit(*(param->argv[2] + i)))
            {
                return AT_PARAM_ERROR;
            }
        }

        if(strlen(param->argv[0]) > 3 || strlen(param->argv[1]) > 1 )
        {
             return AT_PARAM_ERROR;
        }

        lp_port = strtoul(param->argv[0], NULL, 10);
        lp_ack = strtoul(param->argv[1], NULL, 10);
        lp_len = strlen(param->argv[2]);
        if ((lp_len % 2) || (lp_len > 2 * 1024))
            return AT_PARAM_ERROR;

        if (lp_ack > 1)
            return AT_PARAM_ERROR;

        if (lp_port > 223)
            return AT_PARAM_ERROR;

        if (0 != at_check_hex_param(param->argv[2], lp_len, lp_buffer))
            return AT_PARAM_ERROR;
    
        service_lora_lptp_send(lp_port,lp_ack,lp_buffer,lp_len/2);
        return AT_OK;
    }   
}
#endif

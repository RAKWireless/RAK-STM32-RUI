#ifdef SUPPORT_LORA

#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "service_lora_p2p.h"
#include "LoRaMac.h"
#include "Region.h"
#include "systime.h"
#include "utilities.h"
#include "radio.h"
#include "service_lora_test.h"
#include "soft-se/aes.h"
#include "board.h"
#include "service_runtimeConfig.h"

#ifdef LORA_CHIP_SX1276
    // #include "sx1276Regs-LoRa.h"
    #define REG_LR_SYNCWORD                             0x39
#elif defined LORA_CHIP_SX126X
    // #include "sx126x/sx126x.h"
    #define REG_LR_SYNCWORD                             0x0740
#elif defined LORA_CHIP_STM32WLE5XX
    // #include "radio_driver.h"
    #define REG_LR_SYNCWORD                             0x0740
#endif


static int PKCS7Cutting(char *p, int plen);
static int PKCS7Padding(char *p, int plen);

static rui_lora_p2p_recv_t recv_data_pkg;

void radio_set_syncword( uint16_t syncword);
void (*service_lora_p2p_send_callback)(void);
void (*service_lora_p2p_send_CAD_callback)(bool);
void (*service_lora_p2p_recv_callback)(rui_lora_p2p_recv_t recv_data_pkg);

/* Radio events function pointer */
static RadioEvents_t RadioEvents;

LORA_P2P_STATUS_ST lora_p2p_status = {
    .isRxCancel = false,
    .isRadioBusy = false,
    .isContinue = false,
    .isContinue_no_exit = false,
    .isContinue_compatible_tx = false,
    .isCAD = false
};

static uint8_t lora_p2p_buf[255];

void recv_cllback(rui_lora_p2p_recv_t recv_data_pkg)
{
    LORA_TEST_DEBUG("recv register ok");
}

void send_cllback(void)
{
    LORA_TEST_DEBUG("send register ok");
}

static void OnTxDone(void)
{
    lora_p2p_status.isRadioBusy = false;

    LORA_P2P_DEBUG("%s\r\n", __func__);
    if (service_get_debug_level()) {
        udrv_serial_log_printf("%s\r\n", __func__);
    }
    LORA_TEST_DEBUG("service_lora_p2p_send_callback %08x",service_lora_p2p_send_callback);

    if ((*service_lora_p2p_send_callback)!=NULL)
    {
        (*service_lora_p2p_send_callback)();
    }
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
        udrv_serial_log_printf("+EVT:TXP2P DONE\r\n");
    else
        udrv_serial_log_printf("+EVT:TXFSK DONE\r\n");


    udrv_powersave_wake_unlock();   

    if(lora_p2p_status.isContinue_compatible_tx == true)
    {
        //65533 needs to continue receiving after sending.
        lora_p2p_status.isRadioBusy = true;
        Radio.Standby();
        Radio.Rx(0);  
        
        return ;
    }  
}

static void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
    lora_p2p_status.isRadioBusy = false;
    lora_p2p_status.isContinue = false;

    LORA_P2P_DEBUG("%s\r\n", __func__);

    if (true == service_lora_p2p_get_crypto_enable())
    {
        LORA_TEST_DEBUG();
        uint8_t outdata[256], cut_length;
        memset(outdata,'\0',sizeof(outdata));
        if (size % 16)
        {
            /* Normal processing will not be executed here */
            size = size + 16 - size % 16;
        }
        cut_length = service_lora_p2p_decrpty(payload, size, outdata);
        size = cut_length;
        memcpy(lora_p2p_buf, outdata, size);
    }
    else
        memcpy(lora_p2p_buf, payload, size);

    if (SERVICE_LORA_P2P == service_lora_get_nwm())
        udrv_serial_log_printf("+EVT:RXP2P:%d:%d:", rssi, snr);
    else
        udrv_serial_log_printf("+EVT:RXFSK:%d:%d:", rssi, snr);
    printf_hex(lora_p2p_buf, size);
    udrv_serial_log_printf("\r\n");

    recv_data_pkg.Rssi = rssi;
    recv_data_pkg.Snr = snr;
    recv_data_pkg.BufferSize = size;
    recv_data_pkg.Buffer = lora_p2p_buf;

    if((*service_lora_p2p_recv_callback)!=NULL)
    {
        (*service_lora_p2p_recv_callback)(recv_data_pkg);
    }

    if(lora_p2p_status.isContinue_no_exit  || lora_p2p_status.isContinue_compatible_tx)
    {
        lora_p2p_status.isRadioBusy = true;
        return ;
    }
    Radio.Standby();
    udrv_powersave_wake_unlock();
}

static void OnTxTimeout(void)
{
    lora_p2p_status.isRadioBusy = false;
    LORA_P2P_DEBUG("%s\r\n", __func__);
    if (service_get_debug_level()) {
        udrv_serial_log_printf("%s\r\n", __func__);
    }
}

static void OnRxTimeout(void)
{
    LORA_P2P_DEBUG("%s\r\n", __func__);

    lora_p2p_status.isRadioBusy = false;

    if(lora_p2p_status.isContinue || lora_p2p_status.isContinue_no_exit || lora_p2p_status.isContinue_compatible_tx) //RAK4631 will enter receive timeout
    {
        lora_p2p_status.isRadioBusy = true;
        LORA_TEST_DEBUG();
        return;
    }
   
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
        udrv_serial_log_printf("+EVT:RXP2P RECEIVE TIMEOUT\r\n");
    else
        udrv_serial_log_printf("+EVT:RXFSK RECEIVE TIMEOUT\r\n");
    
    if((*service_lora_p2p_recv_callback)!=NULL)
    {
        (*service_lora_p2p_recv_callback)(recv_data_pkg);
    }
    Radio.Standby();
    udrv_powersave_wake_unlock();
}

static void OnRxError(void)
{
    lora_p2p_status.isRadioBusy = false;
    lora_p2p_status.isContinue = false;

    if (SERVICE_LORA_P2P == service_lora_get_nwm())
        udrv_serial_log_printf("+EVT:RXP2P RECEIVE ERROR\r\n");
    else
        udrv_serial_log_printf("+EVT:RXFSK RECEIVE ERROR\r\n");

    LORA_P2P_DEBUG("%s\r\n", __func__);
    
    if((*service_lora_p2p_recv_callback)!=NULL)
    {
        (*service_lora_p2p_recv_callback)(recv_data_pkg);
    }

    if(lora_p2p_status.isContinue_no_exit || lora_p2p_status.isContinue_compatible_tx )
    {
        return;
    }
    else
    {
        Radio.Standby();
        udrv_powersave_wake_unlock();
    }
}

static void OnCadDone(bool channelActivityDetected)
{
    if ((*service_lora_p2p_send_CAD_callback)!=NULL)
    {
        (*service_lora_p2p_send_CAD_callback)(channelActivityDetected);
    }
    if(channelActivityDetected == true)
        lora_p2p_status.isRadioBusy = false;
    lora_p2p_status.isCAD = false;
}


int32_t service_lora_p2p_config(void)
{
    uint32_t timeOnAir = 0x00FFFFFF;

    uint32_t bandwidth, codingrate, Frequency;
    bool rxContinuous = false;
    uint8_t Powerdbm, Spreadfact;
    uint16_t  Preamlen;
    bool fix_length_payload = service_nvm_get_fix_length_payload_from_nvm();
    bool iqinverted = service_nvm_get_iqinverted_from_nvm();
    uint32_t symbol_timeout = service_nvm_get_symbol_timeout_from_nvm();
    uint32_t deviation = service_nvm_get_fdev_from_nvm();
    uint32_t bitrate = service_nvm_get_bitrate_from_nvm();
    uint16_t syncword = service_nvm_get_syncword_from_nvm();

    if (get_useRuntimeConfigP2P()) {
        runtimeConfigP2P_t runtimeConfigP2P;
        get_runtimeConfigP2P(&runtimeConfigP2P);

        Frequency = runtimeConfigP2P.frequency;
        Powerdbm = runtimeConfigP2P.txpower;
        Spreadfact = runtimeConfigP2P.spreading_factor;
        Preamlen = runtimeConfigP2P.preamble_length;

        if (SERVICE_LORA_P2P == service_lora_get_nwm())
        {
            bandwidth = runtimeConfigP2P.bandwidth;
        }
        else if (SERVICE_LORA_FSK == service_lora_get_nwm())
        {
            //Because RadioGetFskBandwidthRegValue( bandwidth << 1 );
            // SX126x badwidth is double sided
            bandwidth = (runtimeConfigP2P.fsk_rxbw >> 1);
        }

        codingrate = runtimeConfigP2P.coding_rate + 1;
    }
    else {
        Frequency = service_nvm_get_freq_from_nvm();
        Powerdbm = service_nvm_get_powerdbm_from_nvm();
        Spreadfact = service_nvm_get_sf_from_nvm();
        Preamlen = service_nvm_get_preamlen_from_nvm();

        if (SERVICE_LORA_P2P == service_lora_get_nwm())
        {
            bandwidth = service_lora_p2p_get_bandwidth();
        }
        else if (SERVICE_LORA_FSK == service_lora_get_nwm())
        {
            //Because RadioGetFskBandwidthRegValue( bandwidth << 1 ); 
            // SX126x badwidth is double sided
            bandwidth = (service_lora_p2p_get_bandwidth() >> 1);
        }

        codingrate = service_nvm_get_codingrate_from_nvm() + 1;
    }

    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {
        if( service_nvm_get_symbol_timeout_from_nvm() == 0)
            rxContinuous = true;

        Radio.SetTxConfig(MODEM_LORA, Powerdbm, 0, bandwidth,
                          Spreadfact, codingrate,
                          Preamlen, fix_length_payload,
                          true, 0, 0, iqinverted, timeOnAir);

        Radio.SetRxConfig(MODEM_LORA, bandwidth, Spreadfact,
                          codingrate, 0, Preamlen,
                          symbol_timeout, fix_length_payload,
                          0, true, 0, 0, iqinverted, rxContinuous);

        Radio.SetMaxPayloadLength(MODEM_LORA, LORA_BUFFER_SIZE);
        radio_set_syncword(syncword);
    }

    if (SERVICE_LORA_FSK == service_lora_get_nwm())
    {
        LORA_TEST_DEBUG("deviation %d Hz", deviation);
        LORA_TEST_DEBUG("bandwidth %d Hz", bandwidth);

        Radio.SetTxConfig(MODEM_FSK, Powerdbm, deviation, bandwidth,
                          bitrate, codingrate,
                          Preamlen, LORA_FIX_LENGTH_PAYLOAD_ON,
                          true, 0, 0, LORA_IQ_INVERSION_ON, timeOnAir);

        Radio.SetRxConfig(MODEM_FSK, bandwidth, bitrate,
                          codingrate, 0, Preamlen,
                          LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
                          0, true, 0, 0, LORA_IQ_INVERSION_ON, true);

        Radio.SetMaxPayloadLength(MODEM_LORA, LORA_BUFFER_SIZE);
    }

    Radio.SetChannel(Frequency);
    LORA_P2P_DEBUG("Freq %d, SF %d, Bandwidth %d, CodeRate %d, Preamlen %d, TxPower %d\r\n",
                   Frequency, Spreadfact,
                   bandwidth, codingrate,
                   Preamlen, Powerdbm);
    return UDRV_RETURN_OK;
}



int32_t service_lora_p2p_init(void)
{
    /* Radio initialization */
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;
    RadioEvents.CadDone = OnCadDone;

    Radio.Init(&RadioEvents);

    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_send(uint8_t *p_data, uint8_t len, bool cad_enable)
{
    if (lora_p2p_status.isRadioBusy == true && lora_p2p_status.isContinue_compatible_tx == false)
        return -UDRV_BUSY;

    service_lora_p2p_config();

    if (true == service_lora_p2p_get_crypto_enable())
        len = service_lora_p2p_encrpty(p_data, len, lora_p2p_buf);
    else
        memcpy(lora_p2p_buf, p_data, len);

    udrv_powersave_wake_lock();
    Radio.Standby();

    lora_p2p_status.isRadioBusy = true;
    if(cad_enable == true)
    {
        //SX126xSetCadParams(0x03,20,10,0x01,0x1);  
        lora_p2p_status.isCAD = true;
        Radio.StartCad();
        while(lora_p2p_status.isCAD == true)
        {
#if defined(LORA_CHIP_SX126X)
            if(SX126xGetIrqStatus() == 0x0080)
            {
                RadioOnDioIrq();
                break;
            }
#endif
        }
            
        if(lora_p2p_status.isRadioBusy == false)
            return -UDRV_BUSY;
    }
    Radio.Send(lora_p2p_buf, len);


    if (service_get_debug_level()) {
        udrv_serial_log_printf("LoRa P2P send data: (%d) ", len);
        printf_hex(lora_p2p_buf, len);
        udrv_serial_log_printf("\r\n");
    }

    return UDRV_RETURN_OK;
}

bool service_lora_p2p_get_radio_stat(void)
{
    if (lora_p2p_status.isRadioBusy || lora_p2p_status.isContinue || lora_p2p_status.isContinue_no_exit || lora_p2p_status.isContinue_compatible_tx)
        return true;
    else
        return false;
}

int32_t service_lora_p2p_recv(uint32_t timeout)
{
    // if ((lora_p2p_status.isRadioBusy == true) && (timeout != 0))
    //     return -UDRV_BUSY;

    if (timeout > 65535)
        return -UDRV_WRONG_ARG;

    //Time can't be too small
    if (0 < timeout && timeout < 15)
        timeout = 15;

   
    memset(&recv_data_pkg,0,sizeof(rui_lora_p2p_recv_t));
    /* timeout description
        0     - Stop receiving immediately
        xx    - Receive xx milliseconds
        65535 - Keep receiving until 1 packet of data is received
    */

    /* The three continuous modes cannot be switched to each other. 
    must exit the current continuous receiving mode first
    */
    if(timeout != 0 && ( lora_p2p_status.isContinue || lora_p2p_status.isContinue_no_exit
    || lora_p2p_status.isContinue_compatible_tx))
    {
        udrv_serial_log_printf("P2P_RX_ON already\r\n");
        return -UDRV_BUSY;
    }


    /* enter the receiving mode and set radio busy */
    lora_p2p_status.isRadioBusy = true;

    if (timeout == 0)
    {
        LORA_P2P_DEBUG("Radio Standby.\r\n");
        lora_p2p_status.isContinue = false;
        lora_p2p_status.isRadioBusy = false;
        lora_p2p_status.isContinue_no_exit = false;
        lora_p2p_status.isContinue_compatible_tx = false;
        udrv_powersave_wake_unlock ();   
        Radio.Standby();
    }
    else if (timeout == 65535)
    {
        lora_p2p_status.isContinue = true;
        LORA_P2P_DEBUG("Radio rx continue.\r\n");
        service_lora_p2p_config();
        Radio.Standby();
        Radio.Rx(0);  
        udrv_powersave_wake_lock();   
    }
    else if (timeout == 65534)
    {
        lora_p2p_status.isContinue_no_exit = true;
        service_lora_p2p_config();
        Radio.Standby();
        Radio.Rx(0); 
        udrv_powersave_wake_lock();
    }
    else if (timeout == 65533)
    {
        lora_p2p_status.isContinue_compatible_tx = true;
        service_lora_p2p_config();
        Radio.Standby();
        Radio.Rx(0); 
        udrv_powersave_wake_lock();
    }
    else
    {
        LORA_P2P_DEBUG("Start recv data\r\n");
        Radio.Rx(timeout);
        udrv_powersave_wake_lock();
    }
    return UDRV_RETURN_OK;
}

uint32_t service_lora_p2p_get_freq(void)
{
    return service_nvm_get_freq_from_nvm();
}

int32_t service_lora_p2p_set_freq(uint32_t freq)
{
    if ((freq < 150e6) || (freq > 960e6))
        return -UDRV_WRONG_ARG;
    
#if defined(rak3172) || defined(rak3172T)
        /* Only RAK3172 supports hardware high and low frequency detection */
        uint8_t hardware_freq = 0;
        hardware_freq =  BoardGetHardwareFreq();
        if(hardware_freq)
        {
            if(freq <= 600e6)
            {
                return -UDRV_WRONG_ARG;
            }
        }
        else
        {
            if(freq > 600e6)
            {
                return -UDRV_WRONG_ARG;
            }
        }
#endif

    service_nvm_set_freq_to_nvm(freq);
    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_check_runtime_freq(uint32_t freq)
{
    if ((freq < 150e6) || (freq > 960e6))
        return -UDRV_WRONG_ARG;

#if defined(rak3172) || defined(rak3172T)
        /* Only RAK3172 supports hardware high and low frequency detection */
        uint8_t hardware_freq = 0;
        hardware_freq =  BoardGetHardwareFreq();
        if(hardware_freq)
        {
            if(freq <= 600e6)
            {
                return -UDRV_WRONG_ARG;
            }
        }
        else
        {
            if(freq > 600e6)
            {
                return -UDRV_WRONG_ARG;
            }
        }
#endif

    return UDRV_RETURN_OK;
}

uint8_t service_lora_p2p_get_sf(void)
{
    return service_nvm_get_sf_from_nvm();
}

int32_t service_lora_p2p_set_sf(uint8_t spreadfact)
{
    if ((spreadfact < 5) || (spreadfact > 12))
        return -UDRV_WRONG_ARG;

    service_nvm_set_sf_to_nvm(spreadfact);
    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_check_runtime_sf(uint8_t spreadfact)
{
    if ((spreadfact < 5) || (spreadfact > 12))
        return -UDRV_WRONG_ARG;

    return UDRV_RETURN_OK;
}

uint32_t service_lora_p2p_get_bandwidth(void)
{
    uint32_t bandwidth = service_nvm_get_bandwidth_from_nvm();
    if( bandwidth == 125 )
        bandwidth = 0;
    else if( bandwidth == 250 )
        bandwidth = 1;
    else if( bandwidth == 500 )
        bandwidth = 2;
    return bandwidth;
}

int32_t service_lora_p2p_set_bandwidth(uint32_t bandwidth)
{
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {
        
        if( bandwidth == 125 )
        {
            bandwidth = 0;
        }
        else if( bandwidth == 250 )
        {
            bandwidth = 1;
        }
        else if( bandwidth == 500 )
        {
            bandwidth = 2;
        }
        else if (bandwidth > 9)
        {
            return -UDRV_WRONG_ARG;
        }
    }
    else if (SERVICE_LORA_FSK == service_lora_get_nwm())
    {
        if (bandwidth > 467000 || bandwidth < 4800)
        {
            return -UDRV_WRONG_ARG;
        }
    }

    int32_t ret = service_nvm_set_bandwidth_to_nvm(bandwidth);
    if( ret == UDRV_RETURN_OK )
        service_lora_p2p_config();
    return ret;
}

int32_t service_lora_p2p_check_runtime_bandwidth(uint32_t bandwidth)
{
    if (SERVICE_LORA_P2P == service_lora_get_nwm())
    {

        if( bandwidth == 125 )
        {
            bandwidth = 0;
        }
        else if( bandwidth == 250 )
        {
            bandwidth = 1;
        }
        else if( bandwidth == 500 )
        {
            bandwidth = 2;
        }
        else if (bandwidth > 9)
        {
            return -UDRV_WRONG_ARG;
        }
    }
    else if (SERVICE_LORA_FSK == service_lora_get_nwm())
    {
        if (bandwidth > 467000 || bandwidth < 4800)
        {
            return -UDRV_WRONG_ARG;
        }
    }

    return UDRV_RETURN_OK;
}

uint8_t service_lora_p2p_get_codingrate(void)
{
    return service_nvm_get_codingrate_from_nvm();
}

int32_t service_lora_p2p_set_codingrate(uint8_t codingrate)
{
    if ((codingrate < 0) || (codingrate > 3))
        return -UDRV_WRONG_ARG;

    service_nvm_set_codingrate_to_nvm(codingrate);
    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_check_runtime_codingrate(uint8_t codingrate)
{
    if ((codingrate < 0) || (codingrate > 3))
        return -UDRV_WRONG_ARG;

    return UDRV_RETURN_OK;
}

uint16_t service_lora_p2p_get_preamlen(void)
{
    return service_nvm_get_preamlen_from_nvm();
}

int32_t service_lora_p2p_set_preamlen(uint16_t preamlen)
{
    if (preamlen < 5)
        return -UDRV_WRONG_ARG;

    service_nvm_set_preamlen_to_nvm(preamlen);
    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_check_runtime_preamlen(uint16_t preamlen)
{
    if (preamlen < 5)
        return -UDRV_WRONG_ARG;

    return UDRV_RETURN_OK;
}

uint8_t service_lora_p2p_get_powerdbm(void)
{
    return service_nvm_get_powerdbm_from_nvm();
}

int32_t service_lora_p2p_set_powerdbm(uint8_t powerdbm)
{
    if ((powerdbm < 5) || (powerdbm > 22))
        return -UDRV_WRONG_ARG;

    service_nvm_set_powerdbm_to_nvm(powerdbm);
    service_lora_p2p_config();

    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_check_runtime_powerdbm(uint8_t powerdbm)
{
    if ((powerdbm < 5) || (powerdbm > 22))
        return -UDRV_WRONG_ARG;

    return UDRV_RETURN_OK;
}

bool service_lora_p2p_get_crypto_enable(void)
{
    return service_nvm_get_crypt_enable_from_nvm();
}

int32_t service_lora_p2p_set_crypto_enable(bool enable)
{
    return service_nvm_set_crypt_enable_to_nvm(enable);
}

int32_t service_lora_p2p_get_crypto_key(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_crypt_key_from_nvm(buff, len);
}

int32_t service_lora_p2p_set_crypto_key(uint8_t *buff, uint32_t len)
{
    return service_nvm_set_crypt_key_to_nvm(buff, len);
}

int32_t service_lora_p2p_get_crypto_IV(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_crypt_IV_from_nvm(buff, len);
}

int32_t service_lora_p2p_set_crypto_IV(uint8_t *buff, uint32_t len)
{
    return service_nvm_set_crypt_IV_to_nvm(buff, len);
}

bool service_lora_p2p_get_CAD(void)
{
    return service_nvm_get_CAD_from_nvm();
}

int32_t service_lora_p2p_set_CAD(bool enable)
{
    return service_nvm_set_CAD_to_nvm(enable);
}


int32_t service_lora_p2p_encrpty(uint8_t *indata, uint16_t inlen,uint8_t *outdata)
{
    uint8_t buf[255];
    uint8_t key[16];
    uint16_t i;
    aes_context ctx;
    uint8_t iv[16];
    uint8_t n_block;
    uint8_t pad_length;

    uint8_t crypt_state;

    if (inlen > 255)
        return -UDRV_WRONG_ARG;
    /* For memory safety  */
    memcpy(buf, indata, inlen);
    pad_length = PKCS7Padding(buf, inlen);
    n_block = pad_length / 16;
    LORA_TEST_DEBUG("pad_length %d", pad_length);
    for (i = 0; i < pad_length; i++)
        LORA_TEST_DEBUG("%02X", buf[i]);

    service_lora_p2p_get_crypto_IV(iv,16);

    service_lora_p2p_get_crypto_key(key, 16);
    aes_set_key(key, 16, &ctx);
    crypt_state = aes_cbc_encrypt(buf, outdata, n_block, iv, &ctx);
    LORA_TEST_DEBUG("crypt_state %d", crypt_state);
    for (i = 0; i < pad_length; i++)
        LORA_TEST_DEBUG("%02X", outdata[i]);

    return pad_length;
}

int32_t service_lora_p2p_decrpty(uint8_t *indata, uint16_t inlen, uint8_t *outdata)
{
    uint8_t key[16];
    uint16_t i;
    aes_context ctx;
    uint8_t iv[16];
    uint8_t crypt_state;
    uint8_t cut_length;

    service_lora_p2p_get_crypto_IV(iv,16);

    service_lora_p2p_get_crypto_key(key, 16);
    aes_set_key(key, 16, &ctx);
    crypt_state = aes_cbc_decrypt(indata, outdata, inlen / 16, iv, &ctx);

    cut_length = PKCS7Cutting(outdata, inlen);

    LORA_TEST_DEBUG("cut_length %d", cut_length);
    for (i = 0; i < cut_length; i++)
        LORA_TEST_DEBUG("%02X", outdata[i]);

    return cut_length;
}

uint32_t service_lora_p2p_get_bitrate(void)
{
    return service_nvm_get_bitrate_from_nvm();
}

uint32_t service_lora_p2p_get_fdev(void)
{
    return service_nvm_get_fdev_from_nvm();
}

int32_t service_lora_p2p_set_fdev(uint32_t fdev)
{
    if ((fdev < 600) || (fdev > 200000))
        return -UDRV_WRONG_ARG;

    service_lora_p2p_config();
    return service_nvm_set_fdev_to_nvm(fdev);
}

int32_t service_lora_p2p_set_bitrate(uint32_t bitrate)
{
    if ((bitrate < 600) || (bitrate > 300000))
        return -UDRV_WRONG_ARG;
   
    service_lora_p2p_config();
    return service_nvm_set_bitrate_to_nvm(bitrate);;
}

int PKCS7Padding(char *p, int plen)
{
    int plen_after_Padding, remain, padding_num;
    char padding_value;

    if (plen % 16 == 0)
    {
        /* add a 16 byte packet */
        padding_num = 16;
        padding_value = 0x10;
    }
    if (plen % 16 != 0)
    {
        remain = plen % 16;
        switch (remain)
        {
        case 1:
            padding_num = 15;
            padding_value = 0x0F;
            break;

        case 2:
            padding_num = 14;
            padding_value = 0x0E;
            break;

        case 3:
            padding_num = 13;
            padding_value = 0x0D;
            break;

        case 4:
            padding_num = 12;
            padding_value = 0x0C;
            break;

        case 5:
            padding_num = 11;
            padding_value = 0x0B;
            break;

        case 6:
            padding_num = 10;
            padding_value = 0x0A;
            break;

        case 7:
            padding_num = 9;
            padding_value = 0x09;
            break;

        case 8:
            padding_num = 8;
            padding_value = 0x08;
            break;

        case 9:
            padding_num = 7;
            padding_value = 0x07;
            break;

        case 10:
            padding_num = 6;
            padding_value = 0x06;
            break;

        case 11:
            padding_num = 5;
            padding_value = 0x5;
            break;

        case 12:
            padding_num = 4;
            padding_value = 0x04;
            break;

        case 13:
            padding_num = 3;
            padding_value = 0x03;
            break;

        case 14:
            padding_num = 2;
            padding_value = 0x02;
            break;

        case 15:
            padding_num = 1;
            padding_value = 0x01;
            break;

        default:
            break;
        }
    }
    plen_after_Padding = plen + padding_num;

    for (int i = plen; i < plen_after_Padding; i++)
    {
        p[i] = padding_value;
    }

    return plen_after_Padding;
}

int PKCS7Cutting(char *p, int plen)
{
    int plen_after_cutting, i;

    if (p[plen - 1] == 0x01)
    {
        plen_after_cutting = plen - 1;
    }
    else if (p[plen - 1] == 0x02)
    {
        if (p[plen - 2] == 0x02)
            plen_after_cutting = plen - 2;
    }
    else if (p[plen - 1] == 0x03)
    {
        if ((p[plen - 2] == 0x03) && (p[plen - 3] == 0x03))
            plen_after_cutting = plen - 3;
    }
    else if (p[plen - 1] == 0x04)
    {
        if ((p[plen - 2] == 0x04) && (p[plen - 3] == 0x04) && (p[plen - 4] == 0x04))
            plen_after_cutting = plen - 4;
    }
    else if (p[plen - 1] == 0x05)
    {
        if ((p[plen - 2] == 0x05) && (p[plen - 3] == 0x05) && (p[plen - 4] == 0x05) && (p[plen - 5] == 0x05))
            plen_after_cutting = plen - 5;
    }
    else if (p[plen - 1] == 0x06)
    {
        if ((p[plen - 2] == 0x06) && (p[plen - 3] == 0x06) && (p[plen - 4] == 0x06) && (p[plen - 5] == 0x06) && (p[plen - 6] == 0x06))
            plen_after_cutting = plen - 6;
    }
    else if (p[plen - 1] == 0x07)
    {
        if ((p[plen - 2] == 0x07) && (p[plen - 3] == 0x07) && (p[plen - 4] == 0x07) && (p[plen - 5] == 0x07) && (p[plen - 6] == 0x07) && (p[plen - 7] == 0x07))
            plen_after_cutting = plen - 7;
    }
    else if (p[plen - 1] == 0x08)
    {
        if ((p[plen - 2] == 0x08) && (p[plen - 3] == 0x08) && (p[plen - 4] == 0x08) && (p[plen - 5] == 0x08) && (p[plen - 6] == 0x08) && (p[plen - 7] == 0x08) && (p[plen - 8] == 0x08))
            plen_after_cutting = plen - 8;
    }
    else if (p[plen - 1] == 0x09)
    {
        if ((p[plen - 2] == 0x09) && (p[plen - 3] == 0x09) && (p[plen - 4] == 0x09) && (p[plen - 5] == 0x09) && (p[plen - 6] == 0x09) && (p[plen - 7] == 0x09) && (p[plen - 8] == 0x09) && (p[plen - 9] == 0x09))
            plen_after_cutting = plen - 9;
    }
    else if (p[plen - 1] == 0x0A)
    {
        if ((p[plen - 2] == 0x0A) && (p[plen - 3] == 0x0A) && (p[plen - 4] == 0x0A) && (p[plen - 5] == 0x0A) && (p[plen - 6] == 0x0A) && (p[plen - 7] == 0x0A) && (p[plen - 8] == 0x0A) && (p[plen - 9] == 0x0A) && (p[plen - 10] == 0x0A))
            plen_after_cutting = plen - 10;
    }
    else if (p[plen - 1] == 0x0B)
    {
        if ((p[plen - 2] == 0x0B) && (p[plen - 3] == 0x0B) && (p[plen - 4] == 0x0B) && (p[plen - 5] == 0x0B) && (p[plen - 6] == 0x0B) && (p[plen - 7] == 0x0B) && (p[plen - 8] == 0x0B) && (p[plen - 9] == 0x0B) && (p[plen - 10] == 0x0B) && (p[plen - 11] == 0x0B))
            plen_after_cutting = plen - 11;
    }
    else if (p[plen - 1] == 0x0C)
    {
        if ((p[plen - 2] == 0x0C) && (p[plen - 3] == 0x0C) && (p[plen - 4] == 0x0C) && (p[plen - 5] == 0x0C) && (p[plen - 6] == 0x0C) && (p[plen - 7] == 0x0C) && (p[plen - 8] == 0x0C) && (p[plen - 9] == 0x0C) && (p[plen - 10] == 0x0C) && (p[plen - 11] == 0x0C) && (p[plen - 12] == 0x0C))
            plen_after_cutting = plen - 12;
    }
    else if (p[plen - 1] == 0x0D)
    {
        if ((p[plen - 2] == 0x0D) && (p[plen - 3] == 0x0D) && (p[plen - 4] == 0x0D) && (p[plen - 5] == 0x0D) && (p[plen - 6] == 0x0D) && (p[plen - 7] == 0x0D) && (p[plen - 8] == 0x0D) && (p[plen - 9] == 0x0D) && (p[plen - 10] == 0x0D) && (p[plen - 11] == 0x0D) && (p[plen - 12] == 0x0D) && (p[plen - 13] == 0x0D))
            plen_after_cutting = plen - 13;
    }
    else if (p[plen - 1] == 0x0E)
    {
        if ((p[plen - 2] == 0x0E) && (p[plen - 3] == 0x0E) && (p[plen - 4] == 0x0E) && (p[plen - 5] == 0x0E) && (p[plen - 6] == 0x0E) && (p[plen - 7] == 0x0E) && (p[plen - 8] == 0x0E) && (p[plen - 9] == 0x0E) && (p[plen - 10] == 0x0E) && (p[plen - 11] == 0x0E) && (p[plen - 12] == 0x0E) && (p[plen - 13] == 0x0E) && (p[plen - 14] == 0x0E))
            plen_after_cutting = plen - 14;
    }
    else if (p[plen - 1] == 0x0F)
    {
        if ((p[plen - 2] == 0x0F) && (p[plen - 3] == 0x0F) && (p[plen - 4] == 0x0F) && (p[plen - 5] == 0x0F) && (p[plen - 6] == 0x0F) && (p[plen - 7] == 0x0F) && (p[plen - 8] == 0x0F) && (p[plen - 9] == 0x0F) && (p[plen - 10] == 0x0F) && (p[plen - 11] == 0x0F) && (p[plen - 12] == 0x0F) && (p[plen - 13] == 0x0F) && (p[plen - 14] == 0x0F) && (p[plen - 15] == 0x0F))
            plen_after_cutting = plen - 15;
    }
    else if (p[plen - 1] == 0x10)
    {
        for (i = 0; i < 16; i++)
        {
            if (p[plen - 1 - i] != 0x10)
                break;
        }
        plen_after_cutting = plen - 16;
    }
    else
    {
        plen_after_cutting = plen;
    }

    return plen_after_cutting;
}


int32_t service_lora_p2p_register_send_cb(service_lora_p2p_send_cb_type callback)
{
    LORA_TEST_DEBUG();
    service_lora_p2p_send_callback = callback;
    return UDRV_RETURN_OK;
}


int32_t service_lora_p2p_register_recv_cb(service_lora_p2p_recv_cb_type callback)
{
    service_lora_p2p_recv_callback = callback;
    return UDRV_RETURN_OK;
}

int32_t service_lora_p2p_register_send_CAD_cb(service_lora_p2p_send_CAD_cb_type callback)
{
    service_lora_p2p_send_CAD_callback = callback;
    return UDRV_RETURN_OK;
}


uint32_t service_lora_p2p_get_symbol_timeout(void)
{
    return service_nvm_get_symbol_timeout_from_nvm();
}

int32_t service_lora_p2p_set_symbol_timeout(uint32_t symbol_timeout)
{
    uint32_t udrv_ret;
    if (symbol_timeout > SYMBTIMEOUT_MAX)
    {
        return -UDRV_WRONG_ARG;
    }
    udrv_ret = service_nvm_set_symbol_timeout_to_nvm(symbol_timeout);
    return udrv_ret;
}

bool service_lora_p2p_get_iqinverted(void)
{
    return service_nvm_get_iqinverted_from_nvm();
}

int32_t service_lora_p2p_set_iqinverted(bool iqinverted)
{
    uint32_t udrv_ret;
    udrv_ret = service_nvm_set_iqinverted_to_nvm(iqinverted);
    return udrv_ret;
}

bool service_lora_p2p_get_fix_length_payload(void)
{
    return service_nvm_get_fix_length_payload_from_nvm();
}

int32_t service_lora_p2p_set_fix_length_payload(bool enable)
{
    uint32_t udrv_ret;
    udrv_ret = service_nvm_set_fix_length_payload_to_nvm(enable);
    return udrv_ret;
}

uint16_t service_lora_p2p_get_syncword(void)
{
    return service_nvm_get_syncword_from_nvm();
}

int32_t service_lora_p2p_set_syncword( uint16_t syncword )
{
    uint32_t udrv_ret;
    udrv_ret = service_nvm_set_syncword_to_nvm(syncword);
    BoardInitMcu();
    service_lora_p2p_config();
    return udrv_ret;
}

void radio_set_syncword( uint16_t syncword)
{
#if defined LORA_CHIP_STM32WLE5XX ||  defined LORA_CHIP_SX126X
    Radio.Write( REG_LR_SYNCWORD, ( syncword >> 8 ) & 0xFF );
    Radio.Write( REG_LR_SYNCWORD + 1, syncword & 0xFF );
#elif defined LORA_CHIP_SX1276
    Radio.Write( REG_LR_SYNCWORD , syncword & 0xFF );
#endif
}

#endif

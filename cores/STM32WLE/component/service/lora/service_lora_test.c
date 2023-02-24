#ifdef SUPPORT_LORA

#include "service_lora_test.h"
#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "LoRaMac.h"
#include "Region.h"
#include "radio.h"
#include "delay.h"
#include "udrv_timer.h"
#include "udrv_rtc.h"
#include "RegionAS923.h"
#include "RegionAU915.h"
#include "RegionCN470.h"
#include "RegionCN779.h"
#include "RegionEU433.h"
#include "RegionEU868.h"
#include "RegionKR920.h"
#include "RegionIN865.h"
#include "RegionUS915.h"
#include "RegionRU864.h"

#define TX_TEST_TONE (1 << 0)
#define RX_TEST_RSSI (1 << 1)
#define TX_TEST_LORA (1 << 2)
#define RX_TEST_LORA (1 << 3)
#define RX_TIMEOUT_VALUE 5000

// #define TEST_MODEM_FSK                              0
// #define TEST_MODEM_LORA                             1

#define TX_OUTPUT_POWER 14      // dBm
#define LORA_BANDWIDTH 0        // [0: 125 kHz, \
                                //  1: 250 kHz, \
                                //  2: 500 kHz, \
                                //  3: Reserved]
#define LORA_SPREADING_FACTOR 7 // [SF7..SF12]
#define LORA_CODINGRATE 1       // [1: 4/5, \
                                //  2: 4/6, \
                                //  3: 4/7, \
                                //  4: 4/8]
#define LORA_PREAMBLE_LENGTH 8  // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT 5   // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON false
#define LORA_IQ_INVERSION_ON false

#define PAYLOAD_LEN 4

#define FSK_FDEV 25000          // Hz
#define FSK_DATARATE 50000      // bps
#define FSK_BANDWIDTH 50000     // Hz
#define FSK_AFC_BANDWIDTH 83333 // Hz
#define FSK_PREAMBLE_LENGTH 5   // Same for Tx and Rx
#define FSK_FIX_LENGTH_PAYLOAD_ON false

static void OnTxDone(void);
static void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);
static void OnTxTimeout(void);
static void OnRxTimeout(void);
static void OnRxError(void);
static int32_t Prbs9_generator(uint8_t *payload, uint8_t len);
static void OnTxTimerEvent(void);
static void OnTxTimerEventRandom(void);
static void Recv_Enent(void);
static RadioEvents_t RadioEvents;
static uint8_t TestState = 0;
extern TimerEvent_t CertifiTimer;

/*
* \param [IN] bandwidth    Sets the bandwidth
 *                          FSK : >= 2600 and <= 250000 Hz
 *                          LoRa: [0: 125 kHz, 1: 250 kHz,
 *                                 2: 500 kHz, 3: Reserved]
 * \param [IN] datarate     Sets the Datarate
 *                          FSK : 600..300000 bits/s
 *                          LoRa: [6: 64, 7: 128, 8: 256, 9: 512,
 *                                10: 1024, 11: 2048, 12: 4096  chips]
*/

volatile testParameter_t testParam = {MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                                    FSK_AFC_BANDWIDTH, LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON, PAYLOAD_LEN,
                                    false, false, 0, 0,
                                    true, LORA_SYMBOL_TIMEOUT, TX_OUTPUT_POWER, FSK_FDEV,
                                    3000, 868000000, 0, 0,
                                    0, 0, 868000000, 868500000,
                                    100000, 6}; //Set a default value

static testCwParameter_t cwParam = {868000000,14,5}; //Set a default value                        

static volatile int16_t last_rx_rssi = 0;
static volatile int8_t last_rx_snr = 0;
static volatile uint32_t packet = 0;
static volatile uint8_t hop_flag = 0;
static TimerEvent_t TxTimer;
static uint8_t payload[256] = {0};
static uint32_t Rx_count_RxKo;
static uint32_t Rx_count_RxOk;
static uint32_t freq_start_back;
static uint32_t packet_back;
static uint8_t freq_cnt;

static uint32_t service_lora_test_full_wlock_cnt;
static volatile uint32_t freq_seq[128] = {0};
static void service_lora_test_full_wake_lock(void) {
    udrv_powersave_wake_lock();
    service_lora_test_full_wlock_cnt++;
}

static void service_lora_test_full_wake_unlock(void) {
    if (service_lora_test_full_wlock_cnt > 0) {
        udrv_powersave_wake_unlock();
        service_lora_test_full_wlock_cnt--;
    }
}

static void service_lora_test_full_wake_unlock_all(void) {
    while (service_lora_test_full_wlock_cnt > 0) {
        udrv_powersave_wake_unlock();
        service_lora_test_full_wlock_cnt--;
    }
}

// static void service_lora_test_wake_unlock(void *m_data)
// {
//     service_lora_test_full_wake_unlock();
// }

int32_t service_lora_ttone(void)
{
    if ((TestState & TX_TEST_TONE) != TX_TEST_TONE)
    {
        service_lora_test_full_wake_lock();
        TestState |= TX_TEST_TONE;
        Radio.SetTxContinuousWave(testParam.frequency, testParam.power, 0xFFFF);
        // udrv_system_timer_stop(SYSTIMER_LORAWAN);
        // if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_test_wake_unlock, HTMR_ONESHOT) == UDRV_RETURN_OK)
        // {
        //     udrv_system_timer_start(SYSTIMER_LORAWAN, 0xFFFF, NULL);
        // }
        // else
        // {
        //     return -UDRV_INTERNAL_ERR;
        // }
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_BUSY;
    }
}

void service_lora_toff(void)
{
  TestState = 0;
  TimerStop(&TxTimer);
  TimerStop(&CertifiTimer);
  Radio.Sleep();
  service_lora_test_full_wake_unlock_all();
  return;
}

int32_t service_lora_trssi(int16_t *rssiVal)
{
  uint32_t timeout = 0;
  /* Test with LNA */
  /* check that test is not already started*/
  if ((TestState & RX_TEST_RSSI) != RX_TEST_RSSI)
  {
    TestState |= RX_TEST_RSSI;
    Radio.SetChannel(testParam.frequency);
    /* RX Continuous */
    Radio.SetTxConfig(testParam.modem, testParam.power, testParam.fdev, testParam.bandwidth, testParam.datarate, testParam.coderate, testParam.preambleLen,
                      testParam.fixLen, testParam.crcOn, testParam.FreqHopOn, testParam.HopPeriod, testParam.iqInverted, testParam.txTimeout);
    timeout = 0xFFFFFF; /* continuous Rx */
    if (testParam.lna == 0)
    {
      Radio.Rx(timeout);
    }
    else
    {
      Radio.RxBoosted(timeout);
    }
    udrv_delay_ms(50); /* Wait for 100ms */
    *rssiVal = Radio.Rssi(MODEM_FSK);
    Radio.Sleep();
    TestState &= ~RX_TEST_RSSI;
    return *rssiVal;
  }
  else
  {
    return -UDRV_BUSY;
  }
}

int32_t service_lora_set_tconf(testParameter_t *Param)
{
  service_lora_test_full_wake_lock();

  if (Param->frequency < 150000000 || Param->frequency > 960000000)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->power > 22 || Param->power < -9)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->bandwidth > 6)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->datarate < 5 || Param->datarate > 12)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->coderate < 1 || Param->coderate > 4)
  {
    return -UDRV_WRONG_ARG;
  }

  if (1) //lna
  {
  }

  if (1) //paBoost_state
  {
  }

  if (Param->modem > 2)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->payloadLen > 256)
  {
    return -UDRV_WRONG_ARG;
  }

  if (Param->fdev < 4800 || Param->fdev > 467000)
  {
    return -UDRV_WRONG_ARG;
  }

  if (1) //lowDrOpt
  {
    //return -UDRV_WRONG_ARG;
  }

  if (1) //BTproduct
  {
    //return -UDRV_WRONG_ARG;
  }

  memcpy1(&testParam, Param, sizeof(testParameter_t));
  return UDRV_RETURN_OK;
}

int32_t service_lora_get_tconf(testParameter_t *Param)
{
  memcpy1(Param, &testParam, sizeof(testParameter_t));
  return UDRV_RETURN_OK;
}

int32_t service_lora_ttx(int32_t nb_packet)
{
  int32_t i;

  if ((TestState & TX_TEST_LORA) != TX_TEST_LORA)
  {
    service_lora_test_full_wake_lock();

    TestState |= TX_TEST_LORA;
    udrv_serial_log_printf("Tx Test\r\n");
    /* Radio initialization */
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;
    Radio.Init(&RadioEvents);
    /*Fill payload with PRBS9 data*/
    Prbs9_generator(payload, testParam.payloadLen);
    LORA_TEST_DEBUG("TX frequency %d", testParam.frequency);
    LORA_TEST_DEBUG("TX power %d", testParam.power);
    LORA_TEST_DEBUG("TX modem %d", testParam.modem);
    LORA_TEST_DEBUG("TX bandwidth %d", testParam.bandwidth);
    LORA_TEST_DEBUG("TX datarate %d", testParam.datarate);
    LORA_TEST_DEBUG("TX coderate %d", testParam.coderate);
    LORA_TEST_DEBUG("TX fixLen %d", testParam.fixLen);
    LORA_TEST_DEBUG("TX payloadLen %d", testParam.payloadLen);
    LORA_TEST_DEBUG("TX preambleLen %d", testParam.preambleLen);
    LORA_TEST_DEBUG("TX FreqHopOn %d", testParam.FreqHopOn);
    LORA_TEST_DEBUG("TX modem %d", testParam.modem);
    LORA_TEST_DEBUG("TX iqInverted %d", testParam.iqInverted);
    LORA_TEST_DEBUG("TX crcOn %d", testParam.crcOn);
    LORA_TEST_DEBUG("TX nb_packet %d", nb_packet);

    /* Launch several times payload: nb times given by user */
    Radio.SetChannel(testParam.frequency);
    Radio.SetTxConfig(testParam.modem, testParam.power, testParam.fdev, testParam.bandwidth, testParam.datarate, testParam.coderate, testParam.preambleLen,
                      testParam.fixLen, testParam.crcOn, testParam.FreqHopOn, testParam.HopPeriod, testParam.iqInverted, testParam.txTimeout);
    packet = nb_packet;
    packet_back = packet;
    TimerInit(&TxTimer, OnTxTimerEvent);
    TimerSetValue(&TxTimer, 500);
    TimerStart(&TxTimer);

    return UDRV_RETURN_OK;
  }
  else
  {
    return -UDRV_BUSY;
  }
}

int32_t service_lora_trx(int32_t nb_packet)
{
  /* init of PER counter */
  if (((TestState & RX_TEST_LORA) != RX_TEST_LORA) && (nb_packet > 0))
  {
    service_lora_test_full_wake_lock();

    TestState |= RX_TEST_LORA;
    /* Radio initialization */
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;
    Radio.Init(&RadioEvents);

    LORA_TEST_DEBUG("RX frequency %d", testParam.frequency);
    LORA_TEST_DEBUG("RX modem %d", testParam.modem);
    LORA_TEST_DEBUG("RX bandwidth %d", testParam.bandwidth);
    LORA_TEST_DEBUG("RX datarate %d", testParam.datarate);
    LORA_TEST_DEBUG("RX coderate %d", testParam.coderate);
    LORA_TEST_DEBUG("RX fixLen %d", testParam.fixLen);
    LORA_TEST_DEBUG("RX payloadLen %d", testParam.payloadLen);
    LORA_TEST_DEBUG("RX rxContinuous %d", testParam.rxContinuous);
    packet = nb_packet;
    packet_back = packet;
    Radio.SetChannel(testParam.frequency);
    Radio.SetRxConfig(testParam.modem, testParam.bandwidth, testParam.datarate, testParam.coderate, testParam.bandwidthAfc, testParam.preambleLen,
                      testParam.symbTimeout, testParam.fixLen, testParam.payloadLen, testParam.crcOn, testParam.FreqHopOn, testParam.HopPeriod, testParam.iqInverted, testParam.rxContinuous);
    Radio.Rx(RX_TIMEOUT_VALUE);

    return UDRV_RETURN_OK;
  }
  else
  {
    return -UDRV_BUSY;
  }
}

int32_t service_lora_tth(const testParameter_t *param)
{
  if ((TestState & TX_TEST_LORA) != TX_TEST_LORA)
  {
    service_lora_test_full_wake_lock();

    TestState |= TX_TEST_LORA;
    hop_flag = 1;
    /* Radio initialization */
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;
    Radio.Init(&RadioEvents);

    testParam.freq_start = param->freq_start;
    testParam.freq_stop = param->freq_stop;
    testParam.hp_step = param->hp_step;
    testParam.nb_tx = param->nb_tx;

    LORA_TEST_DEBUG("RX frequency %d", testParam.freq_start);
    LORA_TEST_DEBUG("RX frequency %d", testParam.freq_stop);
    LORA_TEST_DEBUG("RX frequency %d", testParam.hp_step);
    LORA_TEST_DEBUG("RX frequency %d", testParam.nb_tx);

    /*Fill payload with PRBS9 data*/
    Prbs9_generator(payload, testParam.payloadLen);
    freq_start_back = testParam.freq_start;
    packet_back = testParam.nb_tx;
    Radio.SetChannel(testParam.freq_start);
    Radio.SetTxConfig(testParam.modem, testParam.power, testParam.fdev, testParam.bandwidth, testParam.datarate, testParam.coderate, testParam.preambleLen,
                      testParam.fixLen, testParam.crcOn, testParam.FreqHopOn, testParam.HopPeriod, testParam.iqInverted, testParam.txTimeout);
    TimerInit(&TxTimer, OnTxTimerEvent);
    TimerSetValue(&TxTimer, 500);
    TimerStart(&TxTimer);

    return UDRV_RETURN_OK;
  }
  else
  {
    return -UDRV_BUSY;
  }
}

int32_t service_lora_trth(const testParameter_t *param)
{
  if ((TestState & TX_TEST_LORA) != TX_TEST_LORA)
  {
    service_lora_test_full_wake_lock();
    memset(freq_seq,0,sizeof(freq_seq));
    int j;
    int8_t phyDr;
    uint32_t bandwidth;
    for (freq_cnt = 0; freq_cnt < sizeof(freq_seq)/sizeof(freq_seq[0]); freq_cnt++)
    {
        if(param->freq_start + param->hp_step*freq_cnt > param->freq_stop)
        {
            --freq_cnt;
            break;
        }
        else
            freq_seq[freq_cnt] = param->freq_start + param->hp_step*freq_cnt;
    }
    srandom(udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT));
    for (int i = 0; i < freq_cnt; i++)
    {
        j = i + random() / (RAND_MAX / (freq_cnt - i) + 1);
        if(j == i)
            j = 0;
        freq_seq[i] = freq_seq[i] ^ freq_seq[j];
        freq_seq[j] = freq_seq[i] ^ freq_seq[j];
        freq_seq[i] = freq_seq[i] ^ freq_seq[j];

        freq_seq[j] = freq_seq[j] ^ freq_seq[freq_cnt];
        freq_seq[freq_cnt] = freq_seq[j] ^ freq_seq[freq_cnt];
        freq_seq[j] = freq_seq[j] ^ freq_seq[freq_cnt];

    }
    //for (int i = 0; i< sizeof(freq_seq) / sizeof(freq_seq[0]);i++)
    //    udrv_serial_log_printf("freq_seq[%d]:%u \r\n",i,freq_seq[i]);
    switch (service_lora_get_band())
    {
        case SERVICE_LORA_AS923:
        {
            phyDr = DataratesAS923[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsAS923 );
            break;
        }
        case SERVICE_LORA_AU915:
        {
            phyDr = DataratesAU915[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsAU915 );
            break;
        }
        case SERVICE_LORA_CN470:
        {
            phyDr = DataratesCN470[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsCN470 );
            break;
        }
        case SERVICE_LORA_CN779:
        {
            phyDr = DataratesCN779[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsCN779 );
            break;
        }
        case SERVICE_LORA_EU433:
        {
            phyDr = DataratesEU433[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsEU433 );
            break;
        }
        case SERVICE_LORA_EU868:
        {
            phyDr = DataratesEU868[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsEU868 );
            break;
        }
        case SERVICE_LORA_KR920:
        {
            phyDr = DataratesKR920[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsKR920 );
            break;
        }
        case SERVICE_LORA_IN865:
        {
            phyDr = DataratesIN865[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsIN865 );
            break;
        }
        case SERVICE_LORA_US915:
        {
            phyDr = DataratesUS915[testParam.datarate];
            bandwidth = RegionCommonGetBandwidth( testParam.datarate, BandwidthsUS915 );
            break;
        }
        default:
        {
            phyDr = LORA_SPREADING_FACTOR;
            bandwidth = LORA_BANDWIDTH;
            break;
        }

    }

    TestState |= TX_TEST_LORA;
    hop_flag = 1;
    /* Radio initialization */
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;
    Radio.Init(&RadioEvents);

    //testParam.freq_start = param->freq_start;
    testParam.freq_start = freq_seq[0];
    testParam.freq_stop = param->freq_stop;
    testParam.hp_step = param->hp_step;
    testParam.nb_tx = param->nb_tx;

    LORA_TEST_DEBUG("RX frequency %d", testParam.freq_start);
    LORA_TEST_DEBUG("RX frequency %d", testParam.freq_stop);
    LORA_TEST_DEBUG("RX frequency %d", testParam.hp_step);
    LORA_TEST_DEBUG("RX frequency %d", testParam.nb_tx);

    /*Fill payload with PRBS9 data*/
    Prbs9_generator(payload, testParam.payloadLen);
    freq_start_back = testParam.freq_start;
    packet_back = testParam.nb_tx;
    Radio.SetChannel(testParam.freq_start);
    Radio.SetTxConfig(testParam.modem, testParam.power, testParam.fdev, bandwidth, phyDr, testParam.coderate, testParam.preambleLen,
                      testParam.fixLen, testParam.crcOn, testParam.FreqHopOn, testParam.HopPeriod, testParam.iqInverted, testParam.txTimeout);
    TimerInit(&TxTimer, OnTxTimerEventRandom);
    TimerSetValue(&TxTimer, 500);
    TimerStart(&TxTimer);

    return UDRV_RETURN_OK;
  }
  else
  {
    return -UDRV_BUSY;
  }
}


void OnTxDone(void)
{
  if (packet==0||testParam.nb_tx==0)
  {
    service_lora_test_full_wake_unlock();
  }
  udrv_serial_log_printf("OnTxDone\r\n");
}

void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr)
{
  LORA_TEST_DEBUG("packet %d", packet);
  Rx_count_RxOk++;
  udrv_serial_log_printf("RssiValue= %d dBm, SnrValue= %d \r\n", rssi, snr);
  Recv_Enent();
}

void OnTxTimeout(void)
{
  Radio.Standby();
  LORA_TEST_DEBUG();
  service_lora_test_full_wake_unlock();
}

void OnRxTimeout(void)
{
  LORA_TEST_DEBUG("packet %d", packet);
  Rx_count_RxKo++; 
  Recv_Enent();
}

void OnRxError(void)
{
  LORA_TEST_DEBUG("packet %d", packet);
  Rx_count_RxKo++;
  Recv_Enent();
}

static int32_t Prbs9_generator(uint8_t *payload, uint8_t len)
{
  uint16_t prbs9_val = 2;

  for (int32_t i = 0; i < len * 8; i++)
  {
    /*fill buffer with prbs9 sequence*/
    int32_t newbit = (((prbs9_val >> 8) ^ (prbs9_val >> 4)) & 1);
    prbs9_val = ((prbs9_val << 1) | newbit) & 0x01ff;
    payload[i / 8] |= ((prbs9_val & 0x1) << (i % 8));
  }
  return 0;
}

static void OnTxTimerEvent(void)
{
  LORA_TEST_DEBUG();
  
  if (hop_flag)
  {
    LORA_TEST_DEBUG("nb_tx %d", testParam.nb_tx);

    testParam.nb_tx--;
    Radio.Send(payload, testParam.payloadLen);
    udrv_serial_log_printf("Tx Hop at %d Hz\r\n",testParam.freq_start);
    udrv_serial_log_printf("Tx Test : Packet %d of %d\r\n",( packet_back-testParam.nb_tx),packet_back);
    LORA_TEST_DEBUG("freq %d", testParam.freq_start);

    testParam.freq_start += testParam.hp_step;
    if (testParam.freq_start > testParam.freq_stop)
    {
      testParam.freq_start = freq_start_back;
    }
    Radio.SetChannel(testParam.freq_start);

    if (testParam.nb_tx)
      TimerStart(&TxTimer);
    else
    {
      TestState &= ~TX_TEST_LORA;
      TimerStop(&TxTimer);
      hop_flag = 0;
      //service_lora_test_full_wake_unlock();
    }
  }
  else
  {
    LORA_TEST_DEBUG("packet %d", packet);
    packet--;

    Radio.Send(payload, testParam.payloadLen);
    udrv_serial_log_printf("Tx Test : Packet %d of %d\r\n",( packet_back-packet),packet_back);
    if (packet)
      TimerStart(&TxTimer);
    else
    {
      TestState &= ~TX_TEST_LORA;
      TimerStop(&TxTimer);
      //service_lora_test_full_wake_unlock();
    }
  }
  
}

static void OnTxTimerEventRandom(void)
{
  LORA_TEST_DEBUG();

  if (hop_flag)
  {
    LORA_TEST_DEBUG("nb_tx %d", testParam.nb_tx);

    testParam.nb_tx--;
    Radio.Send(payload, testParam.payloadLen);
    udrv_serial_log_printf("Tx Hop at %d Hz\r\n",testParam.freq_start);
    udrv_serial_log_printf("Tx Test : Packet %d of %d\r\n",( packet_back-testParam.nb_tx),packet_back);
    LORA_TEST_DEBUG("freq %d", testParam.freq_start);

    testParam.freq_start = freq_seq[(packet_back-testParam.nb_tx)%freq_cnt];
    /*testParam.freq_start += testParam.hp_step;
    if (testParam.freq_start == 0 )
    {
        packet_back -= testParam.nb_tx;
        testParam.freq_start = freq_seq[packet_back-testParam.nb_tx];
    }*/
    Radio.SetChannel(testParam.freq_start);

    if (testParam.nb_tx)
      TimerStart(&TxTimer);
    else
    {
      TestState &= ~TX_TEST_LORA;
      TimerStop(&TxTimer);
      hop_flag = 0;
      //service_lora_test_full_wake_unlock();
    }
  }
  else
  {
    LORA_TEST_DEBUG("packet %d", packet);
    packet--;

    Radio.Send(payload, testParam.payloadLen);
    udrv_serial_log_printf("Tx Test : Packet %d of %d\r\n",( packet_back-packet),packet_back);
    if (packet)
      TimerStart(&TxTimer);
    else
    {
      TestState &= ~TX_TEST_LORA;
      TimerStop(&TxTimer);
      //service_lora_test_full_wake_unlock();
    }
  }
  
}


static void Recv_Enent(void)
{
  uint32_t PER = 0;
  packet--;
  PER = (100 * (Rx_count_RxKo)) / (Rx_count_RxKo + Rx_count_RxOk);
  udrv_serial_log_printf("Rx %d of %d  >>> PER= %d %%\r\n",(packet_back -packet) ,packet_back, PER);
  if (packet)
  {
    Radio.Rx(RX_TIMEOUT_VALUE);
  }
  else
  {
    TestState &= ~RX_TEST_LORA;
    Rx_count_RxKo=0;
    Rx_count_RxOk=0;
    Radio.Standby();
  }
}

int32_t service_lora_get_cw(testCwParameter_t *param)
{
  memcpy1(param, &cwParam, sizeof(testCwParameter_t));
  return UDRV_RETURN_OK;
}

int32_t service_lora_set_cw(testCwParameter_t *param)
{
  service_lora_test_full_wake_lock();

  cwParam.txTimeout = param->txTimeout;  //It's in seconds
  cwParam.frequency = param->frequency;
  cwParam.txpower =  param->txpower;

  LORA_TEST_DEBUG("cwParam.txpower %d cwParam.frequency %d cwParam.txpower %d\r\n",
  cwParam.txTimeout,cwParam.frequency,cwParam.txpower);

  RadioEvents.TxTimeout = OnTxTimeout;
  Radio.Init(&RadioEvents);

  Radio.SetTxContinuousWave( cwParam.frequency, cwParam.txpower, cwParam.txTimeout);
  // udrv_system_timer_stop(SYSTIMER_LORAWAN);
  // if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_test_wake_unlock, HTMR_ONESHOT) == UDRV_RETURN_OK)
  // {
  //     udrv_system_timer_start(SYSTIMER_LORAWAN, param->txTimeout*1000, NULL);
  // }
  // else
  // {
  //     return -UDRV_INTERNAL_ERR;
  // }
  return UDRV_RETURN_OK;
}

#endif

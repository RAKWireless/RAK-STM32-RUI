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
#include "timer.h"
#include "udrv_timer.h"
#include "LmhPackage.h"

#define LORAWAN_APP_DATA_MAX_SIZE                           242

#define LORAWAN_ADR_ON                              1

#define LORAWAN_DEFAULT_DATARATE                    DR_0

#define LORAWAN_APP_PORT                            2

#define LORAWAN_CONFIRMED_MSG_ON                    false

static uint8_t AppDataBuffer[LORAWAN_APP_DATA_MAX_SIZE];

static void CertifiTimerEvent( void* context );

uint32_t Certifi_Send(uint8_t port);

static bool SendFrame( void );

static uint8_t AppPort = LORAWAN_APP_PORT;

static uint8_t IsTxConfirmed = LORAWAN_CONFIRMED_MSG_ON;

struct ComplianceTest_s
{
    bool Running;
    uint8_t State;
    bool IsTxConfirmed;
    uint8_t AppPort;
    uint8_t AppDataSize;
    uint8_t *AppDataBuffer;
    uint16_t DownLinkCounter;
    bool LinkCheck;
    uint8_t DemodMargin;
    uint8_t NbGateways;
}ComplianceTest;

extern LmhPackage_t LmhpCompliancePackage;

TimerEvent_t CertifiTimer;

uint8_t AppDataSize;

int32_t service_lora_certification(int32_t mode)
{
    if (mode != 0) {
        service_lora_join(1, -1, -1, -1);

        LoRaMacTestSetDutyCycleOn( false );

        if (udrv_system_timer_create(SYSTIMER_LCT, CertifiTimerEvent, HTMR_PERIODIC) == UDRV_RETURN_OK)
        {
            udrv_system_timer_start(SYSTIMER_LCT, 6000, NULL);
        }
        else
        {
            udrv_serial_log_printf("FAILED(%d)\r\n", __LINE__);
        }
    } else {
        udrv_system_timer_stop(SYSTIMER_LCT);
    }

    return UDRV_RETURN_OK;
}

static void CertifiTimerEvent( void* context )
{
    LORA_TEST_DEBUG("CertifiTimerEvent");
    uint8_t Port = 2;
    if(service_lora_get_njs() != true)
    {
        service_lora_join(1, -1, -1, -1);
    }
    else if (LmhpCompliancePackage.IsRunning() == false)
    {
        Certifi_Send(LORAWAN_APP_PORT);
    }
}

uint32_t Certifi_Send(uint8_t port)
{
    switch( port )
    {
    case 2:
        {
            AppDataSize = 1;
            AppDataBuffer[0] = 0x43;
        }
        break;
    case 224:
        if( ComplianceTest.LinkCheck == true )
        {
            ComplianceTest.LinkCheck = false;
            AppDataSize = 3;
            AppDataBuffer[0] = 5;
            AppDataBuffer[1] = ComplianceTest.DemodMargin;
            AppDataBuffer[2] = ComplianceTest.NbGateways;
            ComplianceTest.State = 1;
        }
        else
        {
            switch( ComplianceTest.State )
            {
            case 4:
                ComplianceTest.State = 1;
                break;
            case 1:
                AppDataSize = 2;
                AppDataBuffer[0] = ComplianceTest.DownLinkCounter >> 8;
                AppDataBuffer[1] = ComplianceTest.DownLinkCounter;
                break;
            }
        }
        break;
    default:
        break;
    }

    SendFrame();
}

static bool SendFrame( void )
{
    McpsReq_t mcpsReq;
    LoRaMacTxInfo_t txInfo;
    LoRaMacStatus_t status;

    if( LoRaMacQueryTxPossible( AppDataSize, &txInfo ) != LORAMAC_STATUS_OK )
    {
        // Send empty frame in order to flush MAC commands
        mcpsReq.Type = MCPS_UNCONFIRMED;
        mcpsReq.Req.Unconfirmed.fBuffer = NULL;
        mcpsReq.Req.Unconfirmed.fBufferSize = 0;
        mcpsReq.Req.Unconfirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
    }
    else
    {
        if( IsTxConfirmed == false )
        {
            mcpsReq.Type = MCPS_UNCONFIRMED;
            mcpsReq.Req.Unconfirmed.fPort = AppPort;
            mcpsReq.Req.Unconfirmed.fBuffer = AppDataBuffer;
            mcpsReq.Req.Unconfirmed.fBufferSize = AppDataSize;
            mcpsReq.Req.Unconfirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
        }
        else
        {
            mcpsReq.Type = MCPS_CONFIRMED;
            mcpsReq.Req.Confirmed.fPort = AppPort;
            mcpsReq.Req.Confirmed.fBuffer = AppDataBuffer;
            mcpsReq.Req.Confirmed.fBufferSize = AppDataSize;
#if LORA_STACK_VER == 0x040407
            mcpsReq.Req.Confirmed.NbTrials = 8;
#elif LORA_STACK_VER == 0x040502
            //mcpsReq.Req.Confirmed.NbTrials = 8;
#else
            mcpsReq.Req.Confirmed.NbTrials = 8;
#endif
            mcpsReq.Req.Confirmed.Datarate = LORAWAN_DEFAULT_DATARATE;
        }
    }

    // Update global variable
    status = LoRaMacMcpsRequest( &mcpsReq );
    
    if( status != LORAMAC_STATUS_OK )
    {
        LORA_TEST_DEBUG("status=%d", status);
        return -UDRV_INTERNAL_ERR;
    }
    return UDRV_RETURN_OK;
}


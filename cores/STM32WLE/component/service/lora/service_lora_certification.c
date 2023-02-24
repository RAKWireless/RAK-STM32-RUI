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
#include "timer.h"
#include "udrv_timer.h"
#include "LmhPackage.h"
#include "LmhpCompliance.h"
#include "service_lora_certification.h"


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
    else if (LmhpCompliancePackage.IsRunning() == true)
    {
        char *context;
        OnComplianceTxNextPacketTimerEvent(context);
    }
}

uint32_t Certifi_Send(uint8_t port)
{
    /* No practical significance, just for sending */
    AppDataSize = 1; 
    AppDataBuffer[0] = 0x43;  
    
    int32_t ret = 0;
    SERVICE_LORA_SEND_INFO info;

    info.port = port;
    info.retry_valid = false;
    info.confirm_valid = false;

    if ((ret = service_lora_send(AppDataBuffer, AppDataSize, info, false)) == UDRV_RETURN_OK)
    {
        LORA_TEST_DEBUG("Send Packet Success\r\n");
    }
    else
    {
        LORA_TEST_DEBUG("Send Packet Fail\r\n");
        return LORAMAC_HANDLER_ERROR;
    }

    return LORAMAC_HANDLER_SUCCESS;
}


#endif 

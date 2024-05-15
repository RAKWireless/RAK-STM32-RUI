#include "radio.h"
#include "udrv_gpio.h"
#ifdef SUPPORT_LORA
#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_system.h"
#include "udrv_rtc.h"
#include "udrv_flash.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "service_lora.h"
#include "LoRaMac.h"
#include "Region.h"
#include "systime.h"
#include "utilities.h"
#include "service_lora_certification.h"
#include "RegionNvm.h"
#include "service_lora_arssi.h"
#include "service_lora_test.h"
#include "LmhPackage.h"
#include "LmhpCompliance.h"
#include "RegionCommon.h"
#include "RegionAS923.h"
#include "LmhpClockSync.h"
#include "LmhpRemoteMcastSetup.h"
#include "LmhpFragmentation.h"
#include "service_lora_fuota.h"




typedef enum PackageNotifyTypes_e
{
    PACKAGE_MCPS_CONFIRM,
    PACKAGE_MCPS_INDICATION,
    PACKAGE_MLME_CONFIRM,
    PACKAGE_MLME_INDICATION,
}PackageNotifyTypes_t;

static void LmHandlerPackagesNotify( PackageNotifyTypes_t notifyType, void *params );
static LmHandlerErrorStatus_t LmHandlerDeviceTimeReq( void );
static uint32_t IsSingleChannelAU915Callback(void);
static uint8_t AlternateDrAU915Callback(void);
static uint32_t IsSingleChannelUS915Callback(void);
static uint8_t AlternateDrUS915Callback(void);

static LmhPackage_t *LmHandlerPackages[PKG_MAX_NUMBER];

static LmhpComplianceParams_t LmhpComplianceParams;




#define LORAWAN_APP_DATA_BUFFER_MAX_SIZE            242
static uint8_t AppDataBuffer[LORAWAN_APP_DATA_BUFFER_MAX_SIZE];
/*!
 * MAC status strings
 */
static const char* MacStatusStrings[] =
{
    "OK",                            // LORAMAC_STATUS_OK
    "Busy",                          // LORAMAC_STATUS_BUSY
    "Service unknown",               // LORAMAC_STATUS_SERVICE_UNKNOWN
    "Parameter invalid",             // LORAMAC_STATUS_PARAMETER_INVALID
    "Frequency invalid",             // LORAMAC_STATUS_FREQUENCY_INVALID
    "Datarate invalid",              // LORAMAC_STATUS_DATARATE_INVALID
    "Frequency or datarate invalid", // LORAMAC_STATUS_FREQ_AND_DR_INVALID
    "No network joined",             // LORAMAC_STATUS_NO_NETWORK_JOINED
    "Length error",                  // LORAMAC_STATUS_LENGTH_ERROR
    "Region not supported",          // LORAMAC_STATUS_REGION_NOT_SUPPORTED
    "Skipped APP data",              // LORAMAC_STATUS_SKIPPED_APP_DATA
    "Duty-cycle restricted",         // LORAMAC_STATUS_DUTYCYCLE_RESTRICTED
    "No channel found",              // LORAMAC_STATUS_NO_CHANNEL_FOUND
    "No free channel found",         // LORAMAC_STATUS_NO_FREE_CHANNEL_FOUND
    "Busy beacon reserved time",     // LORAMAC_STATUS_BUSY_BEACON_RESERVED_TIME
    "Busy ping-slot window time",    // LORAMAC_STATUS_BUSY_PING_SLOT_WINDOW_TIME
    "Busy uplink collision",         // LORAMAC_STATUS_BUSY_UPLINK_COLLISION
    "Crypto error",                  // LORAMAC_STATUS_CRYPTO_ERROR
    "FCnt handler error",            // LORAMAC_STATUS_FCNT_HANDLER_ERROR
    "MAC command error",             // LORAMAC_STATUS_MAC_COMMAD_ERROR
    "ClassB error",                  // LORAMAC_STATUS_CLASS_B_ERROR
    "Confirm queue error",           // LORAMAC_STATUS_CONFIRM_QUEUE_ERROR
    "Multicast group undefined",     // LORAMAC_STATUS_MC_GROUP_UNDEFINED
    "Unknown error",                 // LORAMAC_STATUS_ERROR
};

static bool last_ack;
static uint8_t last_dlink_data[SERVICE_LORA_DLINK_BUFF_SIZE];
static uint8_t last_dlink_data_size;
static uint8_t last_dlink_port;
static SysTime_t btime;
static int16_t rssi;
static int8_t snr;
static uint32_t auto_join_retry_cnt;
static const char *slotStrings[] = {"1", "2", "C", "C", "B", "B"};
static beacon_bgw_t beacon_bgw;
static char *lorawan_ver = LORAWAN_VERSION;
static uint8_t linkcheck_flag;
static uint8_t DemodMargin;
static uint8_t NbGateways;
static uint8_t linkcheck_state;
static uint8_t is_init = 0;
static delay_send_t delay_send;
SERVICE_LORA_CLASS_B_STATE class_b_state = SERVICE_LORA_CLASS_B_S0;//Initial state

static service_lora_linkcheck_cb service_lora_linkcheck_callback;
static SERVICE_LORA_LINKCHECK_T linkcheck_data;
static int32_t service_lora_delay_send_process(void);
static service_lora_recv_cb service_lora_recv_callback;
static SERVICE_LORA_RECEIVE_T recv_data_pkg;
service_lora_join_cb service_lora_join_callback;
static service_lora_send_cb service_lora_send_callback;
static TIMEREQ_STATE timereq_status = TIMEREQ_DISABLED;
static service_lora_timereq_cb service_lora_timereq_callback;
extern bool udrv_powersave_in_sleep;
extern volatile testParameter_t testParam;
extern uint8_t last_tx_channel; 
static udrv_system_event_t rui_lora_join_cb_event = {.request = UDRV_SYS_EVT_OP_LORAWAN_JOIN_CB, .p_context = NULL};


static SingleChannel_t SingleChannelAU915 =
{
    .IsSingleChannel = IsSingleChannelAU915Callback,
    .AlternateDr = AlternateDrAU915Callback
};

static SingleChannel_t SingleChannelUS915 =
{
    .IsSingleChannel = IsSingleChannelUS915Callback,
    .AlternateDr = AlternateDrUS915Callback
};


static void service_lora_auto_join(void *m_data)
{
    service_lora_join(1, -1, -1, -1);
}

static int32_t service_lora_start(void)
{
    LoRaMacStatus_t Status = LoRaMacStart();
    if (Status == LORAMAC_STATUS_OK)
    {
        LORA_TEST_DEBUG("LORAMAC start OK!\r\n");
    }
    else
    {
        LORA_TEST_DEBUG("LORAMAC start FAILED!\r\n");
        return -UDRV_INTERNAL_ERR;
    }

#if 0 //lora still initialize, does not auto join immediately.
    if (service_lora_get_auto_join())
    {
        service_lora_join(1, -1, -1, -1);

        udrv_system_timer_stop(SYSTIMER_LORAWAN);

        auto_join_retry_cnt = 0;

        if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_auto_join, HTMR_PERIODIC) == UDRV_RETURN_OK)
        {
            udrv_system_timer_start(SYSTIMER_LORAWAN, service_lora_get_auto_join_period() * 1000, NULL);
        }
        else
        {
            udrv_serial_log_printf("+EVT:JOIN_FAILED_%d\r\n", __LINE__);
        }
    }
#endif

    return UDRV_RETURN_OK;
}

static int32_t service_lora_stop(void)
{
    LoRaMacStatus_t Status = LoRaMacStop();
    if (Status == LORAMAC_STATUS_BUSY)
    {
        return -UDRV_BUSY;
    }
    else if (Status != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    udrv_system_timer_stop(SYSTIMER_LORAWAN);

    return UDRV_RETURN_OK;
}

static void service_lora_beacon_acquisition(void *m_data)
{
    LoRaMacStatus_t status;
    MlmeReq_t mlmeReq;
    mlmeReq.Type = MLME_BEACON_ACQUISITION;

    status = LoRaMacMlmeRequest(&mlmeReq);

    if (status == LORAMAC_STATUS_OK)
    {
        LORA_TEST_DEBUG("Acquire Beacon Success\r\n");
    }
    else
    {
        //udrv_serial_log_printf("Acquire Beacon Fail\r\n");
        LORA_TEST_DEBUG("+BC:ONGOING\r\n");
    }
}

static void service_lora_send_null(uint8_t m_data)
{
    SERVICE_LORA_SEND_INFO info;
    int32_t ret;

    info.port = 1;
    info.retry_valid = true;
    info.retry = 3;
    info.confirm_valid = true;
    if( m_data == SERVICE_LORA_MAC_CMD_NONE)
        info.confirm = SERVICE_LORA_NO_ACK;
    else
        info.confirm = SERVICE_LORA_ACK;

    if ((ret = service_lora_send("", 0, info, false)) == UDRV_RETURN_OK)
    {
        LORA_TEST_DEBUG("Send Null Success\r\n");
    }
    else
    {
        LORA_TEST_DEBUG("ret=%d", ret);
        LORA_TEST_DEBUG("Send Null Fail\r\n");
    }    
}

static void McpsConfirm(McpsConfirm_t *mcpsConfirm)
{

    if (mcpsConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK)
    {
        last_ack = mcpsConfirm->AckReceived;
        if (service_lora_send_callback != NULL) {
            service_lora_send_callback(UDRV_RETURN_OK);
        }
    } else {
        last_ack = false;
        if (service_lora_send_callback != NULL) {
            service_lora_send_callback(mcpsConfirm->Status);
        }
    }

    if( mcpsConfirm->McpsRequest == MCPS_CONFIRMED)
    {
        if(mcpsConfirm->AckReceived)
            udrv_serial_log_printf("+EVT:SEND_CONFIRMED_OK\r\n");
        else
            udrv_serial_log_printf("+EVT:SEND_CONFIRMED_FAILED(%d)\r\n", mcpsConfirm->Status);
    }
    else {
        udrv_serial_log_printf("+EVT:TX_DONE\r\n");
    }

    service_lora_lptp_send_callback(0);

    LmHandlerPackagesNotify( PACKAGE_MCPS_CONFIRM, mcpsConfirm );
}

static void McpsIndication(McpsIndication_t *mcpsIndication)
{
    if (mcpsIndication->Status == LORAMAC_EVENT_INFO_STATUS_OK)
    {
        rssi = mcpsIndication->Rssi;
        snr = mcpsIndication->Snr;
        service_lora_arssi_rx_callback(rssi);

        if (mcpsIndication->BufferSize > 0)
        {
            udrv_serial_log_printf("+EVT:RX_%s:%d:%d", slotStrings[mcpsIndication->RxSlot], rssi, snr);
            if (mcpsIndication->Multicast == 1)
            {
                udrv_serial_log_printf(":MULTICAST");
            }
            else
            {
                udrv_serial_log_printf(":UNICAST");
            }
            udrv_serial_log_printf(":%d:", mcpsIndication->Port);
            for (int i = 0 ; i < SERIAL_MAX ; i++)
            {
                SERVICE_MODE_TYPE mode = service_nvm_get_mode_type_from_nvm((SERIAL_PORT)i);
                if (mode == SERVICE_MODE_TYPE_CLI) {
                    for (uint8_t j = 0; j < mcpsIndication->BufferSize; j++)
                    {
                        udrv_serial_printf((SERIAL_PORT)i, "%02x", mcpsIndication->Buffer[j]);
                    }
                    udrv_serial_printf((SERIAL_PORT)i, "\r\n");
                }
#ifdef SUPPORT_PASSTHRU
                else if (mode == SERVICE_MODE_TYPE_TRANSPARENT)
                {
                    if (mcpsIndication->Port == service_nvm_get_tp_port_from_nvm((SERIAL_PORT)i))
                    {
                        udrv_serial_write((SERIAL_PORT)i, mcpsIndication->Buffer, mcpsIndication->BufferSize);
                    }
                }
#endif
            }
            if (mcpsIndication->BufferSize >= SERVICE_LORA_DLINK_BUFF_SIZE)
            {
                memcpy(last_dlink_data, mcpsIndication->Buffer, SERVICE_LORA_DLINK_BUFF_SIZE-1);
                last_dlink_data_size = SERVICE_LORA_DLINK_BUFF_SIZE-1;
                last_dlink_data[SERVICE_LORA_DLINK_BUFF_SIZE-1] = '\0';
            }
            else
            {
                memcpy(last_dlink_data, mcpsIndication->Buffer, mcpsIndication->BufferSize);
                last_dlink_data_size = mcpsIndication->BufferSize;
            }
            last_dlink_port = mcpsIndication->Port;
        }

        //FramePending or Confirmed downlink
        if(((mcpsIndication->FramePending == true) && (service_lora_get_class() == SERVICE_LORA_CLASS_A)) || (mcpsIndication->McpsIndication == MCPS_CONFIRMED))
        {
            service_lora_send_null(SERVICE_LORA_MAC_CMD_NONE);
        }

        if (linkcheck_flag)
        {
            linkcheck_flag = 0;
            if (!linkcheck_state)
            {
                // Check DemodMargin
                // Check NbGateways
                udrv_serial_log_printf("+EVT:LINKCHECK:0:%d:%d:%d:%d\r\n", DemodMargin, NbGateways, rssi, snr);
                if (service_lora_linkcheck_callback != NULL) {
                    linkcheck_data.State = linkcheck_state;
                    linkcheck_data.DemodMargin = DemodMargin;
                    linkcheck_data.NbGateways = NbGateways;
                    linkcheck_data.Rssi = rssi;
                    linkcheck_data.Snr = snr;
                    service_lora_linkcheck_callback(&linkcheck_data);
                }
            }
        }

        if(( mcpsIndication->Port ) !=224)
        {
            if (service_lora_recv_callback != NULL) 
            {
                recv_data_pkg.Port = mcpsIndication->Port ;
                recv_data_pkg.RxDatarate = mcpsIndication->RxDatarate;
                recv_data_pkg.Buffer = mcpsIndication->Buffer;
                recv_data_pkg.BufferSize = mcpsIndication->BufferSize;
                recv_data_pkg.Rssi = mcpsIndication->Rssi;
                recv_data_pkg.Snr = mcpsIndication->Snr;
                recv_data_pkg.DownLinkCounter = mcpsIndication->DownLinkCounter;
                service_lora_recv_callback(&recv_data_pkg);
            }
        }

        LmHandlerPackagesNotify( PACKAGE_MCPS_INDICATION, mcpsIndication );

        service_lora_delay_send_process();
    }  
    if(service_get_debug_level())
    {
        MibRequestConfirm_t  mibReq;
        LoRaMacStatus_t status;

        mibReq.Type = MIB_NVM_CTXS;
        LoRaMacMibGetRequestConfirm(&mibReq);
        if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) == LORAMAC_STATUS_OK)
        {
            if(RX_SLOT_WIN_1 == mcpsIndication->RxSlot)
            {
                udrv_serial_log_printf("Receiving in RX_SLOT_WIN_1\r\n");
            }
            else if(RX_SLOT_WIN_2 == mcpsIndication->RxSlot)
            {
                udrv_serial_log_printf("Receiving in RX_SLOT_WIN_2\r\n");
            }
            else if(RX_SLOT_WIN_CLASS_C == mcpsIndication->RxSlot)
            {
                udrv_serial_log_printf("Receiving in RX_SLOT_WIN_CLASS_C\r\n");
            }
            udrv_serial_log_printf("DevAddress:%08x\r\n",mcpsIndication->DevAddress);
            udrv_serial_log_printf("Port:%d\r\n",mcpsIndication->Port);
            udrv_serial_log_printf("Rssi:%d\r\n",mcpsIndication->Rssi);
            udrv_serial_log_printf("Snr:%d\r\n",mcpsIndication->Snr);
            udrv_serial_log_printf("RxDatarate:%u\r\n",mcpsIndication->RxDatarate);
            udrv_serial_log_printf("FCntDown:%u\r\n",mibReq.Param.Contexts->Crypto.FCntList.FCntDown);
        }
        else
            udrv_serial_log_printf("LoRaMacMibGetRequestConfirm ERROR\r\n");
    }

}

static void MlmeConfirm(MlmeConfirm_t *mlmeConfirm)
{
    LmHandlerPackagesNotify( PACKAGE_MLME_CONFIRM, mlmeConfirm );

    switch (mlmeConfirm->MlmeRequest)
    {
    case MLME_JOIN:
        if (mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK)
        {
            LoRaMacStatus_t status;
            MlmeReq_t mlmeReq;

            udrv_serial_log_printf("+EVT:JOINED\r\n");

            udrv_system_timer_stop(SYSTIMER_LORAWAN);

            auto_join_retry_cnt = 0;

            if (service_lora_get_class() == SERVICE_LORA_CLASS_C)
            {
                MibRequestConfirm_t mibReq;

                // Class C is now activated
                mibReq.Type = MIB_DEVICE_CLASS;
                mibReq.Param.Class = CLASS_C;
                if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
                {
                    udrv_serial_log_printf("+EVT:SWITCH_FAILED\r\n");
                }
            }

            if (service_lora_join_callback != NULL) {
                service_lora_join_callback(UDRV_RETURN_OK);
            }
            service_lora_set_dr((SERVICE_LORA_DATA_RATE)service_nvm_get_dr_from_nvm(), false);
        }
        else
        {
            switch (mlmeConfirm->Status) {
                case LORAMAC_EVENT_INFO_STATUS_TX_TIMEOUT:
                {
                    udrv_serial_log_printf("+EVT:JOIN_FAILED_TX_TIMEOUT\r\n");
                    break;
                }
                case LORAMAC_EVENT_INFO_STATUS_RX1_TIMEOUT:
                case LORAMAC_EVENT_INFO_STATUS_RX2_TIMEOUT:
                {
                    udrv_serial_log_printf("+EVT:JOIN_FAILED_RX_TIMEOUT\r\n");
                    break;
                }
                default:
                {
                    udrv_serial_log_printf("+EVT:JOIN_FAILED_%d\r\n", mlmeConfirm->Status);
                    break;
                }
            }

            udrv_system_timer_stop(SYSTIMER_LORAWAN);


                if (++auto_join_retry_cnt > service_lora_get_auto_join_max_cnt())
                {
                    auto_join_retry_cnt = 0;
                }
                else
                {
                    if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_auto_join, HTMR_ONESHOT) == UDRV_RETURN_OK)
                    {
                        udrv_system_timer_start(SYSTIMER_LORAWAN, service_lora_get_auto_join_period() * 1000, NULL);
                    }
                    else
                    {
                        udrv_serial_log_printf("+EVT:JOIN_FAILED_%d\r\n", __LINE__);
                    }
                }

            //Consider join request in join callback, so use system event.
            if (service_lora_join_callback != NULL) {
                rui_lora_join_cb_event.p_context = (void *)mlmeConfirm->Status;
                udrv_system_event_produce(&rui_lora_join_cb_event);
	    }

            Radio.Sleep();
        }

        if (service_lora_get_class() != SERVICE_LORA_CLASS_B)
        {
        }
        if(service_get_debug_level())
        {
            MibRequestConfirm_t  mibReq;
            LoRaMacStatus_t status;

            mibReq.Type = MIB_NVM_CTXS;
            LoRaMacMibGetRequestConfirm(&mibReq);
            if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) == LORAMAC_STATUS_OK)
            {

                udrv_serial_log_printf("Receiving MLME_JOIN\r\n");
                udrv_serial_log_printf("DevAddr:%08x\r\n",mibReq.Param.Contexts->MacGroup2.DevAddr);
            }
            else
                udrv_serial_log_printf("LoRaMacMibGetRequestConfirm ERROR\r\n");
        }

        break;
    case MLME_DEVICE_TIME:
    {
        if (mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK)
        {
            if(timereq_status == TIMEREQ_ENABLED)
            {
                udrv_serial_log_printf("+EVT:TIMEREQ_OK\r\n");
                if (service_lora_timereq_callback != NULL) {
                    service_lora_timereq_callback(GET_DEVICE_TIME_OK);
                }
                timereq_status = TIMEREQ_DISABLED ;
            }
            LORA_TEST_DEBUG("Get Device Time Success\r\n");

            if (service_lora_get_class() == SERVICE_LORA_CLASS_B)
            {
                if (class_b_state != SERVICE_LORA_CLASS_B_COMPLETED) 
                {
                   
                    class_b_state = SERVICE_LORA_CLASS_B_S1;//Beacon searching
                    //Start searching for beacon now
                    service_lora_beacon_acquisition(NULL);
                }
            }
        }
        else
        {
            if(timereq_status == TIMEREQ_ENABLED)
            {
                udrv_serial_log_printf("+EVT:TIMEREQ_FAILED\r\n");
                if (service_lora_timereq_callback != NULL) {
                    service_lora_timereq_callback(GET_DEVICE_TIME_FAIL);
                }
                timereq_status = TIMEREQ_DISABLED ;
            }
        }
        break;
    }
    case MLME_PING_SLOT_INFO:
    {
        if (mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK)
        {
            class_b_state = SERVICE_LORA_CLASS_B_COMPLETED;//Class B enabled

            
            LoRaMacStatus_t status;
            MibRequestConfirm_t mibReq;
            // Class B is now activated
            mibReq.Type = MIB_DEVICE_CLASS;
            mibReq.Param.Class = CLASS_B;
            if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) == LORAMAC_STATUS_OK)
            {
                udrv_serial_log_printf("+BC:DONE\r\n");
                //classb bit is true , Need to send an empty packet to the server
                service_lora_send_null(SERVICE_LORA_MAC_CMD_PING_SLOT_INFO);
            }
            else
            {
                //Normal logic code will not run here
            }
        }
        else
        {
                //to do Add some error status 
        }
        break;
    }
    case MLME_LINK_CHECK:
    {
        linkcheck_flag = 1;
        DemodMargin = mlmeConfirm->DemodMargin;
        NbGateways = mlmeConfirm->NbGateways;
        linkcheck_state = mlmeConfirm->Status;
        if(linkcheck_state!= LORAMAC_EVENT_INFO_STATUS_OK)
        {
            udrv_serial_log_printf("+EVT:LINKCHECK:1:0:0:0:0\r\n");
            if (service_lora_linkcheck_callback != NULL) {
                linkcheck_data.State = linkcheck_state;
                linkcheck_data.DemodMargin = 0;
                linkcheck_data.NbGateways = 0;
                linkcheck_data.Rssi = 0;
                linkcheck_data.Snr = 0;
                service_lora_linkcheck_callback(&linkcheck_data);
            }
        }
        break;
    }
    case MLME_BEACON_ACQUISITION:
    {
        if (mlmeConfirm->Status == LORAMAC_EVENT_INFO_STATUS_OK)
        {
            
        }
        else
        {
            //LORAMAC_EVENT_INFO_STATUS_BEACON_NOT_FOUND
            udrv_serial_log_printf("+BC:FAILED\r\n");
            
            if (class_b_state != SERVICE_LORA_CLASS_B_COMPLETED) 
            {
                class_b_state = SERVICE_LORA_CLASS_B_S3;//Beacon failed
            }
            // First Beacon not acquired
            // Request Device Time again.  
            
            LoRaMacStatus_t status;
            MlmeReq_t mlmeReq;
            mlmeReq.Type = MLME_DEVICE_TIME;
            status = LoRaMacMlmeRequest( &mlmeReq );     
        }
        break;
    }
    default:
        break;
    }
}

static void MlmeIndication(MlmeIndication_t *mlmeIndication)
{
    LmHandlerPackagesNotify( PACKAGE_MLME_INDICATION, mlmeIndication );

    switch (mlmeIndication->MlmeIndication)
    {
    //Not received beacon for two hours 
    case MLME_BEACON_LOST:   
    {
        udrv_serial_log_printf("+BC:LOST\r\n");
        //user need to re execute the ClassB process
        class_b_state = SERVICE_LORA_CLASS_B_S0;

        MibRequestConfirm_t mibReq;
        // Switch to class A again
        mibReq.Type = MIB_DEVICE_CLASS;
        mibReq.Param.Class = CLASS_A;
        LoRaMacMibSetRequestConfirm( &mibReq );

    }
    break;
    case MLME_BEACON:
    {
        if (mlmeIndication->Status == LORAMAC_EVENT_INFO_STATUS_BEACON_LOCKED)
       {
            udrv_serial_log_printf("+BC:LOCKED\r\n");

            LORA_TEST_DEBUG("Lock Beacon Success\r\n");

            if (class_b_state != SERVICE_LORA_CLASS_B_COMPLETED) {
                class_b_state = SERVICE_LORA_CLASS_B_S2;//Beacon locked

                udrv_system_timer_stop(SYSTIMER_LORAWAN);
                if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_send_null, HTMR_ONESHOT) == UDRV_RETURN_OK)
                {
                    //The 32S time can be shortened appropriately, mainly to avoid the Lora channel congestion after receiving the beacon
                    uint32_t ran = random()%32+1;  
                    LORA_TEST_DEBUG("random backoff %u seconds\r\n", ran);
                    udrv_system_timer_start(SYSTIMER_LORAWAN, ran*1000, SERVICE_LORA_MAC_CMD_PING_SLOT_INFO);
                }
                else
                {
                    udrv_serial_log_printf("+BC:FAILED_%d\r\n", __LINE__);
                    udrv_system_timer_stop(SYSTIMER_LORAWAN);
                }
            }

            switch (mlmeIndication->BeaconInfo.GwSpecific.InfoDesc)
            {
            case 0:
                beacon_bgw.GPS_coordinate = 0;

                beacon_bgw.latitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[2] << 16)|
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[1] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[0]);
                beacon_bgw.longitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[5] << 16) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[4] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[3]);
		break;
            case 1:
                beacon_bgw.GPS_coordinate = 1;
		
                beacon_bgw.latitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[2] << 16)|
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[1] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[0]);
                beacon_bgw.longitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[5] << 16) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[4] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[3]);
		break;
            case 2:
                beacon_bgw.GPS_coordinate = 2;

                beacon_bgw.latitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[2] << 16)|
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[1] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[0]);
                beacon_bgw.longitude = (mlmeIndication->BeaconInfo.GwSpecific.Info[5] << 16) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[4] << 8) |
                                      (mlmeIndication->BeaconInfo.GwSpecific.Info[3]);
                break;
            case 3:
                beacon_bgw.net_ID = (mlmeIndication->BeaconInfo.GwSpecific.Info[2] << 16) |
                                    (mlmeIndication->BeaconInfo.GwSpecific.Info[1] << 8) |
                                    (mlmeIndication->BeaconInfo.GwSpecific.Info[0]);
                beacon_bgw.gateway_ID = (mlmeIndication->BeaconInfo.GwSpecific.Info[5] << 16) |
                                        (mlmeIndication->BeaconInfo.GwSpecific.Info[4] << 8) |
                                        (mlmeIndication->BeaconInfo.GwSpecific.Info[3]);
                break;
            default:
                break;
            }
        }
        else if (mlmeIndication->Status == LORAMAC_EVENT_INFO_STATUS_BEACON_LOST)
        {
            //Just print the log. The system has received the beacon before. Although it is lost this time, 
            //the system will automatically find the next beacon
            udrv_serial_log_printf("+BC:FAILED\r\n");
        }
        btime = mlmeIndication->BeaconInfo.Time;
        break;
    }
    default:
        break;
    }
}

static void OnMacProcessNotify(void)
{
    // Mac notification. Process run function
}

static LoRaMacPrimitives_t LoRaMacPrimitives;
static LoRaMacCallback_t LoRaMacCallbacks;

int32_t service_lora_init(SERVICE_LORA_BAND band)
{
    LoRaMacStatus_t Status;
    int32_t ret = UDRV_RETURN_OK;

    BoardInitMcu(); //initialize MCU for LoRa
#ifdef SUPPORT_LORA_P2P
    if (SERVICE_LORAWAN != service_lora_get_nwm())
    {
        service_lora_p2p_init();
        goto out;
    }
#endif
#ifdef REGION_AS923
     /*AS923 sub band selection*/
    if( band == SERVICE_LORA_AS923)
    {
        RegionAS923SubBandSet(AS923_1);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_2)
    {
        RegionAS923SubBandSet(AS923_2);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_3)
    {
        RegionAS923SubBandSet(AS923_3);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_4)
    {
        RegionAS923SubBandSet(AS923_4);
        band = SERVICE_LORA_AS923;
    }
#endif
    LoRaMacPrimitives.MacMcpsConfirm = McpsConfirm;
    LoRaMacPrimitives.MacMcpsIndication = McpsIndication;
    LoRaMacPrimitives.MacMlmeConfirm = MlmeConfirm;
    LoRaMacPrimitives.MacMlmeIndication = MlmeIndication;
    LoRaMacCallbacks.GetBatteryLevel = NULL;
    LoRaMacCallbacks.GetTemperatureLevel = NULL; // apply board specific temperature reading
    LoRaMacCallbacks.NvmDataChange = NULL;
    LoRaMacCallbacks.MacProcessNotify = OnMacProcessNotify;

    /**************************************************************************************
     *
     * Step 1. Start to init LoRaWAN stack with stack built-in config for the selected band.
     *
     **************************************************************************************/

    Status = LoRaMacInitialization(&LoRaMacPrimitives, &LoRaMacCallbacks, band);

    if (Status == LORAMAC_STATUS_OK)
    {
        MibRequestConfirm_t mibReq;
        uint8_t buff[16];
        is_init = 1;

        // Initialization successful
        LORA_TEST_DEBUG("LORAMAC initialization OK!\r\n");

        mibReq.Type = MIB_ABP_LORAWAN_VERSION;
        mibReq.Param.AbpLrWanVersion.Value = 0x01000300;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            ret = -UDRV_INTERNAL_ERR;
            goto out;
        }

        /**************************************************************************************
     *
     * Step 2. Start to apply the RUI saved LoRaWAN config.
     *
     **************************************************************************************/

        if ((band == SERVICE_LORA_AU915) || (band == SERVICE_LORA_US915) || (band == SERVICE_LORA_CN470) || (band == SERVICE_LORA_LA915))
        {
            uint16_t mask_tmp[REGION_NVM_CHANNELS_MASK_SIZE];
            uint16_t channel_mask = 0;
            uint8_t *p_mask;

            if ((ret = service_nvm_get_mask_from_nvm(mask_tmp)) != UDRV_RETURN_OK)
            {
                goto out;
            }
            p_mask = (uint8_t *)mask_tmp;
            for (uint8_t i = 0; i < REGION_NVM_CHANNELS_MASK_SIZE * 2; i++)
            {
                if (p_mask[i])
                    channel_mask |= (1 << i);
            }

            if (service_lora_get_chs() != 0)
            {
                if ((ret = service_lora_set_chs(service_lora_get_chs())) != UDRV_RETURN_OK)
                {
                    goto out;
                }
            }
            else
            {
                if ((ret = service_lora_set_mask(&channel_mask, false)) != UDRV_RETURN_OK)
                {
                    goto out;
                }
            }
        }

        /* Set CHS function of EU868 */
        if(band == SERVICE_LORA_EU868)
        {
            if (service_lora_get_chs() != 0)
            {
                if ((ret = service_lora_set_chs(0)) != UDRV_RETURN_OK)
                {
                    goto out;
                }
            }
        }

        if ((ret = service_lora_set_njm(service_nvm_get_njm_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_setup_multicast()) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_class(service_nvm_get_class_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_adr(service_nvm_get_adr_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_dr(service_nvm_get_dr_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_rx2dr(service_nvm_get_rx2dr_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_rx2freq(service_nvm_get_rx2fq_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            //Because the scope of rx2 is related to the region, in order to prevent ATR errors, no processing is done here
            //goto out;
        }

        if ((ret = service_lora_set_jn1dl(service_nvm_get_jn1dl_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_pub_nwk_mode(service_nvm_get_pub_nwk_mode_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_rx1dl(service_nvm_get_rx1dl_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        if ((ret = service_lora_set_txpower(service_nvm_get_txpower_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        
        if ((ret = service_lora_set_dcs(service_nvm_get_dcs_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            goto out;
        }

        /* Single channel register function */
#ifdef REGION_AU915
        AU915_SingleChannelRegisterCallback(&SingleChannelAU915);
#endif
#ifdef REGION_US915
        US915_SingleChannelRegisterCallback(&SingleChannelUS915);
#endif
        /* Compensate the timer */
        service_lora_systemMaxRxError();
 
        /**************************************************************************************
     *
     * Step 3. Start to enable LoRaWAN stack.
     *
     **************************************************************************************/

        if ((ret = service_lora_start()) != UDRV_RETURN_OK)
        {
            goto out;
        }
    }
    else
    {
        LORA_TEST_DEBUG("LORAMAC initialization FAILED!\r\n");
        ret = -UDRV_INTERNAL_ERR;
        goto out;
    }

//FIXME: Why does srandom() need USB enabled?
#ifdef SUPPORT_USB
    srandom(udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT));
#endif

    /*The LoRa-Alliance Compliance protocol package should always be initialized and activated.*/
    if (LmHandlerPackageRegister(PACKAGE_ID_COMPLIANCE, &LmhpComplianceParams) != LORAMAC_HANDLER_SUCCESS)
    {
        LORA_TEST_DEBUG("LORAMAC register compliance protocol FAILED!\r\n");
        ret = -UDRV_INTERNAL_ERR;
        goto out;
    }
    #ifdef SUPPORT_FUOTA    
    /*The LoraWan Clock Sync package should always be initialized and activated.*/
    if (LmHandlerPackageRegister(PACKAGE_ID_CLOCK_SYNC, NULL) != LORAMAC_HANDLER_SUCCESS)
    {
        LORA_TEST_DEBUG("LORAMAC register  Clock Sync FAILED!\r\n");
        ret = -UDRV_INTERNAL_ERR;
        goto out;
    }
    /*The LoraWan REMOTE MCAST package should always be initialized and activated.*/
    if (LmHandlerPackageRegister(PACKAGE_ID_REMOTE_MCAST_SETUP, NULL) != LORAMAC_HANDLER_SUCCESS)
    {
        LORA_TEST_DEBUG("LORAMAC register REMOTE MCAST FAILED!\r\n");
        ret = -UDRV_INTERNAL_ERR;
        goto out;
    }
    /*The LoraWan FRAGMENTATION package should always be initialized and activated.*/
    if (LmHandlerPackageRegister(PACKAGE_ID_FRAGMENTATION, &LmhpFragmentationParams) != LORAMAC_HANDLER_SUCCESS)
    {
        LORA_TEST_DEBUG("LORAMAC register FRAGMENTATION FAILED!\r\n");
        ret = -UDRV_INTERNAL_ERR;
        goto out;
    }    
    #endif //FUOTA    
out:
    /* ABP + classC Automatically open Rx_C */
    if((service_lora_get_class()!=SERVICE_LORA_CLASS_C)&&(service_lora_get_njm()!=SERVICE_LORA_ABP))
    {
        Radio.Sleep();
    }

    if ((SERVICE_LORAWAN == service_lora_get_nwm()) && (ret == UDRV_RETURN_OK) && service_lora_get_auto_join())
    {
        service_lora_join(service_lora_get_join_start(), service_lora_get_auto_join(), service_lora_get_auto_join_period(), service_lora_get_auto_join_max_cnt());
    }

    return ret;
}

int32_t service_lora_get_app_eui(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_app_eui_from_nvm(buff, len);
}

int32_t service_lora_set_app_eui(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_JOIN_EUI;
    mibReq.Param.JoinEui = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_app_eui_to_nvm(buff, len);
}

int32_t service_lora_get_app_key(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_app_key_from_nvm(buff, len);
}

int32_t service_lora_set_app_key(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_APP_KEY;
    mibReq.Param.AppKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_NWK_KEY;
    mibReq.Param.NwkKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_app_key_to_nvm(buff, len);
}

int32_t service_lora_get_app_skey(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_app_skey_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 16)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 16);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_APP_S_KEY;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, mibReq.Param.AppSKey, 16);
        return UDRV_RETURN_OK;
    }
    }
}

int32_t service_lora_set_app_skey(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_APP_S_KEY;
    mibReq.Param.AppSKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_app_skey_to_nvm(buff, len);
}

int32_t service_lora_get_dev_addr(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
        case SERVICE_LORA_ABP:
            return service_nvm_get_dev_addr_from_nvm(buff, len);
        case SERVICE_LORA_OTAA:
        default:
        {
            MibRequestConfirm_t mibReq;

            if (len < 4)
            {
                return -UDRV_INTERNAL_ERR;
            }

            if (service_lora_get_njs() == false)
            {
                memset(buff, 0, 4);
                return UDRV_RETURN_OK;
            }

            mibReq.Type = MIB_DEV_ADDR;
            if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }

            *(uint32_t *)buff = __builtin_bswap32(mibReq.Param.DevAddr);
            return UDRV_RETURN_OK;
        }
    }
}

int32_t service_lora_set_dev_addr(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_DEV_ADDR;
    mibReq.Param.DevAddr = __builtin_bswap32(*(uint32_t *)buff);
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_dev_addr_to_nvm(buff, len);
}

int32_t service_lora_get_dev_eui(uint8_t *buff, uint32_t len)
{
    return service_nvm_get_dev_eui_from_nvm(buff, len);
}

int32_t service_lora_set_dev_eui(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    /* P2P mode will also set deveui, which is used as a unique ID */
    if(SERVICE_LORAWAN==service_lora_get_nwm())
    {
        MibRequestConfirm_t mibReq;
        LoRaMacStatus_t status;

        mibReq.Type = MIB_DEV_EUI;
        mibReq.Param.DevEui = buff;
        if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
        {
            if (status == LORAMAC_STATUS_BUSY) {
                return -UDRV_BUSY;
            } else {
                return -UDRV_INTERNAL_ERR;
            }
        }
    }
    return service_nvm_set_dev_eui_to_nvm(buff, len);
}

int32_t service_lora_get_net_id(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_net_id_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 4)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 4);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_NET_ID;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, (uint8_t *)&mibReq.Param.NetID, 4);
        return UDRV_RETURN_OK;
    }
    }
}

int32_t service_lora_set_nwk_id(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_NET_ID;
    mibReq.Param.NetID = *(uint32_t *)buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_nwk_id_to_nvm(buff, len);
}

int32_t service_lora_get_nwk_skey(uint8_t *buff, uint32_t len)
{
    switch (service_lora_get_njm())
    {
    case SERVICE_LORA_ABP:
    {
        return service_nvm_get_nwk_skey_from_nvm(buff, len);
    }
    case SERVICE_LORA_OTAA:
    default:
    {
        MibRequestConfirm_t mibReq;

        if (len < 16)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if (service_lora_get_njs() == false)
        {
            memset(buff, 0, 16);
            return UDRV_RETURN_OK;
        }

        mibReq.Type = MIB_NWK_S_ENC_KEY;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        memcpy(buff, mibReq.Param.NwkSEncKey, 16);
        return UDRV_RETURN_OK;
    }
    }
}

int32_t service_lora_set_nwk_skey(uint8_t *buff, uint32_t len)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_F_NWK_S_INT_KEY;
    mibReq.Param.FNwkSIntKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_S_NWK_S_INT_KEY;
    mibReq.Param.SNwkSIntKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    mibReq.Type = MIB_NWK_S_ENC_KEY;
    mibReq.Param.NwkSEncKey = buff;
    if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        if (status == LORAMAC_STATUS_BUSY) {
            return -UDRV_BUSY;
        } else {
            return -UDRV_INTERNAL_ERR;
        }
    }

    return service_nvm_set_nwk_skey_to_nvm(buff, len);
}


int32_t service_lora_get_McRoot_key(uint8_t *buff)
{
    return Get_McRoot_Key(buff);
}


uint8_t service_lora_get_retry(void)
{
    return service_nvm_get_retry_from_nvm();
}

int32_t service_lora_set_retry(uint8_t retry)
{
    if(retry>7)
        return -UDRV_WRONG_ARG;   
    return service_nvm_set_retry_to_nvm(retry);
}

SERVICE_LORA_CONFIRM_MODE service_lora_get_cfm(void)
{
    return service_nvm_get_cfm_from_nvm();
}

int32_t service_lora_set_cfm(SERVICE_LORA_CONFIRM_MODE cfm)
{
    return service_nvm_set_cfm_to_nvm(cfm);
}

bool service_lora_get_cfs(void)
{
    return last_ack;
}

SERVICE_LORA_BAND service_lora_get_band(void)
{
    return service_nvm_get_band_from_nvm();
}

int32_t service_lora_set_band(SERVICE_LORA_BAND band)
{

#if defined(rak3172) || defined(rak3172T)
        /* Only RAK3172 supports hardware high and low frequency detection */
        uint8_t hardware_freq = 0;
        hardware_freq =  BoardGetHardwareFreq();
        if(hardware_freq)
        {
            if((band == SERVICE_LORA_CN470) || (band == SERVICE_LORA_EU433))
            {
                return -UDRV_UNSUPPORTED_BAND;
            }
        }
        else
        {
            if((band != SERVICE_LORA_CN470 ) && (band != SERVICE_LORA_EU433))
            {
                return -UDRV_UNSUPPORTED_BAND;
            }
        }
#endif 

    uint16_t mask = 0;
    int32_t ret;
    LoRaMacStatus_t Status;
    SERVICE_LORA_BAND AS923_sub_band_bak = 0;

    if (band == service_lora_get_band())
    {
        return UDRV_RETURN_OK;
    }

    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;

    /**************************************************************************************
     *
     * Step 1. Start to disable LoRaWAN stack.
     *
     **************************************************************************************/

    if ((ret = service_lora_stop()) != UDRV_RETURN_OK)
    {
        if(is_init)
            return ret;
    }

    if (service_lora_clear_multicast() != UDRV_RETURN_OK)
    {
        return ret;
    }

    if (service_nvm_set_chs_to_nvm(0) != UDRV_RETURN_OK)
    {
        return ret;
    }

#ifdef REGION_AS923
    /*AS923 sub band selection*/
    if( band == SERVICE_LORA_AS923)
    {
        AS923_sub_band_bak = SERVICE_LORA_AS923;
        RegionAS923SubBandSet(AS923_1);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_2)
    {
        AS923_sub_band_bak = SERVICE_LORA_AS923_2;
        RegionAS923SubBandSet(AS923_2);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_3)
    {
        AS923_sub_band_bak = SERVICE_LORA_AS923_3;
        RegionAS923SubBandSet(AS923_3);
        band = SERVICE_LORA_AS923;
    }
    if( band == SERVICE_LORA_AS923_4)
    {
        AS923_sub_band_bak = SERVICE_LORA_AS923_4;
        RegionAS923SubBandSet(AS923_4);
        band = SERVICE_LORA_AS923;
    }
#endif
    /**************************************************************************************
     *
     * Step 2. Start to init LoRaWAN stack with built-in config for the selected band.
     *
     **************************************************************************************/

    Status = LoRaMacInitialization(&LoRaMacPrimitives, &LoRaMacCallbacks, band);

    if (Status == LORAMAC_STATUS_OK)
    {
        MibRequestConfirm_t mibReq;
        uint8_t buff[16];

        // Initialization successful
        LORA_TEST_DEBUG("LORAMAC initialization OK!\r\n");

        /**************************************************************************************
     *
     * Step 3. Replace RUI saved config with the stack built-in config for the selected band.
     *
     **************************************************************************************/

        mibReq.Type = MIB_CHANNELS_DEFAULT_DATARATE;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
        if ((ret = service_nvm_set_dr_to_nvm(mibReq.Param.ChannelsDefaultDatarate)) != UDRV_RETURN_OK)
        {
            return ret;
        }

        mibReq.Type = MIB_RX2_DEFAULT_CHANNEL;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
        if ((ret = service_nvm_set_rx2dr_to_nvm(mibReq.Param.Rx2Channel.Datarate)) != LORAMAC_STATUS_OK)
        {
            return ret;
        }

        mibReq.Type = MIB_RX2_DEFAULT_CHANNEL;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
        if ((ret = service_nvm_set_rx2fq_to_nvm(mibReq.Param.Rx2Channel.Frequency)) != LORAMAC_STATUS_OK)
        {
            return ret;
        }

        mibReq.Type = MIB_CHANNELS_DEFAULT_TX_POWER;
        if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
        if ((ret = service_nvm_set_txpower_to_nvm(mibReq.Param.ChannelsDefaultTxPower)) != UDRV_RETURN_OK)
        {
            return ret;
        }

        if (band == SERVICE_LORA_AU915 || band == SERVICE_LORA_US915 || band == SERVICE_LORA_CN470 || band == SERVICE_LORA_LA915)
        {
            mibReq.Type = MIB_CHANNELS_DEFAULT_MASK;
            if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }

            if ((ret = service_nvm_set_mask_to_nvm(mibReq.Param.ChannelsDefaultMask)) != UDRV_RETURN_OK)
            {
                return ret;
            }

            if (service_nvm_set_chs_to_nvm(0) != UDRV_RETURN_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
        }

        /**************************************************************************************
     *
     * Step 4. Save the new band config.
     *
     **************************************************************************************/
#ifdef REGION_AS923 
        /*AS923 sub band selection*/
        if( AS923_sub_band_bak != NULL )
        {
            band = AS923_sub_band_bak;
        }
#endif
        if ((ret = service_nvm_set_band_to_nvm(band)) != UDRV_RETURN_OK)
        {
            return ret;
        }

        /**************************************************************************************
     *
     * Step 5-1. Start to init LoRaWAN stack with built-in config for the selected band.
     * Step 5-2. Start to apply the RUI saved LoRaWAN config.
     * Step 5-3. Start to enable LoRaWAN stack.
     *
     **************************************************************************************/

        if ((ret = service_lora_init(band)) != UDRV_RETURN_OK)
        {
            return ret;
        }
    }
    else
    {
        LORA_TEST_DEBUG("LORAMAC initialization FAILED!\r\n");
        return -UDRV_INTERNAL_ERR;
    }

    return UDRV_RETURN_OK;
}

int32_t service_lora_get_mask(uint16_t *mask)
{
#if defined(REGION_CN470) || defined(REGION_US915) || \
    defined(REGION_AU915) || defined(REGION_LA915)
    SERVICE_LORA_BAND band = service_lora_get_band();

    if ((band != SERVICE_LORA_AU915) && (band != SERVICE_LORA_US915) && (band != SERVICE_LORA_CN470)  && (band != SERVICE_LORA_LA915))
        return -UDRV_WRONG_ARG;

    uint16_t channel_mask = 0;
    uint16_t mask_tmp[REGION_NVM_CHANNELS_MASK_SIZE];
    uint8_t *p_mask;

    service_nvm_get_mask_from_nvm(mask_tmp);
    p_mask = (uint8_t *)mask_tmp;
    for (uint8_t i = 0; i < REGION_NVM_CHANNELS_MASK_SIZE * 2; i++)
    {
        if (p_mask[i])
            channel_mask |= (1 << i);
    }

    if(band == SERVICE_LORA_US915 || band == SERVICE_LORA_AU915 || band == SERVICE_LORA_LA915)
    {
        channel_mask &= ~(1<<8);
    }

    *mask = channel_mask;

    return UDRV_RETURN_OK;
#else
    return -UDRV_INTERNAL_ERR;
#endif
}

int32_t service_lora_set_mask(uint16_t *mask, bool commit)
{
#if defined(REGION_CN470) || defined(REGION_US915) || \
    defined(REGION_AU915) || defined(REGION_LA915)
    SERVICE_LORA_BAND band = service_lora_get_band();
    uint16_t channel_mask[REGION_NVM_CHANNELS_MASK_SIZE] = {0};
    uint16_t mask_val[2] = {0x00FF, 0xFF00};
    LoRaMacStatus_t Status;
    int32_t ret;

    if ((band != SERVICE_LORA_AU915) && (band != SERVICE_LORA_US915) && (band != SERVICE_LORA_CN470) && (band != SERVICE_LORA_LA915))
    {
        return -UDRV_WRONG_ARG;
    }

    /**************************************************************************************
     *
     * Step 1. Start to disable LoRaWAN stack.
     *
     **************************************************************************************/

    if ((ret = service_lora_stop()) != UDRV_RETURN_OK)
    {
        return ret;
    }

    /**************************************************************************************
     *
     * Step 2. Start to set the new channel mask.
     *
     **************************************************************************************/

    {
        MibRequestConfirm_t mibReq;

        // Initialization successful
        LORA_TEST_DEBUG("LORAMAC initialization OK!\r\n");

        if (*mask == 0)
        { //All zero means enabling all channels; All ones still means enabling all channels.
            if (band == SERVICE_LORA_AU915)
                *mask = 0x01FF; // channels 0 - 71
            if (band == SERVICE_LORA_US915 || band == SERVICE_LORA_LA915)
                *mask = 0x00FF; // channels 0 - 71
            if (band == SERVICE_LORA_CN470)
                *mask = 0x0FFF; // channels 0 - 95
        }

        memset(channel_mask, 0x00, REGION_NVM_CHANNELS_MASK_SIZE * 2);
        for (uint8_t i = 0; i < REGION_NVM_CHANNELS_MASK_SIZE * 2; i++)
        {
            if (*mask & (1 << i))
            {
                channel_mask[i / 2] |= mask_val[i % 2];
            }
        }

        if(band == SERVICE_LORA_US915 || band == SERVICE_LORA_AU915 || band == SERVICE_LORA_LA915) 
        {
            channel_mask[4] &= ~(0x00FF<<0); 
            for(uint8_t i; i < 8;i++ )
            {
                if (*mask & (1 << i))
                {
                    channel_mask[4] |= 1<<i; 
                }
            }
        }

        mibReq.Type = MIB_CHANNELS_MASK;
        mibReq.Param.ChannelsMask = channel_mask;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        mibReq.Type = MIB_CHANNELS_DEFAULT_MASK;
        mibReq.Param.ChannelsDefaultMask = channel_mask;
        LoRaMacMibSetRequestConfirm( &mibReq );

        if(0!=service_nvm_get_chs_from_nvm())
        {
            if (service_nvm_set_chs_to_nvm(0) != UDRV_RETURN_OK)
            {
                return ret;
            }
        }
        /**************************************************************************************
     *
     * Step 3. Start to enable LoRaWAN stack.
     *
     **************************************************************************************/

        if ((ret = service_lora_start()) != UDRV_RETURN_OK)
        {
            return ret;
        }
    }

    if (commit)
    {
        return service_nvm_set_mask_to_nvm(channel_mask);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
#else
    return -UDRV_INTERNAL_ERR;
#endif
}

int32_t service_lora_join(int32_t param1, int32_t param2, int32_t param3, int32_t param4)
{
    LoRaMacStatus_t status;
    uint8_t rbuff[16];
    MibRequestConfirm_t mibReq;
    SERVICE_LORA_JOIN_MODE njm = service_lora_get_njm();
    int32_t ret;

    if (param1 != -1)
    {
        if ((bool)!!param1 != service_lora_get_join_start())
        {
            if ((ret = service_lora_set_join_start((bool)!!param1)) != UDRV_RETURN_OK)
            {
                return ret;
            }
        }
    }

    if (param2 != -1)
    {
        if ((bool)!!param2 != service_lora_get_auto_join())
        {
            if ((ret = service_lora_set_auto_join((bool)!!param2)) != UDRV_RETURN_OK)
            {
                return ret;
            }
        }
    }

    if (param3 != -1)
    {
        if (param3 != service_lora_get_auto_join_period())
        {
            if ((ret = service_lora_set_auto_join_period(param3)) != UDRV_RETURN_OK)
            {
                return ret;
            }
        }
    }

    if (param4 != -1)
    {
        if (param4 != service_lora_get_auto_join_max_cnt())
        {
            if ((ret = service_lora_set_auto_join_max_cnt(param4)) != UDRV_RETURN_OK)
            {
                return ret;
            }
        }
    }

    if (param1 == 0)
    {
        udrv_system_timer_stop(SYSTIMER_LORAWAN);
        auto_join_retry_cnt = 0;
        return UDRV_RETURN_OK;
    }

    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;


    if (njm == SERVICE_LORA_OTAA)
    {
        MlmeReq_t mlmeReq;

        // Setup the request type
        mlmeReq.Type = MLME_JOIN;

        mibReq.Type = MIB_NETWORK_ACTIVATION;
        mibReq.Param.NetworkActivation = ACTIVATION_TYPE_NONE;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        mlmeReq.Req.Join.Datarate = service_nvm_get_dr_from_nvm();

        status = LoRaMacMlmeRequest(&mlmeReq);
        LORA_TEST_DEBUG("status=%d", status);

        if (status == LORAMAC_STATUS_OK)
        {
            if (service_lora_get_class() == SERVICE_LORA_CLASS_B)
            {
                class_b_state = SERVICE_LORA_CLASS_B_S0;//Initial state
            }

        }
        else if (status == LORAMAC_STATUS_BUSY)
        {
            return -UDRV_BUSY;
        }
        else if (status == LORAMAC_STATUS_DUTYCYCLE_RESTRICTED)
        {
            udrv_system_timer_stop(SYSTIMER_LORAWAN);
            if (++auto_join_retry_cnt > service_lora_get_auto_join_max_cnt())
            {
                auto_join_retry_cnt = 0;
            }
            else
            {
                if (udrv_system_timer_create(SYSTIMER_LORAWAN, service_lora_auto_join, HTMR_ONESHOT) == UDRV_RETURN_OK)
                {
                    udrv_system_timer_start(SYSTIMER_LORAWAN, service_lora_get_auto_join_period() * 1000, NULL);
                }
                else
                {
                    udrv_serial_log_printf("+EVT:JOIN_FAILED_%d\r\n", __LINE__);
                }
            }
            udrv_serial_log_printf("Restricted_Wait_%d_ms\r\n", mlmeReq.ReqReturn.DutyCycleWaitTime);
            return -UDRV_BUSY;
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
    }
    else if (njm == SERVICE_LORA_ABP)
    {
        mibReq.Type = MIB_NETWORK_ACTIVATION;
        mibReq.Param.NetworkActivation = ACTIVATION_TYPE_ABP;
        if (LoRaMacMibSetRequestConfirm(&mibReq) == LORAMAC_STATUS_OK)
        {
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
        if (service_lora_get_class() == SERVICE_LORA_CLASS_C)
        { 
            // Class C is now activated
            mibReq.Type = MIB_DEVICE_CLASS;
            mibReq.Param.Class = CLASS_C;
            LoRaMacMibSetRequestConfirm(&mibReq);
        } else if (service_lora_get_class() == SERVICE_LORA_CLASS_B)
        {
        }
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
    if(service_get_debug_level())
    {
        MibRequestConfirm_t  mibReq;
        LoRaMacRegion_t region;
        LoRaMacStatus_t status;

        mibReq.Type = MIB_NVM_CTXS;
        LoRaMacMibGetRequestConfirm(&mibReq);
        if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) == LORAMAC_STATUS_OK)
        {
            region = mibReq.Param.Contexts->MacGroup2.Region;
            udrv_serial_log_printf("Frequency:%u\r\n",mibReq.Param.Contexts->RegionGroup2.Channels[last_tx_channel].Frequency);
            if(region == LORAMAC_REGION_AU915 || region == LORAMAC_REGION_US915)
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency + (last_tx_channel%8)*( (uint32_t) 600000 ));
            }
            else if (region == LORAMAC_REGION_CN470)
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency + (last_tx_channel%48)*( (uint32_t) 200000 ));
            }
            else
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->RegionGroup2.Channels[last_tx_channel].Frequency);
            }
            udrv_serial_log_printf("RxCFrequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency);
            udrv_serial_log_printf("ChannelsDatarate:%d\r\n",mibReq.Param.Contexts->MacGroup1.ChannelsDatarate);
            udrv_serial_log_printf("ChannelsTxPower:%d\r\n",mibReq.Param.Contexts->MacGroup1.ChannelsTxPower);
            udrv_serial_log_printf("FCntUp:%u\r\n",mibReq.Param.Contexts->Crypto.FCntList.FCntUp);
        }
    }
    return UDRV_RETURN_OK;
}

int32_t service_lora_set_lora_default(void)
{
    LoRaMacStatus_t Status;
    int32_t ret;

    /**************************************************************************************
     *
     * Step 1. Start to disable LoRaWAN stack.
     *
     **************************************************************************************/

    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        SERVICE_LORA_BAND band = service_lora_get_band();
        if(band == SERVICE_LORA_AS923_2 || band == SERVICE_LORA_AS923_3 || band == SERVICE_LORA_AS923_4)
            band = SERVICE_LORA_AS923;
        if ((ret = service_lora_stop()) != UDRV_RETURN_OK && (RegionIsActive( band ) == true))
        {
            return ret;
        }
    }
    
    /**************************************************************************************
     *
     * Step 2. Restore the default configuration and save it.
     *
     **************************************************************************************/

    if (service_nvm_set_default_config_to_nvm() != UDRV_RETURN_OK)
    {
        udrv_serial_log_printf("%s():Fail\r\n", __func__);
        return -UDRV_INTERNAL_ERR;
    }

    if(service_lora_clear_multicast()!= UDRV_RETURN_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    /**************************************************************************************
     *
     * Step 3-1. Start to init LoRaWAN stack with built-in config for the current band.
     * Step 3-2. Start to apply the RUI saved LoRaWAN config.
     * Step 3-3. Start to enable LoRaWAN stack.
     *
     **************************************************************************************/

    if (SERVICE_LORAWAN == service_lora_get_nwm())
    {
        SERVICE_LORA_BAND band = service_lora_get_band();
        if(band == SERVICE_LORA_AS923_2 || band == SERVICE_LORA_AS923_3 || band == SERVICE_LORA_AS923_4)
            band = SERVICE_LORA_AS923;
        if ((ret = service_lora_init(service_lora_get_band())) != UDRV_RETURN_OK && (RegionIsActive( band ) == true))
        {
            return ret;
        }
    }

    return UDRV_RETURN_OK;
}

SERVICE_LORA_WORK_MODE service_lora_get_nwm(void)
{
    return service_nvm_get_nwm_from_nvm();
}

int32_t service_lora_set_nwm(SERVICE_LORA_WORK_MODE nwm)
{

    switch (nwm)
    {
    case SERVICE_LORA_P2P:
    case SERVICE_LORAWAN:
    case SERVICE_LORA_FSK:
        break;
    default:
        return -UDRV_INTERNAL_ERR;
    }

    service_nvm_set_nwm_to_nvm(nwm);

    return UDRV_RETURN_OK;
}

SERVICE_LORA_JOIN_MODE service_lora_get_njm(void)
{
    return service_nvm_get_njm_from_nvm();
}

int32_t service_lora_set_njm(SERVICE_LORA_JOIN_MODE njm, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    uint8_t buff[16];
    int32_t ret;

    mibReq.Type = MIB_NETWORK_ACTIVATION;
    switch (njm)
    {
    case SERVICE_LORA_ABP:
        mibReq.Param.NetworkActivation = ACTIVATION_TYPE_ABP;
        break;
    case SERVICE_LORA_OTAA:
    default:
        if (LoRaMacMibGetRequestConfirm(&mibReq) == LORAMAC_STATUS_OK)
        {
            if (mibReq.Param.NetworkActivation == ACTIVATION_TYPE_ABP)
            {
                mibReq.Param.NetworkActivation = ACTIVATION_TYPE_NONE;
            }
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
        break;
    }
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    switch (njm)
    {
    case SERVICE_LORA_ABP:
        service_nvm_get_app_skey_from_nvm(buff, 16);
        mibReq.Type = MIB_APP_S_KEY;
        mibReq.Param.AppSKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        service_nvm_get_dev_addr_from_nvm(buff, 4);
        mibReq.Type = MIB_DEV_ADDR;
        mibReq.Param.DevAddr = __builtin_bswap32(*(uint32_t *)buff);
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        service_nvm_get_nwk_skey_from_nvm(buff, 16);
        mibReq.Type = MIB_F_NWK_S_INT_KEY;
        mibReq.Param.FNwkSIntKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        mibReq.Type = MIB_S_NWK_S_INT_KEY;
        mibReq.Param.SNwkSIntKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        mibReq.Type = MIB_NWK_S_ENC_KEY;
        mibReq.Param.NwkSEncKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        if ((ret = service_lora_set_class(service_nvm_get_class_from_nvm(), false)) != UDRV_RETURN_OK)
        {
            return ret;
        }

        break;
    case SERVICE_LORA_OTAA:
    default:
        service_nvm_get_dev_eui_from_nvm(buff, 8);
        mibReq.Type = MIB_DEV_EUI;
        mibReq.Param.DevEui = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        service_nvm_get_app_eui_from_nvm(buff, 8);
        mibReq.Type = MIB_JOIN_EUI;
        mibReq.Param.JoinEui = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        service_nvm_get_app_key_from_nvm(buff, 16);
        mibReq.Type = MIB_APP_KEY;
        mibReq.Param.AppKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        mibReq.Type = MIB_NWK_KEY;
        mibReq.Param.NwkKey = buff;
        if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }

        break;
    }

    if (commit)
    {
        return service_nvm_set_njm_to_nvm(njm);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

bool service_lora_get_njs(void)
{
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_NETWORK_ACTIVATION;
    status = LoRaMacMibGetRequestConfirm(&mibReq);

    if (status == LORAMAC_STATUS_OK)
    {
        if (mibReq.Param.NetworkActivation == ACTIVATION_TYPE_NONE)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int32_t service_lora_send(uint8_t *buff, uint32_t len, SERVICE_LORA_SEND_INFO info, bool blocking)
{
    LoRaMacStatus_t status;
    McpsReq_t mcpsReq;
    LoRaMacTxInfo_t txInfo;
    SERVICE_LORA_DATA_RATE dr = service_nvm_get_dr_from_nvm();
    bool tx_possible = true;
    MlmeReq_t mlmeReq;

    if (service_lora_get_njs() == false)
    {
        return -UDRV_NO_WAN_CONNECTION;
    }

    if (LoRaMacIsBusy() == true)
    {
        return -UDRV_BUSY;
    }

    if (service_lora_get_class() == SERVICE_LORA_CLASS_C)
    {
        // Class C is now activated
        MibRequestConfirm_t mibReq;
        mibReq.Type = MIB_DEVICE_CLASS;
        mibReq.Param.Class = CLASS_C;
        LoRaMacMibSetRequestConfirm(&mibReq);
    }
    else if (service_lora_get_class() == SERVICE_LORA_CLASS_B)
    {
        switch (class_b_state)
        {
            case SERVICE_LORA_CLASS_B_S0:
            {
                mlmeReq.Type = MLME_DEVICE_TIME;
                status = LoRaMacMlmeRequest(&mlmeReq);
                break;
            }
            case SERVICE_LORA_CLASS_B_S1:
            {
                //Nothing to do
                break;
            }
            case SERVICE_LORA_CLASS_B_S2:
            {
                //Stop the logic of automatic sending because the user send data manually
                udrv_system_timer_stop(SYSTIMER_LORAWAN);
                
                mlmeReq.Type = MLME_PING_SLOT_INFO;
                mlmeReq.Req.PingSlotInfo.PingSlot.Fields.Periodicity = service_lora_get_ping_slot_periodicity();
                mlmeReq.Req.PingSlotInfo.PingSlot.Fields.RFU = 0;
                status = LoRaMacMlmeRequest(&mlmeReq);
                break;
            }
            default:
            {
                //Do nothing
                break;
            }
        }
    }

    mcpsReq.Req.Unconfirmed.Datarate = dr;
    mcpsReq.Req.Confirmed.Datarate = dr;

    if (service_nvm_get_linkcheck_from_nvm() != LINK_CHECK_DISABLE)
    {
        if (service_nvm_get_linkcheck_from_nvm() == LINK_CHECK_ONCE)
            service_lora_set_linkcheck(LINK_CHECK_DISABLE);

        MlmeReq_t mlmeReq;
        mlmeReq.Type = MLME_LINK_CHECK;
        LoRaMacStatus_t status = LoRaMacMlmeRequest(&mlmeReq);
    }

    if (timereq_status == TIMEREQ_ENABLED)
    {
        /* + EVT handle sending callback function */
        MlmeReq_t mlmeReq;
        mlmeReq.Type = MLME_DEVICE_TIME;
        LoRaMacStatus_t status = LoRaMacMlmeRequest(&mlmeReq);
    }

    /* Check payload size first before send */
    status = LoRaMacQueryTxPossible( len , &txInfo );
    if(service_get_debug_level())
    {
        udrv_serial_log_printf("QueryTxPossible: %s, UserDataSize %d PossibleDataSize %d AdditionalFOptsSize %d\r\n", MacStatusStrings[status], len, txInfo.MaxPossibleApplicationDataSize, (txInfo.CurrentPossiblePayloadSize - txInfo.MaxPossibleApplicationDataSize));
    }
    if( status != LORAMAC_STATUS_OK ) /* if invalid, still send null packet for respond ack and trigger adr mechaniam */ 
    {
        //LORA_TEST_DEBUG("status %d CurrentPossiblePayloadSize %d MaxPossibleApplicationDataSize %d",
        //status,txInfo.CurrentPossiblePayloadSize,txInfo.MaxPossibleApplicationDataSize);
        // Send empty frame in order to flush MAC commands
        mcpsReq.Type = MCPS_UNCONFIRMED;
        mcpsReq.Req.Unconfirmed.fBuffer = NULL;
        mcpsReq.Req.Unconfirmed.fBufferSize = 0;
        tx_possible = false;
    }
    else
    {
        mcpsReq.Req.Unconfirmed.fPort = info.port;
        mcpsReq.Req.Unconfirmed.fBufferSize = len;
        mcpsReq.Req.Unconfirmed.fBuffer = buff;

        // Set the retry times
        if (true == info.retry_valid)
        {
#if LORA_STACK_VER == 0x040407
            mcpsReq.Req.Confirmed.NbTrials = info.retry;
#elif LORA_STACK_VER == 0x040502
            //mcpsReq.Req.Confirmed.NbTrials = info.retry;send
#else
            mcpsReq.Req.Confirmed.NbTrials = info.retry;
#endif
        }
        else
        {
#if LORA_STACK_VER == 0x040407
            mcpsReq.Req.Confirmed.NbTrials = service_nvm_get_retry_from_nvm()+1;
#elif LORA_STACK_VER == 0x040502
            //mcpsReq.Req.Confirmed.NbTrials = service_nvm_get_retry_from_nvm()+1;
#else
            mcpsReq.Req.Confirmed.NbTrials = service_nvm_get_retry_from_nvm()+1;
#endif
        }
        // Set the packet type
        if (true == info.confirm_valid)
        {
            if (info.confirm == SERVICE_LORA_NO_ACK)
                mcpsReq.Type = MCPS_UNCONFIRMED;
            else
                mcpsReq.Type = MCPS_CONFIRMED;
        }
        else
        {
            if (service_lora_get_cfm() == SERVICE_LORA_NO_ACK)
            {
                mcpsReq.Type = MCPS_UNCONFIRMED;
            }
            else
            {
                mcpsReq.Type = MCPS_CONFIRMED;
            }
        }
        last_ack = false;
    }

    status = LoRaMacMcpsRequest(&mcpsReq);
    LORA_TEST_DEBUG("status %d",status);
    LORA_TEST_DEBUG("DutyCycleWaitTime  %d",mcpsReq.ReqReturn.DutyCycleWaitTime);
    if(service_get_debug_level())
    {
        MibRequestConfirm_t  mibReq;
        LoRaMacRegion_t region;
        LoRaMacStatus_t status;

        mibReq.Type = MIB_NVM_CTXS;
        LoRaMacMibGetRequestConfirm(&mibReq);
        if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) == LORAMAC_STATUS_OK)
        {
            region = mibReq.Param.Contexts->MacGroup2.Region;
            udrv_serial_log_printf("Frequency:%u\r\n",mibReq.Param.Contexts->RegionGroup2.Channels[last_tx_channel].Frequency);
            if(region == LORAMAC_REGION_AU915 || region == LORAMAC_REGION_US915)
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency + (last_tx_channel%8)*( (uint32_t) 600000 ));
            }
            else if (region == LORAMAC_REGION_CN470)
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency + (last_tx_channel%48)*( (uint32_t) 200000 ));
            }
            else
            {
                udrv_serial_log_printf("Rx1Frequency:%u\r\n",mibReq.Param.Contexts->RegionGroup2.Channels[last_tx_channel].Frequency);
            }
            udrv_serial_log_printf("RxCFrequency:%u\r\n",mibReq.Param.Contexts->MacGroup2.MacParamsDefaults.RxCChannel.Frequency);
            udrv_serial_log_printf("ChannelsDatarate:%d\r\n",mibReq.Param.Contexts->MacGroup1.ChannelsDatarate);
            udrv_serial_log_printf("ChannelsTxPower:%d\r\n",mibReq.Param.Contexts->MacGroup1.ChannelsTxPower);
            udrv_serial_log_printf("FCntUp:%u\r\n",mibReq.Param.Contexts->Crypto.FCntList.FCntUp);
        }
    }


    if (status == LORAMAC_STATUS_OK)
    {
        if (tx_possible == false)
        {
            return -UDRV_WRONG_ARG;
        }

        if (blocking) {
#if 0
            udrv_app_delay_ms(service_lora_get_rx2dl());
#endif
        }
        return UDRV_RETURN_OK;
    }
    else if (status == LORAMAC_STATUS_BUSY_PING_SLOT_WINDOW_TIME)
    {
        return -UDRV_BUSY;
    }
    else if (status == LORAMAC_STATUS_BUSY_BEACON_RESERVED_TIME)
    {
        return -UDRV_BUSY;
    }
    else if (status == LORAMAC_STATUS_DUTYCYCLE_RESTRICTED)
    {
        udrv_serial_log_printf("Restricted_Wait_%d_ms\r\n", mcpsReq.ReqReturn.DutyCycleWaitTime);
        return -UDRV_BUSY;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

bool service_lora_get_adr(void)
{
    return service_nvm_get_adr_from_nvm();
}

int32_t service_lora_set_adr(bool adr, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_ADR;
    mibReq.Param.AdrEnable = adr;
    status = LoRaMacMibSetRequestConfirm(&mibReq);

    if(status == LORAMAC_STATUS_PARAMETER_INVALID) {
        return -UDRV_WRONG_ARG;
    } else if(status == LORAMAC_STATUS_BUSY) {
        return -UDRV_BUSY;
    }
    
    if (commit)
    {
        return service_nvm_set_adr_to_nvm(adr);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

SERVICE_LORA_CLASS service_lora_get_real_class_from_stack(void)
{
    MibRequestConfirm_t mibReq;
    LoRaMacStatus_t status;

    mibReq.Type = MIB_DEVICE_CLASS;
    if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    else
    {
        switch (mibReq.Param.Class)
        {
        case CLASS_A:
            return SERVICE_LORA_CLASS_A;
        case CLASS_B:
            return SERVICE_LORA_CLASS_B;
        case CLASS_C:
            return SERVICE_LORA_CLASS_C;
        default:
            return -UDRV_INTERNAL_ERR;
        }
    }
}

SERVICE_LORA_CLASS service_lora_get_class(void)
{
    return service_nvm_get_class_from_nvm();
}

int32_t service_lora_set_class(SERVICE_LORA_CLASS device_class, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    MlmeReq_t mlmeReq;
    LoRaMacStatus_t status;
    
    if (service_lora_get_njs() == true)
    {
        mibReq.Type = MIB_DEVICE_CLASS;
        if ((status = LoRaMacMibGetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
        else
        {
            switch (mibReq.Param.Class)
            {
            case CLASS_A:
                switch (device_class)
                {
                case SERVICE_LORA_CLASS_A:
                    //Skip switching class A to class A case.
                    goto skip_class_setting;
                case SERVICE_LORA_CLASS_B:
                    class_b_state = SERVICE_LORA_CLASS_B_S0;//Initial state

                    goto skip_class_setting;
                case SERVICE_LORA_CLASS_C:
                    mibReq.Param.Class = CLASS_C;
#ifdef SUPPORT_FUOTA   
                    IsMcSessionStarted = true;
#endif
                    break;
                default:
                    return -UDRV_INTERNAL_ERR;
                }
                break;
            case CLASS_B:
                switch (device_class)
                {
                case SERVICE_LORA_CLASS_A:
                    mibReq.Param.Class = CLASS_A;
                    break;
                case SERVICE_LORA_CLASS_B:
                    break;
                    //Skip switching class B to class B case.
                    goto skip_class_setting;
                case SERVICE_LORA_CLASS_C:
                    mibReq.Param.Class = CLASS_C;
#ifdef SUPPORT_FUOTA   
                    IsMcSessionStarted = true;
#endif
                    break;
                default:
                    return -UDRV_INTERNAL_ERR;
                }
                break;
            case CLASS_C:
                switch (device_class)
                {
                case SERVICE_LORA_CLASS_A:
                    mibReq.Param.Class = CLASS_A;
                    break;
                case SERVICE_LORA_CLASS_B:
                    class_b_state = SERVICE_LORA_CLASS_B_S0;//Initial state

                    goto skip_class_setting;
                case SERVICE_LORA_CLASS_C:
                    //Skip switching class C to class C case.
                    goto skip_class_setting;
                default:
                    return -UDRV_INTERNAL_ERR;
                }
                break;
            default:
                return -UDRV_INTERNAL_ERR;
            }
        }
        if ((status = LoRaMacMibSetRequestConfirm(&mibReq)) != LORAMAC_STATUS_OK)
        {
            return -UDRV_INTERNAL_ERR;
        }
    }
skip_class_setting:

    if (commit)
    {
        return service_nvm_set_class_to_nvm(device_class);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

bool service_lora_get_dcs(void)
{
    // GetPhyParams_t getPhy;
    // PhyParam_t phyParam;

    // getPhy.Attribute = PHY_DUTY_CYCLE;
    // phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    // return (uint32_t)phyParam.Value;
    return service_nvm_get_dcs_from_nvm();
}

int32_t service_lora_set_dcs(uint8_t dutycycle, bool commit )
{
    LoRaMacTestSetDutyCycleOn(dutycycle);

    if(commit)
    {
        return service_nvm_set_dcs_to_nvm(dutycycle);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

SERVICE_LORA_DATA_RATE service_lora_get_dr(void)
{
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_CHANNELS_DATARATE;
    status = LoRaMacMibGetRequestConfirm(&mibReq);
    //return service_nvm_get_dr_from_nvm();
    return mibReq.Param.ChannelsDatarate;
}

int32_t service_lora_set_dr(SERVICE_LORA_DATA_RATE dr, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_CHANNELS_DATARATE;
    mibReq.Param.ChannelsDatarate = (int8_t)dr;

    status = LoRaMacMibSetRequestConfirm(&mibReq);

    if (status == LORAMAC_STATUS_OK)
    {
        testParam.datarate = dr;
        if (commit)
        {
            return service_nvm_set_dr_to_nvm(dr);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }
    else if (status == LORAMAC_STATUS_PARAMETER_INVALID)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

uint32_t service_lora_get_jn1dl(void)
{
    return service_nvm_get_jn1dl_from_nvm();
}

int32_t service_lora_set_jn1dl(uint32_t jn1dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_JOIN_ACCEPT_DELAY_1;
    mibReq.Param.JoinAcceptDelay1 = jn1dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_jn1dl_to_nvm(jn1dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

uint32_t service_lora_get_jn2dl(void)
{
    return service_nvm_get_jn2dl_from_nvm();
}

int32_t service_lora_set_jn2dl(uint32_t jn2dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_JOIN_ACCEPT_DELAY_2;
    mibReq.Param.JoinAcceptDelay2 = jn2dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_jn2dl_to_nvm(jn2dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}


bool service_lora_get_pub_nwk_mode(void)
{
    return service_nvm_get_pub_nwk_mode_from_nvm();
}

int32_t service_lora_set_pub_nwk_mode(bool pnm, bool commit)
{ 
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_PUBLIC_NETWORK;
    mibReq.Param.EnablePublicNetwork = pnm;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        return service_nvm_set_pub_nwk_mode_to_nvm(pnm);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

uint32_t service_lora_get_rx1dl(void)
{
    if ((service_lora_get_njm() == SERVICE_LORA_OTAA) && service_lora_get_njs())
    {
        MibRequestConfirm_t mibReq;

        mibReq.Type = MIB_RECEIVE_DELAY_1;
        if (LoRaMacMibGetRequestConfirm(&mibReq) == LORAMAC_STATUS_OK)
        {
            return mibReq.Param.ReceiveDelay1;
        }
    }
    else
    {
        return service_nvm_get_rx1dl_from_nvm();
    }
}

int32_t service_lora_set_rx1dl(uint32_t rx1dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_RECEIVE_DELAY_1;
    mibReq.Param.ReceiveDelay1 = rx1dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RECEIVE_DELAY_2;
    mibReq.Param.ReceiveDelay2 = rx1dl + 1000;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        if ((ret = service_nvm_set_rx2dl_to_nvm(rx1dl + 1000)) != UDRV_RETURN_OK)
        {
            return ret;
        }
        return service_nvm_set_rx1dl_to_nvm(rx1dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

uint32_t service_lora_get_rx2dl(void)
{
    return service_nvm_get_rx2dl_from_nvm();
}

int32_t service_lora_set_rx2dl(uint32_t rx2dl, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;
    int32_t ret;

    mibReq.Type = MIB_RECEIVE_DELAY_2;
    mibReq.Param.ReceiveDelay2 = rx2dl;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RECEIVE_DELAY_1;
    mibReq.Param.ReceiveDelay1 = rx2dl - 1000;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    if (commit)
    {
        if ((ret = service_nvm_set_rx1dl_to_nvm(rx2dl - 1000)) != UDRV_RETURN_OK)
        {
            return ret;
        }
        return service_nvm_set_rx2dl_to_nvm(rx2dl);
    }
    else
    {
        return UDRV_RETURN_OK;
    }
}

uint8_t service_lora_get_txpower(void)
{
    return service_nvm_get_txpower_from_nvm();
}

int32_t service_lora_set_txpower(uint8_t txp, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_CHANNELS_TX_POWER;
    mibReq.Param.ChannelsTxPower = txp;

    status = LoRaMacMibSetRequestConfirm(&mibReq);
    if (status == LORAMAC_STATUS_OK)
    {
        testParam.power = txp;
        if (commit)
        {
            return service_nvm_set_txpower_to_nvm(txp);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }
    else if (status == LORAMAC_STATUS_PARAMETER_INVALID)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

uint8_t service_lora_get_ping_slot_periodicity(void)
{
    return service_nvm_get_ping_slot_periodicity_from_nvm();
}

int32_t service_lora_set_ping_slot_periodicity(uint8_t periodicity)
{
    return service_nvm_set_ping_slot_periodicity_to_nvm(periodicity);
}

uint32_t service_lora_get_beacon_freq(void)
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    getPhy.Attribute = PHY_BEACON_CHANNEL_FREQ;
    phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    return (uint32_t)phyParam.Value;
}


uint32_t service_lora_get_beacon_dr(void)
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    getPhy.Attribute = PHY_BEACON_CHANNEL_DR;
    phyParam = RegionGetPhyParam(service_lora_get_band(), &getPhy);
    return (uint32_t)phyParam.Value;
}

uint32_t service_lora_get_beacon_time(void)
{
    return (uint32_t)btime.Seconds;
}

int16_t service_lora_get_rssi(void)
{
    return rssi;
}

int8_t service_lora_get_snr(void)
{
    return snr;
}

int32_t service_lora_get_local_time(char *local_time)
{
    struct tm localtime;
    SysTime_t UnixEpoch = SysTimeGet();

    UnixEpoch.Seconds -= 18; /*removing leap seconds*/
    SysTimeLocalTime(UnixEpoch.Seconds, &localtime);
    sprintf(local_time, "%02dh%02dm%02ds on %02d/%02d/%04d", localtime.tm_hour, localtime.tm_min, localtime.tm_sec,
            localtime.tm_mon + 1, localtime.tm_mday, localtime.tm_year + 1900);

    return UDRV_RETURN_OK;
}

uint32_t service_lora_get_lorawan_version(char **version)
{
    *version = lorawan_ver;
    return UDRV_RETURN_OK;
}

uint32_t service_lora_get_rx2freq(void)
{
    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    return mibReq.Param.Rx2Channel.Frequency;
}

uint32_t service_lora_set_rx2freq(uint32_t freq,bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    
    mibReq.Param.Rx2Channel.Frequency = freq;
    if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        if (commit)
        {
            return service_nvm_set_rx2fq_to_nvm(freq);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }


}

uint32_t service_lora_set_rx2dr(SERVICE_LORA_DATA_RATE datarate, bool commit)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if (service_lora_region_isActive(band) == false)
        return -UDRV_UNSUPPORTED_BAND;
    LoRaMacStatus_t status;
    MibRequestConfirm_t mibReq;

    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }

    mibReq.Type = MIB_RXC_CHANNEL;
    mibReq.Param.RxCChannel.Datarate = (uint8_t)datarate;

    status = LoRaMacMibSetRequestConfirm(&mibReq);

    mibReq.Type = MIB_RX2_CHANNEL;
    mibReq.Param.Rx2Channel.Datarate = (uint8_t)datarate;

    status = LoRaMacMibSetRequestConfirm(&mibReq);
    if (status == LORAMAC_STATUS_OK)
    {
        if (commit)
        {
            return service_nvm_set_rx2dr_to_nvm(datarate);
        }
        else
        {
            return UDRV_RETURN_OK;
        }
    }
    else if (status == LORAMAC_STATUS_PARAMETER_INVALID)
    {
        return -UDRV_WRONG_ARG;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

SERVICE_LORA_DATA_RATE service_lora_get_rx2dr(void)
{
    MibRequestConfirm_t mibReq;
    mibReq.Type = MIB_RX2_CHANNEL;
    if (LoRaMacMibGetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
    {
        return -UDRV_INTERNAL_ERR;
    }
    return mibReq.Param.Rx2Channel.Datarate;
    //return service_nvm_get_rx2dr_from_nvm();
}

uint8_t service_lora_get_linkcheck(void)
{
    return service_nvm_get_linkcheck_from_nvm();
}

int32_t service_lora_set_linkcheck(uint8_t mode)
{
    if(mode>2)
    {
        return -UDRV_WRONG_ARG;
    }
    return service_nvm_set_linkcheck_to_nvm(mode);
}


uint8_t service_lora_get_timereq(void)
{
    return timereq_status;
}

int32_t service_lora_set_timereq(uint8_t mode)
{
    if (service_lora_get_njs() == false)
    {
        return -UDRV_NO_WAN_CONNECTION;
    }

    if(mode>1)
    {
        return -UDRV_WRONG_ARG;
    }

    timereq_status = mode ;

    return UDRV_RETURN_OK;
}


bool service_lora_get_join_start(void)
{
    return service_nvm_get_join_start_from_nvm();
}

int32_t service_lora_set_join_start(bool join_start)
{
    return service_nvm_set_join_start_to_nvm(join_start);
}

bool service_lora_get_auto_join(void)
{
    return service_nvm_get_auto_join_from_nvm();
}

int32_t service_lora_set_auto_join(bool auto_join)
{
    return service_nvm_set_auto_join_to_nvm(auto_join);
}

uint32_t service_lora_get_auto_join_period(void)
{
    return service_nvm_get_auto_join_period_from_nvm();
}

int32_t service_lora_set_auto_join_period(uint32_t auto_join_period)
{
    return service_nvm_set_auto_join_period_to_nvm(auto_join_period);
}

uint32_t service_lora_get_auto_join_max_cnt(void)
{
    return service_nvm_get_auto_join_max_cnt_from_nvm();
}

int32_t service_lora_set_auto_join_max_cnt(uint32_t auto_join_max_cnt)
{
    return service_nvm_set_auto_join_max_cnt_to_nvm(auto_join_max_cnt);
}

int32_t service_lora_get_last_recv(uint8_t *port, uint8_t *buff, uint32_t len)
{
    int32_t actual_len;

    if (len < last_dlink_data_size)
    {
        actual_len = len;
    }
    else
    {
        actual_len = last_dlink_data_size;
    }
    memcpy(buff, last_dlink_data, actual_len);
    *port = last_dlink_port;
    last_dlink_data_size = 0;
    last_dlink_port = 0;

    return actual_len;
}

beacon_bgw_t service_lora_get_beacon_gwspecific(void)
{
    return beacon_bgw;
}

int32_t service_lora_set_chs(uint32_t frequency)
{
    uint8_t i, max_nb_ch, j;
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;
    uint16_t channel_mask[REGION_NVM_CHANNELS_MASK_SIZE] = {0};
    SERVICE_LORA_BAND band = service_lora_get_band();
    MibRequestConfirm_t mibReq;

    if ((band != SERVICE_LORA_AU915) && (band != SERVICE_LORA_US915) && (band != SERVICE_LORA_CN470)&& (band != SERVICE_LORA_EU868) && (band != SERVICE_LORA_LA915))
    {
        return -UDRV_INTERNAL_ERR;
    }
    else
    {
        if((band == SERVICE_LORA_AU915)||(band == SERVICE_LORA_US915)||(band == SERVICE_LORA_CN470) || (band == SERVICE_LORA_LA915))
        {
        if (frequency == 0)
        {
            uint16_t lora_service_channel_mask = 0;
            uint8_t *p_mask;
            if (service_nvm_get_mask_from_nvm(channel_mask) != UDRV_RETURN_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            p_mask = (uint8_t *)channel_mask;
            for (uint8_t i = 0; i < REGION_NVM_CHANNELS_MASK_SIZE * 2; i++)
            {
                if (p_mask[i])
                    lora_service_channel_mask |= (1 << i);
            }
            if (service_lora_set_mask(&lora_service_channel_mask, false) != UDRV_RETURN_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            service_nvm_set_chs_to_nvm(frequency);
            return UDRV_RETURN_OK;
        }

        getPhy.Attribute = PHY_MAX_NB_CHANNELS;
        phyParam = RegionGetPhyParam(band, &getPhy);
        max_nb_ch = phyParam.Value;
        mibReq.Type = MIB_CHANNELS;
        LoRaMacMibGetRequestConfirm(&mibReq);

        for (i = 0; i < max_nb_ch; i++)
        {
            if (frequency == mibReq.Param.ChannelList[i].Frequency)
            {
                channel_mask[i / 16] = 1 << (i % 16);
                mibReq.Type = MIB_CHANNELS_MASK;
                mibReq.Param.ChannelsMask = channel_mask;
                if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
                {
                    return -UDRV_INTERNAL_ERR;
                }

                mibReq.Type = MIB_CHANNELS_DEFAULT_MASK;
                mibReq.Param.ChannelsMask = channel_mask;
                if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
                {
                    return -UDRV_INTERNAL_ERR;
                }
                service_nvm_set_chs_to_nvm(frequency);
                return UDRV_RETURN_OK;
            }
        }
        if (i == max_nb_ch)
        {
            return -UDRV_WRONG_ARG;
            }
        }
        else if(band == SERVICE_LORA_EU868)
        {
            //Restore default mask
            if(frequency==0)
            {
                channel_mask[0] = LC( 1 ) + LC( 2 ) + LC( 3 );
            }
            else
            {
                //Check whether the frequency meets the requirements
                mibReq.Type = MIB_CHANNELS;
                LoRaMacMibGetRequestConfirm(&mibReq);

                for(i=0;i<4;i++)
                {
                    if(frequency == mibReq.Param.ChannelList[i].Frequency)
                    {
                        channel_mask[0]=LC( i+1 );
                        break;
                    }
                    if(i==3)
                    {
                        return -UDRV_WRONG_ARG;
                    }
                }
            }
            
            mibReq.Type = MIB_CHANNELS_MASK;
            mibReq.Param.ChannelsMask = channel_mask;
            if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
             {
                return -UDRV_INTERNAL_ERR;
            }

            mibReq.Type = MIB_CHANNELS_DEFAULT_MASK;
            mibReq.Param.ChannelsMask = channel_mask;
            if (LoRaMacMibSetRequestConfirm(&mibReq) != LORAMAC_STATUS_OK)
            {
                return -UDRV_INTERNAL_ERR;
            }
            return service_nvm_set_chs_to_nvm(frequency);

        }
    }
    return UDRV_RETURN_OK;
}

int32_t service_lora_get_chs(void)
{
    SERVICE_LORA_BAND band = service_lora_get_band();
    if ((band != SERVICE_LORA_AU915) && (band != SERVICE_LORA_US915) && (band != SERVICE_LORA_CN470) && (band != SERVICE_LORA_LA915))
    {
        return -UDRV_INTERNAL_ERR;
    }
    return service_nvm_get_chs_from_nvm();
}

int32_t service_lora_register_recv_cb(service_lora_recv_cb callback)
{
    service_lora_recv_callback = callback;
    return UDRV_RETURN_OK;
}

int32_t service_lora_register_join_cb(service_lora_join_cb callback)
{
    service_lora_join_callback = callback;
    return UDRV_RETURN_OK;
}

int32_t service_lora_register_send_cb(service_lora_send_cb callback)
{
    service_lora_send_callback = callback;
    return UDRV_RETURN_OK;
}

int32_t service_lora_register_linkcheck_cb(service_lora_linkcheck_cb callback)
{
    service_lora_linkcheck_callback = callback;
    return UDRV_RETURN_OK;
}

int32_t service_lora_register_timereq_cb(service_lora_timereq_cb callback)
{
    service_lora_timereq_callback = callback;
    return UDRV_RETURN_OK;
}

SERVICE_LORA_CLASS_B_STATE service_lora_get_class_b_state(void)
{
    return class_b_state;
}


int32_t service_lora_delay_send_process(void)
{
    SERVICE_LORA_SEND_INFO info;
    if(delay_send.flag)
    {
        delay_send.flag=0;
        info.confirm_valid = false;
        info.retry_valid = false;
        /*  If it is a viscous Mac, but the server has never sent the downlink data, and it will never send uplift.
        There will be a case that has been sending a space package. */
        /*
        MOTE_MAC_DL_CHANNEL_ANS
        MOTE_MAC_RX_PARAM_SETUP_ANS
        MOTE_MAC_RX_TIMING_SETUP_ANS
        MOTE_MAC_TX_PARAM_SETUP_ANS
        */
        service_lora_send(delay_send.buffer,delay_send.len,info,false);
    }
}


int32_t service_lora_query_txPossible(int16_t len)
{
    int16_t CurrentPossiblePayloadSize=0;
    LoRaMacStatus_t status;
    LoRaMacTxInfo_t txInfo;
    status = LoRaMacQueryTxPossible(len, &txInfo);
    LORA_TEST_DEBUG("service_lora_query_txPossible CurrentPossiblePayloadSize %d MaxPossibleApplicationDataSize %d",
    txInfo.CurrentPossiblePayloadSize,txInfo.MaxPossibleApplicationDataSize);
    return txInfo.MaxPossibleApplicationDataSize;
}

static void DisplayMacMcpsRequestUpdate( LoRaMacStatus_t status, McpsReq_t *mcpsReq, TimerTime_t nextTxIn )
{
    LORA_TEST_DEBUG("\r\n");
    switch( mcpsReq->Type )
    {
        case MCPS_CONFIRMED:
        {
            udrv_serial_log_printf( "\n###### =========== MCPS-Request ============ ######\n" );
            udrv_serial_log_printf( "######            MCPS_CONFIRMED             ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MCPS_UNCONFIRMED:
        {
            udrv_serial_log_printf( "\n###### =========== MCPS-Request ============ ######\n" );
            udrv_serial_log_printf( "######           MCPS_UNCONFIRMED            ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MCPS_PROPRIETARY:
        {
            udrv_serial_log_printf( "\n###### =========== MCPS-Request ============ ######\n" );
            udrv_serial_log_printf( "######           MCPS_PROPRIETARY            ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        default:
        {
            udrv_serial_log_printf( "\n###### =========== MCPS-Request ============ ######\n" );
            udrv_serial_log_printf( "######                MCPS_ERROR             ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
    }
    udrv_serial_log_printf( "STATUS      : %s\n", MacStatusStrings[status] );
    if( status == LORAMAC_STATUS_DUTYCYCLE_RESTRICTED )
    {
        udrv_serial_log_printf( "Next Tx in  : %lu [ms]\n", nextTxIn );
    }
}

static void DisplayMacMlmeRequestUpdate( LoRaMacStatus_t status, MlmeReq_t *mlmeReq, TimerTime_t nextTxIn )
{
    LORA_TEST_DEBUG("\r\n");
    switch( mlmeReq->Type )
    {
        case MLME_JOIN:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######               MLME_JOIN               ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MLME_LINK_CHECK:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######            MLME_LINK_CHECK            ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MLME_DEVICE_TIME:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######            MLME_DEVICE_TIME           ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MLME_TXCW:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######               MLME_TXCW               ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        case MLME_TXCW_1:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######               MLME_TXCW_1             ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
        default:
        {
            udrv_serial_log_printf( "\n###### =========== MLME-Request ============ ######\n" );
            udrv_serial_log_printf( "######              MLME_UNKNOWN             ######\n");
            udrv_serial_log_printf( "###### ===================================== ######\n");
            break;
        }
    }
    udrv_serial_log_printf( "STATUS      : %s\n", MacStatusStrings[status] );
    if( status == LORAMAC_STATUS_DUTYCYCLE_RESTRICTED )
    {
        udrv_serial_log_printf( "Next Tx in  : %lu [ms]\n", nextTxIn );
    }
}

static void OnMacMcpsRequest( LoRaMacStatus_t status, McpsReq_t *mcpsReq, TimerTime_t nextTxIn )
{
    LORA_TEST_DEBUG("\r\n");
    DisplayMacMcpsRequestUpdate( status, mcpsReq, nextTxIn );
}

static void OnMacMlmeRequest( LoRaMacStatus_t status, MlmeReq_t *mlmeReq, TimerTime_t nextTxIn )
{
    LORA_TEST_DEBUG("\r\n");
    DisplayMacMlmeRequestUpdate( status, mlmeReq, nextTxIn );
}

static void LmHandlerJoinRequest( bool isOtaa )
{
    LORA_TEST_DEBUG("isOtaa=%d\r\n", isOtaa);
    if( isOtaa == true )
    {
        //XXX
        service_lora_set_njm(SERVICE_LORA_OTAA, true);
        service_lora_join(1, -1, -1, -1);
    }
    else
    {
        //XXX
        service_lora_set_njm(SERVICE_LORA_OTAA, true);
        service_lora_join(1, -1, -1, -1);
    }
}

LmHandlerErrorStatus_t LmHandlerSend( LmHandlerAppData_t *appData, LmHandlerMsgTypes_t isTxConfirmed )
{
    int32_t ret;
    SERVICE_LORA_SEND_INFO info;
    LORA_TEST_DEBUG("port=%d\r\n", appData->Port);

    info.port = appData->Port;

    info.retry_valid = true;
    info.retry = service_lora_get_retry()+1;

    info.confirm_valid = true;
    if (isTxConfirmed == true) {
        info.confirm = SERVICE_LORA_ACK;
    } else if (isTxConfirmed == false) {
        info.confirm = SERVICE_LORA_NO_ACK;
    }

    if ((ret = service_lora_send(appData->Buffer, appData->BufferSize, info, false)) == UDRV_RETURN_OK)
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

LmHandlerErrorStatus_t LmHandlerPackageRegister( uint8_t id, void *params )
{
    LmhPackage_t *package = NULL;
    LORA_TEST_DEBUG("id=%u\r\n", id);
    switch( id )
    {
        case PACKAGE_ID_COMPLIANCE:
        {
            package = LmphCompliancePackageFactory( );
            break;
        }
#ifdef SUPPORT_FUOTA  
        case PACKAGE_ID_CLOCK_SYNC:
        {
            package = LmphClockSyncPackageFactory( );
            break;
        }
        case PACKAGE_ID_REMOTE_MCAST_SETUP:
        {
            package = LmhpRemoteMcastSetupPackageFactory( );
            break;
        }      
        case PACKAGE_ID_FRAGMENTATION:
        {
            package = LmhpFragmentationPackageFactory( );
            break;
        }
#endif //FUOTA       
    }
    if( package != NULL )
    {
        LmHandlerPackages[id] = package;
        LmHandlerPackages[id]->OnMacMcpsRequest = OnMacMcpsRequest;
        LmHandlerPackages[id]->OnMacMlmeRequest = OnMacMlmeRequest;
        LmHandlerPackages[id]->OnJoinRequest = LmHandlerJoinRequest;
        LmHandlerPackages[id]->OnSendRequest = LmHandlerSend;
        LmHandlerPackages[id]->OnDeviceTimeRequest = LmHandlerDeviceTimeReq;
        
        LmHandlerPackages[id]->Init( params, AppDataBuffer, LORAWAN_APP_DATA_BUFFER_MAX_SIZE );

        return LORAMAC_HANDLER_SUCCESS;
    }
    else
    {
        return LORAMAC_HANDLER_ERROR;
    }
}

bool LmHandlerPackageIsInitialized( uint8_t id )
{
    //LORA_TEST_DEBUG("id=%u\r\n", id);
    if( LmHandlerPackages[id]->IsInitialized != NULL )
    {
        return LmHandlerPackages[id]->IsInitialized( );
    }
    else
    {
        return false;
    }
}

bool LmHandlerPackageIsRunning( uint8_t id )
{
    LORA_TEST_DEBUG("id=%u\r\n", id);
    if( LmHandlerPackages[id]->IsRunning != NULL )
    {
        return LmHandlerPackages[id]->IsRunning( );
    }
    else
    {
        return false;
    }
}

static void LmHandlerPackagesNotify( PackageNotifyTypes_t notifyType, void *params )
{
    LORA_TEST_DEBUG("notifyType=%d\r\n", notifyType);
    for( int8_t i = 0; i < PKG_MAX_NUMBER; i++ )
    {
        if( LmHandlerPackages[i] != NULL )
        {
            switch( notifyType )
            {
                case PACKAGE_MCPS_CONFIRM:
                {
                    if( LmHandlerPackages[i]->OnMcpsConfirmProcess != NULL )
                    {
                        LmHandlerPackages[i]->OnMcpsConfirmProcess( ( McpsConfirm_t* ) params );
                    }
                    break;
                }
                case PACKAGE_MCPS_INDICATION:
                {
                    if ( LmHandlerPackages[i]->OnMcpsIndicationProcess != NULL ) 
  //                      ( LmHandlerPackages[i]->Port == ( ( McpsIndication_t* )params )->Port ) )
                    {
                        LmHandlerPackages[i]->OnMcpsIndicationProcess( ( McpsIndication_t* )params );
                    }
                    break;
                }
                case PACKAGE_MLME_CONFIRM:
                {
                    if( LmHandlerPackages[i]->OnMlmeConfirmProcess != NULL )
                    {
                        LmHandlerPackages[i]->OnMlmeConfirmProcess( ( MlmeConfirm_t* )params );
                    }
                    break;
                }
                case PACKAGE_MLME_INDICATION:
                {
                    if( LmHandlerPackages[i]->OnMlmeIndicationProcess != NULL )
                    {
                        LmHandlerPackages[i]->OnMlmeIndicationProcess( params );
                    }
                    break;
                }
            }
        }
    }
}

void LmHandlerPackagesProcess( void )
{
    //LORA_TEST_DEBUG("\r\n");
    for( int8_t i = 0; i < PKG_MAX_NUMBER; i++ )
    {
        if( ( LmHandlerPackages[i] != NULL ) &&
            ( LmHandlerPackages[i]->Process != NULL ) &&
            ( LmHandlerPackageIsInitialized( i ) != false ) )
        {
            LmHandlerPackages[i]->Process( );
        }
    }
}

LmHandlerErrorStatus_t LmHandlerDeviceTimeReq( void )
{
    LoRaMacStatus_t status;
    MlmeReq_t mlmeReq;

    mlmeReq.Type = MLME_DEVICE_TIME;

    status = LoRaMacMlmeRequest( &mlmeReq );
    LoRaMacMlmeRequest(&mlmeReq);
    
    if( status == LORAMAC_STATUS_OK )
    {
        return LORAMAC_HANDLER_SUCCESS;
    }
    else
    {   
        return LORAMAC_HANDLER_ERROR;
    }
}


 

static uint32_t IsSingleChannelAU915Callback()
{
    //LORA_TEST_DEBUG("IsSingleChannelAU915Callback");
    uint32_t frequency = service_lora_get_chs();
    return frequency;
}
static uint8_t AlternateDrAU915Callback()
{
    uint8_t CurrentDr=0;
    //LORA_TEST_DEBUG("AlternateDrAU915Callback");
    uint32_t step = 1600000,base = 915900000;
    uint32_t frequency = service_lora_get_chs();
    if(frequency)
    {
        for(uint8_t i=0;i < 8;i++)
        {
            if(frequency == base)
            {
                LORA_TEST_DEBUG();
                CurrentDr = DR_6;
            }
            base += step;
        }
    }
    return CurrentDr;
}
static uint32_t IsSingleChannelUS915Callback()
{
    //LORA_TEST_DEBUG("IsSingleChannelUS915Callback");
    uint32_t frequency = service_lora_get_chs();
    return frequency;
}
static uint8_t AlternateDrUS915Callback()
{
    uint8_t CurrentDr=0;
    //LORA_TEST_DEBUG("AlternateDrUS915Callback");
    uint32_t frequency = service_lora_get_chs();
    uint32_t step = 1600000,base = 903000000;
    if(frequency)
    {
        for(uint8_t i=0 ; i < 8 ; i++)
        {
            if(frequency == base)
            {
                CurrentDr = DR_4;
            }
            base += step;
        }
    }
    return CurrentDr;
}

void service_lora_systemMaxRxError()
{
    MibRequestConfirm_t mibReq;
 
    // Update the DEFAULT_SYSTEM_MAX_RX_ERROR
    mibReq.Type = MIB_SYSTEM_MAX_RX_ERROR;
    mibReq.Param.SystemMaxRxError = 25;
    if( LoRaMacMibSetRequestConfirm( &mibReq ) != LORAMAC_STATUS_OK )
    return;
}

int32_t service_lora_get_lbt()
{
    return service_nvm_get_lbt_from_nvm();
}

int32_t service_lora_set_lbt(uint8_t enable)
{
    return service_nvm_set_lbt_to_nvm(enable);
}

int16_t service_lora_get_lbt_rssi()
{
    return service_nvm_get_lbt_rssi_from_nvm();
}

int32_t service_lora_set_lbt_rssi(int16_t rssi)
{
    return service_nvm_set_lbt_rssi_to_nvm(rssi);
}

uint32_t service_lora_get_lbt_scantime()
{
    return service_nvm_get_lbt_scantime_from_nvm();
}

int32_t service_lora_set_lbt_scantime(uint32_t time)
{
    return service_nvm_set_lbt_scantime_to_nvm(time);
}

bool service_lora_region_isActive(SERVICE_LORA_BAND band)
{
    if( RegionIsActive( band ) == false )
    {
        if(band == SERVICE_LORA_AS923 || band == SERVICE_LORA_AS923_2 || band == SERVICE_LORA_AS923_3 || band == SERVICE_LORA_AS923_4)
        {
            if( RegionIsActive( SERVICE_LORA_AS923 ) == false )
                return false;
        }
        else
            return false;
    }
    return true;
}

#endif
#ifndef NO_LORA_SUPPORT
void service_lora_suspend(void) {
#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
    if(Radio.GetStatus() == RF_IDLE)
        Radio.Sleep();
#endif
}

void service_lora_resume(void) {
#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
    if(Radio.GetStatus() == RF_IDLE)
    {
//FIXME
#ifdef rak4630
    udrv_gpio_set_logic((uint32_t)42/*NSS*/, GPIO_LOGIC_LOW);
    udrv_gpio_set_logic((uint32_t)42/*NSS*/, GPIO_LOGIC_HIGH);
#endif
#ifdef rak11720
    udrv_gpio_set_logic((uint32_t)11/*NSS*/, GPIO_LOGIC_LOW);
    udrv_gpio_set_logic((uint32_t)11/*NSS*/, GPIO_LOGIC_HIGH);
#endif
    }
#endif
}
bool service_lora_isbusy(void){
#if defined(SUPPORT_LORA) || defined(SUPPORT_LORA_P2P)
    return (Radio.GetStatus( ) != RF_IDLE);
#else
    return false;
#endif
}   
#endif


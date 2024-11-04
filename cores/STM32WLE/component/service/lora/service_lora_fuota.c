#ifdef SUPPORT_FUOTA
#include <stddef.h>
#include <stdint.h>
#include "udrv_errno.h"
#include "udrv_serial.h"
#include "udrv_system.h"
#include "udrv_rtc.h"
#include "udrv_gpio.h"
#include "udrv_flash.h"
#include "board_basic.h"
#include "service_nvm.h"
#include "service_lora.h"
#include "LoRaMac.h"
#include "Region.h"
#include "LmhPackage.h"
#include "LmhpCompliance.h"
#include "service_lora_fuota.h"
#include "LmhpClockSync.h"
#include "LmhpRemoteMcastSetup.h"
#include "LmhpFragmentation.h"

static volatile bool IsClockSynched = false;
/*!
 * Defines the application data transmission duty cycle. 10s, value in [ms].
 */
#define APP_TX_DUTYCYCLE                            25000
/*!
 * Defines a random delay for application data transmission duty cycle. 5s,
 * value in [ms].
 */
#define APP_TX_DUTYCYCLE_RND                        5000





// #define LORAWAN_APP_DATA_BUFFER_MAX_SIZE            242
static uint8_t AppDataBuffer[242];
/*!
 * Indicates if a Tx frame is pending.
 *
 * \warning Set to 1 when OnTxTimerEvent raised
 */
volatile uint8_t IsTxFramePending = 0;
/*
 * MC Session Started
 */
volatile bool IsMcSessionStarted = false;
/*
 * Indicates if the file transfer is done
 */
static volatile bool IsFileTransferDone = false;

/*
 *  Received file computed CRC32
 */
static volatile uint32_t FileRxCrc = 0;

/*!
 * Timer to handle the application data transmission duty cycle
 */
TimerEvent_t TxTimer;            /* to open the timer to the RemoteMulticast*/


static void hexdump(uint8_t * data, size_t size, bool line)
{
    size_t i = 1;
	size_t j = 0;
  for( i = 1; i <= size; i++ )
	{
        udrv_serial_log_printf("%02x ", data[j]);
		if(!line )
		{
            if(i % 16 == 0)
			{   
				udrv_serial_log_printf("\r\n");
			}	
        }
		j++;
       
    }
	udrv_serial_log_printf("\r\n");
}


static uint32_t crc32(uint8_t *buffer, uint16_t length)
{
  // The CRC calculation follows CCITT - 0x04C11DB7
  const uint32_t reversedPolynom = 0xEDB88320;

  // CRC initial value
  uint32_t crc = 0xFFFFFFFF;

  if (buffer == NULL)
  {
    return 0;
  }

  for (uint16_t i = 0; i < length; ++i)
  {
    crc ^= (uint32_t)buffer[i];
    for (uint16_t i = 0; i < 8; i++)
    {
      crc = (crc >> 1) ^ (reversedPolynom & ~((crc & 0x01) - 1));
    }
  }

  return ~crc;
}

#ifdef SUPPORT_FUOTA  
LmhpFragmentationParams_t LmhpFragmentationParams =
{
  .DecoderCallbacks =
  {
        .FragDecoderWrite = udrv_flash_write,
        .FragDecoderRead = udrv_flash_read,
  },
  .OnProgress = OnFragProgress,           // should be OnUpdateAgentFragProgress to use Actility lib handling progress
  .OnDone = OnFragDone         // the only API hook with Actility lib right now
};
#endif   //FUOTA


//creat_start_timer
void creat_start_timer(TimerID_E timer_id, timer_handler tmr_handler,uint32_t count)
{
  udrv_timer_create (timer_id, tmr_handler,HTMR_PERIODIC);
	udrv_timer_start (timer_id, count, NULL);
}
 

/*!
 * Function executed on TxTimer event
 */
static void OnTxTimerEvent(void *context)
{
  udrv_timer_stop (TIMER_1);

  IsTxFramePending = 1;

  // Schedule next transmission
  creat_start_timer(TIMER_1,  OnTxTimerEvent,APP_TX_DUTYCYCLE);
}



void LoraStartTx(void)
{
  /* send every time timer elapses */
  OnTxTimerEvent(NULL);

}



void UplinkProcess( void )
{
  LmHandlerErrorStatus_t status = LORAMAC_HANDLER_ERROR;

  if (IsTxFramePending == 1)
  {
    // if (LmHandlerIsBusy() == true)
    // {
    //   udrv_serial_log_printf("Busy\r\n");
    //   return;
    // }

    if (IsMcSessionStarted == false)    /* we are in Class A*/
    {
      if (IsClockSynched == false)    /* we request AppTimeReq to allow FUOTA */
      {
        status = LmhpClockSyncAppTimeReq();
        //udrv_serial_log_printf("status:%d\r\n",status);
      }
      else
      {
        AppDataBuffer[0] = randr(0, 255);
        /* Send random packet */
        LmHandlerAppData_t appData =
        {
          .Buffer = AppDataBuffer,
          .BufferSize = 1,
          .Port = 1
        };
        status = LmHandlerSend(&appData, LORAMAC_HANDLER_UNCONFIRMED_MSG);
        udrv_serial_log_printf(" has send up data!\n\r"); // *olg*TMP
      }
    }
    else  /* Now we are in Class C or in Class B -- FUOTA feature could be activated */
    {
      if (IsFileTransferDone == false)
      {
        /* do nothing up to the transfer done or sent a data user */
      }
      else
      {
        AppDataBuffer[0] = 0x05; // FragDataBlockAuthReq
        AppDataBuffer[1] = FileRxCrc & 0x000000FF;
        AppDataBuffer[2] = (FileRxCrc >> 8) & 0x000000FF;
        AppDataBuffer[3] = (FileRxCrc >> 16) & 0x000000FF;
        AppDataBuffer[4] = (FileRxCrc >> 24) & 0x000000FF;

        /* Send FragAuthReq */
        LmHandlerAppData_t appData =
        {
          .Buffer = AppDataBuffer,
          .BufferSize = 5,
          .Port = 201
        };
        status = LmHandlerSend(&appData, LORAMAC_HANDLER_UNCONFIRMED_MSG);
      }
      IsFileTransferDone = false;
      if (status == LORAMAC_HANDLER_SUCCESS)
      {
        /* The fragmented transport layer V1.0 doesn't specify any behavior*/
        /* we keep the interop test behavior - CRC32 is returned to the server*/
        udrv_serial_log_printf(" CRC send \n\r");
      }
    }
    /* send application frame - could be put in conditional compilation*/
    /*  Send(NULL);  comment the sending to avoid interference during multicast*/
  }
    IsTxFramePending = 0;
}
  

void OnSysTimeUpdate(void)
{
    IsClockSynched = true;
}




void OnFragProgress(uint16_t fragCounter, uint16_t fragNb, uint8_t fragSize, uint16_t fragNbLost)
{
  udrv_serial_log_printf("\r\n....... FRAG_DECODER in Progress .......\r\n");
  udrv_serial_log_printf("RECEIVED    : %5d / %5d Fragments\r\n", fragCounter, fragNb);
  udrv_serial_log_printf("              %5d / %5d Bytes\r\n", fragCounter * fragSize, fragNb * fragSize);
  udrv_serial_log_printf("LOST        :       %7d Fragments\r\n\r\n", fragNbLost);
}


void OnFragDone(int32_t status, uint8_t *file, uint32_t size)
{
  IsFileTransferDone = true;
  uint8_t ch[150] = "";
  /* copy the file from RAM to FLASH & ASK to reboot the device*/

  if (udrv_flash_read(0x7d000,100,ch) == UDRV_RETURN_OK) {
    udrv_serial_log_printf("\r\n...... Transfer file RAM to Flash success --> Run  ......\r\n");
    hexdump(ch, 100,true);
    //FwUpdateAgentRun();
  } else {
    udrv_serial_log_printf("\r\n...... Transfer file RAM to Flash Failed  ......\r\n");
  }


  udrv_serial_log_printf("\r\n....... FRAG_DECODER Finished .......\r\n");
  udrv_serial_log_printf("STATUS      : %ld\r\n", status);
}
 
 #endif //FUOTA
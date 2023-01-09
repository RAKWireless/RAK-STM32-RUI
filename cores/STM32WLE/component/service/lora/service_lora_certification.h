#ifndef __SERVICE_LORA_CERFICATION_H__
#define __SERVICE_LORA_CERFICATION_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SUPPORT_LORA

#define LORAWAN_APP_DATA_MAX_SIZE                           242

#define LORAWAN_ADR_ON                              1

#define LORAWAN_DEFAULT_DATARATE                    DR_0

#define LORAWAN_APP_PORT                            2

#define LORAWAN_CONFIRMED_MSG_ON                    true

static uint8_t AppDataBuffer[LORAWAN_APP_DATA_MAX_SIZE];

static void CertifiTimerEvent( void* context );

uint32_t Certifi_Send(uint8_t port);

static bool SendFrame( void );

static uint8_t AppPort = LORAWAN_APP_PORT;

static uint8_t IsTxConfirmed = LORAWAN_CONFIRMED_MSG_ON;

int32_t service_lora_certification(int32_t mode);

int32_t service_lora_Certifi_Callback(McpsIndication_t *mcpsIndication);


#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif // __SERVICE_LORA_CERFICATION_H__

#ifndef __SERVICE_LORA_CERFICATION_H__
#define __SERVICE_LORA_CERFICATION_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SUPPORT_LORA

int32_t service_lora_certification(int32_t mode);

int32_t service_lora_Certifi_Callback(McpsIndication_t *mcpsIndication);


#ifdef __cplusplus
}
#endif

#endif // end SUPPORT_LORA

#endif // __SERVICE_LORA_CERFICATION_H__

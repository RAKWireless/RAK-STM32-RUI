#ifndef SERVICE_LORA_NVM_JOURNAL_H
#define SERVICE_LORA_NVM_JOURNAL_H

#include <stdint.h>
#include "service_nvm.h"

#if defined(STM32WLE5xx) && defined(SUPPORT_LORA) && defined(LORA_STACK_104)

int32_t service_lora_nvm_journal_init(void);
int32_t service_lora_nvm_journal_reset_abp(void);
uint16_t service_lora_nvm_journal_get_devnonce(void);
int32_t service_lora_nvm_journal_prepare_devnonce(uint16_t current_devnonce);
int32_t service_lora_nvm_journal_prepare_fcnt_up(LoRaMacNvmData_t *nvm);
int32_t service_lora_nvm_journal_store_abp(LoRaMacNvmData_t *nvm,
                                           uint16_t notify_flags);
void service_lora_nvm_journal_restore_abp(LoRaMacNvmData_t *nvm);

#endif

#endif

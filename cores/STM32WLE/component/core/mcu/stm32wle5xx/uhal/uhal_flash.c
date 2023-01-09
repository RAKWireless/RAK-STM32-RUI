#include "uhal_flash.h"
#include "uhal_powersave.h"

/**@brief   Sleep until an event is received. */
static void power_manage(void){
}


void uhal_flash_init (void) {
}

void uhal_flash_deinit (void) {
}

int32_t uhal_flash_write (uint32_t addr, uint8_t *buff, uint32_t len) {
    /* Unlock the Flash to enable the flash control register access *************/
    HAL_FLASH_Unlock();
  
    /* Clear all error flags */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_SR_ERRORS);

    uint32_t uhal_addr = addr;     
    uint8_t* data = buff;
    while(uhal_addr < addr + len) {
      if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, uhal_addr, *(uint64_t *)data) == HAL_OK) {
          uhal_addr += 8;
    	  data += 8;
      } else {
	  HAL_FLASH_Lock();
          return -UDRV_INTERNAL_ERR;
      }
    }

    HAL_FLASH_Lock();
    return UDRV_RETURN_OK;
}

int32_t uhal_flash_read (uint32_t addr, uint8_t *buff, uint32_t len) {
    memcpy(buff, (__IO uint8_t*)addr, len);
    return UDRV_RETURN_OK;
}

int32_t uhal_flash_erase (uint32_t addr, uint32_t len) {
    /* Unlock the Flash to enable the flash control register access *************/
    HAL_FLASH_Unlock();
  
    /* Clear all error flags */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_SR_ERRORS);

    uint32_t page_cnt = len / uhal_flash_get_page_size();
    uint32_t pageError = 0;

    static FLASH_EraseInitTypeDef EraseInitStruct;
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Page      = (addr - 0x08000000) / uhal_flash_get_page_size();
    EraseInitStruct.NbPages   = page_cnt; 

    if (HAL_FLASHEx_Erase(&EraseInitStruct, &pageError) != HAL_OK) {
      HAL_FLASH_Lock();
      return -UDRV_INTERNAL_ERR;
    }

    HAL_FLASH_Lock();
    return UDRV_RETURN_OK;
}

uint32_t uhal_flash_get_page_size(void) {
    return 2048;
}

bool uhal_flash_check_addr_valid(uint32_t addr, uint32_t len) {
    return 0;
}

void uhal_flash_suspend(void) {
}

void uhal_flash_resume(void) {
}

#include "uhal_system.h"

static uint8_t seed_data[SEED_LENGTH];

void uhal_sys_get_uid(uint32_t *uid0, uint32_t *uid1, uint32_t *uid2) {
    *uid0 = HAL_GetUIDw0();
    *uid1 = HAL_GetUIDw1();
    *uid2 = HAL_GetUIDw2();
}

static UTIL_TIMER_Object_t uhal_system_user_app_timer_id;

void uhal_sys_reboot(void) {
    NVIC_SystemReset();
}

#ifndef RUI_BOOTLOADER
void uhal_sys_board_critical_section_begin(uint32_t *mask)
{
    __disable_irq();
    *mask = __get_PRIMASK();
}

void uhal_sys_board_critical_section_end(uint32_t *mask)
{
    __set_PRIMASK(*mask);
    __enable_irq();
}

void uhal_sys_randomseed(unsigned long seed) {
    seed_data[0] = (uint8_t)((seed & 0XFF));
    seed_data[1] = (uint8_t)((seed >> 8) & 0xFF) ;
    seed_data[2] = (uint8_t)((seed >> 16) & 0xFF) ;
    seed_data[3] = (uint8_t)((seed >> 24) & 0XFF);
}

unsigned long uhal_sys_random (unsigned long maxvalue) {
    //FIXME
}

int32_t uhal_sys_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode) {
    if (UTIL_TIMER_Create((UTIL_TIMER_Object_t *)&uhal_system_user_app_timer_id, 0xFFFFFFFFU, get_stm_timer_mode(mode), tmr_handler, NULL) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_user_app_timer_start (uint32_t count, void *m_data) {
    if (UTIL_TIMER_SetPeriod((UTIL_TIMER_Object_t *)&uhal_system_user_app_timer_id, count) == UTIL_TIMER_OK)
    {
        if (UTIL_TIMER_Start((UTIL_TIMER_Object_t *)&uhal_system_user_app_timer_id) == UTIL_TIMER_OK)
        {
            return UDRV_RETURN_OK;
        }
        else
        {
            return -UDRV_INTERNAL_ERR;
        }
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}

int32_t uhal_sys_user_app_timer_stop (void) {
    if (UTIL_TIMER_Stop((UTIL_TIMER_Object_t *)&uhal_system_user_app_timer_id) == UTIL_TIMER_OK)
    {
        return UDRV_RETURN_OK;
    }
    else
    {
        return -UDRV_INTERNAL_ERR;
    }
}
#endif

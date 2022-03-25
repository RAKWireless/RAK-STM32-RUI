#include <stdbool.h>
#include "atcmd_queue.h"

ATCMD_SECTION_DEF(atcmd_queue, atcmd_permission_item);

static inline int queue_utilization_get()
{
    return ((uint32_t)&__stop_atcmd_queue - (uint32_t)&__start_atcmd_queue) / sizeof(atcmd_permission_item);
}

uint32_t atcmd_queue_pop(atcmd_permission_item * p_element,uint32_t offset)
{
    uint32_t status = ATCMD_QUEUE_SUCCESS;
    if (!atcmd_queue_is_empty())
    {
            atcmd_permission_item * items = (atcmd_permission_item *)&__start_atcmd_queue + offset;
            memcpy(p_element,items,sizeof(atcmd_permission_item));
    }
    else
        status = ATCMD_QUEUE_ERROR;
    return status;
}


int atcmd_queue_utilization_get()
{
    int utilization = queue_utilization_get();
    return utilization;
}

bool atcmd_queue_is_empty()
{
    return !(ATCMD_SECTION_LENGTH(atcmd_queue));
}

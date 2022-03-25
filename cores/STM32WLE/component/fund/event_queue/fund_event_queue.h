/**
 * @file        fund_event_queue.h
 * @brief       Provide an event queue mechanism for other components to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2022.1
 */

#ifndef _FUND_EVENT_QUEUE_H_
#define _FUND_EVENT_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef void (*fund_event_queue_handler_t)(void * p_event_data, uint16_t event_size);

typedef struct
{
    fund_event_queue_handler_t handler;          /**< Pointer to event handler to receive the event. */
    uint16_t                   event_data_size;  /**< Size of event data. */
} event_header_t;

#define FUND_EVENT_QUEUE_HEADER_SIZE sizeof(event_header_t)

#define FUND_EVENT_QUEUE_BUF_SIZE(EVENT_SIZE, QUEUE_SIZE)                                                 \
            (((EVENT_SIZE) + FUND_EVENT_QUEUE_HEADER_SIZE) * ((QUEUE_SIZE) + 1))

#define CEIL_DIV(A, B)      \
    (((A) + (B) - 1) / (B))

#define FUND_EVENT_QUEUE_INIT(EVENT_SIZE, QUEUE_SIZE)                                                     \
    do                                                                                             \
    {                                                                                              \
        static uint32_t FUND_EVENT_QUEUE_BUF[CEIL_DIV(FUND_EVENT_QUEUE_BUF_SIZE((EVENT_SIZE), (QUEUE_SIZE)),     \
                                               sizeof(uint32_t))];                                 \
        fund_event_queue_init((EVENT_SIZE), (QUEUE_SIZE), FUND_EVENT_QUEUE_BUF);             \
    } while (0)

int32_t fund_event_queue_init(uint16_t event_size, uint16_t queue_size, void * p_evt_buffer);

void fund_event_queue_execute(void);

uint32_t fund_event_queue_put(void const *              p_event_data,
                             uint16_t                  event_data_size,
                             fund_event_queue_handler_t handler);

uint16_t fund_event_queue_space_get(void);

#ifdef __cplusplus
}
#endif

#endif //_FUND_EVENT_QUEUE_H_

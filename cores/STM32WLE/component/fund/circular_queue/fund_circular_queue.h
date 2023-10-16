/**
 * @file        fund_circular_queue.h
 * @brief       Provide an circular queue (ring buffer) mechanism for other components to use.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2022.2
 */

#ifndef _FUND_CIRCULAR_QUEUE_H_
#define _FUND_CIRCULAR_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    void                     *p_buffer;
    size_t                   size;
    size_t                   element_size;
    volatile size_t          start;
    volatile size_t          end;
} fund_circular_queue_t;

#define FUND_CIRCULAR_QUEUE_INIT(_type, _name, _size)                 \
    static _type                       _name##_buffer[(_size) + 1];  \
    static fund_circular_queue_t       _name =                       \
    {                                                                \
            .p_buffer       = _name##_buffer,                        \
            .size           = (_size),                               \
            .element_size   = sizeof(_type),                         \
    };                                                               \

size_t fund_circular_queue_utilization_get(fund_circular_queue_t const *p_queue);
size_t fund_circular_queue_available_get(fund_circular_queue_t const *p_queue);
size_t fund_circular_queue_in(fund_circular_queue_t const *p_queue, void const *p_data, size_t element_count);
size_t fund_circular_queue_out(fund_circular_queue_t const *p_queue, void *p_data, size_t element_count);
void fund_circular_queue_reset(fund_circular_queue_t *p_queue);
bool fund_circular_queue_is_empty(fund_circular_queue_t const *p_queue);
bool fund_circular_queue_is_full(fund_circular_queue_t const *p_queue);
int32_t fund_circular_queue_peek(fund_circular_queue_t const *p_queue, void *p_element);

#ifdef __cplusplus
}
#endif

#endif //_FUND_EVENT_QUEUE_H_

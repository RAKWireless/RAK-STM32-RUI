#include "string.h"
#include "fund_circular_queue.h"
#include "udrv_errno.h"
#include "udrv_system.h"

#define MIN(x,y) (((x) < (y)) ? (x) : (y) )
#define MAX(x,y) (((x) > (y)) ? (x) : (y) )

size_t fund_circular_queue_utilization_get(fund_circular_queue_t const *p_queue)
{
    size_t start    = p_queue->start;
    size_t end      = p_queue->end;

    return (end >= start) ? (end - start) :
        (p_queue->size + 1 - start + end);
}

size_t fund_circular_queue_available_get(fund_circular_queue_t const *p_queue)
{
    return p_queue->size - fund_circular_queue_utilization_get(p_queue);
}

static inline size_t circular_queue_continuous_items_get(fund_circular_queue_t const *p_queue, bool write)
{
    size_t start    = p_queue->start;
    size_t end      = p_queue->end;

    if (write)
    {
        return (end >= start) ? p_queue->size + 1 - end : start - end;
    }
    else
    {
        return (end >= start) ? end - start : p_queue->size + 1 - start;
    }
}

static inline size_t circular_queue_next_idx(fund_circular_queue_t const *p_queue, size_t idx)
{
    return (idx < p_queue->size) ? (idx + 1) : 0;
}

static void circular_queue_write(fund_circular_queue_t *p_queue, void const *p_data, uint32_t element_count)
{
    size_t prev_available = fund_circular_queue_available_get(p_queue);
    size_t continuous     = circular_queue_continuous_items_get(p_queue, true);
    void * p_write_ptr    = (void *)((size_t)p_queue->p_buffer
                          + p_queue->end * p_queue->element_size);

    if (element_count <= continuous)
    {
        memcpy(p_write_ptr,
               p_data,
               element_count * p_queue->element_size);

        p_queue->end = ((p_queue->end + element_count) <= p_queue->size)
                            ? (p_queue->end + element_count)
                            : 0;
    }
    else
    {
        size_t first_write_length = continuous * p_queue->element_size;
        memcpy(p_write_ptr,
               p_data,
               first_write_length);

        size_t elements_left = element_count - continuous;
        memcpy(p_queue->p_buffer,
               (void const *)((size_t)p_data + first_write_length),
               elements_left * p_queue->element_size);

        p_queue->end = elements_left;
        if (prev_available < element_count)
        {
            p_queue->start = circular_queue_next_idx(p_queue, p_queue->end);
        }
    }
}

size_t fund_circular_queue_in(fund_circular_queue_t const *p_queue, void const *p_data, size_t element_count)
{
    uint32_t mask;
    size_t available;

    udrv_system_critical_section_begin(&mask);

    available = fund_circular_queue_available_get(p_queue);
    element_count = MIN(element_count, available);

    circular_queue_write(p_queue, p_data, element_count);

    udrv_system_critical_section_end(&mask);

    return element_count;
}

static void circular_queue_read(fund_circular_queue_t *p_queue, void *p_data, uint32_t element_count)
{
    size_t start        = p_queue->start;
    size_t continuous   = circular_queue_continuous_items_get(p_queue, false);
    void const * p_read_ptr = (void const *)((size_t)p_queue->p_buffer
                                           + start * p_queue->element_size);

    if (element_count <= continuous)
    {
        memcpy(p_data,
               p_read_ptr,
               element_count * p_queue->element_size);

        p_queue->start = ((start + element_count) <= p_queue->size)
                             ? (start + element_count)
                             : 0;
    }
    else
    {
        size_t first_read_length = continuous * p_queue->element_size;
        memcpy(p_data,
               p_read_ptr,
               first_read_length);

        size_t elements_left = element_count - continuous;
        memcpy((void *)((size_t)p_data + first_read_length),
               p_queue->p_buffer,
               elements_left * p_queue->element_size);

        p_queue->start = elements_left;
    }
}

size_t fund_circular_queue_out(fund_circular_queue_t const *p_queue, void *p_data, size_t element_count)
{
    uint32_t mask;
    size_t utilization;

    udrv_system_critical_section_begin(&mask);

    utilization = fund_circular_queue_utilization_get(p_queue);
    element_count = MIN(element_count, utilization);

    circular_queue_read(p_queue, p_data, element_count);

    udrv_system_critical_section_end(&mask);

    return element_count;
}

void fund_circular_queue_reset(fund_circular_queue_t const *p_queue)
{
    memset(p_queue, 0, sizeof(fund_circular_queue_t));
}

bool fund_circular_queue_is_empty(fund_circular_queue_t const *p_queue)
{
    size_t start    = p_queue->start;
    size_t end      = p_queue->end;
    return (start == end);
}

bool fund_circular_queue_is_full(fund_circular_queue_t const *p_queue)
{
    size_t start    = p_queue->start;
    size_t end      = p_queue->end;

    return (circular_queue_next_idx(p_queue, end) == start);
}

int32_t fund_circular_queue_peek(fund_circular_queue_t const *p_queue, void *p_element)
{
    int32_t ret = UDRV_RETURN_OK;

    if (!fund_circular_queue_is_empty(p_queue))
    {
        size_t read_pos = p_queue->start;
    
        switch (p_queue->element_size)
        {
            case sizeof(uint8_t):
                *((uint8_t *)p_element) = ((uint8_t *)p_queue->p_buffer)[read_pos];
                break;

            case sizeof(uint16_t):
                *((uint16_t *)p_element) = ((uint16_t *)p_queue->p_buffer)[read_pos];
                break;

            case sizeof(uint32_t):
                *((uint32_t *)p_element) = ((uint32_t *)p_queue->p_buffer)[read_pos];
                break;

            case sizeof(uint64_t):
                *((uint64_t *)p_element) = ((uint64_t *)p_queue->p_buffer)[read_pos];
                break;

            default:
                memcpy(p_element,
                       (void const *)((size_t)p_queue->p_buffer + read_pos * p_queue->element_size),
                       p_queue->element_size);
                break;
        }
    }
    else
    {
        ret = -UDRV_NOT_FOUND;
    }

    return ret;
}

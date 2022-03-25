#include "fund_event_queue.h"
#include "udrv_errno.h"

static event_header_t * m_queue_event_headers;  /**< Array for holding the queue event headers. */
static uint8_t        * m_queue_event_data;     /**< Array for holding the queue event data. */
static volatile uint8_t m_queue_start_index;    /**< Index of queue entry at the start of the queue. */
static volatile uint8_t m_queue_end_index;      /**< Index of queue entry at the end of the queue. */
static uint16_t         m_queue_event_size;     /**< Maximum event size in queue. */
static uint16_t         m_queue_size;           /**< Number of queue entries. */

static inline bool is_word_aligned(void const* p)
{
    return (((uintptr_t)p & 0x03) == 0);
}

static inline uint8_t next_index(uint8_t index)
{
    return (index < m_queue_size) ? (index + 1) : 0;
}

static inline uint8_t fund_event_queue_full()
{
  uint8_t tmp = m_queue_start_index;
  return next_index(m_queue_end_index) == tmp;
}

#define FUND_EVENT_QUEUE_FULL() fund_event_queue_full()

static inline uint8_t fund_event_queue_empty()
{
  uint8_t tmp = m_queue_start_index;
  return m_queue_end_index == tmp;
}

#define FUND_EVENT_QUEUE_EMPTY() fund_event_queue_empty()

int32_t fund_event_queue_init(uint16_t event_size, uint16_t queue_size, void * p_evt_buffer) {
    uint16_t data_start_index = (queue_size + 1) * sizeof(event_header_t);

    // Check that buffer is correctly aligned
    if (!is_word_aligned(p_evt_buffer))
    {
        return -UDRV_ADDR_NOT_ALIGNED;
    }

    // Initialize event scheduler
    m_queue_event_headers = p_evt_buffer;
    m_queue_event_data    = &((uint8_t *)p_evt_buffer)[data_start_index];
    m_queue_end_index     = 0;
    m_queue_start_index   = 0;
    m_queue_event_size    = event_size;
    m_queue_size          = queue_size;

    return UDRV_RETURN_OK;
}

void fund_event_queue_execute(void) {
    while (!FUND_EVENT_QUEUE_EMPTY())
    {
        uint16_t event_index = m_queue_start_index;

        void * p_event_data;
        uint16_t event_data_size;
        fund_event_queue_handler_t event_handler;

        p_event_data = &m_queue_event_data[event_index * m_queue_event_size];
        event_data_size = m_queue_event_headers[event_index].event_data_size;
        event_handler   = m_queue_event_headers[event_index].handler;

        event_handler(p_event_data, event_data_size);

        m_queue_start_index = next_index(m_queue_start_index);
    }
}

uint32_t fund_event_queue_put(void const *              p_event_data,
                             uint16_t                  event_data_size,
                             fund_event_queue_handler_t handler) {
    int32_t err_code;
    uint32_t mask;

    if (event_data_size <= m_queue_event_size)
    {
        uint16_t event_index = 0xFFFF;

        udrv_system_critical_section_begin(&mask);

        if (!FUND_EVENT_QUEUE_FULL())
        {
            event_index       = m_queue_end_index;
            m_queue_end_index = next_index(m_queue_end_index);
        }

        udrv_system_critical_section_end(&mask);

        if (event_index != 0xFFFF)
        {
            m_queue_event_headers[event_index].handler = handler;
            if ((p_event_data != NULL) && (event_data_size > 0))
            {
                memcpy(&m_queue_event_data[event_index * m_queue_event_size],
                       p_event_data,
                       event_data_size);
                m_queue_event_headers[event_index].event_data_size = event_data_size;
            }
            else
            {
                m_queue_event_headers[event_index].event_data_size = 0;
            }

            err_code = UDRV_RETURN_OK;
        }
        else
        {
            err_code = -UDRV_INTERNAL_ERR;
        }
    }
    else
    {
        err_code = -UDRV_BUFF_OVERFLOW;
    }

    return err_code;
}

uint16_t fund_event_queue_space_get(void) {
    uint16_t start = m_queue_start_index;
    uint16_t end   = m_queue_end_index;
    uint16_t free_space = m_queue_size - ((end >= start) ?
                           (end - start) : (m_queue_size + 1 - start + end));
    return free_space;
}

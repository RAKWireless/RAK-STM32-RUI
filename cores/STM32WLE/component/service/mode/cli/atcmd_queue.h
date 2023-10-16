#ifndef ATCMD_QUEUE_H__
#define ATCMD_QUEUE_H__

#include <stdint.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    char *  atcmd_id;
    size_t permission;
} atcmd_permission_item;

#define CONCAT_2(p1, p2)      CONCAT(p1, p2)
#define CONCAT(p1, p2)     p1##p2

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

#if defined(__CC_ARM)
#define ATCMD_ITEM(section_name, section_var) \
    section_var __attribute__ ((section(STRINGIFY(section_name)))) __attribute__((used))

#elif defined(__GNUC__)
#define ATCMD_ITEM(section_name, section_var) \
    section_var __attribute__ ((section("." STRINGIFY(section_name)))) __attribute__((used))

#elif defined(__ICCARM__)
#define ATCMD_ITEM(section_name, section_var) \
    __root section_var @ STRINGIFY(section_name)
#endif

#if defined(__CC_ARM)
#define ATCMD_SECTION_DEF(section_name, data_type)                \
    extern data_type * CONCAT_2(section_name, $$Base);          \
    extern data_type * CONCAT_2(section_name, $$Limit)
#define ATCMD_SECTION_LENGTH(section_name)                      \
    CONCAT_2(section_name, $$Limit) - CONCAT_2(section_name, $$Base)

#elif defined(__GNUC__)
#define ATCMD_SECTION_DEF(section_name, data_type)                \
    extern data_type * CONCAT_2(__start_, section_name);        \
    extern data_type * CONCAT_2(__stop_,  section_name)
#define ATCMD_SECTION_LENGTH(section_name)                      \
    CONCAT_2(__stop_,  section_name) - CONCAT_2(__start_, section_name)

#elif defined(__ICCARM__)
#define ATCMD_SECTION_DEF(section_name, data_type)                \
    _Pragma(STRINGIFY(section = STRINGIFY(section_name)));

#endif

#define ATCMD_QUEUE_SUCCESS  0
#define ATCMD_QUEUE_ERROR  1


#define UNIQUE_NAME(base) CONCAT_2(base,__COUNTER__)

uint32_t atcmd_queue_pop(atcmd_permission_item * p_element,uint32_t offset);

bool atcmd_queue_is_empty();

int atcmd_queue_utilization_get();


#ifdef __cplusplus
}
#endif

#endif // ATCMD_QUEUE_H__
/** @} */

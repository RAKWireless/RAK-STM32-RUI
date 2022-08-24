#ifndef __UHAL_SCHED_H__
#define __UHAL_SCHED_H__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "stm32_timer.h"
#include "stm32wle5xx.h"
#include "udrv_errno.h"

#define TASK_STACK_SIZE  1024
#define THREAD_POOL_SIZE 4

typedef void (*function) (void);

typedef struct tcb__ {
    char name[32];
    unsigned long int *sp;
    struct tcb__ *prev;
    struct tcb__ *next;
    bool valid;
    unsigned long int stack[TASK_STACK_SIZE];
} tcb_;

typedef struct sys_tcb__ {
    char name[32];
    unsigned long int *sp;
    struct tcb__ *prev;
    struct tcb__ *next;
    bool valid;
} sys_tcb_;

tcb_ *uhal_sched_get_tcb_by_name(char *name);
void uhal_sched_add_tcb_to_run_queue(tcb_ *tcb);
void uhal_sched_add_tcb_to_sleep_queue(tcb_ *tcb);
int32_t uhal_sched_create_thread(char *name, function task);
void uhal_sched_destroy_thread(tcb_ *tcb);
void uhal_sched_lock(void);
void uhal_sched_unlock(void);
bool uhal_sched_run_queue_empty(void);

#endif

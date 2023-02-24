#include "uhal_sched.h"

extern int _estack;

tcb_ thread_pool[THREAD_POOL_SIZE];
sys_tcb_ system_thread;
tcb_ *run_queue;
tcb_ *sleep_queue;
tcb_ *current_thread;
tcb_ *next_thread;

unsigned long int current_sp;
unsigned long int next_sp;
bool sched_start;
bool sched_pending;

/*
 * Enables all interrupts
 */
static void enable_interrupts() {
	// Enables all interrupts
	__asm("CPSIE I");
}

/*
 * Disables all interrupts
 */
static void disable_interrupts() {
	// Disables all interrupts
	__asm("CPSID I");
}

void uhal_sched_init() {
    disable_interrupts();
#if 0
	//  Set the Priority of the PendSV interrupt to minimum
	*(unsigned long int volatile *) 0xE000ED20 |= (0xFFU << 16);
#else
    __NVIC_SetPriority(PendSV_IRQn, 0xFF);
    //__NVIC_SetPriority(SVCall_IRQn, 0xFF);
#endif
    {
        unsigned long control;

        //__set_PSP((uint32_t)((tcb_ *)run_queue)->sp);

        control = __get_CONTROL();
        control &= ~CONTROL_FPCA_Msk;    // Clear FPCA since FPU state does not need to be preserved.
        //control |= CONTROL_FPCA_Msk;
        //control |= CONTROL_SPSEL_Msk;   // Use MSP only for excpetions, leaving PSP for tasks.
        __set_CONTROL(control);
    }
    enable_interrupts();
}

static tcb_ *get_free_tcb(void) {
    /* Search thread pool */
    for (int i = 0 ; i < THREAD_POOL_SIZE ; i++) {
        if (thread_pool[i].valid == false) {
            return &thread_pool[i];
        }
    }
    return NULL;
}

tcb_ *uhal_sched_get_tcb_by_name(char *name) {
    tcb_ *ptcb = NULL;

    /* Search run queue */
    ptcb = run_queue;
    while (ptcb != NULL) {
        if (!strcmp(ptcb->name, name)) {
            return ptcb;
        }
        ptcb = ptcb->next;
    }
    /* Search sleep queue */
    ptcb = sleep_queue;
    while (ptcb != NULL) {
        if (!strcmp(ptcb->name, name)) {
            return ptcb;
        }
        ptcb = ptcb->next;
    }

    return ptcb;
}

static void remove_from_queue(tcb_ *tcb) {
    if (tcb == NULL) {
        return;
    }
    disable_interrupts();

    if (tcb == run_queue) {
        run_queue = tcb->next;
    }

    if (tcb == sleep_queue) {
        sleep_queue = tcb->next;
    }

    /* Disconnect this TCB */
    if (tcb->prev) {
        tcb->prev->next = tcb->next;
    }
    if (tcb->next) {
        tcb->next->prev = tcb->prev;
    }
    tcb->prev = NULL;
    tcb->next = NULL;

    enable_interrupts();
}

void uhal_sched_add_tcb_to_run_queue(tcb_ *tcb) {
    if (tcb == NULL) {
        return;
    }
    remove_from_queue(tcb);

    disable_interrupts();
    /* Insert this TCB to the head of run queue */
    tcb->prev = NULL;
    tcb->next = run_queue;

    if (run_queue) {
        run_queue->prev = tcb;
    }
    run_queue = tcb;

    enable_interrupts();
}

void uhal_sched_add_tcb_to_sleep_queue(tcb_ *tcb) {
    if (tcb == NULL) {
        return;
    }
    remove_from_queue(tcb);

    disable_interrupts();
    /* Insert this TCB to the head of sleep queue */
    tcb->prev = NULL;
    tcb->next = sleep_queue;

    if (sleep_queue) {
        sleep_queue->prev = tcb;
    }
    sleep_queue = tcb;

    enable_interrupts();
}

/*
 * Creates a Thread for a function provided and adds it into execution queue
 */
int32_t uhal_sched_create_thread(char *name, function task) {
    unsigned long int *sp;
    tcb_ *tcb;

    tcb = get_free_tcb();  // Get the Next free TCB

    if (tcb == NULL) {
        return -UDRV_BUFF_OVERFLOW;
    }

    sp   = (unsigned long int *)((unsigned long int*)&(tcb->stack[TASK_STACK_SIZE]));

    *(--sp) = (1U << 24);  // Set thumb bit of XPSR
    *(--sp) = (unsigned long int)task;  // PC points to the task

    for (int i=0; i <= 13; i++) {
        *(--sp) = i;
    }

    *sp = 0xDEADBEEF;

    // Get the stack pointer for current task
    tcb->sp = sp;

    strncpy(tcb->name, name, 31);
    tcb->name[31] = '\0';

    tcb->prev = NULL;
    tcb->next = NULL;

    tcb->valid = true;

    uhal_sched_add_tcb_to_run_queue(tcb);

    return UDRV_RETURN_OK;
}

/*
 * Creates a System Thread for a function provided and adds it into execution queue
 */
void uhal_sched_create_sys_thread(char *name, function task) {
    unsigned long int *sp;
    sys_tcb_ *tcb = &system_thread;  // Get the Next free TCB

    sp   = (unsigned long int *)((uint32_t)&_estack - 0x1000);

    *(--sp) = (1U << 24);  // Set thumb bit of XPSR
    *(--sp) = (unsigned long int)task;  // PC points to the task

    for (int i=0; i <= 13; i++) {
        *(--sp) = i;
    }

    *sp = 0xDEADBEEF;

    // Get the stack pointer for current task
    tcb->sp = sp;

    strncpy(tcb->name, name, 31);
    tcb->name[31] = '\0';

    tcb->prev = NULL;
    tcb->next = NULL;

    tcb->valid = true;

    uhal_sched_add_tcb_to_run_queue((tcb_ *)tcb);
}

void uhal_sched_destroy_thread(tcb_ *tcb) {
    if (tcb == NULL) {
        return;
    }
    disable_interrupts();

    if (tcb == run_queue) {
        run_queue = tcb->next;
    }

    if (tcb == sleep_queue) {
        sleep_queue = tcb->next;
    }

    /* Disconnect this TCB */
    if (tcb->prev) {
        tcb->prev->next = tcb->next;
    }
    if (tcb->next) {
        tcb->next->prev = tcb->prev;
    }
    tcb->prev = NULL;
    tcb->next = NULL;

    tcb->valid = false;
    enable_interrupts();
}

void uhal_sched_lock(void) {
    sched_pending = true;
}

void uhal_sched_unlock(void) {
    sched_pending = false;
}

bool uhal_sched_run_queue_empty(void) {
    /* Search thread pool */
    for (int i = 0 ; i < THREAD_POOL_SIZE ; i++) {
        if (thread_pool[i].valid == true) {
            return false;
        }
    }
    return true;
}

#ifndef __RAK_THREAD_H__
#define __RAK_THREAD_H__

#define LABEL_INIT(s) s = NULL

#define LABEL_RESUME(s)				\
  do {						\
    if(s != NULL) {				\
      goto *s;					\
    }						\
  } while(0)

#define LABEL_CONCAT2(s1, s2) s1##s2
#define LABEL_CONCAT(s1, s2) LABEL_CONCAT2(s1, s2)

#define LABEL_SET(s)				\
  do {						\
    LABEL_CONCAT(LABEL_LABEL, __LINE__):   	        \
    (s) = &&LABEL_CONCAT(LABEL_LABEL, __LINE__);	\
  } while(0)

#define LABEL_END(s)

struct rt {
  void *label;
};

#define RT_WAITING 0
#define RT_YIELDED 1
#define RT_EXITED  2
#define RT_ENDED   3

/**@par		Description
 *              Initialize a RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_INIT(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_INIT(rt)   LABEL_INIT((rt)->label)

/**@par		Description
 *              Begin a RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_BEGIN(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_BEGIN(rt) { char RT_YIELD_FLAG = 1; LABEL_RESUME((rt)->label)

/**@par		Description
 *              End a RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_END(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_END(rt) LABEL_END((rt)->label); RT_YIELD_FLAG = 0; \
                   RT_INIT(rt); return RT_ENDED; }

/**@par		Description
 *              Yield CPU while the conditon is false.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_WAIT_UNTIL(rt, condition)
 *
 * @param	rt		the thread handle
 * @param	condition	wait condition
 *
 * @return      
 */
#define RT_WAIT_UNTIL(rt, condition)	        \
  do {						\
    LABEL_SET((rt)->label);				\
    if(!(condition)) {				\
      return RT_WAITING;			\
    }						\
  } while(0)

/**@par		Description
 *              Yield CPU while the conditon is true.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_WAIT_WHILE(rt, condition)
 *
 * @param	rt		the thread handle
 * @param	condition	wait condition
 *
 * @return      
 */
#define RT_WAIT_WHILE(rt, cond)  RT_WAIT_UNTIL((rt), !(cond))

/**@par		Description
 *              Yield CPU while a thread yields CPU.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_WAIT_THREAD(rt, thread)
 *
 * @param	rt		the thread handle
 * @param	thread		a RAK thread
 *
 * @return      
 */
#define RT_WAIT_THREAD(rt, thread) RT_WAIT_WHILE((rt), RT_SCHEDULE(thread))

/**@par		Description
 *              Spawn a new RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_SPAWN(rt, child, thread)
 *
 * @param	rt		the thread handle
 * @param	child		a RAK child thread
 * @param	thread		a RAK parent thread
 *
 * @return      
 */
#define RT_SPAWN(rt, child, thread)		\
  do {						\
    RT_INIT((child));				\
    RT_WAIT_THREAD((rt), (thread));		\
  } while(0)

/**@par		Description
 *              Restart a RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_RESTART(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_RESTART(rt)				\
  do {						\
    RT_INIT(rt);				\
    return RT_WAITING;			\
  } while(0)

/**@par		Description
 *              Exit a RAK thread.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_EXIT(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_EXIT(rt)				\
  do {						\
    RT_INIT(rt);				\
    return RT_EXITED;			\
  } while(0)

/**@par		Description
 *              Schedule a RAK thread to run.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_SCHEDULE(f)
 *
 * @param	f		a thread function
 *
 * @return      
 */
#define RT_SCHEDULE(f) ((f) < RT_EXITED)

/**@par		Description
 *              Yield CPU time.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_YIELD(rt)
 *
 * @param	rt		the thread handle
 *
 * @return      
 */
#define RT_YIELD(rt)				\
  do {						\
    RT_YIELD_FLAG = 0;				\
    LABEL_SET((rt)->label);				\
    if(RT_YIELD_FLAG == 0) {			\
      return RT_YIELDED;			\
    }						\
  } while(0)

/**@par		Description
 *              Yield CPU time until the condition is false.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_YIELD_UNTIL(rt, condition)
 *
 * @param	rt		the thread handle
 * @param	condition	wait condition
 *
 * @return      
 */
#define RT_YIELD_UNTIL(rt, cond)		\
  do {						\
    RT_YIELD_FLAG = 0;				\
    LABEL_SET((rt)->label);				\
    if((RT_YIELD_FLAG == 0) || !(cond)) {	\
      return RT_YIELDED;			\
    }						\
  } while(0)

/**@par		Description
 *              Yield CPU time for a period of time.
 *
 * @ingroup System_Misc
 * @par		Syntax
 *              RT_SLEEP(rt, delay)
 *
 * @param	rt		the thread handle
 * @param	delay		a period of time
 *
 * @return      
 */
#define RT_SLEEP(rt, delay) \
{ \
  do { \
    static unsigned long protothreads_sleep; \
    protothreads_sleep = millis(); \
    RT_WAIT_UNTIL(rt, millis() - protothreads_sleep > delay); \
  } while(false); \
}

/**@example	RAK_Thread/src/app.cpp
 */

#endif

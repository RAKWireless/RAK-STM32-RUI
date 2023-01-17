/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_sleep Sleep Command
 *
 * This section describes the commands related to sleep.
 *
 * @subsection ATCMD_sleep_1 AT+SLEEP: sleep mode
 *
 * This command provides a way to enter sleep mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SLEEP?          | --                 | AT+SLEEP: enter sleep mode for a period of time (ms)              | OK                 |
 * | AT+SLEEP=\<integer\>   | <integer>      |                                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SLEEP= | 1000             | --                                                                | OK                 |
 * 
 *
 */

#ifndef _ATCMD_SLEEP_DEF_H_
#define _ATCMD_SLEEP_DEF_H_

#define ATCMD_SLEEP                 "AT+SLEEP"
#define ATCMD_AUTOSLEEP             "AT+AUTOSLEEP"

#endif //_ATCMD_SLEEP_DEF_H_

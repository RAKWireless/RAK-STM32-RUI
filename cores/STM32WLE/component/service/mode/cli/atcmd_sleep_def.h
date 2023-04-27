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
 * | AT+SLEEP=\<positive integer\>   | <positive integer>      |                                                 | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SLEEP= | 1000             | --                                                                | OK                 |
 * 
 * @subsection ATCMD_sleep_2 AT+LPM: low power mode
 *
 * This command provides a way to enable/disable low power mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LPM?            | --                 | AT+LPM: get or set the low power mode<br>0 = off<br>1 = on        | OK                 |
 * | AT+LPM=\<Input\>   | 0 or 1             |                                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+LPM= | 1                  | --                                                                | OK                 |
 *
 */

#ifndef _ATCMD_SLEEP_DEF_H_
#define _ATCMD_SLEEP_DEF_H_

#define ATCMD_SLEEP                 "AT+SLEEP"
#define ATCMD_AUTOSLEEP             "AT+LPM"

#endif //_ATCMD_SLEEP_DEF_H_

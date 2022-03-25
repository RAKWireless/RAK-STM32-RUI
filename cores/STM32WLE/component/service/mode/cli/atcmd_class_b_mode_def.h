/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_class_b_mode LoRaWAN Class B
 * 
 * This section provides a set of commands for Class B mode management
 *
 * @subsection ATCMD_class_b_mode_1 AT+PGSLOT
 *
 * This command allows the user to set or to get the unicast ping slot periodicity.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PGSLOT?            | --                 | AT+PGSLOT: get or set the unicast ping slot periodicity (0-7)  | OK                 |
 * | AT+PGSLOT=?           | --                 | 0, 1, 2, 3, 4, 5, 6 or 7                                       | OK                 |
 * | AT+PGSLOT=\<Input\>   | 0, 1, 2, 3, 4, 5, 6 or 7             | --                                           | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PGSLOT= | 1                  | --                                                             | OK                 |
 * | Example<br>AT+PGSLOT=?| --                 | 2                                                              | OK                 |
 *
 * @subsection ATCMD_class_b_mode_2 AT+BFREQ
 *
 * This command allows the user to access the current beacon (default broadcast) frequency.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BFREQ?          | --                 | AT+BFREQ: get the data rate and beacon frequency (MHz)            | OK                 |
 * | AT+BFREQ=?         | --                 | BCON: <0,1,2,3,4,5,6 or 7>, <float>                               | OK                 |
 * | Example<br>AT+BFREQ=?| --               | BCON: 3, 869.525                                                  | OK                 |
 *
 * @subsection ATCMD_class_b_mode_3 AT+BTIME
 *
 * This command allows the user to access the current beacon time.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BTIME?          | --                 | AT+BTIME: get the beacon time (seconds since GPS Epoch time)      | OK                 |
 * | AT+BTIME=?         | --                 | BTIME: <integer>                                                  | OK                 |
 * | Example<br>AT+BTIME=?| --               | BTIME: 1226592311                                                 | OK                 |
 *
 * @subsection ATCMD_class_b_mode_4 AT+BGW
 *
 * This command allows the user to access the gateway GPS coordinate, NetID and GwID.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BGW?            | --                 | AT+BGW: get the gateway GPS coordinate, NetID and GwID            | OK                 |
 * | AT+BGW=?           | --                 | BGW: <INFO>, <netid>, <gwid>, <longitude>, <latitude>             | OK                 |
 *
 * @subsection ATCMD_class_b_mode_5 AT+LTIME
 *
 * This command allows the user to access the local time in UTC format.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LTIME?          | --                 | AT+LTIME: get the local time                                      | OK                 |
 * | AT+LTIME=?         | --                 | LTIME: <HOUR>h<MINUTE>m<SECOND>s <YEAR>-<MONTH>-<DAY>             | OK                 |
 * | Example<br>AT+LTIME=?         | --      | LTIME: 00h37m58s 2018-11-14                                       | OK                 |
 *
 *
 */

#ifndef _ATCMD_CLASS_B_MODE_DEF_H_
#define _ATCMD_CLASS_B_MODE_DEF_H_

//### following AT CMD, has doc ###
#define ATCMD_PGSLOT             "AT+PGSLOT"
#define ATCMD_BFREQ              "AT+BFREQ"
#define ATCMD_BTIME              "AT+BTIME"
#define ATCMD_BGW                "AT+BGW"
#define ATCMD_LTIME              "AT+LTIME"

#endif //_ATCMD_CLASS_B_MODE_DEF_H_

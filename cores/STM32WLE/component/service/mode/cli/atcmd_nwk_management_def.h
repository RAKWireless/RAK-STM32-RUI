#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_nwk_mng LoRaWAN Network Management
 * 
 * This section provides a set of commands for network management.
 *
 * @subsection ATCMD_nwk_mng_1 AT+ADR: adaptive rate
 *
 * This command allows the user to access the adaptive data rate.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ADR?            | --                 | AT+ADR: get or set the adaptive data rate setting<br>0 = off<br>1 = on                         | OK                 |
 * | AT+ADR=?           | --                 | 0 or 1                                                            | OK                 |
 * | AT+ADR=\<Input\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+ADR= | 0                  | --                                                                | OK                 |
 * | Example<br>AT+ADR=?| --                 | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_nwk_mng_2 AT+CLASS: LoRa class
 *
 * This command allows the user to access the LoRaWAN class.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CLASS?          | --                 | AT+CLASS: get or set the device class (A = class A, B = class B, C = class C)                             | OK                 |
 * | AT+CLASS=?         | --                 | A, B or C                                                         | OK                 |
 * | AT+CLASS=\<Input\> | A, B or C          | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+CLASS=?| --               | A                                                                 | OK                 |
 *
 * @subsection ATCMD_nwk_mng_3 AT+DCS: duty cycle settings
 *
 * This command allows the user to access the duty cycle parameter.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+DCS?            | --                 | AT+DCS: get the ETSI duty cycle setting:<br>0 = disabled<br>1 = enabled                             | OK                 |
 * | AT+DCS=?           | --                 | 0 or 1                                                            | OK                 |
 * | AT+DCS=\<Input\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+DCS=?| --                 | 1                                                                 | OK                 |
 * | Example<br>AT+DCS= | 1                  | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_4 AT+DR: data rate
 *
 * This command allows the user to access the data rate.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+DR?             | --                 | AT+DR: get or set the data rate                                   | OK                 |
 * | AT+DR=?            | --                 | 0, 1, 2, 3, 4, 5, 6 or 7                                          | OK                 |
 * | AT+DR=\<Input\>    | 0, 1, 2, 3, 4, 5, 6 or 7             | --                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+DR=? | --                 | 3                                                                 | OK                 |
 * | Example<br>AT+DR=  | 2                  | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_5 AT+JN1DL: join delay on RX window 1
 *
 * This command allows the user to access the join delay on RX window 1.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+JN1DL?          | --                 | AT+JN1DL: get or set the join accept delay between the end of TX and the join Rx window 1 in seconds       | OK                 |
 * | AT+JN1DL=?         | --                 | <integer>                                                         | OK / AT_BUSY_ERROR                 |
 * | AT+JN1DL=\<Input\>    | <integer>       | --                                                                | OK / AT_PARAM_ERROR / AT_BUSY_ERROR |
 * | Example<br>AT+JN1DL=? | --              | 5                                                                 | OK                 |
 * | Example<br>AT+JN1DL=  | 10              | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_6 AT+JN2DL: join delay on RX window 2
 *
 * This command allows the user to access the join delay on RX window 2.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+JN2DL?          | --                 | AT+JN2DL: get the join accept delay between the end of TX and the join Rx window 2 in seconds       | OK                 |
 * | AT+JN2DL=?         | --                 | <integer>                                                         | OK / AT_BUSY_ERROR                 |
 * | Example<br>AT+JN2DL=? | --              | 6                                                                 | OK                 |
 *
 * @subsection ATCMD_nwk_mng_7 AT+PNM: public network mode
 *
 * This command allows the user to access the public network mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PNM?            | --                 | AT+PNM: get or set the public network mode (0 = off, 1 = on)      | OK                 |
 * | AT+PNM=?           | --                 | 0 or 1                                                            | OK                 |
 * | AT+PNM=\<Input\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PNM=?| --                 | 0                                                                 | OK                 |
 * | Example<br>AT+PNM= | 1                  | --                                                                | OK                 |
 * | Example<br>AT+PNM= | 2                  | --                                                                | AT_PARAM_ERROR     |
 *
 * @subsection ATCMD_nwk_mng_8 AT+RX1DL: delay of the received window 1
 *
 * This command allows the user to access the delay of the received window 1.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RX1DL?          | --                 | AT+RX1DL: get or set the delay between the end of TX and the RX window 1 in seconds (1-15)       | OK                 |
 * | AT+RX1DL=?         | --                 | <integer>                                                         | OK / AT_BUSY_ERROR                 |
 * | AT+RX1DL=\<Input\>    | <integer>       | --                                                                | OK / AT_PARAM_ERROR / AT_BUSY_ERROR |
 * | Example<br>AT+RX1DL=? | --              | 1                                                                 | OK                 |
 * | Example<br>AT+RX1DL=  | 1               | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_9 AT+RX2DL: delay of the received window 2
 *
 * This command allows the user to access the delay of the received window 2.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RX2DL?          | --                 | AT+RX2DL: get or set the delay between the end of TX and the RX window 2 in seconds (2-16)       | OK                 |
 * | AT+RX2DL=?         | --                 | <integer>                                                         | OK / AT_BUSY_ERROR                 |
 * | Example<br>AT+RX2DL=? | --              | 2                                                                 | OK                 |
 *
 * @subsection ATCMD_nwk_mng_10 AT+RX2DR: data rate of the received window 2
 *
 * This command allows the user to access the data rate of received window 2.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RX2DR?          | --                 | AT+RX2DR: get or set the RX2 window data rate                     | OK                 |
 * | AT+RX2DR=?         | --                 | 0, 1, 2, 3, 4, 5, 6 or 7                                          | OK / AT_BUSY_ERROR                 |
 * | AT+RX2DR=\<Input\>    | 0, 1, 2, 3, 4, 5, 6 or 7       | --                                                 | OK / AT_PARAM_ERROR / AT_BUSY_ERROR |
 * | Example<br>AT+RX2DR=? | --              | 6                                                                 | OK                 |
 * | Example<br>AT+RX2DR=  | 5               | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_11 AT+RX2FQ: frequency of the received window 2
 *
 * This command allows the user to access the frequency of the received window 2.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RX2FQ?          | --                 | AT+RX2FQ: get or set the RX2 window frequency (Hz)                | OK                 |
 * | AT+RX2FQ=?         | --                 | <integer>                                                         | OK / AT_BUSY_ERROR                 |
 * | AT+RX2FQ=\<Input\>    | <integer>       | --                                                                | OK / AT_PARAM_ERROR / AT_BUSY_ERROR |
 * | Example<br>AT+RX2FQ=? | --              | 869535000                                                         | OK                 |
 * | Example<br>AT+RX2FQ=  | 869535000       | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_12 AT+TXP: transmit power
 *
 * This command allows the user to access the transmit power
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TXP?            | --                 | AT+TXP: get or set the transmitting power                         | OK                 |
 * | AT+TXP=?           | --                 | <integer>                                                         | OK                 |
 * | AT+TXP=\<Input\>   | <integer>          | --                                                                | OK / AT_PARAM_ERROR |
 * | Example<br>AT+TXP=?| --                 | 1                                                                 | OK                 |
 * | Example<br>AT+TXP= | 4                  | --                                                                | OK                 |
 *
 * @subsection ATCMD_nwk_mng_13 AT+LINKCHECK: link check
 *
 * This command allows the user to send the link check command
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+LINKCHECK?            | --                 | AT+LINKCHECK: get or set the link check setting (0 = disabled, 1 = once, 2 = everytime)                       | OK                 |
 * | AT+LINKCHECK=?     | --                 | <0-2>                                                             | OK                 |
 * | AT+LINKCHECK=\<Input\>   | <0-2>        | --                                                                | OK / AT_PARAM_ERROR |
 * | Example<br>AT+LINKCHECK=?| --                 | 1                                                           | OK                 |
 * | Example<br>AT+LINKCHECK= | 2                  | --                                                          | OK                 |
 *
 * @subsection ATCMD_nwk_mng_14 AT+TIMEREQ: time request
 *
 * This command allows the user to request the current date and time
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TIMEREQ?            | --                 | AT+TIMEREQ: request the current date and time (0 = disabled, 1 = enabled)                       | OK                 |
 * | AT+TIMEREQ=?     | --                 | <0-1>                                                             | OK                 |
 * | AT+TIMEREQ=\<Input\>   | <0-1>        | --                                                                | OK / AT_PARAM_ERROR |
 * | Example<br>AT+TIMEREQ=?| --                 | 1                                                           | OK                 |
 * | Example<br>AT+TIMEREQ= | 1                  | --                                                          | OK                 |
 *
 */
#endif 

#ifndef _ATCMD_NWK_MNG_DEF_H_
#define _ATCMD_NWK_MNG_DEF_H_

//### following AT CMD, has doc ###
#define ATCMD_ADR             "AT+ADR"
#define ATCMD_CLASS           "AT+CLASS"
#define ATCMD_DCS             "AT+DCS"
#define ATCMD_DR              "AT+DR"
#define ATCMD_JN1DL           "AT+JN1DL"
#define ATCMD_JN2DL           "AT+JN2DL"
#define ATCMD_PNM             "AT+PNM"
#define ATCMD_RX1DL           "AT+RX1DL"
#define ATCMD_RX2DL           "AT+RX2DL"
#define ATCMD_RX2DR           "AT+RX2DR"
#define ATCMD_RX2FQ           "AT+RX2FQ"
#define ATCMD_TXP             "AT+TXP"
#define ATCMD_LINKCHECK       "AT+LINKCHECK"
#define ATCMD_TIMEREQ         "AT+TIMEREQ"

#endif //_ATCMD_NWK_MNG_DEF_H_

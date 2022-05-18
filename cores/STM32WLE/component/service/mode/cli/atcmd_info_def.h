#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_info LoRaWAN Information
 * 
 * This section provides a set of commands for battery level, RF signal quality and FW version.
 *
 * @subsection ATCMD_info_1 AT+RSSI: RSSI on reception
 *
 * This command allows the user to access the RSSI on reception.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RSSI?           | --                 | AT+RSSI: get the RSSI of the last received packet                 | OK                 |
 * | AT+RSSI=?          | --                 | <interger>                                                        | OK                 |
 * | Example<br>AT+RSSI=?| --                | -31                                                               | OK                 |
 *
 * @subsection ATCMD_info_2 AT+ARSSI: access all open channel rssi
 *
 * This command access all open channel rssi
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ARSSI?          | --                 | AT+ARSSI: access all open channel RSSI                            | OK                 |
 * | AT+ARSSI=?         | --                 |                                                                   | OK                 |
 * | Example<br>AT+ARSSI=?|                  | 0,-16 1,-18 2,-30                                                 | OK                 |
 *
 * @subsection ATCMD_info_3 AT+SNR: signal noise ratio
 *
 * This command allows the user to access the SNR of the last received packet.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SNR?            | --                 | AT+SNR: get the SNR of the last received packet                   | OK                 |
 * | AT+SNR=?           | --                 | <interger>                                                        | OK                 |
 * | Example<br>AT+SNR=?| --                 | 32                                                                | OK                 |
 *
 */
#endif

#ifndef _ATCMD_INFO_DEF_H_
#define _ATCMD_INFO_DEF_H_

//### following AT CMD, has doc ###
#define ATCMD_RSSI            "AT+RSSI"
#define ATCMD_ARSSI           "AT+ARSSI"
#define ATCMD_SNR             "AT+SNR"

#endif //_ATCMD_INFO_DEF_H_

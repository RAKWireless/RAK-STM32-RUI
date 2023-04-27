#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_key_id LoRaWAN Keys and IDs
 *
 * This section describes the commands related to the activation of the end device. EUIs and Keys are MSB first.
 * 
 * @subsection ATCMD_key_id_1 AT+APPEUI: application identifier
 *
 * This command allows the user to access the global application identifier.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APPEUI?         | --                 | AT+APPEUI: get or set the application EUI (8 bytes in hex)        | OK                 |
 * | AT+APPEUI=?        | --                 | \<8 hex\>                                                         | OK                 |
 * | AT+APPEUI=\<Param\>| \<8 hex\>          | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+APPEUI= | 0102030405060708   | --                                                             | OK                 |
 * | Example<br>AT+APPEUI= | 010203040506070809 | --                                                             | AT_PARAM_ERROR     |
 * | Example<br>AT+APPEUI=?|                    | 0102030405060708                                               | OK                 |
 *
 * @subsection ATCMD_key_id_2 AT+APPKEY: application key
 *
 * This command allows the user to access the application key.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APPKEY?         | --                 | AT+APPKEY: get or set the application key (16 bytes in hex)       | OK                 |
 * | AT+APPKEY=?        | --                 | \<16 hex\>                                                        | OK                 |
 * | AT+APPKEY=\<Param\>| \<16 hex\>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+APPKEY= | 0102030405060708090A0B0C0D0E0F00   | --                                             | OK                 |
 * | Example<br>AT+APPKEY= | 010203040506070809 | --                                                             | AT_PARAM_ERROR     |
 * | Example<br>AT+APPKEY=?|                    | 0102030405060708090A0B0C0D0E0F00                               | OK                 |
 *
 * @subsection ATCMD_key_id_3 AT+APPSKEY: application session key
 *
 * This command allows the user to access the application session key.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+APPSKEY?         | --                 | AT+APPSKEY: get or set the application session key (16 bytes in hex)              | OK                 |
 * | AT+APPSKEY=?        | --                 | \<16 hex\>                                                       | OK                 |
 * | AT+APPSKEY=\<Param\>| \<16 hex\>         | --                                                               | OK / AT_PARAM_ERROR|
 * | Example<br>AT+APPSKEY= | 0102030405060708090A0B0C0D0E0F00   | --                                            | OK                 |
 * | Example<br>AT+APPSKEY= | 010203040506070809 | --                                                            | AT_PARAM_ERROR     |
 * | Example<br>AT+APPSKEY=?|                    | 0102030405060708090A0B0C0D0E0F00                              | OK                 |
 *
 * @subsection ATCMD_key_id_4 AT+DEVADDR: device address
 *
 * This command allows the user to access the device address.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+DEVADDR?        | --                 | AT+DEVADDR: get or set the device address (4 bytes in hex)        | OK                 |
 * | AT+DEVADDR=?       | --                 | \<4 hex\>                                                         | OK                 |
 * | AT+DEVADDR=\<Param\> | \<4 hex\>        | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+DEVADDR= | 01020304       | --                                                                | OK                 |
 * | Example<br>AT+DEVADDR= | 0102030405     | --                                                                | AT_PARAM_ERROR     |
 * | Example<br>AT+DEVADDR=?|                | 01020304                                                          | OK                 |
 *
 * @subsection ATCMD_key_id_5 AT+DEVEUI: device EUI
 *
 * This command allows the user to access the global end-device ID.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+DEVEUI?         | --                 | AT+DEVEUI: get or set the device EUI (8 bytes in hex)             | OK                 |
 * | AT+DEVEUI=?        | --                 | \<8 hex\>                                                         | OK                 |
 * | AT+DEVEUI=\<Param\>| \<8 hex\>          | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+DEVEUI= | 0102030405060708   | --                                                             | OK                 |
 * | Example<br>AT+DEVEUI= | 010203040506070809 | --                                                             | AT_PARAM_ERROR     |
 * | Example<br>AT+DEVEUI=?|                 | 0102030405060708                                                  | OK                 |
 *
 * @subsection ATCMD_key_id_6 AT+NETID: network identifier (NetID)
 *
 * This command allows the user to access the network identifier (NetID) of 3 octets.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+NETID?          | --                 | AT+NETID: get the network identifier (NetID) (3 bytes in hex)     | OK                 |
 * | AT+NETID=?         | --                 | \<3 hex\>                                                         | OK                 |
 * | AT+NETID=\<Param\> | \<3 hex\>          | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+NETID=?|                  | 010203                                                            | OK                 |
 *
 * @subsection ATCMD_key_id_7 AT+NWKSKEY: network session key
 *
 * This command allows the user to access the network session key.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+NWKSKEY?          | --                 | AT+NWKSKEY: get or set the network session key (16 bytes in hex)                  | OK                 |
 * | AT+NWKSKEY=?         | --                 | \<16 hex\>                                                      | OK                 |
 * | AT+NWKSKEY=\<Param\> | \<16 hex\>         | --                                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+NWKSKEY= | 0102030405060708090A0B0C0D0E0F00         | --                                      | OK                 |
 * | Example<br>AT+NWKSKEY= | 010203040506070809       | --                                                      | AT_PARAM_ERROR     |
 * | Example<br>AT+NWKSKEY=?|                  | 0102030405060708090A0B0C0D0E0F00                                | OK                 |
 *
*/
#endif

#ifndef _ATCMD_KEY_ID_DEF_H_
#define _ATCMD_KEY_ID_DEF_H_

#define ATCMD_APPEUI           "AT+APPEUI"
#define ATCMD_APPKEY           "AT+APPKEY"
#define ATCMD_APPSKEY          "AT+APPSKEY"
#define ATCMD_DADDR            "AT+DEVADDR"
#define ATCMD_DEUI             "AT+DEVEUI"
#define ATCMD_NETID            "AT+NETID"
#define ATCMD_NWKSKEY          "AT+NWKSKEY"

#endif //_ATCMD_KEY_ID_DEF_H_

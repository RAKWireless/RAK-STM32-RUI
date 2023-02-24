#ifdef RAK5010_EVB
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_cellular Cellular Command
 *
 * This section describes the commands related to Cellular.
 *
 * @subsection ATCMD_cellular_1 AT+CELL: Send cellular commnad
 *
 * This command provides a way to send command or message to cellular module
 * | Command                                                                                    |Corresponding Cellular Command |Input parameter    | Return value                                                      | Return code         |
 * |:------------------------------------------------------------------------------------------:|:-----------------------------:|:-----------------:|:------------------------------------------------------------------|:-------------------:|
 * | <B>ATCELL?</B>                                                                             |--                             |--                 | <B>ATCELL: Send a command to LTE module</B>                              | <B>OK</B>                  |
 * | <B>ATCELL+<CELL_CMD>=?</B>                                                                 |<B><CELL_CMD></B>              |--                 | <B><Help Message for This Cellular Command></B>                          | <B>OK</B>                  |
 * | <B>ATCELL+<CELL_CMD>?</B>                                                                  |<B><CELL_CMD></B>              |--                 | <B><Cellular response></B>                                               | <B>Cellular return code</B>|
 * | <B>ATCELL+<CELL_CMD></B>                                                                   |<B><CELL_CMD></B>              |--                 | <B><Cellular response></B>                                               | <B>Cellular return code</B>|
 * | <B>ATCELL+<CELL_CMD>=<input></B>                                                           |<B><CELL_CMD></B>              |<B><input></B>     | <B><Cellular response></B>                                               | <B>Cellular return code</B>|
 * | Example<br>ATCELL+QCFG=\"band\",0,8000000,8000000,1                                        |AT+QCFG                        |Refer to 4.2.5 of BG96_AT_Commands_Manual_V2.1.                                                            |||
 * | Example<br>ATCELL+QCFG=\"nwscanseq\",030201,1                                              |AT+QCFG                        |Refer to 4.2.1 of BG96_AT_Commands_Manual_V2.1.                                                            |||
 * | Example<br>ATCELL+CGREG=1                                                                  |AT+CGREG                       |Refer to 9.8 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+CGREG?                                                                   |AT+CGREG                       |Refer to 9.8 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+CTZU=1                                                                   |AT+CTZU                        |Refer to 6.7 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+QICSGP=1,1,\"nbiot\",\"\",\"\",1                                         |AT+QICSGP                      |Refer to 2.1.1 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                     |||
 * | Example<br>ATCELL+CGDCONT=1,\"IP\",\"nbiot\"                                               |AT+CGDCONT                     |Refer to 9.2 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+COPS=1,0,\"Far EasTone\",9                                               |AT+COPS                        |Refer to 6.2 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+COPS?                                                                    |AT+COPS                        |Refer to 6.2 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+QIDEACT=1                                                                |AT+QIDEACT                     |Refer to 2.1.3 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                     |||
 * | Example<br>ATCELL+QIACT=1                                                                  |AT+QIACT                       |Refer to 2.1.2 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                     |||
 * | Example<br>ATCELL+QIDNSCFG=1,\"8.8.8.8\",\"8.8.8.4\"                                       |AT+QIDNSCFG                    |Refer to 2.1.13 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                    |||
 * | Example<br>ATCELL+QHTTPCFG=\"contextid\",1                                                 |AT+QHTTPCFG                    |Refer to 2.1 of BG96_HTTP(S)_AT_Commands_Manual_V1.0.                                                      |||
 * | Example<br>ATCELL+QHTTPCFG=\"responseheader\",1                                            |AT+QHTTPCFG                    |Refer to 2.1 of BG96_HTTP(S)_AT_Commands_Manual_V1.0.                                                      |||
 * | Example<br>ATCELL+QHTTPURL=24,80                                                           |AT+QHTTPURL                    |Refer to 2.2 of BG96_HTTP(S)_AT_Commands_Manual_V1.0.                                                      |||
 * | Example<br>ATCELL+QHTTPGET=80                                                              |AT+QHTTPGET                    |Refer to 2.3 of BG96_HTTP(S)_AT_Commands_Manual_V1.0.                                                      |||
 * | Example<br>ATCELL+QHTTPREAD=80                                                             |AT+QHTTPREAD                   |Refer to 2.6 of BG96_HTTP(S)_AT_Commands_Manual_V1.0.                                                      |||
 * | Example<br>ATCELL+QGPS=1                                                                   |AT+QGPS                        |Refer to 2.3 of BG96_GNSS_AT_Commands_Manual_V1.1.                                                         |||
 * | Example<br>ATCELL+QGPSLOC=1                                                                |AT+QGPSLOC                     |Refer to 2.5 of BG96_GNSS_AT_Commands_Manual_V1.1.                                                         |||
 * | Example<br>ATCELL+QGPSLOC?                                                                 |AT+QGPSLOC                     |Refer to 2.5 of BG96_GNSS_AT_Commands_Manual_V1.1.                                                         |||
 * | Example<br>ATCELL+QGPSGNMEA=\"GSV\"                                                        |AT+QGPSGNMEA                   |Refer to 2.6 of BG96_GNSS_AT_Commands_Manual_V1.1.                                                         |||
 * | Example<br>ATCELL+ATE1                                                                     |ATE                            |Refer to 2.16 of BG96_AT_Commands_Manual_V2.1.                                                             |||
 * | Example<br>ATCELL+AT&F0                                                                    |AT&F                           |Refer to 2.10 of BG96_AT_Commands_Manual_V2.1.                                                             |||
 * | Example<br>ATCELL+CTZR=2                                                                   |AT+CTZR                        |Refer to 6.15 of BG96_AT_Commands_Manual_V2.1.                                                             |||
 * | Example<br>ATCELL+CTZR?                                                                    |AT+CTZR                        |Refer to 6.15 of BG96_AT_Commands_Manual_V2.1.                                                             |||
 * | Example<br>ATCELL+CPIN?                                                                    |AT+CPIN                        |Refer to 5.3 of BG96_AT_Commands_Manual_V2.1.                                                              |||
 * | Example<br>ATCELL+QNWINFO                                                                  |AT+CPIN                        |Refer to 6.17 of BG96_AT_Commands_Manual_V2.1.                                                             |||
 * | Example<br>ATCELL+QPING=1,\"8.8.8.8\"                                                      |AT+QPING                       |Refer to 2.1.11 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                    |||
 * | Example<br>ATCELL+QMTCFG=\"ssl\",0,1,2                                                     |AT+QMTCFG                      |Refer to 3.2.1 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTCFG=\"aliauth\",0,\"oyjtmPl5a5j\",\"MQTT_TEST\",\"wN9Y6pZSIIy7Exa5qVzcmigEGO4kAazZ\"    |AT+QMTCFG    |Refer to 3.2.1 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QFDEL=\"cacert.pem\"                                                     |AT+QFDEL                       |Refer to 2.3 of BG96_FILE_AT_Commands_Manual_V1.0.                                                         |||
 * | Example<br>ATCELL+QFUPL=\"cacert.pem\",1187,100                                            |AT+QFUPL                       |Refer to 2.4 of BG96_FILE_AT_Commands_Manual_V1.0.                                                         |||
 * | Example<br>ATCELL+QSSLCFG=\"cacert\",2,\"cacert.pem\"                                      |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"cacert\",2                                                     |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"clientcert\",2,\"client.pem\"                                  |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"clientcert\",2                                                 |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"clientkey\",2,\"user_key.pem\"                                 |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"clientkey\",2                                                  |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"seclevel\",2,2                                                 |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"seclevel\",2                                                   |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"sslversion\",2,4                                               |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"sslversion\",2                                                 |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"ciphersuite\",2,\"0XFFFF\"                                     |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"ciphersuite\",2                                                |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"ignorelocaltime\",2,1                                          |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QSSLCFG=\"ignorelocaltime\",2                                            |AT+QSSLCFG                     |Refer to 2.1.1 of BG96_SSL_AT_Commands_Manual_V1.0.                                                        |||
 * | Example<br>ATCELL+QFLST                                                                    |AT+QFLST                       |Refer to 2.2 of BG96_FILE_AT_Commands_Manual_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTOPEN=0,\"ach7fkebnh9qw-ats.iot.ap-southeast-1.amazonaws.com\",8883    |AT+QMTOPEN                     |Refer to 3.2.2 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTOPEN?                                                                 |AT+QMTOPEN                     |Refer to 3.2.2 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTCONN=0,\"rak5010\"                                                    |AT+QMTCONN                     |Refer to 3.2.4 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTCONN?                                                                 |AT+QMTCONN                     |Refer to 3.2.4 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTSUB=0,1,\"$aws/things/rak5010/shadow/update/accepted\",1              |AT+QMTSUB                      |Refer to 3.2.6 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QMTPUB=0,1,1,0,\"$aws/things/rak5010/shadow/update/accepted\"            |AT+QMTPUB                      |Refer to 3.2.8 of BG96_MQTT_Application_Note_V1.0.                                                         |||
 * | Example<br>ATCELL+QIOPEN=1,0,\"TCP\",\"18.141.176.0\",7000,0,0                             |AT+QIOPEN                      |Refer to 2.1.4 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                     |||
 * | Example<br>ATCELL+QISENDEX=0,\"313233343536\"                                              |AT+QISENDEX                    |Refer to 2.1.9 of BG96_TCP/IP_AT_Commands_Manual_V1.0.                                                     |||
 */
#ifndef _ATCMD_CELLULAR_DEF_H_
#define _ATCMD_CELLULAR_DEF_H_

#define ATCMD_CELLULAR              "ATCELL"

#endif //_ATCMD_CELLULAR_DEF_H_

#endif //RAK51010_EVB

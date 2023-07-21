#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_p2p LoRaWAN P2P
 * 
 * This section provides a set of commands for battery level, RF signal quality and FW version.
 *
 * @subsection ATCMD_p2p_1 AT+NWM: network working mode
 *
 * This command switchs between LoRaWAN P2P mode and LoRaWAN mode (0:LoRaWAN P2P, 1:LoRaWAN, 2: LoRaWAN P2P FSK)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+NWM?            | --                 | AT+NWM: get or set the network working mode (0 = P2P_LORA, 1 = LoRaWAN, 2 = P2P_FSK)                         | OK                 |
 * | AT+NWM=?           | --                 | 0 or 1 or 2                                                       | OK                 |
 * | AT+NWM=\<Param\>   | 0 or 1             | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+NWM= | 1                  | --                                                                | OK                 |
 * | Example<br>AT+NWM=?|                    | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_2 AT+PFREQ: frequency
 *
 * This command allows the user to access the frequency in p2p mode. Note: This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PFREQ?          | --                 | AT+PFREQ: configure P2P Frequency                                 | OK                 |
 * | AT+PFREQ=?         | --                 | <interger>                                                        | OK                 |
 * | AT+PFREQ=\<Param\> | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PFREQ=?| --               | 868000000                                                         | OK                 |
 *
 * @subsection ATCMD_p2p_3 AT+PSF: spreading factor
 *
 * This command allows the user to access the spreading factor in p2p mode. Note: This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PSF?            | --                 | AT+PSF: configure P2P Spreading Factor (5-12)                     | OK                 |
 * | AT+PSF=?           | --                 | <interger>                                                        | OK                 |
 * | AT+PSF=\<Param\>   | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PSF=?| --                 | 7                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_4 AT+PBW: bandwidth
 *
 * This command allows the user to access the bandwidh in p2p mode. Note: This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PBW?            | --                 | AT+PBW: configure P2P Bandwidth(LORA:0=125,1=250,2=500,3=7.8,4=10.4,5=15.63,6=20.83,7=31.25,8=41.67,9=62.5 FSK:4800-467000) | OK                 |
 * | AT+PBW=?           | --                 | <interger>                                                        | OK                 |
 * | AT+PBW=\<Param\>   | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PSF=?| --                 | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_5 AT+PCR: coding rate
 *
 * This command allows the user to access the codingrate in p2p mode. Note: This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PCR?            | --                 | AT+PCR: configure P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)       | OK                 |
 * | AT+PCR=?           | --                 | <interger>                                                        | OK                 |
 * | AT+PCR=\<Param\>   | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PCR=?| --                 | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_6 AT+PPL: the length of preamble
 *
 * This command allows the user to access the length of preamble in p2p mode. This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PPL?            | --                 | AT+PPL: configure P2P Preamble Length (5-65535)                   | OK                 |
 * | AT+PPL=?           | --                 | <interger>                                                        | OK                 |
 * | AT+PPL=\<Param\>   | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PPL=?| --                 | 8                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_7 AT+PTP: tx power
 *
 * This command allows the user to access the tx power in p2p mode. This command will be deleted in the future
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PTP?            | --                 | AT+PTP: configure P2P TX Power(5-22)                              | OK                 |
 * | AT+PTP=?           | --                 | <interger>                                                        | OK                 |
 * | AT+PTP=\<Param\>   | <interger>         | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PTP=?| --                 | 14                                                                | OK                 |
 *
 * @subsection ATCMD_p2p_8 AT+PSEND: send data
 *
 * This command allows the user to send data in p2p mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PSEND?          | --                 | AT+PSEND: send data in P2P mode                                   | OK                 |
 * | AT+PSEND=?         | --                 | <interger>                                                        | OK                 |
 * | Example<br>AT+PSEND=?| --               | 32                                                                | OK                 |
 *
 * @subsection ATCMD_p2p_9 AT+PRECV: receive data
 *
 * This command allows the user to receive data in p2p mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PRECV?          | --                 | AT+PRECV: enter P2P RX mode for a period of time (ms)             | OK                 |
 * | AT+PRECV=?         | --                 | P2P_RX_OFF or P2P_RX_ON                                           | OK                 |
 * | AT+PRECV=<integer> | <integer>          | --                                                                | OK                 |
 * | Example<br>AT+PRECV=| 5000              | --                                                                | OK                 |
 *
 * @subsection ATCMD_p2p_10 AT+PCRYPT: the crypt status
 *
 * This command allows the user to access the crypt status in p2p mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PCRYPT?         | --                 | AT+PCRYPT: get or set the encryption status of P2P mode               | OK                 |
 * | AT+PCRYPT=?        | --                 | \<0 or 1\>                                                        | OK                 |
 * | AT+PCRYPT=         | \<0 or 1\>         | --                                                                | OK                 |
 * | Example<br>AT+PCRYPT=| 0                | --                                                                | OK                 |
 * | Example<br>AT+PCRYPT=?| --              | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_11 AT+PKEY: the encryption and decryption key
 *
 * This command allows the user to access the encryption and decryption key in p2p mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PKEY?           | --                 | AT+PKEY: get or set the encryption key of P2P mode (8 bytes in hex)                | OK                 |
 * | AT+PKEY=?          | --                 | \<8 hex\>                                                         | OK                 |
 * | AT+PKEY=           | \<8 hex\>          | --                                                                | OK                 |
 * | Example<br>AT+PKEY=| 0011223344556677   | --                                                                | OK                 |
 * | Example<br>AT+PKEY=?| --                | 0011223344556677                                                  | OK                 |
 *
 * @subsection ATCMD_p2p_12 AT+P2P: all P2P parameters
 *
 * This command provides a way to access all parameters for P2P mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+P2P?            | --                 | AT+P2P: get or set all P2P parameters                             | OK                 |
 * | AT+P2P=?           | --                 | \<freq\>,\<sf\>,\<bw\>,\<cr\>,\<preamble length\>,\<txp\>         | OK                 |
 * | AT+P2P=            | \<freq\>,\<sf\>,\<bw\>,\<cr\>,\<preamble length\>,\<txp\>,\<Runtime Setting\>    |                      | OK                 |
 * | Example<br>AT+P2P= | 868500000,12,0,0,10,22<br>868500000,8,250,2,24,20:1       | --                                                 | OK                 |
 * | Example<br>AT+P2P=?| --                 | 868000000,7,0,0,8,14                                            | OK                 |
 *
 * Freq: 150000000-960000000<br>
 * SF: 6,7,8,9,10,11,12<br>
 * Bandwidth: 0 = 125,1 = 250,2 = 500,3 = 7.8,4 = 10.4,5 = 15.63,6 = 20.83,7 = 31.25,8 = 41.67,9 = 62.5<br>
 * CR: 0 = 4/5, 1 = 4/6, 2 = 4/7, 3 = 4/8<br>
 * Preamble Length: 5-65535<br>
 * TX Power = 5-22<br>
 * Runtime Setting = 0-1. Optional. When Runtime Setting is 1, the configure will not store in Flash memory.<br>
 *
 * @subsection ATCMD_p2p_13 AT+PBR: get or set the P2P FSK modem bitrate (600b/s-300000b/s)
 *
 * This command allows the user to get or set the P2P FSK modem bitrate (600b/s-300000b/s)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PBR?            | --                 | AT+PBR: get or set the P2P FSK modem bitrate (600-300000 b/s)     | OK                 |
 * | AT+PBR=?           | --                 | <fbitrate>                                                        | OK                 |
 * | AT+PBR=\<Param\>   | <bitrate>          | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PBR=?| --                 | 4915                                                              | OK                 |
 *
 * @subsection ATCMD_p2p_14 AT+PFDEV: get or set the P2P FSK modem frequency deviation
 *
 * This command allows the user to get or set the P2P FSK modem frequency deviation (600-200000 hz)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PFDEV?          | --                 | AT+PFDEV: get or set the P2P FSK modem frequency deviation (600-200000 hz)        | OK                 |
 * | AT+PFDEV=?         | --                 | <frequency deviation>                                             | OK                 |
 * | AT+PFDEV=\<Param\> | <frequency deviation> | --                                                             | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PFDEV=?| --               | 5000                                                              | OK                 |
 *
 * @subsection ATCMD_p2p_15 AT+IQINVER: IQ inversion in p2p mode
 *
 * This command allows the user to get or set P2P IQ inversion (1 = on, 0 = off)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+IQINVER?          | --                 | AT+IQINVER:  get or set P2P IQ inversion (1 = on, 0 = off)      | OK                 |
 * | AT+IQINVER=?         | --                 | \<0 or 1\>                                                      | OK                 |
 * | AT+IQINVER=\<Param\> | \<0 or 1\>         | --                                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+IQINVER=?| --               | 0                                                               | OK                 |
 *
 * @subsection ATCMD_p2p_16 AT+SYNCWORD: P2P syncword (0x0000 - 0xffff) in p2p mode
 *
 * This command allows the user to get or set P2P syncword (0x0000 - 0xffff)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SYNCWORD?          | --              | AT+SYNCWORD:  get or set P2P syncword (0x0000 - 0xffff)        | OK                 |
 * | AT+SYNCWORD=?         | --              | \<2 Hex\>                                                      | OK                 |
 * | AT+SYNCWORD=\<Param\> | \<2 Hex\>       | --                                                             | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SYNCWORD=?| --            | 3444                                                           | OK                 |
 *
 * @subsection ATCMD_p2p_17 AT+RFFREQUENCY: frequency in p2p mode
 *
 * This command allows the user to access the frequency in p2p mode.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+RFFREQUENCY?          | --           | AT+RFFREQUENCY:  get or set P2P Frequency                         | OK                 |
 * | AT+RFFREQUENCY=?         | --           | <interger>                                                        | OK                 |
 * | AT+RFFREQUENCY=\<Param\> | <interger>   | --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+RFFREQUENCY=?| --         | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_18 AT+TXOUTPUTPOWER: P2P Tx Power(5-22)
 *
 * This command allows the user to get or set P2P Tx Power(5-22)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TXOUTPUTPOWER?          | --         | AT+TXOUTPUTPOWER:  get or set P2P Tx Power(5-22)                  | OK                 |
 * | AT+TXOUTPUTPOWER=?         | --         | \<powerlevel\>                                                    | OK                 |
 * | AT+TXOUTPUTPOWER=\<Param\> | \<powerlevel\>| --                                                             | OK / AT_PARAM_ERROR|
 * | Example<br>AT+TXOUTPUTPOWER=?| --       | 20                                                                | OK                 |
 *
 * @subsection ATCMD_p2p_19 AT+BANDWIDTH:P2P Bandwidth
 *
 * This command allows the user to get or set P2P Bandwidth(LORA: 0 = 125, 1 = 250, 2 = 500, 3 = 7.8, 4 = 10.4, 5 = 15.63, 6 = 20.83, 7 = 31.25, 8 = 41.67, 9 = 62.5  FSK:4800-467000)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+BANDWIDTH?          | --             | AT+BANDWIDTH: get or set P2P Bandwidth(LORA:0=125,1=250,2=500,3=7.8,4=10.4,5=15.63,6=20.83,7=31.25,8=41.67,9=62.5 FSK:4800-467000)                  | OK                 |
 * | AT+BANDWIDTH=?         | --             | \<bandwidth\>                                                     | OK                 |
 * | AT+BANDWIDTH=\<Param\> | \<bandwidth\>    | --                                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+BANDWIDTH=?| --           | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_20 AT+SPREADINGFACTOR: P2P Spreading Factor (5-12)
 *
 * This command allows the user to get or set P2P Spreading Factor (5-12)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SPREADINGFACTOR?          | --       | AT+SPREADINGFACTOR:  get or set P2P Spreading Factor (5-12)       | OK                 |
 * | AT+SPREADINGFACTOR=?         | --       | \<Spreading Factor\>                                              | OK                 |
 * | AT+SPREADINGFACTOR=\<Param\> | \<Spreading Factor\>| --                                                     | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SPREADINGFACTOR=?| --     | 5                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_21 AT+SPREADINGFACTOR: P2P coding rate
 *
 * This command allows the user to get or set P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SPREADINGFACTOR?          | --       | AT+SPREADINGFACTOR:get or set P2P Code Rate(0=4/5, 1=4/6, 2=4/7, 3=4/8)| OK                 |
 * | AT+SPREADINGFACTOR=?         | --       | \<coding rate\>                                                   | OK                 |
 * | AT+SPREADINGFACTOR=\<Param\> | \<coding rate\>| --                                                          | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SPREADINGFACTOR=?| --     | 0                                                                 | OK                 |
 *
 * @subsection ATCMD_p2p_22 AT+PREAMBLELENGTH: P2P Preamble Length (5-65535)
 *
 * This command allows the user to get or set P2P Preamble Length (5-65535)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+PREAMBLELENGTH?          | --        | AT+PREAMBLELENGTH:set get or set P2P Preamble Length (5-65535)    | OK                 |
 * | AT+PREAMBLELENGTH=?         | --        | <interger>                                                        | OK                 |
 * | AT+PREAMBLELENGTH=\<Param\> | <interger>| --                                                                | OK / AT_PARAM_ERROR|
 * | Example<br>AT+PREAMBLELENGTH=?| --      | 10                                                                | OK                 |
 *
 * @subsection ATCMD_p2p_23 AT+SYMBOLTIMEOUT: P2P symbolTimeout (0-248)
 *
 * This command allows the user to get or set P2P symbolTimeout (0-248)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+SYMBOLTIMEOUT?          | --       | AT+SYMBOLTIMEOUT:get or set P2P symbolTimeout (0-248)               | OK                 |
 * | AT+SYMBOLTIMEOUT=?         | --       | <interger>                                                          | OK                 |
 * | AT+SYMBOLTIMEOUT=\<Param\> | <interger>| --                                                                 | OK / AT_PARAM_ERROR|
 * | Example<br>AT+SYMBOLTIMEOUT=?| --     | 0                                                                   | OK                 |
 *
 * @subsection ATCMD_p2p_24 AT+FIXLENGTHPAYLOAD: P2P fix length payload on/off ( 1 = on, 0 = off)
 *
 * This command allows the user to get or set P2P fix length payload on/off ( 1 = on, 0 = off)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+FIXLENGTHPAYLOAD?          | --        | AT+FIXLENGTHPAYLOAD:  get or set P2P fix length payload on/off ( 1 = on, 0 = off) | OK                 |
 * | AT+FIXLENGTHPAYLOAD=?         | --        | \<0 or 1\>                                                      | OK                 |
 * | AT+FIXLENGTHPAYLOAD=\<Param\> | \<0 or 1\>| --                                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+FIXLENGTHPAYLOAD=?| --      | 0                                                               | OK                 |
 * 
 *
 * @subsection ATCMD_p2p_25 AT+ENCRY: P2P encryption status  
 *
 * This command allows the user to get or set  the encryption status of P2P mode ( 1 = on, 0 = off)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ENCRY?                     | --        | AT+ENCRY: get or set the encryption status of P2P( 1 = on, 0 = off) | OK                 |
 * | AT+ENCRY=?                    | --        | \<0 or 1\>                                                      | OK                 |
 * | AT+ENCRY=\<Param\>            | \<0 or 1\>| --                                                              | OK / AT_PARAM_ERROR|
 * | Example<br>AT+ENCRY=?         | --        | 0                                                               | OK                 |
 *  
 * @subsection ATCMD_p2p_26 AT+ENCKEY: P2P encryption key 
 *
 * This command allows the user to get or set  the encryption key of P2P mode (16 bytes in hex)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+ENCKEY?              | --                | AT+ENCKEY: get or set  the encryption key of P2P mode (16 bytes in hex)      | OK                 |
 * | AT+ENCKEY=?             | --                | \<16 hex\>                                                     | OK                 |
 * | AT+ENCKEY=\<Param\>     |\<16 hex\>          | --                                                            | OK                 |
 * | Example<br>AT+ENCKEY=   |  0011223344556677 | --                                                            | OK                 |
 * | Example<br>AT+ENCKEY=?  | --                | 0011223344556677                                              | OK                 |                                              
 *
 *
 * @subsection ATCMD_p2p_27 AT+CRYPIV: P2P encryption IV
 *
 * This command allows the user to get or set  the encryption IV of P2P mode (16 bytes in hex)
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CRYPIV?              | --                | AT+CRYPIV: get or set  the encryption key of P2P mode (16 bytes in hex)      | OK                 |
 * | AT+CRYPIV=?             | --                | \<16 hex\>                                                     | OK                 |
 * | AT+CRYPIV=\<Param\>     |\<16 hex\>          | --                                                            | OK                 |
 * | Example<br>AT+CRYPIV=   |  0011223344556677 | --                                                            | OK                 |
 * | Example<br>AT+CRYPIV=?  | --                | 0011223344556677                                              | OK                 |
 *
 *
 * @subsection ATCMD_p2p_28 AT+CAD: P2P Channel Activity Detection
 *
 * This command allows the user to get or set  the Channel Activity Detection of P2P mode 
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CAD?              | --                | AT+CAD: get or set  the Channel Activity Detection of P2P mode ( 1 = on, 0 = off) | OK                 |
 * | AT+CAD=?             | --                | \<0 or 1\>                                                                | OK                 |
 * | AT+CAD=\<Param\>     |\<16 hex\>         | --                                                                        | OK                 |
 * | Example<br>AT+CAD=   |\<0 or 1\>         | --                                                                        | OK                 |
 * | Example<br>AT+CAD=?  | --                | 0                                                                         | OK                 |
 *
 *
 *
 */

#endif

#ifndef _ATCMD_P2P_DEF_H_
#define _ATCMD_P2P_DEF_H_

//### following AT CMD, has doc ###
#define ATCMD_NWM               "AT+NWM"
#define ATCMD_PFREQ             "AT+PFREQ"
#define ATCMD_PSF               "AT+PSF"
#define ATCMD_PBW               "AT+PBW"
#define ATCMD_PCR               "AT+PCR"
#define ATCMD_PPL               "AT+PPL"
#define ATCMD_PTP               "AT+PTP"
#define ATCMD_PSEND             "AT+PSEND"
#define ATCMD_PRECV             "AT+PRECV"
#define ATCMD_PCRYPT            "AT+ENCRY"
#define ATCMD_PCAD               "AT+CAD"
#define ATCMD_PKEY              "AT+ENCKEY"
#define ATCMD_PIV               "AT+CRYPIV"
#define ATCMD_P2P               "AT+P2P"
#define ATCMD_PBR               "AT+PBR"
#define ATCMD_PFDEV             "AT+PFDEV"             
#define ATCMD_IQINVER           "AT+IQINVER"
#define ATCMD_SYNCWORD          "AT+SYNCWORD"
#define ATCMD_RFFREQUENCY       "AT+RFFREQUENCY"
#define ATCMD_TXOUTPUTPOWER     "AT+TXOUTPUTPOWER"
#define ATCMD_BANDWIDTH         "AT+BANDWIDTH"
#define ATCMD_SPREADINGFACTOR   "AT+SPREADINGFACTOR"
#define ATCMD_CODINGRATE        "AT+CODINGRATE"
#define ATCMD_PREAMBLELENGTH    "AT+PREAMBLELENGTH"
#define ATCMD_SYMBOLTIMEOUT     "AT+SYMBOLTIMEOUT"
#define ATCMD_FIXLENGTHPAYLOAD  "AT+FIXLENGTHPAYLOAD"


#endif //_ATCMD_INFO_DEF_H_

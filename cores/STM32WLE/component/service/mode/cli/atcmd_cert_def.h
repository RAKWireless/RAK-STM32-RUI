#ifdef SUPPORT_LORA
/**
 *
 * @page ATCMD AT Command Manual
 *
 * @section ATCMD_cert LoRa Certification
 *
 * This section provides a set of certification commands.
 *
 * @subsection ATCMD_cert_1 AT+TRSSI: RF RSSI tone test
 *
 * This command is used to start the RF RSSI tone test of the device
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TRSSI?          | --                 | AT+TRSSI: start RF RSSI tone test                                 | OK                 |
 * | AT+TRSSI           | --                 | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TRSSI| --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_2 AT+TTONE: RF tone test
 *
 * This command is used to start the RF tone test of the device
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TTONE?          | --                 | AT+TTONE: start RF tone test                                      | OK                 |
 * | AT+TTONE           | --                 | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TTONE| --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_3 AT+TTX: RF TX LoRa test
 *
 * This command is used to set the number of packets to be sent for a PER RF TX test
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TTX?            | --                 | AT+TTX: set number of packets to be sent for PER RF TX test       | OK                 |
 * | AT+TTX=\<input\>   | \<integer\>        | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TTX= | 3                  | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_4 AT+TRX: RF RX LoRa test
 *
 * This command is used to set the number of packets to be received for a PER RF TX test
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TRX?            | --                 | AT+TRX: set number of packets to be received for PER RF RX test   | OK                 |
 * | AT+TRX=\<input\>   | \<integer\>        | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TRX= | 3                  | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_5 AT+TCONF: Configure LoRa RF test
 *
 * This command is used to access and set LoRa configuration test
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TCONF?          | --                 | AT+TCONF: configure LoRa RF test                                  | OK                 |
 * | AT+TCONF=\<input\> | \<integer1\>:\<integer2\>:\<integer3\>:\<integer4\>:\<integer5\>:\<integer6\>:\<integer7\>:\<integer8\>:\<integer9\>:\<integer10\>:\<integer11\>:\<integer12\>          | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TCONF= | 868000000:14:4:12:4/5:0:0:1:16:25000:2:3                  | --                                                                | OK                 |
 *
 * <freq> <br>
 * <power> : output power [dBm]<br>
 * <bw> : bandwidth. FSK : >= 2600 and <= 250000 Hz; LoRa: [0: 125 kHz, 1: 250 kHz, 2: 500 kHz, 3: Reserved]<br>
 * <sf> : datarate. FSK : 600..300000 bits/s; LoRa: [6: 64, 7: 128, 8: 256, 9: 512, 10: 1024, 11: 2048, 12: 4096  chips]<br>
 * <cr> : coding rate (LoRa only). FSK : N/A ( set to 0 ); LoRa: [1: 4/5, 2: 4/6, 3: 4/7, 4: 4/8]
 * <lna> : not implemented yet<br>
 * <pa_boost> : not implemented yet<br>
 * <mod> : radio modem to be used [0: FSK, 1: LoRa] <br>
 * <len> : payload length when fixed length is used<br>
 * <fdev> : frequency deviation (FSK only). FSK : [Hz]; LoRa: 0<br>
 * <lowdropt> : not implemented yet<br>
 * <bt> : not implemented yet<br>
 *
 * @subsection ATCMD_cert_6 AT+TTH: RF Tx hopping test
 *
 * This command is used to access and configure RF Tx hopping test.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TTH?            | --                 | AT+TTH: start RF TX hopping test from Fstart to Fstop, with Fdelta steps           | OK                 |
 * | AT+TTH=\<input\>   | \<Fstart\>:\<Fstop\>:\<Fdelta\>:\<PacketNb\>                 | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TTH= | 868000000:868300000,100000,4               | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_7 AT+TOFF: Stop ongoing radio frequency test
 *
 * This command is used to stop the ongoing RF test.
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+TOFF?           | --                 | AT+TOFF: stop ongoing RF test                                     | OK                 |
 * | AT+TOFF            | --                 | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+TOFF | --                 | --                                                                | OK                 |
 *
 * @subsection ATCMD_cert_8 AT+CERTIF: LoraWAN certification mode
 *
 * This command set the module in LoraWAN certification mode
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CERTIF?         | --                 | AT+CERTIF: set the module in LoraWAN certification mode (0 = normal mode, 1 = certification mode))           | OK                 |
 * | AT+CERTIF=?        | --                 | 0 or 1                                                            | OK                 |
 * | AT+CERTIF=\<Input\>| 0 or 1             |                                                                   | OK / AT_PARAM_ERROR|
 * | Example<br>AT+CERTIF= | 1               | --                                                                | OK                 |
 * | Example<br>AT+CERTIF=?|                 | 1                                                                 | OK                 |
 *
 * @subsection ATCMD_cert_9 AT+CW: Send continuous wave
 *
 * This command is used to enable continuous RF tranmissions with configurable frequency, transmit power and duration
 *
 * | Command            | Input parameter    | Return value                                                      | Return code        |
 * |:------------------:|:------------------:|:------------------------------------------------------------------|:------------------:|
 * | AT+CW?             | --                 | AT+CW: start continuous wave                                      | OK                 |
 * | AT+CW=\<input\>    | \<freq\>:\<power\>:\<time\>                 | --                                                                | OK / AT_BUSY_ERROR |
 * | Example<br>AT+CW   | --                 | --                                                                | OK                 |
 *
 * <freq> : RAK3172(L) is needed to use the low frequency range 150000000 - 600000000; RAK3172(H) is needed to use the high frequency range 600000000 - 960000000<br>
 * <power> : 5 - 22 dBm<br>
 * <time> : 0 - 65535 ms<br>
 *
 */
#endif 
#ifndef _ATCMD_CERT_DEF_H_
#define _ATCMD_CERT_DEF_H_

#define ATCMD_TRSSI            "AT+TRSSI"
#define ATCMD_TTONE            "AT+TTONE"
#define ATCMD_TTX              "AT+TTX"
#define ATCMD_TRX              "AT+TRX"
#define ATCMD_TCONF            "AT+TCONF"
#define ATCMD_TTH              "AT+TTH"
#define ATCMD_TOFF             "AT+TOFF"
#define ATCMD_CERTIF           "AT+CERTIF"
#define ATCMD_CW               "AT+CW"

#endif //_ATCMD_CERT_DEF_H_

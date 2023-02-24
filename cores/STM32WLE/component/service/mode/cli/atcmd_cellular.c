#ifdef RAK5010_EVB
#ifdef SUPPORT_AT
#include <string.h>
#include <ctype.h>

#include "atcmd.h"
#include "atcmd_cellular.h"
#include "udrv_serial.h"
#include "udrv_errno.h"
#include "udrv_rtc.h"
#include "board_basic.h"

#define ATCELL_LEN 7

extern bool keep_bg96_on;
extern bool cellular_parser_enable;

static char send_command[ATCELL_BUFFER_SIZE+1] = {0};
static uint32_t parser_cmd_size, parser_cmd_timeout;
static uint32_t sgCurPos, sgCnt;
static long start_time ,end_time;

int At_Cellular (SERIAL_PORT port, char *cmd, stParam *param)
{
    char cell_cmd[MAX_CMD_LEN];

    memset(send_command, 0, ATCELL_BUFFER_SIZE+1);

    if (strlen(cmd) <= ATCELL_LEN) {
        if (param->argc != 0) {
            for (int argv_count=0; argv_count < param->argc; argv_count++) {
                strcat(send_command, param->argv[argv_count]);
                if (argv_count != param->argc - 1)
                    strcat(send_command, ":");
            } 
            if (strncasecmp(send_command+3, "IPR", 3) == 0) {
                goto exit_cmd_not_support;
            }
            strcat(send_command, "\r\032");
            goto exit_cellular;
        } else if (cmd[strlen(cmd) -1 ] == '?') {
            return AT_OK;
        } else {
            goto exit;
        }
    } else if (cmd[ATCELL_LEN - 1] != '+') {
        goto exit;
    }

    // Cut the command to RUI ATCMD to Cellular command
    memcpy(cell_cmd, cmd + ATCELL_LEN, strlen(cmd) - ATCELL_LEN + 1);

    if (strncasecmp(cell_cmd, "IPR", 3) == 0 || 
        strncasecmp(cell_cmd+3, "IPR", 3) == 0 ) {
        goto exit_cmd_not_support;
    }

    // Set the command to capital
    for(int len=0; len<strlen(cell_cmd); len++) {
        cell_cmd[len] = toupper(cell_cmd[len]);
    }

    // Check the Type of Cellular commands
    if ((param->argc == 0)) {
        // Read Command AT<X>?
        if ((cell_cmd[strlen(cell_cmd) - 1] == '?') && (strncasecmp("AT", cell_cmd, 2) == 0)) {
            strcat(send_command, cell_cmd);
            strcat(send_command, "\r\n");
        } 
        // Read Command AT+<X>?
        else if (cell_cmd[strlen(cell_cmd) - 1] == '?') {
            strcat(send_command, "AT+");
            strcat(send_command, cell_cmd);
            strcat(send_command, "\r\n");
        }
        // Execution Command AT<X>
        else if (strncasecmp("AT", cell_cmd, 2) == 0) {
            strcat(send_command, cell_cmd);
            strcat(send_command, "\r\n");
        } 
        // Execution Command AT+<X>
        else {
            strcat(send_command, "AT+");
            strcat(send_command, cell_cmd);
            strcat(send_command, "\r\n");
        }
        goto exit_cellular;

    } else if (param->argc == 1) {
        // Test Command AT<X>=?
        if (!strcmp(param->argv[0], "?") && (strncasecmp("AT", cell_cmd, 2) == 0)) {
            strcat(send_command, cell_cmd);
            strcat(send_command, "=?\r\n");
        }
        // Test Command AT+<X>=?
        else if (!strcmp(param->argv[0], "?")) {
            strcat(send_command, "AT+");
            strcat(send_command, cell_cmd);
            strcat(send_command, "=?\r\n");
        }
        // Write Command AT+<X>=<...>
        else if ((strncasecmp("AT", cell_cmd, 2) == 0)) {
            strcat(send_command, cell_cmd);
            strcat(send_command, "=");
            strcat(send_command, param->argv[0]);
            strcat(send_command, "\r\n");
        }
        // Write Command AT+<X>=<...>
        else {
            strcat(send_command, "AT+");
            strcat(send_command, cell_cmd);
            strcat(send_command, "=");
            strcat(send_command, param->argv[0]);
            strcat(send_command, "\r\n");
            //AT+QFUPL
            if (!strcasecmp(cell_cmd, "QFUPL")) {
                cellular_parser_enable = true;

                char *p = strtok(param->argv[0], ",");
                p = strtok(NULL, ",");
                parser_cmd_size = atoi(p);
                p = strtok(NULL, ",");
                parser_cmd_timeout = atoi(p) * 1000;
                start_time = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
            }
            //AT+QHTTPURL
            if (!strcasecmp(cell_cmd, "QHTTPURL")) {
                cellular_parser_enable = true;

                char *p = strtok(param->argv[0], ",");
                parser_cmd_size = atoi(p);
                p = strtok(NULL, ",");
                parser_cmd_timeout = atoi(p) * 1000;
                start_time = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
            }
        }
        goto exit_cellular;
        }


exit_cellular:
    udrv_serial_write(SERIAL_UART1, send_command, strlen(send_command)); 

    if (cellular_parser_enable) {
        char read_buf[50] = {0};

        udrv_delay_ms(500);

        if (udrv_serial_read_available(SERIAL_UART1)>0) {
            udrv_serial_read(SERIAL_UART1, read_buf, udrv_serial_read_available(SERIAL_UART1));
            atcmd_printf("%s", read_buf);
        }

        if (strstr(read_buf, "CONNECT") == NULL) 
            cellular_parser_enable = false;
    } 

#ifndef AUTO_DISPLAY_CELLULAR_RESPONSE
    char result[1] = {0};

    udrv_delay_ms(500);

    while(udrv_serial_read_available(SERIAL_UART1)>0) {
        udrv_serial_read(SERIAL_UART1, result, 1);
        atcmd_printf("%c", result[0]);
    }
    if (service_nvm_get_auto_sleep_time_from_nvm() && keep_bg96_on == true) {
        udrv_system_user_app_timer_stop ();
        udrv_system_user_app_timer_start (RAK5010_BG96_LPM_MIN_ACTIVE_TIME, NULL);
    }
#endif
    memset(send_command, 0, ATCELL_BUFFER_SIZE+1);

    return AT_OK;

exit:
    return AT_ERROR;

exit_cmd_not_support:
    atcmd_printf("This command is not available on RUI3\r\n");    

    return AT_OK;
}


void service_mode_cli_cellular_handler(SERIAL_PORT port, uint8_t ch) {
    end_time = udrv_rtc_get_timestamp((RtcID_E)SYS_RTC_COUNTER_PORT);
    if ((end_time - start_time) >= parser_cmd_timeout) {
        service_mode_cli_handler(port, ch);
        sgCurPos = 0;
        sgCnt = 0;
        cellular_parser_enable = false;
        return;
    }
    switch (ch)
    {
        case 0x08: /* Backspace Key */
        case 0x7f: /* Del key */
            if ( 0 < sgCurPos ) {
                send_command[--sgCurPos] = 0x00;
                sgCnt--;
            }
            break;
        case 0x0a:
            atcmd_printf("\r");
        case 0x0d:
            atcmd_printf("\n");
        default:
            if (sgCnt < parser_cmd_size) {
                udrv_serial_write(SERIAL_USB0, &ch, 1);
                send_command[sgCurPos++] = ch;
                sgCnt++;
            } else {
                atcmd_printf("\r\n");
                sgCurPos = 0;
                sgCnt = 0;
                cellular_parser_enable = false;

                udrv_serial_write(SERIAL_UART1, send_command, strlen(send_command));  
 
#ifndef AUTO_DISPLAY_CELLULAR_RESPONSE 
                char result[1] = {0}; 
             
                udrv_delay_ms(500); 
             
                while(udrv_serial_read_available(SERIAL_UART1)>0) { 
                    udrv_serial_read(SERIAL_UART1, result, 1); 
                    atcmd_printf("%c", result[0]); 
                } 
                if (service_nvm_get_auto_sleep_time_from_nvm() && keep_bg96_on == true) { 
                    udrv_system_user_app_timer_stop (); 
                    udrv_system_user_app_timer_start (RAK5010_BG96_LPM_MIN_ACTIVE_TIME, NULL); 
                } 
#endif 
                memset(send_command, 0, ATCELL_BUFFER_SIZE+1); 
             
                return AT_OK; 
                
            }
    }

}

#endif 

#endif // RAK5010_EVB

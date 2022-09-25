#include "atcmd.h"
#include "udrv_errno.h"
#ifdef SUPPORT_LORA
#include "service_lora.h"
#endif
#include "service_mode.h"
#include "service_mode_proto.h"
#include "service_mode_proto_builtin_handler.h"

extern const at_cmd_info atcmd_info_tbl[];

extern const char *sw_version;
extern const char *model_id;
extern const char *chip_id;
extern const char *build_date;
extern const char *build_time;
extern const char *repo_info;
extern const char *cli_version;
extern const char *api_version;
extern const char BOOT_VERSION;

void service_mode_proto_echo_request_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length) {
    uint8_t flag = PROTO_FLAG_RESPONSE;

    service_mode_proto_send(port, flag, 0x00, payload, length, service_mode_proto_echo_response_handler);
    return;
}

void service_mode_proto_echo_response_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length) {
    //Silently drop it
    return;
}

static void service_mode_proto_atcmd_report_error(SERIAL_PORT port, uint8_t atcmd_id, AT_ERRNO_E error) {
    uint8_t buff[256];
    proto_atcmd_header header;

    memset(buff, 0, 256);
    *(buff+sizeof(header)) = error;
    header.length = __builtin_bswap16(1);
    header.flag = PROTO_ATCMD_FLAG_RESPONSE;
    if (error != AT_OK) {
        header.flag |= PROTO_ATCMD_FLAG_ERROR;
    }
    header.atcmd_id = atcmd_id;
    memcpy(buff, &header, sizeof(header));

    service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
}

void service_mode_proto_atcmd_request_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length) {
    uint8_t payload_len = __builtin_bswap16(*(uint16_t *)payload);
    uint8_t flag = *(((uint8_t *)payload)+2);
    uint8_t atcmd_id = *(((uint8_t *)payload)+3);
    uint8_t *arg = ((uint8_t *)payload)+4;
    AT_ERRNO_E nRet = AT_ERROR;
    uint8_t buff[256];
    proto_atcmd_header header;
    uint16_t reply_len = 0;
    int32_t ret;

    if (length != (payload_len + 4)) {
        service_mode_proto_atcmd_report_error(port, atcmd_id, AT_PARAM_ERROR);
        return;
    }

    //if (atcmd_id > At_CmdGetTotalNum()) {
    //    service_mode_proto_atcmd_report_error(port, atcmd_id, AT_PARAM_ERROR);
    //    return;
    //}

    switch (atcmd_id) {
        case SERVICE_MODE_PROTO_ATCMD_ATTENTION:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_OK;
            } else {
                nRet = AT_MODE_NO_SUPPORT;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_REBOOT:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                udrv_system_reboot();
                nRet = AT_OK;
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ATR:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
#ifdef SUPPORT_LORA
                ret = service_lora_set_lora_default();
#else
                ret = service_nvm_set_default_config_to_nvm();
#endif
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BOOT:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                udrv_enter_dfu();
                nRet = AT_OK;
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BAT:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                float bat_lvl;

                service_battery_get_batt_level(&bat_lvl);
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%f", bat_lvl);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BUILDTIME:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s-%s", build_date, build_time);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_REPOINFO:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", repo_info);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_FWVER:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", sw_version);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CUSFWVER:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len > 32) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_nvm_set_firmware_ver_to_nvm(arg, strlen(arg)) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[33];
                if (service_nvm_get_firmware_ver_from_nvm(rbuff, 32) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                rbuff[32] = '\0';
                memset(buff, 0, 256);
                reply_len = strlen(rbuff);
                memcpy(buff+sizeof(header), rbuff, reply_len);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CLIVER:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len > 32) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_nvm_set_cli_ver_to_nvm(arg, strlen(arg)) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[33];
                if (service_nvm_get_cli_ver_from_nvm(rbuff, 32) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                rbuff[32] = '\0';
                memset(buff, 0, 256);
                reply_len = strlen(rbuff);
                memcpy(buff+sizeof(header), rbuff, reply_len);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_APIVER:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", api_version);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_HWMODEL:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len > 32) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_nvm_set_hwmodel_to_nvm(arg, strlen(arg)) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[33];
                if (service_nvm_get_hwmodel_from_nvm(rbuff, 32) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                rbuff[32] = '\0';
                memset(buff, 0, 256);
                reply_len = strlen(rbuff);
                memcpy(buff+sizeof(header), rbuff, reply_len);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_HWID:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", chip_id);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ALIAS:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) 
            {
                if (payload_len > 16) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_nvm_set_atcmd_alias_to_nvm(arg, strlen(arg)) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[17];
                if (service_nvm_get_atcmd_alias_from_nvm(rbuff, 16) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                rbuff[16] = '\0';
                memset(buff, 0, 256);
                reply_len = strlen(rbuff);
                memcpy(buff+sizeof(header), rbuff, reply_len);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_SYSV:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                float bat_lvl;
                service_battery_get_SysVolt_level (&bat_lvl);
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%f", bat_lvl);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
#ifdef SUPPORT_BLE
        case SERVICE_MODE_PROTO_ATCMD_BLEMAC:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 12) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (udrv_ble_set_macaddress(arg) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t blemac[12];
                udrv_ble_get_macaddress(blemac);
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", blemac);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
#endif 
        case SERVICE_MODE_PROTO_ATCMD_BOOTVER:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", &BOOT_VERSION);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_LOCK:
        {
            //if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
            //    udrv_serial_lock(port);
            //    nRet = AT_OK;
            //} else {
            //    nRet = AT_PARAM_ERROR;
            //}
            nRet = AT_MODE_NO_SUPPORT;
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PWORD:
        {
            //uint8_t rbuff[8];
            //uint32_t len;

            //if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
            //    if (payload_len < 1 || payload_len > 8) {
            //        nRet = AT_PARAM_ERROR;
            //        goto out;
            //    }

            //    if (udrv_serial_set_passwd(arg, payload_len) == UDRV_RETURN_OK) {
            //        nRet = AT_OK;
            //    } else {
            //        nRet = AT_ERROR;
            //    }
            //} else {
            //    if ((len = udrv_serial_get_passwd(rbuff, 8)) <= 0) {
            //        nRet = AT_ERROR;
            //        goto out;
            //    }
            //    memset(buff, 0, 256);
            //    reply_len = len;
            //    memcpy(buff+sizeof(header), rbuff, len);
            //    header.length = __builtin_bswap16(reply_len);
            //    header.flag = PROTO_ATCMD_FLAG_RESPONSE;
            //    header.atcmd_id = atcmd_id;
            //    memcpy(buff, &header, sizeof(header));

            //    service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
            //    nRet = AT_OK;
            //}
            nRet = AT_MODE_NO_SUPPORT;
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BAUD:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t baud;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                baud = __builtin_bswap32(*(uint32_t *)arg);

                udrv_serial_init(port, baud, SERIAL_WORD_LEN_8, SERIAL_STOP_BIT_1, SERIAL_PARITY_DISABLE, SERIAL_TWO_WIRE_NORMAL_MODE);

                ret = service_nvm_set_baudrate_to_nvm(baud);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_nvm_get_baudrate_from_nvm());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ATM:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                SERVICE_MODE_TYPE old_mode;

                if (payload_len != 0) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_CLI)
                {
                    if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_CLI)) != UDRV_RETURN_OK)
                    {
                        nRet = AT_ERROR;
                        goto out;
                    }

                    switch (old_mode)
                    {
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                        case SERVICE_MODE_TYPE_TRANSPARENT:
                        {
                            service_mode_transparent_deinit(port);
                            break;
                        }
#endif
#endif
                        case SERVICE_MODE_TYPE_PROTOCOL:
                        {
                            service_mode_proto_deinit(port);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }

                    service_mode_cli_init(port);
                }
                nRet = AT_OK;
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_APM:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                SERVICE_MODE_TYPE old_mode;
                uint8_t addr;

                if (payload_len == 0) {
                    if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_PROTOCOL)
                    {
                        if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_PROTOCOL)) != UDRV_RETURN_OK)
                        {
                            nRet = AT_ERROR;
                            goto out;
                        }

                        switch (old_mode)
                        {
                            case SERVICE_MODE_TYPE_CLI:
                            {
                                service_mode_cli_deinit(port);
                                break;
                            }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
                            case SERVICE_MODE_TYPE_TRANSPARENT:
                            {
                                service_mode_transparent_deinit(port);
                                break;
                            }
#endif
#endif
                            default:
                            {
                                break;
                            }
                        }

                        service_mode_proto_init(port);
                    }
                    nRet = AT_OK;
                } else {
                    nRet = AT_PARAM_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
#ifdef SUPPORT_LORA
#ifdef SUPPORT_PASSTHRU
        case SERVICE_MODE_PROTO_ATCMD_PAM:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                SERVICE_MODE_TYPE old_mode;
                uint8_t tp_port;

                if (payload_len == 0) {
                    if (service_lora_get_njs() == false)
                    {
                        nRet = AT_NO_NETWORK_JOINED;
                        goto out;
                    }

                    if ((old_mode = service_nvm_get_mode_type_from_nvm(port)) != SERVICE_MODE_TYPE_TRANSPARENT)
                    {
                        if ((ret = service_nvm_set_mode_type_to_nvm(port, SERVICE_MODE_TYPE_TRANSPARENT)) != UDRV_RETURN_OK)
                        {
                            nRet = AT_ERROR;
                            goto out;
                        }

                        switch (old_mode)
                        {
                            case SERVICE_MODE_TYPE_CLI:
                            {
                                service_mode_cli_deinit(port);
                                break;
                            }
                            case SERVICE_MODE_TYPE_PROTOCOL:
                            {
                                service_mode_proto_deinit(port);
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }

                        service_mode_transparent_init(port);
                    }
                    nRet = AT_OK;
                } else {
                    if (payload_len != 1) {
                        nRet = AT_PARAM_ERROR;
                        goto out;
                    }

                    tp_port = *arg;

                    if (tp_port < 1 || tp_port > 223)
                    {
                        ret = AT_PARAM_ERROR;
                        goto out;
                    }

                    if (service_nvm_set_tp_port_to_nvm(port, tp_port) == UDRV_RETURN_OK) {
                        nRet = AT_OK;
                    } else {
                        nRet = AT_ERROR;
                    }
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_nvm_get_tp_port_from_nvm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
#endif
        case SERVICE_MODE_PROTO_ATCMD_APPEUI:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 8) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_app_eui(arg, 8) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[8];
                if (service_lora_get_app_eui(rbuff, 8) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 8;
                memcpy(buff+sizeof(header), rbuff, 8);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_APPKEY:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 16) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_app_key(arg, 16) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[16];
                if (service_lora_get_app_key(rbuff, 16) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 16;
                memcpy(buff+sizeof(header), rbuff, 16);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_APPSKEY:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 16) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_app_skey(arg, 16) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[16];
                if (service_lora_get_app_skey(rbuff, 16) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 16;
                memcpy(buff+sizeof(header), rbuff, 16);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_DADDR:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_dev_addr(arg, 4) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[4];
                if (service_lora_get_dev_addr(rbuff, 4) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 4;
                memcpy(buff+sizeof(header), rbuff, 4);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_DEUI:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 8) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_dev_eui(arg, 8) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[8];
                if (service_lora_get_dev_eui(rbuff, 8) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 8;
                memcpy(buff+sizeof(header), rbuff, 8);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_NETID:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                uint8_t rbuff[4];
                if (service_lora_get_net_id(rbuff, 4) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 3;
                memcpy(buff+sizeof(header), rbuff, 3);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_NWKSKEY:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 16) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_set_nwk_skey(arg, 16) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[16];
                if (service_lora_get_nwk_skey(rbuff, 16) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 16;
                memcpy(buff+sizeof(header), rbuff, 16);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CFM:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t mode;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                mode = *arg;

                if (mode != 0 && mode != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_cfm((SERVICE_LORA_CONFIRM_MODE)mode) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_cfm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CFS:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_cfs();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_JOIN:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                int32_t val[4] = {-1, -1, -1, -1};
                uint32_t argc = payload_len;

                if (argc != 1 && argc != 2 && argc != 3 && argc != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                for (int i = 0 ; i < argc ; i++) {
                    val[i] = *(arg+i);
                }

                if (argc > 0 && (val[0] != 0 && val[0] != 1)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (argc > 1 && (val[1] != 0 && val[1] != 1)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (argc > 2 && (val[2] < 7 && val[2] > 255)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (argc > 3 && (val[3] < 0 && val[3] > 255)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_join(val[0], val[1], val[2], val[3]);
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_join_start();
                *(buff+sizeof(header)+1) = (uint8_t)service_lora_get_auto_join();
                *(buff+sizeof(header)+2) = (uint8_t)service_lora_get_auto_join_period();
                *(buff+sizeof(header)+3) = (uint8_t)service_lora_get_auto_join_max_cnt();
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_NJM:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t mode;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                mode = *arg;

                if (mode != 0 && mode != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_njm((SERVICE_LORA_JOIN_MODE)mode, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_njm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_NJS:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_njs();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RECV:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                uint8_t recv_buff[SERVICE_LORA_DLINK_BUFF_SIZE], fport;
                int32_t len;

                len = service_lora_get_last_recv(&fport, recv_buff, SERVICE_LORA_DLINK_BUFF_SIZE);
                memset(buff, 0, 256);
                memcpy(buff+sizeof(header), &fport, 1);
                reply_len = 1;
                memcpy(buff+sizeof(header)+reply_len, recv_buff, len);
                reply_len += len;
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_SEND:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                SERVICE_LORA_SEND_INFO info;
                uint8_t fport;
                int32_t ret;

                if (payload_len < 2 || payload_len > 251) {//1 byte for port, and data length is 1~250 bytes
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                fport = *arg;

                if (fport < 1 || fport > 223)
                {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                info.port = fport;
                info.retry_valid = false;
                info.confirm_valid = false;
                ret = service_lora_send(arg+1, payload_len-1, info, false);
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_NO_WAN_CONNECTION)
                {
                    nRet = AT_NO_NETWORK_JOINED;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_LPSEND:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                SERVICE_LORA_SEND_INFO info;
                uint8_t fport, ack;
                int32_t ret;

                if (payload_len < 2 || payload_len > 251) {//1 byte for port, and data length is 1~250 bytes
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                fport = *arg;

                if (fport < 1 || fport > 223)
                {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ack = *(arg+1);

                ret = service_lora_lptp_send(fport, ack, arg+2, payload_len-2);
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_NO_WAN_CONNECTION)
                {
                    nRet = AT_NO_NETWORK_JOINED;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RETY:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t retry_times;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                retry_times = *arg;

                if (service_lora_set_retry(retry_times) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_lora_get_retry();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ADR:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t adr;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                adr = *arg;

                if (adr != 0 && adr != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_adr((bool)adr, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_adr();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CLASS:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                switch (*arg) {
                    case 'a':
                    case 'A':
                    {
                        if (service_lora_set_class(SERVICE_LORA_CLASS_A, true) == UDRV_RETURN_OK) {
                            nRet = AT_OK;
                        } else {
                            nRet = AT_ERROR;
                        }
                        break;
                    }
                    case 'b':
                    case 'B':
                    {
                        if (service_lora_set_class(SERVICE_LORA_CLASS_B, true) == UDRV_RETURN_OK) {
                            nRet = AT_OK;
                        } else {
                            nRet = AT_ERROR;
                        }
                        break;
                    }
                    case 'c':
                    case 'C':
                    {
                        if (service_lora_set_class(SERVICE_LORA_CLASS_C, true) == UDRV_RETURN_OK) {
                            nRet = AT_OK;
                        } else {
                            nRet = AT_ERROR;
                        }
                        break;
                    }
                    default:
                    {
                        nRet = AT_PARAM_ERROR;
                        break;
                    }
                }
            } else {
                memset(buff, 0, 256);
                switch (service_lora_get_class()) {
                    case SERVICE_LORA_CLASS_A:
                        *(buff+sizeof(header)) = 'A';
                        break;
                    case SERVICE_LORA_CLASS_B:
                        *(buff+sizeof(header)) = 'B';
                        break;
                    case SERVICE_LORA_CLASS_C:
                        *(buff+sizeof(header)) = 'C';
                        break;
                    default:
                        return AT_ERROR;
                }
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_DCS:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t dcs;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                dcs = *arg;

                if (dcs != 0 && dcs != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_dcs(dcs, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_dcs();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_DR:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t dr;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                dr = *arg;

                if (service_lora_set_dr((SERVICE_LORA_DATA_RATE)dr, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_dr();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_JN1DL:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t jn1dl;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                jn1dl = __builtin_bswap32(*(uint32_t *)arg);

                if (jn1dl < 1 || jn1dl > 14) {//unit is second
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (jn1dl >= service_lora_get_jn2dl()/1000) {
                    ret = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_jn1dl(jn1dl*1000, true) == UDRV_RETURN_OK) {//change unit from s to ms
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_nvm_get_jn1dl_from_nvm()/1000);//change unit from ms to s
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_JN2DL:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t jn2dl;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                jn2dl = __builtin_bswap32(*(uint32_t *)arg);

                if (jn2dl < 2 || jn2dl > 15) {//unit is second
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (jn2dl <= service_lora_get_jn1dl()/1000) {//change unit from ms to s
                    ret = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_jn2dl(jn2dl*1000, true) == UDRV_RETURN_OK) {//change unit from s to ms
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_nvm_get_jn2dl_from_nvm()/1000);
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PNM:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t pnm;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                pnm = *arg;

                if (pnm != 0 && pnm != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_pub_nwk_mode((bool)pnm, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_pub_nwk_mode();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RX1DL:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t rx1dl;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                rx1dl = __builtin_bswap32(*(uint32_t *)arg);

                if (rx1dl < 1 || rx1dl > 15) {//unit is second
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_rx1dl(rx1dl*1000, true) == UDRV_RETURN_OK) {//change unit from s to ms
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_nvm_get_rx1dl_from_nvm()/1000);
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RX2DL:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t rx2dl;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                rx2dl = __builtin_bswap32(*(uint32_t *)arg);

                if (rx2dl < 2 || rx2dl > 16) {//unit is second
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_rx2dl(rx2dl*1000, true) == UDRV_RETURN_OK) {//change unit from s to ms
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_nvm_get_rx2dl_from_nvm()/1000);//change unit from ms to s
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RX2DR:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t dr;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                dr = *arg;

                if (service_lora_set_rx2dr((SERVICE_LORA_DATA_RATE)dr, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_rx2dr();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RX2FQ:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t rx2fq;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                rx2fq = __builtin_bswap32(*(uint32_t *)arg);

                if (service_lora_set_rx2freq(rx2fq, true) == UDRV_RETURN_OK) {//change unit from s to ms
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_lora_get_rx2freq());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_TXP:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t txp;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                txp = *arg;

                if (txp > SERVICE_LORA_TX_POWER_MAX) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_txpower(txp, true) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_txpower();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_LINKCHECK:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t linkcheck_mode;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                linkcheck_mode = *arg;

                if (service_lora_set_linkcheck(linkcheck_mode) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_linkcheck();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PGSLOT:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t periodicity;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                periodicity = *arg;

                if (periodicity > 7)
                {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_ping_slot_periodicity(periodicity) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_ping_slot_periodicity();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BFREQ:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                uint32_t freq;

                freq = service_lora_get_beacon_freq();

                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(freq);
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BTIME:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                uint32_t time;

                time = service_lora_get_beacon_time();

                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(time);
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_BGW:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                beacon_bgw_t beacon_bgw = service_lora_get_beacon_gwspecific();
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%d,%d,%d,%d,%d",
    	    		beacon_bgw.GPS_coordinate,
    	    		beacon_bgw.net_ID,
    	    		beacon_bgw.gateway_ID,
    	    		beacon_bgw.latitude,
    	    		beacon_bgw.longitude);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_LTIME:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                char local_time[30] = {0};
                service_lora_get_local_time(local_time);
                memset(buff, 0, 256);
                reply_len = sprintf(buff+sizeof(header), "%s", local_time);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RSSI:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                *(int16_t *)(buff+sizeof(header)) = __builtin_bswap16(service_lora_get_rssi());
                header.length = __builtin_bswap16(2);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+2, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ARSSI:
        {
            //TODO
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_SNR:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
            } else {
                memset(buff, 0, 256);
                *(int8_t *)(buff+sizeof(header)) = service_lora_get_snr();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
        case SERVICE_MODE_PROTO_ATCMD_MASK:
        {
            uint16_t ch_mask;

            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 2) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ch_mask = __builtin_bswap16(*(uint16_t *)arg);

                ret = service_lora_set_mask(&ch_mask, true);
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            } else {
                if (UDRV_RETURN_OK == service_lora_get_mask(&ch_mask))
                {
                    memset(buff, 0, 256);
                    *(int16_t *)(buff+sizeof(header)) = __builtin_bswap16(ch_mask);
                    header.length = __builtin_bswap16(2);
                    header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                    header.atcmd_id = atcmd_id;
                    memcpy(buff, &header, sizeof(header));

                    service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+2, NULL);
                    nRet = AT_OK;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CHE:
        {
            nRet = AT_MODE_NO_SUPPORT;
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_CHS:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t freq;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                freq = __builtin_bswap32(*(uint32_t *)arg);

	        ret = service_lora_set_chs(freq);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                int32_t freq;

                if((freq = service_lora_get_chs()) < 0) {
                    nRet = AT_ERROR;
                    goto out;
                }

                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(freq);
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
#endif
        case SERVICE_MODE_PROTO_ATCMD_BAND:
        {
            if (SERVICE_LORAWAN != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t input;
                SERVICE_LORA_BAND band;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                input = *arg;
                switch (input)
                {
                case 0:
                    band = SERVICE_LORA_EU433;
                    break;
                case 1:
                    band = SERVICE_LORA_CN470;
                    break;
                case 2:
#ifndef LEGACY
                    band = SERVICE_LORA_RU864;
                    break;
#else
                    nRet = AT_PARAM_ERROR;
                    break;
#endif
                case 3:
                    band = SERVICE_LORA_IN865;
                    break;
                case 4:
                    band = SERVICE_LORA_EU868;
                    break;
                case 5:
                    band = SERVICE_LORA_US915;
                    break;
                case 6:
                    band = SERVICE_LORA_AU915;
                    break;
                case 7:
                    band = SERVICE_LORA_KR920;
                    break;
                case 8:
                    band = SERVICE_LORA_AS923;
                    break;
                case 9:
                    band = SERVICE_LORA_AS923_2;
                    break;
                case 10:
                    band = SERVICE_LORA_AS923_3;
                    break;
                case 11:
                    band = SERVICE_LORA_AS923_4;
                    break;
                default:
                    nRet = AT_PARAM_ERROR;
                    break;
                }

                ret = service_lora_set_band(band);
                if (ret == UDRV_RETURN_OK)
                {
                    nRet = AT_OK;
                }
                else if (ret == -UDRV_BUSY)
                {
                    nRet = AT_BUSY_ERROR;
                }
                else
                {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                switch (service_lora_get_band())
                {
                    case SERVICE_LORA_EU433:
                        *(buff+sizeof(header)) = 0;
                        break;
                    case SERVICE_LORA_CN470:
                        *(buff+sizeof(header)) = 1;
                        break;
#ifndef LEGACY
                    case SERVICE_LORA_RU864:
                        *(buff+sizeof(header)) = 2;
                        break;
#endif
                    case SERVICE_LORA_IN865:
                        *(buff+sizeof(header)) = 3;
                        break;
                    case SERVICE_LORA_EU868:
                        *(buff+sizeof(header)) = 4;
                        break;
                    case SERVICE_LORA_US915:
                        *(buff+sizeof(header)) = 5;
                        break;
                    case SERVICE_LORA_AU915:
                        *(buff+sizeof(header)) = 6;
                        break;
                    case SERVICE_LORA_KR920:
                        *(buff+sizeof(header)) = 7;
                        break;
                    case SERVICE_LORA_AS923:
                        *(buff+sizeof(header)) = 8;
                        break;
                    case SERVICE_LORA_AS923_2:
                        *(buff+sizeof(header)) = 9;
                        break;
                    case SERVICE_LORA_AS923_3:
                        *(buff+sizeof(header)) = 10;
                        break;
                    case SERVICE_LORA_AS923_4:
                        *(buff+sizeof(header)) = 11;
                        break;
                    
#ifdef LEGACY
                    case SERVICE_LORA_US915_HYBRID:
#endif
                    default:
                        service_mode_proto_atcmd_report_error(port, atcmd_id, AT_ERROR);
                        return;
                }
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_NWM:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t mode;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                mode = *arg;

                if (mode != 0 && mode != 1 && mode != 2) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_set_nwm((SERVICE_LORA_WORK_MODE)mode) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_lora_get_nwm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PFREQ:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t frequency;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                frequency = __builtin_bswap32(*(uint32_t *)arg);

                if ((frequency < 150e6) || (frequency > 960e6)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_p2p_set_freq(frequency);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_lora_p2p_get_freq());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PSF:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t spreading_factor;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                spreading_factor = *arg;

                if ((spreading_factor < 6) || (spreading_factor > 12)) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_p2p_set_sf(spreading_factor);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_lora_p2p_get_sf();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PBW:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t bandwidth;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                bandwidth = __builtin_bswap32(*(uint32_t *)arg);

                ret = service_lora_p2p_set_bandwidth(bandwidth);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_lora_p2p_get_bandwidth());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PCR:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t coding_rate;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                coding_rate = *arg;

                ret = service_lora_p2p_set_codingrate(coding_rate);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_lora_p2p_get_codingrate();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PPL:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint16_t preamble_length;

                if (payload_len != 2) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                preamble_length = __builtin_bswap16(*(uint16_t *)arg);

                if (preamble_length < 5) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (preamble_length > 65535) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_p2p_set_preamlen(preamble_length);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint16_t *)(buff+sizeof(header)) = __builtin_bswap16(service_lora_p2p_get_preamlen());
                header.length = __builtin_bswap16(2);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+2, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PTP:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t txpower;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                txpower = *arg;

                ret = service_lora_p2p_set_powerdbm(txpower);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_lora_p2p_get_powerdbm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PSEND:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t datalen;
                uint8_t lora_data[255];

                if (payload_len == 0 || payload_len > 255) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_lora_p2p_send(arg, payload_len) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PRECV:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t timeout;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                timeout = __builtin_bswap32(*(uint32_t *)arg);

                ret = service_lora_p2p_recv(timeout);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PCRYPT:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t crypto_enable;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                crypto_enable = *arg;

                ret = service_lora_p2p_set_crypto_enable(crypto_enable);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = service_lora_p2p_get_crypto_enable();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PKEY:
        {
            if (SERVICE_LORAWAN == service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                if (payload_len != 8) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }
                if (service_lora_p2p_set_crypto_key(arg, 8) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                uint8_t rbuff[8];
                if (service_lora_p2p_get_crypto_key(rbuff, 8) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 8;
                memcpy(buff+sizeof(header), rbuff, 8);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PBR:
        {
            if (SERVICE_LORA_FSK != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t bitrate;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                bitrate = __builtin_bswap32(*(uint32_t *)arg);

                if(bitrate < 600 || bitrate > 300000)
                {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_p2p_set_bitrate(bitrate);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_lora_p2p_get_bitrate());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_PFDEV:
        {
            if (SERVICE_LORA_FSK != service_lora_get_nwm())
            {
                nRet = AT_MODE_NO_SUPPORT;
                goto out;
            }

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t fdev;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                fdev = __builtin_bswap32(*(uint32_t *)arg);

                if( fdev < 600 || fdev > 200000) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                ret = service_lora_p2p_set_fdev(fdev);
                if (ret == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(uint32_t *)(buff+sizeof(header)) = __builtin_bswap32(service_lora_p2p_get_fdev());
                header.length = __builtin_bswap16(4);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+4, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_ADDMULC:
        {
            //TODO
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_RMVMULC:
        {
            //TODO
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_LSTMULC:
        {
            //TODO
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_SN:
        {
            uint8_t rbuff[18];

            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                nRet = AT_PARAM_ERROR;
                goto out;
            } else {
                if (service_nvm_get_sn_from_nvm(rbuff, 18) != UDRV_RETURN_OK) {
                    nRet = AT_ERROR;
                    goto out;
                }
                memset(buff, 0, 256);
                reply_len = 18;
                memcpy(buff+sizeof(header), rbuff, 18);
                header.length = __builtin_bswap16(reply_len);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+reply_len, NULL);
                nRet = AT_OK;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_SLEEP:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint32_t input;

                if (payload_len != 4) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                input = __builtin_bswap32(*(uint32_t *)arg);

                udrv_sleep_ms(input);
                nRet = AT_OK;
            } else {
                nRet = AT_PARAM_ERROR;
            }
            break;
        }
        case SERVICE_MODE_PROTO_ATCMD_P2P:
        {
            nRet = AT_MODE_NO_SUPPORT;
            break;
        }
#endif
        case SERVICE_MODE_PROTO_ATCMD_AUTOSLEEP:
        {
            if (flag & PROTO_ATCMD_FLAG_WR_OR_EXE) {
                uint8_t autosleep;

                if (payload_len != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                autosleep = *arg;

                if (autosleep != 0 && autosleep != 1) {
                    nRet = AT_PARAM_ERROR;
                    goto out;
                }

                if (service_nvm_set_auto_sleep_time_to_nvm(autosleep) == UDRV_RETURN_OK) {
                    nRet = AT_OK;
                } else {
                    nRet = AT_ERROR;
                }
            } else {
                memset(buff, 0, 256);
                *(buff+sizeof(header)) = (uint8_t)service_nvm_get_auto_sleep_time_from_nvm();
                header.length = __builtin_bswap16(1);
                header.flag = PROTO_ATCMD_FLAG_RESPONSE;
                header.atcmd_id = atcmd_id;
                memcpy(buff, &header, sizeof(header));

                service_mode_proto_send(port, PROTO_FLAG_RESPONSE, 0x01, buff, sizeof(header)+1, NULL);
                nRet = AT_OK;
            }
            break;
        }
        //case SERVICE_MODE_PROTO_ATCMD_DELBONDS:
        default:
        {
            /* do nothing */
            break;
        }
    }

out:
    //if (nRet != AT_OK) {
        service_mode_proto_atcmd_report_error(port, atcmd_id, nRet);
    //}

    return;
}

void service_mode_proto_atcmd_response_handler (SERIAL_PORT port, uint8_t *payload, uint16_t length) {
    return;
}

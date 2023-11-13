/**
 * @file        udrv_errno.h
 * @brief       This file contains all error code for the hardware independent driver layer.
 * @author      Rakwireless
 * @version     0.0.0
 * @date        2021.3
 */

#ifndef _UDRV_ERRNO_H_
#define _UDRV_ERRNO_H_

#ifdef __cplusplus
extern "C" {
#endif 

typedef enum _UDRV_RETURN_CODE
{
    UDRV_RETURN_OK,
    UDRV_NOT_INIT,
    UDRV_ALREADY_INIT,
    UDRV_WRONG_ARG,
    UDRV_NACK,
    UDRV_OCCUPIED,
    UDRV_BUSY,
    UDRV_INTERNAL_ERR,
    UDRV_TEMP_LOCKED,
    UDRV_BUFF_OVERFLOW,
    UDRV_ADDR_NOT_ALIGNED,
    UDRV_LEN_NOT_ALIGNED,
    UDRV_NO_WAN_CONNECTION,
    UDRV_FORBIDDEN,
    UDRV_CONTINUE,
    UDRV_NOT_FOUND,
    UDRV_PARAM_ERR,
    UDRV_UNSUPPORTED_BAND,
    UDRV_INVALID_KEY_LENGTH = 0x0020,
    UDRV_INVALID_INPUT_LENGTH = 0x0022,
} UDRV_RETURN_CODE;

#ifdef __cplusplus
}
#endif

#endif //_UDRV_ERRNO_H_

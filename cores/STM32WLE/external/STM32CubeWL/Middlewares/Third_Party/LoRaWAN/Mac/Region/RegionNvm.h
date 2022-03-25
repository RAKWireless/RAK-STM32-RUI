/*!
 * \file      RegionNvm.h
 *
 * \brief     Region independent non-volatile data.
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 *               ___ _____ _   ___ _  _____ ___  ___  ___ ___
 *              / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 *              \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 *              |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 *              embedded.connectivity.solutions===============
 *
 * \endcode
 *
 * \author     Miguel Luis ( Semtech )
 *
 * \author     Daniel Jaeckle ( STACKFORCE )
 *
 * \addtogroup REGIONCOMMON
 *
 * \{
 */
#ifndef __REGIONNVM_H__
#define __REGIONNVM_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "lorawan_conf.h"
#include "LoRaMacTypes.h"

// Selection of REGION_NVM_MAX_NB_CHANNELS
#if defined( REGION_CN470 )
    #define REGION_NVM_MAX_NB_CHANNELS                 96
#elif defined( REGION_US915 ) || defined( REGION_AU915 )
    #define REGION_NVM_MAX_NB_CHANNELS                 72
#elif defined( REGION_AS923 ) || defined( REGION_CN779 ) || \
      defined( REGION_EU433 ) || defined( REGION_EU868 ) || \
      defined( REGION_IN865 ) || defined( REGION_KR920 )
    #define REGION_NVM_MAX_NB_CHANNELS                 16
#else
    // Region_RU864
    #define REGION_NVM_MAX_NB_CHANNELS                 8
#endif

// Selection of REGION_NVM_MAX_NB_BANDS
#if defined( REGION_EU868 )
    #define REGION_NVM_MAX_NB_BANDS                    6
#else
    // All others
    #define REGION_NVM_MAX_NB_BANDS                    1
#endif

// Selection of REGION_NVM_CHANNELS_MASK_SIZE
#if defined( REGION_CN470 ) || defined( REGION_US915 ) || \
    defined( REGION_AU915 )
    #define REGION_NVM_CHANNELS_MASK_SIZE              6
#else
    // All others
    #define REGION_NVM_CHANNELS_MASK_SIZE              1
#endif

/*!
 * Region specific data which must be stored in the NVM.
 */
typedef struct sRegionNvmDataGroup1
{
    /*!
     * LoRaMac bands
     */
    Band_t Bands[ REGION_NVM_MAX_NB_BANDS ];
#if defined( REGION_US915 ) || defined( REGION_AU915 )
    /*!
     * LoRaMac channels remaining
     */
    uint16_t ChannelsMaskRemaining[ REGION_NVM_CHANNELS_MASK_SIZE ];
    /*!
     * Index of current in use 8 bit group (0: bit 0 - 7, 1: bit 8 - 15, ...,
     * 7: bit 56 - 63)
     */
    uint8_t JoinChannelGroupsCurrentIndex;
    /*!
     * Counter of join trials needed to alternate between datarates.
     */
    uint8_t JoinTrialsCounter;
#endif
    /*!
     * CRC32 value of the Region data structure.
     */
    uint32_t Crc32;
}RegionNvmDataGroup1_t;

/*!
 * Region specific data which must be stored in the NVM.
 * Parameters which do not change very frequently.
 */
typedef struct sRegionNvmDataGroup2
{
    /*!
     * LoRaMAC channels
     */
    ChannelParams_t Channels[ REGION_NVM_MAX_NB_CHANNELS ];
    /*!
     * LoRaMac channels mask
     */
    uint16_t ChannelsMask[ REGION_NVM_CHANNELS_MASK_SIZE ];
    /*!
     * LoRaMac channels default mask
     */
    uint16_t ChannelsDefaultMask[ REGION_NVM_CHANNELS_MASK_SIZE ];
    /*!
     * CRC32 value of the Region data structure.
     */
    uint32_t Crc32;
}RegionNvmDataGroup2_t;

/*! \} addtogroup REGIONCOMMON */

#ifdef __cplusplus
}
#endif

#endif // __REGIONNVM_H__

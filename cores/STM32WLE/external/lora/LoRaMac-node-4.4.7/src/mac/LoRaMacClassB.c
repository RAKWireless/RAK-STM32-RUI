# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3//"
# 1 "<built-in>"
#define __STDC__ 1
#define __STDC_VERSION__ 199901L
#define __STDC_HOSTED__ 1
#define __GNUC__ 10
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __VERSION__ "10.2.1 20201103 (release)"
#define __ATOMIC_RELAXED 0
#define __ATOMIC_SEQ_CST 5
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __OPTIMIZE_SIZE__ 1
#define __OPTIMIZE__ 1
#define __FINITE_MATH_ONLY__ 0
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_LONG_DOUBLE__ 8
#define __SIZEOF_SIZE_T__ 4
#define __CHAR_BIT__ 8
#define __BIGGEST_ALIGNMENT__ 8
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_PDP_ENDIAN__ 3412
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __SIZEOF_POINTER__ 4
#define __SIZE_TYPE__ unsigned int
#define __PTRDIFF_TYPE__ int
#define __WCHAR_TYPE__ unsigned int
#define __WINT_TYPE__ unsigned int
#define __INTMAX_TYPE__ long long int
#define __UINTMAX_TYPE__ long long unsigned int
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __SIG_ATOMIC_TYPE__ int
#define __INT8_TYPE__ signed char
#define __INT16_TYPE__ short int
#define __INT32_TYPE__ long int
#define __INT64_TYPE__ long long int
#define __UINT8_TYPE__ unsigned char
#define __UINT16_TYPE__ short unsigned int
#define __UINT32_TYPE__ long unsigned int
#define __UINT64_TYPE__ long long unsigned int
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST16_TYPE__ short int
#define __INT_LEAST32_TYPE__ long int
#define __INT_LEAST64_TYPE__ long long int
#define __UINT_LEAST8_TYPE__ unsigned char
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __UINT_LEAST32_TYPE__ long unsigned int
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __INT_FAST8_TYPE__ int
#define __INT_FAST16_TYPE__ int
#define __INT_FAST32_TYPE__ int
#define __INT_FAST64_TYPE__ long long int
#define __UINT_FAST8_TYPE__ unsigned int
#define __UINT_FAST16_TYPE__ unsigned int
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __INTPTR_TYPE__ int
#define __UINTPTR_TYPE__ unsigned int
#define __GXX_ABI_VERSION 1014
#define __SCHAR_MAX__ 0x7f
#define __SHRT_MAX__ 0x7fff
#define __INT_MAX__ 0x7fffffff
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __WCHAR_MAX__ 0xffffffffU
#define __WCHAR_MIN__ 0U
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __PTRDIFF_MAX__ 0x7fffffff
#define __SIZE_MAX__ 0xffffffffU
#define __SCHAR_WIDTH__ 8
#define __SHRT_WIDTH__ 16
#define __INT_WIDTH__ 32
#define __LONG_WIDTH__ 32
#define __LONG_LONG_WIDTH__ 64
#define __WCHAR_WIDTH__ 32
#define __WINT_WIDTH__ 32
#define __PTRDIFF_WIDTH__ 32
#define __SIZE_WIDTH__ 32
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __INTMAX_C(c) c ## LL
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __UINTMAX_C(c) c ## ULL
#define __INTMAX_WIDTH__ 64
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __SIG_ATOMIC_WIDTH__ 32
#define __INT8_MAX__ 0x7f
#define __INT16_MAX__ 0x7fff
#define __INT32_MAX__ 0x7fffffffL
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __UINT8_MAX__ 0xff
#define __UINT16_MAX__ 0xffff
#define __UINT32_MAX__ 0xffffffffUL
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __INT_LEAST8_MAX__ 0x7f
#define __INT8_C(c) c
#define __INT_LEAST8_WIDTH__ 8
#define __INT_LEAST16_MAX__ 0x7fff
#define __INT16_C(c) c
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_MAX__ 0x7fffffffL
#define __INT32_C(c) c ## L
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __INT64_C(c) c ## LL
#define __INT_LEAST64_WIDTH__ 64
#define __UINT_LEAST8_MAX__ 0xff
#define __UINT8_C(c) c
#define __UINT_LEAST16_MAX__ 0xffff
#define __UINT16_C(c) c
#define __UINT_LEAST32_MAX__ 0xffffffffUL
#define __UINT32_C(c) c ## UL
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __UINT64_C(c) c ## ULL
#define __INT_FAST8_MAX__ 0x7fffffff
#define __INT_FAST8_WIDTH__ 32
#define __INT_FAST16_MAX__ 0x7fffffff
#define __INT_FAST16_WIDTH__ 32
#define __INT_FAST32_MAX__ 0x7fffffff
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_FAST64_WIDTH__ 64
#define __UINT_FAST8_MAX__ 0xffffffffU
#define __UINT_FAST16_MAX__ 0xffffffffU
#define __UINT_FAST32_MAX__ 0xffffffffU
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __INTPTR_MAX__ 0x7fffffff
#define __INTPTR_WIDTH__ 32
#define __UINTPTR_MAX__ 0xffffffffU
#define __GCC_IEC_559 0
#define __GCC_IEC_559_COMPLEX 0
#define __FLT_EVAL_METHOD__ 0
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __DEC_EVAL_METHOD__ 2
#define __FLT_RADIX__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_DIG__ 6
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_10_EXP__ 38
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_MAX__ 3.4028234663852886e+38F
#define __FLT_NORM_MAX__ 3.4028234663852886e+38F
#define __FLT_MIN__ 1.1754943508222875e-38F
#define __FLT_EPSILON__ 1.1920928955078125e-7F
#define __FLT_DENORM_MIN__ 1.4012984643248171e-45F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_DIG__ 15
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_10_EXP__ 308
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_MAX__ ((double)1.7976931348623157e+308L)
#define __DBL_NORM_MAX__ ((double)1.7976931348623157e+308L)
#define __DBL_MIN__ ((double)2.2250738585072014e-308L)
#define __DBL_EPSILON__ ((double)2.2204460492503131e-16L)
#define __DBL_DENORM_MIN__ ((double)4.9406564584124654e-324L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 53
#define __LDBL_DIG__ 15
#define __LDBL_MIN_EXP__ (-1021)
#define __LDBL_MIN_10_EXP__ (-307)
#define __LDBL_MAX_EXP__ 1024
#define __LDBL_MAX_10_EXP__ 308
#define __DECIMAL_DIG__ 17
#define __LDBL_DECIMAL_DIG__ 17
#define __LDBL_MAX__ 1.7976931348623157e+308L
#define __LDBL_NORM_MAX__ 1.7976931348623157e+308L
#define __LDBL_MIN__ 2.2250738585072014e-308L
#define __LDBL_EPSILON__ 2.2204460492503131e-16L
#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT32_DIG__ 6
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_MAX__ 3.4028234663852886e+38F32
#define __FLT32_NORM_MAX__ 3.4028234663852886e+38F32
#define __FLT32_MIN__ 1.1754943508222875e-38F32
#define __FLT32_EPSILON__ 1.1920928955078125e-7F32
#define __FLT32_DENORM_MIN__ 1.4012984643248171e-45F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT64_MANT_DIG__ 53
#define __FLT64_DIG__ 15
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_MAX__ 1.7976931348623157e+308F64
#define __FLT64_NORM_MAX__ 1.7976931348623157e+308F64
#define __FLT64_MIN__ 2.2250738585072014e-308F64
#define __FLT64_EPSILON__ 2.2204460492503131e-16F64
#define __FLT64_DENORM_MIN__ 4.9406564584124654e-324F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_DIG__ 15
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_MAX__ 1.7976931348623157e+308F32x
#define __FLT32X_NORM_MAX__ 1.7976931348623157e+308F32x
#define __FLT32X_MIN__ 2.2250738585072014e-308F32x
#define __FLT32X_EPSILON__ 2.2204460492503131e-16F32x
#define __FLT32X_DENORM_MIN__ 4.9406564584124654e-324F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __SFRACT_FBIT__ 7
#define __SFRACT_IBIT__ 0
#define __SFRACT_MIN__ (-0.5HR-0.5HR)
#define __SFRACT_MAX__ 0X7FP-7HR
#define __SFRACT_EPSILON__ 0x1P-7HR
#define __USFRACT_FBIT__ 8
#define __USFRACT_IBIT__ 0
#define __USFRACT_MIN__ 0.0UHR
#define __USFRACT_MAX__ 0XFFP-8UHR
#define __USFRACT_EPSILON__ 0x1P-8UHR
#define __FRACT_FBIT__ 15
#define __FRACT_IBIT__ 0
#define __FRACT_MIN__ (-0.5R-0.5R)
#define __FRACT_MAX__ 0X7FFFP-15R
#define __FRACT_EPSILON__ 0x1P-15R
#define __UFRACT_FBIT__ 16
#define __UFRACT_IBIT__ 0
#define __UFRACT_MIN__ 0.0UR
#define __UFRACT_MAX__ 0XFFFFP-16UR
#define __UFRACT_EPSILON__ 0x1P-16UR
#define __LFRACT_FBIT__ 31
#define __LFRACT_IBIT__ 0
#define __LFRACT_MIN__ (-0.5LR-0.5LR)
#define __LFRACT_MAX__ 0X7FFFFFFFP-31LR
#define __LFRACT_EPSILON__ 0x1P-31LR
#define __ULFRACT_FBIT__ 32
#define __ULFRACT_IBIT__ 0
#define __ULFRACT_MIN__ 0.0ULR
#define __ULFRACT_MAX__ 0XFFFFFFFFP-32ULR
#define __ULFRACT_EPSILON__ 0x1P-32ULR
#define __LLFRACT_FBIT__ 63
#define __LLFRACT_IBIT__ 0
#define __LLFRACT_MIN__ (-0.5LLR-0.5LLR)
#define __LLFRACT_MAX__ 0X7FFFFFFFFFFFFFFFP-63LLR
#define __LLFRACT_EPSILON__ 0x1P-63LLR
#define __ULLFRACT_FBIT__ 64
#define __ULLFRACT_IBIT__ 0
#define __ULLFRACT_MIN__ 0.0ULLR
#define __ULLFRACT_MAX__ 0XFFFFFFFFFFFFFFFFP-64ULLR
#define __ULLFRACT_EPSILON__ 0x1P-64ULLR
#define __SACCUM_FBIT__ 7
#define __SACCUM_IBIT__ 8
#define __SACCUM_MIN__ (-0X1P7HK-0X1P7HK)
#define __SACCUM_MAX__ 0X7FFFP-7HK
#define __SACCUM_EPSILON__ 0x1P-7HK
#define __USACCUM_FBIT__ 8
#define __USACCUM_IBIT__ 8
#define __USACCUM_MIN__ 0.0UHK
#define __USACCUM_MAX__ 0XFFFFP-8UHK
#define __USACCUM_EPSILON__ 0x1P-8UHK
#define __ACCUM_FBIT__ 15
#define __ACCUM_IBIT__ 16
#define __ACCUM_MIN__ (-0X1P15K-0X1P15K)
#define __ACCUM_MAX__ 0X7FFFFFFFP-15K
#define __ACCUM_EPSILON__ 0x1P-15K
#define __UACCUM_FBIT__ 16
#define __UACCUM_IBIT__ 16
#define __UACCUM_MIN__ 0.0UK
#define __UACCUM_MAX__ 0XFFFFFFFFP-16UK
#define __UACCUM_EPSILON__ 0x1P-16UK
#define __LACCUM_FBIT__ 31
#define __LACCUM_IBIT__ 32
#define __LACCUM_MIN__ (-0X1P31LK-0X1P31LK)
#define __LACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LK
#define __LACCUM_EPSILON__ 0x1P-31LK
#define __ULACCUM_FBIT__ 32
#define __ULACCUM_IBIT__ 32
#define __ULACCUM_MIN__ 0.0ULK
#define __ULACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULK
#define __ULACCUM_EPSILON__ 0x1P-32ULK
#define __LLACCUM_FBIT__ 31
#define __LLACCUM_IBIT__ 32
#define __LLACCUM_MIN__ (-0X1P31LLK-0X1P31LLK)
#define __LLACCUM_MAX__ 0X7FFFFFFFFFFFFFFFP-31LLK
#define __LLACCUM_EPSILON__ 0x1P-31LLK
#define __ULLACCUM_FBIT__ 32
#define __ULLACCUM_IBIT__ 32
#define __ULLACCUM_MIN__ 0.0ULLK
#define __ULLACCUM_MAX__ 0XFFFFFFFFFFFFFFFFP-32ULLK
#define __ULLACCUM_EPSILON__ 0x1P-32ULLK
#define __QQ_FBIT__ 7
#define __QQ_IBIT__ 0
#define __HQ_FBIT__ 15
#define __HQ_IBIT__ 0
#define __SQ_FBIT__ 31
#define __SQ_IBIT__ 0
#define __DQ_FBIT__ 63
#define __DQ_IBIT__ 0
#define __TQ_FBIT__ 127
#define __TQ_IBIT__ 0
#define __UQQ_FBIT__ 8
#define __UQQ_IBIT__ 0
#define __UHQ_FBIT__ 16
#define __UHQ_IBIT__ 0
#define __USQ_FBIT__ 32
#define __USQ_IBIT__ 0
#define __UDQ_FBIT__ 64
#define __UDQ_IBIT__ 0
#define __UTQ_FBIT__ 128
#define __UTQ_IBIT__ 0
#define __HA_FBIT__ 7
#define __HA_IBIT__ 8
#define __SA_FBIT__ 15
#define __SA_IBIT__ 16
#define __DA_FBIT__ 31
#define __DA_IBIT__ 32
#define __TA_FBIT__ 63
#define __TA_IBIT__ 64
#define __UHA_FBIT__ 8
#define __UHA_IBIT__ 8
#define __USA_FBIT__ 16
#define __USA_IBIT__ 16
#define __UDA_FBIT__ 32
#define __UDA_IBIT__ 32
#define __UTA_FBIT__ 64
#define __UTA_IBIT__ 64
#define __REGISTER_PREFIX__ 
#define __USER_LABEL_PREFIX__ 
#define __GNUC_STDC_INLINE__ 1
#define __STRICT_ANSI__ 1
#define __CHAR_UNSIGNED__ 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#define __ARM_FEATURE_DSP 1
#define __ARM_FEATURE_QBIT 1
#define __ARM_FEATURE_SAT 1
#undef __ARM_FEATURE_CRYPTO
# 1 "<built-in>"
#define __ARM_FEATURE_UNALIGNED 1
#undef __ARM_FEATURE_QRDMX
# 1 "<built-in>"
#undef __ARM_FEATURE_CRC32
# 1 "<built-in>"
#undef __ARM_FEATURE_DOTPROD
# 1 "<built-in>"
#undef __ARM_FEATURE_COMPLEX
# 1 "<built-in>"
#define __ARM_32BIT_STATE 1
#undef __ARM_FEATURE_MVE
# 1 "<built-in>"
#undef __ARM_FEATURE_CMSE
# 1 "<built-in>"
#undef __ARM_FEATURE_LDREX
# 1 "<built-in>"
#define __ARM_FEATURE_LDREX 7
#define __ARM_FEATURE_CLZ 1
#undef __ARM_FEATURE_NUMERIC_MAXMIN
# 1 "<built-in>"
#define __ARM_FEATURE_SIMD32 1
#define __ARM_SIZEOF_MINIMAL_ENUM 1
#define __ARM_SIZEOF_WCHAR_T 4
#undef __ARM_ARCH_PROFILE
# 1 "<built-in>"
#define __ARM_ARCH_PROFILE 77
#define __arm__ 1
#undef __ARM_ARCH
# 1 "<built-in>"
#define __ARM_ARCH 7
#define __APCS_32__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __thumb__ 1
#define __thumb2__ 1
#define __THUMBEL__ 1
#undef __ARM_ARCH_ISA_THUMB
# 1 "<built-in>"
#define __ARM_ARCH_ISA_THUMB 2
#define __ARMEL__ 1
#define __SOFTFP__ 1
#define __VFP_FP__ 1
#undef __ARM_FP
# 1 "<built-in>"
#undef __ARM_FP16_FORMAT_IEEE
# 1 "<built-in>"
#undef __ARM_FP16_FORMAT_ALTERNATIVE
# 1 "<built-in>"
#undef __ARM_FP16_ARGS
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_SCALAR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_VECTOR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_FP16_FML
# 1 "<built-in>"
#define __ARM_FEATURE_FMA 1
#undef __ARM_NEON__
# 1 "<built-in>"
#undef __ARM_NEON
# 1 "<built-in>"
#undef __ARM_NEON_FP
# 1 "<built-in>"
#define __THUMB_INTERWORK__ 1
#define __ARM_ARCH_7EM__ 1
#define __ARM_PCS 1
#define __ARM_EABI__ 1
#undef __FDPIC__
# 1 "<built-in>"
#define __ARM_ARCH_EXT_IDIV__ 1
#define __ARM_FEATURE_IDIV 1
#define __ARM_ASM_SYNTAX_UNIFIED__ 1
#undef __ARM_FEATURE_COPROC
# 1 "<built-in>"
#define __ARM_FEATURE_COPROC 15
#undef __ARM_FEATURE_CDE
# 1 "<built-in>"
#undef __ARM_FEATURE_CDE_COPROC
# 1 "<built-in>"
#undef __ARM_FEATURE_MATMUL_INT8
# 1 "<built-in>"
#undef __ARM_FEATURE_BF16_SCALAR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_FEATURE_BF16_VECTOR_ARITHMETIC
# 1 "<built-in>"
#undef __ARM_BF16_FORMAT_ALTERNATIVE
# 1 "<built-in>"
#define __GXX_TYPEINFO_EQUALITY_INLINE 0
#define __ELF__ 1
# 1 "<command-line>"
#define __USES_INITFINI__ 1
#define stm32wle5xx 1
#define SUPPORT_LORA 1
#define SUPPORT_LORA_P2P 1
#define LORA_IO_SPI_PORT 2
#define SYS_RTC_COUNTER_PORT 2
#define ATCMD_CUST_TABLE_SIZE 64
#define WAN_TYPE 0
#define LORA_STACK_VER 0x040407
#define RAK3372 +RAK5005-O_V1.0 1
#define rak3172 1
#define CORE_CM4 1
#define USE_HAL_DRIVER 1
#define STM32WLE5xx 1
#define REGION_AS923 1
#define REGION_AU915 1
#define REGION_CN470 1
#define REGION_CN779 1
#define REGION_EU433 1
#define REGION_EU868 1
#define REGION_KR920 1
#define REGION_IN865 1
#define REGION_US915 1
#define REGION_RU864 1
#define REGION_LA915 1
#define SOFT_SE 1
#define SECURE_ELEMENT_PRE_PROVISIONED 1
#define LORAMAC_CLASSB_ENABLED 1
#define WISBLOCK_BASE_5005_O 1
#define SUPPORT_SPI 1
#define SUPPORT_AT 1
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
# 20 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 1 3


#define _MATH_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 1 3
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _SYS_REENT_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 1 3







#define __NEWLIB_H__ 1





# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_newlib_version.h" 1 3



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 2 3



#define _WANT_IO_C99_FORMATS 1


#define _WANT_IO_LONG_LONG 1


#define _WANT_REGISTER_FINI 1
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _REENT_CHECK_VERIFY 1





#define _MB_LEN_MAX 1
# 53 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define HAVE_INITFINI_ARRAY 1



#define _ATEXIT_DYNAMIC_ALLOC 1


#define _HAVE_LONG_DOUBLE 1


#define _HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1


#define _LDBL_EQ_DBL 1


#define _FVWRITE_IN_STREAMIO 1


#define _FSEEK_OPTIMIZATION 1


#define _WIDE_ORIENT 1


#define _UNBUF_STREAM_OPT 1
# 95 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _RETARGETABLE_LOCKING 1
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 1 3

#define __SYS_CONFIG_H__ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 77 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __IEEE_LITTLE_ENDIAN 
# 473 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __OBSOLETE_MATH_DEFAULT 1


#define __OBSOLETE_MATH __OBSOLETE_MATH_DEFAULT
# 5 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 1 3
# 22 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define _SYS_FEATURES_H 
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __XSI_VISIBLE 0
# 330 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3
#define __SSP_FORTIFY_LEVEL 0
# 6 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 2 3
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define _POINTER_INT long





#undef __RAND_MAX



#define __RAND_MAX 0x7fffffff
# 250 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define __EXPORT 



#define __IMPORT 






#define _READ_WRITE_RETURN_TYPE int





#define _READ_WRITE_BUFSIZE_TYPE int
# 12 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
# 31 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _BEGIN_STD_C 
#define _END_STD_C 
#define _NOTHROW 



#define _LONG_DOUBLE long double





#define _ATTRIBUTE(attrs) __attribute__ (attrs)
# 69 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _ELIDABLE_INLINE static __inline__



#define _NOINLINE __attribute__ ((__noinline__))
#define _NOINLINE_STATIC _NOINLINE static
# 14 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 39 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 
# 131 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 
#define _PTRDIFF_T_DECLARED 




# 143 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 181 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define __size_t__ 
#define __SIZE_T__ 
#define _SIZE_T 
#define _SYS_SIZE_T_H 
#define _T_SIZE_ 
#define _T_SIZE 
#define __SIZE_T 
#define _SIZE_T_ 
#define _BSD_SIZE_T_ 
#define _SIZE_T_DEFINED_ 
#define _SIZE_T_DEFINED 
#define _BSD_SIZE_T_DEFINED_ 
#define _SIZE_T_DECLARED 
#define ___int_size_t_h 
#define _GCC_SIZE_T 
#define _SIZET_ 






#define __size_t 





typedef unsigned int size_t;
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 260 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define __wchar_t__ 
#define __WCHAR_T__ 
#define _WCHAR_T 
#define _T_WCHAR_ 
#define _T_WCHAR 
#define __WCHAR_T 
#define _WCHAR_T_ 
#define _BSD_WCHAR_T_ 
#define _WCHAR_T_DEFINED_ 
#define _WCHAR_T_DEFINED 
#define _WCHAR_T_H 
#define ___int_wchar_t_h 
#define __INT_WCHAR_T_H 
#define _GCC_WCHAR_T 
#define _WCHAR_T_DECLARED 
# 287 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef _BSD_WCHAR_T_
# 321 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 1 3
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define _SYS__TYPES_H 

#define __need_size_t 
#define __need_wint_t 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t




#define _WINT_T 




typedef unsigned int wint_t;

#undef __need_wint_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 25 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_types.h" 1 3





#define _MACHINE__TYPES_H 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 1 3





#define _MACHINE__DEFAULT_TYPES_H 
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#define __EXP(x) __ ##x ##__
# 26 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#define __have_longlong64 1






#define __have_long32 1







typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3
#undef __EXP
# 8 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_types.h" 2 3
# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


typedef long __blkcnt_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;



typedef long _off_t;





typedef int __pid_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



typedef __uint32_t __id_t;







typedef unsigned short __ino_t;
# 90 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;
# 127 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#undef __size_t



typedef unsigned int __size_t;
# 146 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define unsigned signed
typedef signed int _ssize_t;
#undef unsigned
# 158 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;




typedef void *_iconv_t;



#define _CLOCK_T_ unsigned long


typedef unsigned long __clock_t;




#define _TIME_T_ __int_least64_t

typedef __int_least64_t __time_t;


#define _CLOCKID_T_ unsigned long


typedef unsigned long __clockid_t;

#define _TIMER_T_ unsigned long
typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3

#define _NULL 0



#define __Long long
typedef unsigned long __ULong;
# 34 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 1 3

#define __SYS_LOCK_H__ 
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 3
struct __lock;
typedef struct __lock * _LOCK_T;
#define _LOCK_RECURSIVE_T _LOCK_T

#define __LOCK_INIT(class,lock) extern struct __lock __lock_ ## lock; class _LOCK_T lock = &__lock_ ## lock

#define __LOCK_INIT_RECURSIVE(class,lock) __LOCK_INIT(class,lock)

extern void __retarget_lock_init(_LOCK_T *lock);
#define __lock_init(lock) __retarget_lock_init(&lock)
extern void __retarget_lock_init_recursive(_LOCK_T *lock);
#define __lock_init_recursive(lock) __retarget_lock_init_recursive(&lock)
extern void __retarget_lock_close(_LOCK_T lock);
#define __lock_close(lock) __retarget_lock_close(lock)
extern void __retarget_lock_close_recursive(_LOCK_T lock);
#define __lock_close_recursive(lock) __retarget_lock_close_recursive(lock)
extern void __retarget_lock_acquire(_LOCK_T lock);
#define __lock_acquire(lock) __retarget_lock_acquire(lock)
extern void __retarget_lock_acquire_recursive(_LOCK_T lock);
#define __lock_acquire_recursive(lock) __retarget_lock_acquire_recursive(lock)
extern int __retarget_lock_try_acquire(_LOCK_T lock);
#define __lock_try_acquire(lock) __retarget_lock_try_acquire(lock)
extern int __retarget_lock_try_acquire_recursive(_LOCK_T lock);
#define __lock_try_acquire_recursive(lock) __retarget_lock_try_acquire_recursive(lock)

extern void __retarget_lock_release(_LOCK_T lock);
#define __lock_release(lock) __retarget_lock_release(lock)
extern void __retarget_lock_release_recursive(_LOCK_T lock);
#define __lock_release_recursive(lock) __retarget_lock_release_recursive(lock)
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
typedef _LOCK_T _flock_t;







struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};





#define _ATEXIT_SIZE 32

struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};
# 98 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
#define _ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL}, 0, 0}}





#define _REENT_INIT_ATEXIT _NULL, _ATEXIT_INIT,
# 122 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 183 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_SMALL_CHECK_INIT(ptr) 


struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 292 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 317 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _RAND48_SEED_0 (0x330e)
#define _RAND48_SEED_1 (0xabcd)
#define _RAND48_SEED_2 (0x1234)
#define _RAND48_MULT_0 (0xe66d)
#define _RAND48_MULT_1 (0xdeec)
#define _RAND48_MULT_2 (0x0005)
#define _RAND48_ADD (0x000b)
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};


#define _REENT_EMERGENCY_SIZE 25
#define _REENT_ASCTIME_SIZE 26
#define _REENT_SIGNAL_SIZE 24
# 613 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {
#define _N_LISTS 30
          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};





#define _REENT_STDIO_STREAM(var,index) &(var)->__sf[index]


#define _REENT_INIT(var) { 0, _REENT_STDIO_STREAM(&(var), 0), _REENT_STDIO_STREAM(&(var), 1), _REENT_STDIO_STREAM(&(var), 2), 0, "", 0, _NULL, 0, _NULL, _NULL, 0, _NULL, _NULL, 0, _NULL, { { 0, _NULL, "", {0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 1, { {_RAND48_SEED_0, _RAND48_SEED_1, _RAND48_SEED_2}, {_RAND48_MULT_0, _RAND48_MULT_1, _RAND48_MULT_2}, _RAND48_ADD }, {0, {0}}, {0, {0}}, {0, {0}}, "", "", 0, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}} } }, _REENT_INIT_ATEXIT _NULL, {_NULL, 0, _NULL} }
# 751 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_INIT_PTR_ZEROED(var) { (var)->_stdin = _REENT_STDIO_STREAM(var, 0); (var)->_stdout = _REENT_STDIO_STREAM(var, 1); (var)->_stderr = _REENT_STDIO_STREAM(var, 2); (var)->_new._reent._rand_next = 1; (var)->_new._reent._r48._seed[0] = _RAND48_SEED_0; (var)->_new._reent._r48._seed[1] = _RAND48_SEED_1; (var)->_new._reent._r48._seed[2] = _RAND48_SEED_2; (var)->_new._reent._r48._mult[0] = _RAND48_MULT_0; (var)->_new._reent._r48._mult[1] = _RAND48_MULT_1; (var)->_new._reent._r48._mult[2] = _RAND48_MULT_2; (var)->_new._reent._r48._add = _RAND48_ADD; }
# 765 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_CHECK_RAND48(ptr) 
#define _REENT_CHECK_MP(ptr) 
#define _REENT_CHECK_TM(ptr) 
#define _REENT_CHECK_ASCTIME_BUF(ptr) 
#define _REENT_CHECK_EMERGENCY(ptr) 
#define _REENT_CHECK_MISC(ptr) 
#define _REENT_CHECK_SIGNAL_BUF(ptr) 

#define _REENT_SIGNGAM(ptr) ((ptr)->_new._reent._gamma_signgam)
#define _REENT_RAND_NEXT(ptr) ((ptr)->_new._reent._rand_next)
#define _REENT_RAND48_SEED(ptr) ((ptr)->_new._reent._r48._seed)
#define _REENT_RAND48_MULT(ptr) ((ptr)->_new._reent._r48._mult)
#define _REENT_RAND48_ADD(ptr) ((ptr)->_new._reent._r48._add)
#define _REENT_MP_RESULT(ptr) ((ptr)->_result)
#define _REENT_MP_RESULT_K(ptr) ((ptr)->_result_k)
#define _REENT_MP_P5S(ptr) ((ptr)->_p5s)
#define _REENT_MP_FREELIST(ptr) ((ptr)->_freelist)
#define _REENT_ASCTIME_BUF(ptr) ((ptr)->_new._reent._asctime_buf)
#define _REENT_TM(ptr) (&(ptr)->_new._reent._localtime_buf)
#define _REENT_EMERGENCY(ptr) ((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr) ((ptr)->_new._reent._strtok_last)
#define _REENT_MBLEN_STATE(ptr) ((ptr)->_new._reent._mblen_state)
#define _REENT_MBTOWC_STATE(ptr) ((ptr)->_new._reent._mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr) ((ptr)->_new._reent._wctomb_state)
#define _REENT_MBRLEN_STATE(ptr) ((ptr)->_new._reent._mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr) ((ptr)->_new._reent._mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_new._reent._mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr) ((ptr)->_new._reent._wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_new._reent._wcsrtombs_state)
#define _REENT_L64A_BUF(ptr) ((ptr)->_new._reent._l64a_buf)
#define _REENT_SIGNAL_BUF(ptr) ((ptr)->_new._reent._signal_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._getdate_err))



#define _REENT_INIT_PTR(var) { memset((var), 0, sizeof(*(var))); _REENT_INIT_PTR_ZEROED(var); }







#define _Kmax (sizeof (size_t) << 3)







#define __ATTRIBUTE_IMPURE_PTR__ 


extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 832 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT _impure_ptr


#define _GLOBAL_REENT _global_impure_ptr





#define _GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)
# 6 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 1 3
# 43 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _SYS_CDEFS_H_ 



# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 48 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 2 3

#define __PMT(args) args
#define __DOTS , ...
#define __THROW 


#define __ASMNAME(cname) __XSTRING (__USER_LABEL_PREFIX__) cname


#define __ptr_t void *
#define __long_double_t long double

#define __attribute_malloc__ 
#define __attribute_pure__ 
#define __attribute_format_strfmon__(a,b) 
#define __flexarr [0]


#define __bounded 
#define __unbounded 
#define __ptrvalue 
# 78 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __has_extension __has_feature


#define __has_feature(x) 0
# 94 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __BEGIN_DECLS 
#define __END_DECLS 
# 107 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __GNUCLIKE_ASM 3
#define __GNUCLIKE_MATH_BUILTIN_CONSTANTS 



#define __GNUCLIKE___TYPEOF 1
#define __GNUCLIKE___OFFSETOF 1
#define __GNUCLIKE___SECTION 1


#define __GNUCLIKE_CTOR_SECTION_HANDLING 1


#define __GNUCLIKE_BUILTIN_CONSTANT_P 1






#define __GNUCLIKE_BUILTIN_VARARGS 1
#define __GNUCLIKE_BUILTIN_STDARG 1
#define __GNUCLIKE_BUILTIN_VAALIST 1



#define __GNUC_VA_LIST_COMPATIBILITY 1






#define __compiler_membar() __asm __volatile(" " : : : "memory")



#define __GNUCLIKE_BUILTIN_NEXT_ARG 1
#define __GNUCLIKE_MATH_BUILTIN_RELOPS 


#define __GNUCLIKE_BUILTIN_MEMCPY 1


#define __CC_SUPPORTS_INLINE 1
#define __CC_SUPPORTS___INLINE 1
#define __CC_SUPPORTS___INLINE__ 1

#define __CC_SUPPORTS___FUNC__ 1
#define __CC_SUPPORTS_WARNING 1

#define __CC_SUPPORTS_VARADIC_XXX 1

#define __CC_SUPPORTS_DYNAMIC_ARRAY_INIT 1
# 177 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __P(protos) protos
#define __CONCAT1(x,y) x ## y
#define __CONCAT(x,y) __CONCAT1(x,y)
#define __STRING(x) #x
#define __XSTRING(x) __STRING(x)

#define __const const
#define __signed signed
#define __volatile volatile
# 230 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __weak_symbol __attribute__((__weak__))
# 243 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __dead2 __attribute__((__noreturn__))
#define __pure2 __attribute__((__const__))
#define __unused __attribute__((__unused__))
#define __used __attribute__((__used__))
#define __packed __attribute__((__packed__))
#define __aligned(x) __attribute__((__aligned__(x)))
#define __section(x) __attribute__((__section__(x)))


#define __alloc_size(x) __attribute__((__alloc_size__(x)))
#define __alloc_size2(n,x) __attribute__((__alloc_size__(n, x)))





#define __alloc_align(x) __attribute__((__alloc_align__(x)))
# 280 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Alignas(x) __aligned(x)






#define _Alignof(x) __alignof(x)
# 296 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Atomic(T) struct { T volatile __val; }





#define _Noreturn __dead2
# 331 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Thread_local __thread
# 351 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __generic(expr,t,yes,no) __builtin_choose_expr( __builtin_types_compatible_p(__typeof(expr), t), yes, no)
# 366 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __min_size(x) static (x)





#define __malloc_like __attribute__((__malloc__))
#define __pure __attribute__((__pure__))






#define __always_inline __inline__ __attribute__((__always_inline__))





#define __noinline __attribute__ ((__noinline__))





#define __nonnull(x) __attribute__((__nonnull__ x))
#define __nonnull_all __attribute__((__nonnull__))






#define __fastcall __attribute__((__fastcall__))
#define __result_use_check __attribute__((__warn_unused_result__))






#define __returns_twice __attribute__((__returns_twice__))





#define __unreachable() __builtin_unreachable()
# 434 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __restrict restrict
# 467 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __predict_true(exp) __builtin_expect((exp), 1)
#define __predict_false(exp) __builtin_expect((exp), 0)






#define __null_sentinel __attribute__((__sentinel__))
#define __exported __attribute__((__visibility__("default")))


#define __hidden __attribute__((__visibility__("hidden")))
# 489 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __offsetof(type,field) offsetof(type, field)
#define __rangeof(type,start,end) (__offsetof(type, end) - __offsetof(type, start))
# 500 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __containerof(x,s,m) ({ const volatile __typeof(((s *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volatile char *)__x - __offsetof(s, m));})
# 522 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))

#define __format_arg(fmtarg) __attribute__((__format_arg__ (fmtarg)))
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))

#define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
# 539 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printf0like(fmtarg,firstvararg) 




#define __strong_reference(sym,aliassym) extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))




#define __weak_reference(sym,alias) __asm__(".weak " #alias); __asm__(".equ " #alias ", " #sym)


#define __warn_references(sym,msg) __asm__(".section .gnu.warning." #sym); __asm__(".asciz \"" msg "\""); __asm__(".previous")



#define __sym_compat(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@" #verid)

#define __sym_default(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@@" #verid)
# 593 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __FBSDID(s) struct __hack



#define __RCSID(s) struct __hack



#define __RCSID_SOURCE(s) struct __hack



#define __SCCSID(s) struct __hack



#define __COPYRIGHT(s) struct __hack



#define __DECONST(type,var) ((type)(__uintptr_t)(const void *)(var))



#define __DEVOLATILE(type,var) ((type)(__uintptr_t)(volatile void *)(var))



#define __DEQUALIFY(type,var) ((type)(__uintptr_t)(const volatile void *)(var))






#define _Nonnull 
#define _Nullable 
#define _Null_unspecified 
#define __NULLABILITY_PRAGMA_PUSH 
#define __NULLABILITY_PRAGMA_POP 
# 653 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __arg_type_tag(arg_kind,arg_idx,type_tag_idx) 
#define __datatype_type_tag(kind,type) 
# 672 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __lock_annotate(x) 





#define __lockable __lock_annotate(lockable)


#define __locks_exclusive(...) __lock_annotate(exclusive_lock_function(__VA_ARGS__))

#define __locks_shared(...) __lock_annotate(shared_lock_function(__VA_ARGS__))



#define __trylocks_exclusive(...) __lock_annotate(exclusive_trylock_function(__VA_ARGS__))

#define __trylocks_shared(...) __lock_annotate(shared_trylock_function(__VA_ARGS__))



#define __unlocks(...) __lock_annotate(unlock_function(__VA_ARGS__))


#define __asserts_exclusive(...) __lock_annotate(assert_exclusive_lock(__VA_ARGS__))

#define __asserts_shared(...) __lock_annotate(assert_shared_lock(__VA_ARGS__))



#define __requires_exclusive(...) __lock_annotate(exclusive_locks_required(__VA_ARGS__))

#define __requires_shared(...) __lock_annotate(shared_locks_required(__VA_ARGS__))

#define __requires_unlocked(...) __lock_annotate(locks_excluded(__VA_ARGS__))



#define __no_lock_analysis __lock_annotate(no_thread_safety_analysis)


#define __guarded_by(x) __lock_annotate(guarded_by(x))
#define __pt_guarded_by(x) __lock_annotate(pt_guarded_by(x))
# 7 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 8 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3
# 9 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 2 3




#define _M_LN2 0.693147180559945309417





#define HUGE_VAL (__builtin_huge_val())



#define HUGE_VALF (__builtin_huge_valf())



#define HUGE_VALL (__builtin_huge_vall())



#define INFINITY (__builtin_inff())



#define NAN (__builtin_nanf(""))
# 86 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);






extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);
# 145 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#define __TMP_FLT_EVAL_METHOD 



    typedef float float_t;
    typedef double double_t;
# 168 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
#undef FLT_EVAL_METHOD


#define FP_NAN 0
#define FP_INFINITE 1
#define FP_ZERO 2
#define FP_SUBNORMAL 3
#define FP_NORMAL 4


#define FP_ILOGB0 (-__INT_MAX__)


#define FP_ILOGBNAN __INT_MAX__



#define MATH_ERRNO 1


#define MATH_ERREXCEPT 2


#define math_errhandling MATH_ERRNO


extern int __isinff (float x);
extern int __isinfd (double x);
extern int __isnanf (float x);
extern int __isnand (double x);
extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);
# 211 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
#define fpclassify(__x) (__builtin_fpclassify (FP_NAN, FP_INFINITE, FP_NORMAL, FP_SUBNORMAL, FP_ZERO, __x))



#define isfinite(__x) (__builtin_isfinite (__x))


#define isinf(__x) (__builtin_isinf_sign (__x))


#define isnan(__x) (__builtin_isnan (__x))

#define isnormal(__x) (__builtin_isnormal (__x))
# 244 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
#define signbit(__x) ((sizeof(__x) == sizeof(float)) ? __builtin_signbitf(__x) : (sizeof(__x) == sizeof(double)) ? __builtin_signbit (__x) : __builtin_signbitl(__x))
# 260 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
#define isgreater(__x,__y) (__builtin_isgreater (__x, __y))
#define isgreaterequal(__x,__y) (__builtin_isgreaterequal (__x, __y))
#define isless(__x,__y) (__builtin_isless (__x, __y))
#define islessequal(__x,__y) (__builtin_islessequal (__x, __y))
#define islessgreater(__x,__y) (__builtin_islessgreater (__x, __y))
#define isunordered(__x,__y) (__builtin_isunordered (__x, __y))
# 290 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
extern double infinity (void);
extern double nan (const char *);
extern double copysign (double, double);
extern double logb (double);
extern int ilogb (double);

extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);

extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern long long int llrint (double);
extern double round (double);
extern long int lround (double);
extern long long int llround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);


extern double log1p (double);
extern double expm1 (double);



extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double lgamma (double);
extern double erf (double);
extern double erfc (double);
extern double log2 (double);

#define log2(x) (log (x) / _M_LN2)



extern double hypot (double, double);






extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);


extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);




extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern long long int llrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern long long int llroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);

extern float infinityf (void);
extern float nanf (const char *);
extern float copysignf (float, float);
extern float logbf (float);
extern int ilogbf (float);

extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);


extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float lgammaf (float);
extern float erff (float);
extern float erfcf (float);
extern float log2f (float);
extern float hypotf (float, float);
# 422 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3
extern long double atanl (long double);
extern long double cosl (long double);
extern long double sinl (long double);
extern long double tanl (long double);
extern long double tanhl (long double);
extern long double frexpl (long double, int *);
extern long double modfl (long double, long double *);
extern long double ceill (long double);
extern long double fabsl (long double);
extern long double floorl (long double);
extern long double log1pl (long double);
extern long double expm1l (long double);




extern long double acosl (long double);
extern long double asinl (long double);
extern long double atan2l (long double, long double);
extern long double coshl (long double);
extern long double sinhl (long double);
extern long double expl (long double);
extern long double ldexpl (long double, int);
extern long double logl (long double);
extern long double log10l (long double);
extern long double powl (long double, long double);
extern long double sqrtl (long double);
extern long double fmodl (long double, long double);
extern long double hypotl (long double, long double);


extern long double copysignl (long double, long double);
extern long double nanl (const char *);
extern int ilogbl (long double);
extern long double asinhl (long double);
extern long double cbrtl (long double);
extern long double nextafterl (long double, long double);
extern float nexttowardf (float, long double);
extern double nexttoward (double, long double);
extern long double nexttowardl (long double, long double);
extern long double logbl (long double);
extern long double log2l (long double);
extern long double rintl (long double);
extern long double scalbnl (long double, int);
extern long double exp2l (long double);
extern long double scalblnl (long double, long);
extern long double tgammal (long double);
extern long double nearbyintl (long double);
extern long int lrintl (long double);
extern long long int llrintl (long double);
extern long double roundl (long double);
extern long lroundl (long double);
extern long long int llroundl (long double);
extern long double truncl (long double);
extern long double remquol (long double, long double, int *);
extern long double fdiml (long double, long double);
extern long double fmaxl (long double, long double);
extern long double fminl (long double, long double);
extern long double fmal (long double, long double, long double);

extern long double acoshl (long double);
extern long double atanhl (long double);
extern long double remainderl (long double, long double);
extern long double lgammal (long double);
extern long double erfl (long double);
extern long double erfcl (long double);
# 623 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/math.h" 3

# 21 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define __UTILITIES_H__ 






# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 1 3 4
# 9 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _SYS__INTSUP_H 





#define __STDINT_EXP(x) __ ##x ##__
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef __int20
#undef __int20__
#undef long
#define signed +0
#define unsigned +0
#define char +0
#define short +1
#define __int20 +2
#define __int20__ +2
#define int +2
#define long +4
# 67 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _INTPTR_EQ_INT 






#define _INT32_EQ_LONG 







#define __INT8 "hh"
# 93 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT16 "h"
# 104 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT32 "l"
# 113 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT64 "ll"






#define __FAST8 
# 129 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST16 






#define __FAST32 
# 147 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST64 "ll"



#define __LEAST8 "hh"
# 162 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST16 "h"
# 173 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST32 "l"
# 182 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST64 "ll"

#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef long
       
       
       
       
       
# 194 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20
       
# 195 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20__
       
       
# 14 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
#define _SYS__STDINT_H 
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
typedef __int8_t int8_t ;
#define _INT8_T_DECLARED 


typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED 

#define __int8_t_defined 1




typedef __int16_t int16_t ;
#define _INT16_T_DECLARED 


typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED 

#define __int16_t_defined 1




typedef __int32_t int32_t ;
#define _INT32_T_DECLARED 


typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED 

#define __int32_t_defined 1




typedef __int64_t int64_t ;
#define _INT64_T_DECLARED 


typedef __uint64_t uint64_t ;
#define _UINT64_T_DECLARED 

#define __int64_t_defined 1



typedef __intmax_t intmax_t;
#define _INTMAX_T_DECLARED 



typedef __uintmax_t uintmax_t;
#define _UINTMAX_T_DECLARED 



typedef __intptr_t intptr_t;
#define _INTPTR_T_DECLARED 



typedef __uintptr_t uintptr_t;
#define _UINTPTR_T_DECLARED 
# 15 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4






typedef __int_least8_t int_least8_t;
typedef __uint_least8_t uint_least8_t;
#define __int_least8_t_defined 1



typedef __int_least16_t int_least16_t;
typedef __uint_least16_t uint_least16_t;
#define __int_least16_t_defined 1



typedef __int_least32_t int_least32_t;
typedef __uint_least32_t uint_least32_t;
#define __int_least32_t_defined 1



typedef __int_least64_t int_least64_t;
typedef __uint_least64_t uint_least64_t;
#define __int_least64_t_defined 1
# 51 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
  typedef int int_fast8_t;
  typedef unsigned int uint_fast8_t;
#define __int_fast8_t_defined 1







  typedef int int_fast16_t;
  typedef unsigned int uint_fast16_t;
#define __int_fast16_t_defined 1







  typedef int int_fast32_t;
  typedef unsigned int uint_fast32_t;
#define __int_fast32_t_defined 1







  typedef long long int int_fast64_t;
  typedef long long unsigned int uint_fast64_t;
#define __int_fast64_t_defined 1
# 128 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTPTR_MIN (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX (__INTPTR_MAX__)
#define UINTPTR_MAX (__UINTPTR_MAX__)
# 152 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT8_MIN (-__INT8_MAX__ - 1)
#define INT8_MAX (__INT8_MAX__)
#define UINT8_MAX (__UINT8_MAX__)







#define INT_LEAST8_MIN (-__INT_LEAST8_MAX__ - 1)
#define INT_LEAST8_MAX (__INT_LEAST8_MAX__)
#define UINT_LEAST8_MAX (__UINT_LEAST8_MAX__)
# 174 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_MIN (-__INT16_MAX__ - 1)
#define INT16_MAX (__INT16_MAX__)
#define UINT16_MAX (__UINT16_MAX__)







#define INT_LEAST16_MIN (-__INT_LEAST16_MAX__ - 1)
#define INT_LEAST16_MAX (__INT_LEAST16_MAX__)
#define UINT_LEAST16_MAX (__UINT_LEAST16_MAX__)
# 196 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_MIN (-__INT32_MAX__ - 1)
#define INT32_MAX (__INT32_MAX__)
#define UINT32_MAX (__UINT32_MAX__)
# 212 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST32_MIN (-__INT_LEAST32_MAX__ - 1)
#define INT_LEAST32_MAX (__INT_LEAST32_MAX__)
#define UINT_LEAST32_MAX (__UINT_LEAST32_MAX__)
# 230 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_MIN (-__INT64_MAX__ - 1)
#define INT64_MAX (__INT64_MAX__)
#define UINT64_MAX (__UINT64_MAX__)
# 246 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST64_MIN (-__INT_LEAST64_MAX__ - 1)
#define INT_LEAST64_MAX (__INT_LEAST64_MAX__)
#define UINT_LEAST64_MAX (__UINT_LEAST64_MAX__)
# 262 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST8_MIN (-__INT_FAST8_MAX__ - 1)
#define INT_FAST8_MAX (__INT_FAST8_MAX__)
#define UINT_FAST8_MAX (__UINT_FAST8_MAX__)
# 278 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST16_MIN (-__INT_FAST16_MAX__ - 1)
#define INT_FAST16_MAX (__INT_FAST16_MAX__)
#define UINT_FAST16_MAX (__UINT_FAST16_MAX__)
# 294 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST32_MIN (-__INT_FAST32_MAX__ - 1)
#define INT_FAST32_MAX (__INT_FAST32_MAX__)
#define UINT_FAST32_MAX (__UINT_FAST32_MAX__)
# 310 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST64_MIN (-__INT_FAST64_MAX__ - 1)
#define INT_FAST64_MAX (__INT_FAST64_MAX__)
#define UINT_FAST64_MAX (__UINT_FAST64_MAX__)
# 326 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_MAX (__INTMAX_MAX__)
#define INTMAX_MIN (-INTMAX_MAX - 1)







#define UINTMAX_MAX (__UINTMAX_MAX__)







#define SIZE_MAX (__SIZE_MAX__)





#define SIG_ATOMIC_MIN (-__STDINT_EXP(INT_MAX) - 1)
#define SIG_ATOMIC_MAX (__STDINT_EXP(INT_MAX))



#define PTRDIFF_MAX (__PTRDIFF_MAX__)



#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)




#define WCHAR_MIN (__WCHAR_MIN__)
# 374 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WCHAR_MAX (__WCHAR_MAX__)
# 384 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WINT_MAX (__WINT_MAX__)




#define WINT_MIN (__WINT_MIN__)






#define INT8_C(x) __INT8_C(x)
#define UINT8_C(x) __UINT8_C(x)
# 408 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_C(x) __INT16_C(x)
#define UINT16_C(x) __UINT16_C(x)
# 420 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_C(x) __INT32_C(x)
#define UINT32_C(x) __UINT32_C(x)
# 433 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_C(x) __INT64_C(x)
#define UINT64_C(x) __UINT64_C(x)
# 449 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_C(x) __INTMAX_C(x)
#define UINTMAX_C(x) __UINTMAX_C(x)
# 10 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 32 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h" 2





#define SUCCESS 1



#define FAIL 0
# 52 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define MIN(a,b) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
# 63 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define MAX(a,b) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )
# 72 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define POW2(n) ( 1 << n )





# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
typedef union Version_u
{
    struct Version_s
    {
        uint8_t Revision;
        uint8_t Patch;
        uint8_t Minor;
        uint8_t Major;
    }Fields;
    uint32_t Value;
}Version_t;






void srand1( uint32_t seed );
# 103 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
int32_t randr( int32_t min, int32_t max );
# 114 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memcpy1( uint8_t *dst, const uint8_t *src, uint16_t size );
# 123 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memcpyr( uint8_t *dst, const uint8_t *src, uint16_t size );
# 134 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memset1( uint8_t *dst, uint8_t value, uint16_t size );







int8_t Nibble2HexChar( uint8_t a );
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32( uint8_t *buffer, uint16_t length );







uint32_t Crc32Init( void );
# 171 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32Update( uint32_t crcInit, uint8_t *buffer, uint16_t length );
# 180 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32Finalize( uint32_t crc );




#define CRITICAL_SECTION_BEGIN() uint32_t mask; BoardCriticalSectionBegin( &mask )




#define CRITICAL_SECTION_END() BoardCriticalSectionEnd( &mask )
# 203 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void BoardCriticalSectionBegin( uint32_t *mask );






void BoardCriticalSectionEnd( uint32_t *mask );
# 22 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h" 1
# 39 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
#define __SECURE_ELEMENT_H__ 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 1
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
#define __LORAMAC_CRYPTO_H__ 






# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 1 3







#define _STDLIB_H_ 

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 11 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3


#define __need_size_t 
#define __need_wchar_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 17 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3



# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/stdlib.h" 1 3

#define _MACHSTDLIB_H_ 
# 21 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 2 3
# 33 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3



# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;



#define __compar_fn_t_defined 
typedef int (*__compar_fn_t) (const void *, const void *);


#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX __RAND_MAX

int __locale_mb_cur_max (void);

#define MB_CUR_MAX __locale_mb_cur_max()

void abort (void) __attribute__ ((__noreturn__));
int abs (int);





int atexit (void (*__func)(void));
double atof (const char *__nptr);



int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void *__key,
         const void *__base,
         size_t __nmemb,
         size_t __size,
         __compar_fn_t _compar);
void *calloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__))
      __attribute__((__alloc_size__(1, 2))) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((__noreturn__));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);



char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);




long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void *malloc(size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(1))) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);
# 137 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void *realloc(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2))) ;
# 159 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
void srand (unsigned __seed);
double strtod (const char *restrict __n, char **restrict __end_PTR);
double _strtod_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR);

float strtof (const char *restrict __n, char **restrict __end_PTR);







long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
# 191 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
int system (const char *__string);
# 202 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
void _Exit (int __status) __attribute__ ((__noreturn__));




int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);



int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
char * __itoa (int, char *, int);
char * __utoa (unsigned, char *, int);
# 263 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
long long atoll (const char *__nptr);

long long _atoll_r (struct _reent *, const char *__nptr);

long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);

long long _strtoll_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long _strtoull_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);
# 284 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
int _unsetenv_r (struct _reent *, const char *__string);







char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);
# 322 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3
extern long double _strtold_r (struct _reent *, const char *restrict, char **restrict);

extern long double strtold (const char *restrict, char **restrict);
# 339 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdlib.h" 3

# 46 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 2

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 1 3 4
# 29 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 1
# 36 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define __LORAMAC_TYPES_H__ 
# 45 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h"
#define __TIMER_H__ 






# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 1
# 44 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
#define UTIL_TIME_SERVER_H__ 
# 58 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 59 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h" 1
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h"
#define __CMSIS_COMPILER_H 
# 54 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h" 1
# 26 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __CMSIS_GCC_H 


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
# 41 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __ASM __asm


#define __INLINE inline


#define __STATIC_INLINE static inline


#define __STATIC_FORCEINLINE __attribute__((always_inline)) static inline


#define __NO_RETURN __attribute__((__noreturn__))


#define __USED __attribute__((used))


#define __WEAK __attribute__((weak))


#define __PACKED __attribute__((packed, aligned(1)))


#define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))


#define __PACKED_UNION union __attribute__((packed, aligned(1)))


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  
# 74 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
 struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop
#define __UNALIGNED_UINT32(x) (((struct T_UINT32 *)(x))->v)


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_WRITE { uint16_t v; };
#pragma GCC diagnostic pop
#define __UNALIGNED_UINT16_WRITE(addr,val) (void)((((struct T_UINT16_WRITE *)(void *)(addr))->v) = (val))


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_READ { uint16_t v; };
#pragma GCC diagnostic pop
#define __UNALIGNED_UINT16_READ(addr) (((const struct T_UINT16_READ *)(const void *)(addr))->v)


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_WRITE { uint32_t v; };
#pragma GCC diagnostic pop
#define __UNALIGNED_UINT32_WRITE(addr,val) (void)((((struct T_UINT32_WRITE *)(void *)(addr))->v) = (val))


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_READ { uint32_t v; };
#pragma GCC diagnostic pop
#define __UNALIGNED_UINT32_READ(addr) (((const struct T_UINT32_READ *)(const void *)(addr))->v)


#define __ALIGNED(x) __attribute__((aligned(x)))


#define __RESTRICT __restrict


#define __COMPILER_BARRIER() __ASM volatile("":::"memory")
# 131 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline __attribute__((__noreturn__)) void __cmsis_start(void)
{
  extern void _start(void) __attribute__((__noreturn__));

  typedef struct {
    uint32_t const* src;
    uint32_t* dest;
    uint32_t wlen;
  } __copy_table_t;

  typedef struct {
    uint32_t* dest;
    uint32_t wlen;
  } __zero_table_t;

  extern const __copy_table_t __copy_table_start__;
  extern const __copy_table_t __copy_table_end__;
  extern const __zero_table_t __zero_table_start__;
  extern const __zero_table_t __zero_table_end__;

  for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = pTable->src[i];
    }
  }

  for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = 0u;
    }
  }

  _start();
}

#define __PROGRAM_START __cmsis_start



#define __INITIAL_SP __StackTop



#define __STACK_LIMIT __StackLimit



#define __VECTOR_TABLE __Vectors



#define __VECTOR_TABLE_ATTRIBUTE __attribute((used, section(".vectors")))
# 196 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 272 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 344 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 368 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 398 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 449 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) :: "memory");
  return(result);
}
# 479 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 506 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri" : "=r" (result) );
  return(result);
}
# 558 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 583 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  __asm volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 624 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 833 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_FPSCR(void)
{
# 849 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  return(0U);

}







__attribute__((always_inline)) static inline void __set_FPSCR(uint32_t fpscr)
{
# 872 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  (void)fpscr;

}
# 894 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __CMSIS_GCC_OUT_REG(r) "=r" (r)
#define __CMSIS_GCC_RW_REG(r) "+r" (r)
#define __CMSIS_GCC_USE_REG(r) "r" (r)






#define __NOP() __ASM volatile ("nop")





#define __WFI() __ASM volatile ("wfi")







#define __WFE() __ASM volatile ("wfe")






#define __SEV() __ASM volatile ("sev")
# 933 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}
# 967 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}
# 986 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return result;
}
# 1001 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline int16_t __REVSH(int16_t value)
{

  return (int16_t)__builtin_bswap16(value);






}
# 1021 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 1039 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __BKPT(value) __ASM volatile ("bkpt "#value)
# 1048 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




   __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
# 1068 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  return result;
}
# 1078 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __CLZ(uint32_t value)
{
# 1089 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 1107 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint8_t) result);
}
# 1129 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint16_t) result);
}
# 1151 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}
# 1168 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1185 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1202 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}






__attribute__((always_inline)) static inline void __CLREX(void)
{
  __asm volatile ("clrex" ::: "memory");
}
# 1236 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __SSAT(ARG1,ARG2) __extension__ ({ int32_t __RES, __ARG1 = (ARG1); __ASM ("ssat %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })
# 1252 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __USAT(ARG1,ARG2) __extension__ ({ uint32_t __RES, __ARG1 = (ARG1); __ASM ("usat %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })
# 1268 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 1283 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint8_t) result);
}
# 1305 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint16_t) result);
}
# 1327 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *ptr)
{
    uint32_t result;

   __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
   return(result);
}
# 1342 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
   __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1354 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
   __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1366 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
   __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
# 1621 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __SADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__((always_inline)) static inline uint32_t __SSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__((always_inline)) static inline uint32_t __SADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __QSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UQSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USAD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usad8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("usada8 %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

#define __SSAT16(ARG1,ARG2) ({ int32_t __RES, __ARG1 = (ARG1); __ASM ("ssat16 %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })






#define __USAT16(ARG1,ARG2) ({ uint32_t __RES, __ARG1 = (ARG1); __ASM ("usat16 %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })






__attribute__((always_inline)) static inline uint32_t __UXTB16(uint32_t op1)
{
  uint32_t result;

  __asm volatile ("uxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SXTB16(uint32_t op1)
{
  uint32_t result;

  __asm volatile ("sxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUAD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuad %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUADX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuadx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLAD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlad %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLADX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smladx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint64_t __SMLALD (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlald %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint64_t __SMLALDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlaldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint32_t __SMUSD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMUSDX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusdx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLSD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsd %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint32_t __SMLSDX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsdx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__((always_inline)) static inline uint64_t __SMLSLD (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlsld %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint64_t __SMLSLDX (uint32_t op1, uint32_t op2, uint64_t acc)
{
  union llreg_u{
    uint32_t w32[2];
    uint64_t w64;
  } llr;
  llr.w64 = acc;


  __asm volatile ("smlsldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );




  return(llr.w64);
}

__attribute__((always_inline)) static inline uint32_t __SEL (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sel %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline int32_t __QADD( int32_t op1, int32_t op2)
{
  int32_t result;

  __asm volatile ("qadd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__((always_inline)) static inline int32_t __QSUB( int32_t op1, int32_t op2)
{
  int32_t result;

  __asm volatile ("qsub %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}
# 2148 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __PKHBT(ARG1,ARG2,ARG3) ( ((((uint32_t)(ARG1)) ) & 0x0000FFFFUL) | ((((uint32_t)(ARG2)) << (ARG3)) & 0xFFFF0000UL) )


#define __PKHTB(ARG1,ARG2,ARG3) ( ((((uint32_t)(ARG1)) ) & 0xFFFF0000UL) | ((((uint32_t)(ARG2)) >> (ARG3)) & 0x0000FFFFUL) )


__attribute__((always_inline)) static inline int32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
 int32_t result;

 __asm volatile ("smmla %0, %1, %2, %3" : "=r" (result): "r" (op1), "r" (op2), "r" (op3) );
 return(result);
}





#pragma GCC diagnostic pop
# 55 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h" 2
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h"
#define __UTILITIES_CONF_H__ 
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h" 1
# 22 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
#define __STM32_MEM_H__ 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h" 1
# 31 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h" 2





#define UTIL_MEM_PLACE_IN_SECTION(__x__) UTIL_PLACE_IN_SECTION( __x__ )
#define UTIL_MEM_ALIGN ALIGN
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_cpy_8( void *dst, const void *src, uint16_t size );
# 56 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_cpyr_8( void *dst, const void *src, uint16_t size );
# 65 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_set_8( void *dst, uint8_t value, uint16_t size );
# 35 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 1
# 21 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"
#define __STM32_TINY_VSNPRINTF_H__ 






# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 1 3 4
# 31 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
#define _STDARG_H 
#define _ANSI_STDARG_H_ 

#undef __need___va_list




#define __GNUC_VA_LIST 

# 40 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;






#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)


#define va_copy(d,s) __builtin_va_copy(d,s)

#define __va_copy(d,s) __builtin_va_copy(d,s)
# 99 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;





#define _VA_LIST_ 


#define _VA_LIST 


#define _VA_LIST_DEFINED 


#define _VA_LIST_T_H 


#define __va_list__ 
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 2
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 1 3







#define _STRING_H_ 






#define __need_size_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 18 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 27 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *restrict, const void *restrict, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *restrict, const char *restrict);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *restrict, const char *restrict);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *restrict, const char *restrict, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);

char *strtok (char *restrict, const char *restrict);

size_t strxfrm (char *restrict, const char *restrict, size_t);
# 86 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *_strdup_r (struct _reent *, const char *);



char *_strndup_r (struct _reent *, const char *, size_t);
# 112 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char * _strerror_r (struct _reent *, int, int, int *);
# 134 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *strsignal (int __signo);
# 175 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/string.h" 1 3
# 176 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3


# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 2
# 54 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"

# 54 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"
int tiny_vsnprintf_like(char *buf, const int size, const char *fmt, va_list args);
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h" 2
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h"
#define VLEVEL_OFF 0
#define VLEVEL_ALWAYS 0

#define VLEVEL_L 1
#define VLEVEL_M 2
#define VLEVEL_H 3

#define TS_OFF 0
#define TS_ON 1

#define T_REG_OFF 0
# 78 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h"
#define UTIL_PLACE_IN_SECTION(__x__) __attribute__((section (__x__)))





#undef ALIGN



#define ALIGN(n) __attribute__((aligned(n)))





#define UTIL_SEQ_INIT_CRITICAL_SECTION() UTILS_INIT_CRITICAL_SECTION()




#define UTIL_SEQ_ENTER_CRITICAL_SECTION() UTILS_ENTER_CRITICAL_SECTION()




#define UTIL_SEQ_EXIT_CRITICAL_SECTION() UTILS_EXIT_CRITICAL_SECTION()




#define UTIL_SEQ_MEMSET8(dest,value,size) UTIL_MEM_set_8( dest, value, size )




#define UTILS_INIT_CRITICAL_SECTION() 




#define UTILS_ENTER_CRITICAL_SECTION() uint32_t primask_bit= __get_PRIMASK(); __disable_irq()





#define UTILS_EXIT_CRITICAL_SECTION() __set_PRIMASK(primask_bit)
# 135 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/utilities_conf.h"
#define UTIL_ADV_TRACE_CONDITIONNAL 
#define UTIL_ADV_TRACE_UNCHUNK_MODE 
#define UTIL_ADV_TRACE_DEBUG(...) 
#define UTIL_ADV_TRACE_INIT_CRITICAL_SECTION() UTILS_INIT_CRITICAL_SECTION()
#define UTIL_ADV_TRACE_ENTER_CRITICAL_SECTION() UTILS_ENTER_CRITICAL_SECTION()
#define UTIL_ADV_TRACE_EXIT_CRITICAL_SECTION() UTILS_EXIT_CRITICAL_SECTION()
#define UTIL_ADV_TRACE_TMP_BUF_SIZE (512U)
#define UTIL_ADV_TRACE_TMP_MAX_TIMESTMAP_SIZE (15U)
#define UTIL_ADV_TRACE_FIFO_SIZE (1024U)
#define UTIL_ADV_TRACE_MEMSET8(dest,value,size) UTIL_MEM_set_8((dest),(value),(size))
#define UTIL_ADV_TRACE_VSNPRINTF(...) tiny_vsnprintf_like(__VA_ARGS__)
# 61 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 70 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
typedef enum {
  UTIL_TIMER_ONESHOT = 0,
  UTIL_TIMER_PERIODIC = 1
} UTIL_TIMER_Mode_t;





typedef enum {
  UTIL_TIMER_OK = 0,
  UTIL_TIMER_INVALID_PARAM = 1,
  UTIL_TIMER_HW_ERROR = 2,
  UTIL_TIMER_UNKNOWN_ERROR = 3
} UTIL_TIMER_Status_t;




typedef struct TimerEvent_s
{
    uint32_t Timestamp;
    uint32_t ReloadValue;
    uint8_t IsPending;
    uint8_t IsRunning;
    uint8_t IsReloadStopped;
    UTIL_TIMER_Mode_t Mode;
    void ( *Callback )( void *);
    void *argument;
 struct TimerEvent_s *Next;
} UTIL_TIMER_Object_t;




typedef struct
{
    UTIL_TIMER_Status_t (* InitTimer )( void );
    UTIL_TIMER_Status_t (* DeInitTimer )( void );

    UTIL_TIMER_Status_t (* StartTimerEvt )( uint32_t timeout );
    UTIL_TIMER_Status_t (* StopTimerEvt )( void);

    uint32_t (* SetTimerContext)( void );
    uint32_t (* GetTimerContext)( void );

    uint32_t (* GetTimerElapsedTime)( void );
    uint32_t (* GetTimerValue)( void );
    uint32_t (* GetMinimumTimeout)( void );

    uint32_t (* ms2Tick)( uint32_t timeMicroSec );
    uint32_t (* Tick2ms)( uint32_t tick );
} UTIL_TIMER_Driver_s;




typedef uint32_t UTIL_TIMER_Time_t;
# 142 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
extern const UTIL_TIMER_Driver_s UTIL_TimerDriver;
# 162 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_Init(void);






UTIL_TIMER_Status_t UTIL_TIMER_DeInit(void);
# 184 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_Create( UTIL_TIMER_Object_t *TimerObject, uint32_t PeriodValue, UTIL_TIMER_Mode_t Mode, void ( *Callback )( void *) , void *Argument);







UTIL_TIMER_Status_t UTIL_TIMER_Start( UTIL_TIMER_Object_t *TimerObject );
# 201 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_StartWithPeriod( UTIL_TIMER_Object_t *TimerObject, uint32_t PeriodValue);







UTIL_TIMER_Status_t UTIL_TIMER_Stop( UTIL_TIMER_Object_t *TimerObject );
# 219 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_SetPeriod(UTIL_TIMER_Object_t *TimerObject, uint32_t NewPeriodValue);
# 228 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_SetReloadMode(UTIL_TIMER_Object_t *TimerObject, UTIL_TIMER_Mode_t ReloadMode);
# 237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_GetRemainingTime(UTIL_TIMER_Object_t *TimerObject, uint32_t *Time);







uint32_t UTIL_TIMER_IsRunning( UTIL_TIMER_Object_t *TimerObject );







uint32_t UTIL_TIMER_GetFirstRemainingTime(void);






UTIL_TIMER_Time_t UTIL_TIMER_GetCurrentTime(void);
# 269 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Time_t UTIL_TIMER_GetElapsedTime(UTIL_TIMER_Time_t past );
# 278 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
void UTIL_TIMER_IRQ_Handler( void );
# 32 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h" 2
# 45 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h"
#define TIMERTIME_T_MAX ( ( uint32_t )~0 )
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h"
#define TimerTime_t UTIL_TIMER_Time_t




#define TimerEvent_t UTIL_TIMER_Object_t




#define TimerInit(HANDLE,CB) do { UTIL_TIMER_Create( HANDLE, TIMERTIME_T_MAX, UTIL_TIMER_ONESHOT, CB, NULL); } while(0)






#define TimerSetValue(HANDLE,TIMEOUT) do{ UTIL_TIMER_SetPeriod(HANDLE, TIMEOUT); } while(0)






#define TimerStart(HANDLE) do { UTIL_TIMER_Start(HANDLE); } while(0)






#define TimerStop(HANDLE) do { if (UTIL_TIMER_IsRunning(HANDLE)) { UTIL_TIMER_Stop(HANDLE); } } while(0)
# 100 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/timer.h"
#define TimerGetCurrentTime UTIL_TIMER_GetCurrentTime




#define TimerGetElapsedTime UTIL_TIMER_GetElapsedTime



#define TimerTempCompensation(x,y) (x)
# 46 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/systime.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/systime.h"
#define __SYSTIME_H__ 






# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h" 1
# 46 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
#define __STM32_SYS_TIME_H__ 
# 59 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 1 3







#define _TIME_H_ 





#define __need_size_t 
#define __need_NULL 
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/opt/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 17 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/time.h" 1 3

#define _MACHTIME_H_ 




#define _CLOCKS_PER_SEC_ 100
# 20 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3





#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC

# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 1 3
# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3

# 28 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __uint8_t u_int8_t;


typedef __uint16_t u_int16_t;


typedef __uint32_t u_int32_t;


typedef __uint64_t u_int64_t;

typedef __intptr_t register_t;
#define __BIT_TYPES_DEFINED__ 1



#define _SYS_TYPES_H 
# 97 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __blkcnt_t blkcnt_t;
#define _BLKCNT_T_DECLARED 



typedef __blksize_t blksize_t;
#define _BLKSIZE_T_DECLARED 



typedef unsigned long clock_t;
#define __clock_t_defined 
#define _CLOCK_T_DECLARED 



typedef __int_least64_t time_t;
#define __time_t_defined 
#define _TIME_T_DECLARED 



typedef long daddr_t;
#define __daddr_t_defined 


typedef char * caddr_t;
#define __caddr_t_defined 



typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
#define _FSBLKCNT_T_DECLARED 



typedef __id_t id_t;
#define _ID_T_DECLARED 



typedef __ino_t ino_t;
#define _INO_T_DECLARED 
# 157 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __off_t off_t;
#define _OFF_T_DECLARED 


typedef __dev_t dev_t;
#define _DEV_T_DECLARED 


typedef __uid_t uid_t;
#define _UID_T_DECLARED 


typedef __gid_t gid_t;
#define _GID_T_DECLARED 



typedef __pid_t pid_t;
#define _PID_T_DECLARED 



typedef __key_t key_t;
#define _KEY_T_DECLARED 



typedef _ssize_t ssize_t;
#define _SSIZE_T_DECLARED 



typedef __mode_t mode_t;
#define _MODE_T_DECLARED 



typedef __nlink_t nlink_t;
#define _NLINK_T_DECLARED 



typedef __clockid_t clockid_t;
#define __clockid_t_defined 
#define _CLOCKID_T_DECLARED 



typedef __timer_t timer_t;
#define __timer_t_defined 
#define _TIMER_T_DECLARED 



typedef __useconds_t useconds_t;
#define _USECONDS_T_DECLARED 



typedef __suseconds_t suseconds_t;
#define _SUSECONDS_T_DECLARED 


typedef __int64_t sbintime_t;


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 1 3
# 19 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 3
#define _SYS__PTHREADTYPES_H_ 
# 224 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/types.h" 1 3
# 225 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3



#undef __need_inttypes
# 29 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3
# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 1 3
# 35 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
#define _SYS_TIMESPEC_H_ 


# 1 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 1 3
# 37 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
#define _SYS__TIMESPEC_H_ 
# 47 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
struct timespec {
 time_t tv_sec;
 long tv_nsec;
};
# 39 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 2 3
# 58 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
# 30 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3







struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;






};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char *restrict _s,
        size_t _maxsize, const char *restrict _fmt,
        const struct tm *restrict _t);







char *asctime_r (const struct tm *restrict,
     char *restrict);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *restrict,
     struct tm *restrict);
struct tm *localtime_r (const time_t *restrict,
     struct tm *restrict);


# 103 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
void _tzset_r (struct _reent *);

typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset;
} __tzrule_type;

typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;

__tzinfo_type *__gettzinfo (void);
# 240 "/opt/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
#define CLOCK_ENABLED 1
#define CLOCK_DISABLED 0



#define CLOCK_ALLOWED 1


#define CLOCK_DISALLOWED 0






#define TIMER_ABSTIME 4







#define CLOCK_REALTIME ((clockid_t) 1)
# 60 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h" 2
# 70 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
#define TM_DAYS_IN_LEAP_YEAR ( ( uint32_t ) 366U )
#define TM_DAYS_IN_YEAR ( ( uint32_t ) 365U )
#define TM_SECONDS_IN_1DAY ( ( uint32_t )86400U )
#define TM_SECONDS_IN_1HOUR ( ( uint32_t ) 3600U )
#define TM_SECONDS_IN_1MINUTE ( ( uint32_t ) 60U )
#define TM_MINUTES_IN_1HOUR ( ( uint32_t ) 60U )
#define TM_HOURS_IN_1DAY ( ( uint32_t ) 24U )




#define TM_MONTH_JANUARY ( ( uint8_t ) 0U )
#define TM_MONTH_FEBRUARY ( ( uint8_t ) 1U )
#define TM_MONTH_MARCH ( ( uint8_t ) 2U )
#define TM_MONTH_APRIL ( ( uint8_t ) 3U )
#define TM_MONTH_MAY ( ( uint8_t ) 4U )
#define TM_MONTH_JUNE ( ( uint8_t ) 5U )
#define TM_MONTH_JULY ( ( uint8_t ) 6U )
#define TM_MONTH_AUGUST ( ( uint8_t ) 7U )
#define TM_MONTH_SEPTEMBER ( ( uint8_t ) 8U )
#define TM_MONTH_OCTOBER ( ( uint8_t ) 9U )
#define TM_MONTH_NOVEMBER ( ( uint8_t )10U )
#define TM_MONTH_DECEMBER ( ( uint8_t )11U )




#define TM_WEEKDAY_SUNDAY ( ( uint8_t )0U )
#define TM_WEEKDAY_MONDAY ( ( uint8_t )1U )
#define TM_WEEKDAY_TUESDAY ( ( uint8_t )2U )
#define TM_WEEKDAY_WEDNESDAY ( ( uint8_t )3U )
#define TM_WEEKDAY_THURSDAY ( ( uint8_t )4U )
#define TM_WEEKDAY_FRIDAY ( ( uint8_t )5U )
#define TM_WEEKDAY_SATURDAY ( ( uint8_t )6U )




#define UNIX_GPS_EPOCH_OFFSET 315964800
# 122 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"

# 122 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
typedef struct SysTime_s
{
uint32_t Seconds;
int16_t SubSeconds;
}SysTime_t;




typedef struct
{
  void (*BKUPWrite_Seconds) ( uint32_t Seconds);
  uint32_t (*BKUPRead_Seconds) ( void );
  void (*BKUPWrite_SubSeconds) ( uint32_t SubSeconds);
  uint32_t (*BKUPRead_SubSeconds) ( void );
  uint32_t (*GetCalendarTime)( uint16_t* SubSeconds );
} UTIL_SYSTIM_Driver_s;
# 156 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
extern const UTIL_SYSTIM_Driver_s UTIL_SYSTIMDriver;
# 174 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeAdd( SysTime_t a, SysTime_t b );
# 184 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeSub( SysTime_t a, SysTime_t b );






void SysTimeSet( SysTime_t sysTime );






SysTime_t SysTimeGet( void );






SysTime_t SysTimeGetMcuTime( void );
# 214 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
uint32_t SysTimeToMs( SysTime_t sysTime );
# 223 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeFromMs( uint32_t timeMs );







uint32_t SysTimeMkTime( const struct tm* localtime );
# 240 "/home/jenkins/workspace/RUI_Release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
void SysTimeLocalTime( const uint32_t timestamp, struct tm *localtime );
# 32 "/home/jenkins/workspace/RUI_Release/rui-v3/component/core/board/rak3172/systime.h" 2
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 2




#define LORAMAC_CRYPTO_UNICAST_KEYS 0




#define LORAMAC_CRYPTO_MULTICAST_KEYS 127




#define LORAMAC_MAX_MC_CTX 4
# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_0 0
# 93 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_1 1
# 109 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_2 2
# 125 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_3 3
# 141 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_4 4
# 157 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_5 5
# 173 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_6 6
# 189 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_7 7
# 205 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_8 8
# 221 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_9 9
# 237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_10 10
# 253 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_11 11
# 269 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_12 12
# 285 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_13 13
# 301 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_14 14
# 317 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_15 15
# 335 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_0 0
# 351 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_1 1
# 367 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_2 2
# 383 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_3 3
# 399 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_4 4
# 415 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_5 5
# 431 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_6 6
# 447 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_7 7
# 463 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_8 8
# 479 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_9 9
# 495 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_10 10
# 511 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_11 11
# 527 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_12 12
# 543 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_13 13
# 559 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_14 14




#define TX_POWER_15 15






typedef enum DeviceClass_e
{





    CLASS_A = 0x00,





    CLASS_B = 0x01,





    CLASS_C = 0x02,
}DeviceClass_t;







typedef enum eFType
{





    FRAME_TYPE_A,





    FRAME_TYPE_B,





    FRAME_TYPE_C,





    FRAME_TYPE_D,
}FType_t;




typedef enum eFCntIdentifier
{



    FCNT_UP = 0,




    N_FCNT_DOWN,




    A_FCNT_DOWN,




    FCNT_DOWN,



    MC_FCNT_DOWN_0,



    MC_FCNT_DOWN_1,



    MC_FCNT_DOWN_2,



    MC_FCNT_DOWN_3,
}FCntIdentifier_t;




typedef enum eKeyIdentifier
{



    APP_KEY = 0,



    NWK_KEY,



    J_S_INT_KEY,



    J_S_ENC_KEY,



    F_NWK_S_INT_KEY,



    S_NWK_S_INT_KEY,



    NWK_S_ENC_KEY,



    APP_S_KEY,



    MC_ROOT_KEY,



    MC_KE_KEY = 127,



    MC_KEY_0,



    MC_APP_S_KEY_0,



    MC_NWK_S_KEY_0,



    MC_KEY_1,



    MC_APP_S_KEY_1,



    MC_NWK_S_KEY_1,



    MC_KEY_2,



    MC_APP_S_KEY_2,



    MC_NWK_S_KEY_2,



    MC_KEY_3,



    MC_APP_S_KEY_3,



    MC_NWK_S_KEY_3,



    SLOT_RAND_ZERO_KEY,



    NO_KEY,
}KeyIdentifier_t;




typedef enum eAddressIdentifier
{



    MULTICAST_0_ADDR = 0,



    MULTICAST_1_ADDR = 1,



    MULTICAST_2_ADDR = 2,



    MULTICAST_3_ADDR = 3,



    UNICAST_DEV_ADDR = 4,
}AddressIdentifier_t;




typedef union uMcRxParams
{
    struct
    {



        uint32_t Frequency;



        int8_t Datarate;




        uint16_t Periodicity;
    }ClassB;
    struct
    {



        uint32_t Frequency;



        int8_t Datarate;
    }ClassC;
}McRxParams_t;




typedef struct sMcChannelParams
{




    
# 842 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 842 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
        IsRemotelySetup;



    DeviceClass_t Class;



    
# 850 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 850 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
        IsEnabled;



    AddressIdentifier_t GroupID;



    uint32_t Address;



    union uMcKeys
    {




        uint8_t *McKeyE;



        struct
        {



            uint8_t *McAppSKey;



            uint8_t *McNwkSKey;
        }Session;
    }McKeys;



    uint32_t FCountMin;



    uint32_t FCountMax;



    McRxParams_t RxParams;
}McChannelParams_t;




typedef struct sMulticastCtx
{



    McChannelParams_t ChannelParams;



    uint32_t* DownLinkCounter;
# 920 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
    uint8_t PingNb;





    uint16_t PingPeriod;



    uint16_t PingOffset;
}MulticastCtx_t;




typedef enum eJoinReqIdentifier
{



    REJOIN_REQ_0 = 0x00,



    REJOIN_REQ_1 = 0x01,



    REJOIN_REQ_2 = 0x02,



    JOIN_REQ = 0xFF,
}JoinReqIdentifier_t;






typedef enum eLoRaMacMoteCmd
{



    MOTE_MAC_LINK_CHECK_REQ = 0x02,



    MOTE_MAC_LINK_ADR_ANS = 0x03,



    MOTE_MAC_DUTY_CYCLE_ANS = 0x04,



    MOTE_MAC_RX_PARAM_SETUP_ANS = 0x05,



    MOTE_MAC_DEV_STATUS_ANS = 0x06,



    MOTE_MAC_NEW_CHANNEL_ANS = 0x07,



    MOTE_MAC_RX_TIMING_SETUP_ANS = 0x08,



    MOTE_MAC_TX_PARAM_SETUP_ANS = 0x09,



    MOTE_MAC_DL_CHANNEL_ANS = 0x0A,



    MOTE_MAC_DEVICE_TIME_REQ = 0x0D,



    MOTE_MAC_PING_SLOT_INFO_REQ = 0x10,



    MOTE_MAC_PING_SLOT_FREQ_ANS = 0x11,



    MOTE_MAC_BEACON_TIMING_REQ = 0x12,



    MOTE_MAC_BEACON_FREQ_ANS = 0x13,
}LoRaMacMoteCmd_t;






typedef enum eLoRaMacSrvCmd
{



    SRV_MAC_RESET_CONF = 0x01,



    SRV_MAC_LINK_CHECK_ANS = 0x02,



    SRV_MAC_LINK_ADR_REQ = 0x03,



    SRV_MAC_DUTY_CYCLE_REQ = 0x04,



    SRV_MAC_RX_PARAM_SETUP_REQ = 0x05,



    SRV_MAC_DEV_STATUS_REQ = 0x06,



    SRV_MAC_NEW_CHANNEL_REQ = 0x07,



    SRV_MAC_RX_TIMING_SETUP_REQ = 0x08,



    SRV_MAC_TX_PARAM_SETUP_REQ = 0x09,



    SRV_MAC_DL_CHANNEL_REQ = 0x0A,



    SRV_MAC_DEVICE_TIME_ANS = 0x0D,



    SRV_MAC_PING_SLOT_INFO_ANS = 0x10,



    SRV_MAC_PING_SLOT_CHANNEL_REQ = 0x11,



    SRV_MAC_BEACON_TIMING_ANS = 0x12,



    SRV_MAC_BEACON_FREQ_REQ = 0x13,
}LoRaMacSrvCmd_t;




typedef struct sBand
{



    uint16_t DCycle;



    int8_t TxMaxPower;




    UTIL_TIMER_Time_t LastBandUpdateTime;




    UTIL_TIMER_Time_t LastMaxCreditAssignTime;




    UTIL_TIMER_Time_t TimeCredits;




    UTIL_TIMER_Time_t MaxTimeCredits;



    
# 1126 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 1126 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
        ReadyForTransmission;
}Band_t;




typedef union uDrRange
{



    int8_t Value;



    struct sFields
    {







        int8_t Min : 4;







        int8_t Max : 4;
    }Fields;
}DrRange_t;




typedef struct sChannelParams
{



    uint32_t Frequency;



    uint32_t Rx1Frequency;



    DrRange_t DrRange;



    uint8_t Band;
}ChannelParams_t;






typedef enum eLoRaMacFrameType
{



    FRAME_TYPE_JOIN_REQ = 0x00,



    FRAME_TYPE_JOIN_ACCEPT = 0x01,



    FRAME_TYPE_DATA_UNCONFIRMED_UP = 0x02,



    FRAME_TYPE_DATA_UNCONFIRMED_DOWN = 0x03,



    FRAME_TYPE_DATA_CONFIRMED_UP = 0x04,



    FRAME_TYPE_DATA_CONFIRMED_DOWN = 0x05,



    FRAME_TYPE_PROPRIETARY = 0x07,
}LoRaMacFrameType_t;




typedef enum eLoRaMacBatteryLevel
{



    BAT_LEVEL_EXT_SRC = 0x00,



    BAT_LEVEL_EMPTY = 0x01,



    BAT_LEVEL_FULL = 0xFE,



    BAT_LEVEL_NO_MEASURE = 0xFF,
}LoRaMacBatteryLevel_t;
# 50 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacMessageTypes.h" 1
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacMessageTypes.h"
#define __LORAMAC_MESSAGE_TYPES_H__ 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h" 1
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define __LORAMAC_HEADER_TYPES_H__ 
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_MHDR_FIELD_SIZE 1


#define LORAMAC_JOIN_TYPE_FIELD_SIZE 1


#define LORAMAC_JOIN_EUI_FIELD_SIZE 8


#define LORAMAC_DEV_EUI_FIELD_SIZE 8


#define LORAMAC_DEV_NONCE_FIELD_SIZE 2


#define LORAMAC_JOIN_NONCE_FIELD_SIZE 3


#define LORAMAC_RJCOUNT_0_FIELD_SIZE 2


#define LORAMAC_RJCOUNT_1_FIELD_SIZE 2


#define LORAMAC_NET_ID_FIELD_SIZE 3


#define LORAMAC_DEV_ADDR_FIELD_SIZE 4


#define LORAMAC_DL_SETTINGS_FIELD_SIZE 1


#define LORAMAC_RX_DELAY_FIELD_SIZE 1


#define LORAMAC_CF_LIST_FIELD_SIZE 16


#define LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE LORAMAC_DEV_ADDR_FIELD_SIZE


#define LORAMAC_FHDR_F_CTRL_FIELD_SIZE 1


#define LORAMAC_FHDR_F_CNT_FIELD_SIZE 2


#define LORAMAC_FHDR_F_OPTS_MAX_FIELD_SIZE 15


#define LORAMAC_F_PORT_FIELD_SIZE 1


#define LORAMAC_MAC_PAYLOAD_FIELD_MAX_SIZE 242


#define LORAMAC_MIC_FIELD_SIZE 4






#define LORAMAC_JOIN_REQ_MSG_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_EUI_FIELD_SIZE + LORAMAC_DEV_EUI_FIELD_SIZE + LORAMAC_DEV_NONCE_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_RE_JOIN_1_MSG_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_JOIN_EUI_FIELD_SIZE + LORAMAC_DEV_EUI_FIELD_SIZE + LORAMAC_RJCOUNT_1_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 131 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_RE_JOIN_0_2_MSG_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_EUI_FIELD_SIZE + LORAMAC_RJCOUNT_0_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 141 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_JOIN_ACCEPT_FRAME_MIN_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_NONCE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_ADDR_FIELD_SIZE + LORAMAC_DL_SETTINGS_FIELD_SIZE + LORAMAC_RX_DELAY_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 151 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_JOIN_ACCEPT_FRAME_MAX_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_NONCE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_ADDR_FIELD_SIZE + LORAMAC_DL_SETTINGS_FIELD_SIZE + LORAMAC_RX_DELAY_FIELD_SIZE + LORAMAC_CF_LIST_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 160 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define JOIN_ACCEPT_MIC_COMPUTATION_OFFSET ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_JOIN_EUI_FIELD_SIZE + LORAMAC_DEV_NONCE_FIELD_SIZE )
# 173 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_FRAME_PAYLOAD_OVERHEAD_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_F_PORT_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 182 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_FRAME_PAYLOAD_MIN_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_MIC_FIELD_SIZE )







#define LORAMAC_FRAME_PAYLOAD_MAX_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_F_PORT_FIELD_SIZE + LORAMAC_MAC_PAYLOAD_FIELD_MAX_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 200 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
typedef union uLoRaMacDLSettings
{



    uint8_t Value;



    struct sDLSettingsBits
    {



        uint8_t RX2DataRate : 4;



        uint8_t RX1DRoffset : 3;



        uint8_t OptNeg : 1;
    }Bits;
}LoRaMacDLSettings_t;






typedef union uLoRaMacHeader
{



    uint8_t Value;



    struct sMacHeaderBits
    {



        uint8_t Major : 2;



        uint8_t RFU : 3;



        uint8_t MType : 3;
    }Bits;
}LoRaMacHeader_t;






typedef union uLoRaMacFrameCtrl
{



    uint8_t Value;



    struct sCtrlBits
    {



        uint8_t FOptsLen : 4;



        uint8_t FPending : 1;



        uint8_t Ack : 1;



        uint8_t AdrAckReq : 1;



        uint8_t Adr : 1;
    }Bits;
}LoRaMacFrameCtrl_t;






typedef struct sLoRaMacFrameHeader
{



    uint32_t DevAddr;



    LoRaMacFrameCtrl_t FCtrl;



    uint16_t FCnt;



    uint8_t FOpts[15];
}LoRaMacFrameHeader_t;
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacMessageTypes.h" 2




typedef struct sLoRaMacMessageJoinRequest
{



    uint8_t* Buffer;



    uint8_t BufSize;



    LoRaMacHeader_t MHDR;



    uint8_t JoinEUI[8];



    uint8_t DevEUI[8];



    uint16_t DevNonce;



    uint32_t MIC;
}LoRaMacMessageJoinRequest_t;




typedef struct sLoRaMacMessageReJoinType1
{



    uint8_t* Buffer;



    uint8_t BufSize;



    LoRaMacHeader_t MHDR;



    uint8_t ReJoinType;



    uint8_t JoinEUI[8];



    uint8_t DevEUI[8];



    uint16_t RJcount1;



    uint32_t MIC;
}LoRaMacMessageReJoinType1_t;




typedef struct sLoRaMacMessageReJoinType0or2
{



    uint8_t* Buffer;



    uint8_t BufSize;



    LoRaMacHeader_t MHDR;



    uint8_t ReJoinType;



    uint8_t NetID[3];



    uint8_t DevEUI[8];



    uint16_t RJcount0;



    uint32_t MIC;
}LoRaMacMessageReJoinType0or2_t;




typedef struct sLoRaMacMessageJoinAccept
{



    uint8_t* Buffer;



    uint8_t BufSize;



    LoRaMacHeader_t MHDR;



    uint8_t JoinNonce[3];



    uint8_t NetID[3];



    uint32_t DevAddr;



    LoRaMacDLSettings_t DLSettings;



    uint8_t RxDelay;



    uint8_t CFList[16];



    uint32_t MIC;
}LoRaMacMessageJoinAccept_t;






typedef struct sLoRaMacMessageData
{



    uint8_t* Buffer;



    uint8_t BufSize;



    LoRaMacHeader_t MHDR;



    LoRaMacFrameHeader_t FHDR;



    uint8_t FPort;



    uint8_t* FRMPayload;



    uint8_t FRMPayloadSize;



    uint32_t MIC;
}LoRaMacMessageData_t;




typedef enum eLoRaMacMessageType
{



    LORAMAC_MSG_TYPE_JOIN_REQUEST,



    LORAMAC_MSG_TYPE_RE_JOIN_1,



    LORAMAC_MSG_TYPE_RE_JOIN_0_2,



    LORAMAC_MSG_TYPE_JOIN_ACCEPT,



    LORAMAC_MSG_TYPE_DATA,



    LORAMAC_MSG_TYPE_UNDEF,
}LoRaMacMessageType_t;




typedef struct sLoRaMacMessage
{
    LoRaMacMessageType_t Type;
    union uMessage
    {
        LoRaMacMessageJoinRequest_t JoinReq;
        LoRaMacMessageReJoinType1_t ReJoin1;
        LoRaMacMessageReJoinType0or2_t ReJoin0or2;
        LoRaMacMessageJoinAccept_t JoinAccept;
        LoRaMacMessageData_t Data;
    }Message;
}LoRaMacMessage_t;
# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h" 1
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h"
#define __LORAMAC_CRYPTO_NVM_H__ 
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h"
typedef struct sFCntList
{



    uint32_t FCntUp;




    uint32_t NFCntDown;




    uint32_t AFCntDown;




    uint32_t FCntDown;



    uint32_t McFCntDown[4];






}FCntList_t;




typedef struct sLoRaMacCryptoNvmData
{




    Version_t LrWanVersion;




    uint16_t DevNonce;




    uint32_t JoinNonce;



    FCntList_t FCntList;





    uint32_t LastDownFCnt;



    uint32_t Crc32;
}LoRaMacCryptoNvmData_t;
# 52 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h" 2




#define USE_LRWAN_1_1_X_CRYPTO 0




#define USE_RANDOM_DEV_NONCE 1




#define USE_JOIN_NONCE_COUNTER_CHECK 0




#define FCNT_DOWN_INITAL_VALUE 0xFFFFFFFF




typedef enum eLoRaMacCryptoStatus
{



    LORAMAC_CRYPTO_SUCCESS = 0,



    LORAMAC_CRYPTO_FAIL_MIC,



    LORAMAC_CRYPTO_FAIL_ADDRESS,



    LORAMAC_CRYPTO_FAIL_JOIN_NONCE,



    LORAMAC_CRYPTO_FAIL_RJCOUNT0_OVERFLOW,



    LORAMAC_CRYPTO_FAIL_FCNT_ID,



    LORAMAC_CRYPTO_FAIL_FCNT_SMALLER,



    LORAMAC_CRYPTO_FAIL_FCNT_DUPLICATED,



    LORAMAC_CRYPTO_FAIL_MAX_GAP_FCNT,



    LORAMAC_CRYPTO_FAIL_PARAM,



    LORAMAC_CRYPTO_ERROR_NPE,



    LORAMAC_CRYPTO_ERROR_INVALID_KEY_ID,



    LORAMAC_CRYPTO_ERROR_INVALID_ADDR_ID,



    LORAMAC_CRYPTO_ERROR_INVALID_VERSION,



    LORAMAC_CRYPTO_ERROR_BUF_SIZE,



    LORAMAC_CRYPTO_ERROR_SECURE_ELEMENT_FUNC,



    LORAMAC_CRYPTO_ERROR_PARSER,



    LORAMAC_CRYPTO_ERROR_SERIALIZER,



    LORAMAC_CRYPTO_ERROR_RJCOUNT1_OVERFLOW,



    LORAMAC_CRYPTO_ERROR,
}LoRaMacCryptoStatus_t;







typedef void ( *LoRaMacCryptoNvmEvent )( void );
# 176 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoInit( LoRaMacCryptoNvmData_t* nvm );
# 187 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoSetLrWanVersion( Version_t version );
# 198 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoGetFCntDown( FCntIdentifier_t fCntID, uint16_t maxFCntGap, uint32_t frameFcnt, uint32_t* currentDown );







LoRaMacCryptoStatus_t LoRaMacCryptoGetFCntUp( uint32_t* currentUp );
# 215 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoSetMulticastReference( MulticastCtx_t* multicastList );
# 224 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoSetKey( KeyIdentifier_t keyID, uint8_t* key );
# 233 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoPrepareJoinRequest( LoRaMacMessageJoinRequest_t* macMsg );
# 242 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoPrepareReJoinType1( LoRaMacMessageReJoinType1_t* macMsg );
# 251 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoPrepareReJoinType0or2( LoRaMacMessageReJoinType0or2_t* macMsg );
# 262 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoHandleJoinAccept( JoinReqIdentifier_t joinReqType, uint8_t* joinEUI, LoRaMacMessageJoinAccept_t* macMsg );
# 273 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoSecureMessage( uint32_t fCntUp, uint8_t txDr, uint8_t txCh, LoRaMacMessageData_t* macMsg );
# 285 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoUnsecureMessage( AddressIdentifier_t addrID, uint32_t address, FCntIdentifier_t fCntID, uint32_t fCntDown, LoRaMacMessageData_t* macMsg );
# 300 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoDeriveMcRootKey( uint8_t versionMinor, KeyIdentifier_t keyID );
# 310 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoDeriveMcKEKey( KeyIdentifier_t keyID );
# 322 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCrypto.h"
LoRaMacCryptoStatus_t LoRaMacCryptoDeriveMcSessionKeyPair( AddressIdentifier_t addrID, uint32_t mcAddr );
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h" 1
# 35 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h"
#define __SECURE_ELEMENT_NVM_H__ 
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h"
#define SE_KEY_SIZE 16




#define SE_EUI_SIZE 8




#define SE_PIN_SIZE 4





#define NUM_OF_KEYS 23




typedef struct sKey
{



    KeyIdentifier_t KeyID;



    uint8_t KeyValue[16];
} Key_t;


typedef struct sSecureElementNvCtx
{



    uint8_t DevEui[8];



    uint8_t JoinEui[8];



    uint8_t Pin[4];





    Key_t KeyList[23];




    uint32_t Crc32;
} SecureElementNvmData_t;
# 49 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h" 2




typedef enum eSecureElementStatus
{



    SECURE_ELEMENT_SUCCESS = 0,



    SECURE_ELEMENT_FAIL_CMAC,



    SECURE_ELEMENT_ERROR_NPE,



    SECURE_ELEMENT_ERROR_INVALID_KEY_ID,



    SECURE_ELEMENT_ERROR_INVALID_LORAWAM_SPEC_VERSION,



    SECURE_ELEMENT_ERROR_BUF_SIZE,



    SECURE_ELEMENT_ERROR,



    SECURE_ELEMENT_FAIL_ENCRYPT,
}SecureElementStatus_t;
# 96 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementInit( SecureElementNvmData_t* nvm );
# 105 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementSetKey( KeyIdentifier_t keyID, uint8_t* key );
# 117 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementComputeAesCmac( uint8_t* micBxBuffer, uint8_t* buffer, uint16_t size, KeyIdentifier_t keyID, uint32_t* cmac );
# 128 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementVerifyAesCmac( uint8_t* buffer, uint16_t size, uint32_t expectedCmac, KeyIdentifier_t keyID );
# 139 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementAesEncrypt( uint8_t* buffer, uint16_t size, KeyIdentifier_t keyID, uint8_t* encBuffer );
# 149 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementDeriveAndStoreKey( uint8_t* input, KeyIdentifier_t rootKeyID, KeyIdentifier_t targetKeyID );
# 162 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
SecureElementStatus_t SecureElementProcessJoinAccept( JoinReqIdentifier_t joinReqType, uint8_t* joinEui,
                                                      uint16_t devNonce, uint8_t* encJoinAccept,
                                                      uint8_t encJoinAcceptSize, uint8_t* decJoinAccept,
                                                      uint8_t* versionMinor );







SecureElementStatus_t SecureElementRandomNumber( uint32_t* randomNum );







SecureElementStatus_t SecureElementSetDevEui( uint8_t* devEui );






uint8_t* SecureElementGetDevEui( void );







SecureElementStatus_t SecureElementSetJoinEui( uint8_t* joinEui );






uint8_t* SecureElementGetJoinEui( void );







SecureElementStatus_t SecureElementSetPin( uint8_t* pin );






uint8_t* SecureElementGetPin( void );






# 224 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h" 3 4
_Bool 
# 224 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element.h"
    Get_McRoot_Key(uint8_t *key);
# 23 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 1
# 67 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
#define __LORAMAC_H__ 
# 81 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h" 1
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define __REGIONNVM_H__ 






# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 1
# 42 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h" 2



#define REGION_NVM_MAX_NB_CHANNELS 96
# 59 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define REGION_NVM_MAX_NB_BANDS 6
# 68 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define REGION_NVM_CHANNELS_MASK_SIZE 6
# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
typedef struct sRegionNvmDataGroup1
{



    Band_t Bands[ 6 ];




    uint16_t ChannelsMaskRemaining[ 6 ];




    uint8_t JoinChannelGroupsCurrentIndex;



    uint8_t JoinTrialsCounter;




    uint32_t Crc32;
}RegionNvmDataGroup1_t;





typedef struct sRegionNvmDataGroup2
{



    ChannelParams_t Channels[ 96 ];



    uint16_t ChannelsMask[ 6 ];



    uint16_t ChannelsDefaultMask[ 6 ];



    uint32_t Crc32;
}RegionNvmDataGroup2_t;
# 82 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2


# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h" 1
# 34 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h"
#define __LORAMACCLASSBNVM_H__ 
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h"
typedef struct sLoRaMacClassBPingSlotNvmData
{
    struct sPingSlotCtrlNvm
    {



        uint8_t Assigned : 1;



        uint8_t CustomFreq : 1;
    }Ctrl;



    uint8_t PingNb;



    uint16_t PingPeriod;



    uint32_t Frequency;



    int8_t Datarate;
} LoRaMacClassBPingSlotNvmData_t;





typedef struct sLoRaMacClassBBeaconNvmData
{
    struct sBeaconCtrlNvm
    {



        uint8_t CustomFreq : 1;
    }Ctrl;



    uint32_t Frequency;
} LoRaMacClassBBeaconNvmData_t;




typedef struct sLoRaMacClassBNvmData
{



    LoRaMacClassBPingSlotNvmData_t PingSlotCtx;



    LoRaMacClassBBeaconNvmData_t BeaconCtx;



    uint32_t Crc32;
} LoRaMacClassBNvmData_t;
# 85 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2




#define MAX_ACK_RETRIES 8




#define UP_LINK 0




#define DOWN_LINK 1




#define LORA_MAC_MLME_CONFIRM_QUEUE_LEN 5




#define LORAMAC_CRYPTO_MULTICAST_KEYS 127




#define LORA_MAC_COMMAND_MAX_LENGTH 128





#define LORAMAC_NVM_NOTIFY_FLAG_NONE 0x00




#define LORAMAC_NVM_NOTIFY_FLAG_CRYPTO 0x01




#define LORAMAC_NVM_NOTIFY_FLAG_MAC_GROUP1 0x02




#define LORAMAC_NVM_NOTIFY_FLAG_MAC_GROUP2 0x04




#define LORAMAC_NVM_NOTIFY_FLAG_SECURE_ELEMENT 0x08




#define LORAMAC_NVM_NOTIFY_FLAG_REGION_GROUP1 0x10




#define LORAMAC_NVM_NOTIFY_FLAG_REGION_GROUP2 0x20




#define LORAMAC_NVM_NOTIFY_FLAG_CLASS_B 0x40




typedef enum eActivationType
{



    ACTIVATION_TYPE_NONE = 0,



    ACTIVATION_TYPE_ABP = 1,



    ACTIVATION_TYPE_OTAA = 2,
}ActivationType_t;




typedef struct sRxChannelParams
{



    uint32_t Frequency;







    uint8_t Datarate;
}RxChannelParams_t;




typedef enum eLoRaMacRxSlot
{



    RX_SLOT_WIN_1,



    RX_SLOT_WIN_2,



    RX_SLOT_WIN_CLASS_C,



    RX_SLOT_WIN_CLASS_C_MULTICAST,



    RX_SLOT_WIN_CLASS_B_PING_SLOT,



    RX_SLOT_WIN_CLASS_B_MULTICAST_SLOT,



    RX_SLOT_NONE,
}LoRaMacRxSlot_t;




typedef struct sLoRaMacParams
{





    uint32_t SystemMaxRxError;




    uint8_t MinRxSymbols;



    uint32_t MaxRxWindow;



    uint32_t ReceiveDelay1;



    uint32_t ReceiveDelay2;



    uint32_t JoinAcceptDelay1;



    uint32_t JoinAcceptDelay2;



    uint8_t ChannelsNbTrans;



    uint8_t Rx1DrOffset;



    RxChannelParams_t Rx2Channel;



    RxChannelParams_t RxCChannel;



    uint8_t UplinkDwellTime;



    uint8_t DownlinkDwellTime;



    float MaxEirp;



    float AntennaGain;
}LoRaMacParams_t;






typedef union uPingSlotInfo
{



    uint8_t Value;



    struct sInfoFields
    {




        uint8_t Periodicity : 3;



        uint8_t RFU : 5;
    }Fields;
}PingSlotInfo_t;






typedef struct sBeaconInfo
{




    SysTime_t Time;



    uint32_t Frequency;



    uint8_t Datarate;



    int16_t Rssi;



    int8_t Snr;




    struct sGwSpecific
    {



        uint8_t InfoDesc;



        uint8_t Info[6];
    }GwSpecific;
}BeaconInfo_t;




typedef enum eLoRaMacEventInfoStatus
{



    LORAMAC_EVENT_INFO_STATUS_OK = 0,



    LORAMAC_EVENT_INFO_STATUS_ERROR,



    LORAMAC_EVENT_INFO_STATUS_TX_TIMEOUT,



    LORAMAC_EVENT_INFO_STATUS_RX1_TIMEOUT,



    LORAMAC_EVENT_INFO_STATUS_RX2_TIMEOUT,



    LORAMAC_EVENT_INFO_STATUS_RX1_ERROR,



    LORAMAC_EVENT_INFO_STATUS_RX2_ERROR,



    LORAMAC_EVENT_INFO_STATUS_JOIN_FAIL,





    LORAMAC_EVENT_INFO_STATUS_DOWNLINK_REPEATED,




    LORAMAC_EVENT_INFO_STATUS_TX_DR_PAYLOAD_SIZE_ERROR,



    LORAMAC_EVENT_INFO_STATUS_DOWNLINK_TOO_MANY_FRAMES_LOSS,



    LORAMAC_EVENT_INFO_STATUS_ADDRESS_FAIL,



    LORAMAC_EVENT_INFO_STATUS_MIC_FAIL,



    LORAMAC_EVENT_INFO_STATUS_MULTICAST_FAIL,



    LORAMAC_EVENT_INFO_STATUS_BEACON_LOCKED,



    LORAMAC_EVENT_INFO_STATUS_BEACON_LOST,



    LORAMAC_EVENT_INFO_STATUS_BEACON_NOT_FOUND,
}LoRaMacEventInfoStatus_t;




typedef union eLoRaMacFlags_t
{



    uint8_t Value;



    struct sMacFlagBits
    {



        uint8_t McpsReq : 1;



        uint8_t McpsInd : 1;



        uint8_t MlmeReq : 1;



        uint8_t MlmeInd : 1;



        uint8_t MlmeSchedUplinkInd : 1;



        uint8_t MacDone : 1;
    }Bits;
}LoRaMacFlags_t;




typedef enum eLoRaMacRegion
{



    LORAMAC_REGION_AS923,



    LORAMAC_REGION_AU915,



    LORAMAC_REGION_CN470,



    LORAMAC_REGION_CN779,



    LORAMAC_REGION_EU433,



    LORAMAC_REGION_EU868,



    LORAMAC_REGION_KR920,



    LORAMAC_REGION_IN865,



    LORAMAC_REGION_US915,



    LORAMAC_REGION_RU864,
    LORAMAC_REGION_LA915,
}LoRaMacRegion_t;

typedef struct sLoRaMacNvmDataGroup1
{



    uint32_t AdrAckCounter;



    UTIL_TIMER_Time_t LastTxDoneTime;



    UTIL_TIMER_Time_t AggregatedTimeOff;



    uint32_t LastRxMic;



    int8_t ChannelsTxPower;



    int8_t ChannelsDatarate;




    
# 570 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 570 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        SrvAckRequested;



    uint32_t Crc32;
}LoRaMacNvmDataGroup1_t;

typedef struct sLoRaMacNvmDataGroup2
{



    LoRaMacRegion_t Region;



    LoRaMacParams_t MacParams;



    LoRaMacParams_t MacParamsDefaults;



    int8_t ChannelsTxPowerDefault;



    int8_t ChannelsDatarateDefault;



    uint32_t NetID;



    uint32_t DevAddr;



    MulticastCtx_t MulticastChannelList[4];



    DeviceClass_t DeviceClass;




    
# 619 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 619 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        PublicNetwork;



    
# 623 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 623 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AdrCtrlOn;




    uint8_t MaxDCycle;



    
# 632 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 632 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        DutyCycleOn;



    uint16_t AggregatedDCycle;





    SysTime_t InitializationTime;



    Version_t Version;



    ActivationType_t NetworkActivation;



    uint32_t Crc32;
}LoRaMacNvmDataGroup2_t;





typedef struct sLoRaMacNvmData
{




    LoRaMacCryptoNvmData_t Crypto;




    LoRaMacNvmDataGroup1_t MacGroup1;




    LoRaMacNvmDataGroup2_t MacGroup2;



    SecureElementNvmData_t SecureElement;




    RegionNvmDataGroup1_t RegionGroup1;




    RegionNvmDataGroup2_t RegionGroup2;



    LoRaMacClassBNvmData_t ClassB;
}LoRaMacNvmData_t;
# 721 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
typedef enum eMcps
{



    MCPS_UNCONFIRMED,



    MCPS_CONFIRMED,



    MCPS_MULTICAST,



    MCPS_PROPRIETARY,
}Mcps_t;




typedef struct sRequestReturnParam
{





    UTIL_TIMER_Time_t DutyCycleWaitTime;
}RequestReturnParam_t;




typedef struct sMcpsReqUnconfirmed
{






    uint8_t fPort;



    void* fBuffer;



    uint16_t fBufferSize;



    int8_t Datarate;
}McpsReqUnconfirmed_t;




typedef struct sMcpsReqConfirmed
{






    uint8_t fPort;



    void* fBuffer;



    uint16_t fBufferSize;



    int8_t Datarate;
# 824 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    uint8_t NbTrials;
}McpsReqConfirmed_t;




typedef struct sMcpsReqProprietary
{



    void* fBuffer;



    uint16_t fBufferSize;



    int8_t Datarate;
}McpsReqProprietary_t;




typedef struct sMcpsReq
{



    Mcps_t Type;




    union uMcpsParam
    {



        McpsReqUnconfirmed_t Unconfirmed;



        McpsReqConfirmed_t Confirmed;



        McpsReqProprietary_t Proprietary;
    }Req;




    RequestReturnParam_t ReqReturn;
}McpsReq_t;




typedef struct sMcpsConfirm
{



    Mcps_t McpsRequest;



    LoRaMacEventInfoStatus_t Status;



    uint8_t Datarate;



    int8_t TxPower;



    
# 905 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 905 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AckReceived;



    uint8_t NbRetries;



    UTIL_TIMER_Time_t TxTimeOnAir;



    uint32_t UpLinkCounter;



    uint32_t Channel;
}McpsConfirm_t;




typedef struct sMcpsIndication
{



    Mcps_t McpsIndication;



    LoRaMacEventInfoStatus_t Status;



    uint8_t Multicast;



    uint8_t Port;



    uint8_t RxDatarate;



    uint8_t FramePending;



    uint8_t* Buffer;



    uint8_t BufferSize;



    
# 964 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 964 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        RxData;



    int16_t Rssi;



    int8_t Snr;



    LoRaMacRxSlot_t RxSlot;



    
# 980 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 980 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AckReceived;



    uint32_t DownLinkCounter;



    uint32_t DevAddress;



    
# 992 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 992 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        DeviceTimeAnsReceived;
}McpsIndication_t;
# 1019 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
typedef enum eMlme
{



    MLME_UNKNOWN,





    MLME_JOIN,





    MLME_REJOIN_0,





    MLME_REJOIN_1,





    MLME_LINK_CHECK,





    MLME_TXCW,





    MLME_TXCW_1,




    MLME_SCHEDULE_UPLINK,



    MLME_DERIVE_MC_KE_KEY,



    MLME_DERIVE_MC_KEY_PAIR,





    MLME_DEVICE_TIME,






    MLME_BEACON,






    MLME_BEACON_ACQUISITION,





    MLME_PING_SLOT_INFO,





    MLME_BEACON_TIMING,







    MLME_BEACON_LOST,
}Mlme_t;




typedef struct sMlmeReqJoin
{



    uint8_t Datarate;
}MlmeReqJoin_t;




typedef struct sMlmeReqTxCw
{



    uint16_t Timeout;



    uint32_t Frequency;



    int8_t Power;
}MlmeReqTxCw_t;




typedef struct sMlmeReqPingSlotInfo
{
    PingSlotInfo_t PingSlot;
}MlmeReqPingSlotInfo_t;




typedef struct sMlmeReqDeriveMcKEKey
{



    KeyIdentifier_t KeyID;



    uint16_t Nonce;



    uint8_t* DevEUI;
}MlmeReqDeriveMcKEKey_t;




typedef struct sMlmeReqDeriveMcSessionKeyPair
{



    AddressIdentifier_t GroupID;
}MlmeReqDeriveMcSessionKeyPair_t;




typedef struct sMlmeReq
{



    Mlme_t Type;




    union uMlmeParam
    {



        MlmeReqJoin_t Join;



        MlmeReqTxCw_t TxCw;



        MlmeReqPingSlotInfo_t PingSlotInfo;



        MlmeReqDeriveMcKEKey_t DeriveMcKEKey;



        MlmeReqDeriveMcSessionKeyPair_t DeriveMcSessionKeyPair;
    }Req;




    RequestReturnParam_t ReqReturn;
}MlmeReq_t;




typedef struct sMlmeConfirm
{



    Mlme_t MlmeRequest;



    LoRaMacEventInfoStatus_t Status;



    UTIL_TIMER_Time_t TxTimeOnAir;




    uint8_t DemodMargin;



    uint8_t NbGateways;



    uint8_t NbRetries;




    UTIL_TIMER_Time_t BeaconTimingDelay;



    uint8_t BeaconTimingChannel;
}MlmeConfirm_t;




typedef struct sMlmeIndication
{



    Mlme_t MlmeIndication;



    LoRaMacEventInfoStatus_t Status;




    BeaconInfo_t BeaconInfo;
}MlmeIndication_t;
# 1370 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
typedef enum eMib
{





    MIB_DEVICE_CLASS,





    MIB_NETWORK_ACTIVATION,





    MIB_DEV_EUI,





    MIB_JOIN_EUI,



    MIB_SE_PIN,







    MIB_ADR,





    MIB_NET_ID,





    MIB_DEV_ADDR,





    MIB_APP_KEY,





    MIB_NWK_KEY,





    MIB_J_S_INT_KEY,





    MIB_J_S_ENC_KEY,





    MIB_F_NWK_S_INT_KEY,





    MIB_S_NWK_S_INT_KEY,





    MIB_NWK_S_ENC_KEY,





    MIB_APP_S_KEY,





    MIB_MC_KE_KEY,





    MIB_MC_KEY_0,





    MIB_MC_APP_S_KEY_0,





    MIB_MC_NWK_S_KEY_0,





    MIB_MC_KEY_1,





    MIB_MC_APP_S_KEY_1,





    MIB_MC_NWK_S_KEY_1,





    MIB_MC_KEY_2,





    MIB_MC_APP_S_KEY_2,





    MIB_MC_NWK_S_KEY_2,





    MIB_MC_KEY_3,





    MIB_MC_APP_S_KEY_3,





    MIB_MC_NWK_S_KEY_3,







    MIB_PUBLIC_NETWORK,







    MIB_CHANNELS,





    MIB_RX2_CHANNEL,





    MIB_RX2_DEFAULT_CHANNEL,





    MIB_RXC_CHANNEL,





    MIB_RXC_DEFAULT_CHANNEL,





    MIB_CHANNELS_MASK,





    MIB_CHANNELS_DEFAULT_MASK,





    MIB_CHANNELS_NB_TRANS,





    MIB_MAX_RX_WINDOW_DURATION,





    MIB_RECEIVE_DELAY_1,





    MIB_RECEIVE_DELAY_2,





    MIB_JOIN_ACCEPT_DELAY_1,





    MIB_JOIN_ACCEPT_DELAY_2,







    MIB_CHANNELS_DEFAULT_DATARATE,







    MIB_CHANNELS_DATARATE,







    MIB_CHANNELS_TX_POWER,







    MIB_CHANNELS_DEFAULT_TX_POWER,





    MIB_SYSTEM_MAX_RX_ERROR,




    MIB_MIN_RX_SYMBOLS,
# 1687 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    MIB_ANTENNA_GAIN,
# 1698 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    MIB_DEFAULT_ANTENNA_GAIN,



    MIB_NVM_CTXS,



    MIB_ABP_LORAWAN_VERSION,



    MIB_LORAWAN_VERSION,



    MIB_BEACON_INTERVAL,



    MIB_BEACON_RESERVED,



    MIB_BEACON_GUARD,



    MIB_BEACON_WINDOW,



    MIB_BEACON_WINDOW_SLOTS,



    MIB_PING_SLOT_WINDOW,



    MIB_BEACON_SYMBOL_TO_DEFAULT,



    MIB_BEACON_SYMBOL_TO_EXPANSION_MAX,



    MIB_PING_SLOT_SYMBOL_TO_EXPANSION_MAX,




    MIB_BEACON_SYMBOL_TO_EXPANSION_FACTOR,




    MIB_PING_SLOT_SYMBOL_TO_EXPANSION_FACTOR,



    MIB_MAX_BEACON_LESS_PERIOD,







     MIB_PING_SLOT_DATARATE,
}Mib_t;




typedef union uMibParam
{





    DeviceClass_t Class;





    ActivationType_t NetworkActivation;





    uint8_t* DevEui;





    uint8_t* JoinEui;





    uint8_t* SePin;





    
# 1811 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 1811 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AdrEnable;





    uint32_t NetID;





    uint32_t DevAddr;





    uint8_t* AppKey;





    uint8_t* NwkKey;





    uint8_t* JSIntKey;





    uint8_t* JSEncKey;





    uint8_t* FNwkSIntKey;





    uint8_t* SNwkSIntKey;





    uint8_t* NwkSEncKey;





    uint8_t* AppSKey;





    uint8_t* McKEKey;





    uint8_t* McKey0;





    uint8_t* McAppSKey0;





    uint8_t* McNwkSKey0;





    uint8_t* McKey1;





    uint8_t* McAppSKey1;





    uint8_t* McNwkSKey1;





    uint8_t* McKey2;





    uint8_t* McAppSKey2;





    uint8_t* McNwkSKey2;





    uint8_t* McKey3;





    uint8_t* McAppSKey3;





    uint8_t* McNwkSKey3;





    
# 1955 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 1955 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        EnablePublicNetwork;





    ChannelParams_t* ChannelList;





    RxChannelParams_t Rx2Channel;





    RxChannelParams_t Rx2DefaultChannel;





    RxChannelParams_t RxCChannel;





    RxChannelParams_t RxCDefaultChannel;





    uint16_t* ChannelsMask;





    uint16_t* ChannelsDefaultMask;





    uint8_t ChannelsNbTrans;





    uint32_t MaxRxWindow;





    uint32_t ReceiveDelay1;





    uint32_t ReceiveDelay2;





    uint32_t JoinAcceptDelay1;





    uint32_t JoinAcceptDelay2;





    int8_t ChannelsDefaultDatarate;





    int8_t ChannelsDatarate;





    int8_t ChannelsDefaultTxPower;





    int8_t ChannelsTxPower;





    McChannelParams_t MulticastChannel;





    uint32_t SystemMaxRxError;





    uint8_t MinRxSymbols;





    float AntennaGain;





    float DefaultAntennaGain;






    LoRaMacNvmData_t* Contexts;





    Version_t AbpLrWanVersion;





    struct sLrWanVersion
    {
        Version_t LoRaWan;
        Version_t LoRaWanRegion;
    }LrWanVersion;





    uint32_t BeaconInterval;





    uint32_t BeaconReserved;





    uint32_t BeaconGuard;





    uint32_t BeaconWindow;





    uint32_t BeaconWindowSlots;





    uint32_t PingSlotWindow;





    uint32_t BeaconSymbolToDefault;





    uint32_t BeaconSymbolToExpansionMax;





    uint32_t PingSlotSymbolToExpansionMax;






    uint32_t BeaconSymbolToExpansionFactor;






    uint32_t PingSlotSymbolToExpansionFactor;





    uint32_t MaxBeaconLessPeriod;





    int8_t PingSlotDatarate;
}MibParam_t;




typedef struct eMibRequestConfirm
{



    Mib_t Type;




    MibParam_t Param;
}MibRequestConfirm_t;




typedef struct sLoRaMacTxInfo
{



    uint8_t MaxPossibleApplicationDataSize;




    uint8_t CurrentPossiblePayloadSize;
}LoRaMacTxInfo_t;




typedef enum eLoRaMacStatus
{



    LORAMAC_STATUS_OK,



    LORAMAC_STATUS_BUSY,



    LORAMAC_STATUS_SERVICE_UNKNOWN,



    LORAMAC_STATUS_PARAMETER_INVALID,



    LORAMAC_STATUS_FREQUENCY_INVALID,



    LORAMAC_STATUS_DATARATE_INVALID,



    LORAMAC_STATUS_FREQ_AND_DR_INVALID,



    LORAMAC_STATUS_NO_NETWORK_JOINED,



    LORAMAC_STATUS_LENGTH_ERROR,




    LORAMAC_STATUS_REGION_NOT_SUPPORTED,




    LORAMAC_STATUS_SKIPPED_APP_DATA,
# 2289 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    LORAMAC_STATUS_DUTYCYCLE_RESTRICTED,



    LORAMAC_STATUS_NO_CHANNEL_FOUND,



    LORAMAC_STATUS_NO_FREE_CHANNEL_FOUND,



    LORAMAC_STATUS_BUSY_BEACON_RESERVED_TIME,



    LORAMAC_STATUS_BUSY_PING_SLOT_WINDOW_TIME,



    LORAMAC_STATUS_BUSY_UPLINK_COLLISION,



    LORAMAC_STATUS_CRYPTO_ERROR,



    LORAMAC_STATUS_FCNT_HANDLER_ERROR,



    LORAMAC_STATUS_MAC_COMMAD_ERROR,



    LORAMAC_STATUS_CLASS_B_ERROR,



    LORAMAC_STATUS_CONFIRM_QUEUE_ERROR,



    LORAMAC_STATUS_MC_GROUP_UNDEFINED,



    LORAMAC_STATUS_ERROR
}LoRaMacStatus_t;





typedef struct sLoRaMacPrimitives
{





    void ( *MacMcpsConfirm )( McpsConfirm_t* McpsConfirm );





    void ( *MacMcpsIndication )( McpsIndication_t* McpsIndication );





    void ( *MacMlmeConfirm )( MlmeConfirm_t* MlmeConfirm );





    void ( *MacMlmeIndication )( MlmeIndication_t* MlmeIndication );
}LoRaMacPrimitives_t;




typedef struct sLoRaMacCallback
{
# 2385 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    uint8_t ( *GetBatteryLevel )( void );





    float ( *GetTemperatureLevel )( void );






    void ( *NvmDataChange )( uint16_t notifyFlags );






    void ( *MacProcessNotify )( void );
}LoRaMacCallback_t;





static const uint8_t LoRaMacMaxEirpTable[] = { 8, 10, 12, 13, 14, 16, 18, 20, 21, 24, 26, 27, 29, 30, 33, 36 };
# 2436 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacInitialization( LoRaMacPrimitives_t* primitives, LoRaMacCallback_t* callbacks, LoRaMacRegion_t region );
# 2445 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacStart( void );
# 2454 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacStop( void );







# 2461 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
_Bool 
# 2461 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    LoRaMacIsBusy( void );






void LoRaMacProcess( void );
# 2495 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacQueryTxPossible( uint8_t size, LoRaMacTxInfo_t* txInfo );
# 2513 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacChannelAdd( uint8_t id, ChannelParams_t params );
# 2527 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacChannelRemove( uint8_t id );
# 2542 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelSetup( McChannelParams_t *channel );
# 2556 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelDelete( AddressIdentifier_t groupID );
# 2566 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
uint8_t LoRaMacMcChannelGetGroupId( uint32_t mcAddress );
# 2583 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelSetupRxParams( AddressIdentifier_t groupID, McRxParams_t *rxParams, uint8_t *status );
# 2611 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMibGetRequestConfirm( MibRequestConfirm_t* mibGet );
# 2642 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMibSetRequestConfirm( MibRequestConfirm_t* mibSet );
# 2675 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMlmeRequest( MlmeReq_t* mlmeRequest );
# 2709 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcpsRequest( McpsReq_t* mcpsRequest );
# 2721 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacDeInitialization( void );
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 1
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
#define __LORAMACCLASSB_H__ 
# 51 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
typedef enum eBeaconState
{



    BEACON_STATE_ACQUISITION,



    BEACON_STATE_ACQUISITION_BY_TIME,



    BEACON_STATE_TIMEOUT,



    BEACON_STATE_BEACON_MISSED,




    BEACON_STATE_REACQUISITION,



    BEACON_STATE_LOCKED,



    BEACON_STATE_HALT,




    BEACON_STATE_IDLE,



    BEACON_STATE_GUARD,



    BEACON_STATE_RX,



    BEACON_STATE_LOST,
}BeaconState_t;




typedef enum ePingSlotState
{



    PINGSLOT_STATE_CALC_PING_OFFSET,



    PINGSLOT_STATE_SET_TIMER,



    PINGSLOT_STATE_IDLE,



    PINGSLOT_STATE_RX,
}PingSlotState_t;




typedef struct sPingSlotContext
{




    uint32_t PingSlotWindow;



    uint16_t PingOffset;




    uint16_t SymbolTimeout;



    MulticastCtx_t *NextMulticastChannel;
}PingSlotContext_t;





typedef struct sBeaconContext
{
    struct sBeaconCtrl
    {



        uint8_t BeaconMode : 1;



        uint8_t BeaconAcquired : 1;



        uint8_t BeaconDelaySet : 1;



        uint8_t BeaconChannelSet : 1;



        uint8_t AcquisitionPending : 1;



        uint8_t ResumeBeaconing : 1;
    }Ctrl;




    float Temperature;



    SysTime_t BeaconTime;



    SysTime_t LastBeaconRx;



    SysTime_t NextBeaconRx;





    UTIL_TIMER_Time_t NextBeaconRxAdjusted;




    uint16_t SymbolTimeout;



    UTIL_TIMER_Time_t BeaconWindowMovement;



    uint8_t BeaconTimingChannel;



    UTIL_TIMER_Time_t BeaconTimingDelay;
    UTIL_TIMER_Time_t TimeStamp;
}BeaconContext_t;




typedef struct sLoRaMacClassBCallback
{





    float ( *GetTemperatureLevel )( void );






    void ( *MacProcessNotify )( void );
}LoRaMacClassBCallback_t;




typedef struct sLoRaMacClassBParams
{



    MlmeIndication_t *MlmeIndication;



    McpsIndication_t *McpsIndication;



    MlmeConfirm_t *MlmeConfirm;



    LoRaMacFlags_t *LoRaMacFlags;



    uint32_t *LoRaMacDevAddr;



    LoRaMacRegion_t *LoRaMacRegion;



    LoRaMacParams_t *LoRaMacParams;



    MulticastCtx_t *MulticastChannels;
}LoRaMacClassBParams_t;





typedef void ( *LoRaMacClassBNvmEvent )( void );
# 297 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
void LoRaMacClassBInit( LoRaMacClassBParams_t *classBParams, LoRaMacClassBCallback_t *callbacks,
                        LoRaMacClassBNvmData_t* nvm );






void LoRaMacClassBSetBeaconState( BeaconState_t beaconState );






void LoRaMacClassBSetPingSlotState( PingSlotState_t pingSlotState );






void LoRaMacClassBSetMulticastSlotState( PingSlotState_t multicastSlotState );







# 326 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 326 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsAcquisitionInProgress( void );




void LoRaMacClassBBeaconTimerEvent( void* context );




void LoRaMacClassBPingSlotTimerEvent( void* context );




void LoRaMacClassBMulticastSlotTimerEvent( void* context );
# 350 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"

# 350 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 350 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBRxBeacon( uint8_t *payload, uint16_t size );








# 358 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 358 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsBeaconExpected( void );








# 366 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 366 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsPingExpected( void );








# 374 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 374 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsMulticastExpected( void );







# 381 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 381 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsAcquisitionPending( void );







# 388 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 388 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBIsBeaconModeActive( void );




void LoRaMacClassBHaltBeaconing( void );




void LoRaMacClassBResumeBeaconing( void );






void LoRaMacClassBSetPingSlotInfo( uint8_t periodicity );
# 414 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
LoRaMacStatus_t LoRaMacClassBSwitchClass( DeviceClass_t nextClass );
# 429 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
LoRaMacStatus_t LoRaMacClassBMibGetRequestConfirm( MibRequestConfirm_t *mibGet );
# 445 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
LoRaMacStatus_t LoRaMacMibClassBSetRequestConfirm( MibRequestConfirm_t *mibSet );




void LoRaMacClassBPingSlotInfoAns( void );
# 460 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
uint8_t LoRaMacClassBPingSlotChannelReq( uint8_t datarate, uint32_t frequency );
# 469 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
void LoRaMacClassBBeaconTimingAns( uint16_t beaconTimingDelay, uint8_t beaconTimingChannel, UTIL_TIMER_Time_t lastRxDone );




void LoRaMacClassBDeviceTimeAns( void );
# 483 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"

# 483 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h" 3 4
_Bool 
# 483 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
    LoRaMacClassBBeaconFreqReq( uint32_t frequency );
# 492 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
UTIL_TIMER_Time_t LoRaMacClassBIsUplinkCollision( UTIL_TIMER_Time_t txTimeOnAir );





void LoRaMacClassBStopRxSlots( void );





void LoRaMacClassBStartRxSlots( void );
# 514 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.h"
void LoRaMacClassBSetMulticastPeriodicity( MulticastCtx_t* multicastChannel );

void LoRaMacClassBProcess( void );
# 25 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBConfig.h" 1
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBConfig.h"
#define __LORAMACCLASSBCONFIG_H__ 
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBConfig.h"
#define CLASSB_BEACON_INTERVAL 128000




#define CLASSB_BEACON_RESERVED 2120




#define CLASSB_BEACON_GUARD 3000




#define CLASSB_BEACON_WINDOW 122880




#define CLASSB_BEACON_WINDOW_SLOTS 4096




#define CLASSB_PING_SLOT_WINDOW 30




#define CLASSB_MAX_BEACON_LESS_PERIOD 7200000




#define CLASSB_BEACON_DELAY_BEACON_TIMING_ANS 30




#define CLASSB_BEACON_SYMBOL_TO_DEFAULT 8




#define CLASSB_BEACON_SYMBOL_TO_EXPANSION_MAX 255




#define CLASSB_PING_SLOT_SYMBOL_TO_EXPANSION_MAX 30





#define CLASSB_BEACON_SYMBOL_TO_EXPANSION_FACTOR 2




#define CLASSB_WINDOW_MOVE_DEFAULT 2




#define CLASSB_WINDOW_MOVE_EXPANSION_MAX 256




#define CLASSB_WINDOW_MOVE_EXPANSION_FACTOR 2
# 27 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 1
# 40 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
#define __LORAMAC_CONFIRMQUEUE_H__ 
# 55 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
#define LORA_MAC_MLME_CONFIRM_QUEUE_LEN 5




typedef struct sMlmeConfirmQueue
{



    Mlme_t Request;



    LoRaMacEventInfoStatus_t Status;



    
# 73 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
   _Bool 
# 73 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
        ReadyToHandle;




    
# 78 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
   _Bool 
# 78 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
        RestrictCommonReadyToHandle;
}MlmeConfirmQueue_t;






void LoRaMacConfirmQueueInit( LoRaMacPrimitives_t* primitive );
# 95 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"

# 95 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
_Bool 
# 95 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
    LoRaMacConfirmQueueAdd( MlmeConfirmQueue_t* mlmeConfirm );







# 102 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
_Bool 
# 102 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
    LoRaMacConfirmQueueRemoveLast( void );







# 109 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
_Bool 
# 109 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
    LoRaMacConfirmQueueRemoveFirst( void );
# 118 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
void LoRaMacConfirmQueueSetStatus( LoRaMacEventInfoStatus_t status, Mlme_t request );
# 127 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
LoRaMacEventInfoStatus_t LoRaMacConfirmQueueGetStatus( Mlme_t request );






void LoRaMacConfirmQueueSetStatusCmn( LoRaMacEventInfoStatus_t status );






LoRaMacEventInfoStatus_t LoRaMacConfirmQueueGetStatusCmn( void );
# 150 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"

# 150 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
_Bool 
# 150 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
    LoRaMacConfirmQueueIsCmdActive( Mlme_t request );






void LoRaMacConfirmQueueHandleCb( MlmeConfirm_t* mlmeConfirm );






uint8_t LoRaMacConfirmQueueGetCnt( void );







# 171 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h" 3 4
_Bool 
# 171 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacConfirmQueue.h"
    LoRaMacConfirmQueueIsFull( void );
# 29 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 1
# 24 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
#define __RADIO_H__ 
# 37 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
typedef enum
{
    MODEM_FSK = 0,
    MODEM_LORA,
}RadioModems_t;




typedef enum
{
    RF_IDLE = 0,
    RF_RX_RUNNING,
    RF_TX_RUNNING,
    RF_CAD,
}RadioState_t;




typedef struct
{



    void ( *TxDone )( void );



    void ( *TxTimeout )( void );
# 77 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    void ( *RxDone )( uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr );



    void ( *RxTimeout )( void );



    void ( *RxError )( void );





    void ( *FhssChangeChannel )( uint8_t currentChannel );






    void ( *CadDone ) ( 
# 98 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                       _Bool 
# 98 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                            channelActivityDetected );




    void ( *GnssDone )( void );




    void ( *WifiDone )( void );
}RadioEvents_t;




struct Radio_s
{





    void ( *Init )( RadioEvents_t *events );





    RadioState_t ( *GetStatus )( void );





    void ( *SetModem )( RadioModems_t modem );





    void ( *SetChannel )( uint32_t freq );
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
   _Bool 
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
           ( *IsChannelFree )( uint32_t freq, uint32_t rxBandwidth, int16_t rssiThresh, uint32_t maxCarrierSenseTime );
# 163 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    uint32_t ( *Random )( void );
# 203 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    void ( *SetRxConfig )( RadioModems_t modem, uint32_t bandwidth,
                              uint32_t datarate, uint8_t coderate,
                              uint32_t bandwidthAfc, uint16_t preambleLen,
                              uint16_t symbTimeout, 
# 206 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                                   _Bool 
# 206 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                                        fixLen,
                              uint8_t payloadLen,
                              
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                             _Bool 
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                  crcOn, 
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                         _Bool 
# 208 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                              freqHopOn, uint8_t hopPeriod,
                              
# 209 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                             _Bool 
# 209 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                  iqInverted, 
# 209 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                              _Bool 
# 209 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                                   rxContinuous );
# 245 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    void ( *SetTxConfig )( RadioModems_t modem, int8_t power, uint32_t fdev,
                              uint32_t bandwidth, uint32_t datarate,
                              uint8_t coderate, uint16_t preambleLen,
                              
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                             _Bool 
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                  fixLen, 
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                          _Bool 
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                               crcOn, 
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                                      _Bool 
# 248 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                                           freqHopOn,
                              uint8_t hopPeriod, 
# 249 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                                _Bool 
# 249 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                                     iqInverted, uint32_t timeout );






    
# 256 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
   _Bool 
# 256 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
           ( *CheckRfFrequency )( uint32_t frequency );
# 283 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    uint32_t ( *TimeOnAir )( RadioModems_t modem, uint32_t bandwidth,
                              uint32_t datarate, uint8_t coderate,
                              uint16_t preambleLen, 
# 285 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                                   _Bool 
# 285 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                                        fixLen, uint8_t payloadLen,
                              
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                             _Bool 
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                  crcOn );







    void ( *Send )( uint8_t *buffer, uint8_t size );



    void ( *Sleep )( void );



    void ( *Standby )( void );





    void ( *Rx )( uint32_t timeout );



    void ( *StartCad )( void );







    void ( *SetTxContinuousWave )( uint32_t freq, int8_t power, uint16_t time );





    int16_t ( *Rssi )( RadioModems_t modem );






    void ( *Write )( uint32_t addr, uint8_t data );






    uint8_t ( *Read )( uint32_t addr );







    void ( *WriteBuffer )( uint32_t addr, uint8_t *buffer, uint8_t size );







    void ( *ReadBuffer )( uint32_t addr, uint8_t *buffer, uint8_t size );






    void ( *SetMaxPayloadLength )( RadioModems_t modem, uint8_t max );







    void ( *SetPublicNetwork )( 
# 371 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h" 3 4
                                  _Bool 
# 371 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
                                       enable );





    uint32_t ( *GetWakeupTime )( void );



    void ( *IrqProcess )( void );
# 393 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    void ( *RxBoosted )( uint32_t timeout );
# 402 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/radio/radio.h"
    void ( *SetRxDutyCycle ) ( uint32_t rxTime, uint32_t sleepTime );
};







extern const struct Radio_s Radio;
# 30 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 1
# 53 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
#define __REGION_H__ 
# 63 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 1
# 64 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 2

# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 1
# 38 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
#define __REGIONCOMMON_H__ 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h" 1
# 47 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 1
# 48 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 2






#define REGION_COMMON_DEFAULT_RECEIVE_DELAY1 1000




#define REGION_COMMON_DEFAULT_RECEIVE_DELAY2 ( REGION_COMMON_DEFAULT_RECEIVE_DELAY1 + 1000 )




#define REGION_COMMON_DEFAULT_JOIN_ACCEPT_DELAY1 5000




#define REGION_COMMON_DEFAULT_JOIN_ACCEPT_DELAY2 ( REGION_COMMON_DEFAULT_JOIN_ACCEPT_DELAY1 + 1000 )




#define REGION_COMMON_DEFAULT_ADR_ACK_LIMIT 64




#define REGION_COMMON_DEFAULT_ADR_ACK_DELAY 32




#define REGION_COMMON_DEFAULT_MAX_FCNT_GAP 16384




#define REGION_COMMON_DEFAULT_ACK_TIMEOUT 2000





#define REGION_COMMON_DEFAULT_ACK_TIMEOUT_RND 1000




#define REGION_COMMON_DEFAULT_RX1_DR_OFFSET 0




#define REGION_COMMON_DEFAULT_DOWNLINK_DWELL_TIME 0







#define REGION_COMMON_DEFAULT_PING_SLOT_PERIODICITY 7

typedef struct sRegionCommonLinkAdrParams
{



    uint8_t NbRep;



    int8_t Datarate;



    int8_t TxPower;



    uint8_t ChMaskCtrl;



    uint16_t ChMask;
}RegionCommonLinkAdrParams_t;

typedef struct sRegionCommonLinkAdrReqVerifyParams
{



    Version_t Version;



    uint8_t Status;



    
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 152 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
        AdrEnabled;



    int8_t Datarate;



    int8_t TxPower;



    uint8_t NbRep;



    int8_t CurrentDatarate;



    int8_t CurrentTxPower;



    int8_t CurrentNbRep;



    uint8_t NbChannels;



    uint16_t* ChannelsMask;



    int8_t MinDatarate;



    int8_t MaxDatarate;



    ChannelParams_t* Channels;



    int8_t MinTxPower;



    int8_t MaxTxPower;
}RegionCommonLinkAdrReqVerifyParams_t;

typedef struct sRegionCommonRxBeaconSetupParams
{



    const uint8_t* Datarates;



    uint32_t Frequency;



    uint8_t BeaconSize;



    uint8_t BeaconDatarate;



    uint8_t BeaconChannelBW;



    uint32_t RxTime;



    uint16_t SymbolTimeout;
}RegionCommonRxBeaconSetupParams_t;

typedef struct sRegionCommonCountNbOfEnabledChannelsParams
{



    
# 244 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 244 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
        Joined;



    uint8_t Datarate;



    uint16_t* ChannelsMask;



    ChannelParams_t* Channels;



    Band_t* Bands;



    uint16_t MaxNbChannels;





    uint16_t* JoinChannels;
}RegionCommonCountNbOfEnabledChannelsParams_t;

typedef struct sRegionCommonIdentifyChannelsParam
{



    UTIL_TIMER_Time_t AggrTimeOff;



    UTIL_TIMER_Time_t LastAggrTx;



    
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
        DutyCycleEnabled;



    uint8_t MaxBands;



    SysTime_t ElapsedTimeSinceStartUp;



    
# 298 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 298 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
        LastTxIsJoinRequest;



    UTIL_TIMER_Time_t ExpectedTimeOnAir;



    RegionCommonCountNbOfEnabledChannelsParams_t* CountNbOfEnabledChannelsParam;
}RegionCommonIdentifyChannelsParam_t;

typedef struct sRegionCommonSetDutyCycleParams
{



    UTIL_TIMER_Time_t DutyCycleTimePeriod;



    uint8_t MaxBands;



    Band_t* Bands;
}RegionCommonSetDutyCycleParams_t;

typedef struct sRegionCommonGetNextLowerTxDrParams
{
    int8_t CurrentDr;
    int8_t MaxDr;
    int8_t MinDr;
    uint8_t NbChannels;
    uint16_t* ChannelsMask;
    ChannelParams_t* Channels;
}RegionCommonGetNextLowerTxDrParams_t;
# 347 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonValueInRange( int8_t value, int8_t min, int8_t max );
# 367 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"

# 367 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
_Bool 
# 367 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
    RegionCommonChanVerifyDr( uint8_t nbChannels, uint16_t* channelsMask, int8_t dr,
                            int8_t minDr, int8_t maxDr, ChannelParams_t* channels );
# 382 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"

# 382 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
_Bool 
# 382 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
    RegionCommonChanDisable( uint16_t* channelsMask, uint8_t id, uint8_t maxChannels );
# 396 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonCountChannels( uint16_t* channelsMask, uint8_t startIdx, uint8_t stopIdx );
# 408 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonChanMaskCopy( uint16_t* channelsMaskDest, uint16_t* channelsMaskSrc, uint8_t len );
# 422 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonSetBandTxDone( Band_t* band, UTIL_TIMER_Time_t lastTxAirTime, 
# 422 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                                                        _Bool 
# 422 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                                                             joined, SysTime_t elapsedTimeSinceStartup );
# 444 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
UTIL_TIMER_Time_t RegionCommonUpdateBandTimeOff( 
# 444 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                          _Bool 
# 444 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                               joined, Band_t* bands,
                                           uint8_t nbBands, 
# 445 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                                           _Bool 
# 445 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                                                dutyCycleEnabled,
                                           
# 446 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                          _Bool 
# 446 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                               lastTxIsJoinRequest, SysTime_t elapsedTimeSinceStartup,
                                           UTIL_TIMER_Time_t expectedTimeOnAir );
# 461 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonParseLinkAdrReq( uint8_t* payload, RegionCommonLinkAdrParams_t* parseLinkAdr );
# 477 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonLinkAdrReqVerifyParams( RegionCommonLinkAdrReqVerifyParams_t* verifyParams, int8_t* dr, int8_t* txPow, uint8_t* nbRep );
# 488 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint32_t RegionCommonComputeSymbolTimeLoRa( uint8_t phyDr, uint32_t bandwidthInHz );
# 497 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint32_t RegionCommonComputeSymbolTimeFsk( uint8_t phyDrInKbps );
# 515 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonComputeRxWindowParameters( uint32_t tSymbolInUs, uint8_t minRxSymbols, uint32_t rxErrorInMs, uint32_t wakeUpTimeInMs, uint32_t* windowTimeoutInSymbols, int32_t* windowOffsetInMs );
# 532 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonComputeTxPower( int8_t txPowerIndex, float maxEirp, float antennaGain );






void RegionCommonRxBeaconSetup( RegionCommonRxBeaconSetupParams_t* rxBeaconSetupParams );
# 554 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonCountNbOfEnabledChannels( RegionCommonCountNbOfEnabledChannelsParams_t* countNbOfEnabledChannelsParams,
                                           uint8_t* enabledChannels, uint8_t* nbEnabledChannels, uint8_t* nbRestrictedChannels );
# 578 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
LoRaMacStatus_t RegionCommonIdentifyChannels( RegionCommonIdentifyChannelsParam_t* identifyChannelsParam,
                                              UTIL_TIMER_Time_t* aggregatedTimeOff, uint8_t* enabledChannels,
                                              uint8_t* nbEnabledChannels, uint8_t* nbRestrictedChannels,
                                              UTIL_TIMER_Time_t* nextTxDelay );
# 590 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonGetNextLowerTxDr( RegionCommonGetNextLowerTxDrParams_t *params );
# 601 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonLimitTxPower( int8_t txPower, int8_t maxBandTxPower );
# 612 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint32_t RegionCommonGetBandwidth( uint32_t drIndex, const uint32_t* bandwidths );



typedef uint32_t (*IsSingleChannel_t)(void);

typedef uint8_t (*AlternateDr_t)(void);

typedef struct SingleChannel_s
{
    IsSingleChannel_t IsSingleChannel;
    AlternateDr_t AlternateDr;
}SingleChannel_t;

int32_t US915_SingleChannelRegisterCallback(SingleChannel_t* SingleChannel);

int32_t AU915_SingleChannelRegisterCallback(SingleChannel_t* SingleChannel);
# 66 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 2




#define LC(channelIndex) ( uint16_t )( 1 << ( channelIndex - 1 ) )





#define REGION_VERSION 0x00010003







typedef enum ePhyAttribute
{




    PHY_FREQUENCY,



    PHY_MIN_RX_DR,



    PHY_MIN_TX_DR,



    PHY_MAX_RX_DR,



    PHY_MAX_TX_DR,





    PHY_TX_DR,



    PHY_DEF_TX_DR,




    PHY_RX_DR,



    PHY_MAX_TX_POWER,




    PHY_TX_POWER,



    PHY_DEF_TX_POWER,



    PHY_DEF_ADR_ACK_LIMIT,



    PHY_DEF_ADR_ACK_DELAY,



    PHY_MAX_PAYLOAD,



    PHY_DUTY_CYCLE,



    PHY_MAX_RX_WINDOW,



    PHY_RECEIVE_DELAY1,



    PHY_RECEIVE_DELAY2,



    PHY_JOIN_ACCEPT_DELAY1,



    PHY_JOIN_ACCEPT_DELAY2,



    PHY_MAX_FCNT_GAP,



    PHY_ACK_TIMEOUT,



    PHY_DEF_DR1_OFFSET,



    PHY_DEF_RX2_FREQUENCY,



    PHY_DEF_RX2_DR,



    PHY_CHANNELS_MASK,



    PHY_CHANNELS_DEFAULT_MASK,



    PHY_MAX_NB_CHANNELS,



    PHY_CHANNELS,



    PHY_DEF_UPLINK_DWELL_TIME,



    PHY_DEF_DOWNLINK_DWELL_TIME,



    PHY_DEF_MAX_EIRP,



    PHY_DEF_ANTENNA_GAIN,



    PHY_NEXT_LOWER_TX_DR,



    PHY_BEACON_INTERVAL,



    PHY_BEACON_RESERVED,



    PHY_BEACON_GUARD,



    PHY_BEACON_WINDOW,



    PHY_BEACON_WINDOW_SLOTS,



    PHY_PING_SLOT_WINDOW,



    PHY_BEACON_SYMBOL_TO_DEFAULT,



    PHY_BEACON_SYMBOL_TO_EXPANSION_MAX,



    PHY_PING_SLOT_SYMBOL_TO_EXPANSION_MAX,




    PHY_BEACON_SYMBOL_TO_EXPANSION_FACTOR,




    PHY_PING_SLOT_SYMBOL_TO_EXPANSION_FACTOR,



    PHY_MAX_BEACON_LESS_PERIOD,



    PHY_BEACON_DELAY_BEACON_TIMING_ANS,



    PHY_BEACON_CHANNEL_FREQ,



    PHY_BEACON_FORMAT,



    PHY_BEACON_CHANNEL_DR,



    PHY_BEACON_NB_CHANNELS,



    PHY_BEACON_CHANNEL_OFFSET,



    PHY_PING_SLOT_CHANNEL_FREQ,



    PHY_PING_SLOT_CHANNEL_DR,



    PHY_PING_SLOT_NB_CHANNELS,



    PHY_SF_FROM_DR,



    PHY_BW_FROM_DR,
}PhyAttribute_t;




typedef enum eInitType
{






    INIT_TYPE_DEFAULTS,




    INIT_TYPE_RESET_TO_DEFAULT_CHANNELS,




    INIT_TYPE_ACTIVATE_DEFAULT_CHANNELS
}InitType_t;

typedef enum eChannelsMask
{



    CHANNELS_MASK,



    CHANNELS_DEFAULT_MASK
}ChannelsMask_t;




typedef struct sBeaconFormat
{



    uint8_t BeaconSize;



    uint8_t Rfu1Size;



    uint8_t Rfu2Size;
}BeaconFormat_t;




typedef union uPhyParam
{



    uint32_t Value;



    float fValue;



    uint16_t* ChannelsMask;



    ChannelParams_t* Channels;



    BeaconFormat_t BeaconFormat;



    UTIL_TIMER_Time_t DutyCycleTimePeriod;
}PhyParam_t;




typedef struct sGetPhyParams
{



    PhyAttribute_t Attribute;





    int8_t Datarate;






    uint8_t UplinkDwellTime;






    uint8_t DownlinkDwellTime;





    uint8_t Channel;
}GetPhyParams_t;




typedef struct sSetBandTxDoneParams
{



    uint8_t Channel;



    
# 458 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 458 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        Joined;



    UTIL_TIMER_Time_t LastTxDoneTime;



    UTIL_TIMER_Time_t LastTxAirTime;



    SysTime_t ElapsedTimeSinceStartUp;
}SetBandTxDoneParams_t;




typedef struct sInitDefaultsParams
{



    void* NvmGroup1;



    void* NvmGroup2;



    InitType_t Type;
}InitDefaultsParams_t;




typedef union uVerifyParams
{



    uint32_t Frequency;



    int8_t TxPower;



    
# 508 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 508 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        DutyCycle;



    struct sDatarateParams
    {



        int8_t Datarate;



        uint8_t DownlinkDwellTime;



        uint8_t UplinkDwellTime;
    }DatarateParams;
}VerifyParams_t;




typedef struct sApplyCFListParams
{



    uint8_t* Payload;



    uint8_t Size;
}ApplyCFListParams_t;




typedef struct sChanMaskSetParams
{



    uint16_t* ChannelsMaskIn;



    ChannelsMask_t ChannelsMaskType;
}ChanMaskSetParams_t;




typedef struct sRxConfigParams
{



    uint8_t Channel;



    int8_t Datarate;



    uint8_t Bandwidth;



    int8_t DrOffset;



    uint32_t Frequency;



     uint32_t WindowTimeout;



    int32_t WindowOffset;



    uint8_t DownlinkDwellTime;



    
# 599 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 599 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        RxContinuous;



    LoRaMacRxSlot_t RxSlot;
}RxConfigParams_t;




typedef struct sTxConfigParams
{



    uint8_t Channel;



    int8_t Datarate;



    int8_t TxPower;



    float MaxEirp;



    float AntennaGain;



    uint16_t PktLen;
}TxConfigParams_t;




typedef struct sLinkAdrReqParams
{



    Version_t Version;



    uint8_t* Payload;



    uint8_t PayloadSize;



    uint8_t UplinkDwellTime;



    
# 661 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 661 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        AdrEnabled;



    int8_t CurrentDatarate;



    int8_t CurrentTxPower;



    uint8_t CurrentNbRep;
}LinkAdrReqParams_t;




typedef struct sRxParamSetupReqParams
{



    int8_t Datarate;



    int8_t DrOffset;



    uint32_t Frequency;
}RxParamSetupReqParams_t;




typedef struct sNewChannelReqParams
{



    ChannelParams_t* NewChannel;



    int8_t ChannelId;
}NewChannelReqParams_t;




typedef struct sTxParamSetupReqParams
{



    uint8_t UplinkDwellTime;



    uint8_t DownlinkDwellTime;



    uint8_t MaxEirp;
}TxParamSetupReqParams_t;




typedef struct sDlChannelReqParams
{



    uint8_t ChannelId;



    uint32_t Rx1Frequency;
}DlChannelReqParams_t;




typedef enum eAlternateDrType
{



    ALTERNATE_DR,



    ALTERNATE_DR_RESTORE
}AlternateDrType_t;




typedef struct sNextChanParams
{



    UTIL_TIMER_Time_t AggrTimeOff;



    UTIL_TIMER_Time_t LastAggrTx;



    int8_t Datarate;



    
# 779 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 779 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        Joined;



    
# 783 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 783 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        DutyCycleEnabled;



    SysTime_t ElapsedTimeSinceStartUp;



    
# 791 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 791 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        LastTxIsJoinRequest;



    uint16_t PktLen;
}NextChanParams_t;




typedef struct sChannelAddParams
{



    ChannelParams_t* NewChannel;



    uint8_t ChannelId;
}ChannelAddParams_t;




typedef struct sChannelRemoveParams
{



    uint8_t ChannelId;
}ChannelRemoveParams_t;




typedef struct sContinuousWaveParams
{



    uint8_t Channel;



    int8_t Datarate;



    int8_t TxPower;



    float MaxEirp;



    float AntennaGain;



    uint16_t Timeout;
}ContinuousWaveParams_t;




typedef struct sRxBeaconSetupParams
{



    uint16_t SymbolTimeout;



    uint32_t RxTime;



    uint32_t Frequency;
}RxBeaconSetup_t;
# 884 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 884 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 884 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionIsActive( LoRaMacRegion_t region );
# 895 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
PhyParam_t RegionGetPhyParam( LoRaMacRegion_t region, GetPhyParams_t* getPhy );
# 904 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionSetBandTxDone( LoRaMacRegion_t region, SetBandTxDoneParams_t* txDone );
# 913 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionInitDefaults( LoRaMacRegion_t region, InitDefaultsParams_t* params );
# 926 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 926 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 926 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionVerify( LoRaMacRegion_t region, VerifyParams_t* verify, PhyAttribute_t phyAttribute );
# 936 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionApplyCFList( LoRaMacRegion_t region, ApplyCFListParams_t* applyCFList );
# 947 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 947 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 947 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionChanMaskSet( LoRaMacRegion_t region, ChanMaskSetParams_t* chanMaskSet );
# 960 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 960 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 960 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionRxConfig( LoRaMacRegion_t region, RxConfigParams_t* rxConfig, int8_t* datarate );
# 1015 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionComputeRxWindowParameters( LoRaMacRegion_t region, int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 1030 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 1030 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 1030 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionTxConfig( LoRaMacRegion_t region, TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 1049 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionLinkAdrReq( LoRaMacRegion_t region, LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 1060 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionRxParamSetupReq( LoRaMacRegion_t region, RxParamSetupReqParams_t* rxParamSetupReq );
# 1071 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionNewChannelReq( LoRaMacRegion_t region, NewChannelReqParams_t* newChannelReq );
# 1084 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionTxParamSetupReq( LoRaMacRegion_t region, TxParamSetupReqParams_t* txParamSetupReq );
# 1095 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionDlChannelReq( LoRaMacRegion_t region, DlChannelReqParams_t* dlChannelReq );
# 1108 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionAlternateDr( LoRaMacRegion_t region, int8_t currentDr, AlternateDrType_t type );
# 1124 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
LoRaMacStatus_t RegionNextChannel( LoRaMacRegion_t region, NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 1135 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
LoRaMacStatus_t RegionChannelAdd( LoRaMacRegion_t region, ChannelAddParams_t* channelAdd );
# 1146 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 1146 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 1146 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionChannelsRemove( LoRaMacRegion_t region, ChannelRemoveParams_t* channelRemove );
# 1155 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionSetContinuousWave( LoRaMacRegion_t region, ContinuousWaveParams_t* continuousWave );
# 1168 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionApplyDrOffset( LoRaMacRegion_t region, uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );
# 1177 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionRxBeaconSetup( LoRaMacRegion_t region, RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );






Version_t RegionGetVersion( void );
# 31 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2
# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/udrv/system/udrv_system.h" 1

#define _UDRV_SYSTEM_H_ 







# 1 "/home/jenkins/workspace/RUI_Release/rui-v3/component/udrv/timer/udrv_timer.h" 1

#define _UDRV_TIMER_H_ 







typedef enum {
        TIMER_0 = 0,
        TIMER_1 = 1,
        TIMER_2 = 2,
        TIMER_3 = 3,
        TIMER_4 = 4,
        TIMER_ID_MAX = 5,
} TimerID_E;

typedef enum {
        SYSTIMER_LORAWAN = 0,
        SYSTIMER_TRANSPARENT_MODE = 1,
        SYSTIMER_PROTOCOL_MODE = 2,
        SYSTIMER_LED = 3,
        SYSTIMER_LCT = 4,
        SYSTIMER_ID_MAX = 5,
} SysTimerID_E;

typedef enum hwtmr_op_mode {
    HTMR_ONESHOT = 0,
    HTMR_PERIODIC = 1,
} TimerMode_E;

typedef void (*timer_handler) (void *m_data);


struct udrv_timer_api {
    void (*TIMER_INIT) (void);
    int32_t (*TIMER_CREATE) (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
    int32_t (*TIMER_START) (TimerID_E timer_id, uint32_t count, void *m_data);
    int32_t (*TIMER_STOP) (TimerID_E timer_id);
};

void udrv_timer_init (void);
int32_t udrv_timer_create (TimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t udrv_timer_start (TimerID_E timer_id, uint32_t count, void *m_data);
int32_t udrv_timer_stop (TimerID_E timer_id);

int32_t udrv_system_timer_create (SysTimerID_E timer_id, timer_handler tmr_handler, TimerMode_E mode);
int32_t udrv_system_timer_start (SysTimerID_E timer_id, uint32_t count, void *m_data);
int32_t udrv_system_timer_stop (SysTimerID_E timer_id);

void udrv_system_timer_handler_handler (void *pdata);

unsigned long udrv_get_microsecond(void);
# 11 "/home/jenkins/workspace/RUI_Release/rui-v3/component/udrv/system/udrv_system.h" 2

#define RANDOM_LENGTH 4
#define SEED_LENGTH 4


#define EVENT_QUEUE_SIZE (128)
#define EVENT_DATA_SIZE (8)




typedef enum
{
    UDRV_SYS_EVT_OP_SERIAL_UART = 0x00,







    UDRV_SYS_EVT_OP_LORAWAN,
    UDRV_SYS_EVT_OP_LORAWAN_JOIN_CB,

    UDRV_SYS_EVT_OP_USER_APP,
    UDRV_SYS_EVT_OP_USER_TIMER,
    UDRV_SYS_EVT_OP_SYS_TIMER,



    UDRV_SYS_EVT_OP_SERIAL_FALLBACK,
    UDRV_SYS_EVT_OP_RTC,
    UDRV_SYS_EVT_OP_GPIO_INTERRUPT,
} udrv_system_event_op_t;

typedef struct
{
    udrv_system_event_op_t request;
    void *p_context;
} udrv_system_event_t;

typedef void (*UDRV_TASK_HANDLER) (void);

void udrv_system_event_init(void);

int32_t udrv_system_event_produce(udrv_system_event_t *event);

void udrv_system_event_consume(void);

void udrv_system_reboot(void);
# 69 "/home/jenkins/workspace/RUI_Release/rui-v3/component/udrv/system/udrv_system.h"
void udrv_system_critical_section_begin(uint32_t *mask);

void udrv_system_critical_section_end (uint32_t *mask);

unsigned long udrv_system_random (unsigned long maxvalue);

void udrv_system_randomseed(unsigned long seed);

int32_t udrv_system_user_app_timer_create (timer_handler tmr_handler, TimerMode_E mode);

int32_t udrv_system_user_app_timer_start (uint32_t count, void *m_data);

int32_t udrv_system_user_app_timer_stop (void);

int32_t udrv_create_thread(char *name, UDRV_TASK_HANDLER handler);
void udrv_destroy_thread(char *name);
void udrv_destroy_myself(void);
void udrv_thread_lock(void);
void udrv_thread_unlock(void);
# 32 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 2



extern 
# 35 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
      _Bool 
# 35 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
           udrv_powersave_in_sleep;
static udrv_system_event_t rui_lora_event = {.request = UDRV_SYS_EVT_OP_LORAWAN, .p_context = 
# 36 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                             ((void *)0)
# 36 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                 };




typedef struct sLoRaMacClassBCtx
{



    PingSlotContext_t PingSlotCtx;



    BeaconContext_t BeaconCtx;



    BeaconState_t BeaconState;



    PingSlotState_t PingSlotState;



    PingSlotState_t MulticastSlotState;



    UTIL_TIMER_Object_t BeaconTimer;



    UTIL_TIMER_Object_t PingSlotTimer;



    UTIL_TIMER_Object_t MulticastSlotTimer;



    LoRaMacClassBCallback_t LoRaMacClassBCallbacks;




    LoRaMacClassBParams_t LoRaMacClassBParams;
} LoRaMacClassBCtx_t;




typedef union uLoRaMacClassBEvents
{
    uint32_t Value;
    struct sEvents
    {
        uint32_t Beacon : 1;
        uint32_t PingSlot : 1;
        uint32_t MulticastSlot : 1;
    }Events;
}LoRaMacClassBEvents_t;

LoRaMacClassBEvents_t LoRaMacClassBEvents = { .Value = 0 };




static LoRaMacClassBCtx_t Ctx;





static LoRaMacClassBNvmData_t* ClassBNvm;
# 121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static void ComputePingOffset( uint64_t beaconTime, uint32_t address, uint16_t pingPeriod, uint16_t *pingOffset )
{
    uint8_t buffer[16];
    uint8_t cipher[16];
    uint32_t result = 0;



    uint32_t time = ( beaconTime % ( ( ( uint64_t ) 1 ) << 32 ) );

    memset1( buffer, 0, 16 );
    memset1( cipher, 0, 16 );

    buffer[0] = ( time ) & 0xFF;
    buffer[1] = ( time >> 8 ) & 0xFF;
    buffer[2] = ( time >> 16 ) & 0xFF;
    buffer[3] = ( time >> 24 ) & 0xFF;

    buffer[4] = ( address ) & 0xFF;
    buffer[5] = ( address >> 8 ) & 0xFF;
    buffer[6] = ( address >> 16 ) & 0xFF;
    buffer[7] = ( address >> 24 ) & 0xFF;

    SecureElementAesEncrypt( buffer, 16, SLOT_RAND_ZERO_KEY, cipher );

    result = ( ( ( uint32_t ) cipher[0] ) + ( ( ( uint32_t ) cipher[1] ) * 256 ) );

    *pingOffset = ( uint16_t )( result % pingPeriod );
}
# 161 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static uint32_t CalcDownlinkFrequency( uint8_t channel, 
# 161 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                       _Bool 
# 161 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                            isBeacon )
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    getPhy.Attribute = PHY_PING_SLOT_CHANNEL_FREQ;

    if( isBeacon == 
# 168 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                   1 
# 168 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                        )
    {
        getPhy.Attribute = PHY_BEACON_CHANNEL_FREQ;
    }
    getPhy.Channel = channel;
    phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );

    return phyParam.Value;
}
# 193 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static uint32_t CalcDownlinkChannelAndFrequency( uint32_t devAddr, UTIL_TIMER_Time_t beaconTime,
                                                 UTIL_TIMER_Time_t beaconInterval, 
# 194 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                            _Bool 
# 194 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                 isBeacon )
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;
    uint32_t channel = 0;
    uint8_t nbChannels = 0;
    uint8_t offset = 0;


    getPhy.Attribute = PHY_PING_SLOT_NB_CHANNELS;

    if( isBeacon == 
# 205 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                   1 
# 205 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                        )
    {

        getPhy.Attribute = PHY_BEACON_NB_CHANNELS;
    }
    phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );
    nbChannels = ( uint8_t ) phyParam.Value;



    if( nbChannels > 1 )
    {
        getPhy.Attribute = PHY_BEACON_CHANNEL_OFFSET;
        phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );
        offset = ( uint8_t ) phyParam.Value;


        channel = devAddr + ( beaconTime / ( beaconInterval / 1000 ) );
        channel = channel % nbChannels;
        channel += offset;
    }



    return CalcDownlinkFrequency( channel, isBeacon );
}
# 243 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static void CalculateBeaconRxWindowConfig( RxConfigParams_t* rxConfig, uint16_t currentSymbolTimeout )
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;

    rxConfig->WindowTimeout = currentSymbolTimeout;
    rxConfig->WindowOffset = 0;

    if( ( Ctx.BeaconCtx.Ctrl.BeaconAcquired == 1 ) || ( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 ) )
    {



        getPhy.Attribute = PHY_BEACON_CHANNEL_DR;
        phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );


        RegionComputeRxWindowParameters( *Ctx.LoRaMacClassBParams.LoRaMacRegion,
                                        ( int8_t )phyParam.Value,
                                        Ctx.LoRaMacClassBParams.LoRaMacParams->MinRxSymbols,
                                        Ctx.LoRaMacClassBParams.LoRaMacParams->SystemMaxRxError,
                                        rxConfig );
    }
}
# 277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static void RxBeaconSetup( UTIL_TIMER_Time_t rxTime, 
# 277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                              _Bool 
# 277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                   activateDefaultChannel, uint16_t symbolTimeout )
{
    RxBeaconSetup_t rxBeaconSetup;
    uint32_t frequency = 0;

    if( activateDefaultChannel == 
# 282 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                 1 
# 282 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                      )
    {


        frequency = CalcDownlinkFrequency( 0, 
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                             1 
# 286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                  );
    }
    else
    {

        frequency = CalcDownlinkChannelAndFrequency( 0, Ctx.BeaconCtx.BeaconTime.Seconds + ( 128000 / 1000 ),
                                                     128000, 
# 292 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                            1 
# 292 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                 );
    }

    if( ClassBNvm->BeaconCtx.Ctrl.CustomFreq == 1 )
    {

        frequency = ClassBNvm->BeaconCtx.Frequency;
    }

    if( Ctx.BeaconCtx.Ctrl.BeaconChannelSet == 1 )
    {

        Ctx.BeaconCtx.Ctrl.BeaconChannelSet = 0;
        frequency = CalcDownlinkFrequency( Ctx.BeaconCtx.BeaconTimingChannel, 
# 305 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                             1 
# 305 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                  );
    }

    rxBeaconSetup.SymbolTimeout = symbolTimeout;
    rxBeaconSetup.RxTime = rxTime;
    rxBeaconSetup.Frequency = frequency;

    RegionRxBeaconSetup( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &rxBeaconSetup, &Ctx.LoRaMacClassBParams.McpsIndication->RxDatarate );

    Ctx.LoRaMacClassBParams.MlmeIndication->BeaconInfo.Frequency = frequency;
    Ctx.LoRaMacClassBParams.MlmeIndication->BeaconInfo.Datarate = Ctx.LoRaMacClassBParams.McpsIndication->RxDatarate;
}
# 327 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static 
# 327 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
      _Bool 
# 327 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
           CalcNextSlotTime( uint16_t slotOffset, uint16_t pingPeriod, uint16_t pingNb, UTIL_TIMER_Time_t* timeOffset )
{
    uint8_t currentPingSlot = 0;
    UTIL_TIMER_Time_t slotTime = 0;
    UTIL_TIMER_Time_t currentTime = UTIL_TIMER_GetCurrentTime( );


    slotTime = ( ( currentTime - SysTimeToMs( Ctx.BeaconCtx.LastBeaconRx ) ) % 128000 );
    slotTime = currentTime - slotTime;


    slotTime += 2120;
    slotTime += slotOffset * 30;

    if( slotTime < currentTime )
    {
        currentPingSlot = ( ( currentTime - slotTime ) /
                          ( pingPeriod * 30 ) ) + 1;
        slotTime += ( ( UTIL_TIMER_Time_t )( currentPingSlot * pingPeriod ) *
                    30 );
    }

    if( currentPingSlot < pingNb )
    {
        if( slotTime <= ( SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx ) - 3000 - 30 ) )
        {

            slotTime -= currentTime;
            slotTime -= Radio.GetWakeupTime( );
            slotTime = (slotTime);
            *timeOffset = slotTime;
            return 
# 358 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                  1
# 358 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                      ;
        }
    }
    return 
# 361 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 361 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;
}
# 372 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
static uint16_t BeaconCrc( uint8_t *buffer, uint16_t length )
{

    const uint16_t polynom = 0x1021;

    uint16_t crc = 0x0000;

    if( buffer == 
# 379 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                 ((void *)0) 
# 379 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                      )
    {
        return 0;
    }

    for( uint16_t i = 0; i < length; ++i )
    {
        crc ^= ( uint16_t ) buffer[i] << 8;
        for( uint16_t j = 0; j < 8; ++j )
        {
            crc = ( crc & 0x8000 ) ? ( crc << 1 ) ^ polynom : ( crc << 1 );
        }
    }

    return crc;
}

static void GetTemperatureLevel( LoRaMacClassBCallback_t *callbacks, BeaconContext_t *beaconCtx )
{

    if( ( callbacks != 
# 399 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                      ((void *)0) 
# 399 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                           ) && ( callbacks->GetTemperatureLevel != 
# 399 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                    ((void *)0) 
# 399 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                         ) )
    {
        beaconCtx->Temperature = callbacks->GetTemperatureLevel( );
    }
}

static void InitClassB( void )
{
    GetPhyParams_t getPhy;
    PhyParam_t phyParam;


    LoRaMacClassBEvents.Value = 0;


    memset1( ( uint8_t* ) ClassBNvm, 0, sizeof( LoRaMacClassBNvmData_t ) );
    memset1( ( uint8_t* ) &Ctx.PingSlotCtx, 0, sizeof( PingSlotContext_t ) );
    memset1( ( uint8_t* ) &Ctx.BeaconCtx, 0, sizeof( BeaconContext_t ) );


    Ctx.BeaconCtx.Temperature = 25.0;
    GetTemperatureLevel( &Ctx.LoRaMacClassBCallbacks, &Ctx.BeaconCtx );


    getPhy.Attribute = PHY_PING_SLOT_CHANNEL_DR;
    phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );
    ClassBNvm->PingSlotCtx.Datarate = ( int8_t )( phyParam.Value );


    Ctx.BeaconState = BEACON_STATE_ACQUISITION;
    Ctx.PingSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
    Ctx.MulticastSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
}

static void InitClassBDefaults( void )
{


    LoRaMacClassBBeaconNvmData_t beaconCtx = ClassBNvm->BeaconCtx;
    LoRaMacClassBPingSlotNvmData_t pingSlotCtx = ClassBNvm->PingSlotCtx;

    InitClassB( );


    ClassBNvm->BeaconCtx.Frequency = beaconCtx.Frequency;
    ClassBNvm->BeaconCtx.Ctrl.CustomFreq = beaconCtx.Ctrl.CustomFreq;


    ClassBNvm->PingSlotCtx.Ctrl.CustomFreq = pingSlotCtx.Ctrl.CustomFreq;
    ClassBNvm->PingSlotCtx.Frequency = pingSlotCtx.Frequency;
    ClassBNvm->PingSlotCtx.Datarate = pingSlotCtx.Datarate;
}

static void EnlargeWindowTimeout( void )
{

    Ctx.BeaconCtx.BeaconWindowMovement *= 2;
    if( Ctx.BeaconCtx.BeaconWindowMovement > 256 )
    {
        Ctx.BeaconCtx.BeaconWindowMovement = 256;
    }

    Ctx.BeaconCtx.SymbolTimeout *= 2;
    if( Ctx.BeaconCtx.SymbolTimeout > 255 )
    {
        Ctx.BeaconCtx.SymbolTimeout = 255;
    }
    Ctx.PingSlotCtx.SymbolTimeout *= 2;
    if( Ctx.PingSlotCtx.SymbolTimeout > 30 )
    {
        Ctx.PingSlotCtx.SymbolTimeout = 30;
    }
}

static void ResetWindowTimeout( void )
{
    Ctx.BeaconCtx.SymbolTimeout = 8;
    Ctx.PingSlotCtx.SymbolTimeout = 8;
    Ctx.BeaconCtx.BeaconWindowMovement = 2;
}

static UTIL_TIMER_Time_t CalcDelayForNextBeacon( UTIL_TIMER_Time_t currentTime, UTIL_TIMER_Time_t lastBeaconRx )
{
    UTIL_TIMER_Time_t nextBeaconRxTime = 0;


    nextBeaconRxTime = ( ( currentTime - lastBeaconRx ) % 128000 );
    return ( 128000 - nextBeaconRxTime );
}

static void IndicateBeaconStatus( LoRaMacEventInfoStatus_t status )
{
    if( Ctx.BeaconCtx.Ctrl.ResumeBeaconing == 0 )
    {
        Ctx.LoRaMacClassBParams.MlmeIndication->MlmeIndication = MLME_BEACON;
        Ctx.LoRaMacClassBParams.MlmeIndication->Status = status;
        Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MlmeInd = 1;

        Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MacDone = 1;
    }
    Ctx.BeaconCtx.Ctrl.ResumeBeaconing = 0;
}

static UTIL_TIMER_Time_t ApplyGuardTime( UTIL_TIMER_Time_t beaconEventTime )
{
    UTIL_TIMER_Time_t timeGuard = beaconEventTime;

    if( timeGuard > 3000 )
    {
        timeGuard -= 3000;
    }
    return timeGuard;
}

static UTIL_TIMER_Time_t UpdateBeaconState( LoRaMacEventInfoStatus_t status,
                                      UTIL_TIMER_Time_t windowMovement, UTIL_TIMER_Time_t currentTime )

{
    UTIL_TIMER_Time_t beaconEventTime = 0;


    beaconEventTime = CalcDelayForNextBeacon( currentTime, SysTimeToMs( Ctx.BeaconCtx.LastBeaconRx ) );
    Ctx.BeaconCtx.NextBeaconRx = SysTimeFromMs( currentTime + beaconEventTime );


    beaconEventTime = (beaconEventTime);


    if( beaconEventTime > windowMovement )
    {
        beaconEventTime -= windowMovement;
    }
    Ctx.BeaconCtx.NextBeaconRxAdjusted = currentTime + beaconEventTime;


    LoRaMacClassBStartRxSlots( );


    IndicateBeaconStatus( status );


    return ApplyGuardTime( beaconEventTime );
}

static uint8_t CalcPingNb( uint16_t periodicity )
{
    return 128 / ( 1 << periodicity );
}

static uint16_t CalcPingPeriod( uint8_t pingNb )
{
    return 4096 / pingNb;
}


void LoRaMacClassBInit( LoRaMacClassBParams_t *classBParams, LoRaMacClassBCallback_t *callbacks,
                        LoRaMacClassBNvmData_t* nvm )
{


    if( nvm == 
# 559 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              ((void *)0) 
# 559 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                   )
    {
        return;
    }
    ClassBNvm = nvm;


    Ctx.LoRaMacClassBCallbacks = *callbacks;


    Ctx.LoRaMacClassBParams = *classBParams;


    do { UTIL_TIMER_Create( &Ctx.BeaconTimer, ( ( uint32_t )~0 ), UTIL_TIMER_ONESHOT, LoRaMacClassBBeaconTimerEvent, 
# 572 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   ((void *)0)
# 572 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
   ); } while(0);
    do { UTIL_TIMER_Create( &Ctx.PingSlotTimer, ( ( uint32_t )~0 ), UTIL_TIMER_ONESHOT, LoRaMacClassBPingSlotTimerEvent, 
# 573 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   ((void *)0)
# 573 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
   ); } while(0);
    do { UTIL_TIMER_Create( &Ctx.MulticastSlotTimer, ( ( uint32_t )~0 ), UTIL_TIMER_ONESHOT, LoRaMacClassBMulticastSlotTimerEvent, 
# 574 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   ((void *)0)
# 574 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
   ); } while(0);

    InitClassB( );

}

void LoRaMacClassBSetBeaconState( BeaconState_t beaconState )
{

    if( beaconState == BEACON_STATE_ACQUISITION )
    {


        if( ( Ctx.BeaconCtx.Ctrl.BeaconDelaySet == 1 ) &&
            ( LoRaMacClassBIsAcquisitionPending( ) == 
# 588 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                     0 
# 588 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                           ) )
        {
            Ctx.BeaconState = BEACON_STATE_ACQUISITION_BY_TIME;
        }
        else
        {
           Ctx.BeaconState = beaconState;
        }
    }
    else
    {
        if( ( Ctx.BeaconState != BEACON_STATE_ACQUISITION ) &&
            ( Ctx.BeaconState != BEACON_STATE_ACQUISITION_BY_TIME ) )
        {
            Ctx.BeaconState = beaconState;
        }
    }

}

void LoRaMacClassBSetPingSlotState( PingSlotState_t pingSlotState )
{

    Ctx.PingSlotState = pingSlotState;

}

void LoRaMacClassBSetMulticastSlotState( PingSlotState_t multicastSlotState )
{

    Ctx.MulticastSlotState = multicastSlotState;

}


# 622 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 622 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsAcquisitionInProgress( void )
{

    if( Ctx.BeaconState == BEACON_STATE_ACQUISITION_BY_TIME )
    {


        return 
# 629 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 629 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    if( LoRaMacClassBIsAcquisitionPending( ) == 
# 631 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                               1 
# 631 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                    )
    {


        return 
# 635 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 635 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 637 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 637 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}

void LoRaMacClassBBeaconTimerEvent( void* context )
{

    Ctx.BeaconCtx.TimeStamp = UTIL_TIMER_GetCurrentTime( );
    do { if (UTIL_TIMER_IsRunning(&Ctx.BeaconTimer)) { UTIL_TIMER_Stop(&Ctx.BeaconTimer); } } while(0);
    LoRaMacClassBEvents.Events.Beacon = 1;

    if( Ctx.LoRaMacClassBCallbacks.MacProcessNotify != 
# 650 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                      ((void *)0) 
# 650 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                           )
    {
        Ctx.LoRaMacClassBCallbacks.MacProcessNotify( );
    }
    udrv_system_event_produce(&rui_lora_event);
    udrv_powersave_in_sleep = 
# 655 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                             0
# 655 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                  ;

}


static void LoRaMacClassBProcessBeacon( void )
{
    
# 662 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   _Bool 
# 662 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
        activateTimer = 
# 662 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                        0
# 662 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                             ;
    UTIL_TIMER_Time_t beaconEventTime = 1;
    RxConfigParams_t beaconRxConfig;
    UTIL_TIMER_Time_t currentTime = Ctx.BeaconCtx.TimeStamp;


    switch( Ctx.BeaconState )
    {
        case BEACON_STATE_ACQUISITION_BY_TIME:
        {
            activateTimer = 
# 672 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1
# 672 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;

            if( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 )
            {
                Radio.Sleep();
                Ctx.BeaconState = BEACON_STATE_LOST;
            }
            else
            {

                ResetWindowTimeout( );

                if( Ctx.BeaconCtx.Ctrl.BeaconDelaySet == 1 )
                {

                    CalculateBeaconRxWindowConfig( &beaconRxConfig, Ctx.BeaconCtx.SymbolTimeout );

                    if( Ctx.BeaconCtx.BeaconTimingDelay > 0 )
                    {
                        if( SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx ) > currentTime )
                        {

                            beaconEventTime = (SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx ) - currentTime);

                            if( ( int32_t ) beaconEventTime > beaconRxConfig.WindowOffset )
                            {

                                beaconEventTime += beaconRxConfig.WindowOffset;
                            }
                        }
                        else
                        {

                            Ctx.BeaconCtx.Ctrl.BeaconDelaySet = 0;
                            Ctx.BeaconCtx.Ctrl.BeaconChannelSet = 0;
                            Ctx.BeaconState = BEACON_STATE_ACQUISITION;
                        }
                        Ctx.BeaconCtx.BeaconTimingDelay = 0;
                    }
                    else
                    {
                        activateTimer = 
# 713 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                       0
# 713 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                            ;


                        Ctx.BeaconCtx.Ctrl.BeaconDelaySet = 0;

                        Ctx.BeaconCtx.Ctrl.AcquisitionPending = 1;



                        RxBeaconSetup( 2120, 
# 722 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                              0
# 722 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                   , beaconRxConfig.WindowTimeout );
                    }
                }
                else
                {
                    Ctx.BeaconCtx.NextBeaconRx.Seconds = 0;
                    Ctx.BeaconCtx.NextBeaconRx.SubSeconds = 0;
                    Ctx.BeaconCtx.BeaconTimingDelay = 0;

                    Ctx.BeaconState = BEACON_STATE_ACQUISITION;
                }
            }
            break;
        }
        case BEACON_STATE_ACQUISITION:
        {
            activateTimer = 
# 738 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1
# 738 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;

            if( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 )
            {
                Radio.Sleep();
                Ctx.BeaconState = BEACON_STATE_LOST;
            }
            else
            {

                ResetWindowTimeout( );

                Ctx.BeaconCtx.Ctrl.AcquisitionPending = 1;
                beaconEventTime = 128000;


                CalculateBeaconRxWindowConfig( &beaconRxConfig, Ctx.BeaconCtx.SymbolTimeout );






                RxBeaconSetup( 0, 
# 761 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                 1
# 761 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                     , beaconRxConfig.WindowTimeout );
            }
            break;
        }
        case BEACON_STATE_TIMEOUT:
        {

            Ctx.BeaconCtx.BeaconTime.Seconds += ( 128000 / 1000 );
            Ctx.BeaconCtx.BeaconTime.SubSeconds = 0;


            EnlargeWindowTimeout( );


            Ctx.BeaconState = BEACON_STATE_REACQUISITION;
        }

        case BEACON_STATE_REACQUISITION:
        {
            activateTimer = 
# 780 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1
# 780 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;


            Ctx.BeaconCtx.Ctrl.BeaconAcquired = 0;


            if( ( currentTime - SysTimeToMs( Ctx.BeaconCtx.LastBeaconRx ) ) > 7200000 )
            {
                Ctx.BeaconState = BEACON_STATE_LOST;
            }
            else
            {

                beaconEventTime = UpdateBeaconState( LORAMAC_EVENT_INFO_STATUS_BEACON_LOST,
                                                     Ctx.BeaconCtx.BeaconWindowMovement, currentTime );


                Ctx.BeaconState = BEACON_STATE_IDLE;
            }
            break;
        }
        case BEACON_STATE_LOCKED:
        {
            activateTimer = 
# 803 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1
# 803 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;


            Ctx.BeaconCtx.Ctrl.AcquisitionPending = 0;


            beaconEventTime = UpdateBeaconState( LORAMAC_EVENT_INFO_STATUS_BEACON_LOCKED,
                                                 0, currentTime );


            if( Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MlmeReq == 1 )
            {
                if( LoRaMacConfirmQueueIsCmdActive( MLME_BEACON_ACQUISITION ) == 
# 815 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                1 
# 815 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                     )
                {
                    LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_OK, MLME_BEACON_ACQUISITION );
                    Ctx.LoRaMacClassBParams.MlmeConfirm->TxTimeOnAir = 0;
                }
            }


            Ctx.BeaconState = BEACON_STATE_IDLE;
            break;
        }
        case BEACON_STATE_IDLE:
        {
            activateTimer = 
# 828 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1
# 828 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;
            GetTemperatureLevel( &Ctx.LoRaMacClassBCallbacks, &Ctx.BeaconCtx );
            beaconEventTime = Ctx.BeaconCtx.NextBeaconRxAdjusted - Radio.GetWakeupTime( );
            currentTime = UTIL_TIMER_GetCurrentTime( );


            CalculateBeaconRxWindowConfig( &beaconRxConfig, Ctx.BeaconCtx.SymbolTimeout );

            if( beaconEventTime > currentTime )
            {
                Ctx.BeaconState = BEACON_STATE_GUARD;
                beaconEventTime -= currentTime;
                beaconEventTime = (beaconEventTime);

                if( ( int32_t ) beaconEventTime > beaconRxConfig.WindowOffset )
                {

                    beaconEventTime += beaconRxConfig.WindowOffset;
                }
            }
            else
            {
                Ctx.BeaconState = BEACON_STATE_REACQUISITION;
                beaconEventTime = 1;
            }
            break;
        }
        case BEACON_STATE_GUARD:
        {
            Ctx.BeaconState = BEACON_STATE_RX;


            LoRaMacClassBStopRxSlots( );



            RxBeaconSetup( 2120, 
# 864 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                  0
# 864 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                       , beaconRxConfig.WindowTimeout );
            break;
        }
        case BEACON_STATE_LOST:
        {

            if( Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MlmeReq == 1 )
            {
                if( LoRaMacConfirmQueueIsCmdActive( MLME_BEACON_ACQUISITION ) == 
# 872 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                1 
# 872 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                     )
                {
                    LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_BEACON_NOT_FOUND, MLME_BEACON_ACQUISITION );
                }
            }
            else
            {
                Ctx.LoRaMacClassBParams.MlmeIndication->MlmeIndication = MLME_BEACON_LOST;
                Ctx.LoRaMacClassBParams.MlmeIndication->Status = LORAMAC_EVENT_INFO_STATUS_OK;
                Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MlmeInd = 1;
            }


            LoRaMacClassBStopRxSlots( );


            InitClassBDefaults( );

            Ctx.LoRaMacClassBParams.LoRaMacFlags->Bits.MacDone = 1;

            break;
        }
        default:
        {
            Ctx.BeaconState = BEACON_STATE_ACQUISITION;
            break;
        }
    }

    if( activateTimer == 
# 901 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                        1 
# 901 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                             )
    {
        do{ UTIL_TIMER_SetPeriod(&Ctx.BeaconTimer, beaconEventTime); } while(0);
        do { UTIL_TIMER_Start(&Ctx.BeaconTimer); } while(0);
    }
}


void LoRaMacClassBPingSlotTimerEvent( void* context )
{

    LoRaMacClassBEvents.Events.PingSlot = 1;

    if( Ctx.LoRaMacClassBCallbacks.MacProcessNotify != 
# 914 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                      ((void *)0) 
# 914 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                           )
    {
        Ctx.LoRaMacClassBCallbacks.MacProcessNotify( );
    }
    udrv_system_event_produce(&rui_lora_event);
    udrv_powersave_in_sleep = 
# 919 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                             0
# 919 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                  ;

}


static void LoRaMacClassBProcessPingSlot( void )
{
    static RxConfigParams_t pingSlotRxConfig;
    UTIL_TIMER_Time_t pingSlotTime = 0;

    switch( Ctx.PingSlotState )
    {
        case PINGSLOT_STATE_CALC_PING_OFFSET:
        {
            ComputePingOffset( Ctx.BeaconCtx.BeaconTime.Seconds,
                               *Ctx.LoRaMacClassBParams.LoRaMacDevAddr,
                               ClassBNvm->PingSlotCtx.PingPeriod,
                               &( Ctx.PingSlotCtx.PingOffset ) );
            Ctx.PingSlotState = PINGSLOT_STATE_SET_TIMER;
        }

        case PINGSLOT_STATE_SET_TIMER:
        {
            if( CalcNextSlotTime( Ctx.PingSlotCtx.PingOffset, ClassBNvm->PingSlotCtx.PingPeriod, ClassBNvm->PingSlotCtx.PingNb, &pingSlotTime ) == 
# 942 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                                                                                  1 
# 942 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                                                                       )
            {
                if( Ctx.BeaconCtx.Ctrl.BeaconAcquired == 1 )
                {


                    RegionComputeRxWindowParameters( *Ctx.LoRaMacClassBParams.LoRaMacRegion,
                                                     ClassBNvm->PingSlotCtx.Datarate,
                                                     Ctx.LoRaMacClassBParams.LoRaMacParams->MinRxSymbols,
                                                     Ctx.LoRaMacClassBParams.LoRaMacParams->SystemMaxRxError,
                                                     &pingSlotRxConfig );
                    Ctx.PingSlotCtx.SymbolTimeout = pingSlotRxConfig.WindowTimeout;

                    if( ( int32_t )pingSlotTime > pingSlotRxConfig.WindowOffset )
                    {
                        pingSlotTime += pingSlotRxConfig.WindowOffset;
                    }
                }


                Ctx.PingSlotState = PINGSLOT_STATE_IDLE;
                do{ UTIL_TIMER_SetPeriod(&Ctx.PingSlotTimer, pingSlotTime); } while(0);
                do { UTIL_TIMER_Start(&Ctx.PingSlotTimer); } while(0);
            }
            break;
        }
        case PINGSLOT_STATE_IDLE:
        {
            uint32_t frequency = ClassBNvm->PingSlotCtx.Frequency;


            if( ClassBNvm->PingSlotCtx.Ctrl.CustomFreq == 0 )
            {

                frequency = CalcDownlinkChannelAndFrequency( *Ctx.LoRaMacClassBParams.LoRaMacDevAddr, Ctx.BeaconCtx.BeaconTime.Seconds,
                                                             128000, 
# 977 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                    0 
# 977 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                          );
            }



            if( Ctx.MulticastSlotState != PINGSLOT_STATE_RX )
            {
                Ctx.PingSlotState = PINGSLOT_STATE_RX;

                pingSlotRxConfig.Datarate = ClassBNvm->PingSlotCtx.Datarate;
                pingSlotRxConfig.DownlinkDwellTime = Ctx.LoRaMacClassBParams.LoRaMacParams->DownlinkDwellTime;
                pingSlotRxConfig.Frequency = frequency;
                pingSlotRxConfig.RxContinuous = 
# 989 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                               0
# 989 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                    ;
                pingSlotRxConfig.RxSlot = RX_SLOT_WIN_CLASS_B_PING_SLOT;

                RegionRxConfig( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &pingSlotRxConfig, ( int8_t* )&Ctx.LoRaMacClassBParams.McpsIndication->RxDatarate );

                if( pingSlotRxConfig.RxContinuous == 
# 994 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                    0 
# 994 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                          )
                {
                    Radio.Rx( Ctx.LoRaMacClassBParams.LoRaMacParams->MaxRxWindow );
                }
                else
                {
                    Radio.Rx( 0 );
                }
            }
            else
            {

                Ctx.PingSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
                do{ UTIL_TIMER_SetPeriod(&Ctx.PingSlotTimer, 30); } while(0);
                do { UTIL_TIMER_Start(&Ctx.PingSlotTimer); } while(0);
            }
            break;
        }
        default:
        {
            Ctx.PingSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
            break;
        }
    }
}


void LoRaMacClassBMulticastSlotTimerEvent( void* context )
{

    LoRaMacClassBEvents.Events.MulticastSlot = 1;

    if( Ctx.LoRaMacClassBCallbacks.MacProcessNotify != 
# 1026 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                      ((void *)0) 
# 1026 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                           )
    {
        Ctx.LoRaMacClassBCallbacks.MacProcessNotify( );
    }
    udrv_system_event_produce(&rui_lora_event);
    udrv_powersave_in_sleep = 
# 1031 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                             0
# 1031 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                  ;

}


static void LoRaMacClassBProcessMulticastSlot( void )
{
    static RxConfigParams_t multicastSlotRxConfig;
    UTIL_TIMER_Time_t multicastSlotTime = 0;
    UTIL_TIMER_Time_t slotTime = 0;
    MulticastCtx_t *cur = Ctx.LoRaMacClassBParams.MulticastChannels;


    if( cur == 
# 1044 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              ((void *)0) 
# 1044 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                   )
    {
        return;
    }

    if( Ctx.MulticastSlotState == PINGSLOT_STATE_RX )
    {

        return;
    }

    switch( Ctx.MulticastSlotState )
    {
        case PINGSLOT_STATE_CALC_PING_OFFSET:
        {

            for( uint8_t i = 0; i < 4; i++ )
            {
                ComputePingOffset( Ctx.BeaconCtx.BeaconTime.Seconds,
                                   cur->ChannelParams.Address,
                                   cur->PingPeriod,
                                   &( cur->PingOffset ) );
                cur++;
            }
            Ctx.MulticastSlotState = PINGSLOT_STATE_SET_TIMER;
        }

        case PINGSLOT_STATE_SET_TIMER:
        {
            cur = Ctx.LoRaMacClassBParams.MulticastChannels;
            Ctx.PingSlotCtx.NextMulticastChannel = 
# 1074 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                  ((void *)0)
# 1074 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                      ;

            for( uint8_t i = 0; i < 4; i++ )
            {

                if( CalcNextSlotTime( cur->PingOffset, cur->PingPeriod, cur->PingNb, &slotTime ) == 
# 1079 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                                   1 
# 1079 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                        )
                {
                    if( ( multicastSlotTime == 0 ) || ( multicastSlotTime > slotTime ) )
                    {

                        multicastSlotTime = slotTime;
                        Ctx.PingSlotCtx.NextMulticastChannel = cur;
                    }
                }
                cur++;
            }


            if( Ctx.PingSlotCtx.NextMulticastChannel != 
# 1092 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                       ((void *)0) 
# 1092 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                            )
            {
                if( Ctx.BeaconCtx.Ctrl.BeaconAcquired == 1 )
                {
                    RegionComputeRxWindowParameters( *Ctx.LoRaMacClassBParams.LoRaMacRegion,
                                                    ClassBNvm->PingSlotCtx.Datarate,
                                                    Ctx.LoRaMacClassBParams.LoRaMacParams->MinRxSymbols,
                                                    Ctx.LoRaMacClassBParams.LoRaMacParams->SystemMaxRxError,
                                                    &multicastSlotRxConfig );
                    Ctx.PingSlotCtx.SymbolTimeout = multicastSlotRxConfig.WindowTimeout;
                }

                if( ( int32_t )multicastSlotTime > multicastSlotRxConfig.WindowOffset )
                {
                    multicastSlotTime += multicastSlotRxConfig.WindowOffset;
                }


                Ctx.MulticastSlotState = PINGSLOT_STATE_IDLE;
                do{ UTIL_TIMER_SetPeriod(&Ctx.MulticastSlotTimer, multicastSlotTime); } while(0);
                do { UTIL_TIMER_Start(&Ctx.MulticastSlotTimer); } while(0);
            }
            break;
        }
        case PINGSLOT_STATE_IDLE:
        {
            uint32_t frequency = 0;


            if( Ctx.PingSlotCtx.NextMulticastChannel == 
# 1121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                       ((void *)0) 
# 1121 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                            )
            {
                Ctx.MulticastSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
                do{ UTIL_TIMER_SetPeriod(&Ctx.MulticastSlotTimer, 1); } while(0);
                do { UTIL_TIMER_Start(&Ctx.MulticastSlotTimer); } while(0);
                break;
            }


            frequency = Ctx.PingSlotCtx.NextMulticastChannel->ChannelParams.RxParams.ClassB.Frequency;


            if( frequency == 0 )
            {

                frequency = CalcDownlinkChannelAndFrequency( Ctx.PingSlotCtx.NextMulticastChannel->ChannelParams.Address,
                                                             Ctx.BeaconCtx.BeaconTime.Seconds, 128000, 
# 1137 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                                                      0 
# 1137 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                                            );
            }

            Ctx.MulticastSlotState = PINGSLOT_STATE_RX;

            multicastSlotRxConfig.Datarate = Ctx.PingSlotCtx.NextMulticastChannel->ChannelParams.RxParams.ClassB.Datarate;
            multicastSlotRxConfig.DownlinkDwellTime = Ctx.LoRaMacClassBParams.LoRaMacParams->DownlinkDwellTime;
            multicastSlotRxConfig.Frequency = frequency;
            multicastSlotRxConfig.RxContinuous = 
# 1145 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                0
# 1145 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                     ;
            multicastSlotRxConfig.RxSlot = RX_SLOT_WIN_CLASS_B_MULTICAST_SLOT;

            RegionRxConfig( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &multicastSlotRxConfig, ( int8_t* )&Ctx.LoRaMacClassBParams.McpsIndication->RxDatarate );

            if( Ctx.PingSlotState == PINGSLOT_STATE_RX )
            {

                Radio.Standby( );
                Ctx.PingSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
                do{ UTIL_TIMER_SetPeriod(&Ctx.PingSlotTimer, 30); } while(0);
                do { UTIL_TIMER_Start(&Ctx.PingSlotTimer); } while(0);
            }

            if( multicastSlotRxConfig.RxContinuous == 
# 1159 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                     0 
# 1159 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                           )
            {
                Radio.Rx( Ctx.LoRaMacClassBParams.LoRaMacParams->MaxRxWindow );
            }
            else
            {
                Radio.Rx( 0 );
            }
            break;
        }
        default:
        {
            Ctx.MulticastSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
            break;
        }
    }
}



# 1178 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1178 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBRxBeacon( uint8_t *payload, uint16_t size )
{

    GetPhyParams_t getPhy;
    PhyParam_t phyParam;
    
# 1183 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   _Bool 
# 1183 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
        beaconProcessed = 
# 1183 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                          0
# 1183 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                               ;
    uint16_t crc0 = 0;
    uint16_t crc1 = 0;
    uint16_t beaconCrc0 = 0;
    uint16_t beaconCrc1 = 0;

    getPhy.Attribute = PHY_BEACON_FORMAT;
    phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );


    if( ( Ctx.BeaconState == BEACON_STATE_RX ) || ( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 ) )
    {
        if( size == phyParam.BeaconFormat.BeaconSize )
        {
# 1205 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
            beaconCrc0 = ( ( uint16_t )payload[phyParam.BeaconFormat.Rfu1Size + 4] ) & 0x00FF;
            beaconCrc0 |= ( ( uint16_t )payload[phyParam.BeaconFormat.Rfu1Size + 4 + 1] << 8 ) & 0xFF00;
            crc0 = BeaconCrc( payload, phyParam.BeaconFormat.Rfu1Size + 4 );


            if( crc0 == beaconCrc0 )
            {

                Ctx.BeaconCtx.BeaconTime.Seconds = ( ( uint32_t )payload[phyParam.BeaconFormat.Rfu1Size] ) & 0x000000FF;
                Ctx.BeaconCtx.BeaconTime.Seconds |= ( ( uint32_t )( payload[phyParam.BeaconFormat.Rfu1Size + 1] << 8 ) ) & 0x0000FF00;
                Ctx.BeaconCtx.BeaconTime.Seconds |= ( ( uint32_t )( payload[phyParam.BeaconFormat.Rfu1Size + 2] << 16 ) ) & 0x00FF0000;
                Ctx.BeaconCtx.BeaconTime.Seconds |= ( ( uint32_t )( payload[phyParam.BeaconFormat.Rfu1Size + 3] << 24 ) ) & 0xFF000000;
                Ctx.BeaconCtx.BeaconTime.SubSeconds = 0;
                Ctx.LoRaMacClassBParams.MlmeIndication->BeaconInfo.Time = Ctx.BeaconCtx.BeaconTime;
                beaconProcessed = 
# 1219 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                 1
# 1219 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                     ;
            }


            beaconCrc1 = ( ( uint16_t )payload[phyParam.BeaconFormat.Rfu1Size + 4 + 2 + 7 + phyParam.BeaconFormat.Rfu2Size] ) & 0x00FF;
            beaconCrc1 |= ( ( uint16_t )payload[phyParam.BeaconFormat.Rfu1Size + 4 + 2 + 7 + phyParam.BeaconFormat.Rfu2Size + 1] << 8 ) & 0xFF00;
            crc1 = BeaconCrc( &payload[phyParam.BeaconFormat.Rfu1Size + 4 + 2], 7 + phyParam.BeaconFormat.Rfu2Size );


            if( crc1 == beaconCrc1 )
            {


                Ctx.LoRaMacClassBParams.MlmeIndication->BeaconInfo.GwSpecific.InfoDesc = payload[phyParam.BeaconFormat.Rfu1Size + 4 + 2];
                memcpy1( Ctx.LoRaMacClassBParams.MlmeIndication->BeaconInfo.GwSpecific.Info, &payload[phyParam.BeaconFormat.Rfu1Size + 4 + 2 + 1], 6 );
            }


            if( beaconProcessed == 
# 1237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                  1 
# 1237 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                       )
            {
                uint32_t spreadingFactor = 0;
                uint32_t bandwith = 0;

                getPhy.Attribute = PHY_BEACON_CHANNEL_DR;
                phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );

                getPhy.Attribute = PHY_SF_FROM_DR;
                getPhy.Datarate = phyParam.Value;
                phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );
                spreadingFactor = phyParam.Value;

                getPhy.Attribute = PHY_BW_FROM_DR;
                phyParam = RegionGetPhyParam( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &getPhy );
                bandwith = phyParam.Value;

                UTIL_TIMER_Time_t time = Radio.TimeOnAir( MODEM_LORA, bandwith, spreadingFactor, 1, 10, 
# 1254 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                                 1
# 1254 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                     , size, 
# 1254 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                                             0 
# 1254 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                                   );
                SysTime_t timeOnAir;
                timeOnAir.Seconds = time / 1000;
                timeOnAir.SubSeconds = time - timeOnAir.Seconds * 1000;

                Ctx.BeaconCtx.LastBeaconRx = Ctx.BeaconCtx.BeaconTime;
                Ctx.BeaconCtx.LastBeaconRx.Seconds += 315964800;


                SysTimeSet( SysTimeAdd( Ctx.BeaconCtx.LastBeaconRx, timeOnAir ) );

                Ctx.BeaconCtx.Ctrl.BeaconAcquired = 1;
                Ctx.BeaconCtx.Ctrl.BeaconMode = 1;
                ResetWindowTimeout( );
                Ctx.BeaconState = BEACON_STATE_LOCKED;

                LoRaMacClassBBeaconTimerEvent( 
# 1270 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                              ((void *)0) 
# 1270 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                   );
            }
        }

        if( Ctx.BeaconState == BEACON_STATE_RX )
        {
            Ctx.BeaconState = BEACON_STATE_TIMEOUT;
            LoRaMacClassBBeaconTimerEvent( 
# 1277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                          ((void *)0) 
# 1277 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                               );
        }







        beaconProcessed = 
# 1286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                         1
# 1286 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                             ;
    }
    return beaconProcessed;



}


# 1294 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1294 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsBeaconExpected( void )
{

    if( ( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 ) ||
        ( Ctx.BeaconState == BEACON_STATE_RX ) )
    {
        return 
# 1300 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1300 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1302 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1302 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}


# 1308 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1308 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsPingExpected( void )
{

    if( Ctx.PingSlotState == PINGSLOT_STATE_RX )
    {
        return 
# 1313 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1313 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1315 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1315 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}


# 1321 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1321 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsMulticastExpected( void )
{

    if( Ctx.MulticastSlotState == PINGSLOT_STATE_RX )
    {
        return 
# 1326 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1326 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1328 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1328 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}


# 1334 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1334 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsAcquisitionPending( void )
{

    if( Ctx.BeaconCtx.Ctrl.AcquisitionPending == 1 )
    {
        return 
# 1339 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1339 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1341 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1341 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}


# 1347 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1347 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBIsBeaconModeActive( void )
{

    if( ( Ctx.BeaconCtx.Ctrl.BeaconMode == 1 ) ||
        ( Ctx.BeaconState == BEACON_STATE_ACQUISITION_BY_TIME ) )
    {
        return 
# 1353 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1353 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1355 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1355 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}

void LoRaMacClassBSetPingSlotInfo( uint8_t periodicity )
{

    ClassBNvm->PingSlotCtx.PingNb = CalcPingNb( periodicity );
    ClassBNvm->PingSlotCtx.PingPeriod = CalcPingPeriod( ClassBNvm->PingSlotCtx.PingNb );

}

void LoRaMacClassBHaltBeaconing( void )
{

    if( Ctx.BeaconCtx.Ctrl.BeaconMode == 1 )
    {
        if( ( Ctx.BeaconState == BEACON_STATE_TIMEOUT ) ||
            ( Ctx.BeaconState == BEACON_STATE_LOST ) )
        {

            LoRaMacClassBBeaconTimerEvent( 
# 1378 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                          ((void *)0) 
# 1378 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                               );
        }

        uint32_t mask; BoardCriticalSectionBegin( &mask );
        LoRaMacClassBEvents.Events.Beacon = 0;
        BoardCriticalSectionEnd( &mask );


        do { if (UTIL_TIMER_IsRunning(&Ctx.BeaconTimer)) { UTIL_TIMER_Stop(&Ctx.BeaconTimer); } } while(0);


        Ctx.BeaconState = BEACON_STATE_HALT;


        LoRaMacClassBStopRxSlots( );
    }

}

void LoRaMacClassBResumeBeaconing( void )
{

    if( Ctx.BeaconState == BEACON_STATE_HALT )
    {
        Ctx.BeaconCtx.Ctrl.ResumeBeaconing = 1;


        Ctx.BeaconState = BEACON_STATE_LOCKED;

        if( Ctx.BeaconCtx.Ctrl.BeaconAcquired == 0 )
        {

            Ctx.BeaconState = BEACON_STATE_REACQUISITION;
        }

        LoRaMacClassBBeaconTimerEvent( 
# 1413 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                      ((void *)0) 
# 1413 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                           );
    }

}

LoRaMacStatus_t LoRaMacClassBSwitchClass( DeviceClass_t nextClass )
{

    if( nextClass == CLASS_B )
    {
        if( ( Ctx.BeaconCtx.Ctrl.BeaconMode == 1 ) && ( ClassBNvm->PingSlotCtx.Ctrl.Assigned == 1 ) )
        {
            return LORAMAC_STATUS_OK;
        }
    }
    if( nextClass == CLASS_A )
    {
        LoRaMacClassBHaltBeaconing( );


        InitClassBDefaults( );

        return LORAMAC_STATUS_OK;
    }
    return LORAMAC_STATUS_SERVICE_UNKNOWN;



}

LoRaMacStatus_t LoRaMacClassBMibGetRequestConfirm( MibRequestConfirm_t *mibGet )
{

    LoRaMacStatus_t status;

    switch( mibGet->Type )
    {
        case MIB_PING_SLOT_DATARATE:
        {
            mibGet->Param.PingSlotDatarate = ClassBNvm->PingSlotCtx.Datarate;
            break;
        }
        default:
        {
            status = LORAMAC_STATUS_SERVICE_UNKNOWN;
            break;
        }
    }
    return status;



}

LoRaMacStatus_t LoRaMacMibClassBSetRequestConfirm( MibRequestConfirm_t *mibSet )
{

    LoRaMacStatus_t status;

    switch( mibSet->Type )
    {
        case MIB_PING_SLOT_DATARATE:
        {
            ClassBNvm->PingSlotCtx.Datarate = mibSet->Param.PingSlotDatarate;
            break;
        }
        default:
        {
            status = LORAMAC_STATUS_SERVICE_UNKNOWN;
            break;
        }
    }
    return status;



}

void LoRaMacClassBPingSlotInfoAns( void )
{

    if( LoRaMacConfirmQueueIsCmdActive( MLME_PING_SLOT_INFO ) == 
# 1494 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                1 
# 1494 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                     )
    {
        LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_OK, MLME_PING_SLOT_INFO );
        ClassBNvm->PingSlotCtx.Ctrl.Assigned = 1;
    }

}

uint8_t LoRaMacClassBPingSlotChannelReq( uint8_t datarate, uint32_t frequency )
{

    uint8_t status = 0x03;
    VerifyParams_t verify;
    
# 1507 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
   _Bool 
# 1507 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
        isCustomFreq = 
# 1507 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                       0
# 1507 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                            ;

    if( frequency != 0 )
    {
        isCustomFreq = 
# 1511 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                      1
# 1511 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                          ;
        verify.Frequency = frequency;
        if( RegionVerify( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &verify, PHY_FREQUENCY ) == 
# 1513 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                             0 
# 1513 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                   )
        {
            status &= 0xFE;
        }
    }

    verify.DatarateParams.Datarate = datarate;
    verify.DatarateParams.DownlinkDwellTime = Ctx.LoRaMacClassBParams.LoRaMacParams->DownlinkDwellTime;

    if( RegionVerify( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &verify, PHY_RX_DR ) == 
# 1522 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                     0 
# 1522 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                           )
    {
        status &= 0xFD;
    }

    if( status == 0x03 )
    {
        if( isCustomFreq == 
# 1529 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           1 
# 1529 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                )
        {
            ClassBNvm->PingSlotCtx.Ctrl.CustomFreq = 1;
            ClassBNvm->PingSlotCtx.Frequency = frequency;
        }
        else
        {
            ClassBNvm->PingSlotCtx.Ctrl.CustomFreq = 0;
            ClassBNvm->PingSlotCtx.Frequency = 0;
        }
        ClassBNvm->PingSlotCtx.Datarate = datarate;
    }

    return status;



}

void LoRaMacClassBBeaconTimingAns( uint16_t beaconTimingDelay, uint8_t beaconTimingChannel, UTIL_TIMER_Time_t lastRxDone )
{

    Ctx.BeaconCtx.BeaconTimingDelay = ( 30 * beaconTimingDelay );
    Ctx.BeaconCtx.BeaconTimingChannel = beaconTimingChannel;

    if( LoRaMacConfirmQueueIsCmdActive( MLME_BEACON_TIMING ) == 
# 1554 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                               1 
# 1554 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                    )
    {
        if( Ctx.BeaconCtx.BeaconTimingDelay > 128000 )
        {

            Ctx.BeaconCtx.BeaconTimingDelay = 0;
            Ctx.BeaconCtx.BeaconTimingChannel = 0;
            LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_BEACON_NOT_FOUND, MLME_BEACON_TIMING );
        }
        else
        {
            Ctx.BeaconCtx.Ctrl.BeaconDelaySet = 1;
            Ctx.BeaconCtx.Ctrl.BeaconChannelSet = 1;
            Ctx.BeaconCtx.NextBeaconRx = SysTimeFromMs( lastRxDone + Ctx.BeaconCtx.BeaconTimingDelay );
            LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_OK, MLME_BEACON_TIMING );
        }

        Ctx.LoRaMacClassBParams.MlmeConfirm->BeaconTimingDelay = Ctx.BeaconCtx.BeaconTimingDelay;
        Ctx.LoRaMacClassBParams.MlmeConfirm->BeaconTimingChannel = Ctx.BeaconCtx.BeaconTimingChannel;
    }

}

void LoRaMacClassBDeviceTimeAns( void )
{


    SysTime_t nextBeacon = SysTimeGet( );
    uint32_t currentTimeMs = SysTimeToMs( nextBeacon );

    nextBeacon.Seconds = nextBeacon.Seconds + ( 128 - ( nextBeacon.Seconds % 128 ) );
    nextBeacon.SubSeconds = 0;

    Ctx.BeaconCtx.NextBeaconRx = nextBeacon;
    Ctx.BeaconCtx.LastBeaconRx = SysTimeSub( Ctx.BeaconCtx.NextBeaconRx, ( SysTime_t ){ .Seconds = 128000 / 1000, .SubSeconds = 0 } );

    if( LoRaMacConfirmQueueIsCmdActive( MLME_DEVICE_TIME ) == 
# 1590 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                             1 
# 1590 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                  )
    {
        if( currentTimeMs > SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx ) )
        {

            Ctx.BeaconCtx.LastBeaconRx.Seconds = 0;
            Ctx.BeaconCtx.LastBeaconRx.SubSeconds = 0;
            Ctx.BeaconCtx.NextBeaconRx.Seconds = 0;
            Ctx.BeaconCtx.NextBeaconRx.SubSeconds = 0;
            LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_BEACON_NOT_FOUND, MLME_DEVICE_TIME );
        }
        else
        {
            Ctx.BeaconCtx.Ctrl.BeaconDelaySet = 1;
            Ctx.BeaconCtx.BeaconTimingDelay = SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx ) - currentTimeMs;
            Ctx.BeaconCtx.BeaconTime.Seconds = nextBeacon.Seconds - 315964800 - 128;
            Ctx.BeaconCtx.BeaconTime.SubSeconds = 0;
            LoRaMacConfirmQueueSetStatus( LORAMAC_EVENT_INFO_STATUS_OK, MLME_DEVICE_TIME );
        }
    }

}


# 1613 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
_Bool 
# 1613 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
    LoRaMacClassBBeaconFreqReq( uint32_t frequency )
{

    VerifyParams_t verify;

    if( frequency != 0 )
    {
        verify.Frequency = frequency;

        if( RegionVerify( *Ctx.LoRaMacClassBParams.LoRaMacRegion, &verify, PHY_FREQUENCY ) == 
# 1622 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                                                                                             1 
# 1622 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                                                                                  )
        {
            ClassBNvm->BeaconCtx.Ctrl.CustomFreq = 1;
            ClassBNvm->BeaconCtx.Frequency = frequency;
            return 
# 1626 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                  1
# 1626 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                      ;
        }
    }
    else
    {
        ClassBNvm->BeaconCtx.Ctrl.CustomFreq = 0;
        return 
# 1632 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
              1
# 1632 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                  ;
    }
    return 
# 1634 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
          0
# 1634 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
               ;



}

UTIL_TIMER_Time_t LoRaMacClassBIsUplinkCollision( UTIL_TIMER_Time_t txTimeOnAir )
{

    UTIL_TIMER_Time_t currentTime = UTIL_TIMER_GetCurrentTime( );
    UTIL_TIMER_Time_t beaconReserved = 0;
    UTIL_TIMER_Time_t nextBeacon = SysTimeToMs( Ctx.BeaconCtx.NextBeaconRx );

    beaconReserved = nextBeacon -
                     3000 -
                     Ctx.LoRaMacClassBParams.LoRaMacParams->ReceiveDelay1 -
                     Ctx.LoRaMacClassBParams.LoRaMacParams->ReceiveDelay2 -
                     txTimeOnAir;


    if( ( currentTime >= beaconReserved ) && ( currentTime < ( nextBeacon + 2120 ) ) )
    {
        return 2120;
    }
    return 0;



}

void LoRaMacClassBStopRxSlots( void )
{

    do { if (UTIL_TIMER_IsRunning(&Ctx.PingSlotTimer)) { UTIL_TIMER_Stop(&Ctx.PingSlotTimer); } } while(0);
    do { if (UTIL_TIMER_IsRunning(&Ctx.MulticastSlotTimer)) { UTIL_TIMER_Stop(&Ctx.MulticastSlotTimer); } } while(0);

    uint32_t mask; BoardCriticalSectionBegin( &mask );
    LoRaMacClassBEvents.Events.PingSlot = 0;
    LoRaMacClassBEvents.Events.MulticastSlot = 0;
    BoardCriticalSectionEnd( &mask );

}

void LoRaMacClassBStartRxSlots( void )
{

    if( ClassBNvm->PingSlotCtx.Ctrl.Assigned == 1 )
    {
        Ctx.PingSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
        do{ UTIL_TIMER_SetPeriod(&Ctx.PingSlotTimer, 1); } while(0);
        do { UTIL_TIMER_Start(&Ctx.PingSlotTimer); } while(0);

        Ctx.MulticastSlotState = PINGSLOT_STATE_CALC_PING_OFFSET;
        do{ UTIL_TIMER_SetPeriod(&Ctx.MulticastSlotTimer, 1); } while(0);
        do { UTIL_TIMER_Start(&Ctx.MulticastSlotTimer); } while(0);
    }

}

void LoRaMacClassBSetMulticastPeriodicity( MulticastCtx_t* multicastChannel )
{

    if( multicastChannel != 
# 1696 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c" 3 4
                           ((void *)0) 
# 1696 "/home/jenkins/workspace/RUI_Release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassB.c"
                                )
    {
        multicastChannel->PingNb = CalcPingNb( multicastChannel->ChannelParams.RxParams.ClassB.Periodicity );
        multicastChannel->PingPeriod = CalcPingPeriod( multicastChannel->PingNb );
    }

}

void LoRaMacClassBProcess( void )
{

    LoRaMacClassBEvents_t events;

    uint32_t mask; BoardCriticalSectionBegin( &mask );
    events = LoRaMacClassBEvents;
    LoRaMacClassBEvents.Value = 0;
    BoardCriticalSectionEnd( &mask );

    if( events.Value != 0 )
    {
        if( events.Events.Beacon == 1 )
        {
            LoRaMacClassBProcessBeacon( );
        }
        if( events.Events.PingSlot == 1 )
        {
            LoRaMacClassBProcessPingSlot( );
        }
        if( events.Events.MulticastSlot == 1 )
        {
            LoRaMacClassBProcessMulticastSlot( );
        }
    }

}

# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3//"
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
#define LORA_IO_SPI_PORT 2
#define SYS_RTC_COUNTER_PORT 2
#define ATCMD_CUST_TABLE_SIZE 64
#define WAN_TYPE 0
#define LORA_STACK_VER 0x040407
#define RAK3272_SIP_VA 1
#define rak3172 -sip 1
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
#define SOFT_SE 1
#define SECURE_ELEMENT_PRE_PROVISIONED 1
#define LORAMAC_CLASSB_ENABLED 1
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 31 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 1
# 67 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
#define __LORAMAC_H__ 






# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 1 3 4
# 9 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 3 4
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 1 3 4
# 10 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define _STDINT_H 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 1 3 4





#define _MACHINE__DEFAULT_TYPES_H 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 1 3 4
# 22 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define _SYS_FEATURES_H 





# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_newlib_version.h" 1 3 4



#define _NEWLIB_VERSION_H__ 1

#define _NEWLIB_VERSION "3.3.0"
#define __NEWLIB__ 3
#define __NEWLIB_MINOR__ 3
#define __NEWLIB_PATCHLEVEL__ 0
# 29 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 2 3 4




#define __GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))






#define __GNUC_PREREQ__(ma,mi) __GNUC_PREREQ(ma, mi)
# 249 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __ATFILE_VISIBLE 0





#define __BSD_VISIBLE 0





#define __GNU_VISIBLE 0







#define __ISO_C_VISIBLE 1999







#define __LARGEFILE_VISIBLE 0





#define __MISC_VISIBLE 0
# 299 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __POSIX_VISIBLE 0





#define __SVID_VISIBLE 0
# 319 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __XSI_VISIBLE 0
# 330 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/features.h" 3 4
#define __SSP_FORTIFY_LEVEL 0
# 9 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 2 3 4






#define __EXP(x) __ ##x ##__
# 26 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
#define __have_longlong64 1






#define __have_long32 1








# 41 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;



#define ___int8_t_defined 1







typedef short int __int16_t;

typedef short unsigned int __uint16_t;



#define ___int16_t_defined 1
# 77 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int32_t;

typedef long unsigned int __uint32_t;



#define ___int32_t_defined 1
# 103 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;



#define ___int64_t_defined 1
# 134 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;



#define ___int_least8_t_defined 1
# 160 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;



#define ___int_least16_t_defined 1
# 182 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;



#define ___int_least32_t_defined 1
# 200 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;



#define ___int_least64_t_defined 1







typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 244 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_default_types.h" 3 4
#undef __EXP
# 13 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 1 3 4
# 10 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _SYS__INTSUP_H 





#define __STDINT_EXP(x) __ ##x ##__
# 35 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
       
       
       
       
       
       
       
       
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
# 67 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define _INTPTR_EQ_INT 






#define _INT32_EQ_LONG 







#define __INT8 "hh"
# 93 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT16 "h"
# 104 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT32 "l"
# 113 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __INT64 "ll"






#define __FAST8 
# 129 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST16 






#define __FAST32 
# 147 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __FAST64 "ll"



#define __LEAST8 "hh"
# 162 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST16 "h"
# 173 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST32 "l"
# 182 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#define __LEAST64 "ll"

#undef signed
#undef unsigned
#undef char
#undef short
#undef int
#undef long
       
       
       
       
       
# 194 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20
       
# 195 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_intsup.h" 3 4
#undef __int20__
       
       
# 14 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 1 3 4
# 10 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
#define _SYS__STDINT_H 
# 20 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_stdint.h" 3 4
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
# 15 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 2 3 4






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
# 51 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
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
# 128 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTPTR_MIN (-__INTPTR_MAX__ - 1)
#define INTPTR_MAX (__INTPTR_MAX__)
#define UINTPTR_MAX (__UINTPTR_MAX__)
# 152 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT8_MIN (-__INT8_MAX__ - 1)
#define INT8_MAX (__INT8_MAX__)
#define UINT8_MAX (__UINT8_MAX__)







#define INT_LEAST8_MIN (-__INT_LEAST8_MAX__ - 1)
#define INT_LEAST8_MAX (__INT_LEAST8_MAX__)
#define UINT_LEAST8_MAX (__UINT_LEAST8_MAX__)
# 174 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_MIN (-__INT16_MAX__ - 1)
#define INT16_MAX (__INT16_MAX__)
#define UINT16_MAX (__UINT16_MAX__)







#define INT_LEAST16_MIN (-__INT_LEAST16_MAX__ - 1)
#define INT_LEAST16_MAX (__INT_LEAST16_MAX__)
#define UINT_LEAST16_MAX (__UINT_LEAST16_MAX__)
# 196 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_MIN (-__INT32_MAX__ - 1)
#define INT32_MAX (__INT32_MAX__)
#define UINT32_MAX (__UINT32_MAX__)
# 212 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST32_MIN (-__INT_LEAST32_MAX__ - 1)
#define INT_LEAST32_MAX (__INT_LEAST32_MAX__)
#define UINT_LEAST32_MAX (__UINT_LEAST32_MAX__)
# 230 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_MIN (-__INT64_MAX__ - 1)
#define INT64_MAX (__INT64_MAX__)
#define UINT64_MAX (__UINT64_MAX__)
# 246 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_LEAST64_MIN (-__INT_LEAST64_MAX__ - 1)
#define INT_LEAST64_MAX (__INT_LEAST64_MAX__)
#define UINT_LEAST64_MAX (__UINT_LEAST64_MAX__)
# 262 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST8_MIN (-__INT_FAST8_MAX__ - 1)
#define INT_FAST8_MAX (__INT_FAST8_MAX__)
#define UINT_FAST8_MAX (__UINT_FAST8_MAX__)
# 278 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST16_MIN (-__INT_FAST16_MAX__ - 1)
#define INT_FAST16_MAX (__INT_FAST16_MAX__)
#define UINT_FAST16_MAX (__UINT_FAST16_MAX__)
# 294 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST32_MIN (-__INT_FAST32_MAX__ - 1)
#define INT_FAST32_MAX (__INT_FAST32_MAX__)
#define UINT_FAST32_MAX (__UINT_FAST32_MAX__)
# 310 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT_FAST64_MIN (-__INT_FAST64_MAX__ - 1)
#define INT_FAST64_MAX (__INT_FAST64_MAX__)
#define UINT_FAST64_MAX (__UINT_FAST64_MAX__)
# 326 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_MAX (__INTMAX_MAX__)
#define INTMAX_MIN (-INTMAX_MAX - 1)







#define UINTMAX_MAX (__UINTMAX_MAX__)







#define SIZE_MAX (__SIZE_MAX__)





#define SIG_ATOMIC_MIN (-__STDINT_EXP(INT_MAX) - 1)
#define SIG_ATOMIC_MAX (__STDINT_EXP(INT_MAX))



#define PTRDIFF_MAX (__PTRDIFF_MAX__)



#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)




#define WCHAR_MIN (__WCHAR_MIN__)
# 374 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WCHAR_MAX (__WCHAR_MAX__)
# 384 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define WINT_MAX (__WINT_MAX__)




#define WINT_MIN (__WINT_MIN__)






#define INT8_C(x) __INT8_C(x)
#define UINT8_C(x) __UINT8_C(x)
# 408 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT16_C(x) __INT16_C(x)
#define UINT16_C(x) __UINT16_C(x)
# 420 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT32_C(x) __INT32_C(x)
#define UINT32_C(x) __UINT32_C(x)
# 433 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INT64_C(x) __INT64_C(x)
#define UINT64_C(x) __UINT64_C(x)
# 449 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/stdint.h" 3 4
#define INTMAX_C(x) __INTMAX_C(x)
#define UINTMAX_C(x) __UINTMAX_C(x)
# 10 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdint.h" 2 3 4



#define _GCC_WRAP_STDINT_H 
# 75 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 1 3 4
# 29 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 3 4
#define _STDBOOL_H 



#define bool _Bool
#define true 1
#define false 0
# 52 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdbool.h" 3 4
#define __bool_true_false_are_defined 1
# 76 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2

# 1 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h" 1
# 24 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h"
#define __TIMER_H__ 






# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 1
# 44 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
#define UTIL_TIME_SERVER_H__ 
# 58 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 39 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 
# 131 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 
#define _PTRDIFF_T_DECLARED 



typedef int ptrdiff_t;
# 155 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 181 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
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
# 231 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 260 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
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
# 287 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef _BSD_WCHAR_T_
# 321 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 340 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 59 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h" 1
# 26 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h"
#define __CMSIS_COMPILER_H 
# 54 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h" 1
# 26 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __CMSIS_GCC_H 


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
# 41 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
  
# 74 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 131 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 196 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 248 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 272 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 344 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 368 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 398 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 449 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) :: "memory");
  return(result);
}
# 479 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 506 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 558 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 583 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 624 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 833 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_FPSCR(void)
{
# 849 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  return(0U);

}







__attribute__((always_inline)) static inline void __set_FPSCR(uint32_t fpscr)
{
# 872 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  (void)fpscr;

}
# 894 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __CMSIS_GCC_OUT_REG(r) "=r" (r)
#define __CMSIS_GCC_RW_REG(r) "+r" (r)
#define __CMSIS_GCC_USE_REG(r) "r" (r)






#define __NOP() __ASM volatile ("nop")





#define __WFI() __ASM volatile ("wfi")







#define __WFE() __ASM volatile ("wfe")






#define __SEV() __ASM volatile ("sev")
# 933 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 967 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}
# 986 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return result;
}
# 1001 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline int16_t __REVSH(int16_t value)
{

  return (int16_t)__builtin_bswap16(value);






}
# 1021 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 1039 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __BKPT(value) __ASM volatile ("bkpt "#value)
# 1048 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




   __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
# 1068 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  return result;
}
# 1078 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __CLZ(uint32_t value)
{
# 1089 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 1107 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint8_t) result);
}
# 1129 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint16_t) result);
}
# 1151 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}
# 1168 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1185 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}
# 1202 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 1236 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __SSAT(ARG1,ARG2) __extension__ ({ int32_t __RES, __ARG1 = (ARG1); __ASM ("ssat %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })
# 1252 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __USAT(ARG1,ARG2) __extension__ ({ uint32_t __RES, __ARG1 = (ARG1); __ASM ("usat %0, %1, %2" : "=r" (__RES) : "I" (ARG2), "r" (__ARG1) ); __RES; })
# 1268 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 1283 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint8_t) result);
}
# 1305 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint16_t) result);
}
# 1327 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *ptr)
{
    uint32_t result;

   __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
   return(result);
}
# 1342 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
   __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1354 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
   __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}
# 1366 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
   __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
# 1621 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
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
# 2148 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_gcc.h"
#define __PKHBT(ARG1,ARG2,ARG3) ( ((((uint32_t)(ARG1)) ) & 0x0000FFFFUL) | ((((uint32_t)(ARG2)) << (ARG3)) & 0xFFFF0000UL) )


#define __PKHTB(ARG1,ARG2,ARG3) ( ((((uint32_t)(ARG1)) ) & 0xFFFF0000UL) | ((((uint32_t)(ARG2)) >> (ARG3)) & 0x0000FFFFUL) )


__attribute__((always_inline)) static inline int32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
 int32_t result;

 __asm volatile ("smmla %0, %1, %2, %3" : "=r" (result): "r" (op1), "r" (op2), "r" (op3) );
 return(result);
}





#pragma GCC diagnostic pop
# 55 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Drivers/CMSIS/Include/cmsis_compiler.h" 2
# 60 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h" 1
# 24 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h"
#define __UTILITIES_CONF_H__ 
# 34 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h" 1
# 22 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
#define __STM32_MEM_H__ 







# 1 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h" 1
# 31 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h" 2





#define UTIL_MEM_PLACE_IN_SECTION(__x__) UTIL_PLACE_IN_SECTION( __x__ )
#define UTIL_MEM_ALIGN ALIGN
# 47 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_cpy_8( void *dst, const void *src, uint16_t size );
# 56 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_cpyr_8( void *dst, const void *src, uint16_t size );
# 65 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_mem.h"
void UTIL_MEM_set_8( void *dst, uint8_t value, uint16_t size );
# 35 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h" 2

# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 1
# 21 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"
#define __STM32_TINY_VSNPRINTF_H__ 






# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 1 3 4
# 31 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
#define _STDARG_H 
#define _ANSI_STDARG_H_ 

#undef __need___va_list




#define __GNUC_VA_LIST 

# 40 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;






#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)


#define va_copy(d,s) __builtin_va_copy(d,s)

#define __va_copy(d,s) __builtin_va_copy(d,s)
# 99 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;





#define _VA_LIST_ 


#define _VA_LIST 


#define _VA_LIST_DEFINED 


#define _VA_LIST_T_H 


#define __va_list__ 
# 29 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 2
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 1 3







#define _STRING_H_ 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3







#define _ANSIDECL_H_ 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 1 3







#define __NEWLIB_H__ 1
# 18 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _WANT_IO_C99_FORMATS 1


#define _WANT_IO_LONG_LONG 1


#define _WANT_REGISTER_FINI 1
# 37 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _REENT_CHECK_VERIFY 1





#define _MB_LEN_MAX 1
# 53 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define HAVE_INITFINI_ARRAY 1



#define _ATEXIT_DYNAMIC_ALLOC 1


#define _HAVE_LONG_DOUBLE 1


#define _HAVE_CC_INHIBIT_LOOP_TO_LIBCALL 1


#define _LDBL_EQ_DBL 1


#define _FVWRITE_IN_STREAMIO 1


#define _FSEEK_OPTIMIZATION 1


#define _WIDE_ORIENT 1


#define _UNBUF_STREAM_OPT 1
# 95 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/newlib.h" 3
#define _RETARGETABLE_LOCKING 1
# 11 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 1 3

#define __SYS_CONFIG_H__ 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 1 3
# 77 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __IEEE_LITTLE_ENDIAN 
# 473 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/ieeefp.h" 3
#define __OBSOLETE_MATH_DEFAULT 1


#define __OBSOLETE_MATH __OBSOLETE_MATH_DEFAULT
# 5 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 2 3
# 224 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define _POINTER_INT long





#undef __RAND_MAX



#define __RAND_MAX 0x7fffffff
# 250 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/config.h" 3
#define __EXPORT 



#define __IMPORT 






#define _READ_WRITE_RETURN_TYPE int





#define _READ_WRITE_BUFSIZE_TYPE int
# 12 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 2 3
# 31 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _BEGIN_STD_C 
#define _END_STD_C 
#define _NOTHROW 



#define _LONG_DOUBLE long double





#define _ATTRIBUTE(attrs) __attribute__ (attrs)
# 69 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 3
#define _ELIDABLE_INLINE static __inline__



#define _NOINLINE __attribute__ ((__noinline__))
#define _NOINLINE_STATIC _NOINLINE static
# 11 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 1 3
# 11 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _SYS_REENT_H_ 

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/_ansi.h" 1 3
# 14 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 15 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 1 3
# 20 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define _SYS__TYPES_H 

#define __need_size_t 
#define __need_wint_t 
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t




#define _WINT_T 




typedef unsigned int wint_t;

#undef __need_wint_t
# 390 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 25 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/_types.h" 1 3





#define _MACHINE__TYPES_H 
# 28 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 2 3


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
# 90 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;
# 127 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#undef __size_t



typedef unsigned int __size_t;
# 146 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
#define unsigned signed
typedef signed int _ssize_t;
#undef unsigned
# 158 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_types.h" 3
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
# 16 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3

#define _NULL 0



#define __Long long
typedef unsigned long __ULong;
# 34 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 1 3

#define __SYS_LOCK_H__ 
# 33 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/lock.h" 3
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
# 35 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 2 3
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
# 98 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
#define _ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL}, 0, 0}}





#define _REENT_INIT_ATEXIT _NULL, _ATEXIT_INIT,
# 122 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 183 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
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
# 292 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 317 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
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
# 613 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
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
# 751 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT_INIT_PTR_ZEROED(var) { (var)->_stdin = _REENT_STDIO_STREAM(var, 0); (var)->_stdout = _REENT_STDIO_STREAM(var, 1); (var)->_stderr = _REENT_STDIO_STREAM(var, 2); (var)->_new._reent._rand_next = 1; (var)->_new._reent._r48._seed[0] = _RAND48_SEED_0; (var)->_new._reent._r48._seed[1] = _RAND48_SEED_1; (var)->_new._reent._r48._seed[2] = _RAND48_SEED_2; (var)->_new._reent._r48._mult[0] = _RAND48_MULT_0; (var)->_new._reent._r48._mult[1] = _RAND48_MULT_1; (var)->_new._reent._r48._mult[2] = _RAND48_MULT_2; (var)->_new._reent._r48._add = _RAND48_ADD; }
# 765 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
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
# 832 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/reent.h" 3
#define _REENT _impure_ptr


#define _GLOBAL_REENT _global_impure_ptr





#define _GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)
# 12 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 1 3
# 43 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _SYS_CDEFS_H_ 



# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 48 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 2 3

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
# 78 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __has_extension __has_feature


#define __has_feature(x) 0
# 94 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __BEGIN_DECLS 
#define __END_DECLS 
# 107 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 177 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __P(protos) protos
#define __CONCAT1(x,y) x ## y
#define __CONCAT(x,y) __CONCAT1(x,y)
#define __STRING(x) #x
#define __XSTRING(x) __STRING(x)

#define __const const
#define __signed signed
#define __volatile volatile
# 230 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __weak_symbol __attribute__((__weak__))
# 243 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 280 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Alignas(x) __aligned(x)






#define _Alignof(x) __alignof(x)
# 296 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Atomic(T) struct { T volatile __val; }





#define _Noreturn __dead2
# 331 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define _Thread_local __thread
# 351 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __generic(expr,t,yes,no) __builtin_choose_expr( __builtin_types_compatible_p(__typeof(expr), t), yes, no)
# 366 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 434 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __restrict restrict
# 467 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __predict_true(exp) __builtin_expect((exp), 1)
#define __predict_false(exp) __builtin_expect((exp), 0)






#define __null_sentinel __attribute__((__sentinel__))
#define __exported __attribute__((__visibility__("default")))


#define __hidden __attribute__((__visibility__("hidden")))
# 489 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __offsetof(type,field) offsetof(type, field)
#define __rangeof(type,start,end) (__offsetof(type, end) - __offsetof(type, start))
# 500 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __containerof(x,s,m) ({ const volatile __typeof(((s *)0)->m) *__x = (x); __DEQUALIFY(s *, (const volatile char *)__x - __offsetof(s, m));})
# 522 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))

#define __format_arg(fmtarg) __attribute__((__format_arg__ (fmtarg)))
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))

#define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
# 539 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __printf0like(fmtarg,firstvararg) 




#define __strong_reference(sym,aliassym) extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))




#define __weak_reference(sym,alias) __asm__(".weak " #alias); __asm__(".equ " #alias ", " #sym)


#define __warn_references(sym,msg) __asm__(".section .gnu.warning." #sym); __asm__(".asciz \"" msg "\""); __asm__(".previous")



#define __sym_compat(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@" #verid)

#define __sym_default(sym,impl,verid) __asm__(".symver " #impl ", " #sym "@@" #verid)
# 593 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 653 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
#define __arg_type_tag(arg_kind,arg_idx,type_tag_idx) 
#define __datatype_type_tag(kind,type) 
# 672 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/cdefs.h" 3
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
# 13 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3


#define __need_size_t 
#define __need_NULL 
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 18 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3
# 27 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3


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
# 86 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *_strdup_r (struct _reent *, const char *);



char *_strndup_r (struct _reent *, const char *, size_t);
# 112 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char * _strerror_r (struct _reent *, int, int, int *);
# 134 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
char *strsignal (int __signo);
# 175 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/string.h" 1 3
# 176 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/string.h" 2 3


# 30 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h" 2
# 54 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"

# 54 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_tiny_vsnprintf.h"
int tiny_vsnprintf_like(char *buf, const int size, const char *fmt, va_list args);
# 37 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h" 2
# 49 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h"
#define VLEVEL_OFF 0
#define VLEVEL_ALWAYS 0

#define VLEVEL_L 1
#define VLEVEL_M 2
#define VLEVEL_H 3

#define TS_OFF 0
#define TS_ON 1

#define T_REG_OFF 0
# 78 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h"
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
# 135 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/utilities_conf.h"
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
# 61 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h" 2
# 70 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
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
# 142 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
extern const UTIL_TIMER_Driver_s UTIL_TimerDriver;
# 162 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_Init(void);






UTIL_TIMER_Status_t UTIL_TIMER_DeInit(void);
# 184 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_Create( UTIL_TIMER_Object_t *TimerObject, uint32_t PeriodValue, UTIL_TIMER_Mode_t Mode, void ( *Callback )( void *) , void *Argument);







UTIL_TIMER_Status_t UTIL_TIMER_Start( UTIL_TIMER_Object_t *TimerObject );
# 201 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_StartWithPeriod( UTIL_TIMER_Object_t *TimerObject, uint32_t PeriodValue);







UTIL_TIMER_Status_t UTIL_TIMER_Stop( UTIL_TIMER_Object_t *TimerObject );
# 219 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_SetPeriod(UTIL_TIMER_Object_t *TimerObject, uint32_t NewPeriodValue);
# 228 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_SetReloadMode(UTIL_TIMER_Object_t *TimerObject, UTIL_TIMER_Mode_t ReloadMode);
# 237 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Status_t UTIL_TIMER_GetRemainingTime(UTIL_TIMER_Object_t *TimerObject, uint32_t *Time);







uint32_t UTIL_TIMER_IsRunning( UTIL_TIMER_Object_t *TimerObject );







uint32_t UTIL_TIMER_GetFirstRemainingTime(void);






UTIL_TIMER_Time_t UTIL_TIMER_GetCurrentTime(void);
# 269 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
UTIL_TIMER_Time_t UTIL_TIMER_GetElapsedTime(UTIL_TIMER_Time_t past );
# 278 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/timer/stm32_timer.h"
void UTIL_TIMER_IRQ_Handler( void );
# 32 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h" 2
# 45 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h"
#define TIMERTIME_T_MAX ( ( uint32_t )~0 )
# 60 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h"
#define TimerTime_t UTIL_TIMER_Time_t




#define TimerEvent_t UTIL_TIMER_Object_t




#define TimerInit(HANDLE,CB) do { UTIL_TIMER_Create( HANDLE, TIMERTIME_T_MAX, UTIL_TIMER_ONESHOT, CB, NULL); } while(0)






#define TimerSetValue(HANDLE,TIMEOUT) do{ UTIL_TIMER_SetPeriod(HANDLE, TIMEOUT); } while(0)






#define TimerStart(HANDLE) do { UTIL_TIMER_Start(HANDLE); } while(0)






#define TimerStop(HANDLE) do { if (UTIL_TIMER_IsRunning(HANDLE)) { UTIL_TIMER_Stop(HANDLE); } } while(0)
# 100 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/timer.h"
#define TimerGetCurrentTime UTIL_TIMER_GetCurrentTime




#define TimerGetElapsedTime UTIL_TIMER_GetElapsedTime



#define TimerTempCompensation(x,y) (x)
# 78 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/systime.h" 1
# 24 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/systime.h"
#define __SYSTIME_H__ 






# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h" 1
# 46 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
#define __STM32_SYS_TIME_H__ 
# 59 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 1 3







#define _TIME_H_ 





#define __need_size_t 
#define __need_NULL 
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 1 3 4
# 155 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_ptrdiff_t
# 231 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_size_t
# 340 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef __need_wchar_t
# 390 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/lib/gcc/arm-none-eabi/10.2.1/include/stddef.h" 3 4
#undef NULL




#define NULL ((void *)0)





#undef __need_NULL




#define offsetof(TYPE,MEMBER) __builtin_offsetof (TYPE, MEMBER)
# 17 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3


# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/time.h" 1 3

#define _MACHTIME_H_ 




#define _CLOCKS_PER_SEC_ 100
# 20 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3





#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC

# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 1 3
# 28 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3

# 28 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
typedef __uint8_t u_int8_t;


typedef __uint16_t u_int16_t;


typedef __uint32_t u_int32_t;


typedef __uint64_t u_int64_t;

typedef __intptr_t register_t;
#define __BIT_TYPES_DEFINED__ 1



#define _SYS_TYPES_H 
# 97 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
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
# 157 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 3
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


# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 1 3
# 19 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_pthreadtypes.h" 3
#define _SYS__PTHREADTYPES_H_ 
# 224 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/machine/types.h" 1 3
# 225 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/types.h" 2 3



#undef __need_inttypes
# 29 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3
# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 1 3
# 35 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
#define _SYS_TIMESPEC_H_ 


# 1 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 1 3
# 37 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
#define _SYS__TIMESPEC_H_ 
# 47 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/_timespec.h" 3
struct timespec {
 time_t tv_sec;
 long tv_nsec;
};
# 39 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 2 3
# 58 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/sys/timespec.h" 3
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
# 30 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 2 3







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


# 103 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
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
# 240 "/home/eddieho/tool/gcc-arm-none-eabi-10-2020-q4-major/arm-none-eabi/include/time.h" 3
#define CLOCK_ENABLED 1
#define CLOCK_DISABLED 0



#define CLOCK_ALLOWED 1


#define CLOCK_DISALLOWED 0






#define TIMER_ABSTIME 4







#define CLOCK_REALTIME ((clockid_t) 1)
# 60 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h" 2
# 70 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
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
# 122 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"

# 122 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
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
# 156 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
extern const UTIL_SYSTIM_Driver_s UTIL_SYSTIMDriver;
# 174 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeAdd( SysTime_t a, SysTime_t b );
# 184 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeSub( SysTime_t a, SysTime_t b );






void SysTimeSet( SysTime_t sysTime );






SysTime_t SysTimeGet( void );






SysTime_t SysTimeGetMcuTime( void );
# 214 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
uint32_t SysTimeToMs( SysTime_t sysTime );
# 223 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
SysTime_t SysTimeFromMs( uint32_t timeMs );







uint32_t SysTimeMkTime( const struct tm* localtime );
# 240 "/home/eddieho/tmp/phase2_release/rui-v3/external/STM32CubeWL/Utilities/misc/stm32_systime.h"
void SysTimeLocalTime( const uint32_t timestamp, struct tm *localtime );
# 32 "/home/eddieho/tmp/phase2_release/rui-v3/component/core/board/rak3172-sip/systime.h" 2
# 79 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 1
# 36 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define __LORAMAC_TYPES_H__ 
# 51 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define LORAMAC_CRYPTO_UNICAST_KEYS 0




#define LORAMAC_CRYPTO_MULTICAST_KEYS 127




#define LORAMAC_MAX_MC_CTX 4
# 77 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_0 0
# 93 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_1 1
# 109 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_2 2
# 125 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_3 3
# 141 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_4 4
# 157 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_5 5
# 173 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_6 6
# 189 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_7 7
# 205 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_8 8
# 221 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_9 9
# 237 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_10 10
# 253 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_11 11
# 269 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_12 12
# 285 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_13 13
# 301 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_14 14
# 317 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define DR_15 15
# 335 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_0 0
# 351 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_1 1
# 367 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_2 2
# 383 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_3 3
# 399 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_4 4
# 415 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_5 5
# 431 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_6 6
# 447 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_7 7
# 463 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_8 8
# 479 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_9 9
# 495 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_10 10
# 511 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_11 11
# 527 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_12 12
# 543 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
#define TX_POWER_13 13
# 559 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
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




    
# 842 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 842 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
        IsRemotelySetup;



    DeviceClass_t Class;



    
# 850 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 850 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
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
# 920 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
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



    
# 1126 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 3 4
   _Bool 
# 1126 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h"
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
# 80 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2

# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h" 1
# 34 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define __REGIONNVM_H__ 






# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacTypes.h" 1
# 42 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h" 2



#define REGION_NVM_MAX_NB_CHANNELS 96
# 59 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define REGION_NVM_MAX_NB_BANDS 6
# 68 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
#define REGION_NVM_CHANNELS_MASK_SIZE 6
# 77 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionNvm.h"
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
# 82 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h" 1
# 34 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h"
#define __LORAMAC_CRYPTO_NVM_H__ 







# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h" 1
# 24 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define __UTILITIES_H__ 
# 37 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define SUCCESS 1



#define FAIL 0
# 52 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define MIN(a,b) ( ( ( a ) < ( b ) ) ? ( a ) : ( b ) )
# 63 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define MAX(a,b) ( ( ( a ) > ( b ) ) ? ( a ) : ( b ) )
# 72 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
#define POW2(n) ( 1 << n )




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
# 103 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
int32_t randr( int32_t min, int32_t max );
# 114 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memcpy1( uint8_t *dst, const uint8_t *src, uint16_t size );
# 123 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memcpyr( uint8_t *dst, const uint8_t *src, uint16_t size );
# 134 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void memset1( uint8_t *dst, uint8_t value, uint16_t size );







int8_t Nibble2HexChar( uint8_t a );
# 152 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32( uint8_t *buffer, uint16_t length );







uint32_t Crc32Init( void );
# 171 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32Update( uint32_t crcInit, uint8_t *buffer, uint16_t length );
# 180 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
uint32_t Crc32Finalize( uint32_t crc );




#define CRITICAL_SECTION_BEGIN() uint32_t mask; BoardCriticalSectionBegin( &mask )




#define CRITICAL_SECTION_END() BoardCriticalSectionEnd( &mask )
# 203 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/boards/utilities.h"
void BoardCriticalSectionBegin( uint32_t *mask );






void BoardCriticalSectionEnd( uint32_t *mask );
# 43 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacCryptoNvm.h" 2






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
# 83 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h" 1
# 35 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h"
#define __SECURE_ELEMENT_NVM_H__ 
# 48 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/secure-element-nvm.h"
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
# 84 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h" 1
# 34 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h"
#define __LORAMACCLASSBNVM_H__ 
# 47 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacClassBNvm.h"
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
# 85 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 2




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
}LoRaMacRegion_t;

typedef struct sLoRaMacNvmDataGroup1
{



    uint32_t AdrAckCounter;



    UTIL_TIMER_Time_t LastTxDoneTime;



    UTIL_TIMER_Time_t AggregatedTimeOff;



    uint32_t LastRxMic;



    int8_t ChannelsTxPower;



    int8_t ChannelsDatarate;




    
# 569 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 569 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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




    
# 618 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 618 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        PublicNetwork;



    
# 622 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 622 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AdrCtrlOn;




    uint8_t MaxDCycle;



    
# 631 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 631 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 720 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 823 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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



    
# 904 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 904 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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



    
# 963 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 963 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        RxData;



    int16_t Rssi;



    int8_t Snr;



    LoRaMacRxSlot_t RxSlot;



    
# 979 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 979 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        AckReceived;



    uint32_t DownLinkCounter;



    uint32_t DevAddress;



    
# 991 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 991 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
        DeviceTimeAnsReceived;
}McpsIndication_t;
# 1018 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 1369 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 1686 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    MIB_ANTENNA_GAIN,
# 1697 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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





    
# 1810 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 1810 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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





    
# 1954 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
   _Bool 
# 1954 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 2288 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
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
# 2384 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    uint8_t ( *GetBatteryLevel )( void );





    float ( *GetTemperatureLevel )( void );






    void ( *NvmDataChange )( uint16_t notifyFlags );






    void ( *MacProcessNotify )( void );
}LoRaMacCallback_t;





static const uint8_t LoRaMacMaxEirpTable[] = { 8, 10, 12, 13, 14, 16, 18, 20, 21, 24, 26, 27, 29, 30, 33, 36 };
# 2435 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacInitialization( LoRaMacPrimitives_t* primitives, LoRaMacCallback_t* callbacks, LoRaMacRegion_t region );
# 2444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacStart( void );
# 2453 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacStop( void );







# 2460 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h" 3 4
_Bool 
# 2460 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
    LoRaMacIsBusy( void );






void LoRaMacProcess( void );
# 2494 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacQueryTxPossible( uint8_t size, LoRaMacTxInfo_t* txInfo );
# 2512 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacChannelAdd( uint8_t id, ChannelParams_t params );
# 2526 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacChannelRemove( uint8_t id );
# 2541 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelSetup( McChannelParams_t *channel );
# 2555 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelDelete( AddressIdentifier_t groupID );
# 2565 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
uint8_t LoRaMacMcChannelGetGroupId( uint32_t mcAddress );
# 2582 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcChannelSetupRxParams( AddressIdentifier_t groupID, McRxParams_t *rxParams, uint8_t *status );
# 2610 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMibGetRequestConfirm( MibRequestConfirm_t* mibGet );
# 2641 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMibSetRequestConfirm( MibRequestConfirm_t* mibSet );
# 2674 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMlmeRequest( MlmeReq_t* mlmeRequest );
# 2708 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacMcpsRequest( McpsReq_t* mcpsRequest );
# 2720 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMac.h"
LoRaMacStatus_t LoRaMacDeInitialization( void );
# 32 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2



# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
#define __REGION_AS923_H__ 






# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 1
# 53 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
#define __REGION_H__ 
# 65 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
#define __REGIONCOMMON_H__ 







# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define __LORAMAC_HEADER_TYPES_H__ 
# 48 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
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
# 121 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_RE_JOIN_1_MSG_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_JOIN_EUI_FIELD_SIZE + LORAMAC_DEV_EUI_FIELD_SIZE + LORAMAC_RJCOUNT_1_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 131 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_RE_JOIN_0_2_MSG_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_EUI_FIELD_SIZE + LORAMAC_RJCOUNT_0_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 141 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_JOIN_ACCEPT_FRAME_MIN_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_NONCE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_ADDR_FIELD_SIZE + LORAMAC_DL_SETTINGS_FIELD_SIZE + LORAMAC_RX_DELAY_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 151 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_JOIN_ACCEPT_FRAME_MAX_SIZE ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_NONCE_FIELD_SIZE + LORAMAC_NET_ID_FIELD_SIZE + LORAMAC_DEV_ADDR_FIELD_SIZE + LORAMAC_DL_SETTINGS_FIELD_SIZE + LORAMAC_RX_DELAY_FIELD_SIZE + LORAMAC_CF_LIST_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 160 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define JOIN_ACCEPT_MIC_COMPUTATION_OFFSET ( LORAMAC_MHDR_FIELD_SIZE + LORAMAC_JOIN_TYPE_FIELD_SIZE + LORAMAC_JOIN_EUI_FIELD_SIZE + LORAMAC_DEV_NONCE_FIELD_SIZE )
# 173 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_FRAME_PAYLOAD_OVERHEAD_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_F_PORT_FIELD_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 182 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
#define LORAMAC_FRAME_PAYLOAD_MIN_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_MIC_FIELD_SIZE )







#define LORAMAC_FRAME_PAYLOAD_MAX_SIZE ( LORAMAC_MHDR_FIELD_SIZE + ( LORAMAC_FHDR_DEV_ADDR_FIELD_SIZE + LORAMAC_FHDR_F_CTRL_FIELD_SIZE + LORAMAC_FHDR_F_CNT_FIELD_SIZE ) + LORAMAC_F_PORT_FIELD_SIZE + LORAMAC_MAC_PAYLOAD_FIELD_MAX_SIZE + LORAMAC_MIC_FIELD_SIZE )
# 200 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/LoRaMacHeaderTypes.h"
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
# 47 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 2
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 1
# 48 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 2






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



    
# 152 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 152 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
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



    
# 244 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 244 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
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



    
# 286 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 286 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
        DutyCycleEnabled;



    uint8_t MaxBands;



    SysTime_t ElapsedTimeSinceStartUp;



    
# 298 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
   _Bool 
# 298 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
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
# 347 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonValueInRange( int8_t value, int8_t min, int8_t max );
# 367 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"

# 367 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
_Bool 
# 367 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
    RegionCommonChanVerifyDr( uint8_t nbChannels, uint16_t* channelsMask, int8_t dr,
                            int8_t minDr, int8_t maxDr, ChannelParams_t* channels );
# 382 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"

# 382 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
_Bool 
# 382 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
    RegionCommonChanDisable( uint16_t* channelsMask, uint8_t id, uint8_t maxChannels );
# 396 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonCountChannels( uint16_t* channelsMask, uint8_t startIdx, uint8_t stopIdx );
# 408 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonChanMaskCopy( uint16_t* channelsMaskDest, uint16_t* channelsMaskSrc, uint8_t len );
# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonSetBandTxDone( Band_t* band, UTIL_TIMER_Time_t lastTxAirTime, 
# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                                                        _Bool 
# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                                                             joined, SysTime_t elapsedTimeSinceStartup );
# 444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
UTIL_TIMER_Time_t RegionCommonUpdateBandTimeOff( 
# 444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                          _Bool 
# 444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                               joined, Band_t* bands,
                                           uint8_t nbBands, 
# 445 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                                           _Bool 
# 445 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                                                dutyCycleEnabled,
                                           
# 446 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h" 3 4
                                          _Bool 
# 446 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
                                               lastTxIsJoinRequest, SysTime_t elapsedTimeSinceStartup,
                                           UTIL_TIMER_Time_t expectedTimeOnAir );
# 461 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonParseLinkAdrReq( uint8_t* payload, RegionCommonLinkAdrParams_t* parseLinkAdr );
# 477 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint8_t RegionCommonLinkAdrReqVerifyParams( RegionCommonLinkAdrReqVerifyParams_t* verifyParams, int8_t* dr, int8_t* txPow, uint8_t* nbRep );
# 488 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint32_t RegionCommonComputeSymbolTimeLoRa( uint8_t phyDr, uint32_t bandwidthInHz );
# 497 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
uint32_t RegionCommonComputeSymbolTimeFsk( uint8_t phyDrInKbps );
# 515 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonComputeRxWindowParameters( uint32_t tSymbolInUs, uint8_t minRxSymbols, uint32_t rxErrorInMs, uint32_t wakeUpTimeInMs, uint32_t* windowTimeoutInSymbols, int32_t* windowOffsetInMs );
# 532 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonComputeTxPower( int8_t txPowerIndex, float maxEirp, float antennaGain );






void RegionCommonRxBeaconSetup( RegionCommonRxBeaconSetupParams_t* rxBeaconSetupParams );
# 554 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
void RegionCommonCountNbOfEnabledChannels( RegionCommonCountNbOfEnabledChannelsParams_t* countNbOfEnabledChannelsParams,
                                           uint8_t* enabledChannels, uint8_t* nbEnabledChannels, uint8_t* nbRestrictedChannels );
# 578 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
LoRaMacStatus_t RegionCommonIdentifyChannels( RegionCommonIdentifyChannelsParam_t* identifyChannelsParam,
                                              UTIL_TIMER_Time_t* aggregatedTimeOff, uint8_t* enabledChannels,
                                              uint8_t* nbEnabledChannels, uint8_t* nbRestrictedChannels,
                                              UTIL_TIMER_Time_t* nextTxDelay );
# 590 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonGetNextLowerTxDr( RegionCommonGetNextLowerTxDrParams_t *params );
# 601 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
int8_t RegionCommonLimitTxPower( int8_t txPower, int8_t maxBandTxPower );
# 612 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCommon.h"
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
# 66 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 2




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



    
# 458 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 458 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
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



    
# 508 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 508 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
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



    
# 599 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 599 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
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



    
# 661 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 661 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
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



    
# 779 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 779 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        Joined;



    
# 783 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 783 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
        DutyCycleEnabled;



    SysTime_t ElapsedTimeSinceStartUp;



    
# 791 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
   _Bool 
# 791 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
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
# 884 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 884 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 884 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionIsActive( LoRaMacRegion_t region );
# 895 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
PhyParam_t RegionGetPhyParam( LoRaMacRegion_t region, GetPhyParams_t* getPhy );
# 904 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionSetBandTxDone( LoRaMacRegion_t region, SetBandTxDoneParams_t* txDone );
# 913 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionInitDefaults( LoRaMacRegion_t region, InitDefaultsParams_t* params );
# 926 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 926 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 926 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionVerify( LoRaMacRegion_t region, VerifyParams_t* verify, PhyAttribute_t phyAttribute );
# 936 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionApplyCFList( LoRaMacRegion_t region, ApplyCFListParams_t* applyCFList );
# 947 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 947 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 947 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionChanMaskSet( LoRaMacRegion_t region, ChanMaskSetParams_t* chanMaskSet );
# 960 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 960 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 960 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionRxConfig( LoRaMacRegion_t region, RxConfigParams_t* rxConfig, int8_t* datarate );
# 1015 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionComputeRxWindowParameters( LoRaMacRegion_t region, int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 1030 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 1030 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 1030 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionTxConfig( LoRaMacRegion_t region, TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 1049 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionLinkAdrReq( LoRaMacRegion_t region, LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 1060 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionRxParamSetupReq( LoRaMacRegion_t region, RxParamSetupReqParams_t* rxParamSetupReq );
# 1071 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionNewChannelReq( LoRaMacRegion_t region, NewChannelReqParams_t* newChannelReq );
# 1084 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionTxParamSetupReq( LoRaMacRegion_t region, TxParamSetupReqParams_t* txParamSetupReq );
# 1095 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionDlChannelReq( LoRaMacRegion_t region, DlChannelReqParams_t* dlChannelReq );
# 1108 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
int8_t RegionAlternateDr( LoRaMacRegion_t region, int8_t currentDr, AlternateDrType_t type );
# 1124 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
LoRaMacStatus_t RegionNextChannel( LoRaMacRegion_t region, NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 1135 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
LoRaMacStatus_t RegionChannelAdd( LoRaMacRegion_t region, ChannelAddParams_t* channelAdd );
# 1146 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"

# 1146 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h" 3 4
_Bool 
# 1146 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
    RegionChannelsRemove( LoRaMacRegion_t region, ChannelRemoveParams_t* channelRemove );
# 1155 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionSetContinuousWave( LoRaMacRegion_t region, ContinuousWaveParams_t* continuousWave );
# 1168 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
uint8_t RegionApplyDrOffset( LoRaMacRegion_t region, uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );
# 1177 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.h"
void RegionRxBeaconSetup( LoRaMacRegion_t region, RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );






Version_t RegionGetVersion( void );
# 46 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 2





#define CHANNEL_PLAN_GROUP_AS923_1 1





#define CHANNEL_PLAN_GROUP_AS923_2 2





#define CHANNEL_PLAN_GROUP_AS923_3 3





#define CHANNEL_PLAN_GROUP_AS923_1_JP 4




#define AS923_MAX_NB_CHANNELS 16




#define AS923_NUMB_DEFAULT_CHANNELS 2




#define AS923_NUMB_CHANNELS_CF_LIST 5




#define AS923_TX_MIN_DATARATE DR_0




#define AS923_TX_MAX_DATARATE DR_7




#define AS923_RX_MIN_DATARATE DR_0




#define AS923_RX_MAX_DATARATE DR_7




#define AS923_DEFAULT_DATARATE DR_2





#define AS923_DWELL_LIMIT_DATARATE DR_2




#define AS923_MIN_RX1_DR_OFFSET 0




#define AS923_MAX_RX1_DR_OFFSET 7




#define AS923_MIN_TX_POWER TX_POWER_7




#define AS923_MAX_TX_POWER TX_POWER_0




#define AS923_DEFAULT_TX_POWER TX_POWER_0




#define AS923_DEFAULT_UPLINK_DWELL_TIME 1




#define AS923_DEFAULT_MAX_EIRP 16.0f




#define AS923_DEFAULT_ANTENNA_GAIN 2.15f




#define AS923_DUTY_CYCLE_ENABLED 0




#define AS923_MAX_RX_WINDOW 3000
# 174 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
#define AS923_RX_WND_2_FREQ 923200000




#define AS923_RX_WND_2_DR DR_2







#define AS923_BEACON_CHANNEL_FREQ 923400000




#define AS923_PING_SLOT_CHANNEL_FREQ 923400000




#define AS923_BEACON_SIZE 17




#define AS923_RFU1_SIZE 2




#define AS923_RFU2_SIZE 0




#define AS923_BEACON_CHANNEL_DR DR_3




#define AS923_BEACON_CHANNEL_BW 0




#define AS923_PING_SLOT_CHANNEL_DR DR_3




#define AS923_MAX_NB_BANDS 1





#define AS923_BAND0 { 100, AS923_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define AS923_LC1 { 923200000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define AS923_LC2 { 923400000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define AS923_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) )




#define AS923_RSSI_FREE_TH -80




#define AS923_CARRIER_SENSE_TIME 5




static const uint8_t DataratesAS923[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsAS923[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };





static const uint8_t MaxPayloadOfDatarateDwell0AS923[] = { 59, 59, 123, 123, 250, 250, 250, 250 };





static const uint8_t MaxPayloadOfDatarateDwell1AS923[] = { 0, 0, 19, 61, 133, 250, 250, 250 };





static const uint8_t MaxPayloadOfDatarateDwell1DownAS923[] = { 0, 0, 11, 53, 126, 242, 242, 242 };




static const int8_t EffectiveRx1DrOffsetAS923[] = { 0, 1, 2, 3, 4, 5, -1, -2 };
# 302 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
PhyParam_t RegionAS923GetPhyParam( GetPhyParams_t* getPhy );






void RegionAS923SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionAS923InitDefaults( InitDefaultsParams_t* params );
# 327 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"

# 327 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 3 4
_Bool 
# 327 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
    RegionAS923Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionAS923ApplyCFList( ApplyCFListParams_t* applyCFList );
# 344 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"

# 344 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 3 4
_Bool 
# 344 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
    RegionAS923ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 359 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
void RegionAS923ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 370 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"

# 370 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 3 4
_Bool 
# 370 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
    RegionAS923RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 383 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"

# 383 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 3 4
_Bool 
# 383 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
    RegionAS923TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 392 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
uint8_t RegionAS923LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 401 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
uint8_t RegionAS923RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 410 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
int8_t RegionAS923NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 421 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
int8_t RegionAS923TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 430 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
int8_t RegionAS923DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 439 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
int8_t RegionAS923AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 453 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
LoRaMacStatus_t RegionAS923NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 462 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
LoRaMacStatus_t RegionAS923ChannelAdd( ChannelAddParams_t* channelAdd );
# 471 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"

# 471 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h" 3 4
_Bool 
# 471 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
    RegionAS923ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionAS923SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 491 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAS923.h"
uint8_t RegionAS923ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






 void RegionAS923RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 36 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define AS923_CASE case LORAMAC_REGION_AS923:
#define AS923_IS_ACTIVE() AS923_CASE { return true; }
#define AS923_GET_PHY_PARAM() AS923_CASE { return RegionAS923GetPhyParam( getPhy ); }
#define AS923_SET_BAND_TX_DONE() AS923_CASE { RegionAS923SetBandTxDone( txDone ); break; }
#define AS923_INIT_DEFAULTS() AS923_CASE { RegionAS923InitDefaults( params ); break; }
#define AS923_VERIFY() AS923_CASE { return RegionAS923Verify( verify, phyAttribute ); }
#define AS923_APPLY_CF_LIST() AS923_CASE { RegionAS923ApplyCFList( applyCFList ); break; }
#define AS923_CHAN_MASK_SET() AS923_CASE { return RegionAS923ChanMaskSet( chanMaskSet ); }
#define AS923_COMPUTE_RX_WINDOW_PARAMETERS() AS923_CASE { RegionAS923ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define AS923_RX_CONFIG() AS923_CASE { return RegionAS923RxConfig( rxConfig, datarate ); }
#define AS923_TX_CONFIG() AS923_CASE { return RegionAS923TxConfig( txConfig, txPower, txTimeOnAir ); }
#define AS923_LINK_ADR_REQ() AS923_CASE { return RegionAS923LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define AS923_RX_PARAM_SETUP_REQ() AS923_CASE { return RegionAS923RxParamSetupReq( rxParamSetupReq ); }
#define AS923_NEW_CHANNEL_REQ() AS923_CASE { return RegionAS923NewChannelReq( newChannelReq ); }
#define AS923_TX_PARAM_SETUP_REQ() AS923_CASE { return RegionAS923TxParamSetupReq( txParamSetupReq ); }
#define AS923_DL_CHANNEL_REQ() AS923_CASE { return RegionAS923DlChannelReq( dlChannelReq ); }
#define AS923_ALTERNATE_DR() AS923_CASE { return RegionAS923AlternateDr( currentDr, type ); }
#define AS923_NEXT_CHANNEL() AS923_CASE { return RegionAS923NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define AS923_CHANNEL_ADD() AS923_CASE { return RegionAS923ChannelAdd( channelAdd ); }
#define AS923_CHANNEL_REMOVE() AS923_CASE { return RegionAS923ChannelsRemove( channelRemove ); }
#define AS923_SET_CONTINUOUS_WAVE() AS923_CASE { RegionAS923SetContinuousWave( continuousWave ); break; }
#define AS923_APPLY_DR_OFFSET() AS923_CASE { return RegionAS923ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define AS923_RX_BEACON_SETUP() AS923_CASE { RegionAS923RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 86 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
#define __REGION_AU915_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
#define AU915_MAX_NB_CHANNELS 72




#define AU915_TX_MIN_DATARATE DR_0




#define AU915_TX_MAX_DATARATE DR_6




#define AU915_RX_MIN_DATARATE DR_8




#define AU915_RX_MAX_DATARATE DR_13




#define AU915_DEFAULT_DATARATE DR_2





#define AU915_DWELL_LIMIT_DATARATE DR_2




#define AU915_MIN_RX1_DR_OFFSET 0




#define AU915_MAX_RX1_DR_OFFSET 5




#define AU915_MIN_TX_POWER TX_POWER_14




#define AU915_MAX_TX_POWER TX_POWER_0




#define AU915_DEFAULT_TX_POWER TX_POWER_0




#define AU915_DEFAULT_UPLINK_DWELL_TIME 1




#define AU915_DEFAULT_MAX_EIRP 30.0f




#define AU915_DEFAULT_ANTENNA_GAIN 2.15f




#define AU915_DUTY_CYCLE_ENABLED 0




#define AU915_MAX_RX_WINDOW 3000




#define AU915_RX_WND_2_FREQ 923300000




#define AU915_RX_WND_2_DR DR_8







#define AU915_BEACON_CHANNEL_FREQ 923300000




#define AU915_BEACON_CHANNEL_STEPWIDTH 600000




#define AU915_PING_SLOT_CHANNEL_FREQ 923300000




#define AU915_BEACON_NB_CHANNELS 8




#define AU915_BEACON_SIZE 23




#define AU915_RFU1_SIZE 5




#define AU915_RFU2_SIZE 3




#define AU915_BEACON_CHANNEL_DR DR_8




#define AU915_BEACON_CHANNEL_BW 2




#define AU915_PING_SLOT_CHANNEL_DR DR_8




#define AU915_MAX_NB_BANDS 1





#define AU915_BAND0 { 1, AU915_MAX_TX_POWER, 0, 0, 0, 0, 0 }




#define AU915_FIRST_RX1_CHANNEL ( (uint32_t) 923300000 )




#define AU915_LAST_RX1_CHANNEL ( (uint32_t) 927500000 )




#define AU915_STEPWIDTH_RX1_CHANNEL ( (uint32_t) 600000 )




static const uint8_t DataratesAU915[] = { 12, 11, 10, 9, 8, 7, 8, 0, 12, 11, 10, 9, 8, 7, 0, 0 };




static const uint32_t BandwidthsAU915[] = { 125000, 125000, 125000, 125000, 125000, 125000, 500000, 0, 500000, 500000, 500000, 500000, 500000, 500000, 0, 0 };




static const int8_t DatarateOffsetsAU915[7][6] =
{
    { 8 , 8 , 8 , 8 , 8 , 8 },
    { 9 , 8 , 8 , 8 , 8 , 8 },
    { 10, 9 , 8 , 8 , 8 , 8 },
    { 11, 10, 9 , 8 , 8 , 8 },
    { 12, 11, 10, 9 , 8 , 8 },
    { 13, 12, 11, 10, 9 , 8 },
    { 13, 13, 12, 11, 10, 9 },
};





static const uint8_t MaxPayloadOfDatarateDwell0AU915[] = { 51, 51, 51, 115, 242, 242, 242, 0, 53, 129, 242, 242, 242, 242 };





static const uint8_t MaxPayloadOfDatarateDwell1AU915[] = { 0, 0, 11, 53, 125, 242, 242, 0, 53, 129, 242, 242, 242, 242 };
# 265 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
PhyParam_t RegionAU915GetPhyParam( GetPhyParams_t* getPhy );






void RegionAU915SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionAU915InitDefaults( InitDefaultsParams_t* params );
# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"

# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 3 4
_Bool 
# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
    RegionAU915Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionAU915ApplyCFList( ApplyCFListParams_t* applyCFList );
# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"

# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 3 4
_Bool 
# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
    RegionAU915ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 322 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
void RegionAU915ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"

# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 3 4
_Bool 
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
    RegionAU915RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"

# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 3 4
_Bool 
# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
    RegionAU915TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 355 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
uint8_t RegionAU915LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 364 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
uint8_t RegionAU915RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 373 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
int8_t RegionAU915NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 384 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
int8_t RegionAU915TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 393 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
int8_t RegionAU915DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 402 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
int8_t RegionAU915AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 416 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
LoRaMacStatus_t RegionAU915NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 425 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
LoRaMacStatus_t RegionAU915ChannelAdd( ChannelAddParams_t* channelAdd );
# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"

# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h" 3 4
_Bool 
# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
    RegionAU915ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionAU915SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 454 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionAU915.h"
uint8_t RegionAU915ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






 void RegionAU915RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 87 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define AU915_CASE case LORAMAC_REGION_AU915:
#define AU915_IS_ACTIVE() AU915_CASE { return true; }
#define AU915_GET_PHY_PARAM() AU915_CASE { return RegionAU915GetPhyParam( getPhy ); }
#define AU915_SET_BAND_TX_DONE() AU915_CASE { RegionAU915SetBandTxDone( txDone ); break; }
#define AU915_INIT_DEFAULTS() AU915_CASE { RegionAU915InitDefaults( params ); break; }
#define AU915_VERIFY() AU915_CASE { return RegionAU915Verify( verify, phyAttribute ); }
#define AU915_APPLY_CF_LIST() AU915_CASE { RegionAU915ApplyCFList( applyCFList ); break; }
#define AU915_CHAN_MASK_SET() AU915_CASE { return RegionAU915ChanMaskSet( chanMaskSet ); }
#define AU915_COMPUTE_RX_WINDOW_PARAMETERS() AU915_CASE { RegionAU915ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define AU915_RX_CONFIG() AU915_CASE { return RegionAU915RxConfig( rxConfig, datarate ); }
#define AU915_TX_CONFIG() AU915_CASE { return RegionAU915TxConfig( txConfig, txPower, txTimeOnAir ); }
#define AU915_LINK_ADR_REQ() AU915_CASE { return RegionAU915LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define AU915_RX_PARAM_SETUP_REQ() AU915_CASE { return RegionAU915RxParamSetupReq( rxParamSetupReq ); }
#define AU915_NEW_CHANNEL_REQ() AU915_CASE { return RegionAU915NewChannelReq( newChannelReq ); }
#define AU915_TX_PARAM_SETUP_REQ() AU915_CASE { return RegionAU915TxParamSetupReq( txParamSetupReq ); }
#define AU915_DL_CHANNEL_REQ() AU915_CASE { return RegionAU915DlChannelReq( dlChannelReq ); }
#define AU915_ALTERNATE_DR() AU915_CASE { return RegionAU915AlternateDr( currentDr, type ); }
#define AU915_NEXT_CHANNEL() AU915_CASE { return RegionAU915NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define AU915_CHANNEL_ADD() AU915_CASE { return RegionAU915ChannelAdd( channelAdd ); }
#define AU915_CHANNEL_REMOVE() AU915_CASE { return RegionAU915ChannelsRemove( channelRemove ); }
#define AU915_SET_CONTINUOUS_WAVE() AU915_CASE { RegionAU915SetContinuousWave( continuousWave ); break; }
#define AU915_APPLY_DR_OFFSET() AU915_CASE { return RegionAU915ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define AU915_RX_BEACON_SETUP() AU915_CASE { RegionAU915RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 137 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
#define __REGION_CN470_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
#define CN470_MAX_NB_CHANNELS 96




#define CN470_TX_MIN_DATARATE DR_0




#define CN470_TX_MAX_DATARATE DR_5




#define CN470_RX_MIN_DATARATE DR_0




#define CN470_RX_MAX_DATARATE DR_5




#define CN470_DEFAULT_DATARATE DR_0




#define CN470_MIN_RX1_DR_OFFSET 0




#define CN470_MAX_RX1_DR_OFFSET 5




#define CN470_MIN_TX_POWER TX_POWER_7




#define CN470_MAX_TX_POWER TX_POWER_0




#define CN470_DEFAULT_TX_POWER TX_POWER_0




#define CN470_DEFAULT_MAX_EIRP 19.15f




#define CN470_DEFAULT_ANTENNA_GAIN 2.15f




#define CN470_DUTY_CYCLE_ENABLED 0




#define CN470_MAX_RX_WINDOW 3000




#define CN470_RX_WND_2_FREQ 505300000




#define CN470_RX_WND_2_DR DR_0




#define CN470_DEFAULT_UPLINK_DWELL_TIME 0







#define CN470_BEACON_CHANNEL_FREQ 508300000




#define CN470_BEACON_CHANNEL_STEPWIDTH 200000




#define CN470_PING_SLOT_CHANNEL_FREQ 508300000




#define CN470_BEACON_NB_CHANNELS 8




#define CN470_BEACON_SIZE 19




#define CN470_RFU1_SIZE 3




#define CN470_RFU2_SIZE 1




#define CN470_BEACON_CHANNEL_DR DR_2




#define CN470_BEACON_CHANNEL_BW 0




#define CN470_PING_SLOT_CHANNEL_DR DR_2




#define CN470_MAX_NB_BANDS 1





#define CN470_BAND0 { 1, CN470_MAX_TX_POWER, 0, 0, 0, 0, 0 }




#define CN470_FIRST_RX1_CHANNEL ( (uint32_t) 500300000 )




#define CN470_LAST_RX1_CHANNEL ( (uint32_t) 509700000 )




#define CN470_STEPWIDTH_RX1_CHANNEL ( (uint32_t) 200000 )




static const uint8_t DataratesCN470[] = { 12, 11, 10, 9, 8, 7 };




static const uint32_t BandwidthsCN470[] = { 125000, 125000, 125000, 125000, 125000, 125000 };




static const uint8_t MaxPayloadOfDatarateCN470[] = { 51, 51, 51, 115, 242, 242 };
# 238 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
PhyParam_t RegionCN470GetPhyParam( GetPhyParams_t* getPhy );






void RegionCN470SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionCN470InitDefaults( InitDefaultsParams_t* params );
# 263 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"

# 263 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 3 4
_Bool 
# 263 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
    RegionCN470Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionCN470ApplyCFList( ApplyCFListParams_t* applyCFList );
# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"

# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 3 4
_Bool 
# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
    RegionCN470ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 295 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
void RegionCN470ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"

# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 3 4
_Bool 
# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
    RegionCN470RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 319 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"

# 319 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 3 4
_Bool 
# 319 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
    RegionCN470TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 328 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
uint8_t RegionCN470LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 337 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
uint8_t RegionCN470RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
int8_t RegionCN470NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 357 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
int8_t RegionCN470TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 366 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
int8_t RegionCN470DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 377 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
int8_t RegionCN470AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 391 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
LoRaMacStatus_t RegionCN470NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 400 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
LoRaMacStatus_t RegionCN470ChannelAdd( ChannelAddParams_t* channelAdd );
# 409 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"

# 409 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h" 3 4
_Bool 
# 409 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
    RegionCN470ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionCN470SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 429 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN470.h"
uint8_t RegionCN470ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






void RegionCN470RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 138 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define CN470_CASE case LORAMAC_REGION_CN470:
#define CN470_IS_ACTIVE() CN470_CASE { return true; }
#define CN470_GET_PHY_PARAM() CN470_CASE { return RegionCN470GetPhyParam( getPhy ); }
#define CN470_SET_BAND_TX_DONE() CN470_CASE { RegionCN470SetBandTxDone( txDone ); break; }
#define CN470_INIT_DEFAULTS() CN470_CASE { RegionCN470InitDefaults( params ); break; }
#define CN470_VERIFY() CN470_CASE { return RegionCN470Verify( verify, phyAttribute ); }
#define CN470_APPLY_CF_LIST() CN470_CASE { RegionCN470ApplyCFList( applyCFList ); break; }
#define CN470_CHAN_MASK_SET() CN470_CASE { return RegionCN470ChanMaskSet( chanMaskSet ); }
#define CN470_COMPUTE_RX_WINDOW_PARAMETERS() CN470_CASE { RegionCN470ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define CN470_RX_CONFIG() CN470_CASE { return RegionCN470RxConfig( rxConfig, datarate ); }
#define CN470_TX_CONFIG() CN470_CASE { return RegionCN470TxConfig( txConfig, txPower, txTimeOnAir ); }
#define CN470_LINK_ADR_REQ() CN470_CASE { return RegionCN470LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define CN470_RX_PARAM_SETUP_REQ() CN470_CASE { return RegionCN470RxParamSetupReq( rxParamSetupReq ); }
#define CN470_NEW_CHANNEL_REQ() CN470_CASE { return RegionCN470NewChannelReq( newChannelReq ); }
#define CN470_TX_PARAM_SETUP_REQ() CN470_CASE { return RegionCN470TxParamSetupReq( txParamSetupReq ); }
#define CN470_DL_CHANNEL_REQ() CN470_CASE { return RegionCN470DlChannelReq( dlChannelReq ); }
#define CN470_ALTERNATE_DR() CN470_CASE { return RegionCN470AlternateDr( currentDr, type ); }
#define CN470_NEXT_CHANNEL() CN470_CASE { return RegionCN470NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define CN470_CHANNEL_ADD() CN470_CASE { return RegionCN470ChannelAdd( channelAdd ); }
#define CN470_CHANNEL_REMOVE() CN470_CASE { return RegionCN470ChannelsRemove( channelRemove ); }
#define CN470_SET_CONTINUOUS_WAVE() CN470_CASE { RegionCN470SetContinuousWave( continuousWave ); break; }
#define CN470_APPLY_DR_OFFSET() CN470_CASE { return RegionCN470ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define CN470_RX_BEACON_SETUP() CN470_CASE { RegionCN470RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 188 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
#define __REGION_CN779_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
#define CN779_MAX_NB_CHANNELS 16




#define CN779_NUMB_DEFAULT_CHANNELS 3




#define CN779_NUMB_CHANNELS_CF_LIST 5




#define CN779_TX_MIN_DATARATE DR_0




#define CN779_TX_MAX_DATARATE DR_7




#define CN779_RX_MIN_DATARATE DR_0




#define CN779_RX_MAX_DATARATE DR_7




#define CN779_DEFAULT_DATARATE DR_0




#define CN779_MIN_RX1_DR_OFFSET 0




#define CN779_MAX_RX1_DR_OFFSET 5




#define CN779_MIN_TX_POWER TX_POWER_5




#define CN779_MAX_TX_POWER TX_POWER_0




#define CN779_DEFAULT_TX_POWER TX_POWER_0




#define CN779_DEFAULT_MAX_EIRP 12.15f




#define CN779_DEFAULT_ANTENNA_GAIN 2.15f




#define CN779_DUTY_CYCLE_ENABLED 1




#define CN779_MAX_RX_WINDOW 3000
# 142 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
#define CN779_RX_WND_2_FREQ 786000000




#define CN779_RX_WND_2_DR DR_0




#define CN779_DEFAULT_UPLINK_DWELL_TIME 0







#define CN779_BEACON_CHANNEL_FREQ 785000000




#define CN779_PING_SLOT_CHANNEL_FREQ 785000000




#define CN779_BEACON_SIZE 17




#define CN779_RFU1_SIZE 2




#define CN779_RFU2_SIZE 0




#define CN779_BEACON_CHANNEL_DR DR_3




#define CN779_BEACON_CHANNEL_BW 0




#define CN779_PING_SLOT_CHANNEL_DR DR_3




#define CN779_MAX_NB_BANDS 1





#define CN779_BAND0 { 100, CN779_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define CN779_LC1 { 779500000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define CN779_LC2 { 779700000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define CN779_LC3 { 779900000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define CN779_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) | LC( 3 ) )




static const uint8_t DataratesCN779[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsCN779[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };




static const uint8_t MaxPayloadOfDatarateCN779[] = { 51, 51, 51, 115, 242, 242, 242, 242 };
# 252 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
PhyParam_t RegionCN779GetPhyParam( GetPhyParams_t* getPhy );






void RegionCN779SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionCN779InitDefaults( InitDefaultsParams_t* params );
# 277 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"

# 277 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 3 4
_Bool 
# 277 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
    RegionCN779Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionCN779ApplyCFList( ApplyCFListParams_t* applyCFList );
# 294 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"

# 294 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 3 4
_Bool 
# 294 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
    RegionCN779ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 309 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
void RegionCN779ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 320 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"

# 320 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 3 4
_Bool 
# 320 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
    RegionCN779RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"

# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 3 4
_Bool 
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
    RegionCN779TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 342 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
uint8_t RegionCN779LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 351 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
uint8_t RegionCN779RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 360 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
int8_t RegionCN779NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 371 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
int8_t RegionCN779TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 380 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
int8_t RegionCN779DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 389 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
int8_t RegionCN779AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 403 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
LoRaMacStatus_t RegionCN779NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 412 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
LoRaMacStatus_t RegionCN779ChannelAdd( ChannelAddParams_t* channelAdd );
# 421 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"

# 421 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h" 3 4
_Bool 
# 421 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
    RegionCN779ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionCN779SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 441 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionCN779.h"
uint8_t RegionCN779ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






 void RegionCN779RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 189 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define CN779_CASE case LORAMAC_REGION_CN779:
#define CN779_IS_ACTIVE() CN779_CASE { return true; }
#define CN779_GET_PHY_PARAM() CN779_CASE { return RegionCN779GetPhyParam( getPhy ); }
#define CN779_SET_BAND_TX_DONE() CN779_CASE { RegionCN779SetBandTxDone( txDone ); break; }
#define CN779_INIT_DEFAULTS() CN779_CASE { RegionCN779InitDefaults( params ); break; }
#define CN779_VERIFY() CN779_CASE { return RegionCN779Verify( verify, phyAttribute ); }
#define CN779_APPLY_CF_LIST() CN779_CASE { RegionCN779ApplyCFList( applyCFList ); break; }
#define CN779_CHAN_MASK_SET() CN779_CASE { return RegionCN779ChanMaskSet( chanMaskSet ); }
#define CN779_COMPUTE_RX_WINDOW_PARAMETERS() CN779_CASE { RegionCN779ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define CN779_RX_CONFIG() CN779_CASE { return RegionCN779RxConfig( rxConfig, datarate ); }
#define CN779_TX_CONFIG() CN779_CASE { return RegionCN779TxConfig( txConfig, txPower, txTimeOnAir ); }
#define CN779_LINK_ADR_REQ() CN779_CASE { return RegionCN779LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define CN779_RX_PARAM_SETUP_REQ() CN779_CASE { return RegionCN779RxParamSetupReq( rxParamSetupReq ); }
#define CN779_NEW_CHANNEL_REQ() CN779_CASE { return RegionCN779NewChannelReq( newChannelReq ); }
#define CN779_TX_PARAM_SETUP_REQ() CN779_CASE { return RegionCN779TxParamSetupReq( txParamSetupReq ); }
#define CN779_DL_CHANNEL_REQ() CN779_CASE { return RegionCN779DlChannelReq( dlChannelReq ); }
#define CN779_ALTERNATE_DR() CN779_CASE { return RegionCN779AlternateDr( currentDr, type ); }
#define CN779_NEXT_CHANNEL() CN779_CASE { return RegionCN779NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define CN779_CHANNEL_ADD() CN779_CASE { return RegionCN779ChannelAdd( channelAdd ); }
#define CN779_CHANNEL_REMOVE() CN779_CASE { return RegionCN779ChannelsRemove( channelRemove ); }
#define CN779_SET_CONTINUOUS_WAVE() CN779_CASE { RegionCN779SetContinuousWave( continuousWave ); break; }
#define CN779_APPLY_DR_OFFSET() CN779_CASE { return RegionCN779ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define CN779_RX_BEACON_SETUP() CN779_CASE { RegionCN779RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 239 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
#define __REGION_EU433_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
#define EU433_MAX_NB_CHANNELS 16




#define EU433_NUMB_DEFAULT_CHANNELS 3




#define EU433_NUMB_CHANNELS_CF_LIST 5




#define EU433_TX_MIN_DATARATE DR_0




#define EU433_TX_MAX_DATARATE DR_7




#define EU433_RX_MIN_DATARATE DR_0




#define EU433_RX_MAX_DATARATE DR_7




#define EU433_DEFAULT_DATARATE DR_0




#define EU433_MIN_RX1_DR_OFFSET 0




#define EU433_MAX_RX1_DR_OFFSET 5




#define EU433_MIN_TX_POWER TX_POWER_5




#define EU433_MAX_TX_POWER TX_POWER_0




#define EU433_DEFAULT_TX_POWER TX_POWER_0




#define EU433_DEFAULT_MAX_EIRP 12.15f




#define EU433_DEFAULT_ANTENNA_GAIN 2.15f




#define EU433_DUTY_CYCLE_ENABLED 1




#define EU433_MAX_RX_WINDOW 3000
# 142 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
#define EU433_RX_WND_2_FREQ 434665000




#define EU433_RX_WND_2_DR DR_0




#define EU433_MAX_NB_BANDS 1




#define EU433_DEFAULT_UPLINK_DWELL_TIME 0







#define EU433_BEACON_CHANNEL_FREQ 434665000




#define EU433_PING_SLOT_CHANNEL_FREQ 434665000




#define EU433_BEACON_SIZE 17




#define EU433_RFU1_SIZE 2




#define EU433_RFU2_SIZE 0




#define EU433_BEACON_CHANNEL_DR DR_3




#define EU433_BEACON_CHANNEL_BW 0




#define EU433_PING_SLOT_CHANNEL_DR DR_3





#define EU433_BAND0 { 100, EU433_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU433_LC1 { 433175000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define EU433_LC2 { 433375000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define EU433_LC3 { 433575000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define EU433_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) | LC( 3 ) )




static const uint8_t DataratesEU433[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsEU433[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };




static const uint8_t MaxPayloadOfDatarateEU433[] = { 51, 51, 51, 115, 242, 242, 242, 242 };
# 253 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
PhyParam_t RegionEU433GetPhyParam( GetPhyParams_t* getPhy );






void RegionEU433SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionEU433InitDefaults( InitDefaultsParams_t* params );
# 278 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"

# 278 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 3 4
_Bool 
# 278 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
    RegionEU433Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionEU433ApplyCFList( ApplyCFListParams_t* applyCFList );
# 295 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"

# 295 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 3 4
_Bool 
# 295 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
    RegionEU433ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 310 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
void RegionEU433ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 321 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"

# 321 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 3 4
_Bool 
# 321 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
    RegionEU433RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 334 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"

# 334 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 3 4
_Bool 
# 334 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
    RegionEU433TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 343 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
uint8_t RegionEU433LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 352 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
uint8_t RegionEU433RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 361 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
int8_t RegionEU433NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 372 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
int8_t RegionEU433TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 381 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
int8_t RegionEU433DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 390 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
int8_t RegionEU433AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 404 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
LoRaMacStatus_t RegionEU433NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 413 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
LoRaMacStatus_t RegionEU433ChannelAdd( ChannelAddParams_t* channelAdd );
# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"

# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h" 3 4
_Bool 
# 422 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
    RegionEU433ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionEU433SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 442 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU433.h"
uint8_t RegionEU433ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






void RegionEU433RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 240 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define EU433_CASE case LORAMAC_REGION_EU433:
#define EU433_IS_ACTIVE() EU433_CASE { return true; }
#define EU433_GET_PHY_PARAM() EU433_CASE { return RegionEU433GetPhyParam( getPhy ); }
#define EU433_SET_BAND_TX_DONE() EU433_CASE { RegionEU433SetBandTxDone( txDone ); break; }
#define EU433_INIT_DEFAULTS() EU433_CASE { RegionEU433InitDefaults( params ); break; }
#define EU433_VERIFY() EU433_CASE { return RegionEU433Verify( verify, phyAttribute ); }
#define EU433_APPLY_CF_LIST() EU433_CASE { RegionEU433ApplyCFList( applyCFList ); break; }
#define EU433_CHAN_MASK_SET() EU433_CASE { return RegionEU433ChanMaskSet( chanMaskSet ); }
#define EU433_COMPUTE_RX_WINDOW_PARAMETERS() EU433_CASE { RegionEU433ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define EU433_RX_CONFIG() EU433_CASE { return RegionEU433RxConfig( rxConfig, datarate ); }
#define EU433_TX_CONFIG() EU433_CASE { return RegionEU433TxConfig( txConfig, txPower, txTimeOnAir ); }
#define EU433_LINK_ADR_REQ() EU433_CASE { return RegionEU433LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define EU433_RX_PARAM_SETUP_REQ() EU433_CASE { return RegionEU433RxParamSetupReq( rxParamSetupReq ); }
#define EU433_NEW_CHANNEL_REQ() EU433_CASE { return RegionEU433NewChannelReq( newChannelReq ); }
#define EU433_TX_PARAM_SETUP_REQ() EU433_CASE { return RegionEU433TxParamSetupReq( txParamSetupReq ); }
#define EU433_DL_CHANNEL_REQ() EU433_CASE { return RegionEU433DlChannelReq( dlChannelReq ); }
#define EU433_ALTERNATE_DR() EU433_CASE { return RegionEU433AlternateDr( currentDr, type ); }
#define EU433_NEXT_CHANNEL() EU433_CASE { return RegionEU433NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define EU433_CHANNEL_ADD() EU433_CASE { return RegionEU433ChannelAdd( channelAdd ); }
#define EU433_CHANNEL_REMOVE() EU433_CASE { return RegionEU433ChannelsRemove( channelRemove ); }
#define EU433_SET_CONTINUOUS_WAVE() EU433_CASE { RegionEU433SetContinuousWave( continuousWave ); break; }
#define EU433_APPLY_DR_OFFSET() EU433_CASE { return RegionEU433ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define EU433_RX_BEACON_SETUP() EU433_CASE { RegionEU433RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
#define __REGION_EU868_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
#define EU868_MAX_NB_CHANNELS 16




#define EU868_NUMB_DEFAULT_CHANNELS 3




#define EU868_NUMB_CHANNELS_CF_LIST 5




#define EU868_TX_MIN_DATARATE DR_0




#define EU868_TX_MAX_DATARATE DR_7




#define EU868_RX_MIN_DATARATE DR_0




#define EU868_RX_MAX_DATARATE DR_7




#define EU868_DEFAULT_DATARATE DR_0




#define EU868_MIN_RX1_DR_OFFSET 0




#define EU868_MAX_RX1_DR_OFFSET 5




#define EU868_MIN_TX_POWER TX_POWER_7




#define EU868_MAX_TX_POWER TX_POWER_0




#define EU868_DEFAULT_TX_POWER TX_POWER_0




#define EU868_DEFAULT_MAX_EIRP 16.0f




#define EU868_DEFAULT_ANTENNA_GAIN 2.15f




#define EU868_DUTY_CYCLE_ENABLED 1




#define EU868_MAX_RX_WINDOW 3000
# 139 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
#define EU868_RX_WND_2_FREQ 869525000




#define EU868_RX_WND_2_DR DR_0




#define EU868_DEFAULT_UPLINK_DWELL_TIME 0







#define EU868_BEACON_CHANNEL_FREQ 869525000




#define EU868_PING_SLOT_CHANNEL_FREQ 869525000




#define EU868_BEACON_SIZE 17




#define EU868_RFU1_SIZE 2




#define EU868_RFU2_SIZE 0




#define EU868_BEACON_CHANNEL_DR DR_3




#define EU868_BEACON_CHANNEL_BW 0




#define EU868_PING_SLOT_CHANNEL_DR DR_3




#define EU868_MAX_NB_BANDS 6





#define EU868_BAND0 { 100 , EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU868_BAND1 { 100 , EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU868_BAND2 { 1000, EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU868_BAND3 { 10 , EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU868_BAND4 { 100 , EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }






#define EU868_BAND5 { 1000, EU868_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define EU868_LC1 { 868100000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }





#define EU868_LC2 { 868300000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }





#define EU868_LC3 { 868500000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 1 }




#define EU868_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) | LC( 3 ) )




static const uint8_t DataratesEU868[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsEU868[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };




static const uint8_t MaxPayloadOfDatarateEU868[] = { 51, 51, 51, 115, 242, 242, 242, 242 };
# 281 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
PhyParam_t RegionEU868GetPhyParam( GetPhyParams_t* getPhy );






void RegionEU868SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionEU868InitDefaults( InitDefaultsParams_t* params );
# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"

# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 3 4
_Bool 
# 306 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
    RegionEU868Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionEU868ApplyCFList( ApplyCFListParams_t* applyCFList );
# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"

# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 3 4
_Bool 
# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
    RegionEU868ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 338 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
void RegionEU868ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 349 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"

# 349 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 3 4
_Bool 
# 349 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
    RegionEU868RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 362 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"

# 362 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 3 4
_Bool 
# 362 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
    RegionEU868TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 371 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
uint8_t RegionEU868LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 380 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
uint8_t RegionEU868RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 389 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
int8_t RegionEU868NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 400 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
int8_t RegionEU868TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 409 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
int8_t RegionEU868DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 418 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
int8_t RegionEU868AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 432 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
LoRaMacStatus_t RegionEU868NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 441 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
LoRaMacStatus_t RegionEU868ChannelAdd( ChannelAddParams_t* channelAdd );
# 450 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"

# 450 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h" 3 4
_Bool 
# 450 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
    RegionEU868ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionEU868SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 470 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionEU868.h"
uint8_t RegionEU868ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






void RegionEU868RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 291 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define EU868_CASE case LORAMAC_REGION_EU868:
#define EU868_IS_ACTIVE() EU868_CASE { return true; }
#define EU868_GET_PHY_PARAM() EU868_CASE { return RegionEU868GetPhyParam( getPhy ); }
#define EU868_SET_BAND_TX_DONE() EU868_CASE { RegionEU868SetBandTxDone( txDone ); break; }
#define EU868_INIT_DEFAULTS() EU868_CASE { RegionEU868InitDefaults( params ); break; }
#define EU868_VERIFY() EU868_CASE { return RegionEU868Verify( verify, phyAttribute ); }
#define EU868_APPLY_CF_LIST() EU868_CASE { RegionEU868ApplyCFList( applyCFList ); break; }
#define EU868_CHAN_MASK_SET() EU868_CASE { return RegionEU868ChanMaskSet( chanMaskSet ); }
#define EU868_COMPUTE_RX_WINDOW_PARAMETERS() EU868_CASE { RegionEU868ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define EU868_RX_CONFIG() EU868_CASE { return RegionEU868RxConfig( rxConfig, datarate ); }
#define EU868_TX_CONFIG() EU868_CASE { return RegionEU868TxConfig( txConfig, txPower, txTimeOnAir ); }
#define EU868_LINK_ADR_REQ() EU868_CASE { return RegionEU868LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define EU868_RX_PARAM_SETUP_REQ() EU868_CASE { return RegionEU868RxParamSetupReq( rxParamSetupReq ); }
#define EU868_NEW_CHANNEL_REQ() EU868_CASE { return RegionEU868NewChannelReq( newChannelReq ); }
#define EU868_TX_PARAM_SETUP_REQ() EU868_CASE { return RegionEU868TxParamSetupReq( txParamSetupReq ); }
#define EU868_DL_CHANNEL_REQ() EU868_CASE { return RegionEU868DlChannelReq( dlChannelReq ); }
#define EU868_ALTERNATE_DR() EU868_CASE { return RegionEU868AlternateDr( currentDr, type ); }
#define EU868_NEXT_CHANNEL() EU868_CASE { return RegionEU868NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define EU868_CHANNEL_ADD() EU868_CASE { return RegionEU868ChannelAdd( channelAdd ); }
#define EU868_CHANNEL_REMOVE() EU868_CASE { return RegionEU868ChannelsRemove( channelRemove ); }
#define EU868_SET_CONTINUOUS_WAVE() EU868_CASE { RegionEU868SetContinuousWave( continuousWave ); break; }
#define EU868_APPLY_DR_OFFSET() EU868_CASE { return RegionEU868ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define EU868_RX_BEACON_SETUP() EU868_CASE { RegionEU868RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 341 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
#define __REGION_KR920_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
#define KR920_MAX_NB_CHANNELS 16




#define KR920_NUMB_DEFAULT_CHANNELS 3




#define KR920_NUMB_CHANNELS_CF_LIST 5




#define KR920_TX_MIN_DATARATE DR_0




#define KR920_TX_MAX_DATARATE DR_5




#define KR920_RX_MIN_DATARATE DR_0




#define KR920_RX_MAX_DATARATE DR_5




#define KR920_DEFAULT_DATARATE DR_0




#define KR920_MIN_RX1_DR_OFFSET 0




#define KR920_MAX_RX1_DR_OFFSET 5




#define KR920_MIN_TX_POWER TX_POWER_7




#define KR920_MAX_TX_POWER TX_POWER_0




#define KR920_DEFAULT_TX_POWER TX_POWER_0




#define KR920_DEFAULT_MAX_EIRP_LOW 10.0f




#define KR920_DEFAULT_MAX_EIRP_HIGH 14.0f




#define KR920_DEFAULT_ANTENNA_GAIN 2.15f




#define KR920_DUTY_CYCLE_ENABLED 0




#define KR920_MAX_RX_WINDOW 4000
# 144 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
#define KR920_RX_WND_2_FREQ 921900000




#define KR920_RX_WND_2_DR DR_0




#define KR920_DEFAULT_UPLINK_DWELL_TIME 0







#define KR920_BEACON_CHANNEL_FREQ 923100000




#define KR920_PING_SLOT_CHANNEL_FREQ 923100000




#define KR920_BEACON_SIZE 17




#define KR920_RFU1_SIZE 2




#define KR920_RFU2_SIZE 0




#define KR920_BEACON_CHANNEL_DR DR_3




#define KR920_BEACON_CHANNEL_BW 0




#define KR920_PING_SLOT_CHANNEL_DR DR_3




#define KR920_MAX_NB_BANDS 1





#define KR920_BAND0 { 1 , KR920_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define KR920_LC1 { 922100000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define KR920_LC2 { 922300000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define KR920_LC3 { 922500000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define KR920_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) | LC( 3 ) )




#define KR920_RSSI_FREE_TH -65




#define KR920_CARRIER_SENSE_TIME 6




static const uint8_t DataratesKR920[] = { 12, 11, 10, 9, 8, 7 };




static const uint32_t BandwidthsKR920[] = { 125000, 125000, 125000, 125000, 125000, 125000 };




static const uint8_t MaxPayloadOfDatarateKR920[] = { 51, 51, 51, 115, 242, 242 };
# 265 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
PhyParam_t RegionKR920GetPhyParam( GetPhyParams_t* getPhy );






void RegionKR920SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionKR920InitDefaults( InitDefaultsParams_t* params );
# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"

# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 3 4
_Bool 
# 290 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
    RegionKR920Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionKR920ApplyCFList( ApplyCFListParams_t* applyCFList );
# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"

# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 3 4
_Bool 
# 307 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
    RegionKR920ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 322 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
void RegionKR920ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"

# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 3 4
_Bool 
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
    RegionKR920RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"

# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 3 4
_Bool 
# 346 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
    RegionKR920TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 355 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
uint8_t RegionKR920LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 364 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
uint8_t RegionKR920RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 373 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
int8_t RegionKR920NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 384 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
int8_t RegionKR920TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 393 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
int8_t RegionKR920DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 402 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
int8_t RegionKR920AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 416 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
LoRaMacStatus_t RegionKR920NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 425 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
LoRaMacStatus_t RegionKR920ChannelAdd( ChannelAddParams_t* channelAdd );
# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"

# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h" 3 4
_Bool 
# 434 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
    RegionKR920ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionKR920SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 454 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionKR920.h"
uint8_t RegionKR920ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






 void RegionKR920RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 342 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define KR920_CASE case LORAMAC_REGION_KR920:
#define KR920_IS_ACTIVE() KR920_CASE { return true; }
#define KR920_GET_PHY_PARAM() KR920_CASE { return RegionKR920GetPhyParam( getPhy ); }
#define KR920_SET_BAND_TX_DONE() KR920_CASE { RegionKR920SetBandTxDone( txDone ); break; }
#define KR920_INIT_DEFAULTS() KR920_CASE { RegionKR920InitDefaults( params ); break; }
#define KR920_VERIFY() KR920_CASE { return RegionKR920Verify( verify, phyAttribute ); }
#define KR920_APPLY_CF_LIST() KR920_CASE { RegionKR920ApplyCFList( applyCFList ); break; }
#define KR920_CHAN_MASK_SET() KR920_CASE { return RegionKR920ChanMaskSet( chanMaskSet ); }
#define KR920_COMPUTE_RX_WINDOW_PARAMETERS() KR920_CASE { RegionKR920ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define KR920_RX_CONFIG() KR920_CASE { return RegionKR920RxConfig( rxConfig, datarate ); }
#define KR920_TX_CONFIG() KR920_CASE { return RegionKR920TxConfig( txConfig, txPower, txTimeOnAir ); }
#define KR920_LINK_ADR_REQ() KR920_CASE { return RegionKR920LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define KR920_RX_PARAM_SETUP_REQ() KR920_CASE { return RegionKR920RxParamSetupReq( rxParamSetupReq ); }
#define KR920_NEW_CHANNEL_REQ() KR920_CASE { return RegionKR920NewChannelReq( newChannelReq ); }
#define KR920_TX_PARAM_SETUP_REQ() KR920_CASE { return RegionKR920TxParamSetupReq( txParamSetupReq ); }
#define KR920_DL_CHANNEL_REQ() KR920_CASE { return RegionKR920DlChannelReq( dlChannelReq ); }
#define KR920_ALTERNATE_DR() KR920_CASE { return RegionKR920AlternateDr( currentDr, type ); }
#define KR920_NEXT_CHANNEL() KR920_CASE { return RegionKR920NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define KR920_CHANNEL_ADD() KR920_CASE { return RegionKR920ChannelAdd( channelAdd ); }
#define KR920_CHANNEL_REMOVE() KR920_CASE { return RegionKR920ChannelsRemove( channelRemove ); }
#define KR920_SET_CONTINUOUS_WAVE() KR920_CASE { RegionKR920SetContinuousWave( continuousWave ); break; }
#define KR920_APPLY_DR_OFFSET() KR920_CASE { return RegionKR920ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define KR920_RX_BEACON_SETUP() KR920_CASE { RegionKR920RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 392 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
#define __REGION_IN865_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
#define IN865_MAX_NB_CHANNELS 16




#define IN865_NUMB_DEFAULT_CHANNELS 3




#define IN865_NUMB_CHANNELS_CF_LIST 5




#define IN865_TX_MIN_DATARATE DR_0




#define IN865_TX_MAX_DATARATE DR_7




#define IN865_RX_MIN_DATARATE DR_0




#define IN865_RX_MAX_DATARATE DR_7




#define IN865_DEFAULT_DATARATE DR_0




#define IN865_MIN_RX1_DR_OFFSET 0




#define IN865_MAX_RX1_DR_OFFSET 7




#define IN865_MIN_TX_POWER TX_POWER_10




#define IN865_MAX_TX_POWER TX_POWER_0




#define IN865_DEFAULT_TX_POWER TX_POWER_0




#define IN865_DEFAULT_MAX_EIRP 30.0f




#define IN865_DEFAULT_ANTENNA_GAIN 2.15f




#define IN865_DUTY_CYCLE_ENABLED 0




#define IN865_MAX_RX_WINDOW 3000
# 139 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
#define IN865_RX_WND_2_FREQ 866550000




#define IN865_RX_WND_2_DR DR_2




#define IN865_DEFAULT_UPLINK_DWELL_TIME 0







#define IN865_BEACON_CHANNEL_FREQ 866550000




#define IN865_PING_SLOT_CHANNEL_FREQ 866550000




#define IN865_BEACON_SIZE 19




#define IN865_RFU1_SIZE 1




#define IN865_RFU2_SIZE 3




#define IN865_BEACON_CHANNEL_DR DR_4




#define IN865_BEACON_CHANNEL_BW 0




#define IN865_PING_SLOT_CHANNEL_DR DR_4




#define IN865_MAX_NB_BANDS 1





#define IN865_BAND0 { 1 , IN865_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define IN865_LC1 { 865062500, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define IN865_LC2 { 865402500, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define IN865_LC3 { 865985000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }




#define IN865_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) | LC( 3 ) )




static const uint8_t DataratesIN865[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsIN865[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };




static const uint8_t MaxPayloadOfDatarateIN865[] = { 51, 51, 51, 115, 242, 242, 242, 242 };




static const int8_t EffectiveRx1DrOffsetIN865[] = { 0, 1, 2, 3, 4, 5, -1, -2 };
# 255 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
PhyParam_t RegionIN865GetPhyParam( GetPhyParams_t* getPhy );






void RegionIN865SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionIN865InitDefaults( InitDefaultsParams_t* params );
# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"

# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 3 4
_Bool 
# 280 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
    RegionIN865Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionIN865ApplyCFList( ApplyCFListParams_t* applyCFList );
# 297 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"

# 297 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 3 4
_Bool 
# 297 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
    RegionIN865ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 312 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
void RegionIN865ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"

# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 3 4
_Bool 
# 323 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
    RegionIN865RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 336 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"

# 336 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 3 4
_Bool 
# 336 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
    RegionIN865TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 345 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
uint8_t RegionIN865LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 354 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
uint8_t RegionIN865RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 363 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
int8_t RegionIN865NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 374 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
int8_t RegionIN865TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 383 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
int8_t RegionIN865DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 392 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
int8_t RegionIN865AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 406 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
LoRaMacStatus_t RegionIN865NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 415 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
LoRaMacStatus_t RegionIN865ChannelAdd( ChannelAddParams_t* channelAdd );
# 424 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"

# 424 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h" 3 4
_Bool 
# 424 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
    RegionIN865ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionIN865SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionIN865.h"
uint8_t RegionIN865ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






 void RegionIN865RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 393 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define IN865_CASE case LORAMAC_REGION_IN865:
#define IN865_IS_ACTIVE() IN865_CASE { return true; }
#define IN865_GET_PHY_PARAM() IN865_CASE { return RegionIN865GetPhyParam( getPhy ); }
#define IN865_SET_BAND_TX_DONE() IN865_CASE { RegionIN865SetBandTxDone( txDone ); break; }
#define IN865_INIT_DEFAULTS() IN865_CASE { RegionIN865InitDefaults( params ); break; }
#define IN865_VERIFY() IN865_CASE { return RegionIN865Verify( verify, phyAttribute ); }
#define IN865_APPLY_CF_LIST() IN865_CASE { RegionIN865ApplyCFList( applyCFList ); break; }
#define IN865_CHAN_MASK_SET() IN865_CASE { return RegionIN865ChanMaskSet( chanMaskSet ); }
#define IN865_COMPUTE_RX_WINDOW_PARAMETERS() IN865_CASE { RegionIN865ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define IN865_RX_CONFIG() IN865_CASE { return RegionIN865RxConfig( rxConfig, datarate ); }
#define IN865_TX_CONFIG() IN865_CASE { return RegionIN865TxConfig( txConfig, txPower, txTimeOnAir ); }
#define IN865_LINK_ADR_REQ() IN865_CASE { return RegionIN865LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define IN865_RX_PARAM_SETUP_REQ() IN865_CASE { return RegionIN865RxParamSetupReq( rxParamSetupReq ); }
#define IN865_NEW_CHANNEL_REQ() IN865_CASE { return RegionIN865NewChannelReq( newChannelReq ); }
#define IN865_TX_PARAM_SETUP_REQ() IN865_CASE { return RegionIN865TxParamSetupReq( txParamSetupReq ); }
#define IN865_DL_CHANNEL_REQ() IN865_CASE { return RegionIN865DlChannelReq( dlChannelReq ); }
#define IN865_ALTERNATE_DR() IN865_CASE { return RegionIN865AlternateDr( currentDr, type ); }
#define IN865_NEXT_CHANNEL() IN865_CASE { return RegionIN865NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define IN865_CHANNEL_ADD() IN865_CASE { return RegionIN865ChannelAdd( channelAdd ); }
#define IN865_CHANNEL_REMOVE() IN865_CASE { return RegionIN865ChannelsRemove( channelRemove ); }
#define IN865_SET_CONTINUOUS_WAVE() IN865_CASE { RegionIN865SetContinuousWave( continuousWave ); break; }
#define IN865_APPLY_DR_OFFSET() IN865_CASE { return RegionIN865ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define IN865_RX_BEACON_SETUP() IN865_CASE { RegionIN865RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 443 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 1
# 38 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
#define __REGION_US915_H__ 
# 50 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
#define US915_MAX_NB_CHANNELS 72




#define US915_TX_MIN_DATARATE DR_0




#define US915_TX_MAX_DATARATE DR_4




#define US915_RX_MIN_DATARATE DR_8




#define US915_RX_MAX_DATARATE DR_13




#define US915_DEFAULT_DATARATE DR_0




#define US915_MIN_RX1_DR_OFFSET 0




#define US915_MAX_RX1_DR_OFFSET 3




#define US915_MIN_TX_POWER TX_POWER_14




#define US915_MAX_TX_POWER TX_POWER_0




#define US915_DEFAULT_TX_POWER TX_POWER_0




#define US915_DEFAULT_MAX_ERP 30.0f




#define US915_DUTY_CYCLE_ENABLED 0




#define US915_MAX_RX_WINDOW 3000




#define US915_RX_WND_2_FREQ 923300000




#define US915_RX_WND_2_DR DR_8




#define US915_DEFAULT_UPLINK_DWELL_TIME 0







#define US915_BEACON_CHANNEL_FREQ 923300000




#define US915_BEACON_CHANNEL_STEPWIDTH 600000




#define US915_PING_SLOT_CHANNEL_FREQ 923300000




#define US915_BEACON_NB_CHANNELS 8




#define US915_BEACON_SIZE 23




#define US915_RFU1_SIZE 5




#define US915_RFU2_SIZE 3




#define US915_BEACON_CHANNEL_DR DR_8




#define US915_BEACON_CHANNEL_BW 2




#define US915_PING_SLOT_CHANNEL_DR DR_8




#define US915_MAX_NB_BANDS 1





#define US915_BAND0 { 1, US915_MAX_TX_POWER, 0, 0, 0, 0, 0 }




#define US915_FIRST_RX1_CHANNEL ( (uint32_t) 923300000 )




#define US915_LAST_RX1_CHANNEL ( (uint32_t) 927500000 )




#define US915_STEPWIDTH_RX1_CHANNEL ( (uint32_t) 600000 )




static const uint8_t DataratesUS915[] = { 10, 9, 8, 7, 8, 0, 0, 0, 12, 11, 10, 9, 8, 7, 0, 0 };




static const uint32_t BandwidthsUS915[] = { 125000, 125000, 125000, 125000, 500000, 0, 0, 0, 500000, 500000, 500000, 500000, 500000, 500000, 0, 0 };




static const int8_t DatarateOffsetsUS915[5][4] =
{
    { 10, 9 , 8 , 8 },
    { 11, 10, 9 , 8 },
    { 12, 11, 10, 9 },
    { 13, 12, 11, 10 },
    { 13, 13, 12, 11 },
};




static const uint8_t MaxPayloadOfDatarateUS915[] = { 11, 53, 125, 242, 242, 0, 0, 0, 53, 129, 242, 242, 242, 242, 0, 0 };
# 245 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
PhyParam_t RegionUS915GetPhyParam( GetPhyParams_t* getPhy );






void RegionUS915SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionUS915InitDefaults( InitDefaultsParams_t* params );
# 270 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"

# 270 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 3 4
_Bool 
# 270 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
    RegionUS915Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionUS915ApplyCFList( ApplyCFListParams_t* applyCFList );
# 287 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"

# 287 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 3 4
_Bool 
# 287 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
    RegionUS915ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 302 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
void RegionUS915ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 313 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"

# 313 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 3 4
_Bool 
# 313 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
    RegionUS915RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 326 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"

# 326 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 3 4
_Bool 
# 326 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
    RegionUS915TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 335 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
uint8_t RegionUS915LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 344 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
uint8_t RegionUS915RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 353 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
int8_t RegionUS915NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 364 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
int8_t RegionUS915TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 373 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
int8_t RegionUS915DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 384 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
int8_t RegionUS915AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 398 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
LoRaMacStatus_t RegionUS915NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 407 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
LoRaMacStatus_t RegionUS915ChannelAdd( ChannelAddParams_t* channelAdd );
# 416 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"

# 416 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h" 3 4
_Bool 
# 416 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
    RegionUS915ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionUS915SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 436 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionUS915.h"
uint8_t RegionUS915ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






void RegionUS915RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 444 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define US915_CASE case LORAMAC_REGION_US915:
#define US915_IS_ACTIVE() US915_CASE { return true; }
#define US915_GET_PHY_PARAM() US915_CASE { return RegionUS915GetPhyParam( getPhy ); }
#define US915_SET_BAND_TX_DONE() US915_CASE { RegionUS915SetBandTxDone( txDone ); break; }
#define US915_INIT_DEFAULTS() US915_CASE { RegionUS915InitDefaults( params ); break; }
#define US915_VERIFY() US915_CASE { return RegionUS915Verify( verify, phyAttribute ); }
#define US915_APPLY_CF_LIST() US915_CASE { RegionUS915ApplyCFList( applyCFList ); break; }
#define US915_CHAN_MASK_SET() US915_CASE { return RegionUS915ChanMaskSet( chanMaskSet ); }
#define US915_COMPUTE_RX_WINDOW_PARAMETERS() US915_CASE { RegionUS915ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define US915_RX_CONFIG() US915_CASE { return RegionUS915RxConfig( rxConfig, datarate ); }
#define US915_TX_CONFIG() US915_CASE { return RegionUS915TxConfig( txConfig, txPower, txTimeOnAir ); }
#define US915_LINK_ADR_REQ() US915_CASE { return RegionUS915LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define US915_RX_PARAM_SETUP_REQ() US915_CASE { return RegionUS915RxParamSetupReq( rxParamSetupReq ); }
#define US915_NEW_CHANNEL_REQ() US915_CASE { return RegionUS915NewChannelReq( newChannelReq ); }
#define US915_TX_PARAM_SETUP_REQ() US915_CASE { return RegionUS915TxParamSetupReq( txParamSetupReq ); }
#define US915_DL_CHANNEL_REQ() US915_CASE { return RegionUS915DlChannelReq( dlChannelReq ); }
#define US915_ALTERNATE_DR() US915_CASE { return RegionUS915AlternateDr( currentDr, type ); }
#define US915_NEXT_CHANNEL() US915_CASE { return RegionUS915NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define US915_CHANNEL_ADD() US915_CASE { return RegionUS915ChannelAdd( channelAdd ); }
#define US915_CHANNEL_REMOVE() US915_CASE { return RegionUS915ChannelsRemove( channelRemove ); }
#define US915_SET_CONTINUOUS_WAVE() US915_CASE { RegionUS915SetContinuousWave( continuousWave ); break; }
#define US915_APPLY_DR_OFFSET() US915_CASE { return RegionUS915ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define US915_RX_BEACON_SETUP() US915_CASE { RegionUS915RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 494 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
# 1 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 1
# 36 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
#define __REGION_RU864_H__ 
# 48 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
#define RU864_MAX_NB_CHANNELS 8




#define RU864_NUMB_DEFAULT_CHANNELS 2




#define RU864_NUMB_CHANNELS_CF_LIST 5




#define RU864_TX_MIN_DATARATE DR_0




#define RU864_TX_MAX_DATARATE DR_7




#define RU864_RX_MIN_DATARATE DR_0




#define RU864_RX_MAX_DATARATE DR_7




#define RU864_DEFAULT_DATARATE DR_0




#define RU864_MIN_RX1_DR_OFFSET 0




#define RU864_MAX_RX1_DR_OFFSET 5




#define RU864_MIN_TX_POWER TX_POWER_7




#define RU864_MAX_TX_POWER TX_POWER_0




#define RU864_DEFAULT_TX_POWER TX_POWER_0




#define RU864_DEFAULT_MAX_EIRP 16.0f




#define RU864_DEFAULT_ANTENNA_GAIN 2.15f




#define RU864_DUTY_CYCLE_ENABLED 1




#define RU864_MAX_RX_WINDOW 3000
# 137 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
#define RU864_RX_WND_2_FREQ 869100000




#define RU864_RX_WND_2_DR DR_0




#define RU864_DEFAULT_UPLINK_DWELL_TIME 0







#define RU864_BEACON_CHANNEL_FREQ 869100000




#define RU864_PING_SLOT_CHANNEL_FREQ 868900000




#define RU864_BEACON_SIZE 17




#define RU864_RFU1_SIZE 2




#define RU864_RFU2_SIZE 0




#define RU864_BEACON_CHANNEL_DR DR_3




#define RU864_BEACON_CHANNEL_BW 0




#define RU864_PING_SLOT_CHANNEL_DR DR_3




#define RU864_MAX_NB_BANDS 1





#define RU864_BAND0 { 100 , RU864_MAX_TX_POWER, 0, 0, 0, 0, 0 }





#define RU864_LC1 { 868900000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define RU864_LC2 { 869100000, 0, { ( ( DR_5 << 4 ) | DR_0 ) }, 0 }





#define RU864_JOIN_CHANNELS ( uint16_t )( LC( 1 ) | LC( 2 ) )




static const uint8_t DataratesRU864[] = { 12, 11, 10, 9, 8, 7, 7, 50 };




static const uint32_t BandwidthsRU864[] = { 125000, 125000, 125000, 125000, 125000, 125000, 250000, 0 };




static const uint8_t MaxPayloadOfDatarateRU864[] = { 51, 51, 51, 115, 242, 242, 242, 242 };
# 243 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
PhyParam_t RegionRU864GetPhyParam( GetPhyParams_t* getPhy );






void RegionRU864SetBandTxDone( SetBandTxDoneParams_t* txDone );






void RegionRU864InitDefaults( InitDefaultsParams_t* params );
# 268 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"

# 268 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 3 4
_Bool 
# 268 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
    RegionRU864Verify( VerifyParams_t* verify, PhyAttribute_t phyAttribute );







void RegionRU864ApplyCFList( ApplyCFListParams_t* applyCFList );
# 285 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"

# 285 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 3 4
_Bool 
# 285 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
    RegionRU864ChanMaskSet( ChanMaskSetParams_t* chanMaskSet );
# 300 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
void RegionRU864ComputeRxWindowParameters( int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams );
# 311 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"

# 311 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 3 4
_Bool 
# 311 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
    RegionRU864RxConfig( RxConfigParams_t* rxConfig, int8_t* datarate );
# 324 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"

# 324 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 3 4
_Bool 
# 324 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
    RegionRU864TxConfig( TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir );
# 333 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
uint8_t RegionRU864LinkAdrReq( LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed );
# 342 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
uint8_t RegionRU864RxParamSetupReq( RxParamSetupReqParams_t* rxParamSetupReq );
# 351 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
int8_t RegionRU864NewChannelReq( NewChannelReqParams_t* newChannelReq );
# 362 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
int8_t RegionRU864TxParamSetupReq( TxParamSetupReqParams_t* txParamSetupReq );
# 371 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
int8_t RegionRU864DlChannelReq( DlChannelReqParams_t* dlChannelReq );
# 380 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
int8_t RegionRU864AlternateDr( int8_t currentDr, AlternateDrType_t type );
# 394 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
LoRaMacStatus_t RegionRU864NextChannel( NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff );
# 403 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
LoRaMacStatus_t RegionRU864ChannelAdd( ChannelAddParams_t* channelAdd );
# 412 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"

# 412 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h" 3 4
_Bool 
# 412 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
    RegionRU864ChannelsRemove( ChannelRemoveParams_t* channelRemove );






void RegionRU864SetContinuousWave( ContinuousWaveParams_t* continuousWave );
# 432 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/RegionRU864.h"
uint8_t RegionRU864ApplyDrOffset( uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset );






void RegionRU864RxBeaconSetup( RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr );
# 495 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 2
#define RU864_CASE case LORAMAC_REGION_RU864:
#define RU864_IS_ACTIVE() RU864_CASE { return true; }
#define RU864_GET_PHY_PARAM() RU864_CASE { return RegionRU864GetPhyParam( getPhy ); }
#define RU864_SET_BAND_TX_DONE() RU864_CASE { RegionRU864SetBandTxDone( txDone ); break; }
#define RU864_INIT_DEFAULTS() RU864_CASE { RegionRU864InitDefaults( params ); break; }
#define RU864_VERIFY() RU864_CASE { return RegionRU864Verify( verify, phyAttribute ); }
#define RU864_APPLY_CF_LIST() RU864_CASE { RegionRU864ApplyCFList( applyCFList ); break; }
#define RU864_CHAN_MASK_SET() RU864_CASE { return RegionRU864ChanMaskSet( chanMaskSet ); }
#define RU864_COMPUTE_RX_WINDOW_PARAMETERS() RU864_CASE { RegionRU864ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; }
#define RU864_RX_CONFIG() RU864_CASE { return RegionRU864RxConfig( rxConfig, datarate ); }
#define RU864_TX_CONFIG() RU864_CASE { return RegionRU864TxConfig( txConfig, txPower, txTimeOnAir ); }
#define RU864_LINK_ADR_REQ() RU864_CASE { return RegionRU864LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); }
#define RU864_RX_PARAM_SETUP_REQ() RU864_CASE { return RegionRU864RxParamSetupReq( rxParamSetupReq ); }
#define RU864_NEW_CHANNEL_REQ() RU864_CASE { return RegionRU864NewChannelReq( newChannelReq ); }
#define RU864_TX_PARAM_SETUP_REQ() RU864_CASE { return RegionRU864TxParamSetupReq( txParamSetupReq ); }
#define RU864_DL_CHANNEL_REQ() RU864_CASE { return RegionRU864DlChannelReq( dlChannelReq ); }
#define RU864_ALTERNATE_DR() RU864_CASE { return RegionRU864AlternateDr( currentDr, type ); }
#define RU864_NEXT_CHANNEL() RU864_CASE { return RegionRU864NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); }
#define RU864_CHANNEL_ADD() RU864_CASE { return RegionRU864ChannelAdd( channelAdd ); }
#define RU864_CHANNEL_REMOVE() RU864_CASE { return RegionRU864ChannelsRemove( channelRemove ); }
#define RU864_SET_CONTINUOUS_WAVE() RU864_CASE { RegionRU864SetContinuousWave( continuousWave ); break; }
#define RU864_APPLY_DR_OFFSET() RU864_CASE { return RegionRU864ApplyDrOffset( downlinkDwellTime, dr, drOffset ); }
#define RU864_RX_BEACON_SETUP() RU864_CASE { RegionRU864RxBeaconSetup( rxBeaconSetup, outDr ); break; }
# 544 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"

# 544 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 544 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionIsActive( LoRaMacRegion_t region )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return 
# 548 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 548 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_AU915: { return 
# 549 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 549 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_CN470: { return 
# 550 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 550 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_CN779: { return 
# 551 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 551 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_EU433: { return 
# 552 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 552 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_EU868: { return 
# 553 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 553 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_KR920: { return 
# 554 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 554 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_IN865: { return 
# 555 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 555 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_US915: { return 
# 556 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 556 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        case LORAMAC_REGION_RU864: { return 
# 557 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
       1
# 557 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
       ; };
        default:
        {
            return 
# 560 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 560 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}

PhyParam_t RegionGetPhyParam( LoRaMacRegion_t region, GetPhyParams_t* getPhy )
{
    PhyParam_t phyParam = { 0 };
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923GetPhyParam( getPhy ); };
        case LORAMAC_REGION_AU915: { return RegionAU915GetPhyParam( getPhy ); };
        case LORAMAC_REGION_CN470: { return RegionCN470GetPhyParam( getPhy ); };
        case LORAMAC_REGION_CN779: { return RegionCN779GetPhyParam( getPhy ); };
        case LORAMAC_REGION_EU433: { return RegionEU433GetPhyParam( getPhy ); };
        case LORAMAC_REGION_EU868: { return RegionEU868GetPhyParam( getPhy ); };
        case LORAMAC_REGION_KR920: { return RegionKR920GetPhyParam( getPhy ); };
        case LORAMAC_REGION_IN865: { return RegionIN865GetPhyParam( getPhy ); };
        case LORAMAC_REGION_US915: { return RegionUS915GetPhyParam( getPhy ); };
        case LORAMAC_REGION_RU864: { return RegionRU864GetPhyParam( getPhy ); };
        default:
        {
            return phyParam;
        }
    }
}

void RegionSetBandTxDone( LoRaMacRegion_t region, SetBandTxDoneParams_t* txDone )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_US915: { RegionUS915SetBandTxDone( txDone ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864SetBandTxDone( txDone ); break; };
        default:
        {
            return;
        }
    }
}

void RegionInitDefaults( LoRaMacRegion_t region, InitDefaultsParams_t* params )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923InitDefaults( params ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915InitDefaults( params ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470InitDefaults( params ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779InitDefaults( params ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433InitDefaults( params ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868InitDefaults( params ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920InitDefaults( params ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865InitDefaults( params ); break; };
        case LORAMAC_REGION_US915: { RegionUS915InitDefaults( params ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864InitDefaults( params ); break; };
        default:
        {
            break;
        }
    }
}


# 629 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 629 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionVerify( LoRaMacRegion_t region, VerifyParams_t* verify, PhyAttribute_t phyAttribute )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_AU915: { return RegionAU915Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_CN470: { return RegionCN470Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_CN779: { return RegionCN779Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_EU433: { return RegionEU433Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_EU868: { return RegionEU868Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_KR920: { return RegionKR920Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_IN865: { return RegionIN865Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_US915: { return RegionUS915Verify( verify, phyAttribute ); };
        case LORAMAC_REGION_RU864: { return RegionRU864Verify( verify, phyAttribute ); };
        default:
        {
            return 
# 645 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 645 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}

void RegionApplyCFList( LoRaMacRegion_t region, ApplyCFListParams_t* applyCFList )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_US915: { RegionUS915ApplyCFList( applyCFList ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864ApplyCFList( applyCFList ); break; };
        default:
        {
            break;
        }
    }
}


# 671 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 671 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionChanMaskSet( LoRaMacRegion_t region, ChanMaskSetParams_t* chanMaskSet )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_AU915: { return RegionAU915ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_CN470: { return RegionCN470ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_CN779: { return RegionCN779ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_EU433: { return RegionEU433ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_EU868: { return RegionEU868ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_KR920: { return RegionKR920ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_IN865: { return RegionIN865ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_US915: { return RegionUS915ChanMaskSet( chanMaskSet ); };
        case LORAMAC_REGION_RU864: { return RegionRU864ChanMaskSet( chanMaskSet ); };
        default:
        {
            return 
# 687 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 687 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}

void RegionComputeRxWindowParameters( LoRaMacRegion_t region, int8_t datarate, uint8_t minRxSymbols, uint32_t rxError, RxConfigParams_t *rxConfigParams )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_US915: { RegionUS915ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864ComputeRxWindowParameters( datarate, minRxSymbols, rxError, rxConfigParams ); break; };
        default:
        {
            break;
        }
    }
}


# 713 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 713 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionRxConfig( LoRaMacRegion_t region, RxConfigParams_t* rxConfig, int8_t* datarate )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_AU915: { return RegionAU915RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_CN470: { return RegionCN470RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_CN779: { return RegionCN779RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_EU433: { return RegionEU433RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_EU868: { return RegionEU868RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_KR920: { return RegionKR920RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_IN865: { return RegionIN865RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_US915: { return RegionUS915RxConfig( rxConfig, datarate ); };
        case LORAMAC_REGION_RU864: { return RegionRU864RxConfig( rxConfig, datarate ); };
        default:
        {
            return 
# 729 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 729 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}


# 734 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 734 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionTxConfig( LoRaMacRegion_t region, TxConfigParams_t* txConfig, int8_t* txPower, UTIL_TIMER_Time_t* txTimeOnAir )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_AU915: { return RegionAU915TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_CN470: { return RegionCN470TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_CN779: { return RegionCN779TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_EU433: { return RegionEU433TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_EU868: { return RegionEU868TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_KR920: { return RegionKR920TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_IN865: { return RegionIN865TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_US915: { return RegionUS915TxConfig( txConfig, txPower, txTimeOnAir ); };
        case LORAMAC_REGION_RU864: { return RegionRU864TxConfig( txConfig, txPower, txTimeOnAir ); };
        default:
        {
            return 
# 750 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 750 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}

uint8_t RegionLinkAdrReq( LoRaMacRegion_t region, LinkAdrReqParams_t* linkAdrReq, int8_t* drOut, int8_t* txPowOut, uint8_t* nbRepOut, uint8_t* nbBytesParsed )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_AU915: { return RegionAU915LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_CN470: { return RegionCN470LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_CN779: { return RegionCN779LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_EU433: { return RegionEU433LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_EU868: { return RegionEU868LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_KR920: { return RegionKR920LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_IN865: { return RegionIN865LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_US915: { return RegionUS915LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        case LORAMAC_REGION_RU864: { return RegionRU864LinkAdrReq( linkAdrReq, drOut, txPowOut, nbRepOut, nbBytesParsed ); };
        default:
        {
            return 0;
        }
    }
}

uint8_t RegionRxParamSetupReq( LoRaMacRegion_t region, RxParamSetupReqParams_t* rxParamSetupReq )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_AU915: { return RegionAU915RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_CN470: { return RegionCN470RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_CN779: { return RegionCN779RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_EU433: { return RegionEU433RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_EU868: { return RegionEU868RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_KR920: { return RegionKR920RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_IN865: { return RegionIN865RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_US915: { return RegionUS915RxParamSetupReq( rxParamSetupReq ); };
        case LORAMAC_REGION_RU864: { return RegionRU864RxParamSetupReq( rxParamSetupReq ); };
        default:
        {
            return 0;
        }
    }
}

int8_t RegionNewChannelReq( LoRaMacRegion_t region, NewChannelReqParams_t* newChannelReq )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_AU915: { return RegionAU915NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_CN470: { return RegionCN470NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_CN779: { return RegionCN779NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_EU433: { return RegionEU433NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_EU868: { return RegionEU868NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_KR920: { return RegionKR920NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_IN865: { return RegionIN865NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_US915: { return RegionUS915NewChannelReq( newChannelReq ); };
        case LORAMAC_REGION_RU864: { return RegionRU864NewChannelReq( newChannelReq ); };
        default:
        {
            return 0;
        }
    }
}

int8_t RegionTxParamSetupReq( LoRaMacRegion_t region, TxParamSetupReqParams_t* txParamSetupReq )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_AU915: { return RegionAU915TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_CN470: { return RegionCN470TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_CN779: { return RegionCN779TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_EU433: { return RegionEU433TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_EU868: { return RegionEU868TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_KR920: { return RegionKR920TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_IN865: { return RegionIN865TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_US915: { return RegionUS915TxParamSetupReq( txParamSetupReq ); };
        case LORAMAC_REGION_RU864: { return RegionRU864TxParamSetupReq( txParamSetupReq ); };
        default:
        {
            return 0;
        }
    }
}

int8_t RegionDlChannelReq( LoRaMacRegion_t region, DlChannelReqParams_t* dlChannelReq )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_AU915: { return RegionAU915DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_CN470: { return RegionCN470DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_CN779: { return RegionCN779DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_EU433: { return RegionEU433DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_EU868: { return RegionEU868DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_KR920: { return RegionKR920DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_IN865: { return RegionIN865DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_US915: { return RegionUS915DlChannelReq( dlChannelReq ); };
        case LORAMAC_REGION_RU864: { return RegionRU864DlChannelReq( dlChannelReq ); };
        default:
        {
            return 0;
        }
    }
}

int8_t RegionAlternateDr( LoRaMacRegion_t region, int8_t currentDr, AlternateDrType_t type )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_AU915: { return RegionAU915AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_CN470: { return RegionCN470AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_CN779: { return RegionCN779AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_EU433: { return RegionEU433AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_EU868: { return RegionEU868AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_KR920: { return RegionKR920AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_IN865: { return RegionIN865AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_US915: { return RegionUS915AlternateDr( currentDr, type ); };
        case LORAMAC_REGION_RU864: { return RegionRU864AlternateDr( currentDr, type ); };
        default:
        {
            return 0;
        }
    }
}

LoRaMacStatus_t RegionNextChannel( LoRaMacRegion_t region, NextChanParams_t* nextChanParams, uint8_t* channel, UTIL_TIMER_Time_t* time, UTIL_TIMER_Time_t* aggregatedTimeOff )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_AU915: { return RegionAU915NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_CN470: { return RegionCN470NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_CN779: { return RegionCN779NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_EU433: { return RegionEU433NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_EU868: { return RegionEU868NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_KR920: { return RegionKR920NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_IN865: { return RegionIN865NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_US915: { return RegionUS915NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        case LORAMAC_REGION_RU864: { return RegionRU864NextChannel( nextChanParams, channel, time, aggregatedTimeOff ); };
        default:
        {
            return LORAMAC_STATUS_REGION_NOT_SUPPORTED;
        }
    }
}

LoRaMacStatus_t RegionChannelAdd( LoRaMacRegion_t region, ChannelAddParams_t* channelAdd )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_AU915: { return RegionAU915ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_CN470: { return RegionCN470ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_CN779: { return RegionCN779ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_EU433: { return RegionEU433ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_EU868: { return RegionEU868ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_KR920: { return RegionKR920ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_IN865: { return RegionIN865ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_US915: { return RegionUS915ChannelAdd( channelAdd ); };
        case LORAMAC_REGION_RU864: { return RegionRU864ChannelAdd( channelAdd ); };
        default:
        {
            return LORAMAC_STATUS_PARAMETER_INVALID;
        }
    }
}


# 923 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
_Bool 
# 923 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
    RegionChannelsRemove( LoRaMacRegion_t region, ChannelRemoveParams_t* channelRemove )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_AU915: { return RegionAU915ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_CN470: { return RegionCN470ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_CN779: { return RegionCN779ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_EU433: { return RegionEU433ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_EU868: { return RegionEU868ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_KR920: { return RegionKR920ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_IN865: { return RegionIN865ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_US915: { return RegionUS915ChannelsRemove( channelRemove ); };
        case LORAMAC_REGION_RU864: { return RegionRU864ChannelsRemove( channelRemove ); };
        default:
        {
            return 
# 939 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c" 3 4
                  0
# 939 "/home/eddieho/tmp/phase2_release/rui-v3/external/lora/LoRaMac-node-4.4.7/src/mac/region/Region.c"
                       ;
        }
    }
}

void RegionSetContinuousWave( LoRaMacRegion_t region, ContinuousWaveParams_t* continuousWave )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_US915: { RegionUS915SetContinuousWave( continuousWave ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864SetContinuousWave( continuousWave ); break; };
        default:
        {
            break;
        }
    }
}

uint8_t RegionApplyDrOffset( LoRaMacRegion_t region, uint8_t downlinkDwellTime, int8_t dr, int8_t drOffset )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { return RegionAS923ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_AU915: { return RegionAU915ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_CN470: { return RegionCN470ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_CN779: { return RegionCN779ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_EU433: { return RegionEU433ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_EU868: { return RegionEU868ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_KR920: { return RegionKR920ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_IN865: { return RegionIN865ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_US915: { return RegionUS915ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        case LORAMAC_REGION_RU864: { return RegionRU864ApplyDrOffset( downlinkDwellTime, dr, drOffset ); };
        default:
        {
            return dr;
        }
    }
}

void RegionRxBeaconSetup( LoRaMacRegion_t region, RxBeaconSetup_t* rxBeaconSetup, uint8_t* outDr )
{
    switch( region )
    {
        case LORAMAC_REGION_AS923: { RegionAS923RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_AU915: { RegionAU915RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_CN470: { RegionCN470RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_CN779: { RegionCN779RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_EU433: { RegionEU433RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_EU868: { RegionEU868RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_KR920: { RegionKR920RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_IN865: { RegionIN865RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_US915: { RegionUS915RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        case LORAMAC_REGION_RU864: { RegionRU864RxBeaconSetup( rxBeaconSetup, outDr ); break; };
        default:
        {
            break;
        }
    }
}

Version_t RegionGetVersion( void )
{
    Version_t version;

    version.Value = 0x00010003;

    return version;
}

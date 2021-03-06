#define TC_LINKKEY_JOIN
#define NV_INIT
#define NV_RESTORE
// to make TL work, need patch this macroses in SDK
// #define TOUCHLINK_KEY_INDEX TOUCHLINK_KEY_INDEX_MASTER
// #define TOUCHLINK_INTERNAL_ENDPOINT 42

#define TP2_LEGACY_ZC
// patch sdk
// #define ZDSECMGR_TC_ATTEMPT_DEFAULT_KEY TRUE

#define NWK_AUTO_POLL
#define MULTICAST_ENABLED FALSE

#define ZCL_READ
#define ZCL_WRITE
#define ZCL_BASIC
#define ZCL_IDENTIFY
#define ZCL_ON_OFF
#define ZCL_LEVEL_CTRL
#define ZCL_REPORTING_DEVICE

// #define FREEPAD_ENABLE_TL
#ifdef FREEPAD_ENABLE_TL
#define INTER_PAN
#define BDB_TL_INITIATOR
#endif


#define DISABLE_GREENPOWER_BASIC_PROXY
#define BDB_FINDING_BINDING_CAPABILITY_ENABLED 1
#define BDB_REPORTING TRUE

#define ISR_KEYINTERRUPT
#define HAL_BUZZER FALSE

#define HAL_LED TRUE
#define HAL_LCD FALSE
#define BLINK_LEDS TRUE

// one of this boards
// #define HAL_BOARD_FREEPAD_20
// #define HAL_BOARD_FREEPAD_12
// #define HAL_BOARD_FREEPAD_8
// #define HAL_BOARD_FREEPAD_3
// #define HAL_BOARD_FREEPAD_2
// #define HAL_BOARD_FREEPAD_1
// #define HAL_BOARD_CHDTECH_DEV

#if !defined(HAL_BOARD_FREEPAD_20) && !defined(HAL_BOARD_FREEPAD_12) && !defined(HAL_BOARD_FREEPAD_8) && !defined(HAL_BOARD_FREEPAD_3) &&  \
    !defined(HAL_BOARD_FREEPAD_2) && !defined(HAL_BOARD_FREEPAD_1) && !defined(HAL_BOARD_CHDTECH_DEV)
#error "Board type must be defined"
#endif

#ifdef HAL_BOARD_FREEPAD_20
#define FREEPAD_BUTTONS_COUNT 20
#elif defined(HAL_BOARD_FREEPAD_12)
#define FREEPAD_BUTTONS_COUNT 12
#elif defined(HAL_BOARD_FREEPAD_8)
#define FREEPAD_BUTTONS_COUNT 8
#elif defined(HAL_BOARD_FREEPAD_3)
#define FREEPAD_BUTTONS_COUNT 3
#elif defined(HAL_BOARD_FREEPAD_2)
#define FREEPAD_BUTTONS_COUNT 2
#elif defined(HAL_BOARD_FREEPAD_1)
#define FREEPAD_BUTTONS_COUNT 1
#elif defined(HAL_BOARD_CHDTECH_DEV)
#define FREEPAD_BUTTONS_COUNT 2
#endif

#ifdef NWK_MAX_BINDING_ENTRIES
#undef NWK_MAX_BINDING_ENTRIES
#endif
#define NWK_MAX_BINDING_ENTRIES MAX(10, ((2 * FREEPAD_BUTTONS_COUNT)))

#undef APS_MAX_GROUPS
#define APS_MAX_GROUPS 1

#if defined(HAL_BOARD_FREEPAD_20) || defined(HAL_BOARD_FREEPAD_12) || defined(HAL_BOARD_FREEPAD_8) || defined(HAL_BOARD_FREEPAD_3) ||      \
    defined(HAL_BOARD_FREEPAD_2) || defined(HAL_BOARD_FREEPAD_1)
#define POWER_SAVING
#endif


#if defined(HAL_BOARD_CHDTECH_DEV)
// #define DO_DEBUG
#endif

#ifdef DO_DEBUG
#define HAL_UART TRUE
#define HAL_UART_ISR 2
#define HAL_UART_DMA 1
#define INT_HEAP_LEN (2688-0x128 - 0xCD)
#endif

#ifndef INT_HEAP_LEN
#define INT_HEAP_LEN 2688
#endif

#include "hal_board_cfg.h"

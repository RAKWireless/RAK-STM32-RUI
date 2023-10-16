LIB_SRC := rui_inner_main.c
LIB_SRC += subghz.c
LIB_SRC += board_basic.c
LIB_SRC += timer_if.c
LIB_SRC += PeripheralPins.c
LIB_SRC += pinmap.c
LIB_SRC += PortNames.c
LIB_SRC += radio_board_if.c
ifneq ($(strip $(SUPPORT_LORA)),0)
LIB_SRC += board.c
LIB_SRC += rtc-board.c
LIB_SRC += delay-board.c
endif
ifneq ($(strip $(SUPPORT_LORA_P2P)),0)
LIB_SRC += board.c
LIB_SRC += rtc-board.c
LIB_SRC += delay-board.c
endif

LIB_ASRC :=
LIBRARY_NAME := rak3172_sip
LOCAL_CFLAGS :=
LOCAL_AFLAGS :=
LOCAL_INC +=

RELEASE_SRC := 2
$(eval $(call build-lib,$(LIBRARY_NAME),$(LIB_SRC),$(LIB_ASRC),$(LOCAL_CFLAGS),$(LOCAL_INC),$(LOCAL_AFLAGS),$(MYDIR)))

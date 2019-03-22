LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#添加log的函数库
LOCAL_LDLIBS    := -lm -llog
LOCAL_MODULE    := Hello
LOCAL_SRC_FILES := Hello.c
include $(BUILD_SHARED_LIBRARY)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Ito ang magiging pangalan ng file mo: libRagdollPort.so
LOCAL_MODULE    := RagdollPort

# IMPORTANTE: Isama ang main.cpp at ang mga AML helper files
# Kung sa GitHub ka nag-build, kailangan ang mod/logger.cpp at mod/config.cpp
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp

# Settings para sa C++17 at floating point support
LOCAL_CFLAGS    += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17

# Ituro kung nasaan ang folder ng mga .h files
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

# Linker flags para sa Android logging
LOCAL_LDLIBS    += -llog

include $(BUILD_SHARED_LIBRARY)

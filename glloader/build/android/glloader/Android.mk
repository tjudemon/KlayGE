include $(CLEAR_VARS)

LOCAL_MODULE := glloader
LOCAL_SRC_FILES := $(GLLOADER_PATH)/lib/android_$(TARGET_ARCH_ABI)/libglloader.a
LOCAL_EXPORT_C_INCLUDES := $(GLLOADER_PATH)/include

include $(PREBUILT_STATIC_LIBRARY)

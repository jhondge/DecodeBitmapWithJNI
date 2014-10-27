LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)


LOCAL_MODULE    := libbitmap


BitmapUtilFileName = BitmapUtil.cpp

SOURCE_ROOT=./skia-build/android2.3-r1_4skiabuild


LOCAL_CFLAGS    := -Werror


SKIA_ROOT=$(SOURCE_ROOT)/skia-include

LOCAL_C_INCLUDES += \
		$(SOURCE_ROOT)/system-core-include \
		$(SOURCE_ROOT)/frameworks-base-include \
		$(SOURCE_ROOT)/frameworks-base-core-jni-android-graphics \
		$(SOURCE_ROOT)/frameworks-native-include \
		$(SKIA_ROOT)/core \
		$(SKIA_ROOT)/images \
		$(SKIA_ROOT)/config \
		$(SKIA_ROOT)/lazy \
		$(LOCAL_PATH)/include \

LOCAL_SRC_FILES := \
		$(BitmapUtilFileName) \

LOCAL_LDLIBS +=  -llog -ljnigraphics -L$(SOURCE_ROOT)/libs/$(TARGET_ARCH_ABI) -landroid_runtime -lskia

include $(BUILD_SHARED_LIBRARY)
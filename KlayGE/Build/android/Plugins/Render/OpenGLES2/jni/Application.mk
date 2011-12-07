NDK_MODULE_PATH := $(call my-dir)/../../../../../../../External/boost/android:$(call my-dir)/../../../../Core::$(call my-dir)/../../../../../../../glloader/build/android

APP_BUILD_SCRIPT := $(call my-dir)/Android.mk

APP_OPTIM := release

APP_PLATFORM 	:= android-9
APP_STL 		:= gnustl_static
APP_CPPFLAGS 	:= -fexceptions -frtti
APP_ABI 		:= armeabi armeabi-v7a
APP_MODULES     := KlayGE_RenderEngine_OpenGLES2_gcc

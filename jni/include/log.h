#ifndef _LOG_H
#define _LOG_H

#include <android/log.h>

#define DEBUG 1;
#define ANDROID_LOG_VERBOSE ANDROID_LOG_DEBUG
#define LOG_TAG "EIBitmapJNI"
#ifdef DEBUG
	#define LOGV(...) __android_log_print(ANDROID_LOG_SILENT, LOG_TAG, __VA_ARGS__)
	#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
	#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
	#define LOGV(...)
	#define LOGI(...)
	#define LOGE(...)
#endif

#endif

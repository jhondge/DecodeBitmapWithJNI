#include "log.h"

#include "jni.h"

#include "SkBitmap.h"

#include "SkTemplates.h"

#include "GraphicsJNI.h"

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jobject JNICALL Java_com_everimaging_bitmap_BitmapUtil_nativeDecodeFile(JNIEnv * env, jobject thiz, jstring jpath,
		jobject jconfig, jboolean jmutable) {
	if (jpath == NULL) {
		LOGE("createBitmapByFile path is null.");
		return 0;
	}
	if (jconfig == NULL) {
		LOGE("config is null.");
		return 0;
	}
	SkBitmap::Config prefConfig = GraphicsJNI::getNativeBitmapConfig(env,
			jconfig);
	char* path = (char*) env->GetStringUTFChars(jpath, NULL);
	SkBitmap* bitmap = new SkBitmap;
	SkImageDecoder::DecodeFile(path, bitmap, prefConfig,
			SkImageDecoder::kDecodePixels_Mode);

	return GraphicsJNI::createBitmap(env, bitmap, jmutable, NULL);
}


#ifdef __cplusplus
}
#endif


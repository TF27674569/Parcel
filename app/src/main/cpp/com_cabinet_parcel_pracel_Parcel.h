/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_cabinet_parcel_pracel_Parcel */

#ifndef _Included_com_cabinet_parcel_pracel_Parcel
#define _Included_com_cabinet_parcel_pracel_Parcel
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeCreate
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeCreate
  (JNIEnv *, jclass);

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeWriteInt
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeWriteInt
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeSetDataPosition
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeSetDataPosition
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeReadInt
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeReadInt
  (JNIEnv *, jclass, jlong);


JNIEXPORT void JNICALL
Java_com_cabinet_parcel_pracel_Parcel_nativeDestory(JNIEnv *env, jclass type, jlong mNativePtr);
#ifdef __cplusplus
}
#endif
#endif

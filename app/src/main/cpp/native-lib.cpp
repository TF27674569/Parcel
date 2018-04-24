#include <jni.h>
#include "com_cabinet_parcel_pracel_Parcel.h"
#include "parcel/Parcel.h"

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeCreate
 * Signature: ()J
 * 需要初始化c++层的 Parcel 对象
 */
JNIEXPORT jlong JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeCreate
        (JNIEnv *env, jclass jclazz) {
    // 创建一个c++对象
    Parcel * parcel = new Parcel();

    // 将c++对象转为jlong 返回给java层  reinterpret_cast c++强转符号
    return *reinterpret_cast<jlong *> (parcel);
}

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeWriteInt
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeWriteInt
        (JNIEnv *env, jclass jclazz, jlong native_ptr, jint value) {

    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    parcel->writeInt(value);
}

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeSetDataPosition
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeSetDataPosition
        (JNIEnv *env, jclass jclazz, jlong native_ptr, jint value) {
    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    parcel->setDataPosition(value);
}

/*
 * Class:     com_cabinet_parcel_pracel_Parcel
 * Method:    nativeReadInt
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeReadInt
        (JNIEnv *env, jclass jclazz, jlong native_ptr) {
    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    return parcel->readInt();
}


JNIEXPORT void JNICALL
Java_com_cabinet_parcel_pracel_Parcel_nativeDestory(JNIEnv *env, jclass type, jlong native_ptr) {

    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    // 释放掉内存
    delete parcel;
}
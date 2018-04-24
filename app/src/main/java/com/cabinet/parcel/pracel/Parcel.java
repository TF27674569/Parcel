package com.cabinet.parcel.pracel;

import android.os.Parcelable;

/**
 * Description :
 * <p/>
 * Created : TIAN FENG
 * Date : 2018/4/24
 * Email : 27674569@qq.com
 *
 * Version : 1.0
 */
public class Parcel {

    static {
        System.loadLibrary("native-lib");
    }

    /**
     * c++ 对象 Parcel 的共享内存单元的头指针
     */
    private long mNativePtr;

    public Parcel(){
        mNativePtr = nativeCreate();
    }

    /**
     * 写int对象
     */
    public final void writeInt(int val) {
        nativeWriteInt(mNativePtr, val);
    }

    /**
     * 设置指针位置 一般在读之前需要置为0
     */
    public final void setDataPosition(int pos) {
        nativeSetDataPosition(mNativePtr, pos);
    }

    /**
     * 读int
     */
    public final int readInt() {
        return nativeReadInt(mNativePtr);
    }

    /**
     * 销毁
     */
    public final void destory(){
        nativeDestory(mNativePtr);
    }

    /**
     * 创建c++对象 并且将c++地址返回
     */
    private static native long nativeCreate();


    /**
     * 向c++  共享内存中写入int值
     *
     * @param mNativePtr  共享内存的头指针
     * @param val 存入的值
     */
    private static native void nativeWriteInt(long mNativePtr, int val);


    /**
     *重置初始位置
     *
     * @param mNativePtr  共享内存的头指针
     * @param pos 初始位置
     */
    private static native void nativeSetDataPosition(long mNativePtr, int pos);

    /**
     * 读取int值
     */
    private static native int nativeReadInt(long mNativePtr);


    /**
     * 销毁
     */
    private static native void nativeDestory(long mNativePtr);
}

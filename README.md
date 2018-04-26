# parcel 序列化过程

## **一、java层Pacel对象构建**
```java
    private long mNativePtr;

    public Parcel(){
        mNativePtr = nativeCreate();
    }

```
```java

JNIEXPORT jlong JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeCreate
        (JNIEnv *env, jclass jclazz) {
    Parcel * parcel = new Parcel();
    return *reinterpret_cast<jlong *> (parcel);
}

```
&nbsp;　　1.成员变量mNativePtr，保存的是一个long值，这个值表示c++层Pacel对象的头指针  
&nbsp;　　2.navite函数中创建了一个c++的Parcel对象，并将parcel对象的头指针返回给java层

## **二、java层读写操作**
```java
    public final void writeInt(int val) {
        nativeWriteInt(mNativePtr, val);
    }
    
    public final int readInt() {
        return nativeReadInt(mNativePtr);
    }
```

```java
JNIEXPORT void JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeWriteInt
        (JNIEnv *env, jclass jclazz, jlong native_ptr, jint value) {

    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    parcel->writeInt(value);
}

JNIEXPORT jint JNICALL Java_com_cabinet_parcel_pracel_Parcel_nativeReadInt
        (JNIEnv *env, jclass jclazz, jlong native_ptr) {
    Parcel * parcel = reinterpret_cast<Parcel *> (native_ptr);
    return parcel->readInt();
}
```
&nbsp;　　1.java层所有读写操作都需要将c++的头指针传过去     
&nbsp;　　2.navite层的的读写过程是将java层传过去的long值转为c++的Parcel对象指针，然后操作Parcel对象



## **三、c++Pacel对象**
&nbsp;　　&nbsp;　　头文件
```java
class Parcel {

public:
    Parcel();
    ~Parcel();

    void writeInt(int value);

    void setDataPosition(int position);

    int readInt();

private:
    // 共享内存头指针
    char* m_CDataHeaderPos;

    // 指针需要移动的大小
    int m_IMoveData;
};
```
&nbsp;　　&nbsp;　　实现
```java
Parcel::Parcel() {
    // 给这个序列化对象申请一块内存区间
    m_CDataHeaderPos = (char *) malloc(MEIMERYSIZE);
    m_IMoveData = 0;
}

// 析构函数释放掉内存
Parcel::~Parcel() {
   free(m_CDataHeaderPos);
}

void Parcel::writeInt(int value) {
    *reinterpret_cast<int*>(m_CDataHeaderPos + m_IMoveData) = value;
    m_IMoveData+= sizeof(int);
}

void Parcel::setDataPosition(int position) {
    m_IMoveData = position;
}

int Parcel::readInt() {
    int value = *reinterpret_cast<int*>(m_CDataHeaderPos + m_IMoveData);
    m_IMoveData+= sizeof(int);
    return  value;
}
```
&nbsp;　　1.在初始化对象时，申请了一块char*内存用来存储数据类型  
&nbsp;　　2.在写入时，将指针所在位置存上对应类型的值   
&nbsp;　　3.写入数据类型后需要将下次写入时的为之记录一下m_IMoveData表示下一个存储对象需要移动的位置  
&nbsp;　　4.在读取是需要先将m_IMoveData位置置为0，根据read函数来判断移动的位置   

## **四、注意事项**
&nbsp;　　1.在序列化过程中，writeInt，writeString后读取操作必须是readInt，readString，否则会因为对象的长度不一样从而导致崩溃  
&nbsp;　　2.在writeString是与其它对象不一样c/c++中，String对象为char*，不能知道其长度，所以在写的时候   
&nbsp;　　需要先将string的长度写在前面，然后写string的内容，读取时先读到需要读取的长度后，再根据长度读相应的值  
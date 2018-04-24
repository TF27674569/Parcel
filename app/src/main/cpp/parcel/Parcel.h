//
// Created by Administrator on 2018/4/24.
//

#ifndef PARCEL_PRACEL_H
#define PARCEL_PRACEL_H

#define MEIMERYSIZE 1024

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


#endif //PARCEL_PRACEL_H

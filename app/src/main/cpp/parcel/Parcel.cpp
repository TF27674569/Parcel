//
// Created by Administrator on 2018/4/24.
//

#include <malloc.h>
#include "Parcel.h"


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

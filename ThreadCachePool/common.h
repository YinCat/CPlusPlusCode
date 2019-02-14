#ifndef _COMMON_H__
#define _COMMON_H__

#include <iostream>

//管理对象自由链表的长度
const size_t NLISTS = 128;

const size_t MAXBYTES = 64 * 1024 * 1024; //64K

class FreeList
{
private:
    void* _list;
};

class ClassSize
{
public:
    static inline size_t Roundup(size_t size)
    {

    }
};

#endif //!_COMMON_H__
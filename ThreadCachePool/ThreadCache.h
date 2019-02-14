#ifndef __THREAD_CACHE_H__
#define __THREAD_CACHE_H__

#include <iostream>
#include <assert.h>

#include "Common.h"

class ThreadCache
{
public:
    //需要多少字节
    void* Allocate(size_t size);

    //释放内存块的字节大小
    void Deallcate(void* ptr, size_t size);
private:
    FreeList _freelist[];
};


#endif //!__THREAD_CACHE_H__
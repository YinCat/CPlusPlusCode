#include "ThreadCache.h"

void* ThreadCache::Allocate(size_t size)
{
    assert(size < MAXBYTES);
    //对其取整

}
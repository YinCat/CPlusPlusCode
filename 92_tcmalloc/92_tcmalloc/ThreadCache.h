#ifndef __THREAD_CACHE_H__
#define __THREAD_CACHE_H__

#include <iostream>
#include "Common.h"

class ThreadCache
{
public:
	void* Allocate(size_t size);
	void Deallocate(void* ptr, size_t size);

	//从中心缓存获取对象
	void* FetchFromCentalCache(size_t index, size_t size);
private:
	FreeList _freelist[NLISTS];
};


#endif //!__THREAD_CACHE_H__

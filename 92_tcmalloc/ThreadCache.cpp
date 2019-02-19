#include "ThreadCache.h"
#include "CentralCache.h"

void* ThreadCache::FetchFromCentalCache(size_t index, size_t bytes)
{
	FreeList& freelist = _freelist[index];
	size_t num = 10;
	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->
		FetchRangeObj(start, end, num, bytes);

	if (fetchnum == 1)
	{
		return start;
	}
	freelist.PushRange(NEXT_OBJ(start), end, fetchnum);
	return start;
}

void* ThreadCache::Allocate(size_t size)
{
	assert(size < MAXBYTES);
	//对size对齐取整
	size = ClassSize::Roundup(size);
	size_t index = ClassSize::Index(size);

	FreeList& freelist = _freelist[index];
	if (freelist.Empty())
	{
		return freelist.Pop();
	}
	else
	{
		return FetchFromCentalCache(size, index);
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(size <= MAXBYTES);
	size_t index = ClassSize::Index(size);
	FreeList& freelist = _freelist[index];
	//释放回来就是挂上去
	freelist.Push(ptr);

	//ListTooLong
}
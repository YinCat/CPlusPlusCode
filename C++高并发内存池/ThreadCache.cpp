#include "ThreadCache.h"
#include "CentralCache.h"

void* ThreadCache::FetchFromCentralCache(size_t index, size_t byte)
{
	FreeList* freelist = &_freelist[index];
	size_t num = 10;
	void* start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, byte);
	if (fetchnum == 1)
		return start;

	freelist->PushRange(NEXT_OBJ(start), end, fetchnum-1);
	return start;
}

void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);

	// ¶ÔÆëÈ¡Õû
	size = ClassSize::Roundup(size);
	size_t index = ClassSize::Index(size);
	FreeList* freelist = &_freelist[index];
	if (!freelist->Empty())
	{
		return freelist->Pop();
	}
	else
	{
		return FetchFromCentralCache(index, size);
	}
}

void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(size <= MAXBYTES);
	size_t index = ClassSize::Index(size);
	FreeList& freelist = _freelist[index];
	freelist.Push(ptr);

	// ListTooLong();
}
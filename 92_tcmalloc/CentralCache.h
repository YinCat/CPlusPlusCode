#ifndef __CENTRAL_CACHE_H__
#define __CENTRAL_CACHE_H__

#include "Common.h"

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//从中心缓存获取一定数量的对象给thread cache
	size_t CentralCache::FetchRangeObj(void*& start, void*& end, 
		size_t n, size_t bytes);
	
	//将一定数量的对象释放到span跨度
	void CentralCache::ReleaseListToSpan(void* start, size_t byte_size);

	//中心缓存自由链表
	SpanList _freeList[NLISTS];
private:
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;

	static CentralCache _inst;
};


#endif //!__CENTRAL_CACHE_H__
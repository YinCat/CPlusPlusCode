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

	//�����Ļ����ȡһ�������Ķ����thread cache
	size_t CentralCache::FetchRangeObj(void*& start, void*& end, 
		size_t n, size_t bytes);
	
	//��һ�������Ķ����ͷŵ�span���
	void CentralCache::ReleaseListToSpan(void* start, size_t byte_size);

	//���Ļ�����������
	SpanList _freeList[NLISTS];
private:
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;

	static CentralCache _inst;
};


#endif //!__CENTRAL_CACHE_H__
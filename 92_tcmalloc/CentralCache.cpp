#include "CentralCache.h"


CentralCache CentralCache::_inst;

//�����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end,
	size_t n, size_t bytes)
{
	return 0;
}

void CentralCache::ReleaseListToSpan(void* start, size_t byte_size)
{

}
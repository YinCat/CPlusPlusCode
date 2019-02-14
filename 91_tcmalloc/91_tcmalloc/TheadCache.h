#ifndef __THREAD_CACHE_H__
#define __THREAD_CACHE_H__

#include <iostream>
#include <assert.h>

#include "Common.h"

class ThreadCache
{
public:
	//��Ҫ�����ֽ�
	void* Allocate(size_t size);

	//�ͷ��ڴ����ֽڴ�С
	void Deallcate(void* ptr, size_t size);

	//�����Ļ����ȡ�ڴ�
	void* FetchFromCentralCache(size_t index, size_t );
private:
	FreeList _freelist[];
};


#endif //!__THREAD_CACHE_H__
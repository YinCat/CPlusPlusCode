#pragma once

#include "Common.h"

class ThreadCache
{
public:
	void* Allocate(size_t size);
	void Deallocate(void* ptr, size_t size);

	// 从中心缓存获取对象
	void* FetchFromCentralCache(size_t index, size_t size);
private:
	FreeList _freelist[NLISTS];
	//int _tid;
	//ThreadCache* _next;
};

static _declspec(thread) ThreadCache* tls_threadcache = nullptr;
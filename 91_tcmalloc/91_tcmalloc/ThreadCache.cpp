#include "TheadCache.h"

void* ThreadCache::Allocate(size_t size)
{
	assert(size < MAXBYTES);
	//¶ÔÆëÈ¡Õû
	size = ClassSize::Roundup(size);
	size_t index = ClassSize::Index(size);

}
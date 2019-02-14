#ifndef _COMMON_H__
#define _COMMON_H__
#include <iostream>

//管理对象自由链表的长度
const size_t NLISTS = 128;

const size_t MAXBYTES = 64 * 1024 * 1024;//64K

static inline void*& NEXT_OBJ()
{
	
}

class FreeList
{
private:
	void* _list;
};

class ClassSize
{
public:
	static inline size_t Roundup(size_t size)
	{
		
	}

	static inline size_t _Roundup(size_t size, size_t)
	{

	}

	static inline size_t Index(size_t bytes)
	{
		assert(bytes < MAXBYTES);
		//
		static int group_array[4] = { 16, 56, 56, 112 };

	}
};

#endif //!_COMMON_H__
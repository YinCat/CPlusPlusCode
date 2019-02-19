#ifndef __COMMON_H__
#define __COMMON_H__

#include <assert.h>

//���������������ĳ���
const size_t NLISTS = 240;
const size_t MAXBYTES = 64 * 1024 * 1024;

static inline void*& NEXT_OBJ(void* obj)
{
	return *((void**)obj);
}

typedef size_t PageID;
struct Span
{
	PageID _id;	//ҳ��
	size_t npage;	//ҳ������

	Span* _next;
	void* _list = nullptr;	//��������
	size_t _usercount = 0;	//ʹ�ü���
};

class SpanList
{
private:
	Span* _head;
};

class FreeList
{
public:
	void PushRange(void* start, void* end, size_t num)
	{
		NEXT_OBJ(end) = _list;
		_list = start;
		_size += num;
	}

	bool Empty()
	{
		return _list == nullptr;
	}
	void* Pop()
	{
		void* obj = _list;
		//_list = *(void**)obj;
		_list = NEXT_OBJ(obj);
		--_size;
		return obj;
	}
	void Push(void* obj)
	{
		//ͷ�巨
		NEXT_OBJ(obj) = _list;
		_list = obj;
		++_size;
	}

private:
	void* _list = nullptr;
	size_t _size = 0;
	size_t _maxsize = 0;
};

//�������ӳ��
class ClassSize
{
	// ������12%���ҵ�����Ƭ�˷�
	// [1,128]				8byte���� freelist[0,16)
	// [129,1024]			16byte���� freelist[16,72)
	// [1025,8*1024]		128byte���� freelist[72,128)
	// [8*1024+1,64*1024]	512byte���� freelist[128,240)
public:
	static inline size_t _Roundup(size_t size, size_t align)
	{
		return (size + align - 1) & (~(align - 1));
	}

	static inline size_t Roundup(size_t size)
	{
		assert(size <= MAXBYTES);
		if (size <= 128)
		{
			return _Roundup(size, 8);
		}
		else if (size <= 1024)
		{
			return _Roundup(size, 16);
		}
		else if (size <= 8912)
		{
			return _Roundup(size, 128);
		}
		else if (size < 65536)
		{
			return _Roundup(size, 512);
		}
		else
		{
			return -1;
		}
	}

	static inline size_t _Index(size_t bytes, size_t align)
	{
		return ((bytes + (1 << align) - 1) >> align) - 1;
	}
	static inline size_t Index(size_t bytes)
	{
		assert(bytes < MAXBYTES);

		//ÿ�������ж��ٸ���������
		static int group_array[4] = { 16, 56, 56, 112 };
		if (bytes < 128)
		{
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024)
		{
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8192)
		{
			return _Index(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 65536)
		{
			return _Index(bytes - 8192, 9) + group_array[2]
				+ group_array[1] + group_array[0];
		}
		else
		{
			return -1;
		}

	}

};

#endif //!__COMMON_H__

#ifndef __OBJECT_POOL_H__
#define __OBJECT_POOL_H__

// 定长的对象池
template<class T>
class ObjectPool
{
protected:
	struct Block
	{
		char* _start = nullptr;
		size_t _bytesize = 0;
		size_t _byteleft = 0;
		Block* _next = nullptr;

		Block(size_t bytesize)
		{
			_start = (char*)malloc(bytesize);
			_bytesize = bytesize;
			_byteleft = bytesize;
			_next = nullptr;
		}

		~Block()
		{
			free(_start);
			_bytesize = _byteleft = 0;
			_next = nullptr;
		}
	};

	static size_t GetItemSize()
	{
		if (sizeof(T) > sizeof(T*))
			return sizeof(T);
		else
			return sizeof(T*);
	}

public:
	ObjectPool(size_t initnum = 8)
	{
		_head = _tail = new Block(initnum * GetItemSize());
	}

	T*& OBJ_NEXT(T* obj)
	{
		return *(T**)obj;
	}

	T* New()
	{
		T* obj = nullptr;
		if (_freelist != nullptr)
		{
			obj = _freelist;
			_freelist = OBJ_NEXT(_freelist);
		}
		else
		{
			if (_tail->_byteleft == 0)
			{
				Block* newblock = new Block(_tail->_bytesize * 2);
				_tail->_next = newblock;
				_tail = newblock;
			}

			obj = (T*)(_tail->_start + (_tail->_bytesize - _tail->_byteleft));
			_tail->_byteleft -= sizeof(T);
		}
		//new定位表达式,调用T的构造函数
		new(obj)T;
		return obj;
	}

	void Delete(T* ptr)
	{
		//TODO
		ptr->~T();
		if (_freelist == nullptr)
		{
			_freelist = ptr;
			OBJ_NEXT(ptr) = nullptr;
		}
		else
		{
			OBJ_NEXT(ptr) = _freelist;
			_freelist = ptr;
		}
	}

	void Destory()
	{
		Block* cur = _head;
		while (cur)
		{
			Block* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head = _tail = nullptr;
		_freelist = nullptr;
	}
protected:
	// 自由链表
	T* _freelist = nullptr;

	// 块管理
	Block* _head = nullptr;
	Block* _tail = nullptr;
};
#endif
#pragma once

namespace bit
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t Size() const
		{
			return _finish - _start;
		}

		size_t Capacity() const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		//Vector<int> v2(v1);
		Vector(const Vector<T>& v);
		Vector<T>& operator=(Vector<T> v);

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		void Reserve(size_t n);
		void Resize(size_t n, const T& val = T());
		void PushBack(const T& x);
		void PopBack();
		void Insert(iterator pos, const T& x);
		iterator Erase(iterator pos);
	private:
		//T* _array;
		//size_t _size;
		//size_t _capacity;

		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}
#if 0
// 代表内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
// 代表自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};
template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};
// ... 所有内置类型都特化一下
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
	}
}
#endif
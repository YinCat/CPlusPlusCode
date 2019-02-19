//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
//
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		dst[i] = src[i];
//	}
//}

//#include <string>
//bool IsPODType(const char* strType)
//{
//	const char* arrType[] = { "char", "short", "int", "long", "long long", "float",
//		"double", "long double" };
//	for (size_t i = 0; i < sizeof(arrType) / sizeof(arrType[0]); ++i)
//	{
//		if (0 == strcmp(strType, arrType[i]))
//			return true;
//	}
//	return false;
//}
//
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	if (IsPODType(typeid(T).name()))
//		memcpy(dst, src, sizeof(T)*size);
//	else
//	{
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//	}
//}
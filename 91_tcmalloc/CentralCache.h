#ifndef __CENTRAL_CACHE_H__
#define __CENTRAL_CACHE_H__

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}
private:
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache) = delete;
	static CentralCache _inst;
};

#endif // !__CENTRAL_CACHE_H__

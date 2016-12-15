#ifndef DB_CACHE_MANAGER_H
#define DB_CACHE_MANAGER_H

#include "DragonBones.h"
#include <unordered_map>
#include <string>

NAME_SPACE_DRAGON_BONES_BEGIN

class DBCacheManager{

public:

	static DBCacheManager* getInstance();
	static void destroyInstance();

	DBCacheManager();
	virtual ~DBCacheManager();

	void retainDragonBonesData(const std::string& dragonBonesName);
	void retainTextureAtlasData(const std::string& textureAtlasName);
	void releaseDragonBonesData(const std::string& dragonBonesName, bool forceClean = false);
	void releaseTextureAtlasData(const std::string& textureAtlasName, bool forceClean = false);
	void clearAllCache();

private:
	static DBCacheManager* instance;
	std::unordered_map<std::string, int> m_mapDragonBonesName2RetainCount;
	std::unordered_map<std::string, int> m_mapTextureAtlasName2RetainCount;
	
};

NAME_SPACE_DRAGON_BONES_END

#endif
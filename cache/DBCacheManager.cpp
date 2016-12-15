#include "cache\DBCacheManager.h"
#include "DBCCFactory.h"

NAME_SPACE_DRAGON_BONES_BEGIN


DBCacheManager* DBCacheManager::instance = nullptr;

DBCacheManager* DBCacheManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new DBCacheManager();
	}
	return instance;
}

void DBCacheManager::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

DBCacheManager::DBCacheManager()
{

}

DBCacheManager::~DBCacheManager()
{
	clearAllCache();
}

void DBCacheManager::releaseDragonBonesData(const std::string& dragonBonesName,bool forceClean)
{
	
	const auto& _iter = m_mapDragonBonesName2RetainCount.find(dragonBonesName);
	if (_iter == m_mapDragonBonesName2RetainCount.end())
	{
		return;
	}
	_iter->second -= 1;
	if (_iter->second <= 0 || forceClean)
	{
		DBCCFactory::getInstance()->removeDragonBonesData(dragonBonesName);
		m_mapDragonBonesName2RetainCount.erase(dragonBonesName);
	}

}

void DBCacheManager::releaseTextureAtlasData(const std::string& textureAtlasName, bool forceClean)
{
	const auto& _iter = m_mapTextureAtlasName2RetainCount.find(textureAtlasName);
	if (_iter == m_mapTextureAtlasName2RetainCount.end())
	{
		return;
	}
	_iter->second -= 1;
	if (_iter->second <= 0 || forceClean)
	{
		DBCCFactory::getInstance()->removeTextureAtlas(textureAtlasName);
		m_mapTextureAtlasName2RetainCount.erase(textureAtlasName);
		
	}
}

void DBCacheManager::retainDragonBonesData(const std::string& dragonBonesName)
{
	const auto& _iter = m_mapDragonBonesName2RetainCount.find(dragonBonesName);
	if (_iter == m_mapDragonBonesName2RetainCount.end())
	{
		m_mapDragonBonesName2RetainCount.emplace(std::make_pair(dragonBonesName, 1));
	}
	else
	{
		_iter->second += 1;
	}

}

void DBCacheManager::retainTextureAtlasData(const std::string& textureAtlasName)
{
	const auto& _iter = m_mapTextureAtlasName2RetainCount.find(textureAtlasName);
	if (_iter == m_mapTextureAtlasName2RetainCount.end())
	{
		m_mapTextureAtlasName2RetainCount.emplace(std::make_pair(textureAtlasName, 1));
	}
	else
	{
		_iter->second += 1;
	}
}

void DBCacheManager::clearAllCache()
{
	for (const auto& _pair : m_mapDragonBonesName2RetainCount)
	{
		DBCCFactory::getInstance()->removeDragonBonesData(_pair.first);
		
	}
	for (const auto& _pair : m_mapTextureAtlasName2RetainCount)
	{
		DBCCFactory::getInstance()->removeTextureAtlas(_pair.first);

	}
	m_mapDragonBonesName2RetainCount.clear();
	m_mapTextureAtlasName2RetainCount.clear();
}



NAME_SPACE_DRAGON_BONES_END
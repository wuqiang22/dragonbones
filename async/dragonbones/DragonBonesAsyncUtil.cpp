#include "DragonBonesAsyncUtil.h"
#include "async/AsyncFileUtils.h"
#include "dragonbones/renderer/cocos2d-x-3.x/DBCCFactory.h"

NAME_SPACE_DRAGON_BONES_BEGIN

DragonBonesAsyncUtil* DragonBonesAsyncUtil::instance = nullptr;

DragonBonesAsyncUtil* DragonBonesAsyncUtil::getInstance()
{
	if (!instance)
	{
		instance = new DragonBonesAsyncUtil();
	}
	return instance;
}

void DragonBonesAsyncUtil::destoryInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void DragonBonesAsyncUtil::loadDragonBonesDataAsync(const std::string& dragonBonesFileName, const std::string& dragonBonesName, std::function<void(dragonBones::DragonBonesData*)> callback)
{
	dragonBones::DragonBonesData* dragonBonesData = dragonBones::DBCCFactory::getInstance()->getDragonBonesData(dragonBonesName);
	if (dragonBonesData)
	{
		if (callback)
		{
			callback(dragonBonesData);
		}
		for (auto& iter : m_asyncStructs)
		{
			if (iter.dragonBonesName == dragonBonesName)
			{
				iter.dragonBonesData = dragonBonesData;
				break;
			}
		}
		tryGenerateArmatureNode();
		return;
	}

	game::AsyncFileUtils::getInstance()->loadDataAsync(dragonBonesFileName, [=](const cocos2d::Data& data){
		if (data.getSize() <= 0)
		{
			CCLOG("can not load dragonBonesData for path = %s", dragonBonesFileName);
			return;
		}
		const char* bytes = (const char*)(data.getBytes());
		size_t len = data.getSize();

		dragonBones::DragonBonesData* dragonBonesData = dragonBones::DBCCFactory::getInstance()->initDragonBonesData(dragonBonesName, bytes, len);
		if (callback)
		{
			callback(dragonBonesData);
		}
		for (auto& iter : m_asyncStructs)
		{
			if (iter.dragonBonesName == dragonBonesName)
			{
				iter.dragonBonesData = dragonBonesData;
				break;
			}
		}
		tryGenerateArmatureNode();
	});
}

void DragonBonesAsyncUtil::loadDragonTextureAtlasDataAsync(const std::string& textureAtlasFileName, const std::string& textureAtalsName, std::function<void(dragonBones::ITextureAtlas*)> callback)
{
	dragonBones::ITextureAtlas* textureAtlasData = dragonBones::DBCCFactory::getInstance()->getTextureAtlas(textureAtalsName);
	if (textureAtlasData)
	{
		if (callback)
		{
			callback(textureAtlasData);
		}
		for (auto& iter : m_asyncStructs)
		{
			if (iter.textureAtlasName == textureAtalsName)
			{
				iter.texureAtlasData = textureAtlasData;
				break;
			}
		}
		tryGenerateArmatureNode();
		return;
	}
	game::AsyncFileUtils::getInstance()->loadDataAsync(textureAtlasFileName, [=](const cocos2d::Data& data){
		if (data.getSize() <= 0)
		{
			CCLOG("can not load dragonBonesData for path = %s", textureAtlasFileName);
			return;
		}
		const char* bytes = (const char*)(data.getBytes());
		size_t len = data.getSize();
		dragonBones::ITextureAtlas* textureAtlasData = dragonBones::DBCCFactory::getInstance()->initTextureAtlasData(textureAtlasFileName,textureAtalsName, bytes, len);
		if (callback)
		{
			callback(textureAtlasData);
		}
		for (auto& iter : m_asyncStructs)
		{
			if (iter.textureAtlasName == textureAtalsName)
			{
				iter.texureAtlasData = textureAtlasData;
				break;
			}
		}
		tryGenerateArmatureNode();
	});
}

void DragonBonesAsyncUtil::buildArmatureNode(const std::string& dragonBonesFileName, const std::string& dragonBonesName, const std::string& textureAtlasFileName, const std::string& textureAtalsName, const std::string& armatureName, ARMATURENODE_FUNC callback)
{
	bool exist = false;
	for (auto& iter : m_asyncStructs)
	{
		if (iter.dragonBonesName == dragonBonesName && iter.textureAtlasName == textureAtalsName)
		{
			iter.emplace_back(armatureName,callback);
			exist = true;
			break;
		}
	}
	if (!exist)
	{
		AsyncStruct asyncStruct(dragonBonesName, textureAtalsName);
		asyncStruct.emplace_back(armatureName, callback);
		m_asyncStructs.emplace_back(asyncStruct);
		loadDragonBonesDataAsync(dragonBonesFileName, dragonBonesName);
		loadDragonTextureAtlasDataAsync(textureAtlasFileName, textureAtalsName);
	}

	tryGenerateArmatureNode();

}


void DragonBonesAsyncUtil::tryGenerateArmatureNode()
{
	for (auto& iter = m_asyncStructs.begin(); iter != m_asyncStructs.end(); )
	{
		if (iter->dragonBonesData != nullptr && iter->texureAtlasData != nullptr)
		{
			CCASSERT(iter->callbacks.size() == iter->armatureNames.size(), "callback and armature is not equal");
			for (size_t idx = 0, len = iter->callbacks.size(); idx <len; idx++)
			{
				ARMATURENODE_FUNC callback = iter->callbacks[idx];

				const std::string& armatureName = iter->armatureNames[idx];
				dragonBones::DBCCArmatureNode* armatureNode = generateArmatureNode(&(*iter), armatureName);
				if (callback)
				{
					callback(armatureNode);
				}
			}
			iter->callbacks.clear();
			iter->armatureNames.clear();
			iter->isValid = false;
			iter = m_asyncStructs.erase(iter);
		}
		else{
			++iter;
		}
	}

}

dragonBones::DBCCArmatureNode* DragonBonesAsyncUtil::generateArmatureNode(AsyncStruct* asyncStruct, const std::string& armatureName)
{
	if (!asyncStruct || !asyncStruct->dragonBonesData || !asyncStruct->texureAtlasData || !asyncStruct->isValid)
	{
		CCLOG("generate armature node fail dragonBonesName = %s, textureAtalsName= %s", asyncStruct->dragonBonesName, asyncStruct->textureAtlasName);
		return nullptr;
	}

	//DBCCFactory::buildArmature(const std::string &armatureName, const std::string &skinName, const std::string &animationName,
	//const std::string &dragonBonesName, const std::string &textureAtlasName) const
	return dragonBones::DBCCFactory::getInstance()->buildArmatureNode(armatureName, "", armatureName, asyncStruct->dragonBonesName, asyncStruct->textureAtlasName);
}

NAME_SPACE_DRAGON_BONES_END
#ifndef __Dragon_Bones_Async_Util_H
#define __Dragon_Bones_Async_Util_H

#include "DragonBones.h"
#include "dragonbones/renderer/cocos2d-x-3.x/DBCCArmatureNode.h"
#include <functional>
#include "base/CCData.h"
#include <vector>


NAME_SPACE_DRAGON_BONES_BEGIN

class DragonBonesAsyncUtil{
public:
	typedef std::function<void(dragonBones::DBCCArmatureNode*)> ARMATURENODE_FUNC; 
	struct AsyncStruct{
	public:
		AsyncStruct(const std::string& _dragonName, const std::string& _textureName) :
			dragonBonesName(_dragonName), textureAtlasName(_textureName), dragonBonesData(nullptr), texureAtlasData(nullptr), isValid(true){}

		virtual ~AsyncStruct()
		{
			callbacks.clear();
			armatureNames.clear();
			dragonBonesData = nullptr;
			texureAtlasData = nullptr;
		}

		std::string dragonBonesName;
		std::string textureAtlasName;
		dragonBones::DragonBonesData* dragonBonesData;
		dragonBones::ITextureAtlas* texureAtlasData;
		cocos2d::Texture2D* texture;
		std::vector<ARMATURENODE_FUNC> callbacks;
		std::vector<std::string> armatureNames;
		bool isValid;
		void emplace_back(const std::string armatureName,ARMATURENODE_FUNC callback)
		{
			armatureNames.emplace_back(armatureName);
			callbacks.emplace_back(callback);
		}
	};
	static DragonBonesAsyncUtil* getInstance();
	static void destoryInstance();
	
	
	void loadDragonBonesDataAsync(const std::string& dragonBonesFileName, const std::string& dragonBonesName, std::function<void(dragonBones::DragonBonesData*)> callback = nullptr);
	void loadDragonTextureAtlasDataAsync(const std::string& textureAtlasFileName, const std::string& textureAtalsName, std::function<void(dragonBones::ITextureAtlas*)> callback = nullptr);

	void buildArmatureNode(const std::string& dragonBonesFileName, const std::string& dragonBonesName, const std::string& textureAtlasFileName, const std::string& textureAtalsName, const std::string& armatureName,ARMATURENODE_FUNC callback);

private:
	dragonBones::DBCCArmatureNode* generateArmatureNode(AsyncStruct* asyncStruct,const std::string& armatureName);
	void tryGenerateArmatureNode();
	void notifyLoadDragonBonesDataFail(const std::string& dragonBonesName);
	void notifyLoadTextureAtlasDataFail(const std::string& textureAtlasName);

	void setDragonBonesData(const std::string& dragonBonesName, dragonBones::DragonBonesData* data);
	void setTextureAtlasData(const std::string& textureAtlasName, dragonBones::ITextureAtlas* data);
	void setTexture2d(const std::string& textureAtlasName, cocos2d::Texture2D* texture);
private:
	static DragonBonesAsyncUtil* instance;

	std::vector<AsyncStruct> m_asyncStructs;
};

NAME_SPACE_DRAGON_BONES_END
#endif
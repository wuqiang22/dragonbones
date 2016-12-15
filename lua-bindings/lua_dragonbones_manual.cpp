#include "lua_dragonbones_manual.hpp"
#include "DBCCRenderHeaders.h"
#include "DragonBonesHeaders.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "cache/DBCacheManager.h"
#include "async/dragonbones/DragonBonesAsyncUtil.h"
#include "CCLuaEngine.h"

int lua_dragonbones_DBCacheManager_clearAllCache(lua_State* tolua_S)
{
	int argc = 0;
	dragonBones::DBCacheManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::DBCacheManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_dragonbones_DBCacheManager_clearAllCache'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:clearAllCache");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_clearAllCache'", nullptr);
			return 0;
		}
		cobj->clearAllCache();
		lua_settop(tolua_S, 1);
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DBCacheManager:clearAllCache", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_clearAllCache'.", &tolua_err);
#endif

	return 0;
}


int lua_dragonbones_DBCacheManager_releaseTextureAtlasData(lua_State* tolua_S)
{
	int argc = 0;
	dragonBones::DBCacheManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::DBCacheManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_dragonbones_DBCacheManager_releaseTextureAtlasData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:releaseTextureAtlasData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseTextureAtlasData'", nullptr);
			return 0;
		}
		cobj->releaseTextureAtlasData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2)
	{
		std::string arg0;
		bool arg1;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:releaseTextureAtlasData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseTextureAtlasData'", nullptr);
			return 0;
		}
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, "db.DBCacheManager:releaseDragonBonesData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseTextureAtlasData'", nullptr);
			return 0;
		}

		cobj->releaseTextureAtlasData(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DBCacheManager:releaseTextureAtlasData", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_releaseTextureAtlasData'.", &tolua_err);
#endif

	return 0;
}

int lua_dragonbones_DBCacheManager_releaseDragonBonesData(lua_State* tolua_S)
{
	int argc = 0;
	dragonBones::DBCacheManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::DBCacheManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_dragonbones_DBCacheManager_releaseDragonBonesData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:releaseDragonBonesData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseDragonBonesData'", nullptr);
			return 0;
		}
		cobj->releaseDragonBonesData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2)
	{
		std::string arg0;
		bool arg1;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:releaseDragonBonesData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseDragonBonesData'", nullptr);
			return 0;
		}
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, "db.DBCacheManager:releaseDragonBonesData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_releaseDragonBonesData'", nullptr);
			return 0;
		}

		cobj->releaseDragonBonesData(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DBCacheManager:releaseDragonBonesData", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_releaseDragonBonesData'.", &tolua_err);
#endif

	return 0;
}

int lua_dragonbones_DBCacheManager_retainDragonBonesData(lua_State* tolua_S)
{
	int argc = 0;
	dragonBones::DBCacheManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::DBCacheManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_dragonbones_DBCacheManager_retainDragonBonesData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:retainDragonBonesData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_retainDragonBonesData'", nullptr);
			return 0;
		}
		cobj->retainDragonBonesData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DBCacheManager:retainDragonBonesData", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_retainDragonBonesData'.", &tolua_err);
#endif

	return 0;
}

int lua_dragonbones_DBCacheManager_retainTextureAtlasData(lua_State* tolua_S)
{
	int argc = 0;
	dragonBones::DBCacheManager* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::DBCacheManager*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_dragonbones_DBCacheManager_retainTextureAtlasData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::string arg0;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DBCacheManager:retainTextureAtlasData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_retainTextureAtlasData'", nullptr);
			return 0;
		}
		cobj->retainTextureAtlasData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DBCacheManager:retainDragonBonesData", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_retainTextureAtlasData'.", &tolua_err);
#endif

	return 0;
}

int lua_dragonbones_DBCacheManager_destroyInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_destroyInstance'", nullptr);
			return 0;
		}
		dragonBones::DBCacheManager::destroyInstance();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DBCacheManager:destroyInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_destroyInstance'.", &tolua_err);
#endif
	return 0;
}

int lua_dragonbones_DBCacheManager_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "db.DBCacheManager", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DBCacheManager_getInstance'", nullptr);
			return 0;
		}
		dragonBones::DBCacheManager* ret = dragonBones::DBCacheManager::getInstance();
		object_to_luaval<dragonBones::DBCacheManager>(tolua_S, "db.DBCacheManager", (dragonBones::DBCacheManager*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DBCacheManager:getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DBCacheManager_getInstance'.", &tolua_err);
#endif
	return 0;
}


int lua_dragonbones_DragonBonesAsyncUtil_destroyInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "db.DragonBonesAsyncUtil", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_destroyInstance'", nullptr);
			return 0;
		}
		dragonBones::DragonBonesAsyncUtil::destoryInstance();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DragonBonesAsyncUtil:destoryInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DragonBonesAsyncUtil_destroyInstance'.", &tolua_err);
#endif
	return 0;
}

int lua_dragonbones_DragonBonesAsyncUtil_getInstance(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "db.DragonBonesAsyncUtil", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_getInstance'", nullptr);
			return 0;
		}
		dragonBones::DragonBonesAsyncUtil* ret = dragonBones::DragonBonesAsyncUtil::getInstance();
		object_to_luaval<dragonBones::DragonBonesAsyncUtil>(tolua_S, "db.DBCacheManager", (dragonBones::DragonBonesAsyncUtil*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DragonBonesAsyncUtil:getInstance", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DragonBonesAsyncUtil_getInstance'.", &tolua_err);
#endif
	return 0;
}


int lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "db.DragonBonesAsyncUtil", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 6)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}
		std::string arg0, arg1, arg2, arg3, arg4;
		LUA_FUNCTION handle;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "db.DragonBonesAsyncUtil:buildArmatureNode");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}

		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "db.DragonBonesAsyncUtil:buildArmatureNode");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}

		ok &= luaval_to_std_string(tolua_S, 4, &arg2, "db.DragonBonesAsyncUtil:buildArmatureNode");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}

		ok &= luaval_to_std_string(tolua_S, 5, &arg3, "db.DragonBonesAsyncUtil:buildArmatureNode");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}

		ok &= luaval_to_std_string(tolua_S, 6, &arg4, "db.DragonBonesAsyncUtil:buildArmatureNode");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}

		handle = toluafix_ref_function(tolua_S, 7, 0); ok &= handle != 0;
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode'", nullptr);
			return 0;
		}
		auto callback = [=](dragonBones::DBCCArmatureNode* armatureNode){
			int ID = (armatureNode) ? (int)armatureNode->_ID : -1;
			int* luaID = (armatureNode) ? &armatureNode->_luaID : nullptr;
			toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)armatureNode, "db.DBCCArmatureNode");
			LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handle, 1);
			LuaEngine::getInstance()->removeScriptHandler(handle);

		};

		dragonBones::DragonBonesAsyncUtil::getInstance()->buildArmatureNode(arg0, arg1, arg2, arg3, arg4, callback);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DragonBonesAsyncUtil:getInstance", argc, 6);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_DragonBonesAsyncUtil_getInstance'.", &tolua_err);
#endif
	return 0;
}


int lua_register_dragonbones_DBCacheManager(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "db.DBCacheManager");
	tolua_cclass(tolua_S, "DBCacheManager", "db.DBCacheManager", "db.DBCacheManager", nullptr);

	tolua_beginmodule(tolua_S, "DBCacheManager");
	tolua_function(tolua_S, "getInstance", lua_dragonbones_DBCacheManager_getInstance);
	tolua_function(tolua_S, "destroyInstance", lua_dragonbones_DBCacheManager_destroyInstance);
	tolua_function(tolua_S, "retainDragonBonesData", lua_dragonbones_DBCacheManager_retainDragonBonesData);
	tolua_function(tolua_S, "retainTextureAtlasData", lua_dragonbones_DBCacheManager_retainTextureAtlasData);
	tolua_function(tolua_S, "releaseDragonBonesData", lua_dragonbones_DBCacheManager_releaseDragonBonesData);
	tolua_function(tolua_S, "releaseTextureAtlasData", lua_dragonbones_DBCacheManager_releaseTextureAtlasData);
	tolua_function(tolua_S, "clearAllCache", lua_dragonbones_DBCacheManager_clearAllCache);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(dragonBones::DBCacheManager).name();
	g_luaType[typeName] = "db.DBCacheManager";
	g_typeCast["DBCacheManager"] = "db.DBCacheManager";
	return 1;
}


int lua_register_dragonbones_DragonBonesAsyncUtil(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "db.DragonBonesAsyncUtil");
	tolua_cclass(tolua_S, "DragonBonesAsyncUtil", "db.DragonBonesAsyncUtil", "db.DragonBonesAsyncUtil", nullptr);

	tolua_beginmodule(tolua_S, "DragonBonesAsyncUtil");
	tolua_function(tolua_S, "getInstance", lua_dragonbones_DragonBonesAsyncUtil_getInstance);
	tolua_function(tolua_S, "destroyInstance", lua_dragonbones_DragonBonesAsyncUtil_destroyInstance);
	tolua_function(tolua_S, "buildArmatureNode", lua_dragonbones_DragonBonesAsyncUtil_buildArmatureNode);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(dragonBones::DragonBonesAsyncUtil).name();
	g_luaType[typeName] = "db.DragonBonesAsyncUtil";
	g_typeCast["DragonBonesAsyncUtil"] = "db.DragonBonesAsyncUtil";
	return 1;
}



TOLUA_API int register_all_dragonbones_manual(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "db", 0);
	tolua_beginmodule(tolua_S, "db");

	lua_register_dragonbones_DBCacheManager(tolua_S);
	lua_register_dragonbones_DragonBonesAsyncUtil(tolua_S);

	tolua_endmodule(tolua_S);

	return 1;
}
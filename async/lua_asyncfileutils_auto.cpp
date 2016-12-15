#include "lua_asyncfileutils_auto.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "AsyncFileUtils.h"
#include "cocos2d\LuaScriptHandlerMgr.h"
#include "CCLuaEngine.h"



int lua_dragonbones_AsyncFileUtils_cancelLoadDataAsync(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

	game::AsyncFileUtils* self = nullptr;

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "game.AsyncFileUtils", 0, &tolua_err)) goto tolua_lerror;
#endif

	self = static_cast<game::AsyncFileUtils*>(tolua_tousertype(tolua_S, 1, 0));
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S, "invalid 'self' in function 'lua_dragonbones_AsyncFileUtils_cancalLoadDataAsync'\n", NULL);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'", nullptr);
			return 0;
		}
		cocos2d::LUA_FUNCTION handler;

		ok &= luaval_to_int32(tolua_S, 2, &handler, "game.AsyncFileUtils:cancelLoadDataAsync");

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'", nullptr);
			return 0;
		}
		toluafix_remove_function_by_refid(tolua_S,handler);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "game.AsyncFileUtils:cancalLoadDataAsync", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'.", &tolua_err);
#endif
	return 0;
}

int lua_dragonbones_AsyncFileUtils_cancelAllLoadDataAsync(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

	game::AsyncFileUtils* self = nullptr;

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "game.AsyncFileUtils", 0, &tolua_err)) goto tolua_lerror;
#endif

	self = static_cast<game::AsyncFileUtils*>(tolua_tousertype(tolua_S, 1, 0));
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S, "invalid 'self' in function 'lua_dragonbones_AsyncFileUtils_cancelAllLoadDataAsync'\n", NULL);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_cancelAllLoadDataAsync'", nullptr);
			return 0;
		}
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "game.AsyncFileUtils:cancalLoadDataAsync");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_cancelAllLoadDataAsync'", nullptr);
			return 0;
		}
		self->cancelLoadDataAsync(arg0);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "game.AsyncFileUtils:cancelLoadDataAsync", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'.", &tolua_err);
#endif
	return 0;
}

int lua_dragonbones_AsyncFileUtils_loadDataAsync(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

	game::AsyncFileUtils* self = nullptr;

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "game.AsyncFileUtils", 0, &tolua_err)) goto tolua_lerror;
#endif

	self = static_cast<game::AsyncFileUtils*>(tolua_tousertype(tolua_S, 1, 0));
#if COCOS2D_DEBUG >= 1
	if (nullptr == self) {
		tolua_error(tolua_S, "invalid 'self' in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'\n", NULL);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	
	if (argc == 2)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'", nullptr);
			return 0;
		}
		std::string arg0;
		cocos2d::LUA_FUNCTION handler;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "game.AsyncFileUtils:loadDataAsync");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'", nullptr);
			return 0;
		}
		handler = toluafix_ref_function(tolua_S, 3, 0);
		ok &= handler != 0;
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'", nullptr);
			return 0;
		}

		self->loadDataAsync(arg0, [=](const Data& data){

			int length = data.getSize();
			char* bytes = (char*)malloc(length + 1);
			memset(bytes, 0, length + 1);
			memcpy(bytes, data.getBytes(), length);

			tolua_pushstring(tolua_S, bytes);
			free(bytes);
			cocos2d::LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 1);
		});
		lua_pushnumber(tolua_S, handler);

		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "game.AsyncFileUtils:loadDataAsync", argc, 2);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_dragonbones_AsyncFileUtils_loadDataAsync'.", &tolua_err);
#endif
	return 0;
}

int lua_register_Async_FileUtils(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "game.AsyncFileUtils");
	tolua_cclass(tolua_S, "AsyncFileUtils", "game.AsyncFileUtils", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "AsyncFileUtils");

	tolua_function(tolua_S, "loadDataAsync", lua_dragonbones_AsyncFileUtils_loadDataAsync);
	tolua_function(tolua_S, "cancelAllLoadDataAsync", lua_dragonbones_AsyncFileUtils_cancelAllLoadDataAsync);
	tolua_function(tolua_S, "cancelLoadDataAsync", lua_dragonbones_AsyncFileUtils_cancelLoadDataAsync);


	tolua_endmodule(tolua_S);
	std::string typeName = typeid(game::AsyncFileUtils).name();
	g_luaType[typeName] = "game.AsyncFileUtils";
	g_typeCast["AsyncFileUtils"] = "game.AsyncFileUtils";
	return 1;
}



TOLUA_API int register_asyncfileutils(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "game", 0);
	tolua_beginmodule(tolua_S, "game");

	lua_register_Async_FileUtils(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

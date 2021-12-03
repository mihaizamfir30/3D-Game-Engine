#pragma once
#include "Engine/GameObject.h"
#include "Engine/Transform.h"
#include "Engine/Input.h"

#include <iostream>
#include <string>


// include Lua, assumes it is local to this file
extern "C"
{
#include "lua535/include/lua.h"
#include "lua535/include/lauxlib.h"
#include "lua535/include/lualib.h"
}

/*
// Link to lua library
#ifdef _WIN32
#pragma comment(lib, "lua535/liblua54.a")
#endif
*/

class Lua
{
public:

	static Lua* GetInstance();

	bool OpenScript(char* script);
	void Register(char* name, int (*func)(lua_State*));

	void Call(char* functionName, double deltaTime);

	lua_State* L;

private:

	Lua();
	~Lua();

	bool CheckLua(lua_State* L, int r);

	static Lua* luaInstance;

};
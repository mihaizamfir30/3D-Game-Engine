#include "Lua.h"

Lua* Lua::luaInstance = NULL;

Lua::Lua() {

	// Create Lua State
	L = luaL_newstate();

	// Add standard libraries to Lua Virtual Machine
	luaL_openlibs(L);
}

//Lua::lua_Translate(lua_State* L)
void Lua::Register(char* name, int (*func)(lua_State*)) {
	lua_register(L, name, func);
}


Lua::~Lua() {
	lua_close(L);
}

Lua* Lua::GetInstance() {
	if (luaInstance == NULL) {
		luaInstance = new Lua();
	}

	return luaInstance;
}

// Little error checking utility function
bool Lua::CheckLua(lua_State* L, int r)
{
	if (r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
		return false;
	}
	return true;
}

bool Lua::OpenScript(char* script) {
	return CheckLua(L, luaL_dostring(L, script));
}

void Lua::Call(char* functionName, double deltaTime) {

	lua_getglobal(L, functionName);

	if (lua_isfunction(L, -1))
	{
		lua_pushnumber(L, deltaTime);

		CheckLua(L, lua_pcall(L, 1, 1, 0));
	}
}
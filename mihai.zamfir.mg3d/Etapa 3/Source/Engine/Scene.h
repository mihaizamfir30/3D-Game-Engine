#pragma once

#include <include/gl.h>

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include "Engine/GameObject.h"
#include "Engine/Camera.h"
#include "Engine/Light.h"
#include "Engine/Canvas.h"

#include "Engine/UI.h"
#include "Engine/Texture.h"

#include "Engine/TextRenderer.h"
#include "Engine/Lua.h"

extern "C"
{
#include "lua535/include/lua.h"
#include "lua535/include/lauxlib.h"
#include "lua535/include/lualib.h"
}

class Scene
{
	public:
		Scene();
		~Scene();

		void OnFrameStart();
		void Update(double deltaTime);
		void OnFrameEnd();

		void SetActiveCamera(int id);

		int activeCameraId;
		std::map<int, Camera> Cameras;
		std::list<GameObject> GameObjects;
		std::map<int, GameObject*> idToGameObject;

		Canvas* canvas;

		static GameObject* activeGameObject;
		char* script;

		Lua* instance;

		void Start();

		void Save();

	private:

		Light* light;

		Texture* texture;
		Camera* camera;

		std::list<int>::iterator it_scr;
		std::list<GameObject>::iterator it_go;
		static std::list<GameObject>::iterator st_it_go;

		static int lua_Translate(lua_State* L);
		static int lua_GetKey(lua_State* L);

};

#pragma once

#include <include/gl.h>

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include "Engine/GameObject.h"

class Scene
{
	public:
		Scene();
		~Scene();

		void OnFrameStart();
		void Update();
		void OnFrameEnd();

		bool debug;

	private:

		std::list<GameObject> gameObjects;
		std::list<GameObject>::iterator it_go;

		Shader shader;
};

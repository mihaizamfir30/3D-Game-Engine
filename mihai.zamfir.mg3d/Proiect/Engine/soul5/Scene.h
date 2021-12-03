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
#include "Engine/Camera.h"
#include "Engine/Light.h"

class Scene
{
	public:
		Scene();
		~Scene();

		void OnFrameStart();
		void Update(double deltaTime);
		void OnFrameEnd();

	private:

		std::list<GameObject> gameObjects;
		std::list<GameObject>::iterator it_go;

		Light* light;

		Mesh* cubeMesh;
		Mesh* sphereMesh;
		Mesh* cylinderMesh;
		Mesh* quadMesh;

		Camera* camera;

		Shader shader;
		Shader lightShader;

		glm::mat4 projection;
};

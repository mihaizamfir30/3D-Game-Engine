#pragma once

#include <vector>
#include <iostream>

#include "Engine/Mesh.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"
#include "Engine/UI.h"

//#include "Engine/SceneManager.h"
//#include "Engine/Camera.h"

#include "Input.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GameObject
{
	public:

		GameObject();
		GameObject(char *name);
		~GameObject();

		void Init(Transform* transform, Mesh* mesh, Shader* shader);

		Mesh* mesh;
		Transform* transform;
		Shader* shader;

		void Update(double deltaTime);
		void Draw();

		char *name;

		int Id;
		int ParentId;
		std::list<int> childrenId;

		glm::vec4 scaleAndOffset;


	private:

};

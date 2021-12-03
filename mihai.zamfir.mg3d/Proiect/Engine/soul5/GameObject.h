#pragma once

#include <vector>
#include <iostream>

#include "Engine/Mesh.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"

#include "Input.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GameObject
{
	public:
		GameObject(std::string name);
		~GameObject();

		Mesh* mesh;
		Transform* transform;
		Shader* shader;

		void Update(double deltaTime);
		void Draw();

		std::string name;

	private:
};

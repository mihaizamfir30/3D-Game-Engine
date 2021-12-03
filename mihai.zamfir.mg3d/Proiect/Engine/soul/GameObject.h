#pragma once

#include <vector>
#include <iostream>

#include "Engine/Mesh.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"

//using namespace std;

class GameObject
{
	public:
		GameObject();
		~GameObject();

		Mesh* mesh;
		Transform* transform;
		Shader* shader;

		void Draw();

	private:

};

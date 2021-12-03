#pragma once

#include <vector>
#include <iostream>

#include "Engine/Mesh.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"
#include "Engine/UI.h"
#include "Engine/Utils.h"

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

		bool IsColliding(GameObject* other);

		Mesh* mesh;
		Transform* transform;
		Shader* shader;

		void Update(double deltaTime);
		void Draw();

		char *name;

		int Id;
		int ParentId;
		std::list<int> childrenId;

		std::list<int> scripts;

		glm::vec4 scaleAndOffset;

		bool isColliding = false;

		void Save(int indentLevel);


	private:

		static bool checkCubeCubeCollision(GameObject* cube, GameObject* otherCube);
		static bool checkCubeSphereCollision(GameObject* cube, GameObject* sphere);
		static bool checkCubeCylinderCollision(GameObject* cube, GameObject* cylinder);

		static bool checkSphereSphereCollision(GameObject *sphere, GameObject *otherSphere);
		static bool checkSphereCylinderCollision(GameObject *sphere, GameObject *cylinder);

		static bool checkCylinderCylinderCollision(GameObject* sphere, GameObject* cylinder);


		static float sqrDistPointToAABB(glm::vec3 point, glm::vec3 position, glm::vec3 scale);


};

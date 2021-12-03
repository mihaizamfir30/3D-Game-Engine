#pragma once

#include <include/glm.h>
//#include <include/gl.h>

#include "Engine/Shader.h"
#include "Engine/Mesh.h"
#include "Engine/Transform.h"

#include "Engine/ResourceManager.h"

class Light
{
	
	public:
		Light();
		Light(glm::vec3 lightPosition, glm::vec3 lightColor);

		~Light();

		void Update(double deltaTime);

		Shader* shader;
		Shader* lightShader;
		Mesh* mesh;
		Transform *transform;

		glm::vec3 lightPosition;
		glm::vec3 lightColor;

		void Draw();

	private:

		float time;

		float radius = 2.0f;
		float speed = 3.0f;
};

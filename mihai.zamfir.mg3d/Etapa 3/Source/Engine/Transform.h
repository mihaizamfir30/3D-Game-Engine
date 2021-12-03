#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Engine/Utils.h"

class Transform
{
	public:
		Transform();
		~Transform();

		glm::vec3 GetPosition();
		glm::vec3 GetRotation();
		glm::vec3 GetScale();

		void SetPosition(glm::vec3 position);
		void SetRotation(glm::vec3 rotation);
		void SetScale(glm::vec3 scale);

		glm::mat4 GetModelMatrix();

		void Translate(glm::vec3 offset);

		void Save(int indentLevel);

	private:

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
};

#pragma once

using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
	

	public:
		Transform();
		~Transform();

		glm::mat4 trans;

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 getModelMatrix();
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

	private:

	private:

};

#pragma once
#include <glm/glm.hpp>
#include <include/gl.h>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include "Shader.h"
#include "Input.h"

class Camera
{
	
	public:

		Camera();
		~Camera();

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();

		void Update(double deltaTime);

		Shader* shader;
		Shader* lightShader;

	private:
		glm::vec3 cameraPosition;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;

		glm::vec3 cameraTarget;

		glm::vec3 cameraDirection;
		glm::vec3 cameraRight;

		float fov;
		float nearPlane;
		float farPlane;

		int width = 600;
		int height = 600;


		float yaw;
		float pitch;
		float roll;

		// Mouse position last frame
		float lastX;
		float lastY;
		bool firstMouse = true;

		float zoom;
};

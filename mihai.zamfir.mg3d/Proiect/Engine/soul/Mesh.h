#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>

#include "stb_image.h"

typedef struct {
	glm::vec4 pos;
} vertex;

class Mesh
{
	public:
		Mesh();
		~Mesh();

		void Draw();

		glm::mat4 trans;

	private:
		unsigned int shaderProgram;

		void loadTexture();
};

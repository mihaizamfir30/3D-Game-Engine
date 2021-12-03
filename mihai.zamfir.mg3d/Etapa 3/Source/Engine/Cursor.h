]#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>

#include <list>

#include "Engine/UIMesh.h"
#include "Engine/Shader.h"

#include "Engine/ResourceManager.h"


class Cursor
{
public:
	Cursor();
	~Cursor();

	void Draw();

	int Id;
	glm::vec3 Position;
	glm::vec3 Scale;

	UIMesh* uiMesh;
	Shader* shader;
	glm::mat4 projection;

	float depth;
	glm::vec3 color;

private:

	glm::mat4 getModelMatrix();
};
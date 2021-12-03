#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>


#include <list>

class Mesh
{
	public:
		Mesh();
		~Mesh();

		void CreateCubeMesh();
		void CreateQuadMesh();
		void CreateSphereMesh();
		void CreateCylinderMesh();

		int vertexSize = 8;

		void Draw();

	private:

		void addVertex(glm::vec3* position, glm::vec3* normal, glm::vec2* uv, int vertexIndex);
		void bind();

		unsigned int VAO, VBO, EBO;

		float* vertices;
		unsigned int noVertices;

		unsigned int* indices;
		unsigned int noIndices;
};
#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>


#include <list>

#include "Utils.h"

class Mesh
{
	public:
		Mesh();
		Mesh(char* path);
		~Mesh();

		void CreateCubeMesh();
		void CreateSphereMesh(int resolutionX, int resolutionY_half);
		void CreateCylinderMesh(int resolution);
		void CreateBoxMesh();

		void Draw();

		float* vertices;
		unsigned int noVertices;
		unsigned int* trianglesPerVertex;

		unsigned int* indices;
		unsigned int noIndices;

		int vertexSize = 6;

	private:

		int currVertexIndex;
		void addVertex(glm::vec3* position);
		void addVertex(glm::vec3* position, int vertexIndex);

		int currTriangleIndex;
		void addTriangle(unsigned int a, unsigned int b, unsigned int c);
		void addTriangle(unsigned int a, unsigned int b, unsigned int c, int triangleIndex);
		
		void calculateNormals();
		void bind();

		unsigned int VAO, VBO, EBO;

		void Load(FILE* file);
};
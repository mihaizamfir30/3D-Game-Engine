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
		void CreateSphereMesh(int resolutionX, int resolutionY);
		void CreateCylinderMesh(int resolution);

		int vertexSize = 6;

		void Draw();

	private:

		int currVertexIndex;
		void addVertex(glm::vec3* position, glm::vec3* normal);
		void addVertex(glm::vec3* position, glm::vec3* normal, int vertexIndex);

		int currTriangleIndex;
		void addTriangle(unsigned int a, unsigned int b, unsigned int c);
		void addTriangle(unsigned int a, unsigned int b, unsigned int c, int triangleIndex);
		
		void calculateNormals();
		void bind();

		unsigned int VAO, VBO, EBO;

		float* vertices;
		unsigned int noVertices;
		unsigned int* trianglesPerVertex;

		unsigned int* indices;
		unsigned int noIndices;
};
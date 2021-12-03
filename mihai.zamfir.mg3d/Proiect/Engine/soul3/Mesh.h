#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>

#include "stb_image.h"

#include <list>

typedef struct {
	glm::vec4 pos;
} vertex;


/*
struct VertexAtrributes {
	bool hasNormals;
	bool hasTangents;
	bool hasColors;
	bool hasUvs;
	bool hasUvs2;
};
*/

class Mesh
{
	public:
		Mesh();
		~Mesh();

		void Draw();

		void CreateMesh();

		void AddTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3);
		void AddTriangleColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3);
		void AddTriangleColor(glm::vec3 col);

		void AddQuad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4);
		void AddQuadColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3, glm::vec3 col4);
		void AddQuadColor(glm::vec3 col);

		void Flush();

		void AddVertex(float* attributes);

		//int GetVertexSize(VertexAtrributes attributes);
		int GetVertexSize();


		std::list<glm::vec3> positions;
		std::list<glm::vec3> normals;
		std::list<glm::vec3> tangents;
		std::list<glm::vec3> colors;
		std::list<glm::vec2> uvs2;

		std::list<glm::vec3> indices;

		bool hasNormals;
		bool hasTangents;
		bool hasColors;
		bool hasUvs;
		bool hasUvs2;


	private:
		unsigned int VAO, VBO, EBO;
};

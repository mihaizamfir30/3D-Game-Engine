#pragma once

#include <vector>
#include <iostream>

#include "Engine/Mesh.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"

#include "Input.h"

//using namespace std;

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

/*
struct VertexAtrributes {
	bool hasNormals;
	bool hasTangents;
	bool hasColors;
	bool hasUvs;
	bool hasUvs2;
};
*/

class GameObject
{
	public:
		GameObject(std::string name);
		~GameObject();

		Mesh* mesh;
		Transform* transform;
		Shader* shader;

		void Update(double deltaTime);
		void Draw();

		void CreateMesh();

		void AddTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3);
		void AddTriangleColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3);
		void AddTriangleColor(glm::vec3 col);

		void AddQuad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4);
		void AddQuadColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3, glm::vec3 col4);
		void AddQuadColor(glm::vec3 col);

		void Flush();

		std::string name;

		std::list<glm::vec3> positions;
		std::list<glm::vec3> normals;
		std::list<glm::vec3> tangents;
		std::list<glm::vec3> colors;
		std::list<glm::vec2> uvs2;

		std::list<glm::vec3> indices;

		void AddVertex(float* attributes);

		//int GetVertexSize(VertexAtrributes attributes);
		int GetVertexSize();

		bool hasNormals;
		bool hasTangents;
		bool hasColors;
		bool hasUvs;
		bool hasUvs2;

	private:

		int k;
};

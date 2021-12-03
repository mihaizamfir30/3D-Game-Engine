#pragma once
#include <glm/glm.hpp>
#include <include/gl.h>
#include <glm/gtc/matrix_transform.hpp>

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include "Engine/ResourceManager.h"

class UIMesh
{
	
	public:
		
		UIMesh();
		~UIMesh();

		void CreateQuadMesh();
		void Draw();

		float* vertices;
		unsigned int noVertices;
		unsigned int* trianglesPerVertex;

		unsigned int* indices;
		unsigned int noIndices;

		int vertexSize = 5;

	private:

		void bind();

		unsigned int VAO, VBO, EBO;
};

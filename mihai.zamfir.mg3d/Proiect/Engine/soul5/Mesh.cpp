#include "Mesh.h"

#include <vector>
#include <iostream>


/*
	void AddQuad (Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4) {
		int vertexIndex = vertices.Count;
		vertices.Add(v1);
		vertices.Add(v2);
		vertices.Add(v3);
		vertices.Add(v4);
		triangles.Add(vertexIndex);
		triangles.Add(vertexIndex + 2);
		triangles.Add(vertexIndex + 1);
		triangles.Add(vertexIndex + 1);
		triangles.Add(vertexIndex + 2);
		triangles.Add(vertexIndex + 3);
	}

	void AddQuadColor (Color c1, Color c2, Color c3, Color c4) {
		colors.Add(c1);
		colors.Add(c2);
		colors.Add(c3);
		colors.Add(c4);
	}
*/


Mesh::Mesh() {

	vertexSize = 9;
}

Mesh::~Mesh() {}

void Mesh::Draw() {

	glBindVertexArray(VAO);
	
	if (cylinder == false) {
		//std::cout << "CUBE" << std::endl;
		glDrawArrays(GL_TRIANGLES, 0, noVertices);
	}
	else {
		//std::cout << "CYLINDER" << std::endl;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, noIndices, GL_UNSIGNED_INT, 0);
	}
}

void Mesh::CreateMesh() {

	return;

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

}

void Mesh::CreateCubeMesh() {

	cylinder = true;

	int faces = 6;

	noVertices = faces * 6;
	noIndices = faces * 2 * 3;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices2 = (unsigned int*)malloc(noIndices * sizeof(unsigned int));

	// Front
	// Colors
	vertices[0 * 9 + 0] =  -0.5f;		vertices[0 * 9 + 1] =  -0.5f;		vertices[0 * 9 + 2] =  0.5f;
	vertices[1 * 9 + 0] =  0.5f;		vertices[1 * 9 + 1] =  -0.5f;		vertices[1 * 9 + 2] =  0.5f;
	vertices[2 * 9 + 0] =  -0.5f;		vertices[2 * 9 + 1] =  0.5f;		vertices[2 * 9 + 2] =  0.5f;
	vertices[3 * 9 + 0] =  0.5f;		vertices[3 * 9 + 1] =  0.5f;		vertices[3 * 9 + 2] =  0.5f;

	// Normals
	vertices[0 * 9 + 6] = 0.0f;			vertices[0 * 9 + 7] = 0.0f;			vertices[0 * 9 + 8] = 1.0f;
	vertices[1 * 9 + 6] = 0.0f;			vertices[1 * 9 + 7] = 0.0f;			vertices[1 * 9 + 8] = 1.0f;
	vertices[2 * 9 + 6] = 0.0f;			vertices[2 * 9 + 7] = 0.0f;			vertices[2 * 9 + 8] = 1.0f;
	vertices[3 * 9 + 6] = 0.0f;			vertices[3 * 9 + 7] = 0.0f;			vertices[3 * 9 + 8] = 1.0f;

	// Back
	// Colors
	vertices[4 * 9 + 0] =  -0.5f;		vertices[4 * 9 + 1] =  -0.5f;		vertices[4 * 9 + 2] =  -0.5f;
	vertices[5 * 9 + 0] =  0.5f;		vertices[5 * 9 + 1] =  -0.5f;		vertices[5 * 9 + 2] =  -0.5f;
	vertices[6 * 9 + 0] =  -0.5f;		vertices[6 * 9 + 1] =  0.5f;		vertices[6 * 9 + 2] =  -0.5f;
	vertices[7 * 9 + 0] =  0.5f;		vertices[7 * 9 + 1] =  0.5f;		vertices[7 * 9 + 2] =  -0.5f;

	// Normals
	vertices[4 * 9 + 6] = 0.0f;			vertices[4 * 9 + 7] = 0.0f;			vertices[4 * 9 + 8] = -1.0f;
	vertices[5 * 9 + 6] = 0.0f;			vertices[5 * 9 + 7] = 0.0f;			vertices[5 * 9 + 8] = -1.0f;
	vertices[6 * 9 + 6] = 0.0f;			vertices[6 * 9 + 7] = 0.0f;			vertices[6 * 9 + 8] = -1.0f;
	vertices[7 * 9 + 6] = 0.0f;			vertices[7 * 9 + 7] = 0.0f;			vertices[7 * 9 + 8] = -1.0f;

	// Left
	// Colors
	vertices[8 * 9 + 0] =  -0.5f;		vertices[8 * 9 + 1] =  -0.5f;		vertices[8 * 9 + 2] =  -0.5f;
	vertices[9 * 9 + 0] =  -0.5f;		vertices[9 * 9 + 1] =  -0.5f;		vertices[9 * 9 + 2] =  0.5f;
	vertices[10 * 9 + 0] = -0.5f;		vertices[10 * 9 + 1] = 0.5f;		vertices[10 * 9 + 2] = -0.5f;
	vertices[11 * 9 + 0] = -0.5f;		vertices[11 * 9 + 1] = 0.5f;		vertices[11 * 9 + 2] = 0.5f;

	// Normals
	vertices[8 * 9 + 6] = -1.0f;		vertices[8 * 9 + 7] = 0.0f;			vertices[8 * 9 + 8] = 0.0f;
	vertices[9 * 9 + 6] = -1.0f;		vertices[9 * 9 + 7] = 0.0f;			vertices[9 * 9 + 8] = 0.0f;
	vertices[10 * 9 + 6] = -1.0f;		vertices[10 * 9 + 7] = 0.0f;		vertices[10 * 9 + 8] = 0.0f;
	vertices[11 * 9 + 6] = -1.0f;		vertices[11 * 9 + 7] = 0.0f;		vertices[11 * 9 + 8] = 0.0f;

	// Right
	// Colors
	vertices[12 * 9 + 0] = 0.5f;		vertices[12 * 9 + 1] = -0.5f;		vertices[12 * 9 + 2] = -0.5f;
	vertices[13 * 9 + 0] = 0.5f;		vertices[13 * 9 + 1] = -0.5f;		vertices[13 * 9 + 2] = 0.5f;
	vertices[14 * 9 + 0] = 0.5f;		vertices[14 * 9 + 1] = 0.5f;		vertices[14 * 9 + 2] = -0.5f;
	vertices[15 * 9 + 0] = 0.5f;		vertices[15 * 9 + 1] = 0.5f;		vertices[15 * 9 + 2] = 0.5f;

	// Normals
	vertices[12 * 9 + 6] = 1.0f;		vertices[12 * 9 + 7] = 0.0f;		vertices[12 * 9 + 8] = 0.0f;
	vertices[13 * 9 + 6] = 1.0f;		vertices[13 * 9 + 7] = 0.0f;		vertices[13 * 9 + 8] = 0.0f;
	vertices[14 * 9 + 6] = 1.0f;		vertices[14 * 9 + 7] = 0.0f;		vertices[14 * 9 + 8] = 0.0f;
	vertices[15 * 9 + 6] = 1.0f;		vertices[15 * 9 + 7] = 0.0f;		vertices[15 * 9 + 8] = 0.0f;

	// Bottom
	// Colors
	vertices[16 * 9 + 0] = -0.5f;		vertices[16 * 9 + 1] = -0.5f;		vertices[16 * 9 + 2] = -0.5f;
	vertices[17 * 9 + 0] = 0.5f;		vertices[17 * 9 + 1] = -0.5f;		vertices[17 * 9 + 2] = -0.5f;
	vertices[18 * 9 + 0] = -0.5f;		vertices[18 * 9 + 1] = -0.5f;		vertices[18 * 9 + 2] = 0.5f;
	vertices[19 * 9 + 0] = 0.5f;		vertices[19 * 9 + 1] = -0.5f;		vertices[19 * 9 + 2] = 0.5f;

	// Normals
	vertices[16 * 9 + 6] = 0.0f;		vertices[16 * 9 + 7] = -1.0f;		vertices[16 * 9 + 8] = 0.0f;
	vertices[17 * 9 + 6] = 0.0f;		vertices[17 * 9 + 7] = -1.0f;		vertices[17 * 9 + 8] = 0.0f;
	vertices[18 * 9 + 6] = 0.0f;		vertices[18 * 9 + 7] = -1.0f;		vertices[18 * 9 + 8] = 0.0f;
	vertices[19 * 9 + 6] = 0.0f;		vertices[19 * 9 + 7] = -1.0f;		vertices[19 * 9 + 8] = 0.0f;

	// Top
	// Colors
	vertices[20 * 9 + 0] = -0.5f;		vertices[20 * 9 + 1] = 0.5f;		vertices[20 * 9 + 2] = -0.5f;
	vertices[21 * 9 + 0] = 0.5f;		vertices[21 * 9 + 1] = 0.5f;		vertices[21 * 9 + 2] = -0.5f;
	vertices[22 * 9 + 0] = -0.5f;		vertices[22 * 9 + 1] = 0.5f;		vertices[22 * 9 + 2] = 0.5f;
	vertices[23 * 9 + 0] = 0.5f;		vertices[23 * 9 + 1] = 0.5f;		vertices[23 * 9 + 2] = 0.5f;

	// Normals
	vertices[20 * 9 + 6] = 0.0f;		vertices[20 * 9 + 7] = 1.0f;		vertices[20 * 9 + 8] = 0.0f;
	vertices[21 * 9 + 6] = 0.0f;		vertices[21 * 9 + 7] = 1.0f;		vertices[21 * 9 + 8] = 0.0f;
	vertices[22 * 9 + 6] = 0.0f;		vertices[22 * 9 + 7] = 1.0f;		vertices[22 * 9 + 8] = 0.0f;
	vertices[23 * 9 + 6] = 0.0f;		vertices[23 * 9 + 7] = 1.0f;		vertices[23 * 9 + 8] = 0.0f;

	for (size_t i = 0; i < 24; i++)
	{
		vertices[i * 9 + 3] = ((double)rand() / (RAND_MAX));
		vertices[i * 9 + 4] = ((double)rand() / (RAND_MAX));
		vertices[i * 9 + 5] = ((double)rand() / (RAND_MAX));
	}

	indices2[0] = 0;	indices2[1] = 1;	indices2[2] = 2;
	indices2[3] = 1;	indices2[4] = 2;	indices2[5] = 3;

	indices2[6] = 4;	indices2[7] = 5;	indices2[8] = 6;
	indices2[9] = 5;	indices2[10] = 6;	indices2[11] = 7;

	indices2[12] = 8;	indices2[13] = 9;	indices2[14] = 10;
	indices2[15] = 9;	indices2[16] = 10;	indices2[17] = 11;

	indices2[18] = 12;	indices2[19] = 13;	indices2[20] = 14;
	indices2[21] = 13;	indices2[22] = 14;	indices2[23] = 15;


	indices2[24] = 16;	indices2[25] = 17;	indices2[26] = 18;
	indices2[27] = 17;	indices2[28] = 18;	indices2[29] = 19;

	indices2[30] = 20;	indices2[31] = 21;	indices2[32] = 22;
	indices2[33] = 21;	indices2[34] = 22;	indices2[35] = 23;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * 9 * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * sizeof(unsigned int), indices2, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
}

void Mesh::CreateSphereMesh(int resolutionX, int resolutionY) {

	cylinder = true;

	noVertices = resolutionX * resolutionY + 2;
	
	//noIndices = (resolutionX - 1) * (resolutionY - 1);

	//noIndices = resolutionX * (resolutionY + 1); //2 * (resolutionX - 1) + 2 * (resolutionY - 1) * (resolutionX - 1);

	noIndices = 2 * resolutionX + 2 * resolutionX * (resolutionY - 1);

	vertexSize = 9;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices2 = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	// Two poles are first and last vertex
	vertices[0] = 0.0f;		
	vertices[1] = -0.5f;		
	vertices[2] = 0.0f;
	
	vertices[(noVertices - 1) * vertexSize + 0] = 0.0f;		
	vertices[(noVertices - 1) * vertexSize + 1] = 0.5f;
	vertices[(noVertices - 1) * vertexSize + 2] = 0.0f;

	std::cout << "<SPHERE>" << std::endl;
	int vertexIndex = 1;

	float yPos = -0.5f;
	for (int y = 0; y < resolutionY; y++)
	{
		float radius = 0.5f;
		yPos += 1.0 / (resolutionY + 1);

		std::cout << yPos << std::endl;

		for (int x = 0; x < resolutionX; x++, vertexIndex++)
		{

			float angle = (360.0f / resolutionX) * (x - 1);
			//std::cout << angle << std::endl;

			vertices[vertexIndex * 9 + 0] = sin(glm::radians(angle)) * radius;
			vertices[vertexIndex * 9 + 1] = yPos;
			vertices[vertexIndex * 9 + 2] = cos(glm::radians(angle)) * radius;

			std::cout << vertexIndex << std::endl;

		}

		std::cout << "----------------" << std::endl;

	}

	for (size_t i = 0; i < noVertices; i++)
	{
		// Colors
		vertices[i * vertexSize + 3] = ((double)rand() / (RAND_MAX));
		vertices[i * vertexSize + 4] = ((double)rand() / (RAND_MAX));
		vertices[i * vertexSize + 5] = ((double)rand() / (RAND_MAX));

		// Normals
		vertices[i * vertexSize + 6] = 0.0f;
		vertices[i * vertexSize + 7] = 0.0f;
		vertices[i * vertexSize + 8] = 0.0f;
	}


	// Indices
	for (int i = 0; i < noIndices * 3; i++)
	{
		indices2[i] = 0;
	}

	// South pole
	size_t i;
	for (i = 0; i < resolutionX - 1; i++)
	{
		indices2[i * 3 + 0] = 0;
		indices2[i * 3 + 1] = i + 1;
		indices2[i * 3 + 2] = i + 2;
	}
	
	indices2[i * 3 + 0] = 0;
	indices2[i * 3 + 1] = i + 1;
	indices2[i * 3 + 2] = 1;

	std::cout << "||||||||||||||||||||||||||||||||||" << std::endl;

	int triangleIndex = resolutionX;

	// Rings
	for (size_t y = 0; y < resolutionY - 1; y++)
	{
		int vertexIndex = y * resolutionX + 1;
		//int triangleIndex = y * resolutionX;

		for (size_t x = 0; x < resolutionX - 1; x++, triangleIndex += 2, vertexIndex ++)
		{

			indices2[triangleIndex * 3 + 0] = vertexIndex;
			indices2[triangleIndex * 3 + 1] = vertexIndex + resolutionX;
			indices2[triangleIndex * 3 + 2] = vertexIndex + resolutionX + 1;

			indices2[(triangleIndex + 1) * 3 + 0] = vertexIndex;
			indices2[(triangleIndex + 1) * 3 + 1] = vertexIndex + resolutionX + 1;
			indices2[(triangleIndex + 1) * 3 + 2] = vertexIndex + 1;

			std::cout << "	" << triangleIndex << " | " << vertexIndex << " " << vertexIndex + resolutionX << " " << vertexIndex + resolutionX + 1 << std::endl;
			std::cout << "	" << triangleIndex + 1 << " | " << vertexIndex << " " << vertexIndex + resolutionX + 1 << " " << vertexIndex + 1 << std::endl;
		}

		std::cout << "	" << triangleIndex << " | " << vertexIndex << " " << vertexIndex + resolutionX << " " << vertexIndex + 1 << std::endl;
		std::cout << "	" << triangleIndex + 1 << " | " << vertexIndex << " " << vertexIndex + 1 << " " << vertexIndex - resolutionX + 1 << std::endl;

		std::cout << "------" << std::endl;


		indices2[triangleIndex * 3 + 0] = vertexIndex;
		indices2[triangleIndex * 3 + 1] = vertexIndex + resolutionX;
		indices2[triangleIndex * 3 + 2] = vertexIndex + 1;

		indices2[(triangleIndex + 1) * 3 + 0] = vertexIndex;
		indices2[(triangleIndex + 1) * 3 + 1] = vertexIndex + 1;
		indices2[(triangleIndex + 1) * 3 + 2] = vertexIndex - resolutionX + 1;

		triangleIndex += 2;
	}

	std::cout << "||||||||||||||||||||||||||||||||||" << std::endl;

	// North pole
	vertexIndex = noVertices - 1 - resolutionX;
	for (size_t x = 0; x < resolutionX - 1; x++, triangleIndex++, vertexIndex++)
	{

		indices2[triangleIndex * 3 + 0] = vertexIndex;
		indices2[triangleIndex * 3 + 1] = noVertices - 1;
		indices2[triangleIndex * 3 + 2] = vertexIndex + 1;

		std::cout << triangleIndex << std::endl;
		std::cout << "	" << vertexIndex << " " << noVertices - 1 << " " << vertexIndex + 1 << " " << std::endl;
	}

	std::cout << triangleIndex << std::endl;
	std::cout << "	" << vertexIndex << " " << noVertices - 1 << " " << vertexIndex - resolutionX + 1 << std::endl;

	indices2[triangleIndex * 3 + 0] = vertexIndex;
	indices2[triangleIndex * 3 + 1] = noVertices - 1;
	indices2[triangleIndex * 3 + 2] = vertexIndex - resolutionX + 1;

	std::cout << "<\SPHERE>" << std::endl;


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * sizeof(unsigned int), indices2, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
}

void Mesh::CreateCylinderMesh(int resolution) {

	cylinder = true;

	int nr = 2;

	noVertices = nr * (resolution + 1);
	noIndices = nr * resolution * 3;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices2 = (unsigned int*)malloc(noIndices * sizeof(unsigned int));

	for (int q = 0; q < noIndices; q++)
	{
		indices2[q] = 0;
	}
	for (int q = 0; q < noVertices * 9; q++)
	{
		vertices[q] = 0;
	}

	int i = 0;
	int j = 0;

	for (int k = 0; k < nr; k++)
	{

		i = k * (resolution + 1);

		// Center vertex
		vertices[i * 9 + 0] = 0; vertices[i * 9 + 1] = -1 + k; vertices[i * 9 + 2] = 0;
		vertices[i * 9 + 3] = 1; vertices[i * 9 + 4] = 0; vertices[i * 9 + 5] = 0;
		vertices[i * 9 + 6] = 0; vertices[i * 9 + 7] = 0; vertices[i * 9 + 8] = 0;

		for (i = i + 1; i < (k + 1) * (resolution + 1); i++)
		{
			float angle = (360.0f / resolution) * (i - 1 - k * (resolution + 1));

			vertices[i * 9 + 0] = sin(glm::radians(angle));
			vertices[i * 9 + 1] = -1;
			vertices[i * 9 + 2] = cos(glm::radians(angle));

			vertices[i * 9 + 3] = 0;			vertices[i * 9 + 4] = 0;	vertices[i * 9 + 5] = 0;
			vertices[i * 9 + 6] = 0;			vertices[i * 9 + 7] = 1;	vertices[i * 9 + 8] = 0;

			//std::cout << "    " << vertices[i * 9 + 0] << " " << vertices[i * 9 + 1] << " " << vertices[i * 9 + 2] << std::endl;
		}

		//std::cout << "--------------" << std::endl;

		int offset = k * resolution;
		int vertexOffset = k * (resolution + 1);

		for (j = offset; j < offset + resolution - 1; j++)
		{
			indices2[j * 3 + 0] = 0 + vertexOffset;
			indices2[j * 3 + 1] = (j - offset) + 1 + vertexOffset;
			indices2[j * 3 + 2] = (j - offset) + 2 + vertexOffset;

			//std::cout << j * 3 << " " << j * 3 + 1 << " " << j * 3 + 2 << " - " << indices2[j * 3 + 0] << " " << indices2[j * 3 + 1] << " " << indices2[j * 3 + 2] << std::endl;
		}

		indices2[j * 3 + 0] = 0 + vertexOffset;
		indices2[j * 3 + 1] = (j - offset) + 1 + vertexOffset;
		indices2[j * 3 + 2] = 1 + vertexOffset;

		//std::cout << j * 3 << " " << j * 3 + 1 << " " << j * 3 + 2 << " - " << indices2[j * 3 + 0] << " " << indices2[j * 3 + 1] << " " << indices2[j * 3 + 2] << std::endl;
	}

	// Colors
	for (size_t i = 0; i < 2 * (resolution + 1); i++)
	{
		vertices[i * vertexSize + 3] = ((double)rand() / (RAND_MAX));
		vertices[i * vertexSize + 4] = ((double)rand() / (RAND_MAX));
		vertices[i * vertexSize + 5] = ((double)rand() / (RAND_MAX));
	}


	// Normals
	for (size_t i = 0; i < resolution + 1; i++)
	{
		vertices[i * vertexSize + 6] = 0.0f;
		vertices[i * vertexSize + 7] = -1.0f;
		vertices[i * vertexSize + 8] = 0.0f;
	}

	vertices[i * vertexSize + 6] = 0.0f;
	vertices[i * vertexSize + 7] = 1.0f;
	vertices[i * vertexSize + 8] = 0.0f;

	/*
	for (size_t i = resolution + 2; i < 2 * (resolution + 1); i++)
	{
		glm::vec3 normal = glm::normalize(glm::vec3(
			vertices[i * vertexSize + 0] - vertices[0],
			vertices[i * vertexSize + 1] - vertices[1],
			vertices[i * vertexSize + 2] - vertices[2]
		));


		vertices[i * vertexSize + 6] = normal.x;
		vertices[i * vertexSize + 7] = normal.y;
		vertices[i * vertexSize + 8] = normal.z;
	}
	*/

	/*
	// Normals
	for (size_t i = resolution + 1; i < (2 * resolution + 1); i++)
	{
		vertices[i * vertexSize + 6] = 0.0f;
		vertices[i * vertexSize + 7] = -1.0f;
		vertices[i * vertexSize + 8] = 0.0f;
	}
	*/

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * sizeof(unsigned int), indices2, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
}

void Mesh::CreateConeMesh() {

}

void Mesh::CreateQuadMesh() {
	cylinder = true;

	noVertices = 4;
	noIndices = 6;

	vertices = (float*)malloc(noVertices * 9 * sizeof(float));
	indices2 = (unsigned int*)malloc(noIndices * sizeof(unsigned int));

	vertices[0 * vertexSize + 0] = -0.5f;	vertices[0 * vertexSize + 1] = -0.5f;	vertices[0 * vertexSize + 2] = 0;
	vertices[0 * vertexSize + 3] = 0.0f;	vertices[0 * vertexSize + 4] = 0.0f;	vertices[0 * vertexSize + 5] = 0.0f;
	vertices[0 * vertexSize + 6] = 0;		vertices[0 * vertexSize + 7] = 0;		vertices[0 * vertexSize + 8] = 0;

	vertices[1 * vertexSize + 0] = 0.5f;	vertices[1 * vertexSize + 1] = -0.5f;	vertices[1 * vertexSize + 2] = 0;
	vertices[1 * vertexSize + 3] = 1.0f;	vertices[1 * vertexSize + 4] = 0.0f;	vertices[1 * vertexSize + 5] = 0.0f;
	vertices[1 * vertexSize + 6] = 0;		vertices[1 * vertexSize + 7] = 0;		vertices[1 * vertexSize + 8] = 0;

	vertices[2 * vertexSize + 0] = -0.5f;	vertices[2 * vertexSize + 1] = 0.5f;	vertices[2 * vertexSize + 2] = 0;
	vertices[2 * vertexSize + 3] = 0.0f;	vertices[2 * vertexSize + 4] = 1.0f;	vertices[2 * vertexSize + 5] = 0.0f;
	vertices[2 * vertexSize + 6] = 0;		vertices[2 * vertexSize + 7] = 0;		vertices[2 * vertexSize + 8] = 0;

	vertices[3 * vertexSize + 0] = 0.5f;	vertices[3 * vertexSize + 1] = 0.5f;	vertices[3 * vertexSize + 2] = 0;
	vertices[3 * vertexSize + 3] = 0.0f;	vertices[3 * vertexSize + 4] = 0.0f;	vertices[3 * vertexSize + 5] = 1.0f;
	vertices[3 * vertexSize + 6] = 0;		vertices[3 * vertexSize + 7] = 0;		vertices[3 * vertexSize + 8] = 0;


	indices2[0] = 0;	indices2[1] = 1;	indices2[2] = 2;
	indices2[3] = 1;	indices2[4] = 2;	indices2[5] = 3;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * 9 * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * sizeof(unsigned int), indices2, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
}


void Mesh::AddTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3) {
}

void Mesh::AddTriangleColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3) {

}

void Mesh::AddTriangleColor(glm::vec3 col) {

}

void Mesh::AddQuad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4) {

}

void Mesh::AddQuadColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3, glm::vec3 col4) {

}

void Mesh::AddQuadColor(glm::vec3 col) {

}

void Mesh::Flush() {
	noVertices = 36;
}

void Mesh::AddVertex(float* attributes) {

	// Check if has correct length

	if (sizeof(attributes) != GetVertexSize()) {
		std::cout << "WTF" << std::endl;
	}


}

int Mesh::GetVertexSize() {
	int size = sizeof(glm::vec3);

	if (hasNormals == true) {
		std::cout << "hasNormmals" << std::endl;
		size += sizeof(glm::vec3);
	}
	if (hasTangents == true) {
		std::cout << "hasTangents" << std::endl;
		size += sizeof(glm::vec3);
	}
	if (hasColors == true) {
		std::cout << "hasColors" << std::endl;
		size += sizeof(glm::vec3);
	}
	if (hasUvs == true) {
		std::cout << "hasUvs" << std::endl;
		size += sizeof(glm::vec2);
	}
	if (hasUvs2 == true) {
		std::cout << "hasUvs2" << std::endl;
		size += sizeof(glm::vec2);
	}

	return size;
}
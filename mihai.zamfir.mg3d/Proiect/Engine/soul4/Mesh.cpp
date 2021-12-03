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

	return;

	//CreateMesh();
	//return;

	CreateSphereMesh(8);

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.94f, 0.17f, 0.33f,  0.0f, 0.0f, -1.0f, // 0, 0, 1
		 0.5f, -0.5f, -0.5f,  0.37f, 0.00f, 0.53f,  0.0f, 0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.25f, 0.85f, 0.38f,  0.0f, 0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.29f, 0.70f,  0.0f, 0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.98f, 0.38f, 0.18f,  0.0f, 0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.11f, 0.50f, 0.87f,  0.0f, 0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.79f, 0.09f, 0.11f,  0.0f, 0.0f, 1.0f, // 0, 0, -1
		 0.5f, -0.5f,  0.5f,  0.34f, 0.00f, 0.91f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.44f, 0.98f, 0.63f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.39f, 0.50f, 0.20f,  0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.41f, 0.52f, 0.63f,  0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.47f, 0.35f, 0.42f,  0.0f, 0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  0.58f, 0.74f, 0.91f,  -1.0f, 0.0f, 0.0f, // -1, 0, 0
		-0.5f,  0.5f, -0.5f,  0.61f, 0.88f, 0.60f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.95f, 0.74f, 0.83f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.23f, 0.56f, 0.75f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.15f, 0.93f, 0.42f,  -1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.15f, 0.66f, 0.22f,  -1.0f, 0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  0.35f, 0.83f, 0.38f,  1.0f, 0.0f, 0.0f, // 1, 0, 0
		 0.5f,  0.5f, -0.5f,  0.30f, 0.76f, 0.31f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.86f, 0.30f, 0.88f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.90f, 0.00f, 0.02f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.59f, 0.72f, 0.82f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.84f, 0.41f, 0.96f,  1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.46f, 0.67f, 0.04f,  0.0f, -1.0f, 0.0f, // -1, 0, 0
		 0.5f, -0.5f, -0.5f,  0.84f, 0.24f, 0.78f,  0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.93f, 0.15f, 0.93f,  0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.65f, 0.27f, 0.24f,  0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.80f, 0.08f, 0.79f,  0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.88f, 0.77f, 0.44f,  0.0f, -1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,  0.53f, 0.96f, 0.82f,  0.0f, 1.0f, 0.0f, // 1, 0, 0
		 0.5f,  0.5f, -0.5f,  0.03f, 0.60f, 0.51f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.95f, 0.14f, 0.94f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.96f, 0.53f, 0.31f,  0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.59f, 0.71f, 0.34f,  0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.46f, 0.69f, 0.81f,  0.0f, 1.0f, 0.0f
	};

	//trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	//trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

	unsigned int indices[] = { // note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3 // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	/*
	// uvs
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	*/

	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
}

Mesh::~Mesh() {}

void Mesh::Draw() {

	glBindVertexArray(VAO);
	
	if (cylinder == false) {
		//std::cout << "CUBE" << std::endl;
		glDrawArrays(GL_TRIANGLES, 0, noVertices);//36);
	}
	else {
		//std::cout << "CYLINDER" << std::endl;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, noIndices, GL_UNSIGNED_INT, 0);
	}

	//std::cout << "-----------------" << std::endl;

	//glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, 4, GL_UNSIGNED_INT, indices2);
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

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.94f, 0.17f, 0.33f,  0.0f, 0.0f, -1.0f, // 0, 0, 1
		 0.5f, -0.5f, -0.5f,  0.37f, 0.00f, 0.53f,  0.0f, 0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.25f, 0.85f, 0.38f,  0.0f, 0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.29f, 0.70f,  0.0f, 0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.98f, 0.38f, 0.18f,  0.0f, 0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.11f, 0.50f, 0.87f,  0.0f, 0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.79f, 0.09f, 0.11f,  0.0f, 0.0f, 1.0f, // 0, 0, -1
		 0.5f, -0.5f,  0.5f,  0.34f, 0.00f, 0.91f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.44f, 0.98f, 0.63f,  0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.39f, 0.50f, 0.20f,  0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.41f, 0.52f, 0.63f,  0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.47f, 0.35f, 0.42f,  0.0f, 0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,  0.58f, 0.74f, 0.91f,  -1.0f, 0.0f, 0.0f, // -1, 0, 0
		-0.5f,  0.5f, -0.5f,  0.61f, 0.88f, 0.60f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.95f, 0.74f, 0.83f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.23f, 0.56f, 0.75f,  -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.15f, 0.93f, 0.42f,  -1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.15f, 0.66f, 0.22f,  -1.0f, 0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  0.35f, 0.83f, 0.38f,  1.0f, 0.0f, 0.0f, // 1, 0, 0
		 0.5f,  0.5f, -0.5f,  0.30f, 0.76f, 0.31f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.86f, 0.30f, 0.88f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.90f, 0.00f, 0.02f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.59f, 0.72f, 0.82f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.84f, 0.41f, 0.96f,  1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.46f, 0.67f, 0.04f,  0.0f, -1.0f, 0.0f, // -1, 0, 0
		 0.5f, -0.5f, -0.5f,  0.84f, 0.24f, 0.78f,  0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.93f, 0.15f, 0.93f,  0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.65f, 0.27f, 0.24f,  0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.80f, 0.08f, 0.79f,  0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.88f, 0.77f, 0.44f,  0.0f, -1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,  0.53f, 0.96f, 0.82f,  0.0f, 1.0f, 0.0f, // 1, 0, 0
		 0.5f,  0.5f, -0.5f,  0.03f, 0.60f, 0.51f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.95f, 0.14f, 0.94f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.96f, 0.53f, 0.31f,  0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.59f, 0.71f, 0.34f,  0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.46f, 0.69f, 0.81f,  0.0f, 1.0f, 0.0f
	};


	//trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	//trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

	unsigned int indices[] = { // note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3 // second triangle
	};

	//std::cout << "WTF " << sizeof(vertices) << " " << sizeof(indices) << " " << sizeof(float) << std::endl;
	//std::cout << "WTF " << sizeof(vertices) << " " << sizeof(indices) << " " << sizeof(float) << std::endl;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	/*
	// uvs
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	*/

	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	noVertices = 4;
	//vertices = (float*)malloc(9 * noVertices * sizeof(float));

	//	int xSize = 2, ySize = 2, zSize = 2;

	// Back

	// Top 

	// Bottom

	// Left

	// Right

}

void Mesh::CreateSphereMesh(int resolutionX, int resolutionY) {

	
}

void Mesh::CreateCylinderMesh(int resolution) {

	cylinder = true;

	int nr = 2;

	noVertices = nr * (resolution + 1);
	noIndices = nr * resolution * 3;

	vertices = (float*)malloc(noVertices * 9 * sizeof(float));
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

			std::cout << i << " " << angle << std::endl;

			vertices[i * 9 + 0] = sin(glm::radians(angle));
			vertices[i * 9 + 1] = -1;
			vertices[i * 9 + 2] = cos(glm::radians(angle));

			vertices[i * 9 + 3] = 0;			vertices[i * 9 + 4] = 0;	vertices[i * 9 + 5] = 0;
			vertices[i * 9 + 6] = 0;			vertices[i * 9 + 7] = 1;	vertices[i * 9 + 8] = 0;

			std::cout << "    " << vertices[i * 9 + 0] << " " << vertices[i * 9 + 1] << " " << vertices[i * 9 + 2] << std::endl;
		}

		std::cout << "--------------" << std::endl;

		int offset = k * resolution;
		int vertexOffset = k * (resolution + 1);

		for (j = offset; j < offset + resolution - 1; j++)
		{
			indices2[j * 3 + 0] = 0 + vertexOffset;
			indices2[j * 3 + 1] = (j - offset) + 1 + vertexOffset;
			indices2[j * 3 + 2] = (j - offset) + 2 + vertexOffset;

			std::cout << j * 3 << " " << j * 3 + 1 << " " << j * 3 + 2 << " - " << indices2[j * 3 + 0] << " " << indices2[j * 3 + 1] << " " << indices2[j * 3 + 2] << std::endl;
		}

		indices2[j * 3 + 0] = 0 + vertexOffset;
		indices2[j * 3 + 1] = (j - offset) + 1 + vertexOffset;
		indices2[j * 3 + 2] = 1 + vertexOffset;

		std::cout << j * 3 << " " << j * 3 + 1 << " " << j * 3 + 2 << " - " << indices2[j * 3 + 0] << " " << indices2[j * 3 + 1] << " " << indices2[j * 3 + 2] << std::endl;
	}

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

void Mesh::CreateConeMesh() {

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
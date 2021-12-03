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

	/*
	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f
	};
	*/

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.34f, 0.67f, 0.41f,
		 0.5f, -0.5f, -0.5f,  0.24f, 0.69f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.62f, 0.58f, 0.78f,
		 0.5f,  0.5f, -0.5f,  0.45f, 0.05f, 0.64f,
		-0.5f,  0.5f, -0.5f,  0.61f, 0.27f, 0.81f,
		-0.5f, -0.5f, -0.5f,  0.42f, 0.95f, 0.91f,

		-0.5f, -0.5f,  0.5f,  0.91f, 0.36f, 0.27f,
		 0.5f, -0.5f,  0.5f,  0.53f, 0.02f, 0.04f,
		 0.5f,  0.5f,  0.5f,  0.21f, 0.82f, 0.92f,
		 0.5f,  0.5f,  0.5f,  0.95f, 0.18f, 0.16f,
		-0.5f,  0.5f,  0.5f,  0.71f, 0.26f, 0.47f,
		-0.5f, -0.5f,  0.5f,  0.12f, 0.69f, 0.38f,

		-0.5f,  0.5f,  0.5f,  0.35f, 0.99f, 0.67f,
		-0.5f,  0.5f, -0.5f,  0.11f, 0.03f, 0.94f,
		-0.5f, -0.5f, -0.5f,  0.73f, 0.33f, 0.22f,
		-0.5f, -0.5f, -0.5f,  0.11f, 0.41f, 0.64f,
		-0.5f, -0.5f,  0.5f,  0.47f, 0.68f, 0.53f,
		-0.5f,  0.5f,  0.5f,  0.57f, 0.62f, 0.44f,

		 0.5f,  0.5f,  0.5f,  0.23f, 0.59f, 0.37f,
		 0.5f,  0.5f, -0.5f,  0.78f, 0.29f, 0.41f,
		 0.5f, -0.5f, -0.5f,  0.90f, 0.35f, 0.16f,
		 0.5f, -0.5f, -0.5f,  0.06f, 0.88f, 0.42f,
		 0.5f, -0.5f,  0.5f,  0.64f, 0.42f, 0.40f,
		 0.5f,  0.5f,  0.5f,  0.05f, 0.46f, 0.48f,

		-0.5f, -0.5f, -0.5f,  0.70f, 0.29f, 0.90f,
		 0.5f, -0.5f, -0.5f,  0.01f, 0.06f, 0.5f,
		 0.5f, -0.5f,  0.5f,  0.29f, 0.48f, 0.93f,
		 0.5f, -0.5f,  0.5f,  0.54f, 0.84f, 0.23f,
		-0.5f, -0.5f,  0.5f,  0.66f, 0.40f, 0.56f,
		-0.5f, -0.5f, -0.5f,  0.08f, 0.31f, 0.76f,

		-0.5f,  0.5f, -0.5f,  0.26f, 0.39f, 0.44f,
		 0.5f,  0.5f, -0.5f,  0.38f, 0.37f, 0.23f,
		 0.5f,  0.5f,  0.5f,  0.29f, 0.82f, 0.18f,
		 0.5f,  0.5f,  0.5f,  0.15f, 0.33f, 0.41f,
		-0.5f,  0.5f,  0.5f,  0.04f, 0.58f, 0.39f,
		-0.5f,  0.5f, -0.5f,  0.06f, 0.77f, 0.30f,
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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

	
	glDrawArrays(GL_TRIANGLES, 0, 36);

	//glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Mesh::CreateMesh() {

	/*
	float vertices[] = {
		// positions // colors // texture coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
	};

	unsigned int indices[] = { // note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3 // second triangle
	};

	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);

	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// uvs
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);

	*/
	Flush();
}

void Mesh::AddTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3) {


	//gameObjects.push_back(GameObject("Mihai"));


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

	/*
		std::list<glm::vec3> positions;
		std::list<glm::vec3> normals;
		std::list<glm::vec3> tangents;
		std::list<glm::vec3> colors;
		std::list<glm::vec2> uvs2;

		std::list<glm::vec3> indices;
	*/

	//std::cout << "Positions " << positions.size() << std::endl;

	/*
	float vertices[] = {
		// positions // colors // texture coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
	};

	unsigned int indices[] = { // note that we start from 0!
		0, 1, 3, // first triangle
		1, 2, 3 // second triangle
	};
	*/

	//float* vertices()
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
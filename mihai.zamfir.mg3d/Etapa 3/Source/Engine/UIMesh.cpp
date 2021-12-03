#include "UIMesh.h"

#include <vector>
#include <iostream>

UIMesh::UIMesh() {

	//: text, meniuri, butoane, liste, edit boxes


}

UIMesh::~UIMesh() {

}

void UIMesh::Draw() {

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(GL_TRIANGLES, noIndices * 3, GL_UNSIGNED_INT, 0);
}

void UIMesh::CreateQuadMesh() {
	int vertexSize = 5;

	noVertices = 4;
	noIndices = 2;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));


	/*
	// Down Left Corner

	// Position
	vertices[0 * vertexSize + 0] = -1.0f;
	vertices[0 * vertexSize + 1] = -1.0f;
	vertices[0 * vertexSize + 2] = 0.0f;

	// UV
	vertices[0 * vertexSize + 3] = 0.0f;
	vertices[0 * vertexSize + 4] = 0.0f;

	// Down Right Corner

	// Position
	vertices[1 * vertexSize + 0] = 1.0f;
	vertices[1 * vertexSize + 1] = -1.0f;
	vertices[1 * vertexSize + 2] = 0.0f;

	// UV
	vertices[1 * vertexSize + 3] = 1.0f;
	vertices[1 * vertexSize + 4] = 0.0f;

	// Upper Left Corner

	// Position
	vertices[2 * vertexSize + 0] = -1.0f;
	vertices[2 * vertexSize + 1] = 1.0f;
	vertices[2 * vertexSize + 2] = 0.0f;

	// UV
	vertices[2 * vertexSize + 3] = 0.0f;
	vertices[2 * vertexSize + 4] = 1.0f;

	// Upper Right Corner

	// Position
	vertices[3 * vertexSize + 0] = 1.0f;
	vertices[3 * vertexSize + 1] = 1.0f;
	vertices[3 * vertexSize + 2] = 0.0f;

	// UV
	vertices[3 * vertexSize + 3] = 1.0f;
	vertices[3 * vertexSize + 4] = 1.0f;
	*/




	/*
	float offset = 0.0f;

	// Down Left Corner

	// Position
	vertices[0 * vertexSize + 0] = -1.0f + offset;
	vertices[0 * vertexSize + 1] = -1.0f + offset;
	vertices[0 * vertexSize + 2] = 0.0f;

	// UV
	vertices[0 * vertexSize + 3] = 0.0f;
	vertices[0 * vertexSize + 4] = 0.0f;

	// Down Right Corner

	// Position
	vertices[1 * vertexSize + 0] = 1.0f + offset;
	vertices[1 * vertexSize + 1] = -1.0f + offset;
	vertices[1 * vertexSize + 2] = 0.0f;

	// UV
	vertices[1 * vertexSize + 3] = 1.0f;
	vertices[1 * vertexSize + 4] = 0.0f;

	// Upper Left Corner

	// Position
	vertices[2 * vertexSize + 0] = -1.0f + offset;
	vertices[2 * vertexSize + 1] = 1.0f + offset;
	vertices[2 * vertexSize + 2] = 0.0f;

	// UV
	vertices[2 * vertexSize + 3] = 0.0f;
	vertices[2 * vertexSize + 4] = 1.0f;

	// Upper Right Corner

	// Position
	vertices[3 * vertexSize + 0] = 1.0f + offset;
	vertices[3 * vertexSize + 1] = 1.0f + offset;
	vertices[3 * vertexSize + 2] = 0.0f;

	// UV
	vertices[3 * vertexSize + 3] = 1.0f;
	vertices[3 * vertexSize + 4] = 1.0f;
	*/




	/*
	// Down Left Corner

	// Position
	vertices[0 * vertexSize + 0] = 0.0f;
	vertices[0 * vertexSize + 1] = 0.0f;
	vertices[0 * vertexSize + 2] = 0.0f;

	// UV
	vertices[0 * vertexSize + 3] = 0.0f;
	vertices[0 * vertexSize + 4] = 0.0f;

	// Down Right Corner

	// Position
	vertices[1 * vertexSize + 0] = 1.0f;
	vertices[1 * vertexSize + 1] = 0.0f;
	vertices[1 * vertexSize + 2] = 0.0f;

	// UV
	vertices[1 * vertexSize + 3] = 1.0f;
	vertices[1 * vertexSize + 4] = 0.0f;

	// Upper Left Corner

	// Position
	vertices[2 * vertexSize + 0] = 0.0f;
	vertices[2 * vertexSize + 1] = 1.0f;
	vertices[2 * vertexSize + 2] = 0.0f;

	// UV
	vertices[2 * vertexSize + 3] = 0.0f;
	vertices[2 * vertexSize + 4] = 1.0f;

	// Upper Right Corner

	// Position
	vertices[3 * vertexSize + 0] = 1.0f;
	vertices[3 * vertexSize + 1] = 1.0f;
	vertices[3 * vertexSize + 2] = 0.0f;

	// UV
	vertices[3 * vertexSize + 3] = 1.0f;
	vertices[3 * vertexSize + 4] = 1.0f;
	*/




	glm::ivec2 resolution = ResourceManager::GetInstance()->GetResolution();
	std::cout << "UIMesh " << resolution << std::endl;

	// Down Left Corner

	// Position
	vertices[0 * vertexSize + 0] = 0.0f;
	vertices[0 * vertexSize + 1] = 0.0f;
	vertices[0 * vertexSize + 2] = 0.0f;

	// UV
	vertices[0 * vertexSize + 3] = 0.0f;
	vertices[0 * vertexSize + 4] = 0.0f;

	// Down Right Corner

	// Position
	vertices[1 * vertexSize + 0] = resolution.x;
	vertices[1 * vertexSize + 1] = 0.0f;
	vertices[1 * vertexSize + 2] = 0.0f;

	// UV
	vertices[1 * vertexSize + 3] = 1.0f;
	vertices[1 * vertexSize + 4] = 0.0f;

	// Upper Left Corner

	// Position
	vertices[2 * vertexSize + 0] = 0.0f;
	vertices[2 * vertexSize + 1] = resolution.y;
	vertices[2 * vertexSize + 2] = 0.0f;

	// UV
	vertices[2 * vertexSize + 3] = 0.0f;
	vertices[2 * vertexSize + 4] = 1.0f;

	// Upper Right Corner

	// Position
	vertices[3 * vertexSize + 0] = resolution.x;
	vertices[3 * vertexSize + 1] = resolution.y;
	vertices[3 * vertexSize + 2] = 0.0f;

	// UV
	vertices[3 * vertexSize + 3] = 1.0f;
	vertices[3 * vertexSize + 4] = 1.0f;


	// Triangles
	indices[0 * 3 + 0] = 0;
	indices[0 * 3 + 1] = 1;
	indices[0 * 3 + 2] = 2;

	indices[1 * 3 + 0] = 1;
	indices[1 * 3 + 1] = 3;
	indices[1 * 3 + 2] = 2;

	bind();
}

void UIMesh::bind() {

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// uv attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(VAO);

}
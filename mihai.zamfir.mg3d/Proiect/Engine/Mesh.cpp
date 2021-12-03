#include "Mesh.h"

#include <vector>
#include <iostream>

Mesh::Mesh() {
	vertexSize = 8;
}

Mesh::~Mesh() {}

void Mesh::Draw() {

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(GL_TRIANGLES, noIndices, GL_UNSIGNED_INT, 0);

}

void Mesh::CreateCubeMesh() {

	int faces = 6;

	noVertices = faces * 4;
	noIndices = faces * 2 * 3;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 normal = glm::vec3(0, 0, 0);
	glm::vec2 uv = glm::vec2(0, 0);

	// Front face
	normal = glm::vec3(0, 0, 1);

	position = glm::vec3(-.5f, -.5f, .5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 0);

	position = glm::vec3(.5f, -.5f, .5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 1);

	position = glm::vec3(-.5f, .5f, .5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 2);

	position = glm::vec3(.5f, .5f, .5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 3);

	// Back face
	normal = glm::vec3(0, 0, -1);

	position = glm::vec3(-.5f, -.5f, -.5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 4);

	position = glm::vec3(.5f, -.5f, -.5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 5);

	position = glm::vec3(-.5f, .5f, -.5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 6);

	position = glm::vec3(.5f, .5f, -.5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 7);

	// Left face
	normal = glm::vec3(-1, 0, 0);

	position = glm::vec3(-.5f, -.5f, -.5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 8);

	position = glm::vec3(-.5f, -.5f, .5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 9);

	position = glm::vec3(-.5f, .5f, -.5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 10);

	position = glm::vec3(-.5f, .5f, .5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 11);

	// Right face
	normal = glm::vec3(1, 0, 0);

	position = glm::vec3(.5f, -.5f, -.5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 12);

	position = glm::vec3(.5f, -.5f, .5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 13);

	position = glm::vec3(.5f, .5f, -.5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 14);

	position = glm::vec3(.5f, .5f, .5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 15);

	// Bottom face
	normal = glm::vec3(0, -1, 0);

	position = glm::vec3(-.5f, -.5f, -.5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 16);

	position = glm::vec3(.5f, -.5f, -.5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 17);

	position = glm::vec3(-.5f, -.5f, .5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 18);

	position = glm::vec3(.5f, -.5f, .5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 19);

	// Top face
	normal = glm::vec3(0, 1, 0);

	position = glm::vec3(-.5f, .5f, -.5f);
	uv = glm::vec2(0, 0);
	addVertex(&position, &normal, &uv, 20);

	position = glm::vec3(.5f, .5f, -.5f);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 21);

	position = glm::vec3(-.5f, .5f, .5f);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 22);

	position = glm::vec3(.5f, .5f, .5f);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 23);

	indices[0] = 0;	indices[1] = 1;	indices[2] = 2;
	indices[3] = 1;	indices[4] = 3;	indices[5] = 2;

	indices[6] = 4;	indices[7] = 5;	indices[8] = 6;
	indices[9] = 5;	indices[10] = 7; indices[11] = 6;

	indices[12] = 8;	indices[13] = 9;	indices[14] = 10;
	indices[15] = 9;	indices[16] = 11;	indices[17] = 10;

	indices[18] = 12;	indices[19] = 13;	indices[20] = 14;
	indices[21] = 13;	indices[22] = 15;	indices[23] = 14;

	indices[24] = 16;	indices[25] = 17;	indices[26] = 18;
	indices[27] = 17;	indices[28] = 19;	indices[29] = 18;

	indices[30] = 20;	indices[31] = 21;	indices[32] = 22;
	indices[33] = 21;	indices[34] = 23;	indices[35] = 22;

	bind();
}

void Mesh::CreateQuadMesh() {

	noVertices = 4;
	noIndices = 6;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(-1, -1, 0);
	glm::vec3 normal = glm::vec3(0, 0, 0);
	glm::vec2 uv = glm::vec2(0, 0);

	addVertex(&position, &normal, &uv, 0);
	
	position = glm::vec3(1, -1, 0);
	uv = glm::vec2(1, 0);
	addVertex(&position, &normal, &uv, 1);

	position = glm::vec3(-1, 1, 0);
	uv = glm::vec2(0, 1);
	addVertex(&position, &normal, &uv, 2);

	position = glm::vec3(1, 1, 0);
	uv = glm::vec2(1, 1);
	addVertex(&position, &normal, &uv, 3);

	indices[0] = 0;	indices[1] = 1;	indices[2] = 2;
	indices[3] = 1;	indices[4] = 3;	indices[5] = 2;

	bind();
}

void Mesh::CreateSphereMesh() {
	CreateCubeMesh();
}

void Mesh::CreateCylinderMesh() {
	CreateCubeMesh();
}

void Mesh::addVertex(glm::vec3* position, glm::vec3* normal, glm::vec2* uv, int vertexIndex) {
	vertices[vertexIndex * vertexSize + 0] = position->x;
	vertices[vertexIndex * vertexSize + 1] = position->y;
	vertices[vertexIndex * vertexSize + 2] = position->z;

	vertices[vertexIndex * vertexSize + 3] = normal->x;
	vertices[vertexIndex * vertexSize + 4] = normal->y;
	vertices[vertexIndex * vertexSize + 5] = normal->z;

	vertices[vertexIndex * vertexSize + 6] = uv->x;
	vertices[vertexIndex * vertexSize + 7] = uv->y;
}

void Mesh::bind() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, noVertices * vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, noIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// uv attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
}

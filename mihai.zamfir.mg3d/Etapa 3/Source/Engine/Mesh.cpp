#include "Mesh.h"

#include <vector>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

Mesh::Mesh() {
	vertexSize = 6;

	currVertexIndex = 0;
	currTriangleIndex = 0;
}

Mesh::~Mesh() {}

void Mesh::Draw() {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glDrawElements(GL_TRIANGLES, noIndices * 3, GL_UNSIGNED_INT, 0);
}

void Mesh::CreateCubeMesh() {

	int faces = 6;

	noVertices = faces * 4;
	noIndices = faces * 2;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(0, 0, 0);

	// Front face
	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position);

	// Back face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position);

	// Left face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position);

	// Right face
	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position);

	// Bottom face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	// Top face
	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position);

	// Triangles
	addTriangle(0, 1, 2);
	addTriangle(1, 3, 2);

	addTriangle(4, 6, 5);
	addTriangle(5, 6, 7);

	addTriangle(8, 9, 10);
	addTriangle(9, 11, 10);

	addTriangle(12, 14, 13);
	addTriangle(13, 14, 15);

	addTriangle(16, 17, 18);
	addTriangle(17, 19, 18);
	
	addTriangle(20, 22, 21);
	addTriangle(21, 22, 23);

	calculateNormals();
	bind();
}

void Mesh::CreateSphereMesh(int resolutionX, int resolutionY_half) {

	resolutionX = 16;
	resolutionY_half = 16;
	
	int resolutionY = resolutionY_half * 2 + 1;

	noVertices = resolutionX * resolutionY + 2;
	noIndices = 2 * resolutionX * resolutionY;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	float heightMax = .5, heightMin = -.5;

	// Vertices

	// Bottom pole
	glm::vec3 position = glm::vec3(0, heightMin, 0);
	addVertex(&position);

	for (size_t y = 0; y < resolutionY; y++)
	{

		float height = (y + 1) * ((heightMax - heightMin) / (resolutionY + 1)) - (heightMax - heightMin) / 2;
		
		float a = abs(int(y) - resolutionY_half) / float(resolutionY_half + 1) * (heightMax - heightMin) / 2;
		float c = (heightMax - heightMin) / 2;
		float b = sqrt(c * c - a * a);

		float radius = b;
		
		for (size_t x = 0; x < resolutionX; x++)
		{
			float angle = (360.0f / resolutionX) * (x - 1);
			position = glm::vec3(sin(glm::radians(angle)) * radius, height, cos(glm::radians(angle)) * radius);

			addVertex(&position);
		}
	}
	
	// Top pole
	position = glm::vec3(0, heightMax, 0);
	addVertex(&position);

	// Triangles

	// Bottom
	int k;
	for (k = 0; k < resolutionX - 1; k++)
	{
		addTriangle(0, k + 2, k + 1);
	}
	addTriangle(0, 1, k + 1);

	// Quads
	for (size_t i = 0, k = 1; i < resolutionY - 1; i++)
	{
		for (size_t j = 0; j < resolutionX - 1; j++, k++)
		{
			addTriangle(k, k + 1, k + 1 + resolutionX);
			addTriangle(k, k + 1 + resolutionX, k + resolutionX);
		}

		addTriangle(k, k + 1 - resolutionX, k + 1);
		addTriangle(k, k + 1, k + resolutionX);

		k++;
	}

	// Top
	k = (resolutionY - 1) * resolutionX + 1;
	for (size_t i = 0; i < resolutionX - 1; i++, k++)
	{
		addTriangle(k, k + 1, resolutionX * resolutionY + 1);
	}
	
	addTriangle(k, k - resolutionX + 1, resolutionX * resolutionY + 1);

	calculateNormals();
	bind();
}

void Mesh::CreateCylinderMesh(int resolution) {

	resolution = 32;

	noVertices = 2 * 2 * resolution + 2;
	noIndices = 4 * resolution;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(0, 0, 0);

	float heightMax = .5f, heightMin = -.5f;
	float radius = (heightMax - heightMin) / 2;

	for (size_t x = 0, y = 0; x < 2; x++) {

		// Center of circle
		float height = x == 0 ? -.5 : .5;
		position = glm::vec3(0, height, 0);
		addVertex(&position);

		int circleCenterIndex = currVertexIndex - 1;

		for (size_t k = 0; k < 2; k++, y++)
		{

			for (size_t i = 0; i < resolution; i++) {

				float angle = (360.0f / resolution) * (i - 1);
				position = glm::vec3(sin(glm::radians(angle)) * radius, height, cos(glm::radians(angle)) * radius);
				addVertex(&position);
				
				if (y % 2 == 0) {

					if (y == 0) {
						// Bottom circle
						if (i < resolution - 1) {
							addTriangle(circleCenterIndex, circleCenterIndex + i + 2, circleCenterIndex + i + 1);
						}
						else {
							addTriangle(circleCenterIndex, circleCenterIndex + 1, circleCenterIndex + i + 1);
						}
					}
					else {
						// Top circle
						if (i < resolution - 1) {
							addTriangle(circleCenterIndex, circleCenterIndex + i + 1, circleCenterIndex + i + 2);
						}
						else {
							addTriangle(circleCenterIndex, circleCenterIndex + i + 1, circleCenterIndex + 1);
						}
					}
				}

				// Cylinder body
				if (y == 1) {

					if (i < resolution - 1) {

						addTriangle(
							circleCenterIndex + resolution * k + i + 1, 
							circleCenterIndex + resolution * k + i + 2,
							circleCenterIndex + 3 * resolution * k + i + 3
						);
						addTriangle(
							circleCenterIndex + resolution * k + i + 1,
							circleCenterIndex + 3 * resolution * k + i + 3,
							circleCenterIndex + 3 * resolution * k + i + 2
						);

					}
					else {
						
						addTriangle(
							circleCenterIndex + resolution * k + i + 1,
							circleCenterIndex + resolution * k + i + 2 - resolution,
							circleCenterIndex + 2 * resolution * k + i + 3
						);
						addTriangle(
							circleCenterIndex + resolution * k + i + 1,
							circleCenterIndex + 2 * resolution * k + i + 3,
							circleCenterIndex + 3 * resolution * k + i + 2
						);	

					}
				}	
			}
		}
	}

	calculateNormals();
	bind();
}

void Mesh::CreateBoxMesh() {

	int faces = 5;

	noVertices = faces * 4;
	noIndices = faces * 2;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(0, 0, 0);

	// Front face
	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position);

	// Back face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position);

	// Left face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position);

	// Right face
	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position);

	// Bottom face
	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position);

	// Triangles
	addTriangle(0, 2, 1);
	addTriangle(1, 2, 3);

	addTriangle(4, 5, 6);
	addTriangle(5, 7, 6);

	addTriangle(8, 10, 9);
	addTriangle(9, 10, 11);

	addTriangle(12, 13, 14);
	addTriangle(13, 15, 14);

	addTriangle(16, 18, 17);
	addTriangle(17, 18, 19);

	calculateNormals();
	bind();
}


void Mesh::addVertex(glm::vec3* position) {
	addVertex(position, currVertexIndex++);
}

void Mesh::addVertex(glm::vec3* position, int vertexIndex) {
	vertices[vertexIndex * vertexSize + 0] = position->x;
	vertices[vertexIndex * vertexSize + 1] = position->y;
	vertices[vertexIndex * vertexSize + 2] = position->z;
}

void Mesh::addTriangle(unsigned int a, unsigned int b, unsigned int c) {
	addTriangle(a, b, c, currTriangleIndex++);
}

void Mesh::addTriangle(unsigned int a, unsigned int b, unsigned int c, int triangleIndex) {
	indices[triangleIndex * 3 + 0] = a;
	indices[triangleIndex * 3 + 1] = b;
	indices[triangleIndex * 3 + 2] = c;

	trianglesPerVertex[a] += 1;
	trianglesPerVertex[b] += 1;
	trianglesPerVertex[c] += 1;
}

void Mesh::calculateNormals() {

	for (size_t i = 0; i < noVertices; i++)
	{
		vertices[i * vertexSize + 3] = 0;
		vertices[i * vertexSize + 4] = 0;
		vertices[i * vertexSize + 5] = 0;
	}
	
	for (size_t i = 0; i < noIndices; i++)
	{
		unsigned int i0 = indices[i * 3 + 0];
		unsigned int i1 = indices[i * 3 + 1];
		unsigned int i2 = indices[i * 3 + 2];

		glm::vec3 p0 = glm::vec3(
			vertices[i0 * vertexSize + 0], 
			vertices[i0 * vertexSize + 1], 
			vertices[i0 * vertexSize + 2]
		);

		glm::vec3 p1 = glm::vec3(
			vertices[i1 * vertexSize + 0],
			vertices[i1 * vertexSize + 1],
			vertices[i1 * vertexSize + 2]
		);

		glm::vec3 p2 = glm::vec3(
			vertices[i2 * vertexSize + 0],
			vertices[i2 * vertexSize + 1],
			vertices[i2 * vertexSize + 2]
		);

		glm::vec3 normal = glm::cross(p1 - p0, p2 - p0);

		vertices[i0 * vertexSize + 3] += normal.x;
		vertices[i0 * vertexSize + 4] += normal.y;
		vertices[i0 * vertexSize + 5] += normal.z;

		vertices[i1 * vertexSize + 3] += normal.x;
		vertices[i1 * vertexSize + 4] += normal.y;
		vertices[i1 * vertexSize + 5] += normal.z;

		vertices[i2 * vertexSize + 3] += normal.x;
		vertices[i2 * vertexSize + 4] += normal.y;
		vertices[i2 * vertexSize + 5] += normal.z;
	}

	for (size_t i = 0; i < noVertices; i++) {

		vertices[i * vertexSize + 3] /= trianglesPerVertex[i];
		vertices[i * vertexSize + 4] /= trianglesPerVertex[i];
		vertices[i * vertexSize + 5] /= trianglesPerVertex[i];

		float magnitude = sqrt(
			vertices[i * vertexSize + 3] * vertices[i * vertexSize + 3] +
			vertices[i * vertexSize + 4] * vertices[i * vertexSize + 4] +
			vertices[i * vertexSize + 5] * vertices[i * vertexSize + 5]
		);

		vertices[i * vertexSize + 3] /= magnitude;
		vertices[i * vertexSize + 4] /= magnitude;
		vertices[i * vertexSize + 5] /= magnitude;
	}

}

void Mesh::bind() {

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

	// normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}


Mesh::Mesh(char* path) {

	std::string modelPath = std::string(Utils::GetModelPath());
	modelPath += path;

	FILE* file = fopen(modelPath.c_str(), "r");
	Load(file);

}

void Mesh::Load(FILE* file) {

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	std::vector<int> temp_indices;

	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}

		else if (strcmp(lineHeader, "f") == 0) {

			/*
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return;
			}
			*/


			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[4], uvIndex[4], normalIndex[4];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2], &vertexIndex[3], &uvIndex[3], &normalIndex[3]);
			
			if ((matches != 9) && (matches != 12)) {
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return;
			}
			
			if (matches == 9) {
				temp_indices.push_back(vertexIndex[0]);
				temp_indices.push_back(normalIndex[0]);

				temp_indices.push_back(vertexIndex[1]);
				temp_indices.push_back(normalIndex[1]);

				temp_indices.push_back(vertexIndex[2]);
				temp_indices.push_back(normalIndex[2]);
			}
			else {
				temp_indices.push_back(vertexIndex[0]);
				temp_indices.push_back(normalIndex[0]);

				temp_indices.push_back(vertexIndex[1]);
				temp_indices.push_back(normalIndex[1]);

				temp_indices.push_back(vertexIndex[2]);
				temp_indices.push_back(normalIndex[2]);

				temp_indices.push_back(vertexIndex[3]);
				temp_indices.push_back(normalIndex[3]);
			}

			/*
			* 	noVertices = faces * 4;
	noIndices = faces * 2;

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	glm::vec3 position = glm::vec3(0, 0, 0);

	// Front face
	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position);


		// Triangles
		addTriangle(0, 2, 1);
		addTriangle(1, 2, 3);
		*/



			/*
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
			*/

		}
	}

	/*
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
	*/

	std::cout << "Vertices " << temp_vertices.size() << std::endl;
	std::cout << "UVs      " << temp_uvs.size() << std::endl;
	std::cout << "Normals  " << temp_normals.size() << std::endl;
	std::cout << "Indices  " << temp_indices.size() / 9 << std::endl;

	
	vertices = (float*)malloc(temp_uvs.size() * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(temp_indices.size() / 3 * sizeof(unsigned int));
	
	bind();
}
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
	glm::vec3 normal = glm::vec3(0, 0, 0);

	// Front face
	normal = glm::vec3(0, 0, 1);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position, &normal);

	// Back face
	normal = glm::vec3(0, 0, -1);

	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position, &normal);

	// Left face
	normal = glm::vec3(-1, 0, 0);

	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position, &normal);

	// Right face
	normal = glm::vec3(1, 0, 0);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position, &normal);

	// Bottom face
	normal = glm::vec3(0, -1, 0);

	position = glm::vec3(-.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, -.5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, -.5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, -.5f, .5f);
	addVertex(&position, &normal);

	// Top face
	normal = glm::vec3(0, 1, 0);

	position = glm::vec3(-.5f, .5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, -.5f);
	addVertex(&position, &normal);

	position = glm::vec3(-.5f, .5f, .5f);
	addVertex(&position, &normal);

	position = glm::vec3(.5f, .5f, .5f);
	addVertex(&position, &normal);

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

void Mesh::CreateSphereMesh(int resolutionX, int resolutionY) {

	/*
	CreateCubeMesh();
	return;
	*/

	/*
	CreateCylinderMesh(8);
	return;
	*/

	resolutionX = 16;
	resolutionY = 2;

	resolutionY = 2 * resolutionY + 1;
	
	resolutionY = 33;
	int resolutionY_half = 16;

	time_t t;
	srand((unsigned)time(&t));

	noVertices = resolutionX * resolutionY + 2;
	noIndices = 2 * resolutionX * resolutionY;
	//noIndices = resolutionX * (resolutionY + 1);

	vertices = (float*)malloc(noVertices * vertexSize * sizeof(float));
	indices = (unsigned int*)malloc(noIndices * 3 * sizeof(unsigned int));

	trianglesPerVertex = (unsigned int*)malloc(noVertices * sizeof(unsigned int));
	trianglesPerVertex = (unsigned int*)memset(trianglesPerVertex, 0, noVertices * sizeof(unsigned int));

	float heightMax = 2, heightMin = -2;

	// Vertices
	glm::vec3 position = glm::vec3(0, heightMin, 0);
	glm::vec3 normal = glm::vec3(0, 0, 0);

	//normal = glm::vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);
	normal = glm::vec3(0.0, 0.0, 0.0);
	addVertex(&position, &normal);

	for (size_t y = 0; y < resolutionY; y++)
	{

		float radius = 1;
		float height = 0;

		//std::cout << "COLOR " << (y + 1) * (255.0 / (resolutionY + 1));
		
		float color = ((y + 1) * (255.0 / (resolutionY + 1))) / 255.0;
		height = (y + 1) * ((heightMax - heightMin) / (resolutionY + 1)) - (heightMax - heightMin) / 2;
		

		//			float angle = (360.0f / resolutionX) * (x - 1);

		//std::cout << "RADIUS " << y << " " << resolutionY_half << " " << int(y) - resolutionY_half << std::endl;

		//std::cout << "RADIUS " << abs(int(y) - resolutionY_half) / float(resolutionY_half + 1) * (heightMax - heightMin) / 2<< std::endl;

		float a = abs(int(y) - resolutionY_half) / float(resolutionY_half + 1) * (heightMax - heightMin) / 2;
		float c = (heightMax - heightMin) / 2;

		float b = sqrt(c * c - a * a);
		std::cout << "RADIUS " << b << std::endl;

		radius = b;
		//radius = (1 - abs(int(y) - resolutionY_half) / float(resolutionY_half + 1)) * (heightMax - heightMin);

		/*
		float angleY = (360.0f / resolutionY) * (int(y) - 1);
		radius = 1 - abs(cos(glm::radians(angleY)));
		*/

		/*
		cos(
			glm::radians(
				(y - int(resolutionY / 2)) * (360.0f / (resolutionY + 1))
			)
		) << std::endl;
		*/
		
		//std::cout << "HEIGHT " << (y + 1) * ((heightMax - heightMin) / (resolutionY + 1)) - (heightMax - heightMin) / 2;

		
		normal = glm::vec3(color, color, color);
		//std::cout << "COLOR " << normal.x << " " << normal.y << " " << normal.z << std::endl;

		/*
		if (y < (resolutionY - 1) / 2) {
			std::cout << "HEIGHT " << y << " " << (y + -1 - resolutionY / 2) * (heightMax - heightMin) / (resolutionY + 1.0) << std::endl;
		}

		if (y == (resolutionY - 1) / 2) {
			std::cout << "HEIGHT " << y << " " << 0 << std::endl;
			//height = 0;
		}
		
		if (y > (resolutionY - 1) / 2) {
			//height = (y - (resolutionY - 1) / 2) * ((heightMax - heightMin) / 2);
			std::cout << "HEIGHT " << y << " " << (y + -1 - resolutionY / 2) * (heightMax - heightMin) / (resolutionY + 1.0) << std::endl;
		}
		*/

		//std::cout << "HEIGHT " << y / (resolutionY + 1) << " " << 0 << std::endl;

		for (size_t x = 0; x < resolutionX; x++)
		{
			float angle = (360.0f / resolutionX) * (x - 1);
			position = glm::vec3(sin(glm::radians(angle)) * radius, height, cos(glm::radians(angle)) * radius);

			//std::cout << rand() % 50 << std::endl;

			//normal = glm::vec3(1, 0, 0);

			addVertex(&position, &normal);
		}
	}

	//normal = glm::vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);
	
	normal = glm::vec3(1, 1, 1);
	position = glm::vec3(0, heightMax, 0);
	
	addVertex(&position, &normal);

	// Triangles

	// Bottom
	int k;
	for (k = 0; k < resolutionX - 1; k++)
	{
		addTriangle(0, k + 2, k + 1);
		//std::cout << "0 " << k + 2 << " " << k + 1 << std::endl;
	}
	addTriangle(0, 1, k + 1);
	//std::cout << "0 1 " << k + 1 << std::endl;

	//std::cout << std::endl;

	// Quads
	for (size_t i = 0, k = 1; i < resolutionY - 1; i++)
	{
		for (size_t j = 0; j < resolutionX - 1; j++, k++)
		{

			/*
			std::cout << k << " " << k + 1 << " " << k + 1 + resolutionX << " || " << k << " " << 
				k + 1 + resolutionX << " " << k + resolutionX << std::endl;
			*/

			addTriangle(k, k + 1, k + 1 + resolutionX);
			addTriangle(k, k + 1 + resolutionX, k + resolutionX);

		}

		/*
		std::cout << k << " " << k + 1 - resolutionX << " " << k + 1 << " || " << 
			k << " " << k + 1 << " " << k + resolutionX << std::endl;
		std::cout << std::endl;
		*/

		addTriangle(k, k + 1 - resolutionX, k + 1);
		addTriangle(k, k + 1, k + resolutionX);

		k++;

	}

	// Top
	k = (resolutionY - 1) * resolutionX + 1;
	for (size_t i = 0; i < resolutionX - 1; i++, k++)
	{
		//addTriangle(0, k + 2, k + 1);
		
		
		//std::cout << k << " " << k + 1 << " " << resolutionX * resolutionY + 1 << std::endl;
		
		
		//std::cout << resolutionX * resolutionY + 1 << k + 2 << " " << k + 1 << std::endl;

		addTriangle(k, k + 1, resolutionX * resolutionY + 1);
	}

	//std::cout << k << " " << k - resolutionX + 1 << " " << resolutionX * resolutionY + 1 << std::endl;
	
	addTriangle(k, k - resolutionX + 1, resolutionX * resolutionY + 1);

	//addTriangle(0, 1, k + 1);
	//std::cout << "0 1 " << k + 1 << std::endl;

	
	std::cout << std::endl;

	std::cout << std::endl << "-------------------" << std::endl << noIndices << " " << currTriangleIndex << std::endl;

	std::cout << std::endl << "-------------------" << std::endl << noVertices << " " << currVertexIndex << std::endl;
	

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

	glm::vec3 position = glm::vec3(0, -1, 0);
	glm::vec3 normal = glm::vec3(0, 0, 0);

	normal = glm::vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);

	for (size_t x = 0, y = 0; x < 2; x++) {

		// Center of circle
		int height = x == 0 ? -1 : 1;
		position = glm::vec3(0, height, 0);
		
		normal = glm::vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);

		addVertex(&position, &normal);

		int circleCenterIndex = currVertexIndex - 1;

		for (size_t k = 0; k < 2; k++, y++)
		{

			for (size_t i = 0; i < resolution; i++) {

				float angle = (360.0f / resolution) * (i - 1);

				position = glm::vec3(sin(glm::radians(angle)), height, cos(glm::radians(angle)));
				
				normal = glm::vec3(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);

				addVertex(&position, &normal);
				
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

void Mesh::addVertex(glm::vec3* position, glm::vec3* normal) {
	addVertex(position, normal, currVertexIndex++);
}

void Mesh::addVertex(glm::vec3* position, glm::vec3* normal, int vertexIndex) {
	vertices[vertexIndex * vertexSize + 0] = position->x;
	vertices[vertexIndex * vertexSize + 1] = position->y;
	vertices[vertexIndex * vertexSize + 2] = position->z;

	vertices[vertexIndex * vertexSize + 3] = normal->x;
	vertices[vertexIndex * vertexSize + 4] = normal->y;
	vertices[vertexIndex * vertexSize + 5] = normal->z;
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

		//std::cout << i << " " << trianglesPerVertex[i] << std::endl;

		vertices[i * vertexSize + 3] = 0;
		vertices[i * vertexSize + 4] = 0;
		vertices[i * vertexSize + 5] = 0;

		/*
		vertices[i * vertexSize + 3] = trianglesPerVertex[i] * 0.2;
		vertices[i * vertexSize + 4] = trianglesPerVertex[i] * 0.2;
		vertices[i * vertexSize + 5] = trianglesPerVertex[i] * 0.2;
		*/
	}

	//return;
	

	std::cout << "--------------------" << std::endl;
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

		/*
		std::cout << i0 << " " << i1 << " " << i2 << std::endl;
		std::cout << "     " << p0 << std::endl << "     " << p1 << std::endl << "     " << p2 << std::endl << "-----" << std::endl << "     " << normal << std::endl << std::endl << std::endl << std::endl;
		*/


		/*
		vertices[i0 * vertexSize + 0] += 1;
		vertices[i0 * vertexSize + 1] += 1;
		vertices[i0 * vertexSize + 2] += 1;
		vertices[i1 * vertexSize + 0] += 1;
		vertices[i1 * vertexSize + 1] += 1;
		vertices[i1 * vertexSize + 2] += 1;
		vertices[i2 * vertexSize + 0] += 1;
		vertices[i2 * vertexSize + 1] += 1;
		vertices[i2 * vertexSize + 2] += 1;
		*/

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


	std::cout << "NORMALS!!" << std::endl;
	for (size_t i = 0; i < noVertices; i++) {

		/*
		std::cout << i << " " << trianglesPerVertex[i] << " - " << vertices[i * vertexSize + 3] << " "
			<< vertices[i * vertexSize + 4] << " " << vertices[i * vertexSize + 5] << std::endl;
		*/
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

		/*
		std::cout << i << " " << trianglesPerVertex[i] << " - " << vertices[i * vertexSize + 3] << " "
			<< vertices[i * vertexSize + 4] << " " << vertices[i * vertexSize + 5] << std::endl;

		std::cout << "-------------" << std::endl;
		*/
	}


}

void Mesh::bind() {

	glm::vec3 a = glm::vec3();
	glm::vec3 b = glm::vec3();
	glm::vec3 cross = glm::cross(a, b);


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

	glBindVertexArray(VAO);
}

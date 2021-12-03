#include "GameObject.h"

GameObject::GameObject(std::string name) {
	this->name = name;

	CreateMesh();

	/*
	hasNormals = true;
	hasTangents = true;
	hasColors = true;
	hasUvs = true;
	hasUvs2 = true;
	*/

	//std::cout << "Vertex size " << GetVertexSize() << std::endl;

	//AddVertex((float*)malloc(3 * sizeof(float)));
}

GameObject::~GameObject() {

}

void GameObject::Update() {
	//std::cout << name << " update" << std::endl;

}

void GameObject::Draw() {

	//std::cout << name << " draw" << std::endl;
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GameObject::CreateMesh() {

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


	Flush();
}

void GameObject::AddTriangle(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3) {


	//gameObjects.push_back(GameObject("Mihai"));


}

void GameObject::AddTriangleColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3) {

}

void GameObject::AddTriangleColor(glm::vec3 col) {

}

void GameObject::AddQuad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4) {

}

void GameObject::AddQuadColor(glm::vec3 col1, glm::vec3 col2, glm::vec3 col3, glm::vec3 col4) {

}

void GameObject::AddQuadColor(glm::vec3 col) {

}

void GameObject::Flush() {

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

void GameObject::AddVertex(float* attributes) {

	// Check if has correct length

	if (sizeof(attributes) != GetVertexSize()) {
		std::cout << "WTF" << std::endl;
	}


}

int GameObject::GetVertexSize() {
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
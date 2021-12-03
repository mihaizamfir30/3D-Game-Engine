#include "GameObject.h"

GameObject::GameObject(std::string name) {
	this->name = name;

	//mesh = new Mesh();
	transform = new Transform();

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

void GameObject::Update(double deltaTime) {

	/*
	float speed = 1;

	if (Input::GetKey(KeyCode::A)) {
		transform->Translate(glm::vec3(-speed * deltaTime, 0, 0));
	}
	if (Input::GetKey(KeyCode::D)) {
		transform->Translate(glm::vec3(speed * deltaTime, 0, 0));
	}
	if (Input::GetKey(KeyCode::S)) {
		transform->Translate(glm::vec3(0, -speed * deltaTime, 0));
	}
	if (Input::GetKey(KeyCode::W)) {
		transform->Translate(glm::vec3(0, speed * deltaTime, 0));
	}
	*/


//	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

}

void GameObject::Draw() {

	glm::mat4 model = transform->GetModelMatrix();
	shader->use();
	shader->setMat4("model", model);

	mesh->Draw();
}
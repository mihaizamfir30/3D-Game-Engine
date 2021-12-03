#include "GameObject.h"

GameObject::GameObject() {
	transform = new Transform();

	//scaleAndOffset = UI::GetScaleAndOffset(49);

}

GameObject::GameObject(char *name) {
	this->name = name;

	//mesh = new Mesh();
	//transform = new Transform();

	//scaleAndOffset = UI::GetScaleAndOffset(49);

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

void GameObject::Init(Transform* transform, Mesh* mesh, Shader* shader) {
	this->transform = transform;
	this->mesh = mesh;
	this->shader = shader;
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

	//std::cout << "GameObject::Draw " << name << std::endl;
	
	//transform->GetModelMatrix();
	glm::mat4 model = transform->GetModelMatrix();
	shader->use();
	shader->setMat4("model", model);
	
	//shader->setVec4("scaleAndOffset", scaleAndOffset);
	//shader->setVec4("scaleAndOffset", glm::vec4(1, 1, 0, 0));

	mesh->Draw();

	//Camera* camera = SceneManager::GetActiveCamera();

	//std::cout << shader != NULL << std::endl;

	/*

	glm::mat4 model = transform->GetModelMatrix();
	shader->use();
	shader->setMat4("model", model);

	mesh->Draw();
	*/
}
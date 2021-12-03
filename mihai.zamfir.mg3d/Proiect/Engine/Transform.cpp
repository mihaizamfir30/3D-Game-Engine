#include "Transform.h"

#include <vector>
#include <iostream>


Transform::Transform() {

	position = glm::vec3(0);
	rotation = glm::vec3(0);
	scale = glm::vec3(0);
}

Transform::~Transform() {

}

glm::vec3 Transform::GetPosition() {
	return position;
}

glm::vec3 Transform::GetRotation() {
	return rotation;
}

glm::vec3 Transform::GetScale() {
	return scale;
}

void Transform::SetPosition(glm::vec3 position) {
	this->position = position;
}

void Transform::SetRotation(glm::vec3 rotation) {
	this->rotation = rotation;
}

void Transform::SetScale(glm::vec3 scale) {
	this->scale = scale;
}

glm::mat4 Transform::GetModelMatrix() {


	/*
	glm::mat4 model;
model = glm::translate(model, cubePositions[i]);
float angle = 20.0f * i;
model = glm::rotate(model, glm::radians(


model = glm::mat4();
model = glm::translate(model, lightPos);
model = glm::scale(model, glm::vec3(0.2f));
	*/

	glm::mat4 model = glm::mat4();
	model = glm::translate(model, position);
	model = glm::scale(model, scale);
	
	return model;

}

/*
glm::mat4 Transform::getModelMatrix() {
	glm::mat4 model;
	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	return model;

	//trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	//trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

}

glm::mat4 Transform::getViewMatrix() {
	glm::mat4 view;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0));
	return view;
}

glm::mat4 Transform::getProjectionMatrix() {
	glm::mat4 projection;

	float screenWidth = 800;
	float screenHeight = 600;

	projection = glm::perspective(glm::radians(45.0f), screenWidth / screenHeight, 0.1f, 100.0f);
	return projection;
}

*/

void Transform::Translate(glm::vec3 offset) {
	position += offset;
}

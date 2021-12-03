#include "Transform.h"

#include <vector>
#include <iostream>


Transform::Transform() {

	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
}

Transform::~Transform() {

}

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


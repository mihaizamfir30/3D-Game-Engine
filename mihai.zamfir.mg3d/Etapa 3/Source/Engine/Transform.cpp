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

void Transform::Save(int indentLevel) {

	// Open Element
	Utils::PrintIndent(indentLevel);
	std::cout << "<transform>" << std::endl;

	// Position
	Utils::PrintIndent(indentLevel + 1);
	std::cout << "<position>" << std::endl;

	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<x>" << position.x << "</x>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<y>" << position.y << "</y>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<z>" << position.z << "</z>" << std::endl;

	Utils::PrintIndent(indentLevel + 1);
	std::cout << "</position>" << std::endl;

	// Rotation
	Utils::PrintIndent(indentLevel + 1);
	std::cout << "<rotation>" << std::endl;

	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<x>" << rotation.x << "</x>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<y>" << rotation.y << "</y>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<z>" << rotation.z << "</z>" << std::endl;

	Utils::PrintIndent(indentLevel + 1);
	std::cout << "</rotation>" << std::endl;

	// Scale
	Utils::PrintIndent(indentLevel + 1);
	std::cout << "<scale>" << std::endl;

	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<x>" << scale.x << "</x>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<y>" << scale.y << "</y>" << std::endl;
	Utils::PrintIndent(indentLevel + 2);
	std::cout << "<z>" << scale.z << "</z>" << std::endl;

	Utils::PrintIndent(indentLevel + 1);
	std::cout << "</scale>" << std::endl;

	// Close Element
	Utils::PrintIndent(indentLevel);
	std::cout << "<transform>" << std::endl;
}

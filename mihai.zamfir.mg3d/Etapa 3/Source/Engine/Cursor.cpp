#include "Cursor.h"

#include <vector>
#include <iostream>


Cursor::Cursor() {

	glm::ivec2 resolution = ResourceManager::GetInstance()->GetResolution();
	projection = glm::ortho(0.0f, (float)resolution.x, 0.0f, (float)resolution.y);

}

Cursor::~Cursor() {
}

void Cursor::Draw() {

	glm::mat4 model = getModelMatrix();
	shader->use();

	shader->setMat4("model", model);
	shader->setMat4("projection", projection);

	shader->setFloat("depth", depth);
	shader->setVec3("color", color);

	uiMesh->Draw();
}

glm::mat4 Cursor::getModelMatrix() {

	glm::mat4 model = glm::mat4();

	model = glm::translate(model, Position);
	model = glm::scale(model, Scale);

	return model;

}
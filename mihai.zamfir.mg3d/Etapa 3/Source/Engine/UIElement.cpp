#include "UIElement.h"

#include <vector>
#include <iostream>


UIElement::UIElement() {

	glm::ivec2 resolution = ResourceManager::GetInstance()->GetResolution();
	projection = glm::ortho(0.0f, (float)resolution.x, 0.0f, (float)resolution.y);

}

UIElement::~UIElement() {
}

void UIElement::Draw() {

	if (selected == 1) {
		std::cout << "I AM SELECTED!!!!!!!!!!!!!!!" << std::endl;
	}

	//std::cout << "UIElement::Draw " << Id << " " << selected << std::endl;

	glm::mat4 model = getModelMatrix();
	shader->use();

	glBindTexture(GL_TEXTURE_2D, Texture->texture);

	shader->setMat4("model", model);
	shader->setMat4("projection", projection);

	shader->setFloat("depth", depth);
	shader->setVec3("color", color);

	if (selected == 1) {
		std::cout << "SELECTED " << Id << std::endl;
		shader->setVec3("selected", glm::vec3(1, 1, 1));
	}
	else {
		shader->setVec3("selected", glm::vec3(0, 0, 0));
	}


	/*
	if (Id == 0) {
		shader->setVec3("selected", glm::vec3(1, 1, 1));
	}
	else {
		shader->setVec3("selected", glm::vec3(0, 0, 0));
	}
	*/


	uiMesh->Draw();
}

glm::mat4 UIElement::getModelMatrix() {
	
	glm::mat4 model = glm::mat4();

	model = glm::translate(model, Position);
	model = glm::scale(model, Scale);

	return model;

}
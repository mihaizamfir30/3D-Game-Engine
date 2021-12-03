#include "Light.h"

Light::Light() {

}

Light::Light(glm::vec3 lightPosition, glm::vec3 lightColor) {
	this->lightPosition = lightPosition;
	this->lightColor = lightColor;

	transform = new Transform();

	transform->SetPosition(glm::vec3(0.0f, 1.5f, 0.0f));
	transform->SetScale(glm::vec3(0.2f));
}

Light::~Light() {

}

void Light::Update(double deltaTime) {

	time += deltaTime * speed;

	glm::vec3 position = glm::vec3(0.0, 0.0f, 1.0f);
	
	position.x = cos(time) * radius;
	position.y = sin(time) * radius;

	transform->SetPosition(position);


	shader->use();
	shader->setVec3("lightPosition", position);
	shader->setVec3("lightColor", lightColor);



	glm::mat4 model = transform->GetModelMatrix();
	lightShader->use();
	lightShader->setMat4("model", model);

	mesh->Draw();
}

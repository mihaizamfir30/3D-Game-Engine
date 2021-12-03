#include "Camera.h"

Camera::Camera() {

	glm::ivec2 resolution = ResourceManager::GetInstance()->GetResolution();

	width = resolution.x;
	height = resolution.y;

	cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);

	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPosition - cameraTarget);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraRight = glm::normalize(glm::cross(up, cameraDirection));

	cameraUp = glm::cross(cameraDirection, cameraRight);

	glm::mat4 view;
	view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	yaw = -90.0f;
	pitch = 0.0f;
	roll = 0.0f;

	lastX = width / 2;
	lastY = height / 2;
}

void Camera::Init() {

	cameraDirection = glm::normalize(Position - Target);

	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);


	/*
	glm::vec3 Position;
	glm::vec3 Target;
	glm::vec3 Up;
	glm::vec3 BackgroundColor;
	*/

	cameraRight = glm::normalize(glm::cross(Up, cameraDirection));

	cameraUp = glm::cross(cameraDirection, cameraRight);

	glm::mat4 view;
	view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	yaw = -90.0f;
	pitch = 0.0f;
	roll = 0.0f;

	lastX = width / 2;
	lastY = height / 2;
}

Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix() {

	//return glm::mat4();

	glm::mat4 view;
	view = glm::lookAt(
		cameraPosition,
		cameraPosition + cameraFront,
		cameraUp);

	return view;

	/*
	glm::mat4 view = glm::mat4(1.0f);
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	return view;
	*/
}

glm::mat4 Camera::GetProjectionMatrix() {

	//return glm::mat4();

	glm::mat4 projection = glm::perspective(
		glm::radians(fov), 
		(float)width / (float)height, 
		nearPlane, 
		farPlane
	);

	return projection;
}


void Camera::Update(double deltaTime) {

	glm::vec2 mouseScroll = Input::GetMouseScroll();
	glm::vec2 mousePosition = Input::GetMousePosition();

	const float scrollSpeed = 30.0f;
	fov -= (float)mouseScroll.y * scrollSpeed * deltaTime;
	if (fov < 1.0f) {
		fov = 1.0f;
	}
	if (fov > 45.0f) {
		fov = 45.0f;
	}

	if (firstMouse == true) {
		lastX = mousePosition.x;
		lastY = mousePosition.y;
		firstMouse = false;
	}

	float xOffset = mousePosition.x - lastX;
	float yOffset = lastY - mousePosition.y;
	lastX = mousePosition.x;
	lastY = mousePosition.y;

	const float sensitivity = 25.0f;
	xOffset *= sensitivity * deltaTime;
	yOffset *= sensitivity * deltaTime;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	cameraFront = glm::normalize(direction);

	const float cameraSpeed = 2.0f; // adjust accordingly

	if (Input::GetKey(KeyCode::Z)) {
		cameraPosition += cameraSpeed * (float)deltaTime * cameraFront;
	}
	if (Input::GetKey(KeyCode::C)) {
		cameraPosition -= cameraSpeed * (float)deltaTime * cameraFront;
	}
	
	if (Input::GetKey(KeyCode::A)) {
		cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * (float)deltaTime;
	}
	if (Input::GetKey(KeyCode::D)) {
		cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * (float)deltaTime;
	}


	if (Input::GetKey(KeyCode::W)) {
		cameraPosition += cameraSpeed * (float)deltaTime * cameraUp;
	}
	if (Input::GetKey(KeyCode::S)) {
		cameraPosition -= cameraSpeed * (float)deltaTime * cameraUp;
	}

	/*
	shader->use();

	glm::mat4 projection = GetProjectionMatrix();
	shader->setMat4("projection", projection);

	glm::mat4 view = GetViewMatrix();
	shader->setMat4("view", view);

	shader->setVec3("viewerPosition", cameraPosition);

	lightShader->use();

	lightShader->setMat4("projection", projection);
	lightShader->setMat4("view", view);
	*/
}
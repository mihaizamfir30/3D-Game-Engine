#include "Input.h"

int Input::keyState[500];
glm::vec2 Input::mousePosition;
glm::vec2 Input::mouseScroll;


void Input::OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//std::cout << "INPUT " << frameId << " " << key << " " << action << std::endl;
	//keyState[key] = action;

	keyState[key] = action;
}

void Input::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
	mousePosition.x = xpos;
	mousePosition.y = ypos;
}

void Input::ScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
	mouseScroll.x = xOffset;
	mouseScroll.y = yOffset;
}


glm::vec2 Input::GetMousePosition() {
	return mousePosition;
}

glm::vec2 Input::GetMouseScroll() {
	return mouseScroll;
}

bool Input::GetKeyDown(KeyCode key) {
	return keyState[key] == 1;
}

bool Input::GetKeyUp(KeyCode key) {
	return keyState[key] == 0;
}

bool Input::GetKey(KeyCode key) {

	return keyState[key] != 0;
}

void Input::Update() {
}
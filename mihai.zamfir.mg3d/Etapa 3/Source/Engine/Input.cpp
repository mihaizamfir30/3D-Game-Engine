#include "Input.h"

int Input::keyState[500];
int Input::keyStatePrev[500];

double Input::xPosPrev;
double Input::yPosPrev;


//bool Input::isKeyPressed[500];
//bool Input::isKeyPressedPrev[500];

glm::ivec2 Input::resolution;
glm::vec2 Input::mousePosition;
glm::vec2 Input::mouseScroll;

void Input::SetResolution(glm::ivec2 rhsResolution) {
	resolution = rhsResolution;
}


void Input::OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods) {

	//std::cout << "INPUT " << key << " " << action << std::endl;

	// 1 - press
	// 2 - hold
	// 0 - release

	//std::cout << "INPUT " << frameId << " " << key << " " << action << std::endl;
	//keyState[key] = action;

	keyState[key] = action;
}

void Input::MouseCallback(GLFWwindow* window, double xpos, double ypos) {

	//std::cout << "CALLBACK " << resolution.x << " " << resolution.y << std::endl;
	
	double deltaX = xpos - xPosPrev;
	double deltaY = ypos - yPosPrev;
	
	mousePosition.x += deltaX;
	if (mousePosition.x < 0) {
		mousePosition.x = 0;
	}
	if (mousePosition.x >= resolution.x) {
		mousePosition.x = resolution.x - 1;
	}
	
	mousePosition.y += deltaY;
	if (mousePosition.y < 0) {
		mousePosition.y = 0;
	}
	if (mousePosition.y >= resolution.y) {
		mousePosition.y = resolution.y - 1;
	}

	xPosPrev = xpos;
	yPosPrev = ypos;

	return;
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

void Input::OnInputStart() {



	/*
	OnKeyDown - now 1, previously 0
	OnKeyHold - now != 0, previously != 0
	OnKeyUp - now 0, previously != 0
	*/
	
	for (size_t i = 0; i < 500; i++)
	{
		/*
		* int Input::keyState[500];
		bool Input::isKeyPressed[500];
		bool Input::isKeyPressedPrev[500];
		*/

		/*
		* 0
		* 1
		* Start 1 F F
		* End   1 F T
		* 1 
		*
		*/

		/*
		* 0 F F - Not Pressed
		* 0 F T - 
		* 0 T F - 
		* 0 T T - 
		* 
		* 1 F F - 
		* 1 F T - 
		* 1 T F - 
		* 1 T T - 
		* 
		* 2 F F - 
		* 2 F T - 
		* 2 T F - 
		* 2 T T - 
		*/
		
		/*
		if (2 == 2) {

		}
		*/

	}

}

void Input::OnInputEnd() {
}

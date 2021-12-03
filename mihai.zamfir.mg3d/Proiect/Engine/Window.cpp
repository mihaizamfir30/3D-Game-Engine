#include "Window.h"

Window::Window() {
	Init();
}

Window::~Window() {
	glfwDestroyWindow(window);
}

void Window::Init() {

	// Initialize the library
	if (!glfwInit())
		exit(0);

	glfwWindowHint(GLFW_VISIBLE, true);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	//glm::ivec2 resolution = glm::ivec2(1280, 720);
	//glm::ivec2 resolution = glm::ivec2(300, 300);

	glm::ivec2 resolution = glm::ivec2(600, 600);

	window = glfwCreateWindow(resolution.x, resolution.y, "PPUPG Project", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(0);
	}

	glfwMakeContextCurrent(window);

	CheckOpenGLError();

	/*
	First we will tell GLFW that it should hide the cursor and capture it. 
	Capturing a cursor means that, once the application has focus, the mouse cursor stays within 
	the center of the window (unless the application loses focus or quits). We can do this with one 
	simple configuration call:
	*/
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	glfwSetKeyCallback(window, &Input::OnKeyPressed);
	glfwSetCursorPosCallback(window, &Input::MouseCallback);
	glfwSetScrollCallback(window, &Input::ScrollCallback);

	glEnable(GL_DEPTH_TEST);

	// Register callbacks
	//glfwSetFramebufferSizeCallback(window, &Window::framebuffer_size_callback);
}

bool Window::update() {

	processInput();

	if (glfwWindowShouldClose(window) == true) {
		glfwTerminate();
		return false;
	}

	glfwPollEvents();

	return true;
}


void Window::processInput() {

	// Esacape kills the app
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void Window::OnFrameStart() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::OnFrameEnd() {

	glfwSwapBuffers(window);

}
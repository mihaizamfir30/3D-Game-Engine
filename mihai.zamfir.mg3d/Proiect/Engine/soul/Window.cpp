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

	glm::ivec2 resolution = glm::ivec2(600, 600);

	window = glfwCreateWindow(resolution.x, resolution.y, "PPUPG Project", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(0);
	}

	glfwMakeContextCurrent(window);

	CheckOpenGLError();

	// Register callbacks
	//glfwSetFramebufferSizeCallback(window, &Window::framebuffer_size_callback);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


bool Window::update() {

	processInput();

	if (glfwWindowShouldClose(window) == true) {
		glfwTerminate();
		return false;
	}

	glfwPollEvents();

	/*
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glfwSwapBuffers(window);


	glfwPollEvents();
	*/

	//glfwShowWindow(window);

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
	glClear(GL_COLOR_BUFFER_BIT);

	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Window::OnFrameEnd() {

	glfwSwapBuffers(window);

}
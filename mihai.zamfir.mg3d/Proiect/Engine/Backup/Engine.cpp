#include "Engine.h"

#include <vector>
#include <iostream>

Engine::Engine() {

	Init();
}

Engine::~Engine() {}

void Engine::Init() {

	// Initialize the library
	if (!glfwInit())
		exit(0);

	glfwWindowHint(GLFW_VISIBLE, true);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glm::ivec2 resolution = glm::ivec2(1280, 720);

	window = glfwCreateWindow(resolution.x, resolution.y, "Mihai", NULL, NULL);
	assert(window != nullptr);
	glfwMakeContextCurrent(window);

	CheckOpenGLError();

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Serious problem
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		exit(0);
	}
}

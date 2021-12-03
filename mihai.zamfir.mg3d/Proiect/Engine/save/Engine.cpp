#include "Engine.h"

#include <vector>
#include <iostream>

Engine::Engine() {

	Init();
}

Engine::~Engine() {}

void Engine::Init() {

	myWindow = new Window();

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Serious problem
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		exit(0);
	}
}

bool Engine::update() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return myWindow->update();
}

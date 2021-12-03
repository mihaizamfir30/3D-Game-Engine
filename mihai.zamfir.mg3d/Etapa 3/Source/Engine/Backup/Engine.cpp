#include "Engine.h"

#include <vector>
#include <iostream>

Engine::Engine() {
	Init();
}

Engine::~Engine() {

}

void Engine::Init() {
	
	myWindow = new Window();

	previousTime = 0;

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Serious problem
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		exit(0);
	}

	ResourceManager::GetInstance()->Init();
	SceneManager::GetInstance()->Init();

	scene = SceneManager::GetActiveScene();
	scene->Start();
}

bool Engine::Update() {

	myWindow->OnFrameStart();

	bool ret = myWindow->update();

	if (ret == false) {
		return false;
	}

	currentTime = glfwGetTime();
	deltaTime = currentTime - previousTime;

	scene->OnFrameStart();
	scene->Update(deltaTime);
	scene->OnFrameEnd();

	myWindow->OnFrameEnd();

	previousTime = currentTime;

	return true;
}
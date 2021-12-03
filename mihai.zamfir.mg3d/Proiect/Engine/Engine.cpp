#include "Engine.h"

#include <vector>
#include <iostream>

Engine::Engine() {
	Init();
}

Engine::~Engine() {

}

void Engine::Init() {

	/*
	std::cout << "CULLING START" << std::endl;
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	std::cout << "CULLING END" << std::endl;
	*/

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

	Texture t = Texture();
	t.LoadTexture("default2.png");
	//t.LoadTexture("font2.png");
	
	//return;

	ResourceManager::GetInstance()->Init();
	SceneManager::GetInstance()->Init();

	scene = SceneManager::GetActiveScene();
	scene->Start();
}

bool Engine::Update() {

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
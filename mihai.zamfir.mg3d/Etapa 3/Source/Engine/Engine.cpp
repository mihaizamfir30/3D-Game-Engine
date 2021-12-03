#include "Engine.h"
#include "Input.h"

#include <vector>
#include <iostream>

Engine::Engine() {
	Init();
}

Engine::~Engine() {

}

void Engine::Init() {

	framerateString = std::string("Framerate: 999");
	
	ResourceManager::GetInstance()->InitSettings();

	myWindow = new Window(ResourceManager::GetInstance()->GetResolution());

	previousTime = 0;

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Serious problem
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		exit(0);
	}

	/*
	Server::GetInstance()->Init();
	std::cout << "LOGIN " << Server::GetInstance()->Login("Alina", "Alina") << std::endl;
	*/

	ResourceManager::GetInstance()->Init();
	SceneManager::GetInstance()->Init();

	// Setup Text Renderer
	TextRenderer::GetInstance()->Init();
	TextRenderer::GetInstance()->Shader = ResourceManager::GetInstance()->LoadShader(3);

	Input::SetResolution(ResourceManager::GetInstance()->GetResolution());

	scene = SceneManager::GetActiveScene();
	scene->Start();
}

void Engine::UpdateFramerateString() {

	float framerate = framesSinceLastUpdate / timeSinceLastUpdate;

	if (framerate > 999) {
		framerate = 999;
	}

	if (framerate >= 100) {
		framerateString[11] = int(framerate / 100) + 48;
		framerateString[12] = int((framerate / 10)) % 10 + 48;
		framerateString[13] = int(framerate) % 10 + 48;
	}
	else {
		if (framerate >= 10) {
			framerateString[11] = ' ';
			framerateString[12] = int((framerate / 10)) % 10 + 48;
			framerateString[13] = int(framerate) % 10 + 48;
		}
		else {
			framerateString[11] = ' ';
			framerateString[12] = ' ';
			framerateString[13] = int(framerate) % 10 + 48;
		}
	}

	//framesSinceLastUpdate += 1;
	timeSinceLastUpdate -= 1.0;
	framesSinceLastUpdate = 0.0;



}

bool Engine::Update() {

	myWindow->OnFrameStart();

	bool ret = myWindow->update();

	if (ret == false) {
		return false;
	}

	currentTime = glfwGetTime();
	deltaTime = currentTime - previousTime;

	/*
	if (Input::GetKeyDown(KeyCode::Q)) {
		std::cout << k << " Q" << std::endl;
		k += 1;
	}
	*/


	Input::OnInputStart();

	framesSinceLastUpdate += 1;
	timeSinceLastUpdate += deltaTime;



	scene->OnFrameStart();
	scene->Update(deltaTime);
	scene->OnFrameEnd();

	if (timeSinceLastUpdate > 1.0) {
		UpdateFramerateString();
	}
	TextRenderer::GetInstance()->RenderText(framerateString, 0.88f, 0.95f, -0.99f, 0.50f, glm::vec3(0.5, 0.8f, 0.2f));

	//TextRenderer::GetInstance()->RenderText("Mihaela este foarte desteapta!", 0.25f, 0.25f, -0.99f, 1.5f, glm::vec3(1.0, 0.0f, 0.0f));

	Input::OnInputEnd();

	myWindow->OnFrameEnd();

	previousTime = currentTime;

	//return false;
	return true;
}
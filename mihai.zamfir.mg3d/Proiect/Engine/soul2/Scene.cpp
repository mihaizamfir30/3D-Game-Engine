#include "Scene.h"

Scene::Scene() {

	debug = false;

	if (debug == true) {
		std::cout << "Scene::Scene" << std::endl;
	}


	// Create shader
	shader = Shader("VertexShader.glsl", "FragmentShader.glsl");
	shader.use();


	gameObjects.push_back(GameObject("Mihai"));
	//gameObjects.push_back(GameObject("Andreea"));
}

Scene::~Scene() {
}

void Scene::OnFrameStart() {

	if (debug == true) {
		std::cout << "Scene::OnFrameStart" << std::endl;
	}
}

void Scene::Update() {

	if (debug == true) {
		std::cout << "Scene::Update" << std::endl;
	}


	for (it_go = gameObjects.begin(); it_go != gameObjects.end(); ++it_go) {
		it_go->Update();
		it_go->Draw();
	}
}

void Scene::OnFrameEnd() {

	if (debug == true) {
		std::cout << "Scene::OnFrameEnd" << std::endl;
	}

}
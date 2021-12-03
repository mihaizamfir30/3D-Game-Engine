#include "Scene.h"

Scene::Scene() {

	light = new Light(glm::vec3(0.0f, 1.5f, 0.0f), glm::vec3(0.2f));

}

Scene::~Scene() {
}

void Scene::Start() {
	return;
	
	it_go = GameObjects.begin(); 
	
	// F
	it_go->scaleAndOffset = UI::GetScaleAndOffset('F');
	it_go++;

	// R
	it_go->scaleAndOffset = UI::GetScaleAndOffset('R');
	it_go++;

	// A
	it_go->scaleAndOffset = UI::GetScaleAndOffset('A');
	it_go++;

	// M
	it_go->scaleAndOffset = UI::GetScaleAndOffset('M');
	it_go++;

	// E
	it_go->scaleAndOffset = UI::GetScaleAndOffset('E');
	it_go++;

	// R
	it_go->scaleAndOffset = UI::GetScaleAndOffset('R');
	it_go++;

	// A
	it_go->scaleAndOffset = UI::GetScaleAndOffset('A');
	it_go++;

	// T
	it_go->scaleAndOffset = UI::GetScaleAndOffset('T');
	it_go++;

	// E
	it_go->scaleAndOffset = UI::GetScaleAndOffset('E');
	it_go++;

	// 
	it_go->scaleAndOffset = UI::GetScaleAndOffset(' ');
	it_go++;

	// 1
	it_go->scaleAndOffset = UI::GetScaleAndOffset('1');
	it_go++;

	// 2
	it_go->scaleAndOffset = UI::GetScaleAndOffset('2');
	it_go++;

	// 3
	it_go->scaleAndOffset = UI::GetScaleAndOffset('3');
	it_go++;

	// 4
	it_go->scaleAndOffset = UI::GetScaleAndOffset('4');
	it_go++;

	//UpdateFramerate(0.05);

}

void Scene::UpdateFramerate(double deltaTime) {

	int frameRate = (int)(1.0 / deltaTime);

	frameRate = 7;

	it_go = GameObjects.begin();
	
	for (size_t i = 0; i < 10; i++)
	{
		it_go++;
	}

	if (frameRate < 10) {
		it_go->scaleAndOffset = UI::GetScaleAndOffset(7);
		it_go++;
		it_go->scaleAndOffset = UI::GetScaleAndOffset(' ');
		it_go++;
		it_go->scaleAndOffset = UI::GetScaleAndOffset(' ');
		it_go++;
		it_go->scaleAndOffset = UI::GetScaleAndOffset(' ');

		return;
	}

	if (frameRate < 100) {
		it_go->scaleAndOffset = UI::GetScaleAndOffset(frameRate / 10);
		it_go++;
		it_go->scaleAndOffset = UI::GetScaleAndOffset(frameRate / 10);
		return;
	}

	return;

	for (size_t i = 0; i < 4; i++)
	{
		it_go->scaleAndOffset = UI::GetScaleAndOffset('5');
		it_go++;

	}

	/*
	// 1
	it_go->scaleAndOffset = UI::GetScaleAndOffset('5');
	it_go++;

	// 2
	it_go->scaleAndOffset = UI::GetScaleAndOffset('6');
	it_go++;

	// 3
	it_go->scaleAndOffset = UI::GetScaleAndOffset('7');
	it_go++;

	// 4
	it_go->scaleAndOffset = UI::GetScaleAndOffset('8');
	it_go++;
	*/
}


void Scene::SetActiveCamera(int cameraId) {
	
	// If passed the same value, no need to do anything
	if (activeCameraId == cameraId) {
		return;
	}

	std::map<int, Camera>::iterator it = Cameras.find(cameraId);
	if (it == Cameras.end()) {
		std::cout << "ERROR::SCENE::SET_ACTIVE_CAMERA::UNRECOGNIZED_CAMERA_ID " << cameraId << std::endl;
		return;
	}

	activeCameraId = cameraId;
	camera = &(it->second);
}

void Scene::OnFrameStart() {
}

void Scene::Update(double deltaTime) {

	light->Update(deltaTime);

	//light->shader->use();
	light->Draw();

	//Scene::UpdateFramerate(deltaTime);

	it_go = GameObjects.begin();
	it_go->shader->use();
	it_go->shader->setMat4("view", camera->GetViewMatrix());
	it_go->shader->setMat4("projection", camera->GetProjectionMatrix());
	

	it_go->shader->setVec3("lightPosition", light->lightPosition);
	it_go->shader->setVec3("lightColor", light->lightColor);

	//it_go->shader->setMat4();
	//it->go.shader

	for (it_go = GameObjects.begin(); it_go != GameObjects.end(); ++it_go) {
		//it_go->Update(deltaTime);
		it_go->Draw();
	}

	camera->Update(deltaTime);

}

void Scene::OnFrameEnd() {
}
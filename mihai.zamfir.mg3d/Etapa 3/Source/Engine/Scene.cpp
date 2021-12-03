#include "Scene.h"

GameObject* Scene::activeGameObject = NULL;
std::list<GameObject>::iterator Scene::st_it_go;

Scene::Scene() {
	light = new Light(glm::vec3(0.0f, 1.5f, 0.0f), glm::vec3(0.2f));

	instance = Lua::GetInstance();

	instance->Register("Translate", lua_Translate);
	instance->Register("GeyKey", lua_GetKey);
}

Scene::~Scene() {
}

void Scene::Start() {
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


	canvas->Update(deltaTime);

	//Save();

	light->Update(deltaTime);

	//light->shader->use();
	light->Draw();

	it_go = GameObjects.begin();
	it_go->shader->use();
	it_go->shader->setMat4("view", camera->GetViewMatrix());
	it_go->shader->setMat4("projection", camera->GetProjectionMatrix());
	

	it_go->shader->setVec3("lightPosition", light->lightPosition);
	it_go->shader->setVec3("lightColor", light->lightColor);

	/*
	for (it_go = GameObjects.begin(); it_go != GameObjects.end(); ++it_go) {
		it_go->isColliding = false;
	}
	*/

	//it_scr

	for (it_go = GameObjects.begin(); it_go != GameObjects.end(); ++it_go) {

		//activeGameObject = *(*it_go);

		st_it_go = it_go;

		// Call scripts
		for (it_scr = it_go->scripts.begin(); it_scr != it_go->scripts.end(); ++it_scr) {

			char* script = ResourceManager::GetInstance()->LoadScript(*it_scr);
			instance->OpenScript(script);
			instance->Call("Update", deltaTime);

		}

		it_go->Update(deltaTime);
		it_go->Draw();
	}

	//canvas->Draw();


	camera->Update(deltaTime);

}

void Scene::OnFrameEnd() {
}

void Scene::Save() {
	std::cout << "Scene::Save" << std::endl;

	std::ofstream out("out.xml");
	std::cout.rdbuf(out.rdbuf());

	std::cout << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>" << std::endl;
	std::cout << "<sceneManager>" << std::endl;

	// Game Objects
	std::cout << "	<gameObjects>" << std::endl;
	for (it_go = GameObjects.begin(); it_go != GameObjects.end(); ++it_go) {
		it_go->Save(2);
	}
	std::cout << "	</gameObjects>" << std::endl;

	std::cout << "</sceneManager>" << std::endl;
}

int Scene::lua_Translate(lua_State* L) {

	float x = (float)lua_tonumber(L, 1);
	float y = (float)lua_tonumber(L, 2);
	float z = (float)lua_tonumber(L, 3);

	//transform->Translate(glm::vec3(-speed * deltaTime, 0, 0));


	st_it_go->transform->Translate(glm::vec3(x, y, z));

	//activeGameObject->transform;

	//lua_pushnumber(L, c);


	//activeObject->

	return 0;
}

int Scene::lua_GetKey(lua_State* L) {

	KeyCode keyCode = (KeyCode)lua_tonumber(L, 1);
	return Input::GetKey(keyCode);

}

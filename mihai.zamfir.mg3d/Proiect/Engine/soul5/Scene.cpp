#include "Scene.h"

Scene::Scene() {

	camera = new Camera();

	projection = camera->GetProjectionMatrix();

	// Create shader
	shader = Shader("VertexShader.glsl", "FragmentShader.glsl");
	lightShader = Shader("LightVertexShader.glsl", "LightFragmentShader.glsl");
	shader.use();

	//shader.setMat4("projection", projection);

	camera->shader = &shader;
	camera->lightShader = &lightShader;

	gameObjects.push_back(GameObject("Mihai"));
	gameObjects.front().shader = &shader;

	cubeMesh = new Mesh();
	cylinderMesh = new Mesh();
	quadMesh = new Mesh();
	sphereMesh = new Mesh();

	cubeMesh->CreateCubeMesh();
	//cubeMesh->Flush();

	//cylinderMesh->CreateCylinderMesh(32);
	cylinderMesh->CreateQuadMesh();
	quadMesh->CreateQuadMesh();
	sphereMesh->CreateSphereMesh(8, 8);

	//gameObjects.front().mesh = cubeMesh;// cylinderMesh;
	//gameObjects.front().mesh = cylinderMesh;// quadMesh;
	gameObjects.front().mesh = sphereMesh;// quadMesh;

	// Create light
	light = new Light(glm::vec3(5.0f, 5.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	light->shader = &shader;
	light->lightShader = &lightShader;
	light->mesh = cubeMesh;
}

Scene::~Scene() {
}

void Scene::OnFrameStart() {

}

void Scene::Update(double deltaTime) {

	for (it_go = gameObjects.begin(); it_go != gameObjects.end(); ++it_go) {
		it_go->Update(deltaTime);
		it_go->Draw();
	}

	camera->Update(deltaTime);
	light->Update(deltaTime);

}

void Scene::OnFrameEnd() {

}
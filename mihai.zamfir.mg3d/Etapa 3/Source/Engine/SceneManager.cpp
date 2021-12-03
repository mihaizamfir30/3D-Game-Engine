#include "SceneManager.h"

SceneManager* SceneManager::smInstance = NULL;
Scene* SceneManager::scene = NULL;

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {

}

SceneManager* SceneManager::GetInstance() {
	if (smInstance == NULL) {
		smInstance = new SceneManager();
	}

	return smInstance;
}

Camera* SceneManager::GetActiveCamera() {
	return &(scene->Cameras.find(scene->activeCameraId)->second);
}

Scene* SceneManager::GetActiveScene() {
	return scene;
}

void SceneManager::Init() {

	scene = new Scene();

	rm = ResourceManager::GetInstance();

	xml_document<> doc;

	std::ifstream file("../Resources/XMLs/sceneManager.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	// Iterate through root's children nodes: Models, Shaders, Textures etc. 
	for (xml_node<>* pNode = doc.first_node()->first_node(); pNode; pNode = pNode->next_sibling()) {

		if (strcmp(pNode->name(), "cameras") == 0) {
			ParseCameras(pNode);
		}
		
		if (strcmp(pNode->name(), "activeCamera") == 0) {
			scene->SetActiveCamera(atoi(pNode->value()));
		}

		if (strcmp(pNode->name(), "gameObjects") == 0) {
			ParseGameObjects(pNode);
		}

		if (strcmp(pNode->name(), "canvas") == 0) {
			ParseCanvas(pNode);
		}
	}
}

void SceneManager::ParseCanvas(xml_node<>* pNode) {

	Canvas* canvas = new Canvas();

	canvas->Init(pNode);

	scene->canvas = canvas;

}

void SceneManager::ParseCameras(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {
		
		if (strcmp(pChild->name(), "camera") != 0) {
			std::cout << "ERROR::SCENE_MANAGER_CAMERAS:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		// Read Camera Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::SCENE_MANAGER_CAMERAS:NO_VALID_ID" << std::endl;
			continue;
		}

		Camera* camera = new Camera();
		camera->Id = id;

		// Read Camera Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Camera Position
			if (strcmp(pGchild->name(), "position") == 0) {

				float x = 0, y = 0, z = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {
					
					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "z") == 0) {
						z = atof(pGgchild->value());
					}

				}

				camera->Position = glm::vec3(x, y, z);
			}

			// Camera Target
			if (strcmp(pGchild->name(), "target") == 0) {

				float x = 0, y = 0, z = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "z") == 0) {
						z = atof(pGgchild->value());
					}

				}

				camera->Target = glm::vec3(x, y, z);
			}

			// Camera Up
			if (strcmp(pGchild->name(), "up") == 0) {

				float x = 0, y = 0, z = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "z") == 0) {
						z = atof(pGgchild->value());
					}

				}

				camera->Up = glm::vec3(x, y, z);
			}

			// Translation Speed
			if (strcmp(pGchild->name(), "translationSpeed") == 0) {
				camera->TranslationSpeed = atof(pGchild->value());
			}

			// Rotation Speed
			if (strcmp(pGchild->name(), "rotationSpeed") == 0) {
				camera->RotationSpeed = atof(pGchild->value());
			}

			// FoV
			if (strcmp(pGchild->name(), "fov") == 0) {
				camera->FoV = atof(pGchild->value());
			}

			// Near
			if (strcmp(pGchild->name(), "near") == 0) {
				camera->Near = atof(pGchild->value());
			}

			// Far
			if (strcmp(pGchild->name(), "far") == 0) {
				camera->Far = atof(pGchild->value());
			}

			// Camera Background Color
			if (strcmp(pGchild->name(), "backgroundColor") == 0) {

				float r = 0, g = 0, b = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "r") == 0) {
						r = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "g") == 0) {
						g = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "b") == 0) {
						b = atof(pGgchild->value());
					}

				}

				camera->BackgroundColor = glm::vec3(r, g, b);
			}
		}

		scene->Cameras.insert(std::pair<int, Camera>(id, *camera));
	}
}

void SceneManager::ParseGameObjects(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "gameObject") != 0) {
			std::cout << "ERROR::SCENE_MANAGER_GAME_OBJECTS:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		// Read Game Object Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::SCENE_MANAGER_GAME_OBJECTS:NO_VALID_ID" << std::endl;
			continue;
		}

		GameObject* obj = new GameObject();
		obj->Id = id;

		// Read Game Object Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Name
			if (strcmp(pGchild->name(), "name") == 0) {
				obj->name = (char*)malloc(strlen(pGchild->value()) + 1);
				obj->name = strncpy(obj->name, pGchild->value(), strlen(pGchild->value()));
				obj->name[strlen(pGchild->value())] = '\0';
			}

			// Parent
			if (strcmp(pGchild->name(), "parent") == 0) {
				obj->ParentId = atoi(pGchild->value());
			}

			// Children
			if (strcmp(pGchild->name(), "children") == 0) {

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {
					if (strcmp(pGgchild->name(), "child") == 0) {
						obj->childrenId.push_back(atoi(pGgchild->value()));
					}
				}
			}

			// Transform
			if (strcmp(pGchild->name(), "transform") == 0) {

				Transform* transform = ParseTransform(pGchild);

				if (transform != NULL) {
					obj->transform = transform;
				}
			}

			// Mesh
			if (strcmp(pGchild->name(), "model") == 0) {
				int meshId = atoi(pGchild->value());
				obj->mesh = rm->LoadModel(meshId);
			}

			// Shader
			if (strcmp(pGchild->name(), "shader") == 0) {
				int shaderId = atoi(pGchild->value());
				obj->shader = rm->LoadShader(shaderId);
			}

			// Shader
			if (strcmp(pGchild->name(), "scripts") == 0) {
				
				ParseScripts(pGchild, obj);

			}
		}

		scene->GameObjects.push_back(*obj);
		scene->idToGameObject.insert(std::pair<int, GameObject*>(id, obj));
	}
}

void SceneManager::ParseScripts(xml_node<>* pNode, GameObject* go) {

	
	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {
	
		
		// Read position
		if (strcmp(pChild->name(), "script") == 0) {
			int scriptId = atoi(pChild->value());
			go->scripts.push_back(scriptId);
		}
	}

}


Transform* SceneManager::ParseTransform(xml_node<>* pNode) {

	Transform* transform = new Transform();
	float x, y, z;

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		// Read position
		if (strcmp(pChild->name(), "position") == 0) {

			x = y = z = 0.0f;

			for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

				if (strcmp(pGchild->name(), "x") == 0) {
					x = atof(pGchild->value());
				}
				if (strcmp(pGchild->name(), "y") == 0) {
					y = atof(pGchild->value());
				}				
				if (strcmp(pGchild->name(), "z") == 0) {
					z = atof(pGchild->value());
				}
			}

			transform->SetPosition(glm::vec3(x, y, z));

		}

		// Read rotation
		if (strcmp(pChild->name(), "rotation") == 0) {

			x = y = z = 0.0f;

			for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

				if (strcmp(pGchild->name(), "x") == 0) {
					x = atof(pGchild->value());
				}
				if (strcmp(pGchild->name(), "y") == 0) {
					y = atof(pGchild->value());
				}
				if (strcmp(pGchild->name(), "z") == 0) {
					z = atof(pGchild->value());
				}
			}

			transform->SetRotation(glm::vec3(x, y, z));

		}

		// Read scale
		if (strcmp(pChild->name(), "scale") == 0) {

			x = y = z = 0.0f;

			for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

				if (strcmp(pGchild->name(), "x") == 0) {
					x = atof(pGchild->value());
				}
				if (strcmp(pGchild->name(), "y") == 0) {
					y = atof(pGchild->value());
				}
				if (strcmp(pGchild->name(), "z") == 0) {
					z = atof(pGchild->value());
				}
			}

			transform->SetScale(glm::vec3(x, y, z));

		}
	}

	return transform;

}
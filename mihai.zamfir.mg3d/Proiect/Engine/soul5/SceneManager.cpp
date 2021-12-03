#include "SceneManager.h"

SceneManager* SceneManager::smInstance = NULL;

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

		if (strcmp(pNode->name(), "backgroundColor") == 0) {
			//ParseModels(pNode);
		}

		if (strcmp(pNode->name(), "gameObjects") == 0) {
			ParseGameObjects(pNode);
			//ParseModels(pNode);
		}
	}
}

void SceneManager::ParseGameObjects(xml_node<>* pNode) {

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {

		if (strcmp(pChild->name(), "gameObject") != 0) {
			std::cout << "ERROR::SCENE_MANAGER_GAME_OBJECTS:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		// Read Model Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::SCENE_MANAGER_GAME_OBJECTS:NO_VALID_ID" << std::endl;
			continue;
		}

		GameObject* obj = new GameObject();
		children.insert(std::pair<int, std::list<int>>(id, std::list<int>()));

		// Read Model Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			// Name
			if (strcmp(pGchild->name(), "name") == 0) {
				obj->name = (char*)malloc(strlen(pGchild->value()) + 1);
				obj->name = strncpy(obj->name, pGchild->value(), strlen(pGchild->value()));
				obj->name[strlen(pGchild->value())] = '\0';
			}

			// Parent
			if (strcmp(pGchild->name(), "parent") == 0) {
				parents.insert(std::pair<int, int>(id, atoi(pGchild->value())));
			}

			// Children
			if (strcmp(pGchild->name(), "children") == 0) {

				std::map<int, std::list<int>>::iterator it = children.find(id);
				std::list<int> childrenList = it->second;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {
					if (strcmp(pGgchild->name(), "child") == 0) {
						childrenList.push_back(atoi(pGgchild->value()));
					}
				}
			}

			// Transform
			if (strcmp(pGchild->name(), "model") == 0) {

				Transform* transform = NULL;
				ParseTransform(pGchild, transform);

				if (transform != NULL) {
					obj->transform = transform;
				}
			}

			// Mesh
			if (strcmp(pGchild->name(), "transform") == 0) {
				int meshId = atoi(pGchild->value());
				obj->mesh = rm->LoadModel(meshId);
			}

			/*
			// Shader
			if (strcmp(pGchild->name(), "shader") == 0) {
				int shaderId = atoi(pGchild->value());
				obj->shader = rm->LoadShader(shaderId);
			}
			*/
		}

		scene->GameObjects.push_back(*obj);
	}

	std::map<int, int>::iterator it;

	//std::map<int, int> parents;
	//std::map<int, std::list<int>> children;
	//std::map<int, GameObject*> idToGameObject;

	for (it = parents.begin(); it != parents.end(); i++) {



	}

	/*
	for (it = parents.begin(); it != parents.end(); it++)
	{
		
		std::cout << it->first  // string (key)
			<< ':'
			<< it->second   // string's value 
			<< std::endl;
	}
	*/

}

void SceneManager::ParseTransform(xml_node<>* pNode, Transform* transform) {

	transform = new Transform();
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

}
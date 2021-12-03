#include "Canvas.h"

#include <vector>
#include <iostream>

Canvas::Canvas() {

	//: text, meniuri, butoane, liste, edit boxes

	resolution = ResourceManager::GetInstance()->GetResolution();

	//1280, 720
	projection = glm::ortho(0.0f, (float)resolution.x, 0.0f, (float)resolution.y);
}

Canvas::~Canvas() {

}

void Canvas::Init(xml_node<>* pNode) {

	Texture* defaultTexture = ResourceManager::GetInstance()->LoadTexture(99);
	Texture* cursorTexture = ResourceManager::GetInstance()->LoadTexture(100);

	if (shader == NULL) {
		shader = ResourceManager::GetInstance()->LoadShader(2);
	}

	if (quadMesh == NULL) {
		quadMesh = new UIMesh();
		quadMesh->CreateQuadMesh();
	}

	if (cursor == NULL) {
		cursor = new UIElement();

		cursor->shader = shader;
		cursor->uiMesh = quadMesh;
		cursor->Texture = cursorTexture;

		cursor->depth = -1.0f; // cursor always visible
		cursor->color = glm::vec3(1.0f, 1.0f, 1.0f); // black

		cursor->Scale = glm::vec3(0.025f, 0.025f, 1.0f);
		cursor->Position = glm::vec3(0.25f * resolution.x, 0.25f * resolution.y, 0.0f);

		cursor->Id = 9999;
	}

	for (xml_node<>* pChild = pNode->first_node(); pChild; pChild = pChild->next_sibling()) {


		if (strcmp(pChild->name(), "element") != 0) {
			std::cout << "ERROR::SCENE_MANAGER_CANVAS:UNEXPECTED_ELEMENT" << std::endl;
			continue;
		}

		int id;

		// Read Element Id
		xml_attribute<>* pAttr = pChild->first_attribute("id");
		if (pAttr != NULL) {
			id = atoi(pAttr->value());
		}
		else {
			std::cout << "ERROR::SCENE_MANAGER_CANVAS:NO_VALID_ID" << std::endl;
			continue;
		}

		UIElement* element = new UIElement();
		element->Id = id;

		// Read Element Attributes
		for (xml_node<>* pGchild = pChild->first_node(); pGchild; pGchild = pGchild->next_sibling()) {

			if (strcmp(pGchild->name(), "position") == 0) {

				float x = 0, y = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
				}

				element->Position = glm::vec3(x * resolution.x, y * resolution.y, 0.0);
			}

			if (strcmp(pGchild->name(), "color") == 0) {

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

				element->color = glm::vec3(r, g, b);
			}

			if (strcmp(pGchild->name(), "scale") == 0) {

				float x = 0, y = 0;

				for (xml_node<>* pGgchild = pGchild->first_node(); pGgchild; pGgchild = pGgchild->next_sibling()) {

					if (strcmp(pGgchild->name(), "x") == 0) {
						x = atof(pGgchild->value());
					}
					if (strcmp(pGgchild->name(), "y") == 0) {
						y = atof(pGgchild->value());
					}
				}

				element->Scale = glm::vec3(x, y, 1.0);
			}

			if (strcmp(pGchild->name(), "depth") == 0) {
				element->depth = atof(pGchild->value());
			}

		}

		element->uiMesh = quadMesh;
		element->shader = shader;
		element->Texture = defaultTexture;

		std::cout << "UIElement " << element->Texture->texture << std::endl;

		UIElements.push_back(*element);
		idToUIElement.insert(std::pair<int, UIElement*>(id, element));
	}

	UIList* element = new UIList();

	//auto mihai = new UIList();

	// TEST
	UIGameObjects.push_back(UIList());
	UIGameObjects.push_back(UIEditBox());



}

void Canvas::Update(double deltaTime) {

	GetElementUnderCursor();

	//std::cout << currentUnderMouseId << std::endl;

}

void Canvas::Draw() {

	for (it_uie = UIElements.begin(); it_uie != UIElements.end(); ++it_uie) {
		it_uie->Draw();
	}

	/*
	for (it_uigo = UIGameObjects.begin(); it_uigo != UIGameObjects.end(); ++it_uigo) {
		it_uigo->Draw();
	}
	*/

	DrawMouseCursor();

}

void Canvas::DrawMouseCursor() {


	glm::vec2 mousePosition = Input::GetMousePosition();
	
	cursor->Position = glm::vec3(mousePosition.x, resolution.y - mousePosition.y, 0.0f);
	//cursor->Position = glm::vec3(0.25f * resolution.x, 0.25f * resolution.y, 0.0f);

	cursor->Draw();
}

void Canvas::GetElementUnderCursor() {

	glm::vec2 mousePosition = Input::GetMousePosition();
	
	float currDepth = 0.1f;
	int Id = -1;

	for (it_uie = UIElements.begin(); it_uie != UIElements.end(); ++it_uie) {
		
		glm::vec2 position = it_uie->Position;
		glm::vec2 scale = it_uie->Scale;
		float depth = it_uie->depth;

		if (((mousePosition.x >= position.x) && (mousePosition.x <= position.x + scale.x * resolution.x)) &&
			((mousePosition.y >= position.y - scale.y * resolution.y) && (mousePosition.y <= position.y))) {

			// Mouse over element
			if (it_uie->depth < currDepth) {
				currDepth = it_uie->depth;
				Id = it_uie->Id;
			}
		}

		
		//it_uie->Draw();
	
	}


	/*
	* 	std::map<int, TextureResource*>::iterator imr = textureResources.find(textureId);

	if (imr == textureResources.end()) {
		std::cout << "ERROR::RESOURCE_MANAGER::UNRECOGNIZED_TEXTURE_ID " << textureId << std::endl;
		return NULL;
	}

	std::map<int, Texture*>::iterator im = textures.find(textureId);

	if (im == textures.end()) {
		// The texture was not loaded yet.
		Texture* newTexture = new Texture();
		newTexture->LoadTexture(imr->second->path);
		
		return newTexture;
	}
	else {
		Texture* texture = im->second;
		return texture;
	}

	std::cout << "Return NULL :(" << std::endl;
	return NULL;
	*/


	// If element under mouse changed
	if (Id != currentUnderMouseId) {


		// Previous element gets unselected
		if (currentUnderMouseId != -1) {

			std::map<int, UIElement*>::iterator iue = idToUIElement.find(currentUnderMouseId);

			if (iue != idToUIElement.end()) {

				UIElement* element = iue->second;
				element->selected = 0;
				//iue->second->selected = 0;

				std::cout << "CHANGE - DESELECT " << currentUnderMouseId << " " << iue->second->Id << std::endl;
			}

		}

		// Current element gets selected
		if (Id != -1) {

			std::map<int, UIElement*>::iterator iue = idToUIElement.find(Id);

			if (iue != idToUIElement.end()) {
				
				//iue->second->selected = 1;

				UIElement* element = iue->second;
				element->selected = 1;

				std::cout << "CHANGE - SELECT " << Id << " " << iue->second->Id << " " << iue->second->selected << std::endl;

			}

		}

	}

	/*
	if (Id != -1) {
		std::map<int, UIElement*>::iterator iue = idToUIElement.find(Id);

		std::cout << "I am selected " << iue->second->Id << " " << iue->second->selected << std::endl;
	}
	*/

	
	//std::cout << Id << std::endl;
	currentUnderMouseId = Id;
}

#pragma once
#include <glm/glm.hpp>
#include <include/gl.h>
#include <glm/gtc/matrix_transform.hpp>

#include<map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include "Engine/Input.h"
#include "Engine/ResourceManager.h"
#include "Engine/UIElement.h"
#include "Engine/UIMesh.h"


#include "Engine/UIGameObject.h"
#include "Engine/UIList.h"
#include "Engine/UIEditBox.h"


#include "../RapidXML/rapidxml.hpp"
using namespace rapidxml;

class Canvas
{
	
	//https://k2s.cc/file/126ee03269c17
	//https://k2s.cc/file/34330d70c5f2f

	public:
		
		Canvas();
		~Canvas();

		void Update(double deltaTime);
		void Draw();
		void DrawMouseCursor();

		void Init(xml_node<>* pNode);

		std::list<UIElement> UIElements;
		std::map<int, UIElement*> idToUIElement;

		std::list<UIGameObject> UIGameObjects;
		std::map<int, UIGameObject*> idToUIGameObjects;

		// TODO:
		// Depth

	private:

		void GetElementUnderCursor();

		int currentUnderMouseId = -1;

		glm::mat4 projection;
		glm::ivec2 resolution;

		UIMesh* quadMesh;
		Shader* shader;

		UIElement* cursor;

		std::list<UIElement>::iterator it_uie;
		std::list<UIGameObject>::iterator it_uigo;
};

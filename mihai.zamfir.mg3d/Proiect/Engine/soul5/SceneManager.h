#pragma once
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include <iostream>

#include <include/gl.h>

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../RapidXML/rapidxml.hpp"

#include "Engine/ResourceManager.h"

#include "Engine/Mesh.h"
#include "Engine/Texture.h"
#include "Engine/Shader.h"
#include "Engine/Transform.h"

#include "Engine/GameObject.h"
#include "Engine/Scene.h"

using namespace rapidxml;

class SceneManager
{
	
	public:

		void Init();
		static SceneManager* GetInstance();
		~SceneManager();


	private:
		SceneManager();

		static SceneManager* smInstance;

		void ParseGameObjects(xml_node<>* pNode);
		void ParseTransform(xml_node<>* pNode, Transform* transform);

		glm::vec3 backgroundColor;

		ResourceManager* rm;

		Scene *scene;

		std::map<int, int> parents;
		std::map<int, std::list<int>> children;
		std::map<int, GameObject*> idToGameObject;

};

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
#include "Engine/Camera.h"

using namespace rapidxml;

class SceneManager
{
	
	public:

		void Init();
		static SceneManager* GetInstance();
		~SceneManager();

		static Camera* GetActiveCamera();
		static Scene* GetActiveScene();

	private:
		SceneManager();

		static SceneManager* smInstance;
		static Scene* scene;

		void ParseCameras(xml_node<>* pNode);
		void ParseGameObjects(xml_node<>* pNode);
		void ParseCanvas(xml_node<>* pNode);
		Transform* ParseTransform(xml_node<>* pNode);
		void ParseScripts(xml_node<>* pNode, GameObject* go);

		glm::vec3 backgroundColor;

		ResourceManager* rm;
};
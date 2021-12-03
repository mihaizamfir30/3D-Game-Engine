#pragma once

#include <include/gl.h>

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include "Engine/GameObject.h"
#include "Engine/Camera.h"
#include "Engine/Light.h"

#include "Engine/UI.h"
#include "Engine/Texture.h"

class Scene
{
	public:
		Scene();
		~Scene();

		void OnFrameStart();
		void Update(double deltaTime);
		void OnFrameEnd();

		void SetActiveCamera(int id);

		int activeCameraId;
		std::map<int, Camera> Cameras;
		std::list<GameObject> GameObjects;
		std::map<int, GameObject*> idToGameObject;

		void Start();
		void UpdateFramerate(double deltaTime);

	private:

		Light* light;

		Texture* texture;
		Camera* camera;

		std::list<GameObject>::iterator it_go;
};

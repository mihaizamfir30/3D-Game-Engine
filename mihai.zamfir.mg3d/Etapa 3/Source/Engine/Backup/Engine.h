#pragma once

#include <include/glm.h>

#include <GL/glew.h>

#include <include/gl.h>

#include "Window.h"
#include "Input.h"

#include "Engine/GameObject.h"
#include "Engine/Mesh.h"
#include "Engine/Texture.h"
#include "Engine/Transform.h"
#include "Engine/Engine.h"
#include "Engine/Shader.h"
#include "Engine/Utils.h"
#include "Engine/Math3D.h"
#include "Engine/Scene.h"

#include <Engine/ResourceManager.h>
#include <Engine/SceneManager.h>

typedef struct {
	std::string name;
	glm::ivec2 resolution;
	glm::ivec2 position;
	glm::ivec2 cursorPos;
	float aspectRatio;
	bool resizable;
	bool visible;
	bool fullScreen;
	bool centered;
	bool hideOnClose;
	bool vSync;
} windowProperties;

class Engine
{
	

	public:
		Engine();
		~Engine();

		void Init();
		bool Update();

	private:
		windowProperties wp;
		Window* myWindow;

		Scene* scene;

		double previousTime;
		double currentTime;
		double deltaTime;

	private:

};
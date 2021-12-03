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

#include "../RapidXML/rapidxml.hpp"
using namespace rapidxml;

class UIGameObject
{

	public:
		
		UIGameObject();
		~UIGameObject();

		virtual void Draw();

		glm::vec2 Position;
		glm::vec2 Scale;
		float depth;

		Shader* shader;

	protected:
		UIElement* uiElements;
		int noUIElements;

	private:
};

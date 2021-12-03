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

#include "../RapidXML/rapidxml.hpp"
using namespace rapidxml;

class UIList : public UIGameObject
{

	public:
		
		UIList();
		~UIList();

		void Draw() override;

	private:
};

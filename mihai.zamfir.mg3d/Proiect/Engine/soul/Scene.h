#pragma once

#include <include/gl.h>

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Scene
{
	public:
		Scene();
		~Scene();

		void OnFrameStart();
		void OnFrameEnd();

	private:

};

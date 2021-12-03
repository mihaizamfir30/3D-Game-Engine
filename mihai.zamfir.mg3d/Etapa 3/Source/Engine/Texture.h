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
#include <list>

#include "stb_image.h"
#include "Utils.h"

class Texture
{
	public:
		Texture();
		~Texture();

		void LoadTexture(const GLchar* texturePath);

		unsigned int texture;

	private:
		int width, height, nrChannels;
};

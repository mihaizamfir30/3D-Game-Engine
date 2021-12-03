#pragma once

#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include <iostream>


#include <include/glm.h>

#include <GL/glew.h>

#include <include/gl.h>

#include "Engine/Texture.h"
#include "Engine/Transform.h"
#include "Engine/Shader.h"

#include "Engine/ResourceManager.h"

#include <ft2build.h>
#include FT_FREETYPE_H

struct Character {
	unsigned int TextureID; // ID handle of the glyph texture
	glm::ivec2 Size; // Size of the glyph
	glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
	unsigned int Advance; // Offset to advance to next glyph
};

class TextRenderer
{
	
	public:
		TextRenderer();
		~TextRenderer();

		static TextRenderer* GetInstance();

		void Init();

		void RenderText(std::string text, float x, float y, float depth, float scale, glm::vec3 color);

		Shader* Shader;

	private:
		std::map<char, Character> Characters;

		unsigned int VAO, VBO;

		static TextRenderer* trInstance;
		glm::mat4 projection;
		glm::ivec2 resolution;
};
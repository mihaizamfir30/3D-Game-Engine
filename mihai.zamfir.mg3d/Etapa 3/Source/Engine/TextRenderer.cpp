#include "TextRenderer.h"

#include <vector>
#include <iostream>

TextRenderer* TextRenderer::trInstance = NULL;

TextRenderer::TextRenderer() {
}

TextRenderer::~TextRenderer() {

}

TextRenderer* TextRenderer::GetInstance() {
	
	if (trInstance == NULL) {
		trInstance = new TextRenderer();
	}

	return trInstance;

}

void TextRenderer::Init() {
	
	// Init Library
	FT_Library ft;

	if (FT_Init_FreeType(&ft))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		return;
	}

	// Load font
	FT_Face face;

	if (FT_New_Face(ft, "../Resources/Fonts/arial.ttf", 0, &face))
	{
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
	}

	// Set font size
	FT_Set_Pixel_Sizes(face, 0, 48);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

	// load character glyph for first 128 ascii characters
	for (unsigned char c = 0; c < 128; c++) {

		// load character glyph
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "ERROR::FREETYPE: Failed to load Glyph" << std::endl;
			continue;
		}

		// generate texture
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

		// set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// now store characters for later use
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};

		Characters.insert(std::pair<char, Character>(c, character));
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	resolution = ResourceManager::GetInstance()->GetResolution();

	//1280, 720
	projection = glm::ortho(0.0f, (float)resolution.x, 0.0f, (float)resolution.y);

	// Create mesh
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
}


void TextRenderer::RenderText(std::string text, float x, float y, float depth, float scale, glm::vec3 color) {

	// Activate corresponding render state
	Shader->use();
	Shader->setVec3("textColor", color);
	Shader->setMat4("projection", projection);
	Shader->setFloat("depth", depth);

	x = x * resolution.x;
	y = y * resolution.y;

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);

	// iterate through all the characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];

		float xpos = x + ch.Bearing.x * scale;
		float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		float w = ch.Size.x * scale;
		float h = ch.Size.y * scale;

		// update VBO for each character
		float vertices[6][4] = {
			{xpos,		ypos + h,	0.0f, 0.0f},
			{xpos,		ypos,	    0.0f, 1.0f},
			{xpos + w,	ypos,		1.0f, 1.0f},

			{xpos,		ypos + h,	0.0f, 0.0f},
			{xpos + w,	ypos,		1.0f, 1.0f},
			{xpos + w,	ypos + h,	1.0f, 0.0f}
		};

		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);

		// update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		
		// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64)
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}
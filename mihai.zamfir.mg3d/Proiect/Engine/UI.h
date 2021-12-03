#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>

#include <list>

class UI
{
	public:
		UI();
		~UI();

		static glm::vec4 GetScaleAndOffset(char ascii);

	private:

		// 637 33
		static float width;
		static float height;
};
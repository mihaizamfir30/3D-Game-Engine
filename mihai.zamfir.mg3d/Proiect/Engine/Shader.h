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

#include "Utils.h"

class Shader
{
	

	public:

		Shader();
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

		~Shader();

		void use();

		void setBool(const std::string &name, bool value);
		void setInt(const std::string& name, int value);
		void setFloat(const std::string& name, float value);

		void setVec3(const std::string& name, glm::vec3 value);
		void setVec4(const std::string& name, glm::vec4 value);

		void setMat4(const std::string& name, glm::mat4 value);

	private:

	public:
		unsigned int ID; // the program ID
	private:

};

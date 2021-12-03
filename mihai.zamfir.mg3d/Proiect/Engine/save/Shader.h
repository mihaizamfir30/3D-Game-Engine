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

using namespace std;

class Shader
{
	

	public:
		Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
		//Shader(const string* vertexPath, const string* fragmentPath);

		~Shader();

		void use();

		void setBool(const string &name, bool value);
		void setInt(const string& name, int value);
		void setFloat(const string& name, float value);

		void setVec3(const string& name, int value);
		void setMat4(const string& name, glm::mat4 mat);

	private:

	public:
		unsigned int ID; // the program ID
	private:


		/*
		const char* vShaderCode = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aColor;\n"
			"out vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			" gl_Position = vec4(aPos, 1.0);\n"
			" ourColor = aColor;\n"
			"}\0";

		const char* fShaderCode = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			" FragColor = vec4(ourColor, 1.0);\n"
			"}\0";
		*/

};

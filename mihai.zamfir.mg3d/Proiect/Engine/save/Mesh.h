#pragma once

#include <include/glm.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GL/glew.h>

#include <include/gl.h>

#include "stb_image.h"


#include "Engine/Transform.h"

using namespace std;


typedef struct {
	glm::vec4 pos;
} vertex;


/*
#include <Component/SimpleScene.h>
using namespace std;
typedef struct {
	glm::vec3 p[8];
	glm::vec3 n[8];
	double val[8];

} GRIDCELL;

typedef struct {
	glm::vec3 p[3]; //varfurile
	glm::vec3 c;	//centrul
	glm::vec3 n[3]; //normale
} TRIANGLE;
*/

class Mesh
{
	

	public:
		Mesh();
		~Mesh();

		void Draw();

		glm::mat4 trans;

	private:

		//float vertices[];

		/*
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"layout (location = 1) in vec3 aColor;\n"
			"out vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			" gl_Position = vec4(aPos, 1.0);\n"
			" ourColor = aColor;\n"
			"}\0";

		const char* fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 ourColor;\n"
			"void main()\n"
			"{\n"
			" FragColor = vec4(ourColor, 1.0);\n"
			"}\0";
		*/

	private:
		unsigned int shaderProgram;

		void loadTexture();
};

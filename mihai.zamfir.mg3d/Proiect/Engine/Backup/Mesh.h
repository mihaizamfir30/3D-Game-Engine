#pragma once

#include <include/glm.h>

#include <GL/glew.h>

#include <include/gl.h>

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

	private:
		float vertices;

		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

	private:

};

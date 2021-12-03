#pragma once

#include <include/glm.h>

#include <GL/glew.h>

#include <include/gl.h>

#include "Window.h"

using namespace std;



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


typedef struct {
	std::string name;
	glm::ivec2 resolution;
	glm::ivec2 position;
	glm::ivec2 cursorPos;
	float aspectRatio;
	bool resizable;
	bool visible;
	bool fullScreen;
	bool centered;
	bool hideOnClose;
	bool vSync;
} windowProperties;

class Engine
{
	

	public:
		Engine();
		~Engine();

		void Init();

	private:
		windowProperties wp;

		Window* myWindow;

		GLFWwindow* window;

	private:

};

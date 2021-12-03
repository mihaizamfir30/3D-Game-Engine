#pragma once

#include <GL/glew.h>
#include <include/gl.h>
#include <include/glm.h>

#include <iostream>

#include "Input.h"

using namespace std;

class Window {

	public:
		Window(glm::ivec2 resolution);
		~Window();

		void Init();

		void OnFrameStart();
		void OnFrameEnd();

		bool update();

	private:
		GLFWwindow* window;

		glm::ivec2 resolution;

		void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		void processInput();
};
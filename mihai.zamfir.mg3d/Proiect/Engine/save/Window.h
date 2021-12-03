#pragma once

#include <GL/glew.h>
#include <include/gl.h>
#include <include/glm.h>

#include <iostream>

using namespace std;

class Window {

	public:
		Window();
		~Window();

		void Init();

		bool update();

	private:
		GLFWwindow* window;

		void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		void processInput();
};
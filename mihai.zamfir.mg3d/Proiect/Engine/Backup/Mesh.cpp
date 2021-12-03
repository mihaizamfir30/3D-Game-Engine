#include "Mesh.h"

#include <vector>
#include <iostream>

Mesh::Mesh() {


	/* Initialize the library */
	if (!glfwInit())
		exit(0);

	// Set context version
	
	//glfwWindowHint(GLFW_VISIBLE, 
	//glfwWindowHint(GLFW_VISIBLE, props.visible);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	glewExperimental = true;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		// Serious problem
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		exit(0);
	}

	cout << "We did it, boss" << endl;



	return;


	/* Initialize the library */
	if (!glfwInit())
		exit(0);
	cout << "So far, so good" << endl;


	//GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	return;

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	//glewInit();

	unsigned int VBO;

	return;

	glGenBuffers(1, &VBO);

	return;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	return;

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	int sucess;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &sucess);

	if (sucess == 0) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}
}

Mesh::~Mesh() {}

void Mesh::Draw() {

}
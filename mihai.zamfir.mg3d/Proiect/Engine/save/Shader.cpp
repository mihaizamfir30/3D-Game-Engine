#include "Shader.h"
#include "Utils.h"

//Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {

Shader::Shader(const GLchar* vertexShaderName, const GLchar* fragmentShaderName) {
	
	std::string vertexPath = std::string(Utils::GetShaderPath());
	vertexPath += vertexShaderName;

	std::string fragmentPath = std::string(Utils::GetShaderPath());
	fragmentPath += fragmentShaderName;

	// retrieve the vertex/fragment source code from filePath
	string vertexCode;
	string fragmentCode;

	ifstream vShaderFile;
	ifstream fShaderFile;

	// ensure ifstream objects can throw exceptions
	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

	try {
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		stringstream vShaderStream, fShaderStream;

		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		// close file handlers
		vShaderFile.close();
		fShaderFile.close();

		// convert stream intro string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (ifstream::failure e) {
		cout << "ERROR::SHADER:FILE_NOT_SUCCESFULLY_READ" << endl;
		return;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// compile shaders
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (success == false) {
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}

	// fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (success == false) {
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
	}

	// shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	use();
	
	// print linking errors if any
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (success == false) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}

	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertex);
	glDeleteShader(fragment);


	glUniform1i(glGetUniformLocation(ID, "ourTexture1"), 0); // set it manually
	setInt("ourTexture2", 1); // or with shader class
}

Shader::~Shader() {
}

void Shader::use() {
	glUseProgram(ID);
}

void Shader::setBool(const string& name, bool value) {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const string& name, int value) {

	int loc = glGetUniformLocation(ID, name.c_str());

	cout << "SetInt: " << name << " " << loc << endl;

	glUniform1i(loc, value);
}

void Shader::setFloat(const string& name, float value) {

	int loc = glGetUniformLocation(ID, name.c_str());
	cout << "SetFloat " << loc << endl;

	glUniform1f(loc, value);
}

void Shader::setVec3(const string& name, int value) {

	int loc = glGetUniformLocation(ID, name.c_str());

	cout << "SetInt: " << name << " " << loc << endl;

	glUniform1i(loc, 127.0);
}

void Shader::setMat4(const string& name, glm::mat4 value) {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
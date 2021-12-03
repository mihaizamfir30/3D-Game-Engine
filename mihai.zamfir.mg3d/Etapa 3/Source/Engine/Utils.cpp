#include "Utils.h"

#include <vector>
#include <iostream>


Utils::Utils() {

}

Utils::~Utils() {

}

char* Utils::GetShaderPath() {
	return "../Resources/Shaders/";
}

char* Utils::GetTexturePath() {
	return "../Resources/Textures/";
}

char* Utils::GetScriptPath() {
	return "../Resources/Scripts/";
}


char* Utils::GetModelPath() {
	return "../Resources/Models/";
}

void Utils::PrintIndent(int indentLevel) {
	for (size_t i = 0; i < indentLevel; i++)
	{
		std::cout << "	";
	}
}
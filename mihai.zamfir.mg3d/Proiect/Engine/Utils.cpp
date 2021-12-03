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

char* Utils::GetModelPath() {
	return "../Resources/Models/";
}
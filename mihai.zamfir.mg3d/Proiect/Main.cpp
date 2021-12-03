#pragma once

#include <ctime>
#include <iostream>

using namespace std;


#include "Engine/Engine.h"

#include <stdio.h>  /* defines FILENAME_MAX */

#define WINDOWS

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


int main(int argc, char **argv)
{

	/*
	glm::mat4 mihai = glm::mat4();

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << mihai[i].x << " " << mihai[i].y << " " << mihai[i].z << " " << mihai[i].w << std::endl;
	}

	return 0;
	*/

	Engine engine = Engine();

	while (engine.Update() == true) {
		
	}

	return 0;
}
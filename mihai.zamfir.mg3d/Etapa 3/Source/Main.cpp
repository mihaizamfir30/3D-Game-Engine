#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include "Engine/Engine.h"

int main(int argc, char **argv)
{
	Engine engine = Engine();

	while (engine.Update() == true) {

	}

	return 0;
}
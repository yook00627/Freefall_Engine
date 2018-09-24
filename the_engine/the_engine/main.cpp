#include <iostream>
#include <GLFW/glfw3.h>
#include "src/window/window.h"

int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	
	Window window("Miner", 1280, 720);

	while (!window.closed())
	{
		window.update();
	}

	return 0;
}
#include <iostream>
#include "src/window/window.h"

int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	
	Window window("Miner", 1280, 720);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

	while (!window.closed())
	{
		window.clear();

		glBegin(GL_QUADS);
		glVertex2f(-0.2f, -0.33f);
		glVertex2f( 0.2f,-0.33f);
		glVertex2f( 0.2f,  0.33f);
		glVertex2f(-0.2f,  0.33f);
		glEnd();

		window.update();
	}

	return 0;
}
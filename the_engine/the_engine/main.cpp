#include <iostream>
#include <math.h>
#include "src/window/window.h"
#include "src/shapes/shapes.h"


int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;

	
	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

	GLuint var;
	glGenVertexArrays(1, &var);
	glBindVertexArray(var);

	while (!window.closed())
	{
		window.clear();

		//drawcircle(.4f, 40);
		//Triangle tri(10, 10);
		//tri.Create_Triangle();
		Square r(10);
		r.draw_rectangle();

		window.update();
	}

	return 0;
}
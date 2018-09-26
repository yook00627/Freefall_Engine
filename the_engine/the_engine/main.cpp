#include <iostream>
#include <math.h>
#include "src/window/window.h"
#include "src/shapes/shapes.h"

#define S_WIDTH 1280
#define S_HEIGHT 720

int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	
	Window window("Miner", S_WIDTH, S_HEIGHT);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);

	GLuint var;
	glGenVertexArrays(1, &var);
	glBindVertexArray(var);

	while (!window.closed())
	{
		window.clear();
#if 0
		glBegin(GL_QUADS);
		glVertex2f(-0.2f, -0.33f);
		glVertex2f( 0.2f,-0.33f);
		glVertex2f( 0.2f,  0.33f);
		glVertex2f(-0.2f,  0.33f);
		glEnd();
#endif
		drawcircle(.4f, 40);
		Triangle tri(10, 10);
		tri.Create_Triangle();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);

		window.update();
	}

	return 0;
}
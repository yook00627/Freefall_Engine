#include <iostream>
#include <math.h>
#include "src/window/window.h"
#include "src/shapes/shapes.h"
#include "src/input/input.h"


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
#if 0
		glBegin(GL_QUADS);
		glVertex2f(-0.2f, -0.33f);
		glVertex2f( 0.2f,-0.33f);
		glVertex2f( 0.2f,  0.33f);
		glVertex2f(-0.2f,  0.33f);
		glEnd();
#endif
		//drawcircle(.4f, 40);
		//Triangle tri(10, 10);
		//tri.Create_Triangle();
		Rectangle rect(10, 10);
		rect.Create_Rectangle();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);

		window.update();
	}

	return 0;
}
#include <iostream>
#include "../window/window.h"

int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;

	//creates windows called triangle
	Window window("Triangle", 800, 600);
	//sets color to black and opaque
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	while (!window.closed())
	{
		//clears window
		window.clear();

		glBegin(GL_TRIANGLES);
		glColor3f(0.5, 0, 0);
		glVertex2f(300.0, 210.0);
		glVertex2f(340.0, 215.0);
		glVertex2f(320.0, 250.0);

		glEnd();

		glFlush();

	}
	return 0;
}
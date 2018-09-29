#if 1
#include <iostream>
#include <math.h>
#include "src/window/window.h"
#include "src/shapes/shapes.h"

int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	using namespace input;

	//FULL SCREEN MODE OR WIDNOW MODE
	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	KeyboardMouse input_keys;
	GLuint var;


	double old_time = 0;
	double new_time = 0;

	glGenVertexArrays(1, &var);
	glBindVertexArray(var);

	const float DEG2RAD = 3.14159 / 180;
	//IMPORTANT CREATE OBJECTS OUTSIDE OF LOOP, VECTOR CONSTRUCTOR REFRESHES VECTORS OTHERWISE
	//drawcircle(.4f, 40);
	//Triangle tri(10, 10);
	//tri.Create_Triangle();
	//Square r(1);
	while (!window.closed())
	{
		window.clear();

		if (input_keys.key_pressed(GLFW_KEY_SPACE))
		{
			std::cout << "pressed space" << std::endl;
		}
		if (input_keys.key_pressed(GLFW_KEY_F11))
		{
			window.windowSizeToggle();
		}
		if (input_keys.mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "pressed mouse" << std::endl;
		}
		drawCircle(.2f);
		old_time = new_time;
		new_time = glfwGetTime();
		//r.vectors.update_position(new_time - old_time);
		//r.draw_rectangle();
		std::cout << new_time << std::endl;
		//double x, y;
		//input_keys.get_mouse_position(x, y);
		//std::cout << "x postion: " << x << " y position: " << y << std::endl;

		window.update();
	}

	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <GL/glut.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;

void reshape(int width, int heigth) {
	/* window ro reshape when made it bigger or smaller*/

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//clip the windows so its shortest side is 2.0
	if (width < heigth) {
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
	}
	else {
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth, 2.0, 2.0);
	}
	// set viewport to use the entire new window
	glViewport(0, 0, width, heigth);
}

void rect() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.1, -0.2);
	glVertex2f(-0.1, 0.2);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.1, -0.2);
	glEnd();

}

void display() {
	//Clear Window
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	rect();
	glPopMatrix();
	glFlush();
}


void init() {
	// set clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set fill color to white
	glColor3f(1.0, 1.0, 1.0);

	//set up standard orthogonal view with clipping
	//box as cube of side 2 centered at origin
	//This is the default view and these statements could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

}
float move_unit = 0.04f;
void keyboardown(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		posX += move_unit;;
		break;

	case GLUT_KEY_LEFT:
		posX -= move_unit;;
		break;

	case GLUT_KEY_UP:
		posY += move_unit;;
		break;

	case GLUT_KEY_DOWN:
		posY -= move_unit;;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv) {

	//initialize mode and open a windows in upper left corner of screen
	//Windows tittle is name of program

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Practice 1");
	glutDisplayFunc(display);
	init();
	glutSpecialFunc(keyboardown);
	glutMainLoop();
}
#endif

#include <iostream>
#include <math.h>

#include "src/window/window.h"
#include "src/shapes/shapes.h"
#include "src/window/text.h"


#if 1
int main(int argc, char *argv)
{

	using namespace engine;
	using namespace graphics;
	using namespace input;

	float old_time = 0.0f;
	float new_time = 0.0f;

	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.5f, 0.5f, 0.5f, -0.5f);
	KeyboardMouse input_keys;

	//GLuint var;
	//glGenVertexArrays(1, &var);
	//glBindVertexArray(var);

	Circle ball(0.05f, 0.0f, 0.8f, 1.0f);
	Line box(-0.08f, -0.5f, 0.08f, -0.5f, -0.08f, -0.3f, 0.08f, -0.3f);
	Collision test(ball, box);

	bool sw = false;
	ball.vectors.vel.x = 0.5f;
	int score = 0;
	float dif = 0;

	bool start = false;

#if 0
	TextRenderer *Text = new TextRenderer(SCREEN_WIDTH, SCREEN_HEIGHT);
	Text->Load("src/window/arial.ttf", 24);
#endif

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (!window.closed())
	{
		window.clear();

		if (!start)
		{
			float space = 0.0f;
			//P
			glLineWidth(2);
			glBegin(GL_LINES);
			glVertex2f(0.0f + space / 1.7, 0.0f);
			glVertex2f(0.03f + space /1.7, 0.0f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.03f + space / 1.7, 0.0f);
			glVertex2f(0.03f + space / 1.7, -0.03f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.03f + space / 1.7, -0.03f);
			glVertex2f(0.0f + space / 1.7, -0.03f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.0f + space / 1.7, 0.0f);
			glVertex2f(0.0f + space / 1.7, -0.06f);
			glEnd();

			//R
			space = 0.06f;
			glBegin(GL_LINES);
			glVertex2f(0.0f + space / 1.7, 0.0f);
			glVertex2f(0.03f + space / 1.7, 0.0f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.03f + space / 1.7, 0.0f);
			glVertex2f(0.03f + space / 1.7, -0.03f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.03f + space / 1.7, -0.03f);
			glVertex2f(0.0f + space / 1.7, -0.03f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.0f + space / 1.7, 0.0f);
			glVertex2f(0.0f + space / 1.7, -0.06f);
			glEnd();
			glBegin(GL_LINES);
			glVertex2f(0.0f + space / 1.7, -0.03f);
			glVertex2f(0.03f + space / 1.7, -0.06f);
			glEnd();

			//Text->RenderText("PRESS ENTER TO START", SCREEN_WIDTH / 3.5, SCREEN_HEIGHT / 2.2, 2.0f, glm::vec3(1.0, 1.0, 0.0));
		}
		if (input_keys.key_pressed(GLFW_KEY_ENTER) && start == false)
		{
			start = true;
			glfwWaitEvents();
		}
		if (start)
		{
			if (input_keys.key_pressed(GLFW_KEY_ENTER) )
			{
				start = true;
				glfwWaitEvents();
			}

			//drawing circle game

			//Text->RenderText("Lives:" + std::to_string(score), 5.0f, 5.0f, 1.0f);
#if 1
			old_time = new_time;
			new_time = glfwGetTime();
			//std::cout << new_time << std::endl;

			box.drawline();
			ball.drawCircle();
			test.lineCircle(ball, box);

			if (ball.vectors.pos.x > 0.8f || ball.vectors.pos.x < -0.8f)
				ball.vectors.vel.x = (ball.vectors.pos.x>0?-1:1)*abs(ball.vectors.vel.x);

			if (ball.vectors.pos.y < -1.2f)
			{
				ball.vectors.reset(0.0f, 0.8f, 1.0f + dif, 0.0f, 0.0f, 0.0f);
				score++;
				std::cout << score << std::endl;
			}
		
			ball.vectors.update_position(new_time - old_time);

			if (sw)
			{
				//r.vectors.update_position(new_time - old_time);
				ball.vectors.vel.x = 0.0f;
				ball.vectors.accel.y = -9.8f;
				ball.vectors.update_position(new_time - old_time);
				sw = false;
			
			}
			if (test.lineCircle(ball, box))
			{
				std::cout << "I HIT SOMETHING" << std::endl;
			}

			if (input_keys.key_pressed(GLFW_KEY_SPACE))
			{
				sw = true;
				dif += 0.002f;
			}

			if (input_keys.key_pressed(GLFW_KEY_ESCAPE))
			{
				window.~Window();
				exit(0);
			}
			if (input_keys.key_pressed(GLFW_KEY_F11))
			{
				window.windowSizeToggle();
			}

			if (input_keys.mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
			{
				double x, y;
				input_keys.get_mouse_position(x, y);
				std::cout << "x postion: " << x << " y position: " << y << std::endl;
			}
#endif
		}
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


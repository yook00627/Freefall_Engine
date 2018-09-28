#include <iostream>
#include <math.h>
#include "src/window/window.h"
#include "src/shapes/shapes.h"
#include "src/math/vec2.h"


int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	using namespace input;
	using namespace math;

	
	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	KeyboardMouse input_keys;
	GLuint var;
	vec2 vector1;
	vec2 vector2(2, 3);


	glGenVertexArrays(1, &var);
	glBindVertexArray(var);

	while (!window.closed())
	{
		window.clear();
#if 0
		//drawcircle(.4f, 40);
		//Triangle tri(10, 10);
		//tri.Create_Triangle();
		Square r(10);
		r.draw_rectangle();
		//vector.add(vec2(2, 3));
		std::cout << (vector1 != vector2) << std::endl;
		if (input_keys.key_pressed(GLFW_KEY_SPACE))
		{
			std::cout << "pressed space" << std::endl;
		}
		if (input_keys.mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "pressed mouse" << std::endl;
		}
		double x, y;
		input_keys.get_mouse_position(x, y);
		std::cout << "x postion: " << x << " y position: " << y << std::endl;
#endif
		window.update();
	}

	return 0;
}
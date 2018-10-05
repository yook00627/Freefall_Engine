#pragma once

#include "../window/window.h"
#include "../shapes/shapes.h"
#include "../window/text.h"
#include "../window/printer.h"


bool fun(Line &lineb, Line &liner, Line &linel, Circle &ball, engine::input::KeyboardMouse input_keys, bool &sw, float old_time, float new_time)
{
	lineb.drawline();
	liner.drawline();
	linel.drawline();
	ball.drawCircle();

	print_tries(3, -1.6f, 0.95f, 1);
	print_level(3, 1.0f, 0.95f, 0);

	//reseting ball when miss
	if (ball.vectors.pos.y < -1.2f)
	{
		ball.vectors.reset(0.0f, 0.8f, 1.0f, 0.0f, 0.0f, 0.0f);
	}

	//updating position of ball
	ball.vectors.update_position(new_time - old_time);

	//switch for dropping the ball
	if (input_keys.key_pressed(GLFW_KEY_SPACE))
	{
		sw = true;
	}
	if (sw)
	{
		ball.vectors.vel.x = 0.0f;
		ball.vectors.accel.y = -9.8f;
		ball.vectors.update_position(new_time - old_time);
		sw = false;
	}

	//reseting ball when miss
	if (ball.vectors.pos.y < -1.2f)
	{
		return true;
	}
	return false;
}
#include <iostream>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

#include "src/window/window.h"
#include "src/shapes/shapes.h"
#include "src/window/text.h"
#include "src/window/printer.h"
#include "src/movement/fun.h"


//main program to run game
int main(int argc, char *argv)
{
	//using namespaces for winows and input
	using namespace engine;
	using namespace graphics;
	using namespace input;
	
	//create window
	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);

	//got to begin when reset is happend
begin:
	glClearColor(0.5f, 0.5f, 0.5f, -0.5f); //color of screen

	//added to blend the text
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//initializing objects to be used
	//circle object
	Circle ball(0.05f, 0.0f, 0.8f, 1.0f);
	//box object
	Line linel(-0.08f, -0.5f, -0.08f, -0.7f);
	Line lineb(-0.08f, -0.7f, 0.08f, -0.7f);
	Line liner(0.08f, -0.7f, 0.08f, -0.5f);
	//collision detection for box object
	Collision testb(ball, lineb);
	Collision testl(ball, linel);
	Collision testr(ball, liner);
	//lines for 3rd level
	Line line1(-0.1f, 0.5f, 0.1f, 0.4f);
	Line line2(-0.4f, 0.0f, -0.6f, 0.2f);
	Line line3(0.2f, -0.3f, 0.4f, -0.2f);
	Line line4(0.6f, 0.4f, 0.8f, 0.5f);
	//collision for lines
	Collision test1(ball, line1);
	Collision test2(ball, line2);
	Collision test3(ball, line3);
	Collision test4(ball, line4);

	//input detection object
	KeyboardMouse input_keys;

	//initalizing variables
	float old_time = 0.0f;
	float new_time = 0.0f;
	bool sw = false;
	float difficulty = 1.0f;
	ball.vectors.vel.x = difficulty;
	int tries = 4;
	int level = 1;
	bool start = false;
	bool started = false;


	//impletment sound
	PlaySound("sound.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	//game loop
	while (!window.closed())
	{
		window.clear(); //clearing the screen preveiose loop
		//setting values to create delta time
		old_time = new_time;
		new_time = (float)glfwGetTime();
		//input detection to make window full screen or windowed
		if (input_keys.key_pressed(GLFW_KEY_F11))
		{
			window.windowSizeToggle();
		}
		//input detection to reset game
		if (input_keys.key_pressed(GLFW_KEY_R))
		{
			goto begin;
		}
		//input detection for cheating extra lives
		if (input_keys.key_pressed(GLFW_KEY_C))
		{
			tries += 1;
		}
		//input detection for next level
		if (input_keys.key_pressed(GLFW_KEY_N))
		{
			level++;
		}
		if (input_keys.key_pressed(GLFW_KEY_W))
		{
			level = 0;
		}
		//input detection to exit game
		if (input_keys.key_pressed(GLFW_KEY_ESCAPE))
		{
			window.~Window();
			exit(0);
		}
		//goto game over
		if (tries == 0)
		{
			goto end;
		}
		//check for starting the game 
		if (!start)
		{
			print_enter(5, -0.35f, 0.1f);
			if (input_keys.key_pressed(GLFW_KEY_ENTER) && start == false)
			{
				start = true;
				started = true;
				glfwWaitEvents();
			}
		}
		//check to pause the game used for testing
		if (input_keys.key_pressed(GLFW_KEY_P) && !start)
		{
			start = true;
			glfwWaitEvents();
		}

		//game starting point
		if (start)
		{
			if (input_keys.key_pressed(GLFW_KEY_P))
			{
				start = false;
				glfwWaitEvents();
			}

			print_tries(3, -1.6f, 0.95f, tries);
			print_level(3, 1.0f, 0.95f, level);

			//secret
			if (level == 0)
			{
				ball.vectors.vel.x = 0.0f;
				if (fun(lineb, liner, linel, ball, input_keys, sw, old_time, new_time))
					goto end;
			}

			//level 1 of game
			if (level == 1)
			{
				//drawing level 1 objects
				lineb.drawline();
				liner.drawline();
				linel.drawline();
				ball.drawCircle();
				testb.lineCircle(ball, lineb);
				testr.lineCircle(ball, liner);
				testl.lineCircle(ball, linel);


				//limiting movement ball
				if (ball.vectors.pos.x > 0.8f || ball.vectors.pos.x < -0.8f)
					ball.vectors.vel.x = (ball.vectors.pos.x > 0 ? -1 : 1)*abs(ball.vectors.vel.x);

				//reseting ball when miss
				if (ball.vectors.pos.y < -1.2f)
				{
					ball.vectors.reset(0.0f, 0.8f, difficulty, 0.0f, 0.0f, 0.0f);
					tries--;
				}

				//updating position of ball
				ball.vectors.update_position(new_time - old_time);

				//switch for dropping the ball
				if (input_keys.key_pressed(GLFW_KEY_SPACE))
				{
					sw = true;
				}

				//dropping the ball
				if (sw)
				{
					ball.vectors.vel.x = 0.0f;
					ball.vectors.accel.y = -9.8f;
					ball.vectors.update_position(new_time - old_time);
					sw = false;
				}

				//collision activation
				if (testb.lineCircle(ball, lineb))
				{
					std::cout << "I HIT Bottom" << std::endl;
					ball.vectors.resolve_collision(ball, lineb, testb);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;
					ball.vectors.pos.y += (ball.radius - testb.offset);
					std::cout << "bottom offset" << testb.offset << std::endl;
					if (ball.vectors.vel.y < 0)
						ball.vectors.vel.y = -ball.vectors.vel.y;
				}
				else if (testr.lineCircle(ball, liner))
				{
					std::cout << "I HIT right" << std::endl;
					std::cout << "Ball radius" << ball.radius << std::endl;
					ball.vectors.resolve_collision(ball, liner, testr);
					if (testr.is_point)
					{
						if (ball.vectors.pos.x < 0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x > 0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						testl.is_point = false;
					}
					else
					{
						std::cout << "offset" << testr.offset << std::endl;
						ball.vectors.pos.x -= (ball.radius - testr.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (testl.lineCircle(ball, linel))
				{
					std::cout << "I HIT left" << std::endl;
					ball.vectors.resolve_collision(ball, linel, testl);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;

					if (testl.is_point)
					{
						std::cout << "offset " << testl.point_x_offset << " " << testl.point_y_offset << std::endl;
						if (ball.vectors.pos.x < -0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x > -0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x == -0.08f && ball.vectors.pos.y == -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						testl.is_point = false;
					}
					else
					{
						std::cout << "offset" << testl.offset << std::endl;
						ball.vectors.pos.x += (ball.radius - testl.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}

				//win condition detected
				if (ball.vectors.vel.x == 0 && ball.vectors.vel.y == 0 &&
					ball.vectors.accel.x == 0 && ball.vectors.accel.y == 0)
				{
					difficulty = 2.0f;
					ball.vectors.reset(0.0f, 0.8f, difficulty, 0.0f, 0.0f, 0.0f);
					lineb.vectors.vel.x = 1.0f;
					liner.vectors.vel.x = 1.0f;
					linel.vectors.vel.x = 1.0f;
					level++;
					tries = 4;
				}
			}
			//level 2 of game
			if (level == 2)
			{
				//drawing level 1 objects
				lineb.drawline();
				liner.drawline();
				linel.drawline();
				ball.drawCircle();
				testb.lineCircle(ball, lineb);
				testr.lineCircle(ball, liner);
				testl.lineCircle(ball, linel);

				//limiting movement ball and box
				if (ball.vectors.pos.x > 0.8f || ball.vectors.pos.x < -0.8f)
				{
					ball.vectors.vel.x = (ball.vectors.pos.x > 0 ? -1 : 1)*abs(ball.vectors.vel.x);
				}
				if (lineb.vectors.pos.x > 0.8f || lineb.vectors.pos.x < -0.8f)
				{
					lineb.vectors.vel.x = (lineb.vectors.pos.x > 0 ? -1 : 1)*abs(lineb.vectors.vel.x);
				}
				if (liner.vectors.pos.x > 0.8f || liner.vectors.pos.x < -0.8f)
				{
					liner.vectors.vel.x = (liner.vectors.pos.x > 0 ? -1 : 1)*abs(liner.vectors.vel.x);
				}
				if (linel.vectors.pos.x > 0.8f || linel.vectors.pos.x < -0.8f)
				{
					linel.vectors.vel.x = (linel.vectors.pos.x > 0 ? -1 : 1)*abs(linel.vectors.vel.x);
				}

				//reseting ball when miss
				if (ball.vectors.pos.y < -1.2f)
				{
					ball.vectors.reset(0.0f, 0.8f, difficulty, 0.0f, 0.0f, 0.0f);
					tries--;
				}

				//updating position of ball and box
				ball.vectors.update_position(new_time - old_time);
				lineb.vectors.update_position(new_time - old_time);
				liner.vectors.update_position(new_time - old_time);
				linel.vectors.update_position(new_time - old_time);

				//switch for dropping the ball
				if (input_keys.key_pressed(GLFW_KEY_SPACE))
				{
					sw = true;
				}

				//dropping the ball
				if (sw)
				{
					ball.vectors.vel.x = 0.0f;
					ball.vectors.accel.y = -9.8f;
					ball.vectors.update_position(new_time - old_time);
					sw = false;
				}

				//collision activation
				if (testb.lineCircle(ball, lineb))
				{
					std::cout << "I HIT Bottom" << std::endl;
					ball.vectors.resolve_collision(ball, lineb, testb);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;
					ball.vectors.pos.y += (ball.radius - testb.offset);
					std::cout << "bottom offset" << testb.offset << std::endl;
					if (ball.vectors.vel.y < 0)
						ball.vectors.vel.y = -ball.vectors.vel.y;
				}
				else if (testr.lineCircle(ball, liner))
				{
					std::cout << "I HIT right" << std::endl;
					std::cout << "Ball radius" << ball.radius << std::endl;
					ball.vectors.resolve_collision(ball, liner, testr);
					if (testr.is_point)
					{
						if (ball.vectors.pos.x < 0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x > 0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						testl.is_point = false;
					}
					else
					{
						std::cout << "offset" << testr.offset << std::endl;
						ball.vectors.pos.x -= (ball.radius - testr.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (testl.lineCircle(ball, linel))
				{
					std::cout << "I HIT left" << std::endl;
					ball.vectors.resolve_collision(ball, linel, testl);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;

					if (testl.is_point)
					{
						std::cout << "offset " << testl.point_x_offset << " " << testl.point_y_offset << std::endl;
						if (ball.vectors.pos.x < -0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x > -0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x == -0.08f && ball.vectors.pos.y == -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						testl.is_point = false;
					}
					else
					{
						std::cout << "offset" << testl.offset << std::endl;
						ball.vectors.pos.x += (ball.radius - testl.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}

				//win condition detected
				if (ball.vectors.vel.x == 0 && ball.vectors.vel.y == 0 &&
					ball.vectors.accel.x == 0 && ball.vectors.accel.y == 0)
				{
					difficulty = 1.5f;
					ball.vectors.reset(0.0f, 0.8f, 1.0f, 0.0f, 0.0f, 0.0f);
					linel.vectors.reset(0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f);
					lineb.vectors.reset(0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f);
					liner.vectors.reset(0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f);
					level++;
					tries = 4;
				}
			}
			if (level == 3)
			{
				//drawing level 1 objects
				lineb.drawline();
				liner.drawline();
				linel.drawline();
				ball.drawCircle();
				testb.lineCircle(ball, lineb);
				testr.lineCircle(ball, liner);
				testl.lineCircle(ball, linel);

				//draw lines for obstacle
				line1.drawline();
				line2.drawline();
				line3.drawline();
				line4.drawline();
				test1.lineCircle(ball, line1);
				test1.level3 = true;
				test2.lineCircle(ball, line2);
				test2.level3 = true;
				test3.lineCircle(ball, line4);
				test3.level3 = true;
				test4.lineCircle(ball, line4);
				test4.level3 = true;

				//limiting movement ball and box
				if (ball.vectors.pos.x > 0.8f || ball.vectors.pos.x < -0.8f)
				{
					ball.vectors.vel.x = (ball.vectors.pos.x > 0 ? -1 : 1)*abs(ball.vectors.vel.x);
				}
				if (lineb.vectors.pos.x > 0.8f || lineb.vectors.pos.x < -0.8f)
				{
					lineb.vectors.vel.x = (lineb.vectors.pos.x > 0 ? -1 : 1)*abs(lineb.vectors.vel.x);
				}
				if (liner.vectors.pos.x > 0.8f || liner.vectors.pos.x < -0.8f)
				{
					liner.vectors.vel.x = (liner.vectors.pos.x > 0 ? -1 : 1)*abs(liner.vectors.vel.x);
				}
				if (linel.vectors.pos.x > 0.8f || linel.vectors.pos.x < -0.8f)
				{
					linel.vectors.vel.x = (linel.vectors.pos.x > 0 ? -1 : 1)*abs(linel.vectors.vel.x);
				}

				//reseting ball when miss
				if (ball.vectors.pos.y < -1.2f)
				{
					ball.vectors.reset(0.0f, 0.8f, difficulty, 0.0f, 0.0f, 0.0f);
					tries--;
				}

				//updating position of ball and box
				ball.vectors.update_position(new_time - old_time);
				lineb.vectors.update_position(new_time - old_time);
				liner.vectors.update_position(new_time - old_time);
				linel.vectors.update_position(new_time - old_time);

				//switch for dropping the ball
				if (input_keys.key_pressed(GLFW_KEY_SPACE))
				{
					sw = true;
				}

				//dropping the ball
				if (sw)
				{
					ball.vectors.vel.x = 0.0f;
					ball.vectors.accel.y = -9.8f;
					ball.vectors.update_position(new_time - old_time);
					sw = false;
				}

				//collision activation
				if (testb.lineCircle(ball, lineb))
				{
					std::cout << "I HIT Bottom" << std::endl;
					ball.vectors.resolve_collision(ball, lineb, testb);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;
					ball.vectors.pos.y += (ball.radius - testb.offset);
					std::cout << "bottom offset" << testb.offset << std::endl;
					if (ball.vectors.vel.y < 0)
						ball.vectors.vel.y = -ball.vectors.vel.y;
				}
				else if (testr.lineCircle(ball, liner))
				{
					std::cout << "I HIT right" << std::endl;
					std::cout << "Ball radius" << ball.radius << std::endl;
					ball.vectors.resolve_collision(ball, liner, testr);
					if (testr.is_point)
					{
						if (ball.vectors.pos.x < 0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x > 0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testr.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testr.point_y_offset);
						}
						testr.is_point = false;
					}
					else
					{
						std::cout << "offset" << testr.offset << std::endl;
						ball.vectors.pos.x -= (ball.radius - testr.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (testl.lineCircle(ball, linel))
				{
					std::cout << "I HIT left" << std::endl;
					ball.vectors.resolve_collision(ball, linel, testl);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;

					if (testl.is_point)
					{
						std::cout << "offset " << testl.point_x_offset << " " << testl.point_y_offset << std::endl;
						if (ball.vectors.pos.x < -0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x > -0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - testl.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						else if (ball.vectors.pos.x == -0.08f && ball.vectors.pos.y == -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - testl.point_y_offset);
						}
						testl.is_point = false;
					}
					else
					{
						std::cout << "offset" << testl.offset << std::endl;
						ball.vectors.pos.x += (ball.radius - testl.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (test1.lineCircle(ball, line1))
				{
					std::cout << "I HIT left" << std::endl;
					ball.vectors.resolve_collision(ball, line1, test1);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;

					if (test1.is_point)
					{
						std::cout << "offset " << test1.point_x_offset << " " << test1.point_y_offset << std::endl;
						if (ball.vectors.pos.x < -0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - test1.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - test1.point_y_offset);
						}
						else if (ball.vectors.pos.x > -0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - test1.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - test1.point_y_offset);
						}
						else if (ball.vectors.pos.x == -0.08f && ball.vectors.pos.y == -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - test1.point_y_offset);
						}
						test1.is_point = false;
					}
					else
					{
						std::cout << "offset" << test1.offset << std::endl;
						ball.vectors.pos.x += (ball.radius - test1.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (test1.lineCircle(ball, line1))
				{
					std::cout << "I HIT left" << std::endl;
					ball.vectors.resolve_collision(ball, line1, test1);
					std::cout << "new vel " << ball.vectors.vel.x << " " << ball.vectors.vel.y << " " << ball.vectors.accel.y << std::endl;

					if (test1.is_point)
					{
						std::cout << "offset " << test1.point_x_offset << " " << test1.point_y_offset << std::endl;
						if (ball.vectors.pos.x < -0.08f)
						{
							ball.vectors.pos.x -= 0.2f * (ball.radius - test1.point_x_offset);
							ball.vectors.pos.y -= 0.2f * (ball.radius - test1.point_y_offset);
						}
						else if (ball.vectors.pos.x > -0.08f)
						{
							ball.vectors.pos.x += 0.2f * (ball.radius - test1.point_x_offset);
							ball.vectors.pos.y += 0.2f * (ball.radius - test1.point_y_offset);
						}
						else if (ball.vectors.pos.x == -0.08f && ball.vectors.pos.y == -0.45f)
						{
							ball.vectors.pos.y += 0.2f * (ball.radius - test1.point_y_offset);
						}
						test1.is_point = false;
					}
					else
					{
						std::cout << "offset" << test1.offset << std::endl;
						ball.vectors.pos.x += (ball.radius - test1.offset);
					}
					if (ball.vectors.vel.y = 0.0f)
						ball.vectors.accel.y = -9.8f;
				}
				else if (test2.lineCircle(ball, line2))
				{
				std::cout << "I HIT right" << std::endl;
				std::cout << "Ball radius" << ball.radius << std::endl;
				ball.vectors.resolve_collision(ball, line2, test2);
				if (test2.is_point)
				{
					if (ball.vectors.pos.x < 0.08f)
					{
						ball.vectors.pos.x -= 0.2f * (ball.radius - test2.point_x_offset);
						ball.vectors.pos.y -= 0.2f * (ball.radius - test2.point_y_offset);
					}
					else if (ball.vectors.pos.x > 0.08f)
					{
						ball.vectors.pos.x += 0.2f * (ball.radius - test2.point_x_offset);
						ball.vectors.pos.y += 0.2f * (ball.radius - test2.point_y_offset);
					}
					else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
					{
						ball.vectors.pos.y += 0.2f * (ball.radius - test2.point_y_offset);
					}
					test2.is_point = false;
				}
				else
				{
					std::cout << "offset" << test2.offset << std::endl;
					ball.vectors.pos.x -= (ball.radius - test2.offset);
				}
				if (ball.vectors.vel.y = 0.0f)
					ball.vectors.accel.y = -9.8f;
				}
				else if (test3.lineCircle(ball, line3))
				{
				std::cout << "I HIT right" << std::endl;
				std::cout << "Ball radius" << ball.radius << std::endl;
				ball.vectors.resolve_collision(ball, line3, test3);
				if (test3.is_point)
				{
					if (ball.vectors.pos.x < 0.08f)
					{
						ball.vectors.pos.x -= 0.2f * (ball.radius - test3.point_x_offset);
						ball.vectors.pos.y -= 0.2f * (ball.radius - test3.point_y_offset);
					}
					else if (ball.vectors.pos.x > 0.08f)
					{
						ball.vectors.pos.x += 0.2f * (ball.radius - test3.point_x_offset);
						ball.vectors.pos.y += 0.2f * (ball.radius - test3.point_y_offset);
					}
					else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
					{
						ball.vectors.pos.y += 0.2f * (ball.radius - test3.point_y_offset);
					}
					test3.is_point = false;
				}
				else
				{
					std::cout << "offset" << test3.offset << std::endl;
					ball.vectors.pos.x -= (ball.radius - test3.offset);
				}
				if (ball.vectors.vel.y = 0.0f)
					ball.vectors.accel.y = -9.8f;
				}
				else if (test4.lineCircle(ball, line4))
				{
				std::cout << "I HIT right" << std::endl;
				std::cout << "Ball radius" << ball.radius << std::endl;
				ball.vectors.resolve_collision(ball, line4, test4);
				if (test4.is_point)
				{
					if (ball.vectors.pos.x < 0.08f)
					{
						ball.vectors.pos.x -= 0.2f * (ball.radius - test4.point_x_offset);
						ball.vectors.pos.y -= 0.2f * (ball.radius - test4.point_y_offset);
					}
					else if (ball.vectors.pos.x > 0.08f)
					{
						ball.vectors.pos.x += 0.2f * (ball.radius - test4.point_x_offset);
						ball.vectors.pos.y += 0.2f * (ball.radius - test4.point_y_offset);
					}
					else if (ball.vectors.pos.x == 0.08f && ball.vectors.pos.y < -0.45f)
					{
						ball.vectors.pos.y += 0.2f * (ball.radius - test4.point_y_offset);
					}
					testr.is_point = false;
				}
				else
				{
					std::cout << "offset" << test4.offset << std::endl;
					ball.vectors.pos.x -= (ball.radius - test4.offset);
				}
				if (ball.vectors.vel.y = 0.0f)
					ball.vectors.accel.y = -9.8f;
				}




				//if (testb.lineCircle(ball, lineb) || testr.lineCircle(ball, liner) ||
				//	testl.lineCircle(ball, linel) || test1.lineCircle(ball, line1) ||
				//	test2.lineCircle(ball, line2) || test3.lineCircle(ball, line3) | \
				//	test4.lineCircle(ball, line4))
				//{
				//	std::cout << "I HIT SOMETHING" << std::endl;
				//	ball.vectors.resolve_collision(ball, lineb, testb);
				//	ball.vectors.resolve_collision(ball, liner, testr);
				//	ball.vectors.resolve_collision(ball, linel, testl);
				//	ball.vectors.resolve_collision(ball, line1, test1);
				//	ball.vectors.resolve_collision(ball, line2, test2);
				//	ball.vectors.resolve_collision(ball, line3, test3);
				//	ball.vectors.resolve_collision(ball, line4, test4);
				//}

				//win condition detected
				if (ball.vectors.vel.x == 0 && ball.vectors.vel.y == 0 &&
					ball.vectors.accel.x == 0 && ball.vectors.accel.y == 0)
				{
					goto end;
				}
			}
		}
		//input mouse testing
		//if (input_keys.mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
			//{
			//	double x, y;
			//	input_keys.get_mouse_position(x, y);
			//}
		window.update(); //updating the screen with new draws
	}
	//ending screen loop 
end:
	//rendering text using freetype but it cannot coesist with glbegin and end
	TextRenderer Text(SCREEN_WIDTH, SCREEN_HEIGHT);
	Text.Load("src/window/arial.ttf", 24);
	//start music for win
	if (tries > 0 && level != 0)
		PlaySound("win.wav", NULL, SND_ASYNC | SND_FILENAME);
	//start music for gameover
	else
		PlaySound("lose.wav", NULL, SND_ASYNC | SND_FILENAME);
	while (!window.closed())
	{
		window.clear(); //clearing the screen preveiose loop
		//printing win game screen
		if (level == 0)
		{
			Text.RenderText("WHAT ARE YOU DOING", SCREEN_WIDTH / 3.5f, SCREEN_HEIGHT / 2.2f, 2.0f, glm::vec3(1.0f, 1.0f, 0.0f));
			Text.RenderText("ANDREW!!!!!", SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 1.8f, 2.0f, glm::vec3(1.0f, 1.0f, 0.0f));
		}
		else if (tries > 0)
		{
			Text.RenderText("THANK YOU FOR PLAYING", SCREEN_WIDTH / 3.5f, SCREEN_HEIGHT / 2.2f, 2.0f, glm::vec3(1.0f, 1.0f, 0.0f));
			Text.RenderText("!!!!! \\ (^_^) / !!!!!", SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 1.8f, 2.0f, glm::vec3(1.0f, 1.0f, 0.0f));
		}
		//printing game over screen
		else
		{
			Text.RenderText("TOO BAD NO GAME FOR YOU", SCREEN_WIDTH / 3.5f, SCREEN_HEIGHT / 2.2f, 2.0f, glm::vec3(1.0f, 0.0f, 0.0f));
			Text.RenderText("!!!!! (;-_-) / !!!!!", SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 1.8f, 2.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		}
		//input detection to exit game
		if (input_keys.key_pressed(GLFW_KEY_ESCAPE))
		{
			window.~Window();
			exit(0);
		}
		//input detection to reset game
		if (input_keys.key_pressed(GLFW_KEY_R))
		{
			glUseProgramObjectARB(0); //resets the shader program to null
			goto begin;
		}
		window.update(); //updating the screen with new draws
	}
	return 0; //always return zero when game ends
}


//glut usage deprecated
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


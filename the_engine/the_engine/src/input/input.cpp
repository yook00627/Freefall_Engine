#include "input.h"


namespace engine
{

	namespace input
	{
		bool KeyboardMouse::p_keys[MAX_KEYS];
		bool KeyboardMouse::p_mouse_buttons[MAX_MOUSE_BUTTONS];
		double KeyboardMouse::p_mx;
		double KeyboardMouse::p_my;

		//constructor keyboard and mouse
		KeyboardMouse::KeyboardMouse()
		{
			init();
		}

		//deestructor keyboard and mouse
		KeyboardMouse::~KeyboardMouse()
		{
		}

		//check for keyboard pressed
		bool KeyboardMouse::key_pressed(unsigned int keycode)
		{
			if (keycode >= MAX_KEYS)
			{
				std::cout << "Key out of range" << std::endl;
				return false;
			}
			return p_keys[keycode];
		}

		//check for mouse pressed
		bool KeyboardMouse::mouse_button_pressed(unsigned int mousebutton)
		{
			if (mousebutton >= MAX_MOUSE_BUTTONS)
			{
				std::cout << "Button out of range" << std::endl;
				return false;
			}
			return p_mouse_buttons[mousebutton];
		}

		//check for mouse location
		void KeyboardMouse::get_mouse_position(double &x, double &y)
		{
			x = p_mx;
			y = p_my;
		}

		//initializing keyboard and mouse by creating keyboard buffers
		void KeyboardMouse::init()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				p_keys[i] = false;
			}
			for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
			{
				p_mouse_buttons[i] = false;
			}
		}

		//keyboard call back to save to buffer
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			KeyboardMouse::p_keys[key] = GLFW_RELEASE != action;
		}
		//mouse button call back to save to buffer
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			KeyboardMouse::p_mouse_buttons[button] = GLFW_RELEASE != action;
		}
		//mouse location call back to save to buffer
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			KeyboardMouse::p_mx = xpos;
			KeyboardMouse::p_my = ypos;
		}
	}
}
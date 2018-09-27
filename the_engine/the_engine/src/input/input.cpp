#include "input.h"


namespace engine
{
	namespace input
	{
		bool KeyboardMouse::p_keys[MAX_KEYS];
		bool KeyboardMouse::p_mouse_buttons[MAX_BUTTONS];
		double KeyboardMouse::p_mx;
		double KeyboardMouse::p_my;

		KeyboardMouse::KeyboardMouse()
		{
			init();
		}

		KeyboardMouse::~KeyboardMouse()
		{
		}

		bool KeyboardMouse::key_pressed(unsigned int keycode)
		{
			if (keycode >= MAX_KEYS)
			{
				std::cout << "Key out of range" << std::endl;
				return false;
			}
			return p_keys[keycode];
		}

		void KeyboardMouse::init()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				p_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				p_mouse_buttons[i] = false;
			}
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			KeyboardMouse::p_keys[key] = GLFW_RELEASE != action;
		}
	}
}
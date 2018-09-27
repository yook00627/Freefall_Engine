#include "input.h"


namespace engine
{
	namespace input
	{
		bool KeyboardMouse::p_keys[MAX_KEYS];
		bool KeyboardMouse::p_mouse_buttons[MAX_MOUSE_BUTTONS];
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

		bool KeyboardMouse::mouse_button_pressed(unsigned int mousebutton)
		{
			if (mousebutton >= MAX_MOUSE_BUTTONS)
			{
				std::cout << "Button out of range" << std::endl;
				return false;
			}
			return p_mouse_buttons[mousebutton];
		}

		void KeyboardMouse::get_mouse_position(double &x, double &y)
		{
			x = p_mx;
			y = p_my;
		}

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

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			KeyboardMouse::p_keys[key] = GLFW_RELEASE != action;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			KeyboardMouse::p_mouse_buttons[button] = GLFW_RELEASE != action;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			KeyboardMouse::p_mx = xpos;
			KeyboardMouse::p_my = ypos;
		}
	}
}
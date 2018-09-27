#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace engine
{
	namespace input
	{
		constexpr auto MAX_KEYS = 101;
		constexpr auto MAX_BUTTONS = 12;
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		//Class for inputs
		class KeyboardMouse
		{
		private:
			static bool p_keys[MAX_KEYS];
			static bool p_mouse_buttons[MAX_BUTTONS];
			static double p_mx, p_my;
		public:
			KeyboardMouse();
			~KeyboardMouse();
			static bool key_pressed(unsigned int keycode);
		private:
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			void init();
		};
	}
}
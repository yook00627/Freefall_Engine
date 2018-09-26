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
		//Class for inputs
		class KeyboardMouse
		{
		private:
			static bool *keys[MAX_KEYS];
			static bool *mouse_buttons[MAX_BUTTONS];
		public:
			void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}
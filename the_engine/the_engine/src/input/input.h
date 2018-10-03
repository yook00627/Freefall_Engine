#pragma once

#include <iostream>
#include <glew/glew.h>
#include <GLFW/glfw3.h>


namespace engine
{
	namespace input
	{
		constexpr auto MAX_KEYS = 1024; //buffor for keyboard holder
		constexpr auto MAX_MOUSE_BUTTONS = 1024; //buffor for mouse holder
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		//Class for inputs
		class KeyboardMouse
		{
		private:
			static bool p_keys[MAX_KEYS];
			static bool p_mouse_buttons[MAX_MOUSE_BUTTONS];
			static double p_mx, p_my;
		public:
			KeyboardMouse();
			~KeyboardMouse();
			static bool key_pressed(unsigned int keycode);
			static bool mouse_button_pressed(unsigned int mousebutton);
			static void get_mouse_position(double &x, double &y);
		private:
			//friending all callbacks to be able to use private variable of the class
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			void init();
		};
	}
}
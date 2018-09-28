#pragma once

#include <iostream>
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include "../input/input.h"


enum screenstate {
	WINDOW_MODE,
	FULL_SCREEN_MODE
};

namespace engine
{
	namespace graphics
	{
		constexpr auto SCREEN_WIDTH = 1280;;
		constexpr auto SCREEN_HEIGHT = 720;;
		constexpr auto SCREEN_NAME = "IKOKO";

		//Class for openigng up window
		class Window
		{
		private:
			//creates the class attribute for Window class
			int w_width, w_height;
			const char *w_name;
			GLFWwindow *w_window;
			screenstate w_mode;
		public:
			Window(const char *name, int width, int height, screenstate mode);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			//getter for width
			inline int getWidth() const { return w_width; };
			//getter for height
			inline int getHeight() const { return w_height; };
		private:
			bool init();
		};
	}
}
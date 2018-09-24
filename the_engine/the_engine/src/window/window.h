#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

namespace engine
{
	namespace graphics
	{
		class Window
		{
		private:
			int w_width, w_height;
			const char *w_name;
			GLFWwindow *w_window;
		public:
			Window(const char *name, int width, int height);
			~Window();
			bool closed() const;
			void update() const;
		private:
			bool init();
		};

	}
}
#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace engine
{
	namespace graphics
	{
		class Window
		{
		private:
			//creates the class attribute for Window class
			int w_width, w_height;
			const char *w_name;
			GLFWwindow *w_window;
		public:
			//initialize the Window class
			Window(const char *name, int width, int height);
			//terminates widnow class
			~Window();
			//terminate 
			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return w_width;  }
			inline int getHeight() const { return w_height; }

		private:
			bool init();
		};

	}
}
#include "window.h"

namespace engine
{
	namespace graphics
	{
		Window::Window(const char *name, int width, int height)
		{
			w_name = name;
			w_width = width;
			w_height = height;
			if (!init())
			{
				glfwTerminate();
			}
		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init()
		{
			if (!glfwInit())
			{ 
				std::cout << "Fail to start glfw" << std::endl;
				return false;
			}

			w_window = glfwCreateWindow(w_width, w_height, w_name, NULL, NULL);
			if (!w_window)
			{
				glfwTerminate();
				std::cout << "Window not working" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(w_window);
			return true;
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(w_window);
		}
		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(w_window);
		}
	}
}
#include "window.h"

namespace engine
{
	namespace graphics
	{
		void resizeWindow(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

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
			glfwSetWindowSizeCallback(w_window, resizeWindow);
			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(w_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(w_window);
		}
	}
}
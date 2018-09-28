#include "window.h"


namespace engine
{
	using namespace input;
	namespace graphics
	{
		// this resizes the widnow when changed
		void resize_window(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		//creates the Window class
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

		//terminates widnow class
		Window::~Window()
		{
			glfwTerminate();
		}

		//terminate program after window is cloased
		bool Window::closed() const
		{
			return glfwWindowShouldClose(w_window);
		}

		//update the window
		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(w_window);
		}

		//update window when size change
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		//change window to full screen or window
		void Window::windowSizeToggle()
		{
			static bool sw = true;
			if (sw)
			{
				glfwSetWindowMonitor(w_window, glfwGetPrimaryMonitor(), 0, 0, w_width, w_height, 60);
				sw = false;
			}
			else
			{
				glfwSetWindowMonitor(w_window, NULL, 1920/6, 1080/6, w_width, w_height, 60);
				sw = true;
			}
		}

		//initialize the window
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
			glfwSetWindowSizeCallback(w_window, resize_window);
			glfwSetKeyCallback(w_window, key_callback);
			glfwSetMouseButtonCallback(w_window, mouse_button_callback);
			glfwSetCursorPosCallback(w_window, cursor_position_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "can not initialize glew" << std::endl;
				return false;
			}

			return true;
		}
	}
}
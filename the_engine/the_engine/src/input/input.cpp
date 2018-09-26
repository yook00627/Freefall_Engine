#include "input.h"


namespace engine
{
	namespace input
	{
		void KeyboardMouse::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			glfwGetWindowUserPointer(window);
		}
	}
}
#include "input.hpp"

void Input::GetAxis(Axis which, float& axis)
{
	switch(which)
	{
		case Axis::Horizontal:
			if (glfwGetKey(window, GLFW_KEY_A))
			{
				axis = -1;
			}
			if (glfwGetKey(window, GLFW_KEY_D))
			{
				axis = 1;
			}
			break;
		case Axis::Vertical:
			if (glfwGetKey(window, GLFW_KEY_W))
			{
				axis = 1;
			}
			if (glfwGetKey(window, GLFW_KEY_S))
			{
				axis = -1;
			}
			break;
	}
}
#include "Input.h"

namespace crynn
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//Update keystate according to action
		if (action == GLFW_PRESS)
			crynn::Input::UpdateKeyState(key, true);
		else if (action == GLFW_RELEASE)
			crynn::Input::UpdateKeyState(key, false);
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::OnMouseScroll.Invoke(yoffset); //Invoke the OnMouseScroll when GLFW reports a mouse scroll
	}

	bool Input::GetKey(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		return currentKeyStates[std::underlying_type<KeyCode>::type(key)];
	}

	bool Input::GetKeyDown(KeyCode key)
	{
		int keyCode = std::underlying_type<KeyCode>::type(key);	//Cast keycode to its underlying int type because it is a strong enum.

		if (previousKeyStates[keyCode] == false && currentKeyStates[keyCode] == true) //If they werent holding before, but are now.
		{
			UpdateKeyState(keyCode, false);
			return true;
		}
		else if (previousKeyStates[keyCode] == true && currentKeyStates[keyCode] == true) //If they were holding before, and still are
		{
			UpdateKeyState(keyCode, true);
			return false;
		}
		else
			return false;
	}

	void Input::Init()
	{
		if (m_initialised)
			return;

		glfwSetKeyCallback(Window::GetGLFWWin(), key_callback);
		glfwSetScrollCallback(Window::GetGLFWWin(), scroll_callback);

		m_initialised = true;

		std::cout << "Input initialised\n";
	}
}
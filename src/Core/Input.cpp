#include "Input.h"

namespace crynn
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//Update keystate according to action
		if (action == GLFW_PRESS)
			crynn::Input::UpdateKeyStateInternal(key, true);
		else if (action == GLFW_RELEASE)
			crynn::Input::UpdateKeyStateInternal(key, false);
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::OnMouseScroll.Invoke((float)yoffset); //Invoke the OnMouseScroll when GLFW reports a mouse scroll
	}

	void cursor_pos_callback(GLFWwindow* window, double xPos, double yPos) 
	{
		Input::UpdateMousePosInternal(xPos, yPos);
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
			UpdateKeyStateInternal(keyCode, false);
			return true;
		}
		else if (previousKeyStates[keyCode] == true && currentKeyStates[keyCode] == true) //If they were holding before, and still are
		{
			UpdateKeyStateInternal(keyCode, true);
			return false;
		}
		else
			return false;
	}

	inline void Input::UpdateMousePosInternal(int xPos, int yPos)
	{
		m_prevXPos = m_xPos;
		m_prevYPos = m_yPos;

		m_xPos = xPos;
		m_yPos = yPos;
	}

	void Input::Init()
	{
		if (m_initialised)
			return;

		glfwSetKeyCallback(Window::GetGLFWWin(), key_callback);
		glfwSetScrollCallback(Window::GetGLFWWin(), scroll_callback);
		glfwSetCursorPosCallback(Window::GetGLFWWin(), cursor_pos_callback);

		m_initialised = true;

		Debug::Log("Input Initialised");
	}
}
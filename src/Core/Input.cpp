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
		Input::OnMouseScroll.Invoke(yoffset); //Invoke the OnMouseScroll when GLFW reports a mouse scroll
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
	{
		//Update mousebutton keystate according to action
		if (action == GLFW_PRESS)
			crynn::Input::UpdateKeyStateInternal(button, true);
		else if (action == GLFW_RELEASE)
			crynn::Input::UpdateKeyStateInternal(button, false);
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

	void Input::UpdateKeyStateInternal(int key, bool state)
	{
		previousKeyStates[key] = currentKeyStates[key]; //Update previous keystate
		currentKeyStates[key] = state; //Update current keystate
	}

	void Input::UpdateMousePosInternal()
	{
		double xPos = 0, yPos = 0;
		glfwGetCursorPos(Window::GetGLFWWin(), &xPos, &yPos);

		m_prevXPos = m_xPos;
		m_prevYPos = m_yPos;

		m_xPos = xPos;
		m_yPos = yPos;
	}

	Vec2 Input::GetMouseDelta()
	{
		return Vec2
		(
			m_xPos - m_prevXPos,
			m_yPos - m_prevYPos
		);
	}

	void Input::Init()
	{
		if (m_initialised)
			return;

		glfwSetKeyCallback(Window::GetGLFWWin(), key_callback);
		glfwSetScrollCallback(Window::GetGLFWWin(), scroll_callback);
		glfwSetMouseButtonCallback(Window::GetGLFWWin(), mouse_button_callback);

		m_initialised = true;

		Debug::Log("Input Initialised");
	}
}
#include "Window.h"
#include "Input.h"
namespace crynn
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key >= KEYSTATE_BUFFER_MAX_SIZE)
			return;

		//Update keystate according to action
		if (action == GLFW_PRESS)
			crynn::Input::currentKeyStates[key] = true;

		else if (action == GLFW_RELEASE)
		{
			crynn::Input::currentKeyStates[key] = false;
			crynn::Input::getKeyDownStates[key] = false;
		}
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::OnMouseScroll.Invoke(yoffset); //Invoke the OnMouseScroll when GLFW reports a mouse scroll
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
	{
		//Update mousebutton keystate according to action
		if (action == GLFW_PRESS)
			crynn::Input::currentKeyStates[button] = true;
		else if (action == GLFW_RELEASE)
		{
			crynn::Input::currentKeyStates[button] = true;
			crynn::Input::getKeyDownStates[button] = false;
		}
	}

	bool Input::GetKey(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		int keyCode = std::underlying_type<KeyCode>::type(key);
		
		if (keyCode >= KEYSTATE_BUFFER_MAX_SIZE) //prevent out of bounds
			return false;

		return currentKeyStates[keyCode];
	}

	bool Input::GetKeyDown(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		int keyCode = std::underlying_type<KeyCode>::type(key);

		if (keyCode >= KEYSTATE_BUFFER_MAX_SIZE) //prevent out of bounds
			return false;

		bool keyCurrentlyPressed = currentKeyStates[keyCode];

		if (keyCurrentlyPressed && !getKeyDownStates[keyCode])
		{
			getKeyDownStates[keyCode] = true;
			return true;
		}

		return false;
	}

	void Input::UpdateMousePosInternal()
	{
		if (!Input::m_initialised)
			return;

		double xPos = 0, yPos = 0;
		glfwGetCursorPos(Window::GetCurrentWindow()->GetGLFWWindow(), &xPos, &yPos);

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

	Vec2Int Input::GetMousePosition()
	{
		return Vec2Int(m_xPos, m_yPos);
	}

	void Input::LockMouse()
	{
		glfwSetInputMode(Window::GetCurrentWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void Input::UnlockMouse()
	{
		glfwSetInputMode(Window::GetCurrentWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void Input::Init()
	{
		if (m_initialised)
			return;

		glfwSetKeyCallback(Window::GetCurrentWindow()->GetGLFWWindow(), key_callback);
		glfwSetScrollCallback(Window::GetCurrentWindow()->GetGLFWWindow(), scroll_callback);
		glfwSetMouseButtonCallback(Window::GetCurrentWindow()->GetGLFWWindow(), mouse_button_callback);
		m_initialised = true;

		std::cout << "Input Initialised\n";
	}

	void Input::StartPoll()
	{
		Input::UpdateMousePosInternal(); //update mouse data	
	}
}
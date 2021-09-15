#include "Window.h"
#include "Input.h"
namespace crynn
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
	{
	}

	InputComponent::InputComponent()
	{
		//Allocate buffers to store keystates
		m_currentKeyStatesBuffer = std::unique_ptr<bool[]>(new bool[KEYSTATE_BUFFER_MAX_SIZE]);
		m_getKeyDownStatesBuffer = std::unique_ptr<bool[]>(new bool[KEYSTATE_BUFFER_MAX_SIZE]);
	}

	InputComponent::~InputComponent()
	{
	}

	bool InputComponent::GetKey(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		int keyCode = std::underlying_type<KeyCode>::type(key);
		
		if (keyCode >= KEYSTATE_BUFFER_MAX_SIZE) //prevent out of bounds
			return false;

		return m_currentKeyStatesBuffer[keyCode];
	}

	bool InputComponent::GetKeyDown(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		int keyCode = std::underlying_type<KeyCode>::type(key);

		if (keyCode >= KEYSTATE_BUFFER_MAX_SIZE) //prevent out of bounds
			return false;

		bool keyCurrentlyPressed = m_currentKeyStatesBuffer[keyCode];

		if (keyCurrentlyPressed && !m_getKeyDownStatesBuffer[keyCode])
		{
			m_getKeyDownStatesBuffer[keyCode] = true;
			return true;
		}

		return false;
	}

	void InputComponent::UpdateMousePosInternal()
	{
		double xPos = 0, yPos = 0;
		glfwGetCursorPos(Window::GetCurrentWindow()->GetGLFWWindow(), &xPos, &yPos);

		m_prevXPos = m_xPos;
		m_prevYPos = m_yPos;

		m_xPos = xPos;
		m_yPos = yPos;
	}

	Vec2 InputComponent::GetMouseDelta()
	{
		return Vec2
		(
			m_xPos - m_prevXPos,
			m_yPos - m_prevYPos
		);
	}

	Vec2Int InputComponent::GetMousePosition()
	{
		return Vec2Int(m_xPos, m_yPos);
	}

	void InputComponent::LockMouse()
	{
		glfwSetInputMode(Window::GetCurrentWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void InputComponent::UnlockMouse()
	{
		glfwSetInputMode(Window::GetCurrentWindow()->GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	void InputComponent::UpdateKeyboardState(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key >= KEYSTATE_BUFFER_MAX_SIZE) //out of bounds check
			return;

		//Update keystate according to action
		if (action == GLFW_PRESS)
		{
			m_currentKeyStatesBuffer[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			m_currentKeyStatesBuffer[key] = false;
			m_getKeyDownStatesBuffer[key] = false;
		}
	}

	void InputComponent::UpdateMouseState(double yoffset)
	{
		OnMouseScroll.Invoke(static_cast<float>(yoffset)); //Invoke the OnMouseScroll when GLFW reports a mouse scroll

	}
}
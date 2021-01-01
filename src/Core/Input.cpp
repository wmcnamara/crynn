#include "Input.h"

namespace crynn
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS) //If its a press, update the keystate
			crynn::Input::UpdateKeyState(key, true);
		else if (action == GLFW_RELEASE)
			crynn::Input::UpdateKeyState(key, false);
	}

	bool Input::GetKey(KeyCode key)
	{
		//Cast keycode to its underlying int type because it is a strong enum.
		return states[std::underlying_type<KeyCode>::type(key)];
	}

	bool Input::GetKeyDown(KeyCode key)
	{
		return false;
	}

	void Input::Init()
	{
		if (m_initialised)
			return;

		glfwSetKeyCallback(Window::GetGLFWWin(), key_callback);
		m_initialised = true;
	}
}
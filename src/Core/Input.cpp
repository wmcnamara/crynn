#include "Input.h"

namespace crynn
{
	bool Input::GetKey(KeyCode key)
	{
		//Cast keycode to its underlying type because it is a strong enum.
		return glfwGetKey(Window::GetGLFWWin(), static_cast<typename std::underlying_type<KeyCode>::type>(key)) == GLFW_PRESS;
	}

	Input::Input()
	{
		handlerID = Application::OnInput.AddHandler(std::bind(&Input::Inputs, this));
	}

	Input::~Input()
	{
		Application::OnInput.RemoveHandler(handlerID);
	}
}
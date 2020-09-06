#include "Input.h"

using namespace Crynn::Windows;

namespace Crynn
{
    namespace Input
    {
        bool Input::GetKey(KeyCode key)
        {
            //You have to cast KeyCode to its underlying type because it is a scoped enum.
            return glfwGetKey(Application::Instance().glfwWindow, static_cast<typename std::underlying_type<KeyCode>::type>(key)) == GLFW_PRESS;
        }

        Input::Input()
        {
            handlerID = Application::Instance().OnInput.AddHandler(std::bind(&Input::InputCommands, this));
        }

        Input::~Input()
        {
            Application::Instance().OnInput.RemoveHandler(handlerID);
        }
    }
}
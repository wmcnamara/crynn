#include "Application.h"

namespace Crynn
{
	void Application::Quit()
	{
		OnBeforeClose.Invoke();
		glfwSetWindowShouldClose(Window::GetGLFWWin(), true);
	}

	void Application::Tick()
	{
		//Get the deltaTime
		currentFrameTime = glfwGetTime();
		double deltaTime = currentFrameTime - previousFrameTime;
		previousFrameTime = currentFrameTime; //Update the previousFrameTime

		//Invoke update
		OnBeforeUpdate.Invoke(deltaTime);
		OnUpdate.Invoke(deltaTime);
	}

	void Application::Initialise()
	{
		glfwSetTime(0); //This is done to prevent long startup times from affecting the first frame deltaTime

		auto func = [](GLFWwindow* w)
		{
			static_cast<Application*>(glfwGetWindowUserPointer(w))->OnBeforeClose.Invoke();
		};

		glfwSetWindowCloseCallback(Window::GetGLFWWin(), func);
		OnStart.Invoke();
	}

	double Application::GetTime()
	{
		return glfwGetTime();
	}
}
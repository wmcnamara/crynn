#include "Application.h"

namespace crynn
{
	void Application::Quit()
	{
		OnBeforeClose.Invoke();
		glfwSetWindowShouldClose(Window::GetGLFWWin(), true);
	}

	void Application::Tick()
	{
		//calculate the deltaTime
		currentFrameTime = glfwGetTime();
		double deltaTime = currentFrameTime - previousFrameTime;
		previousFrameTime = currentFrameTime; //Update the previousFrameTime

		//Invoke update and OnBeforeUpdate
		OnBeforeUpdate.Invoke(deltaTime * Application::TimeScale);
		OnUpdate.Invoke(deltaTime * Application::TimeScale);
	}

	void Application::Initialise()
	{
		glfwSetTime(0); //This is done to prevent long startup times from affecting the first frame deltaTime

		//Lambda for OnBeforeClose
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
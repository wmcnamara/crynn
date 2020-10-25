#include "Application.h"

namespace Crynn
{
	void Application::Quit()
	{
		OnBeforeClose.Invoke();
		glfwSetWindowShouldClose(glfwWindow, true);
	}

	void Application::Tick()
	{
		//Get the deltaTime
		currentFrameTime = glfwGetTime();
		double deltaTime = currentFrameTime - previousFrameTime;

		//Invoke update
		OnBeforeUpdate.Invoke(deltaTime);
		OnUpdate.Invoke(deltaTime * timeScale);
		previousFrameTime = currentFrameTime; //Update the previousFrameTime
	}

	void Application::Initialise()
	{
		glfwSetTime(0); //This is done to prevent long startup times from affecting the first frame deltaTime
		glfwSetWindowUserPointer(glfwWindow, this);

		auto func = [](GLFWwindow* w)
		{
			static_cast<Application*>(glfwGetWindowUserPointer(w))->OnBeforeClose.Invoke();
		};

		glfwSetWindowCloseCallback(glfwWindow, func);
		OnStart.Invoke();
	}

	double Application::GetTime()
	{
		return glfwGetTime();
	}
}
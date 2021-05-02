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
		OnRender.Invoke();
	}

	void Application::Initialise()
	{
		//This is done to prevent long startup times from affecting the first frame deltaTime
		glfwSetTime(0); 
		OnStart.Invoke();
	}

	double Application::GetTime()
	{
		return glfwGetTime();
	}

	void Application::ForceSceneRender()
	{
		OnRender.Invoke();
	}
}
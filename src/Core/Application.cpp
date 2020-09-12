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
		OnUpdate.Invoke(deltaTime);
		previousFrameTime = currentFrameTime; //Update the previousFrameTime
	}

	void Application::Initialise()
	{
		glfwSetTime(0); //This is done to prevent long startup times from affecting the first frame deltaTime
		OnStart.Invoke();
	}
}
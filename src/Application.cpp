#include "Application.h"

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
	OnUpdate.Invoke(deltaTime);

	previousFrameTime = currentFrameTime; //Update the previousFrameTime
}

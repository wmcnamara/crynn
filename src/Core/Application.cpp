#include "Application.h"
#include "Rendering/RenderConfig.h"

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
		float deltaTime = currentFrameTime - previousFrameTime;
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
		RenderConfig::EnableDepthTest();
	}

	float Application::GetTime()
	{
		return glfwGetTime();
	}

	void Application::ForceSceneRender()
	{
		OnRender.Invoke();
	}
}
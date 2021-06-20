#include "Rendering/RenderConfig.h"
#include "Window.h"
#include "Application.h"

namespace crynn
{
	void Application::Quit()
	{
		OnBeforeClose.Invoke();
		glfwSetWindowShouldClose(Window::GetCurrentWindow()->GetGLFWWindow(), true);
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
		if (m_initialised) 
			return;

		//This is done to prevent long startup times from affecting the first frame deltaTime
		glfwSetTime(0); 
		OnStart.Invoke();
		RenderConfig::EnableDepthTest();
		m_initialised = true;
	}

	float Application::GetTime()
	{
		return glfwGetTime();
	}

	void Application::ForceSceneRender()
	{
		OnRender.Invoke();
	}

	bool Application::IsInitialized()
	{
		return m_initialised;
	}

}
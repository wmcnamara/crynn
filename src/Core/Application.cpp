#include "Rendering/RenderConfig.h"
#include "Window.h"
#include "Application.h"
#include "../Utility/Defines.h"

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

		if (m_showFPS)
		{
			std::string fpsText = "Crynn Game Engine | FPS: ";
			fpsText += static_cast<int>(1.0f / deltaTime);

			glfwSetWindowTitle(Window::GetCurrentWindow()->GetGLFWWindow(), fpsText.c_str());
		}
	}

	void Application::Initialise()
	{
		if (m_initialised) 
			return;

		//This is done to prevent long startup times from affecting the first frame deltaTime
		glfwSetTime(0); 
		OnStart.Invoke();
		m_initialised = true;

		std::cout << "Crynn Initialized Successfully!\n";
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

	void Application::SetShowFPSTitle(bool state)
	{
		m_showFPS = state;
	}

	bool Application::GetShowFPSTitle()
	{
		return m_showFPS;
	}

}
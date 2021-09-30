#include "Engine.h"
#include "Core/Window.h"
#include "Core/Input.h"
#include "Core/Application.h"
#include "Core/Physics/Physics.h"
#include "Utility/IO.h"
#include "Core/Scene.h"

namespace crynn
{
	Engine::Engine(int windowWidth, int windowHeight, const char* windowName)
	{
		m_window = std::make_shared<Window>(windowWidth, windowHeight, windowName);
		m_inputComponent = std::make_shared<InputComponent>();

		Physics::Init();
		IO::Init();
	}

	void Engine::Run()
	{
		try
		{
			Application::Initialise();

			while (!m_window->ShouldClose())
			{
				m_window->BeforeRender();
				Tick();
				m_window->AfterRender();

				Scene::Clean();
			}

			Scene::ClearObjects();
		}
		catch (std::exception e)
		{
			std::cout << "Exception thrown: " << e.what() << "\n";
		}
	}

	void Engine::SetClearColor(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
	}

	void Engine::Tick()
	{		
		//calculate the deltaTime
		m_currentFrameTime = static_cast<float>(glfwGetTime());

		float deltaTime = m_currentFrameTime - m_previousFrameTime;
		m_previousFrameTime = m_currentFrameTime; //Update the previousFrameTime

		FrameEventData data;
		data.deltaTime = deltaTime * Application::TimeScale;
		data.inputComponent = m_inputComponent;
		data.window = m_window;

		//Invoke update and OnBeforeUpdate
		events.OnBeforeUpdate.Invoke(data);
		events.OnUpdate.Invoke(data);
		events.OnRender.Invoke();

		if (m_showFPS)
		{
			std::string fpsText = "Crynn Game Engine | FPS: ";
			fpsText += std::to_string(static_cast<int>(1.0f / deltaTime));

			glfwSetWindowTitle(Window::GetCurrentWindow()->GetGLFWWindow(), fpsText.c_str());
		}
	}

	Engine::~Engine()
	{

	}
}
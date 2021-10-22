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
		Window& win = Window::instance();
		win.SetWindowSize(windowWidth, windowHeight);
		win.SetWindowName(windowName);
		
		m_inputComponent = std::make_shared<InputComponent>();

		//Physics::Init();
		IO::Init();
	}

	void Engine::Run()
	{
		try
		{
			Application::Initialise();

			while (!Window::instance().ShouldClose())
			{
				//Calculate deltatime
				m_currentFrameTime = static_cast<float>(glfwGetTime());

				float deltaTime = m_currentFrameTime - m_previousFrameTime;
				m_previousFrameTime = m_currentFrameTime; //Update the previousFrameTime

				//Create the FrameEventData object
				FrameEventData data;
				data.deltaTime = deltaTime * Application::TimeScale;
				data.inputComponent = m_inputComponent;

				Window::instance().BeforeRender(data);
				Tick(data);
				Window::instance().AfterRender();

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

	void Engine::Tick(FrameEventData data)
	{		
		//Invoke update and OnBeforeUpdate
		events.OnBeforeUpdate.Invoke(data);
		events.OnUpdate.Invoke(data);
		events.OnRender.Invoke();

		if (m_showFPS)
		{
			std::string fpsText = "Crynn Game Engine | FPS: ";
			fpsText += std::to_string(static_cast<int>(1.0f / data.deltaTime));

			glfwSetWindowTitle(Window::instance().GetGLFWWindow(), fpsText.c_str());
		}
	}

	std::shared_ptr<Engine> Engine::DefaultEngineReference()
	{
		return m_defaultEngineReference;
	}

	Engine::~Engine()
	{

	}
}
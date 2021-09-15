/// Includes almost all necessary engine components.
#include "Crynn.h"

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
				Application::Tick();
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

	Engine::~Engine()
	{

	}
}
/// Includes almost all necessary engine components.
#include "Crynn.h"

namespace crynn
{
	Engine::Engine(int windowWidth, int windowHeight, const char* windowName) :
		m_window(Window(windowName, windowWidth, windowHeight)) 
	{
		static_assert(__STDCPP_THREADS__, "Crynn requires multiple threads to function");
		Physics::Init(); //initialise physics
	}

	void Engine::Run()
	{
		try 
		{
			Application::Initialise();

			while (!m_window.ShouldClose())
			{
				m_window.BeforeRender();
				Application::Tick();
				m_window.AfterRender();

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
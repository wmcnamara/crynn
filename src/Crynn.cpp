/// Includes almost all necessary engine components.
#include "Crynn.h"

namespace crynn
{
	Engine::Engine(int windowWidth, int windowHeight, const char* winName) : 
		m_window(Window(winName, windowWidth, windowHeight)) {}

	void Engine::Run()
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

	void Engine::SetClearColor(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
	}

	Engine::~Engine()
	{

	}
}
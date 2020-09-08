#pragma once
#include "delegate.h"
#include "GLFW/glfw3.h"

/// <summary>
/// A representation of the application.
/// </summary>

namespace Crynn 
{
	class Application
	{
	public:
		//Used by Input to subscribe input events. Do not manually invoke().
		Event<void> OnInput;
		Event<void> OnBeforeClose;
		Event<float> OnUpdate;
		Event<void> OnBeforeUpdate; //Used to set uniform buffer data before rendering
		Event<void> OnStart;
		Event<int, int> OnWindowResize;

		void Quit();

		/// <summary>
		/// Invokes events to update Behaviours.
		/// </summary>
		void Tick();

		GLFWwindow* glfwWindow;
	private:
		double currentFrameTime = 0;
		double previousFrameTime = 0;
	//SINGLETON//
	public:
		static Application& Instance()
		{
			static Application instance;
			return instance;
		}

		Application(Application const&) = delete;
		void operator=(Application const&) = delete;
	private:
		Application() = default;
	};
}

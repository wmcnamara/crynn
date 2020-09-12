#pragma once
#include "Event.h"
#include "GLFW/glfw3.h"

/// <summary>
/// Main Engine Namespace
/// </summary>
namespace Crynn 
{
	/// <summary>
	/// A singleton representation of the application.
	/// Contains events that many internal classes use to operate, and allows easy interfacing with lower level engine components.
	/// </summary>
	class Application
	{
	public:
		///
		///Used by Input to subscribe input events. Do not manually invoke().
		///Parameters determined by the glfwSetKeyCallback parameters.
		///https://www.glfw.org/docs/latest/group__input.html#ga1caf18159767e761185e49a3be019f8d
		Event<GLFWwindow*, int, int, int, int> OnInput;

		Event<void> OnBeforeClose; ///Called once before quitting to desktop using Application::Instance().Quit();///
		Event<double> OnUpdate; ///Called once every frame///
		Event<double> OnBeforeUpdate; ///Used to set uniform buffer data before rendering///
		Event<void> OnStart; ///Called once before entering the main loop. Called before update.///
		Event<int, int> OnWindowResize; ///Invoked when the window is resized. Contains the width and height of new window.///

		/// <summary>
		/// Invokes OnBeforeClose, and quits to desktop.
		/// </summary>
		void Quit();

		/// <summary>
		/// Invokes events to update Behaviours.
		/// </summary>
		void Tick();

		/// <summary>
		/// Invokes OnStart()
		/// </summary>
		void Initialise();

		/// <summary>
		/// Raw GLFW window. Assigned by the Window class when constructed.
		/// </summary>
		GLFWwindow* glfwWindow;
	private:
		//Used to get deltaTimes.
		double currentFrameTime = 0;
		double previousFrameTime = 0;
	//SINGLETON//
	public:
		/// <summary>
		/// Get the singleton instance of application.
		/// </summary>
		/// <returns>Instance of application.</returns>
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

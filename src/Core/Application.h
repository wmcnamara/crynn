#pragma once
#include "Event.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

//class Window; //Forward declare window
#include "Window.h"

#ifndef UNICODE
#define UNICODE
#endif 

/// <summary>
/// Main Engine Namespace
/// </summary>
namespace crynn 
{
	/// <summary>
	/// A singleton representation of the application.
	/// Contains events that many internal classes use to operate, and allows easy interfacing with lower level engine components.
	/// </summary>
	class Application
	{
	public:
		//This class is totally static. You cannot copy this class, or instantiate it.
		Application() = delete;
		~Application() = default;
		Application(const Application&) = delete;
		Application(const Application&&) = delete;

		///Used by Input to subscribe input events. Do not manually invoke().
		///Parameters determined by the glfwSetKeyCallback parameters.
		///https://www.glfw.org/docs/latest/group__input.html#ga1caf18159767e761185e49a3be019f8d
		inline static Event<GLFWwindow*, int, int, int, int> OnInput;

		inline static Event<void> OnBeforeClose; ///Called once before quitting to desktop using Application::Instance().Quit();///
		inline static Event<double> OnUpdate; ///Called once every frame///
		inline static Event<double> OnBeforeUpdate; ///Used to set uniform buffer data before rendering///
		inline static Event<void> OnStart; ///Called once before entering the main loop. Called before update.///
		inline static Event<int, int> OnWindowResize; ///Invoked when the window is resized. Contains the width and height of new window.///

		/// <summary>
		/// Invokes OnBeforeClose, and quits to desktop.
		/// </summary>
		static void Quit();

		/// <summary>
		/// Invokes events to update Behaviours.
		/// </summary>
		static void Tick();

		/// <summary>
		/// Invokes OnStart()
		/// </summary>
		static void Initialise();

		///Returns the time elapsed since the application was launched.
		static double GetTime();

		//Multiplied by deltaTime before being passed to Update. Used to speed up and slowdown time.
		inline static double timeScale = 1.0;
	private:
		//Used to get deltaTimes.
		inline static double currentFrameTime = 0;
		inline static double previousFrameTime = 0;
	};
}

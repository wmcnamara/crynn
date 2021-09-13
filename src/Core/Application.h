#pragma once
#pragma warning (disable : 4005)

#include "Event.h"
#include <GLFW/glfw3.h>


#ifndef UNICODE
#define UNICODE
#endif 

/// <summary>
/// Main Engine Namespace
/// </summary>
namespace crynn
{
	class Window;

	/// <summary>
	/// A class containing static functions to represent application functions, states, and events.
	/// Contains events that many internal classes use to operate, and allows easy interfacing with lower level engine components.
	/// </summary>
	class Application final
	{
	public:
		//This class is totally static. You cannot copy this class, or instantiate it.
		Application() = delete;
		~Application() = delete;
		Application(const Application& other) = delete;
		Application(const Application&& other) = delete;
		
		Application operator=(const Application& other) = delete;
		Application operator=(Application&& other) = delete;

		///Used by Input to subscribe input events. Do not manually invoke().
		///Parameters determined by the glfwSetKeyCallback parameters.
		///https://www.glfw.org/docs/latest/group__input.html#ga1caf18159767e761185e49a3be019f8d
		inline static Event<GLFWwindow*, int, int, int, int> OnInput;

		inline static Event<void> OnBeforeClose; ///Called once before quitting to desktop using Application::Quit();///
		inline static Event<float> OnUpdate; ///Called once every frame///
		inline static Event<float> OnBeforeUpdate; ///Used to set uniform buffer data before rendering///
		inline static Event<void> OnStart; ///Called once before entering the main loop. Called before update.///
		inline static Event<void> OnRender; ///Called when the engine is going to render a frame.
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
		static float GetTime();

		//Multiplied by deltaTime before being passed to Update. Used to speed up and slowdown time.
		inline static float TimeScale = 1.0;

		//Calls OnRender immediatly.
		//OnRender will still be called during this frame even if this is called before.
		//Useful for lighting passes
		void static ForceSceneRender();

		//Returns a boolean indicating if Crynn has been fully initialized
		static bool IsInitialized();

		//If state is true the window title will display the apps current FPS
		static void SetShowFPSTitle(bool state);

		//Returns true if the FPS title is currently being displayed can be set with SetShowFPSTitle
		static bool GetShowFPSTitle();
	private:
		//Used to get deltaTimes.
		inline static float currentFrameTime = 0;
		inline static float previousFrameTime = 0;

		static inline std::atomic_bool m_initialised = false;
		static inline std::atomic_bool m_showFPS = false;
	};
}

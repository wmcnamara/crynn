#pragma once
#include <memory>
#include "Core/Event.h"


#define DATA_PATH "data/"

namespace crynn
{
	class Window;
	class InputComponent;
	struct FrameEventData;
	
	struct EngineEvents
	{
		Event<void> OnBeforeClose; ///Called once before quitting to desktop using Application::Quit();///
		Event<FrameEventData> OnUpdate; ///Called once every frame///
		Event<FrameEventData> OnBeforeUpdate; ///Used to set uniform buffer data before rendering///
		Event<void> OnStart; ///Called once before entering the main loop. Called before update.///
		Event<void> OnRender; ///Called when the engine is going to render a frame.
	};

	//Encapsulates the Crynn game engine.
	class Engine
	{
	public:
		/// <summary>
		/// Creates an instance of the Crynn Game Engine
		/// </summary>
		/// <param name="windowWidth">Width of the window</param>
		/// <param name="windowHeight">Height of the window</param>
		/// <param name="windowName">Name of the window</param>
		Engine
		(
			int windowWidth,
			int windowHeight,
			const char* windowName
		);

		~Engine();

		//Calls onstart, and begins calling the main game loop.
		void Run();
		void SetClearColor(float r, float g, float b, float a) const;

		void Tick();

		EngineEvents events;

	private:
		std::shared_ptr<Window> m_window;
		std::shared_ptr<InputComponent> m_inputComponent;

		float m_currentFrameTime = 0;
		float m_previousFrameTime = 0;
		
		bool m_showFPS = true;
	};
}
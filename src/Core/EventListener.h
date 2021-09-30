#pragma once
#include <memory>
#include <cstdint>

namespace crynn 
{
	class Window;
	class InputComponent;
	class Engine;

	//Contains data relevant to the current frame, like delta time and input information.
	struct FrameEventData
	{
		float deltaTime = 0.0f;
		std::shared_ptr<InputComponent> inputComponent; //The currently bound input component
		std::shared_ptr<Window> window; //Data about the window currently being rendered to
	};


	/// <summary>
	/// Allows interfacing with the Crynn event system.
	/// Inherit from this class, and override any function you may need.
	/// Events are subscribed automatically with this classes constructor.
	/// </summary>
	class EventListener
	{
	public: 		
		///Unsubscribes the events in this class from the Crynn event system.
		void UnsubscribeEvents();

	protected:		
		EventListener();
		virtual ~EventListener();

		/// <summary>
		/// Called once every frame.
		/// </summary>
		/// <param name="deltaTime">The time it took the previous frame to render.</param>
		virtual void Update(FrameEventData deltaTime) {}
		virtual void Start() {} ///Called once before the game enters its main loop. Will be called before the first Update.

		//Called when the engine is going to render a frame
		virtual void OnRender() {}

		/// <summary>
		/// Called once every frame before Update.
		/// Generally used for setting uniforms, or other things that need to be set before any render calls.
		/// </summary>
		/// <param name="deltaTime">The time it took the previous frame to render.</param>
		virtual void BeforeUpdate(FrameEventData deltaTime) {}
		virtual void BeforeClose() {} ///Called before quitting to desktop with Application::Instance().Quit();
	private:		
		///Subscribes the events in this class to the Crynn event system.
		void SubscribeEvents();

		friend class CrynnObject;

		std::shared_ptr<Engine> m_engine;

		//Used to remove handlers when this object is destructed.
		uint64_t updateHandlerID = 0; 
		uint64_t startHandlerID = 0;
		uint64_t beforeUpdateHandlerID = 0;
		uint64_t beforeCloseHandlerID = 0;
		uint64_t renderID = 0;
	};
}


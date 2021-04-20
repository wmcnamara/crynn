#pragma once
#include "../Utility/Debug.h"
#include "../Utility/Timer.h"
#include "Application.h"
#include <assert.h>

namespace crynn 
{
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
		virtual void Update(double deltaTime) {}
		virtual void Start() {} ///Called once before the game enters its main loop. Will be called before the first Update.

		//Called when the engine is going to render a frame
		virtual void Render() {}

		/// <summary>
		/// Called once every frame before Update.
		/// Generally used for setting uniforms, or other things that need to be set before any render calls.
		/// </summary>
		/// <param name="deltaTime">The time it took the previous frame to render.</param>
		virtual void BeforeUpdate(double deltaTime) {}
		virtual void BeforeClose() {} ///Called before quitting to desktop with Application::Instance().Quit();
	private:		
		///Subscribes the events in this class to the Crynn event system. Call at the end of your constructor.
		void SubscribeEvents();

		friend class CrynnObject;

		//Used to remove handlers when this object is destructed.
		unsigned int updateHandlerID = 0; 
		unsigned int startHandlerID = 0;
		unsigned int beforeUpdateHandlerID = 0;
		unsigned int beforeCloseHandlerID = 0;
		unsigned int renderID = 0;
	};
}


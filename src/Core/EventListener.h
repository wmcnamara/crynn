#pragma once
#include "Utility/Debug.h"
#include <Utility/Timer.h>
#include "Application.h"
#include <assert.h>

namespace Crynn 
{
	/// <summary>
	/// Allows interfacing with the Crynn event system.
	/// Inherit from this class, and override any function you may need.
	/// Call Subscribe() to subscribe overridden functions to the Crynn event system.
	/// </summary>
	class EventListener
	{
	protected:		
		EventListener();
		~EventListener();

		/// <summary>
		/// Called once every frame.
		/// </summary>
		/// <param name="deltaTime">The time it took the previous frame to render.</param>
		virtual void Update(double deltaTime) {}
		virtual void Start() {} ///Called once before the game enters its main loop. Will be called before the first Update.

		/// <summary>
		/// Called once every frame before Update.
		/// Generally used for setting uniforms, or other things that need to be set before any render calls.
		/// </summary>
		/// <param name="deltaTime">The time it took the previous frame to render.</param>
		virtual void BeforeUpdate(double deltaTime) {}
		virtual void BeforeClose() {} ///Called before quitting to desktop with Application::Instance().Quit();

		///Returns true if this instance's events are subscribed to the event system.
		bool IsSubscribed() { return subscribed; }
	private:		
		///Subscribes the events in this class to the Crynn event system. Call at the end of your constructor.
		void SubscribeEvents();
		///Unsubscribes the events in this class from the Crynn event system. Call at the start of your destructor.
		void UnsubscribeEvents();

		//Used to remove handlers when this object is destructed.
		int updateHandlerID; 
		int startHandlerID;
		int beforeUpdateHandlerID;
		int beforeCloseHandlerID;

		bool subscribed = false;
	};
}


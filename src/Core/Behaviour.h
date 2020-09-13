#pragma once
#include "Application.h"

namespace Crynn 
{
	/// <summary>
	/// Allows interfacing with the Crynn event system.
	/// Inherit from this class, and override any function you may need.
	/// </summary>
	class Behaviour
	{
	protected:		
		//This is why this class must be inherited from.
		Behaviour(); ///Automatically subscribes events to the event system.
		~Behaviour(); ///Unsubscribes the events

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

	private:
		//Used to remove handlers when this object is destructed.
		int updateHandlerID; 
		int startHandlerID;
		int beforeUpdateHandlerID;
		int beforeCloseHandlerID;
	};
}


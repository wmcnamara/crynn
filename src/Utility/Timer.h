#pragma once
#include <chrono>
#include "Debug.h"

namespace Crynn 
{
	/// <summary>
	/// Simple timer that counts the miliseconds from instantiation to when it goes out of scope.
	/// Used to time how long functions take.
	/// </summary>
	class ScopedTimer
	{
	public:
		/// <summary>
		/// Creates a ScopedTimer that will Debug::Log() the time when it stops.
		/// </summary>
		/// <param name="funcName">The name of the function that will appear in the logs next to the time.</param>
		ScopedTimer(const char* funcName);
		~ScopedTimer();	
	
		/// <summary>
		/// Stops timing early, and outputs logs.
		/// </summary>
		void Stop();
	private:
		std::chrono::high_resolution_clock::time_point m_startPoint;
		const char* m_funcName;
	};
}


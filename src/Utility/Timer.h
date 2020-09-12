#pragma once
#include <chrono>
#include "Debug.h"

namespace Crynn
{
	/// <summary>
	/// Simple timer that counts the time from instantiation to when it goes out of scope.
	/// Used to time how long functions take.
	/// </summary>

	/// <summary>
	/// The time format you would like to see the delta displayed in.
	/// </summary>
	enum class TimeFormat
	{
		Seconds,
		Milliseconds,
		Microseconds,
		Nanoseconds
	};

	class ScopedTimer
	{
	public:
		/// <summary>
		/// Creates a ScopedTimer that will Debug::Log() the time when it stops.
		/// </summary>
		/// <param name="funcName">The name of the function that will appear in the logs next to the time.</param>
		/// <param name="format">The format you would like the time displayed in.</param>
		ScopedTimer(const char* funcName, TimeFormat format);
		~ScopedTimer();

		/// <summary>
		/// Stops timing early, and outputs logs.
		/// </summary>
		void Stop();
	private:
		std::chrono::high_resolution_clock::time_point m_startPoint;
		const char* m_funcName;
		TimeFormat m_format;
	};
}


#include "Timer.h"
#include <iostream>

namespace crynn
{
	ScopedTimer::ScopedTimer(const char* funcName, TimeFormat format) :
		m_startPoint(std::chrono::high_resolution_clock::now()),
		m_funcName(funcName),
		m_format(format)
	{}

	ScopedTimer::~ScopedTimer()
	{
		Stop();
	}

	void ScopedTimer::Stop()
	{
		auto endPoint = std::chrono::high_resolution_clock::now();
		long long start = 0;
		long long end = 0;

		std::stringstream output;
		long long duration;

		switch (m_format)
		{
		case TimeFormat::Seconds:
			start = std::chrono::time_point_cast<std::chrono::seconds>(m_startPoint).time_since_epoch().count();
			end = std::chrono::time_point_cast<std::chrono::seconds>(endPoint).time_since_epoch().count();

			duration = end - start;
			output << m_funcName << " took " << duration << " seconds to complete\n";
			break;

		case TimeFormat::Milliseconds:
			start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_startPoint).time_since_epoch().count();
			end = std::chrono::time_point_cast<std::chrono::milliseconds>(endPoint).time_since_epoch().count();

			duration = end - start;
			output << m_funcName << " took " << duration << " milliseconds to complete\n";
			break;

		case TimeFormat::Microseconds:
			start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startPoint).time_since_epoch().count();
			end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

			duration = end - start;
			output << m_funcName << " took " << duration << " microseconds to complete\n";
			break;

		case TimeFormat::Nanoseconds:
			start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_startPoint).time_since_epoch().count();
			end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endPoint).time_since_epoch().count();

			duration = end - start;
			output << m_funcName << " took " << duration << " nanoseconds to complete\n";
			break;
		}

		std::cout << output.str() << "\n";
	}
}
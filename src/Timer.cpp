#include "Timer.h"

ScopedTimer::ScopedTimer(const char* funcName) : m_funcName(funcName), m_startPoint(std::chrono::high_resolution_clock::now()) {}

ScopedTimer::~ScopedTimer()
{
	Stop();
}

void ScopedTimer::Stop()
{
	//Cast the time into miliseconds
	auto endPoint = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startPoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();

	auto duration = end - start;
	double ms = duration * 0.001;

	std::stringstream output;
	output << m_funcName << " took " << ms << " miliseconds to complete\n";

	Debug::Log(output, Debug::MsgType::Message);
}

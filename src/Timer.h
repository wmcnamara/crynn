#pragma once
#include <chrono>
#include "Debug.h"

namespace Crynn 
{
	class ScopedTimer
	{
	public:
		ScopedTimer(const char* funcName);
		~ScopedTimer();	
	
		void Stop();
	private:
		std::chrono::high_resolution_clock::time_point m_startPoint;
		const char* m_funcName;
	};
}


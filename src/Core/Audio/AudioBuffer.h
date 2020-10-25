#pragma once
#include "al.h"
#include <iostream>

namespace Crynn 
{
	class AudioBuffer
	{
	public:
		AudioBuffer();
		~AudioBuffer();
	private:
		ALuint m_buffer;
	};
}

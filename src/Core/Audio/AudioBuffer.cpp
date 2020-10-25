#include "AudioBuffer.h"

namespace Crynn
{
	AudioBuffer::AudioBuffer()
	{
		alGetError(); //Clear previous error code
		alGenBuffers(1, &m_buffer);

		int err = alGetError();
		if (alGetError() != AL_NO_ERROR) 
		{
			std::cerr << "alGenBuffers : " << err;
			return;
		}
	}
	AudioBuffer::~AudioBuffer()
	{
		alDeleteBuffers(1, &m_buffer);
	}
}
#include "Audio.h"

Sound::Sound(const char* relativePath)
{
	if (!m_soundBuf.loadFromFile(relativePath))
	{
		std::cout << "Sound failed to load at path: " << relativePath << "\n";
		throw std::runtime_error("Sound failed to load");
	}

	m_sound.setBuffer(m_soundBuf);

}

void Sound::Play()
{
	m_sound.play();
}

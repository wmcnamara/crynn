#pragma once

#include "SFML/Audio.hpp"
#include <iostream>
#include <exception>

/// <summary>
/// Encapsulates loading and playing sounds from a file.
/// </summary>
class Sound
{
public:
	/// <summary>
	/// Loads sound from relativePath, and constructs a playable sound object from it. 
	/// Throws std::runtime_error on failure.
	/// </summary>
	/// <param name="relativePath">Path to load audio from.</param>
	Sound(const char* relativePath);

    //Plays the sound.
    void Play();

private:
	sf::SoundBuffer m_soundBuf;
	sf::Sound m_sound;
};
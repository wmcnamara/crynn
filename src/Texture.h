#pragma once
#include "glad/glad.h"
#include <iostream>
#include "Shader.h"
#include "Window.h"
#include "Debug.h"

namespace Crynn 
{
	class Texture
	{
	public:
		Texture() = default;
		Texture(const char* path); //Creates a texture from path, and generate mipmaps.
		~Texture();

		void Load(const char* path); //Creates a texture from path, and generate mipmaps.

		const unsigned int& Data() { return texture; } //Returns the texture ID
		const bool& Valid() { return valid; }
	private:
		unsigned int texture = 0;
		bool valid = false; // Is a valid texture loaded
	};
}
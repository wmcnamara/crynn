#pragma once
#include "glad/glad.h"
#include <iostream>
#include "Shader.h"
#include "Window.h"
#include "Utility/Debug.h"

namespace Crynn 
{
	/// <summary>
	/// 2D texture class.
	/// </summary>
	class Texture
	{
	public:
		/// <summary>
		/// Creates a dummy texture object with no data.
		/// </summary>
		Texture() = default;
		/// <summary>
		/// Creates a texture object, and loads texture data into it.
		/// </summary>
		/// <param name="path">Relative path to the texture file.</param>
		Texture(const char* path);
		~Texture();

		/// <summary>
		/// Loads a new texture and deletes memory of the old one.
		/// </summary>
		/// <param name="path"></param>
		void Load(const char* path); //Creates a texture from path, and generate mipmaps.

		/// <summary>
		/// Gets the OpenGL texture ID
		/// </summary>
		/// <returns>The OpenGL texture ID</returns>
		const unsigned int& Data() { return texture; } //Returns the texture ID

		/// <summary>
		/// Checks if a texture is loaded
		/// </summary>
		/// <returns>true if valid texture data is loaded in.</returns>
		const bool& Valid() { return valid; }
	private:
		unsigned int texture = 0;
		bool valid = false; //Is a valid texture loaded?
	};
}
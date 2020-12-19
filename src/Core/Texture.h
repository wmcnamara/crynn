#pragma once
#include <iostream>
#include "Shader.h"
#include "Window.h"
#include "Utility/Debug.h"
#include "Utility/Timer.h"
namespace crynn 
{
	/// <summary>
	/// 2D texture class.
	/// </summary>
	class Texture
	{
	public:
		/// <summary>
		/// Creates a texture object, and loads texture data into it.
		/// </summary>
		/// <param name="path">Relative path to the texture file.</param>
		Texture(const char* path);		
		Texture() = default; /// Creates a dummy texture object with no data.
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
		const unsigned int& GetTextureID();

		/// <summary>
		/// Get a pointer to the raw texture data.
		/// </summary>
		/// <returns></returns>
		unsigned char* GetTextureData();

		/// <returns>The width of this texture
		const unsigned int& Width();
		/// <returns>The height of this texture
		const unsigned int& Height();

		/// <summary>
		/// Checks if a texture is loaded
		/// </summary>
		/// <returns>true if valid texture data is loaded in.</returns>
		const bool& Valid() { return m_valid; }
	private:
		unsigned int m_textureID = 0; ///OpenGL texture ID
		unsigned char* m_textureData = 0; ///Texture data pointer
		int m_width, m_height, m_nrChannels;

		bool m_valid = false; //Is a valid texture loaded?
	};
}
#pragma once
#include <iostream>
#include "Rendering/Shader.h"
#include "Window.h"
#include "../Utility/Debug.h"
#include "../Utility/Timer.h"
namespace crynn 
{
	//Represents an RGBA color
	struct Color
	{
		unsigned char red = 0;
		unsigned char green = 0;
		unsigned char blue = 0;
		unsigned char alpha = 0;
	};

	/// <summary>
	/// 2D texture class to load external textures.
	/// This texture should not be used as a render texture.
	/// If you want to render to a texture, check the RenderTexture class.
	/// </summary>
	class Texture
	{
	public:
		/// <summary>
		/// Creates a texture object, and loads texture data into it.
		/// </summary>
		/// <param name="path">Relative path to the texture file.</param>
		Texture(const char* path);		
		~Texture();

		//No copying or moving textures for now
		//TODO properly implement these
		Texture(const Texture& other) = delete;
		Texture& operator= (Texture other) = delete; 

		Texture(Texture&& other) = delete;
		Texture& operator=(Texture&& other) = delete;

		/// <summary>
		/// Gets the OpenGL texture ID
		/// </summary>
		/// <returns>The OpenGL texture ID</returns>
		GLuint GetTextureID();

		/// <summary>
		/// Get a pointer to the raw texture data.
		/// </summary>
		/// <returns></returns>
		unsigned char* GetTextureData();

		/// <returns>The width of this texture
		unsigned int GetWidth();

		/// <returns>The height of this texture
		unsigned int GetHeight();

		/// <summary>
		/// Binds texture to opengl context
		/// </summary>
		void Bind() const { glBindTexture(GL_TEXTURE_2D, m_textureID); }

		//Get a pixel color from the texture at pixel coordinate x and y.
		Color operator () (unsigned int x, unsigned int y);	

		//Get a pixel color from the texture at pixel coordinate x and y.
		Color GetPixelColor(unsigned int x, unsigned int y);
	private:

		/// <summary>
		/// Loads a new texture and deletes memory of the old one.
		/// </summary>
		/// <param name="path"></param>
		void Load(const char* path); //Creates a texture from path, and generate mipmaps.

		GLuint m_textureID = 0; ///OpenGL texture ID
		unsigned char* m_textureData = nullptr; ///Texture data pointer

		int m_width = 0, m_height = 0, m_nrChannels = 4;
	};

	class RenderTexture 
	{
	
	};
}
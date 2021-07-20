#include "Texture.h"

//Create implementation according to stb_image docs
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

namespace crynn
{
	Texture::Texture(const char* path)
	{
		if (path == NULL || strcmp(path, "") == 0)
		{
			std::cout << "Texture path is null";
			throw std::exception("Texture path is null");
		}

		Load(path);
	}

	Texture::~Texture()
	{
		stbi_image_free(m_textureData);
		glDeleteTextures(1, &m_textureID);
	}

	void Texture::Load(const char* path)
	{
#ifdef CRYNN_DEBUG
		ScopedTimer timer("Texture Load");
#endif

		// load and generate the texture
		stbi_set_flip_vertically_on_load(true);
		m_textureData = stbi_load(path, &m_width, &m_height, &m_nrChannels, 4);

		if (m_textureData)
		{
			glGenTextures(1, &m_textureID);
			glBindTexture(GL_TEXTURE_2D, m_textureID);

			// set the texture wrapping/filtering options (on the currently bound texture object)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);

#ifdef CRYNN_DEBUG
			//Debug logging
			std::cout << path << " Loaded Successfully\n";
#endif
		}
		else
		{
#ifdef CRYNN_DEBUG
			m_textureData = nullptr; //prevents crash when deallocating
			std::cerr << "ERROR: Failed to load texture from " << path << "\n";
			Debug::LogToFile("Failed to Load: ");
			Debug::LogToFile(path);
			throw std::runtime_error("Failed to load texture. Check output.log for details");
#endif	
		}
	}

	unsigned int Texture::GetTextureID()
	{
		 return m_textureID;
	}

	unsigned char* Texture::GetTextureData()
	{
		return m_textureData;
	}

	unsigned int Texture::Width()
	{
		return m_width;
	}

	unsigned int Texture::Height()
	{
		return m_height;
	}

	Color Texture::operator()(unsigned int x, unsigned int y)
	{
		return GetPixelColor(x, y);
	}

	Color Texture::GetPixelColor(unsigned int x, unsigned int y)
	{
		//assert that the pixel coord is in bounds
		assert(x < m_width || y < m_height); 

		unsigned bytePerPixel = m_nrChannels;
		unsigned char* pixelOffset = m_textureData + (x + m_height * y) * bytePerPixel;

		unsigned char r = pixelOffset[0];
		unsigned char g = pixelOffset[1];
		unsigned char b = pixelOffset[2];
		unsigned char a = m_nrChannels >= 4 ? pixelOffset[3] : 0xff;

		return Color{ r, g, b, a };
	}
}
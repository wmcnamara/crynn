#include "Texture.h"

//Create implementation according to stb_image docs
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

namespace crynn
{
	Texture::Texture(const char* path)
	{
		if (path == NULL || path == "")
		{
			std::cout << "Texture path is null";
			return;
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
			std::cout << "ERROR: Failed to load texture from " << path << "\n";
			return;
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

	Texture::Texture(const Texture& other)
	{
		m_width = other.m_width;
		m_height = other.m_height;
		m_nrChannels = other.m_nrChannels;

		//Allocate memory for the new texture
		size_t texBytes = m_width * m_height * m_nrChannels;
		m_textureData = (unsigned char*)STBI_MALLOC(texBytes); //malloc because stbi dellocates with free()

		//copy texture memory
		std::memcpy(m_textureData, other.m_textureData, texBytes);

		//Create opengl data
		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		if (m_textureData)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cerr << "Failed to load texture from copy constructor\n";
			return;
		}

		std::cout << "Copied Texture\n";

	}

	Texture& Texture::operator=(Texture other)
	{
		m_width = other.m_width;
		m_height = other.m_height;
		m_nrChannels = other.m_nrChannels;

		//Allocate memory for the new texture
		size_t texBytes = m_width * m_height * m_nrChannels;
		m_textureData = new unsigned char(texBytes); //malloc because stbi dellocates with free()

		//copy texture memory
		std::memcpy(m_textureData, other.m_textureData, texBytes);

		//Create opengl data
		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		if (m_textureData)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cerr << "Failed to load texture from copy constructor\n";
		}

		std::cout << "Copied Texture\n";

		return *this;
	}

	Color Texture::operator()(unsigned int x, unsigned int y)
	{
		return GetPixelColor(x, y);
	}

	Color Texture::GetPixelColor(unsigned int x, unsigned int y)
	{
		assert(x < m_width || y < m_height); //assert in bounds
		
		//If they input an out of bounds data, return a black pixel
		if (x > m_width || y > m_height) 
			return Color{ 0, 0, 0, 1 }; 

		unsigned bytePerPixel = m_nrChannels;
		unsigned char* pixelOffset = m_textureData + (x + m_height * y) * bytePerPixel;

		unsigned char r = pixelOffset[0];
		unsigned char g = pixelOffset[1];
		unsigned char b = pixelOffset[2];
		unsigned char a = m_nrChannels >= 4 ? pixelOffset[3] : 0xff;

		return Color{ r, g, b, a };
	}
}
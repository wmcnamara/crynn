#include "Texture.h"

//Create implementation according to stb_image docs
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

namespace Crynn
{
	Texture::Texture(const char* path) 
	{ 
		Load(path); 
	}

	Texture::~Texture()
	{
		if (m_valid)
		{
			stbi_image_free(m_textureData);
			glDeleteTextures(1, &m_textureID);
		}
	}

	void Texture::Load(const char* path)
	{
		ScopedTimer timer("Texture Load", TimeFormat::Milliseconds);
		if (m_valid)
			stbi_image_free(m_textureData); //Delete old stb image texture memory
			glDeleteTextures(1, &m_textureID); //Delete old texture memory if one was previously loaded.

		glGenTextures(1, &m_textureID);
		glBindTexture(GL_TEXTURE_2D, m_textureID);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// load and generate the texture
		stbi_set_flip_vertically_on_load(true);
		m_textureData = stbi_load(path, &m_width, &m_height, &m_nrChannels, 4);
		if (m_textureData)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glGenerateMipmap(GL_TEXTURE_2D);

			//Debug logging
			std::stringstream output;
			output << path << " Loaded Successfully";

			Debug::Log(output);
		}
		else
		{
			std::stringstream output;
			output << "Failed to load texture from " << path << "\n";
			Debug::Log(output);
		}

		m_valid = true;
	}

	const unsigned int& Texture::GetTextureID()
	{
		 return m_textureID;
	}

	unsigned char* Texture::GetTextureData()
	{
		return m_textureData;
	}

	const unsigned int& Texture::Width()
	{
		return m_width;
	}

	const unsigned int& Texture::Height()
	{
		return m_height;
	}
}
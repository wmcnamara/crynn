#include "Texture.h"

//Create implementation according to stb_image docs
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

Texture::Texture(const char* path) { Load(path); }

Texture::~Texture()
{
	glDeleteTextures(1, &texture);
}

void Texture::Load(const char* path)
{
	ScopedTimer timer("Texture load");

	if (valid)
		glDeleteTextures(1, &texture); //Delete old texture memory if one was previously loaded.

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// load and generate the texture
	int width, height, nrChannels;

	unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 4);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);

		//Debug logging
		std::stringstream output;
		output << path << " Loaded Successfully";

		Debug::Log(output, Debug::Success);
	}
	else
	{
		std::stringstream output;
		output << "Failed to load texture from " << path << "\n";
		Debug::Log(output, Debug::Error);
	}
	stbi_image_free(data);

	valid = true;
}

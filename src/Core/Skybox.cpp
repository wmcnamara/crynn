#include "Skybox.h"

Skybox::Skybox(std::array<const char*, 6> texturepaths) : m_texturepaths(texturepaths)
{
	glGenTextures(1, &cubeID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeID);

	int width, height, nrChannels;
	unsigned char* data;
	for (unsigned int i = 0; i < texturepaths.size(); i++)
	{
		data = stbi_load(texturepaths[i], &width, &height, &nrChannels, 0);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
			0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
		);
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Skybox::Render()
{
	assert(!m_texturepaths.empty());
}

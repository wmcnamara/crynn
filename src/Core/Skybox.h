#pragma once
#include "glad/glad.h"
#include "stb_image.h"
#include <assert.h>
#include <array>
class Skybox
{
public:
	Skybox() = default;
	Skybox(std::array<const char*, 6> texturepaths);

	void Render();
private:
	std::array<const char*, 6> m_texturepaths;
	unsigned int cubeID;
};
#pragma once
#include "Buffers/Buffers.h"
#include <array>
#include "stb_image.h"
#include "Shader.h"

namespace crynn
{
	/// <summary>
	/// Filepaths to the corresponding skybox texture
	/// </summary>
	struct SkyboxFaceFilePathData
	{
		std::array<const char*, 6> filepaths;
		Shader& skyShader;
	};

	class Skybox
	{
	public:
		Skybox(SkyboxFaceFilePathData sbData);
		~Skybox();


	private:
		static Skybox currentSkybox;
		GLuint m_id;
	};
}
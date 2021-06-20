/*
#pragma once
#include "Buffers/Buffers.h"
#include <array>
#include "stb_image.h"
#include "Rendering/Shader.h"
#include "EventListener.h"
#include "../Utility/Shapes.h" //skybox vertices
#include "../Core/Mesh.h"

namespace crynn
{

	/// <summary>
	/// Filepaths to the corresponding skybox texture
	/// </summary>
	struct SkyboxFilePathData
	{
		std::array<const char*, 6> filepaths;
		Shader& skyShader;
	};

	class Skybox : EventListener, Mesh
	{
	public:
		Skybox(const SkyboxFilePathData& sbData);
		~Skybox();

	private:
		void BeforeUpdate(double dt) override;
		
		const Shader& m_shader;
		GLuint m_id;
	};

}
*/
#pragma once
#include "glad/glad.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include "../Utility/Debug.h"
#include "EventListener.h"
#include <memory>

namespace crynn
{
	/// <summary>
	/// Renders a mesh with a shader and a texture.
	/// </summary>
	class MeshRenderer : EventListener
	{
	public:
		MeshRenderer(const Mesh& mesh, const Texture& texture, const Shader& shader, Mat4& modelMatrix);

		inline const Mesh& GetMesh() const { return m_mesh; }
		inline const Texture& GetTexture() const { return m_texture; }
		inline const Shader& GetShader() const { return m_shader; }

		bool active = true; ///Toggle rendering
	private:		
		/// Draws a mesh to the screen with the objects specified int the constructor.
		void Render();

		void Update(double deltaTime) override;
		Mat4& m_model;
		 
		const Mat3 m_normalMat;
		const Mesh& m_mesh;
		const Texture& m_texture;
		const Shader& m_shader;
	};
}
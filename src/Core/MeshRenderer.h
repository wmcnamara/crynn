#pragma once
#include "glad/glad.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include "Utility/Debug.h"
#include "EventListener.h"
#include <memory>

#define SHARED_MESHRENDERER std::shared_ptr<MeshRenderer>
namespace crynn
{
	/// <summary>
	/// Renders a mesh with a shader and a texture.
	/// </summary>
	class MeshRenderer : EventListener
	{
	public:
		MeshRenderer(Mesh* mesh, Texture* texture, Shader* shader, mat4* modelMatrix);

		const Mesh* GetMesh() const { return m_mesh; }
		const Texture* GetTexture() const { return m_texture; }
		const Shader* GetShader() const { return m_shader; }

		bool active = true; ///Toggle rendering
	private:		
		/// Draws a mesh to the screen with the objects specified int the constructor.
		void Render();

		void Update(double deltaTime) override;
		mat4* m_model;
		
		Mesh* m_mesh;
		Texture* m_texture;
		Shader* m_shader;
	};
}
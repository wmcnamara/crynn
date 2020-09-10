#pragma once
#include "glad/glad.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include "Utility/Debug.h"

namespace Crynn
{
	/// <summary>
	/// Renders a mesh with a shader and a texture.
	/// </summary>
	class MeshRenderer
	{
	public:
		MeshRenderer(Mesh* mesh, Texture* texture, Shader* shader, mat4* modelMatrix);
		void Render();

		const Mesh* GetMesh() const { return m_mesh; }		
		bool active = true; //Toggle rendering
	private:		
		mat4* m_model;

		Mesh* m_mesh;
		Texture* m_texture;
		Shader* m_shader;
		bool m_indexed;
	};
}
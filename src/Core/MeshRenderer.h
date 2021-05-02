#pragma once
#pragma warning (disable : 4005)

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
	/// Renders a mesh/model with a shader.
	/// </summary>
	class MeshRenderer : EventListener
	{
	public:
		MeshRenderer(const Model& mesh, const Shader& shader, const Transform& transform);

		inline const Model& GetModel() const { return m_model; }
		inline const Shader& GetShader() const { return m_shader; }

		bool active = true; ///Toggle rendering

		//When true, all mesh renderers will bind and use their m_shader member variable as a shader to render with. If false, they will use the currently bound one.
		//This should usually be true.
		//Useful to easily apply a global shader to all meshrenderers without actually changing the member shader.
		static inline bool UseMemberShader = true; 
	private:		
		/// Draws a mesh to the screen with the objects specified int the constructor.
		void Render() override;

		const Transform& m_transform;
		 
		const Mat3 m_normalMat;
		const Model& m_model;
		const Shader& m_shader;
	};
}
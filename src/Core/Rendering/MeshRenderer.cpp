#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(const Model& mesh, const Material& material, const Transform& transform) :
		m_model(mesh),
		m_material(material),
		m_transform(transform),
		m_normalMat(Mat4(transpose(inverse(transform.GetMatrix())))) //World space normal matrix
	{}

	void MeshRenderer::Render()
	{
		const Shader& shader = m_material.m_shader;

		shader.Use();

		shader.SetFloat("time", (float)glfwGetTime()); //Set time uniform on current shader
		shader.SetMatrix4("model", &m_transform.GetMatrix());
		shader.SetMatrix3("normalMatrix", &m_normalMat);
		m_material.SetUniforms();

		m_model.Render(shader);
	}
}
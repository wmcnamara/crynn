#include "Material.h"

namespace crynn
{
	Material::Material(MaterialData data, Shader& shader) :
		m_properties(data),
		m_shader(shader)
	{}

	const Shader& Material::GetShader() const
	{
		return m_shader;
	}

	const crynn::MaterialData& Material::GetProperties() const
	{
		return m_properties;
	}


	void Material::SetUniforms() const
	{
		m_shader.Use();
		m_shader.SetVec3("material.ambient", m_properties.ambient);
		m_shader.SetVec3("material.diffuse", m_properties.diffuse);
		m_shader.SetVec3("material.specular", m_properties.specular);
		m_shader.SetFloat("material.shininess", m_properties.shininess);
	}
}
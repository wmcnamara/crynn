#include "Material.h"

namespace crynn
{
	Material::Material(MaterialData data, Shader shader) :
		m_properties(data),
		m_shader(shader)
	{}

	Shader& Material::GetShader()
	{
		return m_shader;
	}

	const crynn::MaterialData& Material::GetProperties() const
	{
		return m_properties;
	}

	void Material::SetProperties(MaterialData data)
	{
		m_properties = data;
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
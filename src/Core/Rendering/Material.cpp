#include "Material.h"

namespace crynn
{
	Material::Material(MaterialData data, const Shader& shader) : 
		properties(data),
		m_shader(shader)
	{}

	void Material::SetUniforms() const
	{
		m_shader.Use();
		m_shader.SetVec3("material.ambient", properties.ambient);
		m_shader.SetVec3("material.diffuse", properties.diffuse);
		m_shader.SetVec3("material.specular", properties.specular);
		m_shader.SetFloat("material.shininess", properties.shininess);
	}
}
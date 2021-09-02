#include "Light.h"
#include "Shader.h"

namespace crynn
{
	Light::Light(LightColorData _colorData, LightType _lightType) : 
		colorData(_colorData), 
		m_lightType(_lightType) 
	{}

	LightType Light::GetLightType()
	{
		return m_lightType;
	}

	void Light::SetIntensity(float intensity)
	{
		if (intensity > 0)
		{
			m_intensity = intensity;
		}
		else 
		{
			std::cout << "You're setting the intensity to a negative value\n";
		}
	}

	float Light::GetIntensity()
	{
		return m_intensity;
	}

	void Light::Update(float dt)
	{
		SetUniforms();
	}

	void Light::SetUniforms()
	{
		int lightTypeEnum = std::underlying_type<LightType>::type(m_lightType);

		Shader::SetVec3Current("light.position", GetPosition());
		Shader::SetVec3Current("light.ambient", colorData.ambient);
		Shader::SetVec3Current("light.diffuse", colorData.diffuse);
		Shader::SetVec3Current("light.specular", colorData.specular);
		Shader::SetFloatCurrent("light.intensity", m_intensity);
		Shader::SetIntCurrent("light.type", lightTypeEnum);
		Shader::SetBoolCurrent("sceneHasLights", true);

		SetExtraUniforms();
	}

	DirectionalLight::DirectionalLight(LightColorData _colorData, Vec3 _lightDir) : 
		Light(std::move(_colorData), LightType::Directional), 
		lightDir(glm::normalize(_lightDir))
	{}

	void DirectionalLight::SetLightDir(Vec3 _lightDir)
	{
		lightDir = glm::normalize(_lightDir);
	}

	void DirectionalLight::SetExtraUniforms()
	{
		Shader::SetVec3Current("light.direction", lightDir);
	}

	PointLight::PointLight(LightColorData _colorData, float _range) :
		Light(_colorData, LightType::Point), 
		m_range(_range)
	{}

	float PointLight::GetAttenuationRange()
	{
		return m_range;
	}

	void PointLight::SetAttenuationRange(float range)
	{
		if (range > 0)
			m_range = range;
	}

	void PointLight::SetExtraUniforms()
	{
		Shader::SetFloatCurrent("light.pointLightDistance", m_range);
	}
}
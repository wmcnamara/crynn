#include "Light.h"
#include "Shader.h"

namespace crynn
{
	Light::Light(LightColorData _colorData, LightType _lightType) : colorData(_colorData), lightType(_lightType) {}

	LightType Light::GetLightType()
	{
		return lightType;
	}

	void Light::Update(float dt)
	{
		SetUniforms();
	}

	void Light::SetUniforms()
	{
		int lightTypeEnum = std::underlying_type<LightType>::type(lightType);

		Shader::SetVec3Current("light.position", GetPosition());
		Shader::SetVec3Current("light.ambient", colorData.ambient);
		Shader::SetVec3Current("light.diffuse", colorData.diffuse);
		Shader::SetVec3Current("light.specular", colorData.specular);
		Shader::SetIntCurrent("light.type", std::underlying_type<LightType>::type(lightType));
		Shader::SetBoolCurrent("sceneHasLights", true);

		SetExtraUniforms();
	}

	DirectionalLight::DirectionalLight(LightColorData _colorData, Vec3 _lightDir) : 
		Light(std::move(_colorData), LightType::Directional), 
		lightDir(glm::normalize(_lightDir))
	{}

	void DirectionalLight::SetLightDir(glm::vec3 _lightDir)
	{
		lightDir = glm::normalize(_lightDir);
	}

	void DirectionalLight::SetExtraUniforms()
	{
		Shader::SetVec3Current("light.direction", lightDir);
	}

	PointLight::PointLight(LightColorData _colorData, float _range) :
		Light(_colorData, LightType::Point), 
		range(_range)
	{}

	void PointLight::SetExtraUniforms()
	{
		Shader::SetFloatCurrent("light.pointLightDistance", range);
	}
}
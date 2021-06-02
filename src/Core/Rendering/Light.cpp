#include "Light.h"
#include "Shader.h"

namespace crynn
{
	Light::Light(LightingColorData _colorData, LightType _lightType) : colorData(_colorData), lightType(_lightType) {}

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

		Shader::SetIntCurrent("light.type", lightTypeEnum);
		Shader::SetVec3Current("light.position", GetPosition());
		Shader::SetVec3Current("light.ambient", colorData.ambient);
		Shader::SetVec3Current("light.diffuse", colorData.diffuse);
		Shader::SetVec3Current("light.specular", colorData.specular);
		Shader::SetBoolCurrent("sceneHasLights", true);
	}
}
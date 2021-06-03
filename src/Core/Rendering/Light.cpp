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
		Shader shader = Shader::GetCurrentShaderProgram();

		shader.SetInt("light.type", lightTypeEnum);
		shader.SetVec3("light.position", GetPosition());
		shader.SetVec3("light.ambient", colorData.ambient);
		shader.SetVec3("light.diffuse", colorData.diffuse);
		shader.SetVec3("light.specular", colorData.specular);
		shader.SetBool("sceneHasLights", true);

		SetExtraUniforms();
	}

	DirectionalLight::DirectionalLight(LightColorData _colorData, Vec3 _lightDir) : Light(std::move(_colorData), LightType::Directional), lightDir(_lightDir)
	{
	}

	void DirectionalLight::SetLightDir(glm::vec3 _lightDir)
	{
		lightDir = glm::normalize(_lightDir);
	}

	void DirectionalLight::SetExtraUniforms()
	{
		Shader::SetVec3Current("light.direction", lightDir);
	}
}
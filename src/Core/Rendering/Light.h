#pragma once
#include "../CrynnObject.h"
#include <utility>

namespace crynn
{	
	struct LightColorData
	{
		Vec3 ambient = Vec3(1.0f, 1.0f, 1.0f);
		Vec3 diffuse = Vec3(0.5f, 0.5f, 0.5f);
		Vec3 specular = Vec3(0.1f);
	};

	enum struct LightType
	{
		Point,
		Directional,
		Spotlight,
	};

	//Base class for a light source in the Crynn game engine
	class Light : public CrynnObject
	{
	public:
		Light() = delete; //use an implementation of Light like DirectionalLight
		virtual ~Light() = default;

		LightColorData colorData;
		float intensity = 1.0f;

		virtual LightType GetLightType();
	protected: 
		Light(LightColorData _colorData, LightType _lightType);

		LightType lightType;

		virtual void SetUniforms() final; //Sets the necessary color and position uniforms
		virtual void SetExtraUniforms() = 0; //Used to set additional, light caster specific uniforms like lights direction for instance.
	private:
		virtual void Update(float dt) override; //Update will call SetUniforms
	};

	class DirectionalLight : public Light 
	{
	public:
		DirectionalLight(LightColorData _colorData, Vec3 _lightDir);
		virtual ~DirectionalLight() = default;

		void SetLightDir(Vec3 _lightDir);
		inline Vec3 GetLightDir() { return lightDir; }
	private:
		Vec3 lightDir = Vec3(1.0f, 0.0, 0.0);

		virtual void SetExtraUniforms() override;
	};

	class PointLight : public Light 
	{
	public:
		PointLight(LightColorData _colorData, float _range);
		virtual ~PointLight() = default;
		
		//Sets the attenuation range of the point light
		//Does nothing if range is less than 0
		void SetAttenuationRange(float range);

		//Returns the attenuation range of the point light
		float GetAttenuationRange();

	private:
		float m_range = 10.0f;

		virtual void SetExtraUniforms() override;
	};
}
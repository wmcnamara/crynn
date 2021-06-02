#pragma once
#include "../CrynnObject.h"

namespace crynn
{	
	struct LightingColorData
	{
		Vec3 ambient = Vec3(0.2f, 0.2f, 0.2f);
		Vec3 diffuse = Vec3(0.5, 0.5, 0.5);
		Vec3 specular = Vec3(0.1);
		int shininess = 16;
	};

	enum struct LightType
	{
		Point,
		Directional,
		Spotlight,
	};

	//https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping
	class Light : public CrynnObject
	{
	public:
		Light() = delete;
		virtual ~Light() = default;

		LightingColorData colorData;
		virtual LightType GetLightType();

	protected: 
		Light(LightingColorData _colorData, LightType _lightType);

		LightType lightType;
		virtual void SetUniforms();

	private:
		virtual void Update(float dt) override;
	};

}
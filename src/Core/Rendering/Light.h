#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/matrix.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../CrynnObject.h"
#include "Shader.h"

namespace crynn
{	
	struct LightingColorData
	{
		Vec3 ambient = Vec3(0.2f, 0.2f, 0.2f);
		Vec3 diffuse = Vec3(0.5, 0.5, 0.5);
		Vec3 specular = Vec3(0.1);
		int shininess = 16;
	};

	enum struct LightingType
	{
		Point,
		Directional
	};

	//https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping
	class Light : public CrynnObject
	{
	public:
		Light(LightingColorData colorData);
		~Light();

		Vec3 lightDir = Vec3(0.0, 0.0, 0.0);

		Vec2Int GetShadowMapDimensions();
		void SetShadowMapDimensions(Vec2Int dim);

		LightingColorData ColorData;
		LightingType LightType;
	private:
		void Update(float dt) override;
		Vec2Int shadowMapDimensions = Vec2Int(1024, 1024);

		void RenderDepthTexture();
		void SetUniforms();

		unsigned int m_FBO = 0;
		unsigned int depthMap = 0;

		Shader depthShader;
	};

}
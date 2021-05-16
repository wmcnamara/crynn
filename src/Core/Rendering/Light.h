#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/matrix.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../EventListener.h"
#include "../CrynnObject.h"
#include "Shader.h"
#include "MeshRenderer.h"

namespace crynn
{		
	//https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping

	class Light : CrynnObject
	{
	public:
		Light();
		~Light();

		Vec3 lightDir = Vec3(0.0, 0.0, 0.0);

		Vec2Int GetShadowMapDimensions();
		void SetShadowMapDimensions(Vec2Int dim);
	private:
		Vec2Int shadowMapDimensions = Vec2Int(1024, 1024);

		void RenderDepthTexture();
		unsigned int m_FBO = 0;
		unsigned int depthMap = 0;

		Shader depthShader;
	};
}
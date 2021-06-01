#include "Light.h"

namespace crynn 
{
	Light::Light(LightingColorData colorData) : depthShader("Shaders/DepthShader.vert", "Shaders/DepthShader.frag"), ColorData(colorData)
	{
		glGenTextures(1, &depthMap);
		glGenFramebuffers(1, &m_FBO);

		/*
		glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		*/
	}

	Light::~Light()
	{
		glDeleteTextures(1, &depthMap);
		glGenFramebuffers(1, &m_FBO);
	}

	Vec2Int Light::GetShadowMapDimensions()
	{
		return shadowMapDimensions;
	}

	void Light::SetShadowMapDimensions(Vec2Int dim)
	{
		if (dim.x <= 0 || dim.y <= 0)
			throw std::runtime_error("Shadowmap dimensions are 0");

		//256 is the minimum size of a shadow map here.
		if (dim.x < 256 || dim.y < 256)
			std::cout << "Use a higher shadowmap dimension.\n";

		shadowMapDimensions = dim;
	}

	void Light::Update(float dt)
	{
		SetUniforms();
	}

	void Light::RenderDepthTexture()
	{
		float near_plane = 1.0f, far_plane = 7.5f;
		glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);

		glm::mat4 lightView = glm::lookAt(GetPosition(),
			lightDir,
			glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 lightSpaceMatrix = lightProjection * lightView;

		depthShader.Use();
		depthShader.SetMatrix4("lightSpaceMatrix", &lightSpaceMatrix);
		glViewport(0, 0, shadowMapDimensions.x, shadowMapDimensions.y);
		glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
		glClear(GL_DEPTH_BUFFER_BIT);

		glBindTexture(GL_TEXTURE_2D, depthMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
			shadowMapDimensions.x, shadowMapDimensions.y, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		MeshRenderer::UseMemberShader = false; //force the scene to render with the depth shader.
		Application::ForceSceneRender(); //render scene into depth texture
		MeshRenderer::UseMemberShader = true;

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void Light::SetUniforms()
	{
		Shader::SetVec3Current("light.position", GetPosition());
		Shader::SetVec3Current("light.ambient", ColorData.ambient);
		Shader::SetVec3Current("light.diffuse", ColorData.diffuse);
		Shader::SetVec3Current("light.specular", ColorData.specular);
	}
}

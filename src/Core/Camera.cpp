#include "Camera.h"
namespace crynn
{
	Camera::Camera(vec3 position, Projection projType) : m_projType(projType)
	{
		Translate(position);

		m_camInvDir = glm::normalize(position - m_target);
		m_right = glm::normalize(glm::cross(vec3(0.0f, 1.0f, 0.0f), m_camInvDir));
		m_up = glm::cross(m_camInvDir, m_right);

		//Generate a UBO
		glGenBuffers(1, &m_matrixUBO);
		glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);
		glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		// Set camera matrix ubo to bind point 0
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, m_matrixUBO, 0, 2 * sizeof(glm::mat4));
	}

	Camera::~Camera()
	{
		glDeleteBuffers(1, &m_matrixUBO);
	}

	void Camera::SetFOV(float newFOV)
	{
		assert(Math::Between(0, 180, newFOV));

		m_fov = newFOV;
	}

	void Camera::BeforeUpdate(double deltaTime)
	{
		UpdateProjectionData();
		SetUniformData();
	}

	void Camera::SetUniformData()
	{
		//Bind the UBO, fill and unbind.
		glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(m_projection));
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(GetMatrix()));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		Shader::SetVec3Current("cameraPos", GetPosition());
	}

	void Camera::UpdateProjectionData()
	{
		//Get information about the viewport, to make sure the projection is configured correctly.
		//https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glViewport.xml
		//viewportDat[2] and [3] will have the width and height of the viewport
		float viewportDat[4] = { 0, 0, 0, 0 };
		glGetFloatv(GL_VIEWPORT, viewportDat);

		if (m_projType == Projection::Perspective)
		{
			glEnable(GL_DEPTH_TEST);
			m_projection = glm::perspective(
				glm::radians(m_fov),
				viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
				nearClipPlane,
				farClipPlane);
		}
		else if (m_projType == Projection::Orthographic)
		{
			m_projection = glm::ortho(
				glm::radians(m_fov),
				viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
				nearClipPlane,
				farClipPlane);
		}
	}
}
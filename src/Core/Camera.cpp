#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Rendering/Shader.h"
#include "Input.h"

namespace crynn
{
	Camera::Camera(Vec3 position, Projection projType) : m_projType(projType)
	{
		Translate(position);

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

	Mat4 Camera::CalculateProjection() const
	{
		//Get information about the viewport, to make sure the projection is configured correctly.
		//https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glViewport.xml
		//viewportDat[2] and [3] will have the width and height of the viewport
		float viewportDat[4] = { 0, 0, 0, 0 };
		glGetFloatv(GL_VIEWPORT, viewportDat);

		//Dont construct a projection with a zero size width/height
		if (viewportDat[2] <= 0 || viewportDat[3] <= 0)
		{
			return Mat4(1.0f); //If its <= 0 just give an identity matrix
		}

		if (m_projType == Projection::Perspective)
		{
			return glm::perspective(
				glm::radians(m_fov),
				viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
				m_nearClipPlane,
				m_farClipPlane);
		}
		else if (m_projType == Projection::Orthographic)
		{
			return glm::ortho(
				glm::radians(m_fov),
				viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
				m_nearClipPlane,
				m_farClipPlane);
		}

		std::cout << "Projection matrix is identity matrix. Please set a proper projection type.\n";
		return Mat4(1.0f);
	}

	Mat4 Camera::CalculateView() const
	{
		return glm::inverse(GetMatrix());
	}

	void Camera::SetClipPlanes(float farClipPlane, float nearClipPlane)
	{
		m_nearClipPlane = nearClipPlane;
		m_farClipPlane = farClipPlane;
	}

	void Camera::SetFOV(float newFOV)
	{
		assert(Math::Between(0, 180, newFOV));

		m_fov = newFOV;
	}

	void Camera::BeforeUpdate(float deltaTime)
	{
		SetUniformData();
	}

	void Camera::SetUniformData()
	{
		//Bind the UBO, fill and unbind.
		glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(CalculateProjection()));
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(CalculateView()));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		Shader::SetVec3Current("cameraPos", GetPosition());
	}
}
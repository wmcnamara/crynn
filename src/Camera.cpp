#include "Camera.h"
namespace Crynn
{
	namespace Rendering
	{
		Camera::Camera(Projection projType) : m_projType(projType)
		{
			UpdateViewMatrix();
			UpdateProjectionData();
			m_view = translate(m_view, vec3(0, 0, -3));
		}
		
		void Camera::Run()
		{
			UpdateViewMatrix(); 
			UpdateProjectionData();
		}

		void Camera::UpdateViewMatrix()
		{
			Shader::SetMatrix4Current("view", &m_view);
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
				m_projection = glm::perspective(
					glm::radians(60.0f),
					viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
					0.1f,
					100.0f);
			}
			else if (m_projType == Projection::Orthographic)
			{
				m_projection = glm::ortho(
					glm::radians(60.0f),
					viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
					0.1f,
					100.0f);
			}

			Shader::SetMatrix4Current("projection", &GetProjection()); //Set the uniform
		}
	}
}
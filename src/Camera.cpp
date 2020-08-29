#include "Camera.h"

void Camera::Input()
{
	/*
	const float cameraSpeed = 0.05f; // adjust accordingly
	if (glfwGetKey(Window::Instance().GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
		position += cameraSpeed * front;
	if (glfwGetKey(Window::Instance().GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
		position -= cameraSpeed * front;
	if (glfwGetKey(Window::Instance().GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		position -= glm::normalize(glm::cross(front, up)) * cameraSpeed;
	if (glfwGetKey(Window::Instance().GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
		position += glm::normalize(glm::cross(front, up)) * cameraSpeed;
	*/
}

void Camera::UpdatePositionData()
{
	//TODO
	/*
	cameraDirection = normalize(position - target);
	right = normalize(cross(vec3(0.0f, 1.0f, 0.0f), cameraDirection));
	up = cross(cameraDirection, right);

	view = glm::lookAt(position, position + front, up);
	*/

	Shader::SetMatrix4Current("view", &view);
}

void Camera::UpdateProjectionData()
{
	//Get information about the viewport, to make sure the projection is configured correctly.
	//https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glViewport.xml
	float viewportDat[4] = { 0, 0, 0, 0 };
	glGetFloatv(GL_VIEWPORT, viewportDat);

	if (m_projType == Projection::Perspective)
	{
		projection = glm::perspective(
			glm::radians(60.0f),
			viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
			0.1f,
			100.0f);
	}
	else if (m_projType == Projection::Orthographic)
	{
		projection = glm::ortho(
			glm::radians(60.0f),
			viewportDat[2] / viewportDat[3], //The first 2 elements of GL_VIEWPORT are irrelevant here.
			0.1f,
			100.0f);
	}

	Shader::SetMatrix4Current("projection", &GetProjection());
}

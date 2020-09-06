#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Shader.h"
#include "Input.h"

namespace Crynn
{
	using namespace glm;

	enum class Projection
	{
		Orthographic,
		Perspective
	};

	class Camera
	{
	public:
		Camera(Projection projType);

		mat4 GetProjection() const { return m_projection; }
		mat4 view = mat4(1.0f);

		void Run();
	private:
		mat4 m_projection;
		Projection m_projType;

		void UpdateViewMatrix();
		void UpdateProjectionData();
	};
}

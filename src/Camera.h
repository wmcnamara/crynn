#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Behaviour.h"
#include "Window.h"
#include "Shader.h"
#include "Input.h"
#include "Transform.h"

namespace Crynn 
{
	using namespace glm;

	enum class Projection
	{
		Orthographic,
		Perspective
	};

	/// <summary>
	/// Creates a camera that can render objects.
	/// This class creates a Uniform Buffer Object you can use to get projection and view matrix data. 
	/// This UBO will always be at binding point 0, and the block should always be called "CameraMatrices" in the shader.
	/// </summary>
	class Camera: protected Behaviour, protected Input, public Transform
	{
	public:
		Camera(vec3 position, Projection projType);
		~Camera();

		mat4 GetProjection() const { return m_projection; }
	private:
		void BeforeUpdate() override;
		void Start() override {};

		void InputCommands() override;

		mat4 m_projection = glm::mat4(1.0f);
		Projection m_projType;

		unsigned int m_matrixUBO;

		void SetUniformData();
		void UpdateProjectionData();
	};
}

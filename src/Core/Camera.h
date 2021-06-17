#pragma once
#pragma warning (disable : 4005)

#include "Math/Math.h"
#include "EventListener.h"
#include "Transform.h"
#include "../Utility/Defines.h"

namespace crynn 
{
	/// <summary>
	/// Projection type.
	/// </summary>
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
	class Camera : protected EventListener, public Transform
	{
	public:
		Camera(Vec3 position, Projection projType);
		~Camera();

		Mat4 GetProjection() const { return m_projection; }

		void SetClipPlanes(float farClipPlane, float nearClipPlane);

		//Sets the camera FOV in degrees. Clamped between 0 and 180
		void SetFOV(float newFOV);
	private:
		virtual void BeforeUpdate(float deltaTime) override;

		Mat4 m_projection = Mat4(1.0f);
		Projection m_projType = Projection::Perspective;

		unsigned int m_matrixUBO = 0;

		void SetUniformData();
		void UpdateProjectionData();

		float m_fov = 60.0f;
		float m_nearClipPlane = 0.1f;
		float m_farClipPlane = 100.0f;
	};
}
#pragma once
#pragma warning (disable : 4005)

#include "Math/Math.h"
#include "EventListener.h"
#include "Transform.h"
#include "glad/glad.h"

namespace crynn 
{
	/// <summary>
	/// Camera projection type.
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
		Camera(Vec3 position, Projection projType, bool setAsCurrent = true, float FOV = 90.0f, float nearClipPlane = 0.3f, float farClipPlane = 100.0f);
		~Camera();

		//Calculates a projection matrix from the nearand far clip plane, FOV and viewport data.
		//Returns identity matrix if viewport width or height is <= 0
		Mat4 CalculateProjection() const;

		//Calculates a view matrix for this camera.
		Mat4 CalculateView() const;

		//Sets the near and far clipping planes for this camera
		void SetClipPlanes(float nearClipPlane, float farClipPlane);

		//Sets the camera FOV in degrees. Clamped between 10 and 180
		void SetFOV(float newFOV);

	private:
		virtual void BeforeUpdate(FrameEventData deltaTime) override;

		Projection m_projType = Projection::Perspective;

		GLuint m_matrixUBO = 0;
		void SetUniformData();

		float m_fov = 60.0f;
		float m_nearClipPlane = 0.1f;
		float m_farClipPlane = 100.0f;
	};
}
#pragma once
#pragma warning (disable : 4005)

#include "Math/Math.h"
#include "EventListener.h"
#include "Transform.h"
#include "../Utility/Defines.h"
#include <optional>

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
		Camera(Vec3 position, Projection projTyp, bool setAsCurrent = true);
		~Camera();

		Mat4 CalculateProjection() const;
		Mat4 CalculateView() const;

		//Sets the near and far clipping planes for this camera
		void SetClipPlanes(float nearClipPlane, float farClipPlane);

		//Sets the camera FOV in degrees. Clamped between 10 and 180
		void SetFOV(float newFOV);

		//Sets this camera as the current camera the scene should render from
		void SetAsCurrentCamera();

		//Returns a pointer to the camera rendering the scene
		//Returns nullptr if no camera's exist, or the current camera is not set.
		static const Camera* const GetCurrentCamera();

	private:
		virtual void BeforeUpdate(float deltaTime) override;

		Projection m_projType = Projection::Perspective;

		GLuint m_matrixUBO = 0;

		void SetUniformData();

		float m_fov = 60.0f;
		float m_nearClipPlane = 0.1f;
		float m_farClipPlane = 100.0f;

		static inline Camera* currentlyRenderingCam = nullptr; //A reference to the camera rendering the scene
		static inline std::mutex currentCameraMutex;
	};
}
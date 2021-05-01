#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include "../Utility/Debug.h"
#include "Math/Math.h"

namespace crynn
{
	/// <summary>
	/// Matrix representation with easy functions to transform it.
	/// This class is mostly intended to be inherited from.
	/// Any transformations made, (translate, scale rotate) will be applied to the "transformMatrix" member.
	/// You can use this matrix however you please. Its generally used as a model or view matrix, and works very well with MeshRenderer.
	/// Inspired from the Unity transform class.
	/// </summary>
	class Transform
	{
	public:
	    void Translate(Vec3 translation);
	    void Scale(Vec3 scale);
	    void Rotate(Vec3 rot);
	   
	    void SetPosition(Vec3 position);
		Vec3 GetPosition() const;
	   
	    void SetScale(Vec3 scale);
		Vec3 GetScale() const;
	   
	    void SetRotation(Vec3 rot);
		const Quat& GetRotation() const;

		//Returns a non-const reference to the matrix struct this class is represented with
		//The matrix represents the model relative to the world
		Mat4& GetMatrix() const;
	private:
		Quat m_rotation = Quat(Vec3(0.0f, 0.0f, 0.0f));
		Vec3 m_position = Vec3(0, 0, 0);
		Vec3 m_scale = Vec3(1, 1, 1);

		mutable Mat4 m_matrix = Mat4(1.0f);
	};
}

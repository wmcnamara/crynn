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
	/// </summary>
	class Transform
	{
	public:
	    void Translate(Vec3 translation);
	    void Scale(Vec3 scale);
	    void Rotate(Vec3 rotation);
	   
	    void SetPosition(Vec3 position);
		Vec3 GetPosition() const;
	   
	    void SetScale(Vec3 scale);
		Vec3 GetScale() const;
	   
	    void SetRotation(Vec3 rotation);
		Vec3 GetRotation() const;

		//Returns a non-const reference to the matrix struct this class is represented with
		inline Mat4& GetMatrix() { return m_matrix; }
	private:
		//Updated when matrix transformations occur, used to easily return and track rotation scale and pos data.
		Vec3 currentRot = Vec3(0.0);
		Vec3 currentScale = Vec3(1.0, 1.0f, 1.0f);
		Vec3 currentPos = Vec3(0.0);

		Mat4 m_matrix = Mat4(1.0f);
	};
}

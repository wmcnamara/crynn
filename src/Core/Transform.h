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
	    void Translate(Vec3 translation); //Applies a translation to this object.
	    void Scale(Vec3 scale); //Applies a scale to the object
	    void Rotate(Vec3 rot); //Applies a rotation to the object. rot is the XYZ euler angle rotation. Angles should be in degrees
	   
	    void SetPosition(Vec3 position); //Sets the position of the object
		Vec3 GetPosition() const; //Returns a Vec3 containing the XYZ position of the object
	   
	    void SetScale(Vec3 scale); //Sets the scale of the object
		Vec3 GetScale() const; //Returns a Vec3 containing the XYZ scale of the object
	   
	    void SetRotation(Vec3 rot); //Sets the objects rotation. rot is the XYZ euler angle rotation. Angles should be in degrees
		const Quat& GetRotation() const; //Returns a quaternion representing the objects rotation. If you would like euler angles, use GetRotationEuler().
		Vec3 GetRotationEuler() const; //Returns a Vec3 with the euler angle rotation state.

		//Returns a non-const reference to the matrix struct this class is represented with
		//The matrix represents the model relative to the world
		Mat4& GetMatrix() const;
	private:
		Quat m_rotation = Quat(Vec3(0.0f, 0.0f, 0.0f));
		Vec3 m_position = Vec3(0, 0, 0);
		Vec3 m_scale = Vec3(1, 1, 1);

		mutable Vec3 m_eulerRotation = Vec3(0, 0, 0); //Cache for the euler rotation of the object. Not used in any calculation. Degrees
		mutable Mat4 m_matrix = Mat4(1.0f);
	};
}

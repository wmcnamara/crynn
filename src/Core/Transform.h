#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>
#include <memory>
#include <unordered_set>
#include "Math/Math.h"
#include <memory>

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
		Transform();
		virtual ~Transform();

		Transform(const Transform& other);
		Transform& operator=(const Transform& other);
		Transform(Transform&& other) noexcept;
		Transform& operator=(Transform&& other) noexcept;

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

		Vec3 GetForwardVector() const;
		Vec3 GetRightVector() const;
		Vec3 GetUpVector() const;

		//Creates a transformation matrix from the position, rotation and scale of this transform.
		Mat4 GetMatrix() const;

		void SetParent(Transform* parent);
		Transform& GetParent();

		void RemoveParent();

		//Returns a reference to the set of children this transform has
		const std::unordered_set<Transform*>& GetChildren();
	private:
		Vec3 m_position = Vec3(0, 0, 0);
		Quat m_rotation = Quat(Vec3(0.0f, 0.0f, 0.0f));
		Vec3 m_scale = Vec3(1, 1, 1);

		Vec3 m_eulerRotation = Vec3(0, 0, 0); //Cache for the euler rotation of the object. Not used in any calculation. Degrees

		Transform* m_parent = nullptr;
		std::unordered_set<Transform*> m_children; //pointers to this objects children.

		//Recursively computes a matrix that applies transformations from this matrice's parents, instead of the world.
		//The matrix parameter passed to this function will have all the transformations from its parent transforms applied to it.
		Mat4& ComputeLocalMatrixRecursive(Mat4& matrix, const Transform* const transform) const;

		//Caching variables
		mutable Mat4 m_worldMatrixCache = Mat4(1.0f); //Cached model matrix with transformations relative to the world origin
		mutable std::atomic_bool m_recalculateMatrix = true; // Indicates model matrix needs to be recalculated. set to true after translating/rotating/scaling.
	};
}

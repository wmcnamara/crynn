#include "Transform.h"

namespace crynn
{
	Transform::Transform()
	{
		
	}

	Transform::~Transform()
	{			
		//Remove this node from the parent transforms children
		if (m_parent != nullptr)
		{
			m_parent->m_children.erase(this);
		}
		
		//Remove links in children
		for (Transform* child : m_children)
		{
			child->m_parent = nullptr;
		}
	}

	Transform::Transform(const Transform& other)
	{
		m_position = other.m_position;
		m_rotation = other.m_rotation;
		m_scale = other.m_scale;

		m_eulerRotation = other.m_eulerRotation;

		//Add this as a child to other parent
		m_parent = other.m_parent;
		other.m_parent->m_children.insert(this);

		m_children = std::unordered_set<Transform*>();

		m_worldMatrixCache = Mat4(1.0f);
		m_recalculateMatrix = true;
	}

	Transform& Transform::operator=(const Transform& other)
	{
		m_position = other.m_position;
		m_rotation = other.m_rotation;
		m_scale = other.m_scale;

		m_eulerRotation = other.m_eulerRotation;

		//Add this as a child to other parent
		m_parent = other.m_parent;
		other.m_parent->m_children.insert(this);

		m_children = std::unordered_set<Transform*>();

		m_worldMatrixCache = Mat4(1.0f);
		m_recalculateMatrix = true;

		return *this;
	}

	Transform::Transform(Transform&& other) noexcept
	{
		if (&other != this) 
		{
			m_position = other.m_position;
			m_rotation = other.m_rotation;
			m_scale = other.m_scale;

			m_eulerRotation = other.m_eulerRotation;
			m_parent = other.m_parent;

			m_children = std::move(other.m_children);

			m_worldMatrixCache = std::move(other.m_worldMatrixCache);
			m_recalculateMatrix = true;


			other.m_position = Vec3(0.0f);
			other.m_rotation = Vec3(0.0f);
			other.m_scale = Vec3(0.0f);
			other.m_eulerRotation = Vec3(0.0f);
			other.m_parent = nullptr;
		}		
	}

	Transform& Transform::operator=(Transform&& other) noexcept
	{
		if (&other != this) 
		{
			m_position = other.m_position;
			m_rotation = other.m_rotation;
			m_scale = other.m_scale;

			m_eulerRotation = other.m_eulerRotation;
			m_parent = other.m_parent;

			m_children = std::move(other.m_children);

			m_worldMatrixCache = std::move(other.m_worldMatrixCache);
			m_recalculateMatrix = true;


			other.m_position = Vec3(0.0f);
			other.m_rotation = Vec3(0.0f);
			other.m_scale = Vec3(0.0f);
			other.m_eulerRotation = Vec3(0.0f);
			other.m_parent = nullptr;
		}

		return *this;
	}

	void Transform::Translate(Vec3 translation)
	{
		m_position += translation;

		m_recalculateMatrix = true;
	}	

	void Transform::Scale(Vec3 scale)
	{
		m_scale += scale;

		m_recalculateMatrix = true;
	}

	void Transform::Rotate(Vec3 rot)
	{		
		//Calculate quaternion
		m_rotation *= glm::quat(glm::radians(rot));
		m_eulerRotation += rot;

		m_recalculateMatrix = true;
	}

	void Transform::SetPosition(Vec3 pos)
	{
		m_position = pos; //Update currentPos

		m_recalculateMatrix = true;
	}

	Vec3 Transform::GetPosition() const
	{
		return m_position;
	}

	void Transform::SetScale(Vec3 newScale)
	{
		m_scale = newScale;

		m_recalculateMatrix = true;
	}

	Vec3 Transform::GetScale() const
	{
		return m_scale;
	}

	void Transform::SetRotation(Vec3 rot)
	{		
		m_rotation = glm::quat(glm::radians(rot));
		m_eulerRotation = rot;

		m_recalculateMatrix = true;
	}

	const Quat& Transform::GetRotation() const
	{
		return m_rotation;
	}

	Vec3 Transform::GetRotationEuler() const
	{
		return m_eulerRotation;
	}

	Vec3 Transform::GetForwardVector() const
	{
		const Vec3 forward = Vec3(0, 0, 1);

		return glm::normalize(m_rotation * forward);
	}

	Vec3 Transform::GetRightVector() const
	{
		const Vec3 forward = GetForwardVector();

		Vec3 up = Vec3(0, 1, 0);

		return glm::normalize(glm::cross(up, -forward));
	}

	Vec3 Transform::GetUpVector() const
	{
		return glm::normalize(glm::cross(GetRightVector(), GetForwardVector()));
	}

	//My own little implementation of a transformation hierarchy.
	//Its a bit complicated, so take a moment to look through if you're confused.
	//Basically the idea is to compute a matrix for the current pos/rot/scale, and then multiply that matrix with the parent matrices recursively.

	Mat4 Transform::GetMatrix() const
	{  
		if (m_recalculateMatrix) 
		{		
			//Apply world space transformations
			m_worldMatrixCache = Mat4(1.0f);
			m_worldMatrixCache = glm::scale(m_worldMatrixCache, m_scale);
			m_worldMatrixCache = glm::translate(m_worldMatrixCache, m_position);
			m_worldMatrixCache *= glm::mat4_cast(m_rotation);

			m_recalculateMatrix = false;
		}

		//Apply parent transformations to it aswell
		return ComputeLocalMatrixRecursive(m_worldMatrixCache, this);
	}

	void Transform::SetParent(Transform* parent)
	{
		if (parent == nullptr || parent == this)
			return;

		m_parent = parent;
		parent->m_children.insert(this);

		m_recalculateMatrix = true;
	}

	Transform& Transform::GetParent()
	{
		return *m_parent;
	}

	void Transform::RemoveParent()
	{
		m_parent = nullptr;
	}

	Mat4& Transform::ComputeLocalMatrixRecursive(Mat4& matrix, const Transform* const transform) const
	{
		if (transform->m_parent == nullptr)
			return matrix;

		//Recursively walk parent model matrices and multiply them along the way
		return ComputeLocalMatrixRecursive(matrix *= m_parent->m_worldMatrixCache, transform->m_parent);
	}
}
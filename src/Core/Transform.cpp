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

	Mat4& Transform::GetMatrix() const
	{  
		if (m_recalculateMatrix) 
		{		
			//Apply world space transformations (model matrix)
			m_worldMatrix = Mat4(1.0f);
			m_worldMatrix = glm::scale(m_worldMatrix, m_scale);
			m_worldMatrix = glm::translate(m_worldMatrix, m_position);
			m_worldMatrix *= glm::mat4_cast(m_rotation);

			m_recalculateMatrix = false;
		}

		//Apply parent transformations to it aswell
		m_localMatrix = std::move(ComputeLocalMatrixRecursive(m_worldMatrix, this));

		return m_localMatrix;
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
		return ComputeLocalMatrixRecursive(matrix *= m_parent->m_worldMatrix, transform->m_parent);
	}
}
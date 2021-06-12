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
			m_parent->m_children.erase(this);
		
		//Remove links in children
		for (Transform* child : m_children)
		{
			child->m_parent = nullptr;
		}
	}

	void Transform::Translate(Vec3 translation)
	{
		m_position += translation;
	}	

	void Transform::Scale(Vec3 scale)
	{
		m_scale += scale;
	}

	void Transform::Rotate(Vec3 rot)
	{		
		rot *= DEG2RAD; //convert to radians
		m_rotation *= glm::quat(rot);

		m_eulerRotation += rot;
	}

	void Transform::SetPosition(Vec3 pos)
	{
		m_position = pos; //Update currentPos
	}

	Vec3 Transform::GetPosition() const
	{
		return m_position;
	}

	void Transform::SetScale(Vec3 newScale)
	{
		m_scale = newScale;
	}

	Vec3 Transform::GetScale() const
	{
		return m_scale;
	}

	void Transform::SetRotation(Vec3 rot)
	{
		rot *= DEG2RAD; //convert to radians
		m_rotation = glm::quat(rot);

		m_eulerRotation = rot;
	}

	const Quat& Transform::GetRotation() const
	{
		return m_rotation;
	}

	Vec3 Transform::GetRotationEuler() const
	{
		return m_eulerRotation * RAD2DEG;
	}

	//My own little implementation of a transformation hierarchy.
	//Its a bit complicated, so take a moment to look through if you're confused.
	//TODO implement matrix caching

	Mat4& Transform::GetMatrix() const
	{  
		//Apply this matrices world transformations
		m_worldMatrix = Mat4(1.0f);
		m_worldMatrix = glm::scale(m_worldMatrix, m_scale);
		m_worldMatrix *= glm::mat4_cast(m_rotation);
		m_worldMatrix = glm::translate(m_worldMatrix, m_position);

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
	}

	Transform* Transform::GetParent()
	{
		return m_parent;
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
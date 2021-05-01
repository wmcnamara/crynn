#include "Transform.h"

namespace crynn
{
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
	}

	const Quat& Transform::GetRotation() const
	{
		return m_rotation;
	}

	Mat4& Transform::GetMatrix() const
	{
		m_matrix = Mat4(1.0f);
		m_matrix = glm::scale(m_matrix, m_scale);
		m_matrix *= glm::mat4_cast(m_rotation);
		m_matrix = glm::translate(m_matrix, m_position);

		return m_matrix;
	}
}
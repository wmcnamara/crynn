#include "Transform.h"

namespace Crynn
{
	void Transform::Translate(glm::vec3 translation)
	{
		m_matrix = glm::translate(m_matrix, translation);
	}

	void Transform::Translate(glm::vec3 translation, glm::mat4* matrix)
	{
		*matrix = glm::translate(*matrix, translation);
	}

	void Transform::Scale(glm::vec3 scale)
	{
		m_matrix = glm::scale(m_matrix, scale);
	}

	void Transform::Scale(glm::vec3 scale, glm::mat4* matrix)
	{
		*matrix = glm::scale(*matrix, scale);
	}

	void Transform::Rotate(float rotationInDegrees, glm::vec3 axis)
	{
		m_matrix = glm::rotate(m_matrix, glm::radians(rotationInDegrees), axis);
	}

	void Transform::Rotate(float rotationInDegrees, glm::vec3 axis, glm::mat4* matrix)
	{
		*matrix = glm::rotate(*matrix, glm::radians(rotationInDegrees), axis);
	}

	void Transform::SetPosition(glm::vec3 position)
	{
		//3rd colum, 1st second and 3rd row.
		m_matrix[3][0] = position.x;
		m_matrix[3][1] = position.y;
		m_matrix[3][2] = position.z;
	}

	void Transform::SetPosition(float x, float y, float z)
	{		
		//3rd colum, 1st second and 3rd row.
		m_matrix[3][0] = x;
		m_matrix[3][1] = y;
		m_matrix[3][2] = z;
	}

	void Transform::SetPosition(float x, float y, float z, glm::mat4& matrix)
	{		
		//3rd colum, 1st second and 3rd row.
		matrix[3][0] = x;
		matrix[3][1] = y;
		matrix[3][2] = z;
	}

	void Transform::InheritFrom(std::shared_ptr<Transform> matrix)
	{
		m_parentMatrix = matrix;
	}
}
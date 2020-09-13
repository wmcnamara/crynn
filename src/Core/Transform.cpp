#include "Transform.h"

namespace Crynn
{
	void Transform::Translate(glm::vec3 translation)
	{
		transformMatrix = glm::translate(transformMatrix, translation);
	}

	void Transform::Scale(glm::vec3 scale)
	{
		transformMatrix = glm::scale(transformMatrix, scale);
	}

	void Transform::Rotate(float rotationInDegrees, glm::vec3 axis)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(rotationInDegrees), axis);
	}

	void Transform::SetPosition(glm::vec3 position)
	{
		//3rd colum, 1st second and 3rd row.
		transformMatrix[3][0] = position.x;
		transformMatrix[3][1] = position.y;
		transformMatrix[3][2] = position.z;
	}

	void Transform::SetPosition(float x, float y, float z)
	{		
		//3rd colum, 1st second and 3rd row.
		transformMatrix[3][0] = x;
		transformMatrix[3][1] = y;
		transformMatrix[3][2] = z;
	}
	void Transform::SetPosition(float x, float y, float z, glm::mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[3][0] = x;
		matrix[3][1] = y;
		matrix[3][2] = z;
	}

	void Transform::SetPosition(glm::vec3 position, glm::mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[3][0] = position.x;
		matrix[3][1] = position.y;
		matrix[3][2] = position.z;
	}

	void Transform::SetScale(float x, float y, float z, glm::mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[0][0] = x;
		matrix[1][1] = y;
		matrix[2][2] = z;
	}

	void Transform::SetScale(glm::vec3 scale, glm::mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[0][0] = scale.x;
		matrix[1][1] = scale.y;
		matrix[2][2] = scale.z;
	}
}
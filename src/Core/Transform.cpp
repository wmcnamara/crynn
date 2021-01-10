#include "Transform.h"

namespace crynn
{
	void Transform::Translate(glm::vec3 translation)
	{
		transformMatrix = glm::translate(transformMatrix, translation);
	}
	
	void Transform::Translate(float x, float y, float z)
	{
		transformMatrix = translate(transformMatrix, glm::vec3(x, y, z));
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

	glm::vec3 Transform::GetPosition()
	{
		glm::vec3 pos;

		pos.x = transformMatrix[3][0];
		pos.y = transformMatrix[3][1];
		pos.z = transformMatrix[3][2];

		return pos;
	}

	void Transform::SetScale(glm::vec3 scale)
	{
		//Scale matrix. first 3 columns and rows.
		transformMatrix[0][0] = scale.x;
		transformMatrix[1][1] = scale.y;
		transformMatrix[2][2] = scale.z;
	}

	void Transform::SetScale(float x, float y, float z)
	{
		//Scale matrix. first 3 columns and rows.
		transformMatrix[0][0] = x;
		transformMatrix[1][1] = y;
		transformMatrix[2][2] = z;
	}

	glm::vec3 Transform::GetScale()
	{
		glm::vec3 scale;

		//Scale matrix. first 3 columns and rows.
		scale.x = transformMatrix[0][0];
		scale.y = transformMatrix[1][1];
		scale.z = transformMatrix[2][2];

		return scale;
	}

	//THIS IS BROKEN. DO NOT USE
	void Transform::SetRotation(glm::vec3 rotation)
	{
		assert(1 && "SetRotation IS BROKEN. DO NOT USE");

		glm::mat4 rotMatrix = glm::mat4(1.0f);

		//Set the scale	to the current values
		rotMatrix[0][0] = transformMatrix[0][0];
		rotMatrix[1][1] = transformMatrix[1][1];
		rotMatrix[2][2] = transformMatrix[2][2];

		//Create a rotation matrix with the new rotation
		//rotMatrix = glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);

		//Set the position to the current values
		rotMatrix[3][0] = transformMatrix[3][0];
		rotMatrix[3][1] = transformMatrix[3][1];
		rotMatrix[3][2] = transformMatrix[3][2];

		transformMatrix = rotMatrix;
	}

	//THIS IS BROKEN. DO NOT USE
	void Transform::SetRotation(float x, float y, float z)
	{
		assert(1 && "SetRotation FUNCTION IS BROKEN. DO NOT USE");

		glm::mat4 rotMatrix = glm::mat4(1.0f);

		//Set the scale	to the current values
		rotMatrix[0][0] = transformMatrix[0][0];
		rotMatrix[1][1] = transformMatrix[1][1];
		rotMatrix[2][2] = transformMatrix[2][2];

		//Create a rotation matrix with the new rotation
		//rotMatrix = glm::eulerAngleXYZ(glm::radians(x), glm::radians(y), glm::radians(z));

		//Set the position to the current values
		rotMatrix[3][0] = transformMatrix[3][0];
		rotMatrix[3][1] = transformMatrix[3][1];
		rotMatrix[3][2] = transformMatrix[3][2];

		transformMatrix = rotMatrix;
	}

	void Transform::GetRotation()
	{
	}
}
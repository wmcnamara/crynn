#include "Transform.h"

namespace crynn
{
	void Transform::Translate(glm::vec3 translation)
	{
		transformMatrix = glm::translate(transformMatrix, translation);

		currentPos += translation;
	}	

	void Transform::Scale(glm::vec3 scale)
	{
		transformMatrix = glm::scale(transformMatrix, scale);

		currentScale += scale;
	}

	void Transform::Rotate(glm::vec3 rotation)
	{
		rotation *= DEG2RAD;
		transformMatrix *= glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);

		currentRot += (rotation * RAD2DEG); //Convert back and add the new rotation
	}

	void Transform::SetPosition(glm::vec3 position)
	{
		//3rd colum, 1st second and 3rd row.
		transformMatrix[3][0] = position.x;
		transformMatrix[3][1] = position.y;
		transformMatrix[3][2] = position.z;

		currentPos = position; //Update currentPos
	}

	glm::vec3 Transform::GetPosition()
	{
		return currentPos;
	}

	void Transform::SetScale(glm::vec3 scale)
	{
		//Scale matrix. first 3 columns and rows.
		transformMatrix[0][0] = scale.x;
		transformMatrix[1][1] = scale.y;
		transformMatrix[2][2] = scale.z;

		currentScale = scale;
	}

	glm::vec3 Transform::GetScale()
	{
		return currentScale;
	}

	void Transform::SetRotation(glm::vec3 rotation)
	{
		glm::mat4 rot = glm::mat4(1.0f);

		//Set scale
		rot[0][0] = transformMatrix[0][0];
		rot[1][1] = transformMatrix[1][1];
		rot[2][2] = transformMatrix[2][2];

		//Create and apply the new rotation
		rot *= glm::eulerAngleXYZ(glm::radians(rotation.x), glm::radians(rotation.y), glm::radians(rotation.z));

		//Apply transform
		rot[3][0] = transformMatrix[3][0];
		rot[3][1] = transformMatrix[3][1];
		rot[3][2] = transformMatrix[3][2];

		transformMatrix = rot;

		currentRot = rotation;
	}

	glm::vec3 Transform::GetRotation()
	{
		return currentRot;
	}
}
#include "Transform.h"

namespace crynn
{
	void Transform::Translate(Vec3 translation)
	{
		m_matrix = glm::translate(m_matrix, translation);

		currentPos += translation;
	}	

	void Transform::Scale(Vec3 scale)
	{
		m_matrix = glm::scale(m_matrix, scale);

		currentScale += scale;
	}

	void Transform::Rotate(Vec3 rotation)
	{
		rotation *= DEG2RAD;
		m_matrix *= glm::eulerAngleXYZ(rotation.x, rotation.y, rotation.z);

		currentRot += (rotation * RAD2DEG); //Convert back and add the new rotation
	}

	void Transform::SetPosition(Vec3 position)
	{
		Mat4 posMat(1.0f);

		//Set scale
		posMat[0][0] = currentScale.x;
		posMat[1][1] = currentScale.y;
		posMat[2][2] = currentScale.z;

		//Create and apply the new rotation
		posMat *= glm::eulerAngleXYZ(glm::radians(currentRot.x), glm::radians(currentRot.y), glm::radians(currentRot.z));

		//Apply transform
		posMat = glm::translate(posMat, position);

		m_matrix = posMat;
		currentPos = position; //Update currentPos
	}

	Vec3 Transform::GetPosition() const
	{
		return currentPos;
	}

	void Transform::SetScale(Vec3 scale)
	{
		Mat4 scaleMat(1.0f);
		scaleMat = glm::scale(scaleMat, scale);

		//Create and apply the new rotation
		scaleMat *= glm::eulerAngleXYZ(glm::radians(currentRot.x), glm::radians(currentRot.y), glm::radians(currentRot.z));

		//Apply transform
		scaleMat[3][0] = currentPos.x;
		scaleMat[3][1] = currentPos.y;
		scaleMat[3][2] = currentPos.z;

		m_matrix = scaleMat;	
		currentScale = scale;
	}

	Vec3 Transform::GetScale() const
	{
		return currentScale;
	}

	void Transform::SetRotation(Vec3 rotation)
	{
		Mat4 rot(1.0f);

		//Set scale
		rot[0][0] = currentScale.x;
		rot[1][1] = currentScale.y;
		rot[2][2] = currentScale.z;

		//Create and apply the new rotation
		rot *= glm::eulerAngleXYZ(glm::radians(rotation.x), glm::radians(rotation.y), glm::radians(rotation.z));

		//Apply translation
		rot[3][0] = currentPos.x;
		rot[3][1] = currentPos.y;
		rot[3][2] = currentPos.z;

		m_matrix = rot;

		currentRot = rotation;
	}

	Vec3 Transform::GetRotation() const
	{
		return currentRot;
	}
}
#include "Transform.h"

namespace Crynn
{
	void Transform::Translate(vec3 translation)
	{
		transformMatrix = translate(transformMatrix, translation);
	}
	
	void Transform::Translate(float x, float y, float z)
	{
		transformMatrix = translate(transformMatrix, glm::vec3(x, y, z));
	}

	void Transform::Scale(vec3 scale)
	{
		transformMatrix = glm::scale(transformMatrix, scale);
	}

	void Transform::Rotate(float rotationInDegrees, vec3 axis)
	{
		transformMatrix = rotate(transformMatrix, radians(rotationInDegrees), axis);
	}

	void Transform::SetPosition(vec3 position)
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

	vec3 Transform::GetPosition()
	{
		vec3 pos;
		pos.x = transformMatrix[3][0];
		pos.y = transformMatrix[3][1];
		pos.z = transformMatrix[3][2];

		return pos;
	}

	void Transform::SetScale(vec3 scale)
	{
		//3rd colum, 1st second and 3rd row.
		transformMatrix[0][0] = scale.x;
		transformMatrix[1][1] = scale.y;
		transformMatrix[2][2] = scale.z;
	}

	void Transform::SetScale(float x, float y, float z)
	{
		//3rd colum, 1st second and 3rd row.
		transformMatrix[0][0] = x;
		transformMatrix[1][1] = y;
		transformMatrix[2][2] = z;
	}

	vec3 Transform::GetScale()
	{
		glm::vec3 scale;
		//3rd colum, 1st second and 3rd row.
		scale.x = transformMatrix[0][0];
		scale.y = transformMatrix[1][1];
		scale.z = transformMatrix[2][2];

		return scale;
	}

	//Static functions
	void Transform::SetPosition(float x, float y, float z, mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[3][0] = x;
		matrix[3][1] = y;
		matrix[3][2] = z;
	}

	void Transform::SetPosition(vec3 position, mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[3][0] = position.x;
		matrix[3][1] = position.y;
		matrix[3][2] = position.z;
	}

	void Transform::SetScale(float x, float y, float z, mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[0][0] = x;
		matrix[1][1] = y;
		matrix[2][2] = z;
	}

	void Transform::SetScale(vec3 scale, mat4& matrix)
	{
		//3rd colum, 1st second and 3rd row.
		matrix[0][0] = scale.x;
		matrix[1][1] = scale.y;
		matrix[2][2] = scale.z;
	}

	void Transform::SetRotation(float angle, float x, float y, float z, mat4& matrix)
	{
		//assert(0 && "Dont use Setrotation");
		matrix = glm::rotate(mat4(1.0f), angle, vec3(x, y, z));	
	}

	void Transform::SetRotation(float angle, vec3 rotation, mat4& matrix)
	{
		//assert(0 && "Dont use Setrotation");
		matrix = glm::rotate(mat4(1.0f), angle, rotation);
	}
}
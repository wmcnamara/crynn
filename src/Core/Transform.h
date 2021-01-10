#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>
#include <vector>
namespace crynn
{
	/// <summary>
	/// Matrix representation with easy functions to transform it.
	/// This class is mostly intended to be inherited from.
	/// Any transformations made, (translate, scale rotate) will be applied to the "transformMatrix" member.
	/// You can use this matrix however you please. Its generally used as a model or view matrix, and works very well with MeshRenderer.
	/// </summary>
	class Transform
	{
	public:
		Transform() = default;

		void Translate(glm::vec3 translation);
		void Translate(float x, float y, float z);

		void Scale(glm::vec3 scale);

		void Rotate(float rotationInDegrees, glm::vec3 axis);

		void SetPosition(glm::vec3 position);
		void SetPosition(float x, float y, float z);
		glm::vec3 GetPosition();

		void SetScale(glm::vec3 scale);
		void SetScale(float x, float y, float z);
		glm::vec3 GetScale();

		void SetRotation(glm::vec3 rotation);
		void SetRotation(float x, float y, float z);
		void GetRotation();

		//Returns a non-const reference to the matrix struct this class is represented with
		inline glm::mat4& GetMatrix() { return transformMatrix; }
	private:
		glm::mat4 transformMatrix = glm::mat4(1.0f);
	};
}

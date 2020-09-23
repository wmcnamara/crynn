#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <memory>
#include <vector>

using namespace glm;

namespace Crynn
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

		void Translate(vec3 translation);
		void Scale(vec3 scale);
		void Rotate(float rotationInDegrees, vec3 axis);

		void SetPosition(vec3 position);
		void SetPosition(float x, float y, float z);
		vec3 GetPosition();

		void SetScale(vec3 scale);
		void SetScale(float x, float y, float z);
		vec3 GetScale();

		static void SetPosition(float x, float y, float z, mat4& matrix);
		static void SetPosition(vec3 position, mat4& matrix);
		
		static void SetScale(float x, float y, float z, mat4& matrix);
		static void SetScale(vec3 scale, mat4& matrix);

		static void SetRotation(float angle, float x, float y, float z, mat4& matrix);
		static void SetRotation(float angle, vec3 rotation, mat4& matrix);

		/// Prints the content of a 4x4 matrix to the console
		static void LogMatrix4(const mat4& matrix);

		mat4 transformMatrix = mat4(1.0f);
	private:
	};
}

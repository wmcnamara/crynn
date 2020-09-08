#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

namespace Crynn
{
	/// <summary>
	/// Class to easily track and transform matricies.
	/// </summary>
	class Transform
	{
	public:
		Transform() = default;

		void Translate(glm::vec3 translation);
		static void Translate(glm::vec3 translation, glm::mat4* matrix);

		void Scale(glm::vec3 scale);
		static void Scale(glm::vec3 scale, glm::mat4* matrix);
		
		void Rotate(float rotationInDegrees, glm::vec3 axis);
		static void Rotate(float rotationInDegrees, glm::vec3 axis, glm::mat4* matrix);

		void SetPosition(glm::vec3 position);

		void SetPosition(float x, float y, float z);
		static void SetPosition(float x, float y, float z, glm::mat4& matrix);

		void InheritFrom(std::shared_ptr<Transform> matrix);
	private:
		glm::mat4 m_matrix = glm::mat4(1.0f);

		//TODO
		glm::vec3 m_position = glm::vec3(0, 0, 0);
		glm::vec3 m_scale = glm::vec3(0, 0, 0);
		glm::vec3 m_rotation = glm::vec3(0, 0, 0);

		std::shared_ptr<Transform> m_parentMatrix = nullptr; //You can use this to inherit matrix transformations from other objects.
	};
}

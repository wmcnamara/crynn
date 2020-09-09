#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include <vector>

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
		void Scale(glm::vec3 scale);
		void Rotate(float rotationInDegrees, glm::vec3 axis);

		void SetPosition(glm::vec3 position);
		void SetPosition(float x, float y, float z);

		//TODO
		void AddChild();
		void ClearChild(); //Stops inheriting from the object set by InheritFrom()

	protected:
		glm::mat4 transformMatrix = glm::mat4(1.0f);
	private:
		//TODO
		glm::vec3 m_position = glm::vec3(0, 0, 0);
		glm::vec3 m_scale = glm::vec3(0, 0, 0);
		glm::vec3 m_rotation = glm::vec3(0, 0, 0);

		//You can use this to inherit matrix transformations from other objects.
	};
}

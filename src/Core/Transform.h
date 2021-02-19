#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include "../Utility/Debug.h"

#define PI 3.14159f
#define DEG2RAD PI / 180.0f //Converts an angle in degrees to radians
#define RAD2DEG 180.0f / PI //Converts an angle in radians to degrees

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
	    void Translate(glm::vec3 translation);
	    void Scale(glm::vec3 scale);
	    void Rotate(glm::vec3 rotation);
	   
	    void SetPosition(glm::vec3 position);
	    glm::vec3 GetPosition();
	   
	    void SetScale(glm::vec3 scale);
	    glm::vec3 GetScale();
	   
	    void SetRotation(glm::vec3 rotation);
	    glm::vec3 GetRotation();
	   
		bool HasParent() { return m_parent != nullptr; }
		Transform* GetParent() { return m_parent; }
		void SetParent(Transform* parent) { m_parent = parent; }

		//Returns a non-const reference to the matrix struct this class is represented with
		inline glm::mat4& GetMatrix() { return m_matrix; }
	private:
		//Updated when matrix transformations occur, used to easily return and track rotation scale and pos data.
		glm::vec3 currentRot = glm::vec3(0.0); 
		glm::vec3 currentScale = glm::vec3(1.0, 1.0f, 1.0f); 
		glm::vec3 currentPos = glm::vec3(0.0);

		glm::mat4 m_matrix = glm::mat4(1.0f);

		Transform* m_parent = nullptr;
	};
}

#pragma once
#include "GuiWindow.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Core/Transform.h"

namespace crynn
{
	/// <summary>
	/// Allows GUI editing of any matrix at runtime. Useful for debugging, or finding a good orientation for an object.
	/// Overrides any transformations done at runtime.
	/// </summary>
	class MatrixEditor final : public GuiWindow
	{
	public:
		MatrixEditor(Transform& matrix, const char* matrixname);
	private:
		Transform& m_matrix;

		void GUIDraw() override;

		bool m_active = true;
		const char* m_matrixname;

		glm::vec3 position = glm::vec3(0, 0, 0);
		glm::vec3 rotation = glm::vec3(0, 0, 0);
		glm::vec3 scale = glm::vec3(1, 1, 1);
	};
}
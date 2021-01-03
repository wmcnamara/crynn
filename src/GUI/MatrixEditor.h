#pragma once
#include "GuiWindow.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Core/Transform.h"

namespace crynn
{
	/// <summary>
	/// Allows GUI editing of any matrix at runtime. Useful for debugging.
	/// </summary>
	class MatrixEditor final : public GuiWindow
	{
	public:
		MatrixEditor(glm::mat4* matrix, const char* matrixname);
	private:
		glm::mat4* m_matrix;

		void GUIDraw() override;

		bool m_active = true;
		const char* m_matrixname;
	};
}
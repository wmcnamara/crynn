#pragma once
#include "GuiWindow.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Core/Transform.h"

namespace Crynn
{
	/// <summary>
	/// Allows GUI editing of any matrix after runtime. Useful for debugging.
	/// </summary>
	class MatrixEditor final : public GuiWindow
	{
	public:
		MatrixEditor(glm::mat4* matrix);
	private:
		glm::mat4* m_matrix;

		void BeginDraw() override;		
		void Draw() override;
		void EndDraw() override;

		bool m_active = true;
	};
}
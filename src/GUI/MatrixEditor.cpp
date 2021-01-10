#include "MatrixEditor.h"

namespace crynn
{
	MatrixEditor::MatrixEditor(Transform& matrix, const char* matrixname) :
		m_matrix(matrix), 
		m_matrixname(matrixname),
		GuiWindow(ImVec2(200, 300), ImVec2(0, 0), "Matrix Editor")
	{
		Debug::Log("Matrix Editor Constructed");
	}

	void MatrixEditor::GUIDraw()
	{
		ImGui::Begin(m_matrixname, &m_active, ImGuiWindowFlags_None);

		ImGui::InputFloat3("Position", glm::value_ptr(position), ImGuiInputTextFlags_None);
		ImGui::InputFloat3("Scale", glm::value_ptr(scale), ImGuiInputTextFlags_None);		
		ImGui::InputFloat3("Rotation", glm::value_ptr(rotation), ImGuiInputTextFlags_None);

		m_matrix.SetPosition(position);
		m_matrix.SetRotation(rotation);
		m_matrix.SetScale(scale);

		ImGui::End();
	}
}
#include "MatrixEditor.h"

namespace Crynn
{
	MatrixEditor::MatrixEditor(glm::mat4* matrix) : m_matrix(matrix), GuiWindow(ImVec2(200, 300), ImVec2(0, 0), "Matrix Editor")
	{
		Debug::Log("Matrix Editor Constructed");
	}

	void MatrixEditor::BeginDraw()
	{
		ImGui::Begin("Transform", &m_active, ImGuiWindowFlags_None);
	}

	void MatrixEditor::Draw()
	{
		static glm::vec3 position = glm::vec3(0, 0, 0);
		static glm::vec3 rotation = glm::vec3(0, 0, 0);
		static glm::vec3 scale = glm::vec3(1, 1, 1);

		ImGui::InputFloat3("Position", glm::value_ptr(position), ImGuiInputTextFlags_None);
		ImGui::InputFloat3("Rotation", glm::value_ptr(rotation), ImGuiInputTextFlags_None);
		ImGui::InputFloat3("Scale", glm::value_ptr(scale), ImGuiInputTextFlags_None);

		Transform::SetPosition(position, *m_matrix);
		Transform::SetScale(scale, *m_matrix);
	}

	void MatrixEditor::EndDraw()
	{
		ImGui::End();
	}
}
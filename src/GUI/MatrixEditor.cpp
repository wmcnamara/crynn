#include "MatrixEditor.h"

namespace crynn
{
	MatrixEditor::MatrixEditor(glm::mat4* matrix, const char* matrixname) : 
		m_matrix(matrix), 
		m_matrixname(matrixname),
		GuiWindow(ImVec2(200, 300), ImVec2(0, 0), "Matrix Editor")
	{
		Debug::Log("Matrix Editor Constructed");
	}

	void MatrixEditor::BeginGUIDraw()
	{
		ImGui::Begin(m_matrixname, &m_active, ImGuiWindowFlags_None);
	}

	void MatrixEditor::GUIDraw()
	{
		static glm::vec3 position = glm::vec3(0, 3, -15);
		static glm::vec3 rotation = glm::vec3(0, 0, 0);
		static glm::vec3 scale = glm::vec3(1, 1, 1);
		static float angle = 0;

		ImGui::InputFloat3("Position", glm::value_ptr(position), ImGuiInputTextFlags_None);
		ImGui::InputFloat3("Scale", glm::value_ptr(scale), ImGuiInputTextFlags_None);		
		ImGui::InputFloat3("Rotation", glm::value_ptr(rotation), ImGuiInputTextFlags_None);
		ImGui::InputFloat("Angle", &angle, ImGuiInputTextFlags_None);

		Transform::SetPosition(position, *m_matrix);
	//	Transform::SetRotation(angle, rotation, *m_matrix);
		Transform::SetScale(scale, *m_matrix);
	}

	void MatrixEditor::EndGUIDraw()
	{
		ImGui::End();
	}
}
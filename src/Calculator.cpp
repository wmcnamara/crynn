#include "Calculator.h"
namespace Crynn
{
	namespace Windows
	{
		void Calculator::Run()
		{
			// Create a window called "My First Tool", with a menu bar.
			ImGui::Begin("Calculator", &active, ImGuiWindowFlags_None);

			//ImGui::SetWindowPos(ImVec2(0, 0));
			ImGui::Text(resultText.c_str());

			ImGui::NewLine();

			ImGui::PushItemWidth(100);
			ImGui::InputFloat("Number 1", &num1);
			ImGui::InputFloat("Number 2", &num2);

			ImGui::NewLine();
			//Operators
			if (ImGui::Button("*", ImVec2(50, 50)))
			{
				resultText = "Result: " + std::to_string(Calculator::Multiply(num1, num2));
			}
			ImGui::SameLine();

			if (ImGui::Button("+", ImVec2(50, 50)))
			{
				resultText = "Result: " + std::to_string(Calculator::Add(num1, num2));
			}
			ImGui::SameLine();

			if (ImGui::Button("-", ImVec2(50, 50)))
			{
				resultText = "Result: " + std::to_string(Calculator::Subtract(num1, num2));
			}
			ImGui::SameLine();

			if (ImGui::Button("/", ImVec2(50, 50)))
			{
				//Prevent 0 division
				if (num2 == 0) { resultText = "Error! Cannot divide by 0."; }
				else { resultText = "Result: " + std::to_string(Calculator::Divide(num1, num2)); }
			}
			ImGui::SameLine();

			ImGui::End();
		}
	}
}
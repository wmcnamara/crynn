#pragma once

#include <glad/glad.h> 
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Utility/Debug.h"

namespace crynn
{
	class Shader
	{
	public:
		// the program ID
		unsigned int ID;

		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		// use/activate the shader
		void Use();

		// Set Uniforms
		void SetBool(const char* name, bool value) const;
		void SetInt(const char* name, int value) const;
		void SetFloat(const char* name, float value) const;
		void SetMatrix4(const char* name, glm::mat4* matrix) const;

		//Static uniform functions. Will set value for the currently bound shader.
		static void SetBoolCurrent(const char* name, bool value);
		static void SetIntCurrent(const char* name, int value);
		static void SetFloatCurrent(const char* name, float value);
		static void SetMatrix4Current(const char* name, glm::mat4* matrix);

	private:
		unsigned int UBI;

		void ShaderCompileLog(unsigned int vertexShader, unsigned int fragmentShader);
		void ShaderLinkLog(unsigned int shaderProgram);
	};
}
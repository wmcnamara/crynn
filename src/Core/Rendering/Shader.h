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
#include "../../Utility/Debug.h"
#include "../../Utility/IO.h"

namespace crynn
{
	class Shader
	{
	public:

		inline GLuint GetID() { return ID; }

		//Constructs a shader program from two relative paths to the corresponding shader files
		Shader(const char* vertexPath, const char* fragmentPath);

		~Shader();

		// use/activate the shader
		void Use() const;

		// Set Uniforms

		void SetBool(const char* name, bool value) const;
		void SetInt(const char* name, int value) const;
		void SetFloat(const char* name, float value) const;
		void SetVec2(const char* name, glm::vec2 vec) const;
		void SetVec3(const char* name, glm::vec3 vec) const;
		void SetMatrix3(const char* name, const glm::mat3* matrix) const;
		void SetMatrix4(const char* name, const glm::mat4* matrix) const;

		//Static uniform functions. Will set value for the currently bound shader.
		//These are not nearly as fast as the non static versions of these. 
		//If you're calling these frequently, consider using GetCurrentShaderProgram() and setting on that.

		static void SetBoolCurrent(const char* name, bool value);
		static void SetIntCurrent(const char* name, int value);
		static void SetFloatCurrent(const char* name, float value);
		static void SetVec2Current(const char* name, glm::vec2 vec);
		static void SetVec3Current(const char* name, glm::vec3 vec);
		static void SetMatrix3Current(const char* name, const glm::mat3* matrix);
		static void SetMatrix4Current(const char* name, const glm::mat4* matrix);

	private:
		GLuint UBI;
		GLuint ID; // The shader program ID

		void ShaderCompileLog(unsigned int vertexShader, unsigned int fragmentShader);
		void ShaderLinkLog(unsigned int shaderProgram);
	};
}
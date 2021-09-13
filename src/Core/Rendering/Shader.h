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


namespace crynn
{
	class Shader
	{
	public:
		//Constructs a shader program from two relative paths to the corresponding shader files
		Shader(const char* vertexPath, const char* fragmentPath);

		//Constructs a shader program from a Crynn shader file (.shader)
		Shader(const char* crynnShaderPath);
		
		~Shader();

		//Returns the underlying GLuint ID for the shader program
		inline GLuint GetID() { return ID; }

		//Binds this shader to the openGL context.
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

		static void SetBoolCurrent(const char* name, bool value);
		static void SetIntCurrent(const char* name, int value);
		static void SetFloatCurrent(const char* name, float value);
		static void SetVec2Current(const char* name, glm::vec2 vec);
		static void SetVec3Current(const char* name, glm::vec3 vec);
		static void SetMatrix3Current(const char* name, const glm::mat3* matrix);
		static void SetMatrix4Current(const char* name, const glm::mat4* matrix);


		//TODO implement copy and move constructors for Shader class
		Shader(const Shader& other) = delete;
		Shader operator=(const Shader& other) = delete;
		Shader(Shader&& other) = delete;
		Shader operator=(Shader&& other) = delete;
	private:
		struct ShaderParseResult
		{
			std::string vertexCode;
			std::string fragmentCode;

			bool succeeded = false;
		};

		//Compiles and links the shader from a two strings with the vertex and fragment shader code.
		//Returns a boolean indicating if the operation was successful or not.
		bool Recompile(std::string_view vertexCode, std::string_view fragmentCode);

		//Parses a crynn shader file (.shader) and returns a ShaderParseResult object containing the shader code and a result boolean.
		static ShaderParseResult ParseShaderFile(std::string_view pathToShaderFile, bool logDebugOuput = true);

		bool shaderIsBuilt = false;

		GLuint UBI = 0;
		GLuint ID = 0; // The shader program ID

		bool ShaderCompileLog(unsigned int vertexShader, unsigned int fragmentShader) const;
		bool ShaderLinkLog(unsigned int shaderProgram) const;
	};
}
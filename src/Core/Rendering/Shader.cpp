#include "Shader.h"
#include "../../Utility/Debug.h"
#include "../../Utility/IO.h"
#include <algorithm>

namespace crynn
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertCode = IO::LoadFileStr(vertexPath);
		std::string fragCode = IO::LoadFileStr(fragmentPath);

		bool succeeded = Rebuild(vertCode, fragCode);

		if (!succeeded) 
		{
			throw std::exception("Shader creation failed");
		}
	}

	Shader::Shader(const char* crynnShaderPath)
	{
		std::cout << "Loading shader from: " << crynnShaderPath << "\n";

		//load shader file
		std::string shaderCodeText = IO::LoadFileStr(crynnShaderPath);

		//Actual vertex and fragment shader code that will be attempted to be parsed will be put in these
		std::string vertexShaderCodeText, fragmentShaderCodeText;

		//Parse the vertex shader
		{
			//Find the vertex shader code start symbol
			size_t vertexCodeStart = shaderCodeText.find("@VERTEXSTART");

			if (vertexCodeStart == std::string::npos)
			{
				std::stringstream errorMessage;
				errorMessage << "SHADER PARSING ERROR. @VERTEXSTART not defined in the shader file: " << crynnShaderPath << "\n";

				std::cout << errorMessage.str();
				throw std::exception(errorMessage.str().c_str());
			}
		}
		
		//Parse the fragment shader
		{
			//Find the fragment shader code start symbol
			size_t fragmentCodeStart = shaderCodeText.find("@FRAGMENTSTART");

			if (fragmentCodeStart == std::string::npos)
			{
				std::stringstream errorMessage;
				errorMessage << "SHADER PARSING ERROR. @FRAGMENTSTART not defined in the shader file: " << crynnShaderPath << "\n";
			}
		}
	}

	bool Shader::ShaderLinkLog(unsigned int shaderProgram) const
	{
		int success;
		char infoLog[512];

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

			std::cout << "Error. Shader linking failed.\n" << infoLog;
		}
		else
		{
			std::cout << "Shader Program Linked Successfully\n";
		}

		return success;
	}

	bool Shader::ShaderCompileLog(unsigned int vertexShader, unsigned int fragmentShader) const
	{
		int success;
		char infoLog[512];

		//Vertex Shader
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

			std::cout << "Vertex Compilation Failed\n" << infoLog;
		}
		else
			std::cout << "Vertex Shader Compiled Successfully\n";

		//Fragment Shader
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "Fragment Compilation Failed\n" << infoLog << '\n';
		}
		else
			std::cout << "Fragment Shader Compiled Successfully\n";

		return success;
	}

	void Shader::SetBool(const char* name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name), (int)value);
	}

	void Shader::SetInt(const char* name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name), value);
	}

	void Shader::SetFloat(const char* name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name), value);
	}

	void Shader::SetVec2(const char* name, glm::vec2 vec) const
	{		
		glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec));
	}

	void Shader::SetVec3(const char* name, const glm::vec3 vec) const
	{
		glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec));
	}

	void Shader::SetMatrix3(const char* name, const glm::mat3* matrix) const
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
	}

	void Shader::SetMatrix4(const char* name, const glm::mat4* matrix) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
	}

	void Shader::SetBoolCurrent(const char* name, bool value)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniform1i(glGetUniformLocation(ID, name), (int)value);
	}

	void Shader::SetIntCurrent(const char* name, int value)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniform1i(glGetUniformLocation(ID, name), value);
	}

	void Shader::SetFloatCurrent(const char* name, float value)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniform1f(glGetUniformLocation(ID, name), value);
	}

	void Shader::SetVec2Current(const char* name, glm::vec2 vec)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec));
	}

	void Shader::SetVec3Current(const char* name, glm::vec3 vec)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(vec));
	}

	void Shader::SetMatrix3Current(const char* name, const glm::mat3* matrix)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
	}

	void Shader::SetMatrix4Current(const char* name, const glm::mat4* matrix)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
	}

	void Shader::Use() const
	{
		glUseProgram(ID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(ID);
	}

	bool Shader::Rebuild(std::string_view crynnShaderPath)
	{
		return false;
	}

	bool Shader::Rebuild(std::string_view vertexCode, std::string_view fragmentCode)
	{
		unsigned int vertex, fragment;

		const char* vertCodePtr = vertexCode.data();
		const char* fragCodePtr = fragmentCode.data();

		//compile
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertCodePtr, NULL);
		glCompileShader(vertex);

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragCodePtr, NULL);
		glCompileShader(fragment);

		//link shader program
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		//debugging
		ShaderLinkLog(ID);
		ShaderCompileLog(vertex, fragment);

		//Setup block bindings
		UBI = glGetUniformBlockIndex(ID, "CameraMatrices");
		glUniformBlockBinding(ID, UBI, 0);

		//debugging
		bool linkSucceeded = ShaderLinkLog(ID);
		bool compileSucceeded = ShaderCompileLog(vertex, fragment);
		bool succeeded = linkSucceeded && compileSucceeded;

		if (!succeeded)
		{
			glDeleteProgram(ID);
		}

		return succeeded;
	}

}
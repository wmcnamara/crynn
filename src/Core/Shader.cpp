#include "Shader.h"

namespace crynn
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		// Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			// open files
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);

			std::stringstream vShaderStream, fShaderStream;

			// read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			// close file handlers
			vShaderFile.close();
			fShaderFile.close();

			// convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			Debug::Log("Shader Not Read");
		}

		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();

		// 2. compile shaders
		unsigned int vertex, fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);

		// shader Program
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		ShaderLinkLog(ID);
		ShaderCompileLog(vertex, fragment);

		//Setup block bindings
		UBI = glGetUniformBlockIndex(ID, "CameraMatrices");
		glUniformBlockBinding(ID, UBI, 0);
	}

	void Shader::ShaderLinkLog(unsigned int shaderProgram)
	{
		int success;
		char infoLog[512];

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);

			std::stringstream output;
			output << "Error. Shader linking failed.\n" << infoLog;
			Debug::Log(output);
		}
		else
		{
			Debug::Log("Shader Program Linked Successfully");
		}
	}

	void Shader::ShaderCompileLog(unsigned int vertexShader, unsigned int fragmentShader)
	{
		int success;
		char infoLog[512];

		//Vertex Shader
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

			std::stringstream output;
			output << "Vertex Compilation Failed\n" << infoLog;
			Debug::Log(output);
		}
		else
			Debug::Log("Vertex Shader Compiled Successfully");

		//Fragment Shader
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::stringstream output;
			output << "Fragment Compilation Failed\n" << infoLog << '\n';
			Debug::Log(output);
		}
		else
			Debug::Log("Fragment Shader Compiled Successfully");
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

	void Shader::SetMatrix4(const char* name, glm::mat4* matrix) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
		//LOGERR();
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

	void Shader::SetMatrix4Current(const char* name, glm::mat4* matrix)
	{
		GLint ID;
		glGetIntegerv(GL_CURRENT_PROGRAM, &ID);

		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(*matrix));
	}

	void Shader::Use()
	{
		glUseProgram(ID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(ID);
	}
}
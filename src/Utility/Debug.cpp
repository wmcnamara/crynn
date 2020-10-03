#include "Debug.h"

namespace Crynn
{
	void Debug::Log(const std::stringstream& msg)
	{
#ifdef CRYNN_DEBUG
		std::cout << std::fixed << msg.rdbuf() << '\n';
#endif
	}

	void Debug::Log(const char* msg)
	{
#ifdef CRYNN_DEBUG
		std::cout << std::fixed << msg << '\n';
#endif
	}

	void Debug::LogToFile(const char* msg)
	{
#ifdef CRYNN_DEBUG
		std::ofstream log;

		log.open("output.log");
		log << msg << "\n";
		log.close();
#endif
	}

	void Debug::LogToFile(const std::stringstream& msg)
	{
#ifdef CRYNN_DEBUG
		std::ofstream log;

		log.open("output.log");
		log << msg.rdbuf() << '\n';
		log.close();
#endif
	}

	void Debug::LogMatrix4(const glm::mat4& matrix)
	{
#ifdef CRYNN_DEBUG
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; i < 4; i++)
			{
				std::cout << matrix[i][j];
			}
			std::cout << "\n";
		}
#endif
	}

	void Debug::LogGLErr()
	{
#ifdef CRYNN_DEBUG
		std::stringstream output;		
		output << "GL ERROR: " << glGetError() << '\n';

		std::cout << output.rdbuf() << '\n';
#endif
	}

	void Debug::ClearOutputLogs()
	{
#ifdef CRYNN_DEBUG
		std::ofstream log;

		log.open("output.log");
		log << "";
		log.close();
#endif
	}
}
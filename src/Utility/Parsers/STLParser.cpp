#include "STLParser.h"

namespace crynn
{
	STLDataPtr STLParser::Load(const char* path)
	{		
		//Create an object to hold the STL data
		STLDataPtr stlData = std::make_shared<STLData>();

		//Load the STL file into a string
		std::shared_ptr<std::string> str = IO::LoadFileStr(path);

		//Iterate through and get vertex/normal data into the data object
		std::stringstream strStream(*str); //to use getline

		for (std::string line; std::getline(strStream, line); )
		{
			const char* lineStart = line.c_str();

			/*
				If the line starts with "vertex" it denotes a vertex.
				If it starts with "facet normal" it denotes a normal vector.
			*/

			if (line[0] != 'v' && line[0] != 'f')
				continue;

			if (strstr(line.c_str(), "vertex") != NULL)
			{
				//Parse vertex
				lineStart += sizeof("vertex"); //offset pointer to the floating point data

				Vec3 vertex = Vec3::Parse(lineStart);

				stlData->vertices.push_back(vertex.x);
				stlData->vertices.push_back(vertex.y);
				stlData->vertices.push_back(vertex.z);
			}
			else if (strstr(line.c_str(), "facet normal") != NULL)
			{
				//Parse normal vector
				lineStart += sizeof("facet normal"); //offset pointer to the floating point data

				Vec3 normal = Vec3::Parse(lineStart);

				stlData->normals.push_back(normal.x);
				stlData->normals.push_back(normal.y);
				stlData->normals.push_back(normal.z);
			}
		}

		return stlData;
	}
}
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

				//Get vector components
				float x = 0.0f, y = 0.0f, z = 0.0f;
				char* nextFloatEnd; //used in strtof. check strtof docs to understand

				//Parse the vertex values
				x = strtof(lineStart, &nextFloatEnd);
				y = strtof(nextFloatEnd, &nextFloatEnd);
				z = strtof(nextFloatEnd, NULL);

				stlData->vertices.push_back(x);
				stlData->vertices.push_back(y);
				stlData->vertices.push_back(z);
			}
			else if (strstr(line.c_str(), "facet normal") != NULL)
			{
				//Parse normal vector
				lineStart += sizeof("facet normal"); //offset pointer to the floating point data

				//Get vector components
				float x = 0.0f, y = 0.0f, z = 0.0f;
				char* nextFloatEnd; //used in strtof. check strtof docs to understand

				//Parse the vertex values
				x = strtof(lineStart, &nextFloatEnd);
				y = strtof(nextFloatEnd, &nextFloatEnd);
				z = strtof(nextFloatEnd, NULL);

				stlData->normals.push_back(x);
				stlData->normals.push_back(y);
				stlData->normals.push_back(z);
			}
		}

		return stlData;
	}

	std::vector<GLfloat> STLData::ComputeGLFormat()
	{
		std::vector<GLfloat> vertData;
		int normIter = 0;
		int vertIter = 0;


		for (int i = 0; i < vertices.size() / 3; i++)
		{
			//Every three vertices get a new normal vector
			if (i % 3 == 0 && i != 0)
				normIter +=3;

			vertData.push_back(vertices[vertIter]);
			vertData.push_back(vertices[vertIter +1]);
			vertData.push_back(vertices[vertIter +2]);

			vertData.push_back(normals[normIter]);
			vertData.push_back(normals[normIter + 1]);
			vertData.push_back(normals[normIter + 2]);			

			vertIter += 3;
		}	

		return vertData;
	}
}
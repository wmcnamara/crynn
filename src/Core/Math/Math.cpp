#include "Math.h"

namespace crynn
{
	Vec3 crynn::ParseVec3(const char* textStart)
	{
		//Get vector components
		float x = 0.0f, y = 0.0f, z = 0.0f;
		char* nextFloatEnd; //used in strtof. check strtof docs to understand

		//Parse the vertex values
		x = strtof(textStart, &nextFloatEnd);
		y = strtof(nextFloatEnd, &nextFloatEnd);
		z = strtof(nextFloatEnd, NULL);

		//Create Vec3
		return Vec3(x, y, z);
	}

	Vec2 crynn::ParseVec2(const char* textStart)
	{
		//Get vector components
		float x = 0.0f, y = 0.0f, z = 0.0f;
		char* nextFloatEnd; //used in strtof. check strtof docs to understand

		//Parse the vertex values
		x = (int)strtof(textStart, &nextFloatEnd);
		y = (int)strtof(nextFloatEnd, NULL);

		//Create Vec3
		return Vec2(x, y);
	}
}
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <iostream>
#include <cmath>

#define PI 3.14159f
#define DEG2RAD PI / 180.0f //Converts an angle in degrees to radians
#define RAD2DEG 180.0f / PI //Converts an angle in radians to degrees

namespace crynn
{		
	//GLM Math typedefs
	using Vec2 = glm::vec2;
	using Vec3 = glm::vec3;
	using Vec4 = glm::vec4;

	using Mat3 = glm::mat3;
	using Mat4 = glm::mat4;

	using Vec3Int = glm::ivec3;
	using Vec2Int = glm::ivec2;

	using Quat = glm::quat;

	inline std::ostream& operator<<(std::ostream& os, const Vec3& vec) 
	{
		return os << "X: " << vec.x << " Y: " << vec.y << " Z: " << vec.z << "\n";
	}

	inline std::ostream& operator<<(std::ostream& os, const Vec2& vec)
	{
		return os << "X: " << vec.x << " Y: " << vec.y << "\n";
	}

	/*
		Creates a glm::vec3 from a string starting at parameter textStart.
		Expected in the general format: "-1.0 1.0 1.0" for Vec3(-1.0, 1.0, 1.0), or something similar.
		Should not have other text inside of it. Only the numbers, and spaces between them.
		Will place a value of 0 for any component that fails to parse.
	*/	
	Vec3 ParseVec3(const char* textStart);

	/*
		Creates a glm::vec2 from a string starting at parameter textStart.
		Expected in the general format: "-1.0 1.0" for Vec2(-1.0, 1.0) or something similar.
		Should not have other text inside of it. Only the numbers, and spaces between them.
		Will place a value of 0 for any component that fails to parse.
	*/
	Vec2 ParseVec2(const char* textStart);

	/// <summary>
	/// Collection of floating point math functions
	/// </summary>
	class Math
	{
	public:
		//Returns the absolute value of floating point number n
		//constexpr implementation of fabs.
		static constexpr float fabs(float n) 
		{
			return n > 0 ? n : -n;
		}

		//Returns the absolute value of integer n
		//constexpr implementation of abs.
		static constexpr int abs(int n)
		{
			return n > 0 ? n : -n;
		}

		static constexpr float fApproxEqual(float n, float a, float epsilon = 0.00001f) 
		{
			return Math::fabs(n - a) < epsilon;
		}

		//Performs a linear interpolation of min and max with t.
		static constexpr float Lerp(float min, float max, float t)
		{
			return ((max - min) * t) + min;
		}

		//Normalizes angle a so that it stays between 0 and 360.
		//Not a clamp. The value "wraps around" 0 and 360 to always represent a valid rotation between 0 and 360.
		//Example: NormalizeAngle(380) == 20
		static constexpr float NormalizeAngle(float a)
		{
			if (a > 360)
				return a - 360;

			if (a < 0)
				return 360 + a;

			return a;
		}

		//Performs a linear interpolation of min and max with t. This function clamps t to 0 - 1.
		static constexpr float LerpClamped(float min, float max, float t)
		{
			Clamp(0.0f, 1.0f, t);
			return ((max - min) * t) + min;
		}

		//Returns val clamped between min and max.
		static constexpr float Clamp(float min, float max, float val)
		{
			if (val > max)
				return max;

			if (val < min)
				return min;

			return val;
		}

		//Returns val clamped between min and max.
		static constexpr int Clamp(int min, int max, int val)
		{
			if (val > max)
				return max;

			if (val < min)
				return min;

			return val;
		}

		static constexpr bool Vec3ApproxEqual(const Vec3& vec1, const Vec3& vec2, float epsilon = 0.0001f) 
		{
			bool xEqual = fApproxEqual(vec1.x, vec2.x, epsilon);
			bool yEqual = fApproxEqual(vec1.y, vec2.y, epsilon);
			bool zEqual = fApproxEqual(vec1.z, vec2.z, epsilon);

			return xEqual && yEqual && zEqual;
		}

		static constexpr bool Vec2ApproxEqual(const Vec2& vec1, const Vec2& vec2, float epsilon = 0.0001f)
		{
			bool xEqual = fApproxEqual(vec1.x, vec2.x, epsilon);
			bool yEqual = fApproxEqual(vec1.y, vec2.y, epsilon);

			return xEqual && yEqual;
		}

		//Returns a bool indicating if n is between min and max.
		static constexpr bool Between(float min, float max, float n)
		{
			return n < max && n > min;
		}
	};
}
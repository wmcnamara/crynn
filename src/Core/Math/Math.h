#pragma once

/// <summary>
/// Collection of floating point math functions
/// </summary>
class Math
{
public:
	//Performs a linear interpolation of min and max with t.
	static constexpr float Lerp(float min, float max, float t)
	{
		return ((max - min) * t) + min;
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
	 
	//Returns a bool indicating if n is between min and max.
	static constexpr bool Between(float min, float max, float n)
	{
		return n < max && n > min;
	}
};
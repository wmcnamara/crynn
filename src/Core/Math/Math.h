#pragma once
/// <summary>
/// Collection of floating point math functions
/// </summary>
class Math
{
public:
	//Performs a linear interpolation of min and max with t.
	static float Lerp(float min, float max, float t);
	 
	//Performs a linear interpolation of min and max with t. This function clamps t to 0 - 1.
	static float LerpClamped(float min, float max, float t);
	 
	//Returns val clamped between min and max.
	static float Clamp(float min, float max, float val);
	 
	//Returns a bool indicating if n is between min and max.
	static bool Between(float min, float max, float n);
};


#include "Math.h"

float Math::Lerp(float min, float max, float t)
{
	return ((max - min) * t) + min;
}

float Math::LerpClamped(float min, float max, float t)
{
	Clamp(0.0f, 1.0f, t);
	return ((max - min) * t) + min;
}

float Math::Clamp(float val, float min, float max)
{
	if (val > max)
		return max;

	if (val < min)
		return min;

	return val;
}

bool Math::Between(float min, float max, float n)
{
	return n < max && n > min;
}
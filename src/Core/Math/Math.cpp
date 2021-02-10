#include "Math.h"

float Math::Lerp(float min, float max, float t)
{
	return ((max - min) * t) + min;
}

#include "Random.h"
namespace Crynn
{
	int Random::Range(int min, int max)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(gen);
	}
}
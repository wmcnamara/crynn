#include "Random.h"
namespace Crynn
{
	int Random::Range(int min, int max)
	{
		std::random_device rd;
		std::mt19937 gen(rd()); //Mersynne twister generation
		std::uniform_int_distribution<> distr(min, max);

		return distr(gen);
	}
}
#pragma once
#include <random>
namespace crynn
{
	/// Class used for generating random numbers
	class Random
	{
	public:
		/// <summary>
		/// Generates a random number between min and max.
		/// </summary>
		/// <param name="min">The smallest number the function can generate. Inclusive.</param>
		/// <param name="max">The biggest number the function can generate. Inclusive.</param>
		/// <returns>A random number between min and max</returns>
		static int Range(int min, int max);
	};
}
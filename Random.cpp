#include "Random.h"

#include <random>	// for std::random_devide, std::mt19937, 
					// std::uniform_int_distribution<>

namespace random
{
	// Create random distribution seed
	std::random_device rd;
	std::mt19937 seed(rd());

	int generateNumber(const int min, const int max)
	{
		std::uniform_int_distribution<> die{ min, max };
		return die(random::seed);
	}
}
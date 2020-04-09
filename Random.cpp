#include "Random.h"


#include <algorithm>	// for std::shuffle
#include <vector>		// for std::vector
#include <set>			// for std::set

namespace random
{
	// Create random distribution seed
	std::random_device rd;
	std::mt19937 seed(rd());

	std::vector<int> generate_no_repeats_data(const int data_size)
	{
		std::vector<int> result;
		
		for (int i = 1; i <= data_size; ++i) {
			result.emplace_back(i);
		}

		std::shuffle(result.begin(), result.end(), seed);

		return result;
	}

	int get_random_number(const int min, const int max) {
		std::uniform_int_distribution die{ min, max }; 
		return die(random::seed);
	}
}
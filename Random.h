#ifndef RANDOM_H
#define RANDOM_H

#include <vector>		// for std::vector
#include <random>		// for std::random_devide, std::mt19937, 
						// std::uniform_int_distribution<>


namespace random
{
	std::vector<int> generate_no_repeats_data(const int data_size);
	int get_random_number(const int min, const int max);
}

#endif // !RANDOM_H

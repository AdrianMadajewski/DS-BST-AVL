#ifndef TEST_H
#define TEST_H

#include "Tree.h"

#include <vector>		// for std::vector
#include <chrono>		// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
						// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds

#define UNIT_TIME std::chrono::nanoseconds


static constexpr int data_size_min{ 10 };
static constexpr int data_size_max{ 3000 };
static constexpr int increment{ 10 };
static constexpr int number_of_tests{ 15 };

void run_tests();
void make_test(int test_number, TreeType type, std::vector<int>& keys, std::ostream& stream);

std::vector<int> generate_descending_data(const int data_size);

#endif // !TEST_H

#include "Test.h"

#include "Tree.h"
#include "Random.h"

#include <vector>		// for std::vector
#include <iostream>		// for std::cout
#include <fstream>		// for std::ofstream
#include <chrono>		// for std::chrono::high_resolution_clock::now(), std::chrono::duration_cast()
						// std::chrono::hours, minutes, seconds, miliseconds, microseconds, nanoseconds
#include <algorithm>	// for std::sort

std::vector<int> generate_descending_data(const int data_size) {
	std::vector<int> result;
	int counter{ 0 };

	auto big_random_number{ random::get_random_number(data_size_max * 2, 4 * data_size_max) + data_size_max };
	auto decreasing_value{ random::get_random_number(10, 100) };
	int number = big_random_number;
	while (counter < data_size) {
		number -= decreasing_value;
		result.emplace_back(number);
		counter++;
	}
	return result;
}

void run_tests()
{
	// LOGGING FILES
	std::ofstream logBST("log_BST.txt");
	std::ofstream logAVL("log_AVL.txt");

	const std::string header{ "TEST#\tTYPE\tSIZE\tCREATE\tFIND-MIN\tIN-ORDER\tDSW" };

	logBST << header << '\n';
	logAVL << header << '\n';

	using time = std::chrono::high_resolution_clock;

	for (int test = 1; test <= number_of_tests; ++test) {
		std::cout << "TEST #" << test << '\n';

		for (int size = data_size_min; size <= data_size_max; size += increment) {

			auto vec{ generate_descending_data(size) };
			make_test(test, BST, vec, logBST);
			make_test(test, AVL, vec, logAVL);
		}

		std::cout << "TEST #" << test << " -> FINISHED" << '\n';
	}
}

void make_test(int test_number, TreeType type, std::vector<int> &keys, std::ostream& stream) {

	using time = std::chrono::high_resolution_clock;
	std::chrono::time_point<time> start;
	std::chrono::time_point<time> stop;

	Node* root{ nullptr };
	switch (type)
	{
	case BST:
		start = time::now();
		root = create_BST(keys);
		stop = time::now();
		break;
	case AVL:
		std::sort(keys.begin(), keys.end());
		start = time::now();
		root = create_AVL(keys, 0, keys.size() - 1);
		stop = time::now();
		break;
	}

	auto duration_create{ std::chrono::duration_cast<UNIT_TIME>(stop - start).count() };

	// FIND-MIN
	start = time::now();
	find_min(root);
	stop = time::now();

	auto duration_find_min{ std::chrono::duration_cast<UNIT_TIME>(stop - start).count() };

	// IN-ORDER
	start = time::now();
	print_in_order(root);
	stop = time::now();

	auto duration_print_in_order{ std::chrono::duration_cast<UNIT_TIME>(stop - start).count() };

	stream << test_number << '\t' << TreeType_to_string(type) << '\t' << keys.size() << '\t' << duration_create << '\t' << duration_find_min
		<< '\t' << duration_print_in_order;

	// DSW
	start = time::now();
	root = create_right_vine(root);
	root = balance_vine(root, keys.size());
	stop = time::now();
	auto duration_dsw{ std::chrono::duration_cast<UNIT_TIME>(stop - start).count() };
	stream << '\t' << duration_dsw << '\n';

	// DSW
	/*
	if (type == BST) {
		start = time::now();
		root = create_right_vine(root);
		root = balance_vine(root, keys.size());
		stop = time::now();
		auto duration_dsw{ std::chrono::duration_cast<UNIT_TIME>(stop - start).count() };
		stream << '\t' << duration_dsw << '\n';
	}
	else {
		stream << '\n';
	}
	*/

	root = make_empty(root);
	delete root;

	std::cout << "TEST " << test_number << " with size = " << keys.size() << " ended." << '\n';
}
#include "Input.h"
#include "Tree.h"

#include <string>		// for std::string_view
#include <limits>		// for std::numeric_limtis<std::streamsize>::max()
#include <iostream>
#include <algorithm>	// for std::find
#include <fstream>		// for std::ifstream

int get_user_input(const std::string& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{};
		std::cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid input - please try again." << '\n';
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return x;
		}
	}
}

int get_user_data_size(const std::string& message, const int data_size)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{ get_user_input() };
		if (x >= 1 && x <= data_size)
			return x;
		else
			std::cerr << "Data size must be greater than 0 and less than or equal to " << data_size << ". Try again." << '\n';
	}
}

bool ask_user_if(const std::string& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{ get_user_input() };
		switch (x)
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			std::cerr << "Invalid input - please try again." << '\n';
			break;
		}
	}
}

std::vector<int> get_user_keys(const int keys_size) {
	std::vector<int> result;
	using index_t = std::vector<int>::size_type;

	for (index_t i{ 0 }; i < keys_size; ++i) {
		std::string index{ static_cast<char>(i + 48) };
		const auto message = "keys[" + index + "] = ";
		while (true) {
			std::cout << message;
			const auto input{ get_user_input() };
			auto found = std::find(result.begin(), result.end(), input);
			if (found != result.end()) {
				std::cerr << "Invalid input - (data cannot be reapeated) - please try again." << '\n';
			}
			else if (input <= 0) {
				std::cerr << "Invalid input - (data must be greater than 0) - please try again." << '\n';
			}
			else {
				result.emplace_back(input);
				break;
			}
		}
	}
	return result;
}

std::vector<int> get_keys_to_remove(const int keys_size, const Tree& tree) {
	std::vector<int> result;
	using index_t = std::vector<int>::size_type;
	for (index_t i{ 0 }; i < keys_size; ++i) {
		std::string index{ static_cast<char>(i + 48) };
		const auto message = "r_keys[" + index + "] = ";
		std::cout << message;
		auto key{ get_user_input() };
		result.emplace_back(key);
	}
	return result;
}

std::vector<int> load_keys_from_file(const std::string& filename)
{
	std::vector<int> data;
	std::ifstream file;
	file.open(filename);

	if (!file.is_open())
	{
		std::cout << "Couldn't find the file. Please restart." << '\n';
		std::cin.get();
		exit(-1);
	}
	else
	{
		std::cout << "Succesfully read from file " << filename << '\n';
		while (!file.eof())
		{
			int x;
			file >> x;
			data.emplace_back(x);
		}
	}

	return data;
}

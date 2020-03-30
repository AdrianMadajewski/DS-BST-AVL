#include "Input.h"

#include <string>		// for std::string_view
#include <limits>		// for std::numeric_limtis<std::streamsize>::max()
#include <iostream>

int getUserInput(const std::string_view& message)
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
			std::cout << "Invalid input - please try again." << '\n';
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return x;
		}
	}
}

int getUserDataSize(const std::string_view& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{ getUserInput() };
		if (x >= 1 && x <= USER_DATA_SIZE_MAX)
			return x;
		else
			std::cout << "Data size must be greater than 0 and less than or equal to " << USER_DATA_SIZE_MAX << ". Try again." << '\n';
	}
}

bool askUserIf(const std::string_view& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	while (true)
	{
		int x{ getUserInput() };
		switch (x)
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			std::cout << "Invalid input - please try again." << '\n';
			break;
		}
	}
}

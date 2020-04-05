#include <iostream>
#include "Tree.h"
#include "Random.h"
#include "Input.h"
#include "Printer.h"

#include <algorithm>		// for std::find

// TODO: to powinno sprawdzac powtorzenia - zrobione
// TODO: przerzucic do pliku Input.cpp
std::vector<int> get_user_data(const int data_size) {
	std::vector<int> result;
	using index_t = std::vector<int>::size_type;

	for (index_t i{ 0 }; i < data_size; ++i) {
		std::string index{ static_cast<char>(i + 48) };
		const auto message = "data[" + index + "] = ";
		while (true) {
			std::cout << message;
			const auto input{ getUserInput() };
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

int main() {
	/*
	std::vector<int> keys{ 9, 1, 2, 3, 4, 5, 6, 7, 8, 10 };
	Tree bst(keys, AVL);

	bst.print2D();

	bst.display_in_order();
	bst.display_pre_order();

	bst.path_max();
	bst.path_min();
	*/

	bool userData{ askUserIf("Enter user data? : 1 = yes, 0 = false") };
	if (userData) {
		const int user_size{ getUserDataSize("Enter how many elements to enter: ") };
		auto keys = get_user_data(user_size);

		std::cout << "BST SECTION" << '\n';
		Tree BST(keys, BST);

		/*
		int user_choice = ask_user("jaki wybor")
		switch(user_choice)
			case cos : cos break;
			case wyjdz : exit(0) -> lepiej return 0 bo why not
			case skoncz sesje bst -> wyjdz z switcha i przejdz do sekcji AVL
			default:
				popros jeszcze raz o podanie co zrobic

			to wszystko chyba powinno byc w funkcji

		*/
	}


	return 0;
}
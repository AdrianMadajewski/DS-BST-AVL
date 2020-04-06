#include <iostream>
#include "Tree.h"
#include "Random.h"
#include "Input.h"
#include "Printer.h"
#include "Node.h"
#include "Utility.h"
#include "Test.h"
#include "Test.h"

int main() {

	if (ask_user_if("Enter user data? : 1 = yes, 0 = no")) {

		// BST
		auto user_size = get_user_data_size("BST: Enter how many elements to enter: ");
		auto keys = get_user_keys(user_size);

		Tree* bst = new Tree(keys, BST);
		user_decide(*bst);
		delete bst;

		std::cin.get();
		system("cls");

		// AVL
		user_size = get_user_data_size("AVL: Enter how many elements to enter: ");
		keys = get_user_keys(user_size);

		Tree* avl = new Tree(keys, AVL);
		user_decide(*avl);
		delete avl;

		std::cin.get();
		system("cls");
	}

	if (ask_user_if("Enter data from file? : 1 = yes, 0 = no")) {

		// BST
		std::string filename;
		std::cout << "Enter a filename: (BST) ";
		std::cin >> filename;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		auto keys = load_keys_from_file(filename);
		print_keys(keys);
		
		Tree* bst = new Tree(keys, BST);
		user_decide(*bst);
		delete bst;

		std::cin.get();
		system("cls");

		// AVL
		std::cout << "Enter a filename: (AVL) ";

		std::cin >> filename;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		keys = load_keys_from_file(filename);
		print_keys(keys);

		Tree* avl = new Tree(keys, AVL);
		std::cin.get();
		user_decide(*avl);
		delete avl;

		std::cin.get();
		system("cls");
	}

	if (ask_user_if("Generate random data? : 1 = yes, 0 = no")) {

		// BST
		int user_size{ get_user_data_size("BST: Enter how many elements to generate: ") };
		auto keys{ random::generate_no_repeats_data(user_size) };

		print_keys(keys);

		Tree* bst = new Tree(keys, BST);
		user_decide(*bst);
		delete bst;

		std::cin.get();
		system("cls");

		// AVL
		user_size = get_user_data_size("AVL: Enter how many element to generate: ");
		keys = random::generate_no_repeats_data(user_size);

		print_keys(keys);

		Tree* avl = new Tree(keys, AVL);
		user_decide(*avl);
		delete avl;

		std::cin.get();
		system("cls");
	}

	bool make_tests{ ask_user_if("Run tests? : 1 = yes, 0 = no") };

	if (make_tests) {
		std::cout << "TESTING UNIT" << '\n';
		run_tests();
		std::cout << "TESTING UNIT -> FINISHED" << '\n';
	}

	std::cout << "Press enter to quit" << '\n';
	std::cin.get();
	
	return 0;
}
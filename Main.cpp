#include <iostream>
#include "Tree.h"
#include "Random.h"
#include "Input.h"
#include "Printer.h"
#include "Node.h"
#include "Utility.h"

int main() {
	bool user_data{ ask_user_if("Enter user data? : 1 = yes, 0 = no") };

	if (user_data) {

		// BST
		int user_size{ get_user_data_size("BST: Enter how many elements to enter: ") };
		auto keys = get_user_keys(user_size);

		Tree* bst = new Tree(keys, BST);
		user_decide(*bst);
		delete bst;

		std::cin.get();
		system("cls");

		// AVL
		user_size = get_user_data_size("AVL: Enter how many element to enter: ");
		keys = get_user_keys(user_size);

		Tree* avl = new Tree(keys, AVL);
		user_decide(*avl);
		delete avl;

		std::cin.get();
		system("cls");
	}

	bool random_data{ ask_user_if("Generate random data? : 1 = yes, 0 = no") };

	if (random_data) {

		// BST
		int user_size{ get_user_data_size("BST: Enter how many elements to generate: ") };
		auto keys{ random::generate_no_repeats_data(user_size) };

		std::cout << "Displaying keys sequence: " << '\n';
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

	// TESTING IN PROGRESS...
	
	return 0;
}
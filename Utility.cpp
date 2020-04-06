#include "Utility.h"
#include "Input.h"
#include "Tree.h"

#include <vector>		// for std::vector
#include <iostream>		// for std::cout

void print_keys(const std::vector<int>& keys) {
	std::cout << "Displaying keys sequence: " << '\n';
	for (const auto& elem : keys) {
		std::cout << elem << ' ';
	}
	std::cout << '\n';
	std::cout << "Finished" << '\n';
}

User_choice get_user_choice(const std::string message) {

	if (!message.empty())
		std::cout << message << '\n';

	while (true) {
		int x{ get_user_input() };
		switch (x) {
		case 0:
			return DELETE_POST_ORDER;
		case 1:
			return MIN_MAX_PATH;
		case 2:
			return DELETE_KEYS;
		case 3:
			return IN_ORDER;
		case 4:
			return PRE_ORDER;
		case 5:
			return PRE_ORDER_FROM_KEY;
		case 6:
			return DSW;
		default:
			return ERROR;
		}
	}
}

void display_menu(const std::string& tree_type)
{
	std::cout << "MENU " << tree_type << ": \n";
	std::cout << "0 -> DELETE TREE (post order) and QUIT SECTION" << '\n';
	std::cout << "1 -> path to min key, max key" << '\n';
	std::cout << "2 -> delete given keys from the tree" << '\n';
	std::cout << "3 -> print tree in-order" << '\n';
	std::cout << "4 -> print tree pre-order" << '\n';
	std::cout << "5 -> print pre-order from given key" << '\n';
	std::cout << "6 -> DSW algorithm" << '\n';
}

void user_decide(Tree& tree) {
	bool in_menu = true;
	while (in_menu) {
		std::cin.get();
		system("cls"); // windows specific
		tree.print2D();
		display_menu(tree.get_string_type());

		User_choice choice{ get_user_choice("Enter what operation to make: ") };
		int key_to_display;
		int keys_to_remove_SIZE;
		std::vector<int> keys_to_remove;

		switch (choice)
		{
		case MIN_MAX_PATH:
			tree.path_min();
			tree.path_max();
			break;
		case DELETE_KEYS:
			keys_to_remove_SIZE = get_user_data_size("Enter how many keys to remove: ", tree.get_height());
			keys_to_remove = get_keys_to_remove(keys_to_remove_SIZE, tree);
			tree.remove(keys_to_remove);
			break;
		case IN_ORDER:
			tree.display_in_order();
			break;
		case PRE_ORDER:
			tree.display_pre_order();
			break;
		case PRE_ORDER_FROM_KEY:
			key_to_display = get_user_input("Enter key to display: ");
			tree.display_pre_order(key_to_display);
			tree.print2D(key_to_display);
			break;
		case DSW:
			tree.DSW();
			break;
		case DELETE_POST_ORDER:
			std::cout << "Quiting section." << '\n';
			in_menu = false; // calls destructor to delete tree
			break;
		case ERROR:
			std::cerr << "Invalid input - please enter a value from 1 to 7" << '\n';
			break;
		}
	}
}
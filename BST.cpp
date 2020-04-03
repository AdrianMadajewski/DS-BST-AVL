#include "BST.H"
#include "Node.h"
#include "Printer.h"

#include <iostream>		// for std::cout


BST::BST() {
	std::cout << "Created BST instance of an object." << '\n';
	root = nullptr;
	std::cout << "Finished" << '\n';
}

BST::BST(const std::vector<int> keys) {
	std::cout << "Created BST instance of an object." << '\n';
	using index_t = std::vector<int>::size_type;
	const auto size = keys.size();
	for (index_t i{ 0 }; i < size; ++i) {
		root = insert_key(root, keys.at(i));
	}
	height += size;
	std::cout << "Finished" << '\n';
}

BST::~BST() {
	std::cout << "Deleting BST instance of an object. (post order method)" << '\n';
	root = make_empty(root);
	std::cout << "Finished" << '\n';
	root = nullptr;
}

const int BST::get_height() {
	return height;
}

void BST::insert(const int key) {
	std::cout << "Inserting key value." << '\n';
	root = insert_key(root, key);
	++height;
	std::cout << "Finished." << '\n';
}

void BST::insert(const std::vector<int> keys) {
	std::cout << "Inserting keys' values " << '\n';
	using index_t = std::vector<int>::size_type;
	const auto size = keys.size();
	for (index_t i{ 0 }; i < size; ++i) {
		root = insert_key(root, keys.at(i));
	}
	height += keys.size();
	std::cout << "Finished." << '\n';
}

void BST::remove(const int key) {
	std::cout << "Deleting key = " << key << '\n';
	if (find(root, key) == nullptr) {
		std::cout << "No such element to delete." << '\n';
	}
	else {
		root = remove_key(root, key);
		--height;
	}	
	std::cout << "Finished." << '\n';
}

void BST::remove(const std::vector<int> keys) {
	using index_t = std::vector<int>::size_type;
	const auto size = keys.size();
	for (index_t i{ 0 }; i < size; ++i) {
		std::cout << "Deleting key = " << keys.at(i) << '\n';
		if (find(root, keys.at(i)) == nullptr) {
			std::cout << "No such element to delete." << '\n';
		}
		else {
			root = remove_key(root, keys.at(i));
			--height;
		}
	}
	std::cout << "Finished." << '\n';
}

void BST::display_pre_order() {
	std::cout << "Displaying BST instance - pre order." << '\n';
	if (root == nullptr) {
		std::cout << "The three is empty." << '\n';
	}
	else {
		pre_order(root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void BST::display_pre_order(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cout << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Displaying BST instance from key " << key << '\n';
		pre_order(new_root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void BST::display_in_order() {
	std::cout << "Displaying BST instance - in order." << '\n';
	if (root == nullptr) {
		std::cout << "The three is empty." << '\n';
	}
	else {
		in_order(root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void BST::display_in_order(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cout << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Displaying BST instance from key " << key << '\n';
		in_order(new_root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void BST::path_min() {
	std::cout << "Finding path to minimum in BST." << '\n';
	if (root == nullptr) {
		std::cout << "The three is empty." << '\n';
	}
	else {
		find_min(root, true);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void BST::path_max() {
	std::cout << "Finding path to maximum in BST." << '\n';
	if (root == nullptr) {
		std::cout << "The three is empty." << '\n';
	}
	else {
		find_max(root, true);
	}
	std::cout << '\n';
	std::cout << "Finished." << '\n';
}

void BST::print2D() {
	std::cout << "Printing 2D representation of a tree." << '\n';
	if (root == nullptr) {
		std::cout << "The tree is empty. " << '\n';
	}
	else {
		printTree(root, nullptr, false);
	}
	std::cout << "Finished." << '\n';
}

void BST::print2D(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cout << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Printing 2D representation of a tree from key " << key << '\n';
		printTree(new_root, nullptr, false);
	}
	std::cout << "Finished." << '\n';
}

void BST::DSW() {
	std::cout << "Starting DSW algorithm." << '\n';
	root = create_right_vine(root);
	std::cout << "Created right vine." << '\n';
	root = balance_vine(root, height);
	std::cout << "Balanced vine." << '\n';
	std::cout << "Finished" << '\n';
}


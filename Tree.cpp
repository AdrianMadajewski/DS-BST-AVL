#include "Tree.h"
#include "Node.h"
#include "Printer.h"

#include <iostream>		// for std::cout
#include <algorithm>	// for std::sort

std::string TreeType_to_string(TreeType type) {
	switch (type) {
	case BST:
		return "BST";
	case AVL:
		return "AVL";
	default:
		return "NONE";
	}
}

Tree::Tree() {
	std::cout << "Creating empty Tree instance of an object." << '\n';
	root = nullptr;
	height = 0;
	type = NONE;
	s_type = "NONE";
	std::cout << "Finished" << '\n';
}

Tree::Tree(std::vector<int> &keys, TreeType type) {
	s_type = TreeType_to_string(type);
	std::cout << "Creating " << s_type << " instance of an object." << '\n';
	const auto size = keys.size();
	
	switch (type)
	{
	case AVL:
		std::sort(keys.begin(), keys.end());
		root = create_AVL(keys, 0, size - 1);
		type = AVL;
		break;
	case BST:
		root = create_BST(keys);
		type = BST;
	}
	
	height += size;
	std::cout << "Finished" << '\n';
}

Tree::~Tree() {
	std::cout << "Destorying " << s_type << " instance of an object. (post order method)" << '\n';
	root = make_empty(root);
	root = nullptr;
	std::cout << "Finished" << '\n';
}

const int Tree::get_height() {
	return height;
}

void Tree::insert(const int key) {
	std::cout << "Inserting key value." << '\n';
	root = insert_key(root, key);
	++height;
	std::cout << "Finished." << '\n';
}

void Tree::insert(const std::vector<int> &keys) {
	std::cout << "Inserting keys' values " << '\n';
	using index_t = std::vector<int>::size_type;
	const auto size = keys.size();
	for (index_t i{ 0 }; i < size; ++i) {
		root = insert_key(root, keys.at(i));
	}
	height += keys.size();
	std::cout << "Finished." << '\n';
}

void Tree::remove(const int key) {
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

void Tree::remove(const std::vector<int> &keys) {
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

void Tree::display_pre_order() {
	std::cout << "Displaying tree instance - pre order." << '\n';
	if (root == nullptr) {
		std::cerr << "The tree is empty." << '\n';
	}
	else {
		print_pre_order(root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void Tree::display_pre_order(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cout << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Displaying tree instance from key " << key << '\n';
		print_pre_order(new_root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void Tree::display_in_order() {
	std::cout << "Displaying tree instance - in order." << '\n';
	if (root == nullptr) {
		std::cout << '\n';
		std::cout << "The tree is empty." << '\n';
	}
	else {
		print_in_order(root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void Tree::display_in_order(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cerr << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Displaying Tree instance from key " << key << '\n';
		print_in_order(new_root);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void Tree::path_min() {
	std::cout << "Finding path to minimum in Tree." << '\n';
	if (root == nullptr) {
		std::cerr << "The tree is empty." << '\n';
	}
	else {
		find_min(root, true);
		std::cout << '\n';
	}
	std::cout << "Finished." << '\n';
}

void Tree::path_max() {
	std::cout << "Finding path to maximum in Tree." << '\n';
	if (root == nullptr) {
		std::cerr << "The tree is empty." << '\n';
	}
	else {
		find_max(root, true);
	}
	std::cout << '\n';
	std::cout << "Finished." << '\n';
}

void Tree::print2D() {
	std::cout << "Printing 2D representation of a tree." << '\n';
	if (root == nullptr) {
		std::cerr << "The tree is empty. " << '\n';
	}
	else {
		printTree(root, nullptr, false);
	}
	std::cout << "Finished." << '\n';
}

void Tree::print2D(const int key) {
	auto new_root = find(root, key);
	if (new_root == nullptr) {
		std::cerr << "No such element in tree." << '\n';
	}
	else {
		std::cout << "Printing 2D representation of a tree from key " << key << '\n';
		printTree(new_root, nullptr, false);
	}
	std::cout << "Finished." << '\n';
}

void Tree::DSW() {
	std::cout << "Starting DSW algorithm." << '\n';
	root = create_right_vine(root);
	std::cout << "Created right vine." << '\n';
	root = balance_vine(root, height);
	std::cout << "Balanced vine." << '\n';
	std::cout << "Finished" << '\n';
}
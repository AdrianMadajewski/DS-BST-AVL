#include "Printer.h"

#include <string>
#include <iostream>

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	std::cout << p->str;
}

// Recursive function to print binary tree using inorder traversal
void printTree(Node* node, Trunk* prev, bool isRight) {
	if (node == nullptr) {
		return;
	}

	std::string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(node->right, trunk, true);

	if (!prev) {
		trunk->str = "---";
	}
	else if (isRight) {
		trunk->str = ".---";
		prev_str = "   |";
	}
	else {
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	std::cout << node->key << '\n';

	if (prev) {
		prev->str = prev_str;
	}
	trunk->str = "   |";

	printTree(node->left, trunk, false);
}
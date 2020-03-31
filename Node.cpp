#include "Node.h"
#include <iostream>		// for std::cout

Node* make_empty(Node* node)
{
	if (node == nullptr) {
		return node;
	}

	make_empty(node->left);
	make_empty(node->right);
	std::cout << "Deleted key : " << node->key << '\n';
	delete node;
}

Node* insert_key(Node* node, int new_key)
{
	if (node == nullptr)
	{
		node = new Node;
		node->key = new_key;
		node->left = node->right = nullptr;
	}
	else if (new_key < node->key)
		node->left = insert_key(node->left, new_key);
	else if (new_key > node->key)
		node->right = insert_key(node->right, new_key);
	return node;
}

Node* find_min(Node* node, bool log)
{
	if (log) {
		std::cout << node->key << ' ';
	}

	if (node == nullptr) {
		return node;
	}

	else if (node->left == nullptr) {
		return node;
	}

	else {
		return find_min(node->left, log);
	}
}

Node* find_max(Node* node, bool log)
{
	if (log) {
		std::cout << node->key << ' ';
	}

	if (node == nullptr) {
		return node;
	}

	else if (node->right == nullptr) {
		return node;
	}

	else {
		return find_max(node->right, log);
	}
}

Node* remove_key(Node* node, int key)
{
	Node* temp;

	if (node == nullptr) {
		return node;
	}

	else if (key < node->key) {
		node->left = remove_key(node->left, key);
	}
	else if (node->left != nullptr && node->right != nullptr) {
		temp = find_min(node->right);
		node->key = temp->key;
		node->right = remove_key(node->right, node->key);
	}
	else {
		temp = node;
		if (node->left == nullptr) {
			node = node->right;
		}
		else if (node->right == nullptr)
			node = node->left;
		delete temp;
	}
	return node;
}

Node* find(Node* node, int key) {
	if (node == nullptr)
		return node;
	else if (key < node->key)
		return find(node->left, key);
	else if (key > node->key)
		return find(node->right, key);
	else
		return node;
}

void in_order(Node* node) {
	if (node != nullptr) {
		in_order(node->left);
		std::cout << node->key << ' ';
		in_order(node->right);
	}
}

void pre_order(Node* node) {
	if (node != nullptr) {
		std::cout << node->key << ' ';
		pre_order(node->left);
		pre_order(node->right);
	}
}
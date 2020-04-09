#include "Node.h"
#include <iostream>		// for std::cout
#include <cmath>		// for log2

Node* make_empty(Node* node, bool log)
{
	if (node == nullptr) {
		return node;
	}

	make_empty(node->left, log);
	make_empty(node->right, log);

	if (log) {
		std::cout << "Deleted key : " << node->key << '\n';
	}
	
	delete node;
}

Node* insert_key(Node* node, int new_key)
{
	if (node == nullptr) {
		node = new Node(new_key);
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

Node* remove_key(Node* node, const int key)
{
	Node* temp;
	
	if (node == nullptr) {
		return node;
	}
	else if (key < node->key) {
		node->left = remove_key(node->left, key);
	}
	else if (key > node->key) {
		node->right = remove_key(node->right, key);
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

Node* find(Node* node, const int key) {
	if (node == nullptr)
		return node;
	else if (key < node->key)
		return find(node->left, key);
	else if (key > node->key)
		return find(node->right, key);
	else
		return node;
}

void print_in_order(Node* node, const bool log) {
	if (node != nullptr) {
		print_in_order(node->left, log);

		if (log) {
			std::cout << node->key << ' ';
		}

		print_in_order(node->right, log);
	}
}

void print_pre_order(Node* node) {
	if (node != nullptr) {
		std::cout << node->key << ' ';
		print_pre_order(node->left);
		print_pre_order(node->right);
	}
}

Node* right_rotate(Node* root) {

	if (root == nullptr) {
		return root;
	}

	if (root->left != nullptr) {
		Node* left_child = root->left;
		root->left = left_child->left;
		left_child->left = left_child->right;
		left_child->right = root->right;
		root->right = left_child;

		int tmp = root->key;
		root->key = left_child->key;
		left_child->key = tmp;
	}
	return root;
}

Node* left_rorate(Node* root) {

	if (root == nullptr) {
		return root;
	}

	if (root->right != nullptr) {
		auto right_child = root->right;
		root->right = right_child->right;
		right_child->right = right_child->left;
		right_child->left = root->left;
		root->left = right_child;

		int tmp = root->key;
		root->key = right_child->key;
		right_child->key = tmp;
	}
	return root;
}

Node* create_right_vine(Node* root) {
	if (root == nullptr) {
		return root;
	}

	while (root->left != nullptr) {
		root = right_rotate(root);
	}
	if (root->right != nullptr) {
		root->right = create_right_vine(root->right);
	}
	return root;
}

Node* balance_vine(Node* root, int node_count) {
	const int times = static_cast<int>(log2(node_count));
	auto new_root = root;
	for (int i = 0; i < times; ++i) {
		new_root = left_rorate(new_root);
		root = new_root->right;
		for (int j = 0; j < node_count / 2 - 1; ++j) {
			root = left_rorate(root);
			root = root->right;
		}
		node_count /= 2;
	}
	return new_root;
}
	
Node* create_AVL(const std::vector<int>& keys, const int start, const int end, const bool log) {
	if (start > end)
		return nullptr;

	int mid = start + (end - start) / 2;
	Node* root = new Node(keys.at(mid));

	if (log) {
		std::cout << "Inserting : " << root->key << '\n';
	}

	root->left = create_AVL(keys, start, mid - 1, log);
	root->right = create_AVL(keys, mid + 1, end, log);

	return root;
}

Node* create_BST(const std::vector<int>& keys, const bool log) {
	using index_t = std::vector<int>::size_type;
	const auto size = keys.size();
	Node* root = nullptr;
	for (index_t i{ 0 }; i < size; ++i) {
		if (log) {
			std::cout << "Inserting : " << keys.at(i) << '\n';
		}
		root = insert_key(root, keys.at(i));
	}
	return root;
}
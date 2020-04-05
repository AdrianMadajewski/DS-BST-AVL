#ifndef NODE_H
#define NODE_H

#include <vector>	// for std::vector

struct Node {
	int key;
	Node* left;
	Node* right;

	Node() : left(nullptr), right(nullptr) {};
	Node(int key) : key(key), left(nullptr), right(nullptr) {};
};

Node* make_empty(Node* node);
Node* insert_key(Node* node, int new_key);
Node* find_min(Node* node, const bool log = false);
Node* find_max(Node* node, const bool log = false);
Node* remove_key(Node* node, const int key);
Node* find(Node* node, const int key);

void print_in_order(Node* node);
void print_pre_order(Node* node);

// DSW
Node* right_rotate(Node* root);
Node* left_rorate(Node* root);
Node* create_right_vine(Node* root);
Node* balance_vine(Node* root, int node_count);

// Tree creation
Node* create_AVL(const std::vector<int>& keys, const int start, const int end);
Node* create_BST(const std::vector<int>& keys);

#endif // !NODE_H

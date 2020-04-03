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
Node* find_min(Node* node, bool log = false);
Node* find_max(Node* node, bool log = false);
Node* remove_key(Node* node, int key);
Node* find(Node* node, int key);

void in_order(Node* node);
void pre_order(Node* node);

// DSW
Node* right_rotate(Node* root);
Node* left_rorate(Node* root);
Node* create_right_vine(Node* root);
Node* balance_vine(Node* root, int node_count);


#endif // !NODE_H

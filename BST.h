#ifndef BST_H
#define BST_H

#include <vector>	// for std::vector
#include "Node.h"	

class BST
{
	Node* root;

public:

	BST();
	BST(const std::vector<int> keys);
	~BST();

	void insert(const int key);
	void insert(const std::vector<int> keys);

	void remove(const int key);
	void remove(const std::vector<int> keys);

	void display_pre_order();
	void display_pre_order(const int key);

	void display_in_order();
	void display_in_order(const int key);

	void path_min();
	void path_max();

	void print2D();
	void print2D(const int key);

};

#endif // !BST_H

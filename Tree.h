#ifndef TREE_H
#define TREE_H

#include <vector>	// for std::vector
#include <string>	// for std::string
#include "Node.h"	

enum TreeType
{
	NONE = -1,
	BST,
	AVL,
};

std::string TreeType_to_string(TreeType type);

class Tree {
private:
	int height;
	Node* root;
	TreeType type;
	std::string s_type;
public:
	Tree();
	Tree(std::vector<int> &keys, TreeType type);
	~Tree();

	const int get_height();
	const TreeType get_type();
	const std::string get_string_type();

	void insert(const int key);
	void insert(const std::vector<int> &keys);

	void remove(const int key);
	void remove(const std::vector<int> &keys);

	void display_pre_order();
	void display_pre_order(const int key);

	void display_in_order();
	void display_in_order(const int key);

	void path_min();
	void path_max();

	void print2D();
	void print2D(const int key);

	void DSW();
};

#endif // !BST_H

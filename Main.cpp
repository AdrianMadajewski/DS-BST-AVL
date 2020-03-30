#include <iostream>

class BST
{
	struct Node
	{
		int key;
		Node* left;
		Node* right;
	};

	Node* root;

	Node* make_empty(Node *root)
	{
		if (root == nullptr) {
			return root;
		}
			
		make_empty(root->left);
		make_empty(root->right);
		delete root;
	}

	Node* insert_key(Node* root, int new_key)
	{
		if (root == nullptr)
		{
			root = new Node;
			root->key = new_key;
			root->left = root->right = nullptr;
		}
		else if (new_key < root->key)
			root->left = insert_key(root->left, new_key);
		else if (new_key > root->key)
			root->right = insert_key(root->right, new_key);
		return root;
	}

	Node* find_min(Node* root)
	{
		std::cout << root->key << ' ';
		if (root == nullptr) {
			return root;
		}
			
		else if (root->left == nullptr) {
			return root;
		}
			
		else {
			return find_min(root->left);
		}
	}
	
	Node* find_max(Node* root)
	{
		std::cout << root->key << ' ';
		if (root == nullptr) {
			return root;
		}

		else if (root->right == nullptr) {
			return root;
		}

		else {
			return find_max(root->right);
		}
	}

	Node* remove_key(Node* root, int key)
	{
		Node* temp;

		if (root == nullptr) {
			return root;
		}
			
		else if (key < root->key) {
			root->left = remove_key(root->left, key);
		}
		else if (root->left != nullptr && root->right != nullptr) {
			temp = find_min(root->right);
			root->key = temp->key;
			root->right = remove_key(root->right, root->key);
		}
		else {
			temp = root;
			if (root->left == nullptr) {
				root = root->right;
			}
			else if (root->right == nullptr)
				root = root->left;
			delete temp;
		}
		return root;
	}

	void in_order(Node* root) {
		if (root == nullptr)
			return;
		in_order(root->left);
		std::cout << root->key << ' ';
		in_order(root->right);
	}

	void pre_order(Node* root) {

	}

	Node* find(Node* root, int key) {
		if (root == nullptr)
			return root;
		else if (key < root->key)
			return find(root->left, key);
		else if (key > root->key)
			return find(root->right, key);
		else
			return root;
	}

public:

	BST() {
		std::cout << "Created BST instance of an object." << '\n';
		root = nullptr;
	}

	~BST() {
		std::cout << "Destroyed BST instance of an object. (post order method)" << '\n';
		root = make_empty(root);
	}

	void insert(int x) {
		root = insert_key(root, x);
	}

	void remove(int x) {
		root = remove_key(root, x);
	}

	void display_in_order() {
		in_order(root);
		std::cout << '\n';
	}

	void search(int x) {
		root = find(root, x);
	}

	void path_min() {
		std::cout << "Finding path to minimum in BST." << '\n';
		find_min(root);
		std::cout << '\n';
	}

	void path_max() {
		std::cout << "Finding path to maximum in BST." << '\n';
		find_max(root);
		std::cout << '\n';
	}

};

int main()
{
	BST tree;
	tree.insert(8);
	tree.insert(2);
	tree.insert(5);
	tree.insert(14);
	tree.insert(1);
	tree.insert(10);
	tree.insert(12);
	tree.insert(13);
	tree.insert(6);
	tree.insert(9);

	tree.display_in_order();

	tree.path_min();
	tree.path_max();

	return 0;
}
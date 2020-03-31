#include <iostream>
#include "BST.h"
#include "Random.h"
#include "Input.h"

std::vector<int> get_user_data(const int data_size) {
	std::vector<int> result;
	using index_t = std::vector<int>::size_type;

	for (index_t i{ 0 }; i < data_size; ++i) {

	}
	return result;
}

int main()
{
	BST bst({ 8, 2, 5, 14, 1, 10, 12, 13, 6, 9 });
	
	bst.print2D();

	bool userData{ askUserIf("Enter user data? : 1 = yes, 0 = false") };

	if (userData) {
		


	}

	return 0;
}
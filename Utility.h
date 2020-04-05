#ifndef UTILITY_H
#define UTILITY_H

#include <vector>		// for std::vector
#include <string>		// for std::string

#include "Tree.h"

enum User_choice
{
	ERROR = -1,
	QUIT,
	MIN_MAX_PATH,
	DELETE_KEYS,
	IN_ORDER,
	PRE_ORDER,
	DELETE_POST_ORDER,
	PRE_ORDER_FROM_KEY,
	DSW,
};

void print_keys(const std::vector<int>& keys);
void display_menu(const std::string& tree_type);
void user_decide(Tree& tree);
User_choice get_user_choice(const std::string message = "");



#endif // !UTILITY_H



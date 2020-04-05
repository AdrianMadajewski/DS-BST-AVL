#ifndef INPUT_H
#define INPUT_H

#include <string>	// for std::string_view
#include <vector>	// for std::vector

#include "Tree.h"

inline constexpr auto USER_DATA_SIZE_MAX{ 10 };

int get_user_input(const std::string& message = "");
int get_user_data_size(const std::string& message = "", const int data_size = USER_DATA_SIZE_MAX);
bool ask_user_if(const std::string& message = "");
std::vector<int> get_user_keys(const int keys_size);
std::vector<int> get_keys_to_remove(const int keys_size, const Tree& tree);

#endif // !INPUT_H
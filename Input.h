#ifndef INPUT_H
#define INPUT_H

#include <string>	// for std::string_view

inline constexpr auto USER_DATA_SIZE_MAX{ 10 };

int getUserInput(const std::string& message = "");
int getUserDataSize(const std::string& message = "");
bool askUserIf(const std::string& message = "");

#endif // !INPUT_H
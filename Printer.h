#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include "Node.h"

#include  <iostream>

struct Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk *prev, const std::string &str) : prev(prev), str(str) {};
};

void showTrunks(Trunk* p);
void printTree(Node* node, Trunk* prev, bool isRight);

#endif // !PRINTER_H

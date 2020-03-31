#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include "Node.h"

#include  <iostream>

struct Trunk
{
	Trunk* prev;
	std::string str;

	Trunk(Trunk* prev, std::string str) {
		this->prev = prev;
		this->str = str;
	}
};

void showTrunks(Trunk* p);
void printTree(Node* node, Trunk* prev, bool isLeft);

#endif // !PRINTER_H
